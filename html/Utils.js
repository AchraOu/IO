
function clamp(v, min, max){
	if(v <= min) return min;
	if(v >= max) return max;
	return v;
}

function smoothstep(x){
	return x * x * (3 - 2 * x);
}

function mergeTo(to, from){
	for(var i in from){
		if(!from.hasOwnProperty(i)) continue;
		to[i] = from[i];
	}
	return to;
}
