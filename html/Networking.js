
var lastAck = 0;

function onSocketOpen(){
	resetMap();
	console.log("Connected!");
}

function onSocketClose(e){
	resetMap();
	console.log("Socket closed: " + e.reason);
	if(DEBUG){
		setTimeout(function(){ window.location.reload(); }, 1000);
	}
}

function onSocketError(e){
	console.log("Socket error");
}

function parseString(view, offset){
	var str = "";
	var currentChar = 0;
	var b = 0;
	for(; (b = view.getUint8(offset)) != 0; ++offset){
		currentChar <<= 8;
		currentChar |= b;
		if(!(b & 0x80)){
			str += String.fromCharCode(currentChar);
			currentChar = 0;
		}
	}
	
	if(currentChar != 0){
		str += String.fromCharCode(currentChar);
	}
	
	return [str, offset + 1];
}

function parseCursors(view, offset){
	var len = view.getUint16(offset, true);
	numCursors = len;
	
	isOverflowing = (len >= 100);
	var removedCursors = [];
	for(var id in cursors){
		if(!cursors.hasOwnProperty(id)) continue;
		removedCursors.push(id);
	}
	
	for (var i = 0; i < len; i++) {
		var id = view.getUint32(3 + i * 8, true);
		var x = view.getUint16(7 + i * 8, true);
		var y = view.getUint16(9 + i * 8, true);
		
		if(id == myId) continue;
		if(cursors[id] != null){
			for (var j = 0; j < removedCursors.length; j++) {
				if(removedCursors[j] == id){
					removedCursors.splice(j, 1);
					break;
				}
			}
			
			var c = cursors[id];
			c.oldX = c.getX();
			c.oldY = c.getY();
			c.newX = x;
			c.newY = y;
			c.time = now;
			
		}else{
			cursors[id] = new Cursor(x, y);
		}
	}
	
	for (var i = 0; i < removedCursors.length; i++) {
		delete cursors[removedCursors[i]];
	}
	
	return offset + 2 + 8 * len;
}

function parseClicks(view, offset){
	setTimeout(function(){
		var len = view.getUint16(offset, true);
		clicksLoop: for (var i = 0; i < len; i++) {
			var x = view.getUint16(offset + 2 + i * 4, true);
			var y = view.getUint16(offset + 4 + i * 4, true);
			
			for (var j = 0; j < ignoreNextClickAt.length; j++) {
				var c = ignoreNextClickAt[j];
				if(c[0] == x && c[1] == y){
					ignoreNextClickAt.splice(j, 1);
					continue clicksLoop;
				}
			}
			
			addClick(x, y);
		}
	}, INTERP_TIME);
	
	return offset + 2 + view.getUint16(offset, true) * 4;
}

function removeObjectById(id){
	for (var i = 0; i < objects.length; i++) {
		if(objects[i].id != id) continue;
		removeObject(objects[i]);
		objects.splice(i, 1);
		return;
	}
}

function getOrCreateObjectById(id){
	for (var i = 0; i < objects.length; i++) {
		if(objects[i].id != id) continue;
		return objects[i];
	}
	
	var obj = { id: id };
	objects.push(obj);
	return obj;
}

function parseLines(view, offset){
	if(isDrawingEnabled()){
		setTimeout(function(){
			var len = view.getUint16(offset, true);
			for (var i = 0; i < len; i++) {
				var fromX = view.getUint16(offset + 2 + i * 8, true);
				var fromY = view.getUint16(offset + 4 + i * 8, true);
				var toX = view.getUint16(offset + 6 + i * 8, true);
				var toY = view.getUint16(offset + 8 + i * 8, true);
				lines.push([realX(fromX), realY(fromY), realX(toX), realY(toY), now]);
			}
		}, INTERP_TIME / 2);
	}
	return offset + 2 + view.getUint16(offset, true) * 8;
}

function onSocketMessage(e){
	var data = e.data;
	var view = new DataView(data);
	
	switch(view.getUint8(0)){
		case 0x00:
			myId = view.getUint32(1, true);
		break;
		
		case 0x01: // Update
			var offset = parseCursors(view, 1);
			
			offset = parseClicks(view, offset);
			
			// Removed objects
			{
				var len = view.getUint16(offset, true);
				offset += 2;
				
				for(var i = 0; i < len; i++) {
					removeObjectById(view.getUint32(offset, true));
					offset += 4;
				}
			}
			
			// Add or update objects
			{
				var len = view.getUint16(offset, true);
				offset += 2;
				
				for(var i = 0; i < len; i++) {
					var obj = getOrCreateObjectById(view.getUint32(offset, true));
					offset += 4;
					offset = parseObject(view, offset, obj);
				}
			}
			
			// Lines
			offset = parseLines(view, offset);
			
			if(data.byteLength < offset + 4) return;
			
			globalNumCursors = view.getUint32(offset, true);
			offset += 4;
			
		break;
		
		case 0x04: // NewLevel
			resetMap();
			setMousePos(view.getUint16(1, true), view.getUint16(3, true));
			
			var numObjects = view.getUint16(5, true);
			var offset = 7;
			
			for (var i = 0; i < numObjects; i++) {
				var obj = {};
				obj.id = view.getUint32(offset, true);
				offset += 4;
				offset = parseObject(view, offset, obj);
				objects.push(obj);
			}
			
			if(data.byteLength >= offset + 4){
				lastAck = Math.max(lastAck, view.getUint32(offset, true));
				offset += 4;
			}else if(data.byteLength >= offset + 2){
				lastAck = Math.max(lastAck, view.getUint16(offset, true));
				offset += 2;
			}
			
			// ...
			
			checkMouse();
		break;
		
		case 0x05: // Prediction error
			setMousePos(view.getUint16(1, true), view.getUint16(3, true));
			if(view.byteLength >= 9){
				lastAck = Math.max(lastAck, view.getUint32(5, true));
			} else if(view.byteLength >= 7){
				lastAck = Math.max(lastAck, view.getUint16(5, true));
			}
			if(DEBUG) console.log("Prediction error ", cursorX, cursorY);
			checkMouse();
		break;
	}
}

function sendPosition(x, y){
	if(inEditor) return;
	if(waitingForFirstClick) return;
	if(socket == null) return;
	if(socket.readyState != WebSocket.OPEN) return;
	
	if(typeof x == 'undefined') x = cursorX;
	if(typeof y == 'undefined') y = cursorY;
	
	if(x == lastCursorX && y == lastCursorY) return;
	
	var buf = new ArrayBuffer(1 + 2 + 2 + 4);
	var view = new DataView(buf);
	view.setUint8(0, 0x01);
	view.setUint16(1, x, true);
	view.setUint16(3, y, true);
	view.setUint32(5, lastAck, true);
	socket.send(buf);
	lastCursorX = x;
	lastCursorY = y;
}

function sendClick(x, y){
	if(inEditor) return;
	if(socket == null) return;
	if(socket.readyState != WebSocket.OPEN) return;
	var buf = new ArrayBuffer(1 + 2 + 2 + 4);
	var view = new DataView(buf);
	view.setUint8(0, 0x02);
	view.setUint16(1, x, true);
	view.setUint16(3, y, true);
	view.setUint32(5, lastAck, true);
	socket.send(buf);
}

function sendDrawLine(x1, y1, x2, y2){
	if(inEditor) return;
	if(socket == null) return;
	if(socket.readyState != WebSocket.OPEN) return;
	var buf = new ArrayBuffer(1 + 2 + 2 + 2 + 2);
	var view = new DataView(buf);
	view.setUint8(0, 0x03);
	view.setUint16(1, x1, true);
	view.setUint16(3, y1, true);
	view.setUint16(5, x2, true);
	view.setUint16(7, y2, true);
	socket.send(buf);
}


function parseObject(view, offset, obj){
	var objectType = view.getUint8(offset);
	offset += 1;
	
	obj.type = objectType;
	
	function parseBasicPosition(){
		obj.x = view.getUint16(offset, true);
		offset += 2;
		
		obj.y = view.getUint16(offset, true);
		offset += 2;
		
		obj.width = view.getUint16(offset, true);
		offset += 2;
		
		obj.height = view.getUint16(offset, true);
		offset += 2;
	}
	
	function parseColor(){
		var color = view.getUint32(offset, true).toString(16);
		while(color.length < 6) color = '0' + color;
		color = '#' + color;
		offset += 4;
		obj.color = color;
	}
	
	switch(objectType){
		case 0xFF: break;
		case 0x00: // Text
			obj.x = view.getUint16(offset, true);
			offset += 2;
			
			obj.y = view.getUint16(offset, true);
			offset += 2;
			
			obj.size = view.getUint8(offset);
			offset += 1;
			
			obj.isCentered = !!view.getUint8(offset);
			offset += 1;
			
			var tmp = parseString(view, offset);
			obj.text = tmp[0];
			offset = tmp[1];
		break;
		
		case 0x01: // Wall
			parseBasicPosition();
			
			var newObject = !obj.color;
			parseColor();
			
			var x = obj.x|0;
			var y = obj.y|0;
			var width = obj.width|0;
			var height = obj.height|0;
			if(newObject){
				for(var py = y; py < y + height; ++py){
					for(var px = x; px < x + width; ++px){
						if(DEBUG && px >= WIDTH) debugger;
						++solidMap[px + py * WIDTH];
					}
				}
			}
		break;
		
		case 0x02: // Teleport
			parseBasicPosition();
			obj.isBad = !!view.getUint8(offset);
			offset += 1;
		break;
		
		case 0x03: // Area counter
			parseBasicPosition();
			obj.count = view.getUint16(offset, true);
			offset += 2;
			parseColor();
			
		break;
		
		case 0x04: // Click box
			parseBasicPosition();
			if(obj.count){
				if(obj.count > view.getUint16(offset, true)){
					obj.lastClickAt = now;
				}
			}else{
				obj.lastClickAt = 0;
			}
			obj.count = view.getUint16(offset, true);
			offset += 2;
			parseColor();
		break;
		
		default: throw new Error("Unknown object type " + objectType);
	}
	
	return offset;
}

function removeObject(obj){
	if(obj.type == 0x01){
		var x = obj.x|0;
		var y = obj.y|0;
		var width = obj.width|0;
		var height = obj.height|0;
		
		for(var py = y; py < y + height; ++py){
			for(var px = x; px < x + width; ++px){
				--solidMap[px + py * WIDTH];
			}
		}
	}
}

function shouldSendPositionImmediately(x, y){
	for (var i = 0; i < objects.length; i++) {
		var obj = objects[i];
		if(obj.type != 0x02) continue;
		if(cursorX < obj.x) continue;
		if(cursorY < obj.y) continue;
		if(cursorX >= obj.x + obj.width) continue;
		if(cursorY >= obj.y + obj.height) continue;
		return true;
	}
	return false;
}
