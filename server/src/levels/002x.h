#ifndef CURSORS_LEVEL002X_H
#define CURSORS_LEVEL002X_H

#include "LevelObjects.h"

class Level0020 : public Level {
public:
	Level0020() : Level(200, 275){}

	void OnInit(){
		std::vector<LevelObject*> wallByColor[7];
		AddObject(new ObjWall(0, 0, 400, 100, 0x000000));
		AddObject(new ObjWall(150, 100, 25, 150, 0x000000));
		AddObject(new ObjWall(225, 100, 25, 150, 0x000000));
		AddObject(new ObjWall(50, 150, 100, 100, 0x000000));
		AddObject(new ObjWall(250, 150, 100, 100, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(0, 175, 50, 25, 0x9999ff)));
		wallByColor[2].push_back(AddObject(new ObjWall(350, 175, 50, 25, 0x9999ff)));
		wallByColor[3].push_back(AddObject(new ObjWall(175, 200, 50, 25, 0xffff99)));
		wallByColor[1].push_back(AddObject(new ObjWall(175, 225, 50, 25, 0xff9999)));

		AddObject(new ObjAreaCounter(wallByColor[2], 180, 255, 40, 40, 1, 0x9999ff));
		AddObject(new ObjClickBox(wallByColor[1], 105, 105, 40, 40, 5, 1000, 0xff9999));
		AddObject(new ObjClickBox(wallByColor[3], 255, 105, 40, 40, 5, 1000, 0xffff99));

		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 175, 100, 50, 50));
	}
};

class Level0021 : public Level {
public:
	Level0021() : Level(201, 297){}

	void OnInit(){
		std::vector<LevelObject*> wallByColor[7];
		wallByColor[3].push_back(AddObject(new ObjWall(0, 50, 50, 20, 0xFFFF99)));
		AddObject(new ObjWall(50, 50, 300, 40, 0x000000));
		wallByColor[4].push_back(AddObject(new ObjWall(350, 50, 50, 20, 0x99FFFF)));
		AddObject(new ObjWall(180, 90, 40, 170, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 140, 50, 20, 0xFF9999)));
		AddObject(new ObjWall(50, 140, 130, 30, 0x000000));
		AddObject(new ObjWall(220, 140, 130, 30, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(350, 140, 50, 20, 0x9999FF)));
		AddObject(new ObjWall(50, 220, 130, 40, 0x000000));
		AddObject(new ObjWall(220, 220, 130, 40, 0x000000));
		wallByColor[5].push_back(AddObject(new ObjWall(50, 260, 20, 40, 0xFF99FF)));
		wallByColor[6].push_back(AddObject(new ObjWall(330, 260, 20, 40, 0xFF99FF)));
		AddObject(new ObjWall(160, 280, 20, 20, 0x000000));
		AddObject(new ObjWall(220, 280, 20, 20, 0x000000));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 200, 0, 50, 50));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 150, 0, 50, 50));
		AddObject(new ObjAreaCounter(wallByColor[6], 304, 260, 40, 40, 1, 0xFF99FF));
		AddObject(new ObjAreaCounter(wallByColor[5], 56, 260, 40, 40, 1, 0xFF99FF));
		AddObject(new ObjClickBox(wallByColor[1], 225, 175, 40, 40, 10, 1000, 0xFF9999));
		AddObject(new ObjClickBox(wallByColor[2], 135, 175, 40, 40, 10, 1000, 0x9999FF));
		AddObject(new ObjClickBox(wallByColor[4], 135, 95, 40, 40, 10, 1000, 0x99FFFF));
		AddObject(new ObjClickBox(wallByColor[3], 225, 95, 40, 40, 10, 1000, 0xFFFF99));
	}
};

class Level0022 : public Level {
public:
	Level0022() : Level(186, 273){}

	void OnInit(){
		std::vector<LevelObject*> wallByColor[7];
		wallByColor[2].push_back(AddObject(new ObjWall(330, 0, 20, 50, 0x9999FF)));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 50, 50, 20, 0xFF9999)));
		AddObject(new ObjWall(50, 50, 350, 130, 0x000000));
		AddObject(new ObjWall(50, 180, 300, 70, 0x000000));
		wallByColor[4].push_back(AddObject(new ObjWall(50, 250, 20, 50, 0x99FFFF)));
		wallByColor[3].push_back(AddObject(new ObjWall(290, 250, 20, 50, 0xFFFF99)));
		wallByColor[2].push_back(AddObject(new ObjWall(310, 250, 20, 50, 0x9999FF)));
		wallByColor[1].push_back(AddObject(new ObjWall(330, 250, 20, 50, 0xFF9999)));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 350, 180, 50, 50));
		AddObject(new ObjClickBox(wallByColor[1], 5, 255, 40, 40, 10, 1000, 0xFF9999));
		AddObject(new ObjClickBox(wallByColor[2], 5, 5, 40, 40, 10, 1000, 0x9999FF));
		AddObject(new ObjClickBox(wallByColor[3], 355, 5, 40, 40, 10, 1000, 0xFFFF99));
		AddObject(new ObjClickBox(wallByColor[4], 245, 255, 40, 40, 10, 1000, 0x99FFFF));
	}
};

class Level0023 : public Level {
public:
	Level0023() : Level(200, 220){}

	void OnInit(){
		std::vector<LevelObject*> wallByColor[7];
		AddObject(new ObjWall(100, 0, 50, 120, 0x000000));
		AddObject(new ObjWall(250, 0, 50, 120, 0x000000));
		AddObject(new ObjWall(40, 40, 20, 150, 0x000000));
		AddObject(new ObjWall(340, 40, 20, 150, 0x000000));
		AddObject(new ObjWall(150, 100, 30, 20, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(180, 100, 40, 20, 0xFF9999)));
		AddObject(new ObjWall(220, 100, 30, 20, 0x000000));
		AddObject(new ObjWall(160, 120, 20, 70, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(180, 120, 40, 20, 0x9999FF)));
		AddObject(new ObjWall(220, 120, 20, 130, 0x000000));
		AddObject(new ObjWall(60, 170, 100, 20, 0x000000));
		AddObject(new ObjWall(240, 170, 100, 20, 0x000000));
		AddObject(new ObjWall(170, 190, 10, 60, 0x000000));
		AddObject(new ObjWall(0, 210, 150, 10, 0x000000));
		AddObject(new ObjWall(260, 210, 140, 10, 0x000000));
		wallByColor[3].push_back(AddObject(new ObjWall(0, 220, 170, 20, 0xFFFF99)));
		wallByColor[3].push_back(AddObject(new ObjWall(240, 220, 160, 20, 0xFFFF99)));
		wallByColor[3].push_back(AddObject(new ObjWall(0, 240, 20, 50, 0xFFFF99)));
		AddObject(new ObjWall(20, 240, 150, 10, 0x000000));
		AddObject(new ObjWall(240, 240, 140, 10, 0x000000));
		wallByColor[3].push_back(AddObject(new ObjWall(380, 240, 20, 50, 0xFFFF99)));
		AddObject(new ObjWall(20, 250, 10, 20, 0x000000));
		AddObject(new ObjWall(370, 250, 10, 20, 0x000000));
		AddObject(new ObjWall(30, 260, 150, 10, 0x000000));
		AddObject(new ObjWall(220, 260, 150, 10, 0x000000));
		wallByColor[3].push_back(AddObject(new ObjWall(20, 270, 360, 20, 0xFFFF99)));
		AddObject(new ObjWall(0, 290, 400, 10, 0x000000));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 150, 0, 100, 100));
		AddObject(new ObjClickBox(wallByColor[1], 115, 125, 40, 40, 10, 1000, 0xFF9999));
		AddObject(new ObjClickBox(wallByColor[2], 245, 125, 40, 40, 10, 1000, 0x9999FF));
		AddObject(new ObjClickBox(wallByColor[3], 185, 145, 30, 30, 5, 1000, 0xFFFF99));
	}
};

class Level0024 : public Level {
public:
	Level0024() : Level(395, 6){}

	void OnInit(){
		std::vector<LevelObject*> wallByColor[7];
		AddObject(new ObjWall(10, 10, 130, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(140, 10, 20, 10, 0xFF9999)));
		AddObject(new ObjWall(160, 10, 240, 10, 0x000000));
		AddObject(new ObjWall(10, 20, 10, 270, 0x000000));
		AddObject(new ObjWall(30, 30, 110, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(140, 30, 20, 10, 0xFF9999)));
		AddObject(new ObjWall(160, 30, 230, 10, 0x000000));
		AddObject(new ObjWall(30, 40, 10, 230, 0x000000));
		AddObject(new ObjWall(380, 40, 10, 250, 0x000000));
		AddObject(new ObjWall(50, 50, 90, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(140, 50, 20, 10, 0xFF9999)));
		AddObject(new ObjWall(160, 50, 210, 10, 0x000000));
		AddObject(new ObjWall(50, 60, 10, 190, 0x000000));
		AddObject(new ObjWall(360, 60, 10, 210, 0x000000));
		AddObject(new ObjWall(70, 70, 70, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(140, 70, 20, 10, 0xFF9999)));
		AddObject(new ObjWall(160, 70, 190, 10, 0x000000));
		AddObject(new ObjWall(70, 80, 10, 150, 0x000000));
		AddObject(new ObjWall(340, 80, 10, 170, 0x000000));
		AddObject(new ObjWall(90, 90, 50, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(140, 90, 20, 10, 0xFF9999)));
		AddObject(new ObjWall(160, 90, 170, 10, 0x000000));
		AddObject(new ObjWall(90, 100, 10, 110, 0x000000));
		AddObject(new ObjWall(320, 100, 10, 130, 0x000000));
		AddObject(new ObjWall(110, 110, 30, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(140, 110, 20, 10, 0xFF9999)));
		AddObject(new ObjWall(160, 110, 150, 10, 0x000000));
		AddObject(new ObjWall(110, 120, 10, 70, 0x000000));
		AddObject(new ObjWall(300, 120, 10, 90, 0x000000));
		AddObject(new ObjWall(130, 130, 10, 40, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(140, 130, 20, 10, 0xFF9999)));
		AddObject(new ObjWall(160, 130, 130, 10, 0x000000));
		AddObject(new ObjWall(280, 140, 10, 50, 0x000000));
		AddObject(new ObjWall(140, 160, 130, 10, 0x000000));
		AddObject(new ObjWall(120, 180, 160, 10, 0x000000));
		AddObject(new ObjWall(100, 200, 200, 10, 0x000000));
		AddObject(new ObjWall(80, 220, 240, 10, 0x000000));
		AddObject(new ObjWall(60, 240, 280, 10, 0x000000));
		AddObject(new ObjWall(40, 260, 320, 10, 0x000000));
		AddObject(new ObjWall(20, 280, 360, 10, 0x000000));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 140, 140, 20, 20));
		AddObject(new ObjAreaCounter(wallByColor[1], 160, 140, 110, 20, 1, 0xFF9999));
	}
};

class Level0025 : public Level {
public:
	Level0025() : Level(200, 22){}

	void OnInit(){
		std::vector<LevelObject*> wallByColor[7];
		wallByColor[2].push_back(AddObject(new ObjWall(110, 0, 20, 40, 0x9999FF)));
		wallByColor[1].push_back(AddObject(new ObjWall(270, 0, 20, 40, 0xFF9999)));
		AddObject(new ObjWall(40, 40, 320, 20, 0x000000));
		AddObject(new ObjWall(40, 60, 20, 200, 0x000000));
		wallByColor[4].push_back(AddObject(new ObjWall(170, 60, 20, 40, 0x99FFFF)));
		wallByColor[3].push_back(AddObject(new ObjWall(210, 60, 20, 40, 0xFFFF99)));
		AddObject(new ObjWall(340, 60, 20, 200, 0x000000));
		AddObject(new ObjWall(100, 100, 90, 150, 0x000000));
		AddObject(new ObjWall(210, 100, 90, 150, 0x000000));
		AddObject(new ObjWall(100, 250, 70, 50, 0x000000));
		AddObject(new ObjWall(230, 250, 70, 50, 0x000000));
		AddObject(new ObjAreaCounter(wallByColor[1], 250, 0, 40, 40, 1, 0xFF9999));
		AddObject(new ObjAreaCounter(wallByColor[2], 110, 0, 40, 40, 1, 0x9999FF));
		AddObject(new ObjAreaCounter(wallByColor[3], 130, 60, 40, 40, 1, 0xFFFF99));
		AddObject(new ObjAreaCounter(wallByColor[4], 230, 60, 40, 40, 1, 0x99FFFF));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 170, 250, 60, 50));
	}
};

class Level0026 : public Level {
public:
	Level0026() : Level(381, 112){}

	void OnInit(){
		std::vector<LevelObject*> wallByColor[7];
		wallByColor[2].push_back(AddObject(new ObjWall(70, 0, 10, 50, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(110, 0, 10, 50, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(150, 0, 10, 50, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(190, 0, 10, 50, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(230, 0, 10, 50, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(270, 0, 10, 50, 0x9999FF)));
		wallByColor[4].push_back(AddObject(new ObjWall(350, 0, 10, 40, 0x99FFFF)));
		wallByColor[2].push_back(AddObject(new ObjWall(50, 10, 10, 70, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(90, 10, 10, 70, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(130, 10, 10, 70, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(170, 10, 10, 70, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(210, 10, 10, 70, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(250, 10, 10, 70, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(290, 10, 10, 70, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(310, 40, 40, 10, 0x9999FF)));
		AddObject(new ObjWall(350, 40, 10, 140, 0x000000));
		AddObject(new ObjWall(360, 40, 40, 10));
		wallByColor[2].push_back(AddObject(new ObjWall(0, 50, 50, 20, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(60, 60, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(100, 60, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(140, 60, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(180, 60, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(220, 60, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(260, 60, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(300, 60, 40, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(330, 70, 10, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(30, 80, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(70, 80, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(110, 80, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(150, 80, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(190, 80, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(230, 80, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(270, 80, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(310, 80, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(10, 90, 20, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(40, 90, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(80, 90, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(120, 90, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(160, 90, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(200, 90, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(240, 90, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(280, 90, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(320, 90, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(10, 110, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(50, 110, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(90, 110, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(130, 110, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(170, 110, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(210, 110, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(250, 110, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(290, 110, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(330, 110, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(0, 120, 10, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(20, 120, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(60, 120, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(100, 120, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(140, 120, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(180, 120, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(220, 120, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(260, 120, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(300, 120, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(30, 140, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(70, 140, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(110, 140, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(150, 140, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(190, 140, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(230, 140, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(270, 140, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(310, 140, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(10, 150, 20, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(40, 150, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(80, 150, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(120, 150, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(160, 150, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(200, 150, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(240, 150, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(280, 150, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(320, 150, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(10, 170, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(50, 170, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(90, 170, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(130, 170, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(170, 170, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(210, 170, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(250, 170, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(290, 170, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(330, 170, 10, 30, 0x9999FF)));
		wallByColor[5].push_back(AddObject(new ObjWall(360, 170, 40, 10, 0xFF99FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(0, 180, 10, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(20, 180, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(60, 180, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(100, 180, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(140, 180, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(180, 180, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(220, 180, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(260, 180, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(300, 180, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(350, 180, 10, 110, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(30, 200, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(70, 200, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(110, 200, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(150, 200, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(190, 200, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(230, 200, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(270, 200, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(310, 200, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(10, 210, 20, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(40, 210, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(80, 210, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(120, 210, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(160, 210, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(200, 210, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(240, 210, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(280, 210, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(320, 210, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(10, 230, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(50, 230, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(90, 230, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(130, 230, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(170, 230, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(210, 230, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(250, 230, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(290, 230, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(330, 230, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(0, 240, 10, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(20, 240, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(60, 240, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(100, 240, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(140, 240, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(180, 240, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(220, 240, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(260, 240, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(300, 240, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(30, 260, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(70, 260, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(110, 260, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(150, 260, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(190, 260, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(230, 260, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(270, 260, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(310, 260, 10, 30, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(10, 270, 20, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(40, 270, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(80, 270, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(120, 270, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(160, 270, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(200, 270, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(240, 270, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(280, 270, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(320, 270, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(10, 290, 10, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(50, 290, 10, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(90, 290, 10, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(130, 290, 10, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(170, 290, 10, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(210, 290, 10, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(250, 290, 10, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(290, 290, 10, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(330, 290, 10, 10, 0x9999FF)));
		AddObject(new ObjAreaCounter(wallByColor[5], 360, 140, 40, 40, 1, 0xFF99FF));
		AddObject(new ObjAreaCounter(wallByColor[2], 360, 0, 40, 40, 1, 0x3333FF));
		AddObject(new ObjAreaCounter(wallByColor[4], 310, 0, 40, 40, 1, 0x99FFFF));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 0, 0, 50, 50));
	}
};

class Level0027 : public Level {
public:
	Level0027() : Level(200, 150){}

	void OnInit(){
		std::vector<LevelObject*> wallByColor[7];
		AddObject(new ObjWall(130, 0, 270, 10, 0x000000));
		AddObject(new ObjWall(130, 10, 20, 40, 0x000000));
		wallByColor[4].push_back(AddObject(new ObjWall(0, 20, 20, 20, 0x99FFFF)));
		AddObject(new ObjWall(20, 20, 110, 20, 0x000000));
		AddObject(new ObjWall(170, 30, 210, 20, 0x000000));
		AddObject(new ObjWall(80, 40, 50, 10, 0x000000));
		AddObject(new ObjWall(80, 50, 20, 230, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(130, 50, 20, 20, 0x9999FF)));
		AddObject(new ObjWall(170, 50, 20, 40, 0x000000));
		AddObject(new ObjWall(300, 50, 20, 230, 0x000000));
		AddObject(new ObjWall(0, 60, 60, 20, 0x000000));
		AddObject(new ObjWall(120, 70, 50, 20, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(190, 70, 20, 20, 0xFF9999)));
		AddObject(new ObjWall(210, 70, 70, 20, 0x000000));
		AddObject(new ObjWall(340, 70, 60, 20, 0x000000));
		AddObject(new ObjWall(120, 90, 20, 140, 0x000000));
		AddObject(new ObjWall(260, 90, 20, 140, 0x000000));
		AddObject(new ObjWall(20, 100, 60, 20, 0x000000));
		AddObject(new ObjWall(320, 110, 60, 20, 0x000000));
		AddObject(new ObjWall(0, 140, 60, 20, 0x000000));
		AddObject(new ObjWall(340, 150, 60, 20, 0x000000));
		AddObject(new ObjWall(20, 180, 60, 20, 0x000000));
		AddObject(new ObjWall(320, 190, 60, 20, 0x000000));
		AddObject(new ObjWall(140, 210, 120, 20, 0x000000));
		wallByColor[3].push_back(AddObject(new ObjWall(340, 210, 20, 20, 0xFFFF99)));
		AddObject(new ObjWall(0, 220, 60, 20, 0x000000));
		AddObject(new ObjWall(340, 230, 60, 70, 0x000000));
		AddObject(new ObjWall(100, 250, 200, 30, 0x000000));
		AddObject(new ObjWall(20, 260, 60, 20, 0x000000));
		AddObject(new ObjClickBox(wallByColor[1], 215, 95, 40, 40, 10, 1000, 0xFF9999));
		AddObject(new ObjClickBox(wallByColor[2], 145, 95, 40, 40, 10, 1000, 0x9999FF));
		AddObject(new ObjClickBox(wallByColor[3], 145, 165, 40, 40, 10, 1000, 0xFFFF99));
		AddObject(new ObjClickBox(wallByColor[4], 215, 165, 40, 40, 10, 1000, 0x99FFFF));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 110, 0, 20, 20));
	}
};

class Level0028 : public Level {
public:
	Level0028() : Level(171, 151){}

	void OnInit(){
		std::vector<LevelObject*> wallByColor[7];
		AddObject(new ObjWall(350, 0, 10, 30, 0x000000));
		AddObject(new ObjWall(20, 20, 170, 10, 0x000000));
		AddObject(new ObjWall(210, 20, 140, 10, 0x000000));
		AddObject(new ObjWall(370, 20, 10, 120, 0x000000));
		AddObject(new ObjWall(20, 30, 10, 90, 0x000000));
		AddObject(new ObjWall(180, 30, 10, 250, 0x000000));
		AddObject(new ObjWall(210, 30, 10, 90, 0x000000));
		AddObject(new ObjWall(40, 40, 10, 80, 0x000000));
		AddObject(new ObjWall(60, 40, 110, 10, 0x000000));
		AddObject(new ObjWall(230, 40, 130, 10, 0x000000));
		wallByColor[3].push_back(AddObject(new ObjWall(50, 50, 110, 10, 0xFFFF99)));
		AddObject(new ObjWall(160, 50, 10, 70, 0x000000));
		AddObject(new ObjWall(230, 50, 10, 20, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(240, 50, 110, 10, 0xFF9999)));
		AddObject(new ObjWall(350, 50, 10, 70, 0x000000));
		wallByColor[3].push_back(AddObject(new ObjWall(50, 60, 10, 50, 0xFFFF99)));
		AddObject(new ObjWall(60, 60, 90, 10, 0x000000));
		wallByColor[3].push_back(AddObject(new ObjWall(150, 60, 10, 50, 0xFFFF99)));
		AddObject(new ObjWall(220, 60, 10, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(240, 60, 10, 30, 0xFF9999)));
		AddObject(new ObjWall(250, 60, 90, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(340, 60, 10, 50, 0xFF9999)));
		AddObject(new ObjWall(60, 70, 10, 30, 0x000000));
		wallByColor[3].push_back(AddObject(new ObjWall(90, 70, 50, 20, 0xFFFF99)));
		AddObject(new ObjWall(140, 70, 10, 30, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(250, 70, 80, 10, 0xFF9999)));
		AddObject(new ObjWall(330, 70, 10, 30, 0x000000));
		AddObject(new ObjWall(230, 80, 10, 60, 0x000000));
		AddObject(new ObjWall(250, 80, 10, 20, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(260, 80, 70, 10, 0xFF9999)));
		AddObject(new ObjWall(70, 90, 50, 10, 0x000000));
		wallByColor[3].push_back(AddObject(new ObjWall(120, 90, 10, 20, 0xFFFF99)));
		AddObject(new ObjWall(130, 90, 10, 30, 0x000000));
		AddObject(new ObjWall(240, 90, 10, 10, 0x000000));
		AddObject(new ObjWall(260, 90, 70, 10, 0x000000));
		wallByColor[3].push_back(AddObject(new ObjWall(60, 100, 60, 10, 0xFFFF99)));
		wallByColor[3].push_back(AddObject(new ObjWall(140, 100, 10, 10, 0xFFFF99)));
		wallByColor[1].push_back(AddObject(new ObjWall(240, 100, 100, 10, 0xFF9999)));
		AddObject(new ObjWall(30, 110, 10, 10, 0x000000));
		AddObject(new ObjWall(50, 110, 80, 10, 0x000000));
		AddObject(new ObjWall(140, 110, 20, 10, 0x000000));
		AddObject(new ObjWall(250, 110, 100, 10, 0x000000));
		AddObject(new ObjWall(0, 130, 180, 10, 0x000000));
		AddObject(new ObjWall(190, 130, 40, 10, 0x000000));
		AddObject(new ObjWall(240, 130, 130, 10, 0x000000));
		AddObject(new ObjWall(20, 160, 160, 10, 0x000000));
		AddObject(new ObjWall(210, 160, 190, 10, 0x000000));
		AddObject(new ObjWall(20, 170, 10, 90, 0x000000));
		AddObject(new ObjWall(210, 170, 10, 90, 0x000000));
		AddObject(new ObjWall(370, 170, 10, 90, 0x000000));
		AddObject(new ObjWall(40, 180, 110, 10, 0x000000));
		AddObject(new ObjWall(160, 180, 20, 10, 0x000000));
		AddObject(new ObjWall(230, 180, 140, 10, 0x000000));
		AddObject(new ObjWall(40, 190, 10, 90, 0x000000));
		AddObject(new ObjWall(160, 190, 10, 20, 0x000000));
		AddObject(new ObjWall(230, 190, 10, 50, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(240, 190, 120, 10, 0x9999FF)));
		AddObject(new ObjWall(60, 200, 100, 10, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(240, 200, 10, 30, 0x9999FF)));
		AddObject(new ObjWall(250, 200, 110, 10, 0x000000));
		AddObject(new ObjWall(60, 210, 10, 30, 0x000000));
		AddObject(new ObjWall(140, 210, 10, 10, 0x000000));
		AddObject(new ObjWall(250, 210, 10, 10, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(260, 210, 90, 10, 0x9999FF)));
		AddObject(new ObjWall(350, 210, 10, 50, 0x000000));
		AddObject(new ObjWall(160, 220, 10, 40, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(250, 220, 80, 10, 0x9999FF)));
		AddObject(new ObjWall(330, 220, 10, 20, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(340, 220, 10, 30, 0x9999FF)));
		AddObject(new ObjWall(70, 230, 80, 10, 0x000000));
		AddObject(new ObjWall(240, 230, 90, 10, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(230, 240, 110, 10, 0x9999FF)));
		AddObject(new ObjWall(50, 250, 90, 10, 0x000000));
		AddObject(new ObjWall(150, 250, 10, 10, 0x000000));
		AddObject(new ObjWall(230, 250, 120, 10, 0x000000));
		AddObject(new ObjWall(230, 260, 10, 20, 0x000000));
		AddObject(new ObjWall(0, 270, 40, 10, 0x000000));
		AddObject(new ObjWall(60, 270, 120, 10, 0x000000));
		AddObject(new ObjWall(190, 270, 40, 10, 0x000000));
		AddObject(new ObjWall(240, 270, 140, 10, 0x000000));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 70, 70, 30, 20));
		AddObject(new ObjAreaCounter(wallByColor[2], 0, 140, 180, 140, 1, 0x9999FF));
		AddObject(new ObjAreaCounter(wallByColor[1], 190, 140, 220, 140, 1, 0xFF9999));
		AddObject(new ObjAreaCounter(wallByColor[3], 190, 0, 210, 140, 1, 0xFFFF99));
	}
};

class Level0029 : public Level {
public:
	Level0029() : Level(15, 125){}

	void OnInit(){
		std::vector<LevelObject*> wallByColor[7];
		AddObject(new ObjWall(0, 0, 400, 10, 0x000000));
		AddObject(new ObjWall(0, 10, 80, 100, 0x000000));
		AddObject(new ObjWall(320, 10, 80, 100, 0x000000));
		AddObject(new ObjWall(80, 100, 190, 10, 0x000000));
		wallByColor[4].push_back(AddObject(new ObjWall(270, 100, 30, 10, 0x99FFFF)));
		AddObject(new ObjWall(300, 100, 20, 10, 0x000000));
		AddObject(new ObjWall(0, 140, 390, 10, 0x000000));
		AddObject(new ObjWall(10, 160, 390, 10, 0x000000));
		AddObject(new ObjWall(0, 180, 390, 10, 0x000000));
		AddObject(new ObjWall(10, 200, 390, 10, 0x000000));
		AddObject(new ObjWall(0, 220, 390, 10, 0x000000));
		AddObject(new ObjWall(10, 240, 390, 10, 0x000000));
		AddObject(new ObjWall(10, 250, 10, 40, 0x000000));
		AddObject(new ObjWall(50, 250, 10, 40, 0x000000));
		AddObject(new ObjWall(90, 250, 10, 40, 0x000000));
		AddObject(new ObjWall(130, 250, 10, 40, 0x000000));
		AddObject(new ObjWall(170, 250, 10, 40, 0x000000));
		AddObject(new ObjWall(210, 250, 10, 40, 0x000000));
		AddObject(new ObjWall(250, 250, 10, 40, 0x000000));
		AddObject(new ObjWall(290, 250, 10, 40, 0x000000));
		AddObject(new ObjWall(330, 250, 70, 30, 0x000000));
		AddObject(new ObjWall(30, 260, 10, 40, 0x000000));
		AddObject(new ObjWall(70, 260, 10, 40, 0x000000));
		AddObject(new ObjWall(110, 260, 10, 40, 0x000000));
		AddObject(new ObjWall(150, 260, 10, 40, 0x000000));
		AddObject(new ObjWall(190, 260, 10, 40, 0x000000));
		AddObject(new ObjWall(230, 260, 10, 40, 0x000000));
		AddObject(new ObjWall(270, 260, 10, 40, 0x000000));
		AddObject(new ObjWall(310, 260, 10, 40, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(370, 280, 10, 20, 0xFF9999)));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 80, 10, 170, 90));
		AddObject(new ObjClickBox(wallByColor[1], 270, 40, 30, 30, 1, 1000, 0xFF9999));
		AddObject(new ObjAreaCounter(wallByColor[1], 360, 280, 20, 20, 1, 0xFF9999));
		AddObject(new ObjAreaCounter(wallByColor[4], 380, 280, 20, 20, 1, 0x99FFFF));
	}
};


#endif