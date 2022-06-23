
function Cursor(x, y){
	this.oldX = this.newX = x;
	this.oldY = this.newY = y;
	this.time = now;
}

Cursor.prototype = {
	oldX: 0,
	oldY: 0,
	newX: 0,
	newY: 0,
	time: 0,
	
	getX: function(){
		var delta = this.newX - this.oldX;
		var progress = smoothstep(clamp((now - this.time) / INTERP_TIME, 0.0, 1.0));
		return this.oldX + progress * delta;
	},
	
	getY: function(){
		var delta = this.newY - this.oldY;
		var progress = smoothstep(clamp((now - this.time) / INTERP_TIME, 0.0, 1.0));
		return this.oldY + progress * delta;
	}
};
