

function nextFrame(f){
	window.requestAnimationFrame(f);
}

function draw(){
	ctx.clearRect(0, 0, CANVAS_WIDTH, CANVAS_HEIGHT);
	
	ctx.save();
	if((socket != null && socket.readyState != WebSocket.OPEN) || waitingForFirstClick){
		var text;
		
		if(socket == null){
			text = "Click to begin";
		}else{
			switch(socket.readyState){
				case WebSocket.CONNECTING: text = "Connecting"; break;
				case WebSocket.CLOSING:
				case WebSocket.CLOSED:
					text = "Lost connection to server";
				break;
				default: text = "Click to begin";
			}
		}
		
		ctx.font = '60px NovaSquare';
		ctx.fillText(text, 400 - ctx.measureText(text).width / 2, 315);
		
		renderClicks();
		renderMyCursor(false);
		ctx.restore();
		nextFrame(draw);
		return;
	}
	
	
	ctx.fillStyle = '#000000';
	
	// Render objects
	ctx.save();
	ctx.globalAlpha = 1.0;
	
	renderEditor();
	
	for (var i = 0; i < objects.length; i++) {
		var obj = objects[i];
		if(obj.type == 0x00){
			// Text
			ctx.font = obj.size + 'px NovaSquare';
			var x = realX(obj.x);
			var y = realY(obj.y);
			if(obj.isCentered) x -= ctx.measureText(obj.text).width / 2;
			ctx.fillStyle = '#000000';
			ctx.fillText(obj.text, x, y);
		}else if(obj.type == 0x01){
			// Wall
			ctx.fillStyle = obj.color;
			ctx.fillRect(realX(obj.x), realY(obj.y), realX(obj.width), realY(obj.height));
			ctx.strokeStyle = '#000000';
			ctx.globalAlpha = 0.2;
			ctx.lineWidth = 2;
			ctx.strokeRect(realX(obj.x) + 1, realY(obj.y) + 1, realX(obj.width) - 2, realY(obj.height) - 2);
			ctx.globalAlpha = 1.0;
		}else if(obj.type == 0x02){
			// Teleport
			ctx.fillStyle = obj.isBad ? '#FF0000' : '#00FF00';
			ctx.globalAlpha = 0.2;
			ctx.fillRect(realX(obj.x), realY(obj.y), realX(obj.width), realY(obj.height));
			ctx.globalAlpha = 1.0;
		}else if(obj.type == 0x03){
			// Counter
			var x = realX(obj.x);
			var y = realY(obj.y);
			var width = realX(obj.width);
			var height = realY(obj.height);
			ctx.fillStyle = obj.color;
			ctx.globalAlpha = 0.2;
			ctx.fillRect(x, y, width, height);
			ctx.globalAlpha = 0.5;
			ctx.fillStyle = '#000000';
			if(obj.width < 40 || obj.height < 40){
				ctx.font = '30px NovaSquare';
				ctx.fillText(obj.count, x + width / 2 - ctx.measureText(obj.count).width / 2, y + height / 2 + 10);
			}else{
				ctx.font = '60px NovaSquare';
				ctx.fillText(obj.count, x + width / 2 - ctx.measureText(obj.count).width / 2, y + height / 2 + 20);
			}
			
			ctx.globalAlpha = 1.0;
		}else if(obj.type == 0x04){
			// Click box
			var x = realX(obj.x);
			var y = realY(obj.y);
			var width = realX(obj.width);
			var height = realY(obj.height);
			ctx.fillStyle = obj.color;
			ctx.strokeStyle = obj.color;
			ctx.globalAlpha = 1.0;
			ctx.fillRect(x, y, width, height);
			ctx.globalAlpha = 0.2;
			ctx.fillStyle = '#000000';
			ctx.fillRect(x, y, width, height);
			ctx.globalAlpha = 1.0;
			ctx.fillStyle = obj.color;
			
			var recentClick = (now - obj.lastClickAt) < 150;
			
			var borderWidth = recentClick ? 8 : 12;
			ctx.fillRect(x + borderWidth, y + borderWidth, width - borderWidth * 2, height - borderWidth * 2);
			
			ctx.strokeStyle = '#000000';
			ctx.globalAlpha = 0.1;
			ctx.beginPath();
			ctx.moveTo(x, y);
			ctx.lineTo(x + borderWidth, y + borderWidth);
			ctx.moveTo(x + width, y);
			ctx.lineTo(x + width - borderWidth, y + borderWidth);
			ctx.moveTo(x, y + height);
			ctx.lineTo(x + borderWidth, y + height - borderWidth);
			ctx.moveTo(x + width, y + height);
			ctx.lineTo(x + width - borderWidth, y + height - borderWidth);
			ctx.moveTo(x, y);
			ctx.rect(x, y, width, height);
			ctx.rect(x + borderWidth, y + borderWidth, width - borderWidth * 2, height - borderWidth * 2);
			ctx.stroke();
			
			ctx.fillStyle = '#000000';
			ctx.globalAlpha = 0.5;
			if(obj.width < 50 || obj.height < 50){
				ctx.font = '35px NovaSquare';
				ctx.fillText(obj.count, x + width / 2 - ctx.measureText(obj.count).width / 2, y + height / 2 + 13);
			}else{
				ctx.font = '45px NovaSquare';
				ctx.fillText(obj.count, x + width / 2 - ctx.measureText(obj.count).width / 2, y + height / 2 + 16);
			}
			
			if(recentClick){
				ctx.fillStyle = '#000000';
				ctx.globalAlpha = 0.15;
				ctx.fillRect(x + borderWidth, y + borderWidth, width - borderWidth * 2, height - borderWidth * 2);
			}
			
			ctx.globalAlpha = 1.0;
		}
	}
	ctx.restore();
	
	
	if(!inEditor){
		ctx.font = '12px NovaSquare';
		ctx.strokeStyle = '#000000';
		ctx.fillStyle = '#FFFFFF';
		ctx.lineWidth = 2.5;
		
		var text = null;
		if(isOverflowing){
			text = "Area too full, not all cursors are shown";
		}else if(numCursors > 30){
			text = "Area too full, drawing is disabled";
		}else{
			text = "Use shift+click to draw";
		}
		
		ctx.globalAlpha = 0.5;
		ctx.strokeText(text, 10, 590);
		ctx.globalAlpha = 1.0;
		ctx.fillText(text, 10, 590);
		
		if(globalNumCursors != 0){
			var text = globalNumCursors + " players online";
			var tmp = ctx.measureText(text).width;
			ctx.globalAlpha = 0.5;
			ctx.strokeText(text, 790 - tmp, 590);
			ctx.globalAlpha = 1.0;
			ctx.fillText(text, 790 - tmp, 590);
		}
	}
	
	renderClicks();
	renderLines();
	
	ctx.save();
	
	for(var id in cursors){
		if(!cursors.hasOwnProperty(id)) continue;
		ctx.drawImage(cursorImg, realX(cursors[id].getX()) - 6, realY(cursors[id].getY()) - 6, 23, 30);
	}
	
	ctx.restore();
	
	renderMyCursor(true);
	
	ctx.restore();
	
	nextFrame(draw);
}

function renderClicks(){
	ctx.save();
	ctx.strokeStyle = '#000000';
	now = +new Date();
	for (var i = 0; i < clicks.length; i++) {
		var c = clicks[i];
		var time = (now - c[2]) / 1000;
		var opacity = 1 - time * 2;
		if(opacity <= 0.0){
			clicks.splice(i, 1);
			--i;
			continue;
		}
		
		
		var radius = time * 50;
		ctx.beginPath();
		ctx.globalAlpha = opacity * 0.3;
		ctx.arc(c[0], c[1], radius, 0, Math.PI * 2, false);
		ctx.stroke();
	}
	ctx.restore();
}

function renderLines(){
	if(!isDrawingEnabled()) return;
	ctx.save();
	ctx.strokeStyle = '#000000';
	ctx.lineWidth = 1;
	now = +new Date();
	for (var i = 0; i < lines.length; i++) {
		var c = lines[i];
		var time = (now - c[4]) / 1000;
		var opacity = 10 - time;
		if(opacity <= 0.0){
			lines.splice(i, 1);
			--i;
			continue;
		}
		if(opacity > 1.0) opacity = 1.0;
		
		ctx.globalAlpha = opacity * 0.3;
		ctx.beginPath();
		ctx.moveTo(c[0] - 0.5, c[1] - 0.5);
		ctx.lineTo(c[2] - 0.5, c[3] - 0.5);
		ctx.stroke();
	}
	ctx.restore();
}

function renderMyCursor(withCircle){
	if(inEditor){
		ctx.save();
		ctx.globalAlpha = 1.0;
		ctx.drawImage(cursorImg, realMouseX - 5, realMouseY - 5);
		ctx.restore();
		return;
	}
	
	var adjustX = 0;
	var adjustY = 0;
	if(mouseX != cursorX || mouseY != cursorY){
		ctx.save();
		if(withCircle){
			ctx.globalAlpha = 0.2;
			ctx.fillStyle = '#FF0000';
			ctx.beginPath();
			ctx.arc(realMouseX + 2, realMouseY + 8, 20, 0, Math.PI * 2, false);
			ctx.fill();
		}
		ctx.globalAlpha = 0.5;
		
		ctx.drawImage(cursorImg, realMouseX - 5, realMouseY - 5, 23, 30);
		ctx.restore();
	}else{
		adjustX = realMouseX & 1;
		adjustY = realMouseY & 1;
	}
	
	ctx.save();
	if(withCircle){
		ctx.globalAlpha = 0.2;
		ctx.fillStyle = '#FFFF00';
		ctx.beginPath();
		ctx.arc(realX(cursorX) + adjustX + 2, realY(cursorY) + adjustY + 8, 20, 0, Math.PI * 2, false);
		ctx.fill();
	}
	ctx.globalAlpha = 1.0;
	ctx.drawImage(myCursorImg, realX(cursorX) + adjustX - 5, realY(cursorY) + adjustY - 5, 23, 30);
	ctx.restore();
}
