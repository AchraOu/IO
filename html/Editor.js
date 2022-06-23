
var tmp = (function(){
	
/** @const */
var GRID_SIZE = 10;
var GRID_WIDTH = WIDTH / GRID_SIZE;
var GRID_HEIGHT = HEIGHT / GRID_SIZE;

var isMouseDown = false;
var mouseDownGridX = 0;
var mouseDownGridY = 0;

var curPencilColor = 1;

var curPencilStyle = 1;

var spawnX = 200;
var spawnY = 150;

var hasFocus = true;

var wallGrid = new Uint8Array(GRID_WIDTH * GRID_HEIGHT);

var COLORS = [
	'#000000',
	'#FF9999',
	'#9999FF',
	'#FFFF99',
	'#99FFFF',
	'#FF99FF',
	'#3333FF'
];

function initEditor(){
	eventContainer.addEventListener("mousedown", onEditorMouseDown);
	/*
	var maze = new Image();
	maze.src = "maze.png";
	maze.onload = function(){
		var tmpc = document.createElement('canvas');
		tmpc.width = maze.width;
		tmpc.height = maze.height;
		var tmpx = tmpc.getContext('2d');
		tmpx.drawImage(maze, 0, 0);
		var data = tmpx.getImageData(0, 0, maze.width, maze.height).data;
		console.log('yay', maze.width, maze.height);
		for(var x = 0; x < GRID_WIDTH; ++x){
			for(var y = 0; y < GRID_HEIGHT; ++y){
				var i = (x + y * GRID_WIDTH) * 4;
				if(data[i] == 0){
					wallGrid[x + y * GRID_WIDTH] = 1;
				}
			}
		}
	}
	*/
}

function renderEditor(){
	if(!inEditor) return;

	ctx.save();
	
	// Draw grid
	
	ctx.fillStyle = '#FF0000';
	ctx.strokeStyle = '#FF0000';
	ctx.lineWidth = 1;
	ctx.globalAlpha = 0.09;
		
	ctx.beginPath();
	for(var x = 0; x < WIDTH; x += GRID_SIZE){
		ctx.moveTo(realX(x) + 0.5, 0);
		ctx.lineTo(realX(x) + 0.5, CANVAS_HEIGHT);
	}
	
	for(var y = 0; y < HEIGHT; y += GRID_SIZE){
		ctx.moveTo(0, realY(y) + 0.5);
		ctx.lineTo(CANVAS_WIDTH, realY(y) + 0.5);
	}
	ctx.stroke();
	
	ctx.lineWidth = 2;
	ctx.beginPath();
	ctx.moveTo(CANVAS_WIDTH / 2 + 0.5, 0);
	ctx.lineTo(CANVAS_WIDTH / 2 + 0.5, CANVAS_HEIGHT);
	ctx.moveTo(0, CANVAS_HEIGHT / 2 + 0.5, 0);
	ctx.lineTo(CANVAS_WIDTH, CANVAS_HEIGHT / 2 + 0.5);
	ctx.stroke();
	ctx.lineWidth = 1;
	
	ctx.globalAlpha = 1.0;
	ctx.fillStyle = '#000000';
	
	var sel = getSelectionBlock();
	for(var y = 0; y < HEIGHT; y += GRID_SIZE){
		for(var x = 0; x < WIDTH; x += GRID_SIZE){
			var gx = (x / GRID_SIZE)|0;
			var gy = (y / GRID_SIZE)|0;
			var id = wallGrid[gx + gy * GRID_WIDTH];
			
			if(isMouseDown && curPencilStyle == 1){
				if(gx >= sel.sx && gx < sel.fx && gy >= sel.sy && gy < sel.fy){
					id = curPencilColor;
				}
			}
			
			
			if(id != 0){
				ctx.fillStyle = COLORS[id - 1];
				ctx.fillRect(realX(x), realY(y), realX(GRID_SIZE), realY(GRID_SIZE));
			}
		}
	}
	
	ctx.save();
	ctx.globalAlpha = 0.09;
	ctx.fillStyle = '#0000FF';
	ctx.beginPath();
	ctx.arc(realX(spawnX), realY(spawnY), 20, 0, Math.PI * 2, false);
	ctx.fill();
	ctx.restore();
	
	{
		ctx.save();
		ctx.fillStyle = '#FFFFFF';
		ctx.strokeStyle = '#000000';
		ctx.lineWidth = 2.5;
		ctx.font = '14px NovaSquare';
		
		var text = "Current color: ";
		ctx.globalAlpha = 0.5;
		ctx.strokeText(text, 10, 590);
		ctx.globalAlpha = 1.0;
		ctx.fillText(text, 10, 590);
		
		if(curPencilColor == 0){
			ctx.fillText("ESR", 105, 590);
		}else{
			ctx.fillStyle = '#000000';
			ctx.fillRect(104, 575, 22, 22);
			ctx.fillStyle = COLORS[curPencilColor - 1];
			ctx.fillRect(105, 576, 20, 20);
		}
		
		ctx.restore();
	}
	
	
	ctx.restore();
}

function getSelectionBlock(){
	var sx = 0;
	var sy = 0;
	var mgx = mouseX / GRID_SIZE;
	var mgy = mouseY / GRID_SIZE;
	
	if(mouseDownGridX < mgx){
		mgx = Math.ceil(mgx);
		sx = Math.floor(mouseDownGridX);
	}else{
		mgx = Math.floor(mgx);
		sx = Math.ceil(mouseDownGridX);
	}
	
	if(mouseDownGridY < mgy){
		mgy = Math.ceil(mgy);
		sy = Math.floor(mouseDownGridY);
	}else{
		mgy = Math.floor(mgy);
		sy = Math.ceil(mouseDownGridY);
	}
	
	var fx = mgx;
	var fy = mgy;
	
	if(sx > fx){
		var tmp = fx;
		fx = sx;
		sx = tmp;
	}
	
	if(sy > fy){
		var tmp = fy;
		fy = sy 
		sy = tmp;
	}
	
	return {
		sx: sx,
		sy: sy,
		fx: fx,
		fy: fy
	};
}

function onEditorMouseDown(){
	if(!hasFocus) return;
	isMouseDown = true;
	mouseDownGridX = mouseX / GRID_SIZE;
	mouseDownGridY = mouseY / GRID_SIZE;
};

function paintBlock(sel, color){
	for(var y = sel.sy; y < sel.fy; ++y){
		for(var x = sel.sx; x < sel.fx; ++x){
			wallGrid[x + y * GRID_WIDTH] = color;
		}
	}
}

document.addEventListener("mouseup", function(){
	if(!isMouseDown) return;
	
	if(curPencilStyle == 1){
		paintBlock(getSelectionBlock(), curPencilColor);
		
	}
	
	isMouseDown = false;
});

document.addEventListener("mousemove", function(){
	var gx = ~~(mouseX / GRID_SIZE);
	var gy = ~~(mouseY / GRID_SIZE);
	
	if(isMouseDown){
		if(curPencilStyle == 2){
			wallGrid[gx + gy * GRID_WIDTH] = curPencilColor;
		}
	}
});

function generateWalls(){
	var isUsed = new Uint8Array(GRID_WIDTH * GRID_HEIGHT);
	var walls = [];
	for(var y = 0; y < GRID_HEIGHT; ++y){
		for(var x = 0; x < GRID_WIDTH; ++x){
			if(isUsed[x + y * GRID_WIDTH]) continue;
			var color = wallGrid[x + y * GRID_WIDTH];
			if(color == 0) continue;
			
			var xStart = x;
			while(x < GRID_WIDTH && wallGrid[x + y * GRID_WIDTH] == color && !isUsed[x + y * GRID_WIDTH]){
				isUsed[x + y * GRID_WIDTH] = true;
				++x;
			}
			var xEnd = x--;
			//if(xStart == xEnd) continue;
			
			var width = xEnd - xStart;
			var yStart = y++;
			yLoop: while(y < GRID_HEIGHT){
				for(var x2 = xStart; x2 < xEnd; ++x2){
					if(wallGrid[x2 + y * GRID_WIDTH] != color) break yLoop;
					if(isUsed[x2 + y * GRID_WIDTH]) break yLoop;
				}
				
				for(var x2 = xStart; x2 < xEnd; ++x2){
					isUsed[x2 + y * GRID_WIDTH] = true;
				}
				++y;
			}
			var yEnd = y;
			var height = yEnd - yStart;
			y = yStart;
			walls.push({ x: xStart * GRID_SIZE, y: yStart * GRID_SIZE, width: width * GRID_SIZE, height: height * GRID_SIZE, color: color - 1 });
		}
	}
	
	return walls;
}

function colorStringToCode(c){
	return '0x' + parseInt(c.slice(1), 16).toString(16).toUpperCase();;
}

function generateCode(){
	var str = 'class Level? : public Level {\npublic:\n\tLevel?() : Level(' + spawnX + ', ' + spawnY + '){}\n\n\tvoid OnInit(){\n';

	str += "\t\tstd::vector<LevelObject*> wallByColor[" + COLORS.length + "];\n";
	var walls = generateWalls();
	for (var i = 0; i < walls.length; i++) {
		var w = walls[i];
		if(w.color == 0){
			str += '\t\tAddObject(new ObjWall(' + w.x + ', ' + w.y + ', ' + w.width + ', ' + w.height + ', 0x000000));\n';
		}else{
			var color = colorStringToCode(COLORS[w.color]);
			str += '\t\twallByColor[' + w.color + '].push_back(AddObject(new ObjWall(' + w.x + ', ' + w.y + ', ' + w.width + ', ' + w.height + ', ' + color + ')));\n';
		}
	}
	
	for (var i = 0; i < objects.length; i++) {
		var obj = objects[i];
		if(obj.type == 0x00){
			
		}else if(obj.type == 0x02){
			str += '\t\tAddObject(new ObjTeleport(LevelManager::GetNextLevel(this), ' + obj.x + ', ' + obj.y + ', ' + obj.width + ', ' + obj.height + '));\n';
		}else if(obj.type == 0x03){
			str += '\t\tAddObject(new ObjAreaCounter(wallByColor[' + obj.colorCode + '], ' + obj.x + ', ' + obj.y + ', ' + obj.width + ', ' + obj.height + ', ';
			str += obj.count + ', ' + colorStringToCode(obj.color) + '));\n';
		}else if(obj.type == 0x04){
			str += '\t\tAddObject(new ObjClickBox(wallByColor[' + obj.colorCode + '], ' + obj.x + ', ' + obj.y + ', ' + obj.width + ', ' + obj.height + ', ';
			str += obj.count + ', 1000, ' + colorStringToCode(obj.color) + '));\n';
		}
	}
	
	str += '\t}\n'
	str += '};\n'
	return str;
}

window.generateCode = generateCode;

function createObjAtMousePos(width, height, offx, offy, obj){
	return mergeTo({
		x: ~~(cursorX / GRID_SIZE) * GRID_SIZE - ~~(width / 2) + offx,
		y: ~~(cursorY / GRID_SIZE) * GRID_SIZE - ~~(height / 2) + offy,
		width: width,
		height: height
	}, obj);
}

function getObjectClosestTo(x, y){
	var closest = null;
	var closestDist = Number.POSITIVE_INFINITY;
	for (var i = 0; i < objects.length; i++) {
		var obj = objects[i];
		if(!obj.hasOwnProperty('x')) continue;
		if(!obj.hasOwnProperty('y')) continue;
		if(!obj.hasOwnProperty('width')) continue;
		if(!obj.hasOwnProperty('height')) continue;
		var px = obj.x + obj.width / 2;
		var py = obj.y + obj.height / 2;
		var dist = (x - px) * (x - px) + (y - py) * (y - py);
		if(dist < closestDist){
			closestDist = dist;
			closest = obj;
		}
	}
	
	return closest;
}

document.addEventListener("keydown", function(e){
	if(!inEditor) return;
	if(!hasFocus) return;
	var keyCode = e.keyCode;
	//console.log(keyCode);
	
	if(keyCode == 65) { // A
		--curPencilColor;
		if(curPencilColor < 0) curPencilColor = COLORS.length;
	}else if(keyCode == 83) { // S
		++curPencilColor;
		if(curPencilColor > COLORS.length) curPencilColor = 0;
	}else if(keyCode == 66) { // B
		if(curPencilColor <= 1) return;
		
		objects.push(createObjAtMousePos(40, 40, 5, 5, {
			type: 0x04,
			color: COLORS[curPencilColor - 1],
			colorCode: curPencilColor - 1,
			count: 5
		}));
	}else if(keyCode == 90) { // Z
		objects.pop();
	}else if(keyCode == 87) { // W
		objects.push(createObjAtMousePos(50, 50, -5, -5, {
			type: 0x02,
			isBad: false
		}));
	}else if(keyCode == 79) { // O
		spawnX = cursorX;
		spawnY = cursorY;
	}else if(keyCode == 78) { // N
		if(curPencilColor <= 1) return;
		objects.push(createObjAtMousePos(40, 40, 0, 0, {
			type: 0x03,
			color: COLORS[curPencilColor - 1],
			colorCode: curPencilColor - 1,
			count: 1
		}));
	}else if(keyCode == 37) { // Left
		var obj = getObjectClosestTo(mouseX, mouseY);
		if(obj == null) return;
		if(e.shiftKey){
			obj.width -= GRID_SIZE;
		}else{
			obj.x -= GRID_SIZE;
			obj.width += GRID_SIZE;
		}
		
		if(obj.width == 0) objects.splice(objects.indexOf(obj), 1);
	}else if(keyCode == 39) { // Right
		var obj = getObjectClosestTo(mouseX, mouseY);
		if(obj == null) return;
		if(e.shiftKey){
			obj.x += GRID_SIZE;
			obj.width -= GRID_SIZE;
		}else{
			obj.width += GRID_SIZE;
		}
		
		if(obj.width == 0) objects.splice(objects.indexOf(obj), 1);
	}else if(keyCode == 38) { // Up
		var obj = getObjectClosestTo(mouseX, mouseY);
		if(obj == null) return;
		if(e.shiftKey){
			obj.height -= GRID_SIZE;
		}else{
			obj.y -= GRID_SIZE;
			obj.height += GRID_SIZE;
		}
		
		if(obj.height == 0) objects.splice(objects.indexOf(obj), 1);
	}else if(keyCode == 40) { // Down
		var obj = getObjectClosestTo(mouseX, mouseY);
		if(obj == null) return;
		if(e.shiftKey){
			obj.y += GRID_SIZE;
			obj.height -= GRID_SIZE;
		}else{
			obj.height += GRID_SIZE;
		}
		
		if(obj.height == 0) objects.splice(objects.indexOf(obj), 1);
	}
});

return {
	renderEditor: renderEditor,
	initEditor: initEditor
};

})();

var renderEditor = tmp.renderEditor;
var initEditor = tmp.initEditor;
