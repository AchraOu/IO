(function(window, document){
"use strict";
/** @const */
var DEBUG = false;

var LOCALHOST = window.location.protocol == "file:";

/** @const */
var WIDTH = 400;
/** @const */
var HEIGHT = 300;

/** @const */
var CANVAS_WIDTH = 800;
/** @const */
var CANVAS_HEIGHT = 600;

function fakeX(x){ return x >> 1; }
function fakeY(y){ return y >> 1; }
function realX(x){ return x << 1; }
function realY(y){ return y << 1; }

var canvas, ctx;
var eventContainer;

var numCursors = 0;
var mouseX = 0;
var mouseY = 0;
var realMouseX = 0;
var realMouseY = 0;
var cursorX = 0;
var cursorY = 0;
var lastCursorX = -1;
var lastCursorY = -1;
var noCursorLock = null;
var noDrawings = null;
var cursorImg = new Image();
cursorImg.src = "img/cursor.png";

var myCursorImg = cursorImg;
//myCursorImg.src = "img/my_cursor.png";

var inEditor = window.location.search.indexOf('editor') != -1;

var clicks = [];
var lines = [];

var now = 0;
var lastClick = 0;

var socket = null;

var myId = -1;

var cursors = {};


var INTERP_TIME = 100;

var globalNumCursors = 0;

var isOverflowing = false;
var isDrawing = false;
var lastDrawingX = 0;
var lastDrawingY = 0;
var lastSentLine = 0;
var wasPointerLocked = false;
var ignoringMouseMove = false;
var waitingForFirstClick = !inEditor && !DEBUG;

var solidMap = new Uint8Array(WIDTH * HEIGHT);

var objects = [];

var ignoreNextClickAt = [];

var canvasScale = window.devicePixelRatio;

Array.prototype.remove = function(elem){
	var i = this.indexOf(elem);
	if(i != -1){
		this.splice(i, 1);
		return true;
	}
	return false;
}


function isPointerLocked(){
	return document.pointerLockElement === eventContainer
	    || document.mozPointerLockElement === eventContainer
	    || document.webkitPointerLockElement === eventContainer;
}

function grabPointer(){
	if(inEditor) return;
	if(noCursorLock.checked) return;
	if(!eventContainer.requestPointerLock) return;
	eventContainer.requestPointerLock();
}

function isDrawingEnabled(){ return !noDrawings.checked; }

function init(){
	canvas = document.getElementById('canvas');
	ctx = canvas.getContext('2d');
	eventContainer = document.getElementById('canvasContainer') || canvas;
	
	try{
		if(window.top.location.origin != window.location.origin){
			unallowedOrigin();
		}
	}catch(e){
		unallowedOrigin();
	}
	
	canvas.width = 800 * canvasScale;
	canvas.height = 600 * canvasScale;
	ctx.scale(canvasScale, canvasScale);
	
	eventContainer.onmousemove = onMouseMove;
	eventContainer.onmousedown = onMouseDown;
	eventContainer.onmouseup = onMouseUp;
	
	noCursorLock = document.getElementById('noCursorLock');
	noDrawings = document.getElementById('noDrawings');
	
	if(localStorage != null){
		noCursorLock.checked = window.localStorage.getItem("noCursorLock") == "1" ? true : false;
		noDrawings.checked = window.localStorage.getItem("noDrawings") == "1" ? true : false;
	}
	window.onbeforeunload = save;
	
	
	eventContainer.requestPointerLock = eventContainer.requestPointerLock || eventContainer.mozRequestPointerLock || eventContainer.webkitRequestPointerLock;
	
	canvas.style.cursor = 'none';
	
	initEditor();
	
	if(!inEditor){
		connectToServer();
	}
	
	setInterval(sendPosition, 1000 / 20);
	
	nextFrame(draw);
}

function unallowedOrigin(){
	ctx.fillStyle = '#000000';
	ctx.font = '35px NovaSquare';
	
	var txt = "Please do not embed our website, thank you.";
	ctx.fillText(txt, CANVAS_WIDTH / 2 - ctx.measureText(txt).width / 2, CANVAS_HEIGHT / 2);
	
	ctx.font = '16px NovaSquare';
	var txt2 = "Play the game on http://cursors.io/";
	ctx.fillText(txt2, CANVAS_WIDTH / 2 - ctx.measureText(txt2).width / 2, CANVAS_HEIGHT / 2 + 30);
	
	top.location = "http://cursors.io";
	throw txt;
}

function onMouseMove(e){
	updateMousePos(e);
}

function setMousePos(x, y){
	lastCursorX = x;
	lastCursorY = y;
	
	cursorX = mouseX = x;
	cursorY = mouseY = y;
	realMouseX = realX(mouseX);
	realMouseY = realY(mouseY);
	
}

function onMouseDown(e){
	if(inEditor){
		waitingForFirstClick = false;
		updateMousePos(e);
		return false;
	}
	
	if(!isPointerLocked()){
		wasPointerLocked = false;
		grabPointer();
		
	}else if(!wasPointerLocked){
		wasPointerLocked = true;
		setMousePos(cursorX, cursorY);
	}
	
	if(waitingForFirstClick){
		waitingForFirstClick = false;
		sendPosition();
	}else{
		updateMousePos(e);
		if((e.ctrlKey || e.shiftKey) && isDrawingEnabled()){
			isDrawing = true;
			lastDrawingX = cursorX;
			lastDrawingY = cursorY;
		}else{
			if(now - lastClick > 100 && mouseX == cursorX && mouseY == cursorY){
				lastClick = now;
				addClick(mouseX, mouseY);
				sendClick(mouseX, mouseY);
				var c = [mouseX, mouseY];
				ignoreNextClickAt.push(c);
				setTimeout(function(){
					ignoreNextClickAt.remove(c);
				}, 1000);
			}
		}
	}
	
	return false;
}

function onMouseUp(e){
	isDrawing = false;
}

function connectToServer(){
	if(socket != null) return;
	
	function onServerFound(ipv4, ipv6){
		socket = new WebSocket("ws://" + (ipv4 || ("[" + ipv6 + "]")) + ":" + 2828);
		socket.binaryType = "arraybuffer";
		socket.onopen = onSocketOpen;
		socket.onmessage = onSocketMessage;
		socket.onclose = onSocketClose;
		socket.onerror = onSocketError;
	}
	
	if(LOCALHOST){
		onServerFound("127.0.0.1", null);
	}else{
		m28n.findServerPreference("cursors", function(err, servers){
			if(socket != null) return;
			if(err || servers.length == 0){
				console.error(err);
				setTimeout(connectToServer, 1000);
				return;
			}
			
			onServerFound(servers[0].ipv4, servers[0].ipv6);
		});
	}
}

function save(){
	if(!window.localStorage) return;
	if(!noCursorLock) return;
	
	window.localStorage.setItem("noCursorLock", noCursorLock.checked ? "1" : "0");
	window.localStorage.setItem("noDrawings", noDrawings.checked ? "1" : "0");
}

function updateMousePos(e){
	if(ignoringMouseMove) return;
	// Get the new mouse position
	if(isPointerLocked()){
		var mx = e.webkitMovementX || e.mozMovementX || e.movementX || 0;
		var my = e.webkitMovementY || e.mozMovementY || e.movementY || 0;
		if(Math.abs(mx) + Math.abs(my) < 300){
			updateRealMousePos(realMouseX + mx, realMouseY + my);
		}
	}else{
		if(e.offsetX) {
			updateRealMousePos(e.offsetX, e.offsetY);
		}else if(e.layerX) {
			updateRealMousePos(e.layerX, e.layerY);
		}
	}
	
	
	if(inEditor){
		cursorX = mouseX;
		cursorY = mouseY;
		return;
	}
	
	// Try to move the cursor to the mouse
	checkMouse();
	
	// Fix it if the cursor is bouncing on a wall
	if(isPointerLocked()){
		if(mouseX != cursorX || mouseY != cursorY){
			var adjustX = 0;
			var adjustY = 0;
			if(mouseX > cursorX) adjustX = 1;
			if(mouseY > cursorY) adjustY = 1;
			mouseX = cursorX;
			mouseY = cursorY;
			realMouseX = realX(mouseX) + adjustX;
			realMouseY = realY(mouseY) + adjustY;
		}
	}
	
	// Draw lines if drawing
	if(isDrawing && (lastDrawingX != cursorX || lastDrawingY != cursorY) && now - lastSentLine > 50){
		sendDrawLine(lastDrawingX, lastDrawingY, cursorX, cursorY);
		lastDrawingX = cursorX;
		lastDrawingY = cursorY;
		lastSentLine = now;
	}
}

function updateRealMousePos(x, y){
	realMouseX = x;
	realMouseY = y;
	
	mouseX = fakeX(realMouseX);
	mouseY = fakeY(realMouseY);
}

function checkMouse(){
	var oldCursorX = cursorX;
	var oldCursorY = cursorY;
	
	if(isSolid(cursorX, cursorY)){
		//console.log("Unstucking cursor");
		var pos = getUnstuckPosition(cursorX, cursorY);
		cursorX = pos.x;
		cursorY = pos.y;
	}
	
	if(cursorX != mouseX || cursorY != mouseY){
		var pos = line(cursorX, cursorY, mouseX, mouseY);
		cursorX = pos.x;
		cursorY = pos.y;
	}
	
	if(canTraceLine(lastCursorX, lastCursorY, oldCursorX, oldCursorY)){
		if(!canTraceLine(lastCursorX, lastCursorY, cursorX, cursorY)){
			sendPosition(oldCursorX, oldCursorY);
			sendPosition(cursorX, cursorY);
		}
	}
	
	if(shouldSendPositionImmediately(cursorX, cursorY)) sendPosition();
}

function addClick(x, y){
	clicks.push([ realX(x), realY(y), now ]);
}

function resetMap(){
	solidMap.set(zeroSolidMap);
	objects = [];
	clicks = [];
	lines = [];
}

function setImageSmoothing(v){
	ctx.imageSmoothingEnabled = v;
	ctx.mozImageSmoothingEnabled = v;
	ctx.oImageSmoothingEnabled = v;
	ctx.webkitImageSmoothingEnabled = v;
}

#include "Networking"
#include "Rendering"
#include "Cursor"
#include "Utils"
#include "Editor"
#include "shared"

window.onload = init;
	
})(window, document);
