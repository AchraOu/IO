

var zeroSolidMap = new Uint8Array(WIDTH * HEIGHT);


Array.prototype.remove = function(elem){
	var i = this.indexOf(elem);
	if(i != -1){
		this.splice(i, 1);
		return true;
	}
	return false;
}

function line(x1, y1, x2, y2){
	x1 = x1|0;
	y1 = y1|0;
	x2 = x2|0;
	y2 = y2|0;
	if(isSolid(x1, y1)) return {x: x1, y: y1};
	
	if(x1 == x2 && y1 == y2) return {x: x2, y: y2};
	
	var lastX = x1;
	var lastY = y1;
	
	var w = (x2 - x1)|0;
	var h = (y2 - y1)|0;
	var x = x1;
	var y = y1;
	var dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0;
	if(w < 0) dx1 = -1; else if(w > 0) dx1 = 1;
	if(h < 0) dy1 = -1; else if(h > 0) dy1 = 1;
	if(w < 0) dx2 = -1; else if(w > 0) dx2 = 1;
	
	var longest = Math.abs(w)|0;
	var shortest = Math.abs(h)|0;
	if (longest <= shortest) {
		longest = Math.abs(h)|0;
		shortest = Math.abs(w)|0;
		if(h < 0) {
			dy2 = -1;
		}else if(h > 0){
			dy2 = 1;
		}
		dx2 = 0;
	}
	
	var numerator = longest >> 1;
	for (var i = 0; i <= longest; i++) {
		if(isSolid(x, y)) break;
		
		lastX = x;
		lastY = y;
		
		numerator += shortest;
		if(numerator >= longest) {
			numerator -= longest;
			x += dx1;
			y += dy1;
		} else {
			x += dx2;
			y += dy2;
		}
	}
	
	return { x: lastX, y: lastY };
}

function canTraceLine(x1, y1, x2, y2){
	var p = line(x1, y1, x2, y2);
	return p.x == x2 && p.y == y2;
}

function isSolid(x, y){
	if(x < 0 || x >= WIDTH) return true;
	if(y < 0 || y >= HEIGHT) return true;
	return solidMap[x + y * WIDTH];
}

function getUnstuckPosition(x, y){
	var queue = [];
	
	var hasExplored = new Uint8Array(WIDTH * HEIGHT);

	queue.push([x, y]);
	hasExplored[x + y * WIDTH] = 1;
	do{
		var node = queue.shift();
		var px = node[0];
		var py = node[1];
		
		if(px < 0 || py < 0 || px >= WIDTH || py >= HEIGHT) continue;
		
		
		if(!isSolid(px, py)){
			return { x: px, y: py };
		}
		
		if(!hasExplored[(px - 1) + (py) * WIDTH]) {
			queue.push([px - 1, py]);
			hasExplored[(px - 1) + (py) * WIDTH] = 1;
		}
		
		if(!hasExplored[(px + 1) + (py) * WIDTH]) {
			queue.push([px + 1, py]);
			hasExplored[(px + 1) + (py) * WIDTH] = 1;
		}
		
		if(!hasExplored[(px) + (py - 1) * WIDTH]) {
			queue.push([px, py - 1]);
			hasExplored[(px) + (py - 1) * WIDTH] = 1;
		}
		
		if(!hasExplored[(px) + (py + 1) * WIDTH]) {
			queue.push([px, py + 1]);
			hasExplored[(px) + (py + 1) * WIDTH] = 1;
		}
		
		
	}while(queue.length > 0);
	
	// Couldn't unstuck
	return { x: x, y: y};
}
