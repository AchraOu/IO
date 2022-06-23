#ifndef CURSORS_LEVEL005X_H
#define CURSORS_LEVEL005X_H

#include "LevelObjects.h"

class Level0050 : public Level {
public:
	Level0050() : Level(200, 150){}

	void OnInit(){
		std::vector<LevelObject*> wallByColor[7];
		AddObject(new ObjWall(40, 0, 10, 290, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(60, 0, 330, 10, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(50, 10, 10, 260, 0xFF9999)));
		AddObject(new ObjWall(60, 10, 330, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(390, 10, 10, 280, 0xFF9999)));
		AddObject(new ObjWall(60, 20, 10, 250, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(80, 20, 290, 10, 0xFF9999)));
		AddObject(new ObjWall(380, 20, 10, 270, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(70, 30, 10, 220, 0xFF9999)));
		AddObject(new ObjWall(80, 30, 290, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(370, 30, 10, 240, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 40, 10, 20, 0xFF9999)));
		AddObject(new ObjWall(10, 40, 20, 250, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(30, 40, 10, 20, 0xFF9999)));
		AddObject(new ObjWall(80, 40, 10, 210, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(100, 40, 250, 10, 0xFF9999)));
		AddObject(new ObjWall(360, 40, 10, 230, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(90, 50, 10, 180, 0xFF9999)));
		AddObject(new ObjWall(100, 50, 250, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(350, 50, 10, 200, 0xFF9999)));
		AddObject(new ObjWall(100, 60, 10, 170, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(120, 60, 210, 10, 0xFF9999)));
		AddObject(new ObjWall(340, 60, 10, 190, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 70, 10, 30, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(30, 70, 10, 30, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(110, 70, 10, 140, 0xFF9999)));
		AddObject(new ObjWall(120, 70, 210, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(330, 70, 10, 160, 0xFF9999)));
		AddObject(new ObjWall(120, 80, 10, 130, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(140, 80, 170, 10, 0xFF9999)));
		AddObject(new ObjWall(320, 80, 10, 150, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(130, 90, 10, 100, 0xFF9999)));
		AddObject(new ObjWall(140, 90, 170, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(310, 90, 10, 120, 0xFF9999)));
		AddObject(new ObjWall(140, 100, 10, 90, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(160, 100, 130, 10, 0xFF9999)));
		AddObject(new ObjWall(300, 100, 10, 110, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 110, 10, 40, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(30, 110, 10, 40, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(150, 110, 10, 50, 0xFF9999)));
		AddObject(new ObjWall(160, 110, 130, 20, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(290, 110, 10, 80, 0xFF9999)));
		AddObject(new ObjWall(160, 130, 20, 10, 0x000000));
		AddObject(new ObjWall(270, 130, 20, 60, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(160, 140, 20, 20, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 160, 10, 50, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(30, 160, 10, 50, 0xFF9999)));
		AddObject(new ObjWall(150, 160, 30, 30, 0x000000));
		AddObject(new ObjWall(180, 170, 90, 20, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(140, 190, 150, 10, 0xFF9999)));
		AddObject(new ObjWall(130, 200, 170, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(120, 210, 190, 10, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 220, 10, 70, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(30, 220, 10, 70, 0xFF9999)));
		AddObject(new ObjWall(110, 220, 210, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(100, 230, 230, 10, 0xFF9999)));
		AddObject(new ObjWall(90, 240, 250, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(80, 250, 270, 10, 0xFF9999)));
		AddObject(new ObjWall(70, 260, 290, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(60, 270, 310, 10, 0xFF9999)));
		AddObject(new ObjWall(50, 280, 330, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(40, 290, 350, 10, 0xFF9999)));
		AddObject(new ObjClickBox(wallByColor[1], 235, 135, 30, 30, 5, 1000, 0xFF9999));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 0, 0, 40, 40));
	}
};


class Level0051 : public Level {
public:
	Level0051() : Level(200, 10){}

	void OnInit(){
		std::vector<LevelObject*> wallByColor[7];
		wallByColor[3].push_back(AddObject(new ObjWall(10, 0, 10, 20, 0xFFFF99)));
		wallByColor[4].push_back(AddObject(new ObjWall(380, 0, 10, 20, 0x99FFFF)));
		AddObject(new ObjWall(10, 20, 380, 20, 0x000000));
		AddObject(new ObjWall(190, 40, 20, 260, 0x000000));
		AddObject(new ObjWall(0, 50, 140, 30, 0x000000));
		AddObject(new ObjWall(260, 50, 140, 30, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 80, 140, 10, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(260, 80, 140, 10, 0x9999FF)));
		AddObject(new ObjWall(10, 90, 180, 10, 0x000000));
		AddObject(new ObjWall(210, 90, 180, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 100, 190, 10, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(210, 100, 190, 10, 0x9999FF)));
		AddObject(new ObjWall(0, 110, 180, 10, 0x000000));
		AddObject(new ObjWall(220, 110, 180, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 120, 190, 10, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(210, 120, 190, 10, 0x9999FF)));
		AddObject(new ObjWall(10, 130, 180, 10, 0x000000));
		AddObject(new ObjWall(210, 130, 180, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 140, 190, 10, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(210, 140, 190, 10, 0x9999FF)));
		AddObject(new ObjWall(0, 150, 180, 10, 0x000000));
		AddObject(new ObjWall(220, 150, 180, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 160, 190, 10, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(210, 160, 190, 10, 0x9999FF)));
		AddObject(new ObjWall(10, 170, 180, 10, 0x000000));
		AddObject(new ObjWall(210, 170, 180, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 180, 190, 10, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(210, 180, 190, 10, 0x9999FF)));
		AddObject(new ObjWall(0, 190, 180, 10, 0x000000));
		AddObject(new ObjWall(220, 190, 180, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 200, 190, 10, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(210, 200, 190, 10, 0x9999FF)));
		AddObject(new ObjWall(10, 210, 180, 10, 0x000000));
		AddObject(new ObjWall(210, 210, 180, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 220, 190, 10, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(210, 220, 190, 10, 0x9999FF)));
		AddObject(new ObjWall(0, 230, 180, 10, 0x000000));
		AddObject(new ObjWall(220, 230, 180, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 240, 190, 10, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(210, 240, 190, 10, 0x9999FF)));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 250, 10, 50, 0xFF9999)));
		AddObject(new ObjWall(10, 250, 180, 10, 0x000000));
		AddObject(new ObjWall(210, 250, 180, 10, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(390, 250, 10, 50, 0x9999FF)));
		AddObject(new ObjWall(10, 260, 10, 30, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(20, 260, 10, 40, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(40, 260, 10, 40, 0xFF9999)));
		AddObject(new ObjWall(50, 260, 10, 30, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(60, 260, 10, 40, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(80, 260, 10, 40, 0xFF9999)));
		AddObject(new ObjWall(90, 260, 10, 30, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(100, 260, 10, 40, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(120, 260, 10, 40, 0xFF9999)));
		AddObject(new ObjWall(130, 260, 10, 30, 0x000000));
		AddObject(new ObjWall(260, 260, 10, 30, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(270, 260, 10, 40, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(290, 260, 10, 40, 0x9999FF)));
		AddObject(new ObjWall(300, 260, 10, 30, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(310, 260, 10, 40, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(330, 260, 10, 40, 0x9999FF)));
		AddObject(new ObjWall(340, 260, 10, 30, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(350, 260, 10, 40, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(370, 260, 10, 40, 0x9999FF)));
		AddObject(new ObjWall(380, 260, 10, 30, 0x000000));
		AddObject(new ObjWall(30, 270, 10, 30, 0x000000));
		AddObject(new ObjWall(70, 270, 10, 30, 0x000000));
		AddObject(new ObjWall(110, 270, 10, 30, 0x000000));
		AddObject(new ObjWall(280, 270, 10, 30, 0x000000));
		AddObject(new ObjWall(320, 270, 10, 30, 0x000000));
		AddObject(new ObjWall(360, 270, 10, 30, 0x000000));
		AddObject(new ObjClickBox(wallByColor[1], 215, 45, 40, 40, 5, 1000, 0xFF9999));
		AddObject(new ObjClickBox(wallByColor[2], 145, 45, 40, 40, 5, 1000, 0x9999FF));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 210, 260, 40, 40));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 150, 260, 40, 40));
		AddObject(new ObjAreaCounter(wallByColor[4], 360, 0, 30, 20, 1, 0x99FFFF));
		AddObject(new ObjAreaCounter(wallByColor[3], 10, 0, 30, 20, 1, 0xFFFF99));
	}
};

class Level0052 : public Level {
public:
	Level0052() : Level(200, 150){}

	void OnInit(){
		std::vector<LevelObject*> wallByColor[7];
		AddObject(new ObjWall(0, 0, 150, 120, 0x000000));
		AddObject(new ObjWall(200, 0, 20, 130, 0x000000));
		wallByColor[6].push_back(AddObject(new ObjWall(290, 0, 10, 50, 0x3333FF)));
		wallByColor[5].push_back(AddObject(new ObjWall(300, 0, 10, 50, 0xFF99FF)));
		wallByColor[4].push_back(AddObject(new ObjWall(310, 0, 10, 50, 0x99FFFF)));
		wallByColor[3].push_back(AddObject(new ObjWall(320, 0, 10, 50, 0xFFFF99)));
		wallByColor[2].push_back(AddObject(new ObjWall(330, 0, 10, 50, 0x9999FF)));
		wallByColor[1].push_back(AddObject(new ObjWall(340, 0, 10, 50, 0xFF9999)));
		AddObject(new ObjWall(150, 50, 30, 70, 0x000000));
		AddObject(new ObjWall(240, 50, 160, 50, 0x000000));
		AddObject(new ObjWall(240, 100, 110, 30, 0x000000));
		wallByColor[3].push_back(AddObject(new ObjWall(180, 110, 20, 10, 0xFFFF99)));
		AddObject(new ObjWall(0, 120, 30, 30, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(30, 140, 20, 10, 0x9999FF)));
		AddObject(new ObjWall(50, 140, 40, 160, 0x000000));
		wallByColor[5].push_back(AddObject(new ObjWall(90, 140, 20, 10, 0xFF99FF)));
		AddObject(new ObjWall(110, 140, 70, 50, 0x000000));
		AddObject(new ObjWall(320, 150, 80, 50, 0x000000));
		AddObject(new ObjWall(180, 170, 20, 130, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(200, 170, 20, 10, 0xFF9999)));
		AddObject(new ObjWall(220, 170, 80, 80, 0x000000));
		wallByColor[4].push_back(AddObject(new ObjWall(300, 170, 20, 10, 0x99FFFF)));
		AddObject(new ObjWall(140, 190, 40, 110, 0x000000));
		AddObject(new ObjWall(0, 200, 50, 100, 0x000000));
		AddObject(new ObjWall(350, 200, 50, 100, 0x000000));
		AddObject(new ObjWall(90, 240, 50, 60, 0x000000));
		AddObject(new ObjWall(250, 250, 100, 50, 0x000000));
		AddObject(new ObjClickBox(wallByColor[1], 355, 105, 40, 40, 5, 1000, 0xFF9999));
		AddObject(new ObjClickBox(wallByColor[2], 205, 255, 40, 40, 5, 1000, 0x9999FF));
		AddObject(new ObjClickBox(wallByColor[3], 5, 155, 40, 40, 5, 1000, 0xFFFF99));
		AddObject(new ObjClickBox(wallByColor[4], 155, 5, 40, 40, 5, 1000, 0x99FFFF));
		AddObject(new ObjClickBox(wallByColor[5], 305, 205, 40, 40, 5, 1000, 0xFF99FF));
		AddObject(new ObjClickBox(wallByColor[6], 95, 195, 40, 40, 5, 1000, 0x3333FF));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 350, 0, 50, 50));
	}
};

class Level0053 : public Level {
public:
	Level0053() : Level(200, 150){}

	void OnInit(){
		std::vector<LevelObject*> wallByColor[7];
		AddObject(new ObjWall(190, 0, 20, 130, 0x000000));
		AddObject(new ObjWall(40, 10, 140, 40, 0x000000));
		AddObject(new ObjWall(220, 10, 140, 40, 0x000000));
		AddObject(new ObjWall(0, 40, 40, 10, 0x000000));
		AddObject(new ObjWall(360, 40, 40, 10, 0x000000));
		AddObject(new ObjWall(170, 50, 10, 80, 0x000000));
		AddObject(new ObjWall(220, 50, 10, 80, 0x000000));
		AddObject(new ObjWall(40, 60, 120, 70, 0x000000));
		AddObject(new ObjWall(240, 60, 120, 70, 0x000000));
		AddObject(new ObjWall(10, 90, 30, 40, 0x000000));
		AddObject(new ObjWall(360, 90, 30, 40, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(160, 120, 10, 10, 0x9999FF)));
		wallByColor[1].push_back(AddObject(new ObjWall(230, 120, 10, 10, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(150, 130, 10, 10, 0x9999FF)));
		wallByColor[1].push_back(AddObject(new ObjWall(240, 130, 10, 10, 0xFF9999)));
		AddObject(new ObjWall(0, 140, 160, 20, 0x000000));
		AddObject(new ObjWall(240, 140, 160, 20, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(150, 160, 10, 10, 0x9999FF)));
		wallByColor[1].push_back(AddObject(new ObjWall(240, 160, 10, 10, 0xFF9999)));
		AddObject(new ObjWall(10, 170, 150, 40, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(160, 170, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(170, 170, 20, 90, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(190, 170, 20, 10, 0xFF9999)));
		AddObject(new ObjWall(210, 170, 20, 90, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(230, 170, 10, 10, 0xFF9999)));
		AddObject(new ObjWall(240, 170, 150, 40, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(190, 180, 20, 10, 0x9999FF)));
		wallByColor[3].push_back(AddObject(new ObjWall(190, 190, 20, 10, 0xFFFF99)));
		wallByColor[4].push_back(AddObject(new ObjWall(190, 200, 20, 10, 0x99FFFF)));
		AddObject(new ObjWall(40, 210, 120, 30, 0x000000));
		wallByColor[5].push_back(AddObject(new ObjWall(190, 210, 20, 10, 0xFF99FF)));
		AddObject(new ObjWall(240, 210, 120, 30, 0x000000));
		wallByColor[6].push_back(AddObject(new ObjWall(190, 220, 20, 10, 0x3333FF)));
		wallByColor[1].push_back(AddObject(new ObjWall(190, 230, 20, 10, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(190, 240, 20, 10, 0x9999FF)));
		AddObject(new ObjWall(0, 250, 170, 50, 0x000000));
		AddObject(new ObjWall(230, 250, 170, 50, 0x000000));
		AddObject(new ObjWall(170, 260, 10, 40, 0x000000));
		AddObject(new ObjWall(220, 260, 10, 40, 0x000000));
		AddObject(new ObjClickBox(wallByColor[1], 5, 5, 30, 30, 5, 1000, 0xFF9999));
		AddObject(new ObjClickBox(wallByColor[2], 365, 5, 30, 30, 5, 1000, 0x9999FF));
		AddObject(new ObjClickBox(wallByColor[3], 5, 55, 30, 30, 5, 1000, 0xFFFF99));
		AddObject(new ObjClickBox(wallByColor[4], 365, 55, 30, 30, 5, 1000, 0x99FFFF));
		AddObject(new ObjClickBox(wallByColor[5], 5, 215, 30, 30, 5, 1000, 0xFF99FF));
		AddObject(new ObjClickBox(wallByColor[6], 365, 215, 30, 30, 5, 1000, 0x3333FF));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 180, 260, 40, 40));
	}
};

class Level0054 : public Level {
public:
	Level0054() : Level(200, 150){}

	void OnInit(){
		std::vector<LevelObject*> wallByColor[7];
		AddObject(new ObjWall(40, 20, 20, 40, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(60, 20, 20, 10, 0xFF9999)));
		AddObject(new ObjWall(80, 20, 110, 40, 0x000000));
		AddObject(new ObjWall(210, 20, 110, 40, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(320, 20, 20, 10, 0xFF9999)));
		AddObject(new ObjWall(340, 20, 20, 40, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(60, 30, 20, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(320, 30, 20, 10, 0x9999FF)));
		AddObject(new ObjWall(20, 40, 20, 20, 0x000000));
		wallByColor[3].push_back(AddObject(new ObjWall(60, 40, 20, 10, 0xFFFF99)));
		wallByColor[3].push_back(AddObject(new ObjWall(320, 40, 20, 10, 0xFFFF99)));
		AddObject(new ObjWall(360, 40, 20, 20, 0x000000));
		wallByColor[4].push_back(AddObject(new ObjWall(60, 50, 20, 10, 0x99FFFF)));
		wallByColor[4].push_back(AddObject(new ObjWall(320, 50, 20, 10, 0x99FFFF)));
		wallByColor[1].push_back(AddObject(new ObjWall(20, 60, 10, 20, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(30, 60, 10, 20, 0x9999FF)));
		wallByColor[3].push_back(AddObject(new ObjWall(40, 60, 10, 20, 0xFFFF99)));
		wallByColor[4].push_back(AddObject(new ObjWall(50, 60, 10, 20, 0x99FFFF)));
		AddObject(new ObjWall(100, 60, 90, 10, 0x000000));
		AddObject(new ObjWall(210, 60, 90, 10, 0x000000));
		wallByColor[4].push_back(AddObject(new ObjWall(340, 60, 10, 20, 0x99FFFF)));
		wallByColor[3].push_back(AddObject(new ObjWall(350, 60, 10, 20, 0xFFFF99)));
		wallByColor[2].push_back(AddObject(new ObjWall(360, 60, 10, 20, 0x9999FF)));
		wallByColor[1].push_back(AddObject(new ObjWall(370, 60, 10, 20, 0xFF9999)));
		AddObject(new ObjWall(100, 70, 20, 10, 0x000000));
		AddObject(new ObjWall(160, 70, 30, 70, 0x000000));
		AddObject(new ObjWall(210, 70, 30, 70, 0x000000));
		AddObject(new ObjWall(280, 70, 20, 10, 0x000000));
		AddObject(new ObjWall(20, 80, 40, 60, 0x000000));
		wallByColor[5].push_back(AddObject(new ObjWall(100, 80, 20, 20, 0xFF99FF)));
		wallByColor[6].push_back(AddObject(new ObjWall(280, 80, 20, 20, 0x3333FF)));
		AddObject(new ObjWall(340, 80, 40, 60, 0x000000));
		AddObject(new ObjWall(60, 100, 60, 40, 0x000000));
		AddObject(new ObjWall(280, 100, 60, 40, 0x000000));
		AddObject(new ObjWall(120, 110, 40, 30, 0x000000));
		AddObject(new ObjWall(240, 110, 40, 30, 0x000000));
		AddObject(new ObjWall(20, 160, 170, 30, 0x000000));
		AddObject(new ObjWall(210, 160, 170, 30, 0x000000));
		AddObject(new ObjWall(20, 190, 100, 10, 0x000000));
		AddObject(new ObjWall(160, 190, 30, 90, 0x000000));
		AddObject(new ObjWall(210, 190, 30, 90, 0x000000));
		AddObject(new ObjWall(280, 190, 100, 10, 0x000000));
		AddObject(new ObjWall(20, 200, 40, 20, 0x000000));
		wallByColor[6].push_back(AddObject(new ObjWall(100, 200, 20, 20, 0x3333FF)));
		wallByColor[5].push_back(AddObject(new ObjWall(280, 200, 20, 20, 0xFF99FF)));
		AddObject(new ObjWall(340, 200, 40, 20, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(20, 220, 10, 20, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(30, 220, 10, 20, 0x9999FF)));
		wallByColor[3].push_back(AddObject(new ObjWall(40, 220, 10, 20, 0xFFFF99)));
		wallByColor[4].push_back(AddObject(new ObjWall(50, 220, 10, 20, 0x99FFFF)));
		AddObject(new ObjWall(100, 220, 20, 60, 0x000000));
		AddObject(new ObjWall(280, 220, 20, 60, 0x000000));
		wallByColor[4].push_back(AddObject(new ObjWall(340, 220, 10, 20, 0x99FFFF)));
		wallByColor[3].push_back(AddObject(new ObjWall(350, 220, 10, 20, 0xFFFF99)));
		wallByColor[2].push_back(AddObject(new ObjWall(360, 220, 10, 20, 0x9999FF)));
		wallByColor[1].push_back(AddObject(new ObjWall(370, 220, 10, 20, 0xFF9999)));
		AddObject(new ObjWall(120, 230, 40, 50, 0x000000));
		AddObject(new ObjWall(240, 230, 40, 50, 0x000000));
		AddObject(new ObjWall(20, 240, 40, 20, 0x000000));
		wallByColor[4].push_back(AddObject(new ObjWall(60, 240, 20, 10, 0x99FFFF)));
		AddObject(new ObjWall(80, 240, 20, 40, 0x000000));
		AddObject(new ObjWall(300, 240, 20, 40, 0x000000));
		wallByColor[4].push_back(AddObject(new ObjWall(320, 240, 20, 10, 0x99FFFF)));
		AddObject(new ObjWall(340, 240, 40, 20, 0x000000));
		wallByColor[3].push_back(AddObject(new ObjWall(60, 250, 20, 10, 0xFFFF99)));
		wallByColor[3].push_back(AddObject(new ObjWall(320, 250, 20, 10, 0xFFFF99)));
		AddObject(new ObjWall(40, 260, 20, 20, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(60, 260, 20, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(320, 260, 20, 10, 0x9999FF)));
		AddObject(new ObjWall(340, 260, 20, 20, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(60, 270, 20, 10, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(320, 270, 20, 10, 0xFF9999)));
		AddObject(new ObjClickBox(wallByColor[1], 5, 5, 30, 30, 5, 1000, 0xFF9999));
		AddObject(new ObjClickBox(wallByColor[2], 365, 5, 30, 30, 5, 1000, 0x9999FF));
		AddObject(new ObjClickBox(wallByColor[3], 365, 265, 30, 30, 5, 1000, 0xFFFF99));
		AddObject(new ObjClickBox(wallByColor[4], 5, 265, 30, 30, 5, 1000, 0x99FFFF));
		AddObject(new ObjClickBox(wallByColor[5], 305, 65, 30, 30, 5, 1000, 0xFF99FF));
		AddObject(new ObjClickBox(wallByColor[5], 65, 205, 30, 30, 5, 1000, 0xFF99FF));
		AddObject(new ObjClickBox(wallByColor[6], 65, 65, 30, 30, 5, 1000, 0x3333FF));
		AddObject(new ObjClickBox(wallByColor[6], 305, 205, 30, 30, 5, 1000, 0x3333FF));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 120, 190, 40, 40));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 240, 190, 40, 40));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 240, 70, 40, 40));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 120, 70, 40, 40));
	}
};

class Level0055 : public Level {
public:
	Level0055() : Level(200, 150){}

	void OnInit(){
		std::vector<LevelObject*> wallByColor[7];
		wallByColor[1].push_back(AddObject(new ObjWall(0, 0, 70, 10, 0xFF9999)));
		AddObject(new ObjWall(70, 0, 10, 140, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(80, 0, 10, 300, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(100, 0, 10, 300, 0xFF9999)));
		AddObject(new ObjWall(110, 0, 10, 140, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(120, 0, 10, 300, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(140, 0, 10, 300, 0xFF9999)));
		AddObject(new ObjWall(150, 0, 10, 140, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(160, 0, 10, 300, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(180, 0, 10, 300, 0xFF9999)));
		AddObject(new ObjWall(190, 0, 20, 130, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(210, 0, 10, 300, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(230, 0, 10, 300, 0x9999FF)));
		AddObject(new ObjWall(240, 0, 10, 140, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(250, 0, 10, 300, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(270, 0, 10, 300, 0x9999FF)));
		AddObject(new ObjWall(280, 0, 10, 140, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(290, 0, 10, 300, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(310, 0, 10, 300, 0x9999FF)));
		AddObject(new ObjWall(320, 0, 10, 140, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(330, 0, 70, 10, 0x9999FF)));
		AddObject(new ObjWall(10, 10, 50, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(60, 10, 10, 290, 0xFF9999)));
		AddObject(new ObjWall(90, 10, 10, 280, 0x000000));
		AddObject(new ObjWall(130, 10, 10, 280, 0x000000));
		AddObject(new ObjWall(170, 10, 10, 280, 0x000000));
		AddObject(new ObjWall(220, 10, 10, 280, 0x000000));
		AddObject(new ObjWall(260, 10, 10, 280, 0x000000));
		AddObject(new ObjWall(300, 10, 10, 280, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(330, 10, 10, 290, 0x9999FF)));
		AddObject(new ObjWall(340, 10, 50, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 20, 50, 10, 0xFF9999)));
		AddObject(new ObjWall(50, 20, 10, 270, 0x000000));
		AddObject(new ObjWall(340, 20, 10, 270, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(350, 20, 50, 10, 0x9999FF)));
		AddObject(new ObjWall(0, 30, 40, 10, 0x000000));
		AddObject(new ObjWall(360, 30, 40, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 40, 50, 10, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(350, 40, 50, 10, 0x9999FF)));
		AddObject(new ObjWall(10, 50, 40, 10, 0x000000));
		AddObject(new ObjWall(350, 50, 40, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 60, 50, 10, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(350, 60, 50, 10, 0x9999FF)));
		AddObject(new ObjWall(0, 70, 40, 10, 0x000000));
		AddObject(new ObjWall(360, 70, 40, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 80, 50, 10, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(350, 80, 50, 10, 0x9999FF)));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 90, 10, 10, 0xFF9999)));
		AddObject(new ObjWall(10, 90, 40, 10, 0x000000));
		AddObject(new ObjWall(350, 90, 40, 10, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(390, 90, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(70, 160, 10, 140, 0x000000));
		AddObject(new ObjWall(110, 160, 10, 140, 0x000000));
		AddObject(new ObjWall(150, 160, 10, 140, 0x000000));
		AddObject(new ObjWall(240, 160, 10, 140, 0x000000));
		AddObject(new ObjWall(280, 160, 10, 140, 0x000000));
		AddObject(new ObjWall(320, 160, 10, 140, 0x000000));
		AddObject(new ObjWall(190, 170, 20, 130, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 200, 10, 20, 0xFF9999)));
		AddObject(new ObjWall(10, 200, 40, 10, 0x000000));
		AddObject(new ObjWall(350, 200, 40, 10, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(390, 200, 10, 20, 0x9999FF)));
		wallByColor[1].push_back(AddObject(new ObjWall(10, 210, 40, 10, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(350, 210, 40, 10, 0x9999FF)));
		AddObject(new ObjWall(0, 220, 40, 10, 0x000000));
		AddObject(new ObjWall(360, 220, 40, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 230, 50, 10, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(350, 230, 50, 10, 0x9999FF)));
		AddObject(new ObjWall(10, 240, 40, 10, 0x000000));
		AddObject(new ObjWall(350, 240, 40, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 250, 50, 10, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(350, 250, 50, 10, 0x9999FF)));
		AddObject(new ObjWall(0, 260, 40, 10, 0x000000));
		AddObject(new ObjWall(360, 260, 40, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 270, 50, 10, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(350, 270, 50, 10, 0x9999FF)));
		AddObject(new ObjWall(10, 280, 40, 10, 0x000000));
		AddObject(new ObjWall(350, 280, 40, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 290, 60, 10, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(340, 290, 60, 10, 0x9999FF)));
		AddObject(new ObjAreaCounter(wallByColor[1], 200, 0, 200, 300, 1, 0xFF9999));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 350, 100, 50, 100));
		AddObject(new ObjAreaCounter(wallByColor[2], 0, 0, 200, 300, 1, 0x9999FF));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 0, 100, 50, 100));
	}
};

class Level0056 : public Level {
public:
	Level0056() : Level(200, 150){}

	void OnInit(){
		std::vector<LevelObject*> wallByColor[7];
		AddObject(new ObjWall(30, 0, 10, 130, 0x000000));
		AddObject(new ObjWall(70, 0, 10, 130, 0x000000));
		AddObject(new ObjWall(110, 0, 10, 130, 0x000000));
		AddObject(new ObjWall(150, 0, 10, 130, 0x000000));
		AddObject(new ObjWall(190, 0, 20, 130, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(210, 0, 10, 130, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(230, 0, 10, 140, 0xFF9999)));
		AddObject(new ObjWall(240, 0, 10, 130, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(250, 0, 10, 140, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(270, 0, 10, 140, 0xFF9999)));
		AddObject(new ObjWall(280, 0, 10, 130, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(290, 0, 10, 140, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(310, 0, 10, 140, 0xFF9999)));
		AddObject(new ObjWall(320, 0, 10, 130, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(330, 0, 10, 140, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(350, 0, 10, 140, 0xFF9999)));
		AddObject(new ObjWall(360, 0, 10, 130, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(370, 0, 10, 140, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(390, 0, 10, 130, 0xFF9999)));
		AddObject(new ObjWall(10, 10, 10, 280, 0x000000));
		AddObject(new ObjWall(50, 10, 10, 280, 0x000000));
		AddObject(new ObjWall(90, 10, 10, 280, 0x000000));
		AddObject(new ObjWall(130, 10, 10, 280, 0x000000));
		AddObject(new ObjWall(170, 10, 10, 280, 0x000000));
		AddObject(new ObjWall(220, 10, 10, 280, 0x000000));
		AddObject(new ObjWall(260, 10, 10, 280, 0x000000));
		AddObject(new ObjWall(300, 10, 10, 280, 0x000000));
		AddObject(new ObjWall(340, 10, 10, 280, 0x000000));
		AddObject(new ObjWall(380, 10, 10, 280, 0x000000));
		AddObject(new ObjWall(0, 140, 10, 20, 0x000000));
		AddObject(new ObjWall(20, 140, 30, 20, 0x000000));
		AddObject(new ObjWall(60, 140, 30, 20, 0x000000));
		AddObject(new ObjWall(100, 140, 30, 20, 0x000000));
		AddObject(new ObjWall(140, 140, 30, 20, 0x000000));
		AddObject(new ObjWall(230, 140, 30, 20, 0x000000));
		AddObject(new ObjWall(270, 140, 30, 20, 0x000000));
		AddObject(new ObjWall(310, 140, 30, 20, 0x000000));
		AddObject(new ObjWall(350, 140, 30, 20, 0x000000));
		AddObject(new ObjWall(390, 140, 10, 20, 0x000000));
		wallByColor[3].push_back(AddObject(new ObjWall(20, 160, 10, 140, 0xFFFF99)));
		wallByColor[3].push_back(AddObject(new ObjWall(40, 160, 10, 140, 0xFFFF99)));
		wallByColor[3].push_back(AddObject(new ObjWall(60, 160, 10, 140, 0xFFFF99)));
		wallByColor[3].push_back(AddObject(new ObjWall(80, 160, 10, 140, 0xFFFF99)));
		wallByColor[3].push_back(AddObject(new ObjWall(100, 160, 10, 140, 0xFFFF99)));
		wallByColor[3].push_back(AddObject(new ObjWall(120, 160, 10, 140, 0xFFFF99)));
		wallByColor[3].push_back(AddObject(new ObjWall(140, 160, 10, 140, 0xFFFF99)));
		wallByColor[3].push_back(AddObject(new ObjWall(160, 160, 10, 140, 0xFFFF99)));
		wallByColor[2].push_back(AddObject(new ObjWall(230, 160, 10, 140, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(250, 160, 10, 140, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(270, 160, 10, 140, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(290, 160, 10, 140, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(310, 160, 10, 140, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(330, 160, 10, 140, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(350, 160, 10, 140, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(370, 160, 10, 140, 0x9999FF)));
		wallByColor[3].push_back(AddObject(new ObjWall(0, 170, 10, 130, 0xFFFF99)));

		wallByColor[4].push_back(AddObject(new ObjWall(0, 0, 10, 130, 0x99FFFF)));
		wallByColor[4].push_back(AddObject(new ObjWall(20, 0, 10, 140, 0x99FFFF)));
		wallByColor[4].push_back(AddObject(new ObjWall(40, 0, 10, 140, 0x99FFFF)));
		wallByColor[4].push_back(AddObject(new ObjWall(60, 0, 10, 140, 0x99FFFF)));
		wallByColor[4].push_back(AddObject(new ObjWall(80, 0, 10, 140, 0x99FFFF)));
		wallByColor[4].push_back(AddObject(new ObjWall(100, 0, 10, 140, 0x99FFFF)));
		wallByColor[4].push_back(AddObject(new ObjWall(120, 0, 10, 140, 0x99FFFF)));
		wallByColor[4].push_back(AddObject(new ObjWall(140, 0, 10, 140, 0x99FFFF)));
		wallByColor[4].push_back(AddObject(new ObjWall(160, 0, 10, 140, 0x99FFFF)));
		wallByColor[4].push_back(AddObject(new ObjWall(180, 0, 10, 130, 0x99FFFF)));

		AddObject(new ObjWall(30, 170, 10, 130, 0x000000));
		AddObject(new ObjWall(70, 170, 10, 130, 0x000000));
		AddObject(new ObjWall(110, 170, 10, 130, 0x000000));
		AddObject(new ObjWall(150, 170, 10, 130, 0x000000));
		wallByColor[3].push_back(AddObject(new ObjWall(180, 170, 10, 130, 0xFFFF99)));
		AddObject(new ObjWall(190, 170, 20, 130, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(210, 170, 10, 130, 0x9999FF)));
		AddObject(new ObjWall(240, 170, 10, 130, 0x000000));
		AddObject(new ObjWall(280, 170, 10, 130, 0x000000));
		AddObject(new ObjWall(320, 170, 10, 130, 0x000000));
		AddObject(new ObjWall(360, 170, 10, 130, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(390, 170, 10, 130, 0x9999FF)));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 0, 160, 10, 10));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 390, 160, 10, 10));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 390, 130, 10, 10));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 0, 130, 10, 10));
		AddObject(new ObjAreaCounter(wallByColor[1], 0, 0, 190, 140, 1, 0xFF9999));
		AddObject(new ObjAreaCounter(wallByColor[2], 210, 0, 190, 140, 1, 0x9999FF));
		AddObject(new ObjAreaCounter(wallByColor[3], 210, 160, 190, 140, 1, 0xFFFF99));
		AddObject(new ObjAreaCounter(wallByColor[4], 0, 160, 190, 140, 1, 0x99FFFF));
	}
};

class Level0057 : public Level {
public:
	Level0057() : Level(395, 295){}

	void OnInit(){
		std::vector<LevelObject*> wallByColor[7];
		wallByColor[3].push_back(AddObject(new ObjWall(30, 0, 10, 300, 0xFFFF99)));
		AddObject(new ObjWall(40, 0, 10, 290, 0x000000));
		wallByColor[3].push_back(AddObject(new ObjWall(50, 0, 10, 300, 0xFFFF99)));
		wallByColor[2].push_back(AddObject(new ObjWall(70, 0, 10, 300, 0x9999FF)));
		AddObject(new ObjWall(80, 0, 10, 290, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(90, 0, 10, 300, 0x9999FF)));
		wallByColor[1].push_back(AddObject(new ObjWall(110, 0, 10, 300, 0xFF9999)));
		AddObject(new ObjWall(120, 0, 10, 290, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(130, 0, 10, 300, 0xFF9999)));
		AddObject(new ObjWall(160, 0, 10, 290, 0x000000));
		AddObject(new ObjWall(200, 0, 10, 290, 0x000000));
		AddObject(new ObjWall(240, 0, 10, 290, 0x000000));
		AddObject(new ObjWall(280, 0, 10, 290, 0x000000));
		AddObject(new ObjWall(320, 0, 10, 290, 0x000000));
		AddObject(new ObjWall(360, 0, 10, 290, 0x000000));
		wallByColor[4].push_back(AddObject(new ObjWall(0, 10, 20, 270, 0x99FFFF)));
		AddObject(new ObjWall(20, 10, 10, 290, 0x000000));
		AddObject(new ObjWall(60, 10, 10, 290, 0x000000));
		AddObject(new ObjWall(100, 10, 10, 290, 0x000000));
		AddObject(new ObjWall(140, 10, 10, 290, 0x000000));
		AddObject(new ObjWall(180, 10, 10, 290, 0x000000));
		AddObject(new ObjWall(220, 10, 10, 290, 0x000000));
		AddObject(new ObjWall(260, 10, 10, 290, 0x000000));
		AddObject(new ObjWall(300, 10, 10, 290, 0x000000));
		AddObject(new ObjWall(340, 10, 10, 290, 0x000000));
		AddObject(new ObjWall(380, 10, 10, 290, 0x000000));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 0, 280, 20, 20));
		AddObject(new ObjAreaCounter(wallByColor[1], 310, 0, 70, 300, 1, 0xFF9999));
		AddObject(new ObjAreaCounter(wallByColor[2], 230, 0, 70, 300, 1, 0x9999FF));
		AddObject(new ObjAreaCounter(wallByColor[3], 150, -10, 70, 310, 1, 0xFFFF99));
		AddObject(new ObjAreaCounter(wallByColor[4], 30, 0, 110, 300, 1, 0x99FFFF));
	}
};

class Level0058 : public Level {
public:
	Level0058() : Level(200, 150){}

	void OnInit(){
		std::vector<LevelObject*> wallByColor[7];
		AddObject(new ObjWall(190, 0, 10, 30, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(210, 0, 10, 10, 0xFF9999)));
		AddObject(new ObjWall(230, 0, 10, 30, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(250, 0, 10, 10, 0xFF9999)));
		AddObject(new ObjWall(270, 0, 10, 30, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(290, 0, 10, 10, 0xFF9999)));
		AddObject(new ObjWall(310, 0, 10, 110, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(340, 0, 20, 20, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 10, 10, 10, 0xFF9999)));
		AddObject(new ObjWall(10, 10, 170, 10, 0x000000));
		AddObject(new ObjWall(210, 10, 10, 40, 0x000000));
		AddObject(new ObjWall(250, 10, 10, 40, 0x000000));
		AddObject(new ObjWall(290, 10, 10, 40, 0x000000));
		AddObject(new ObjWall(170, 20, 10, 40, 0x000000));
		AddObject(new ObjWall(330, 20, 30, 120, 0x000000));
		AddObject(new ObjWall(0, 30, 160, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(160, 30, 10, 10, 0xFF9999)));
		AddObject(new ObjWall(180, 40, 30, 10, 0x000000));
		AddObject(new ObjWall(220, 40, 30, 10, 0x000000));
		AddObject(new ObjWall(260, 40, 30, 10, 0x000000));
		AddObject(new ObjWall(360, 40, 40, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 50, 10, 10, 0xFF9999)));
		AddObject(new ObjWall(10, 50, 160, 10, 0x000000));
		AddObject(new ObjWall(180, 50, 10, 90, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(190, 60, 10, 10, 0xFF9999)));
		AddObject(new ObjWall(200, 60, 110, 10, 0x000000));
		AddObject(new ObjWall(0, 70, 170, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(170, 70, 10, 10, 0xFF9999)));
		AddObject(new ObjWall(190, 80, 110, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(300, 80, 10, 10, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 90, 10, 10, 0xFF9999)));
		AddObject(new ObjWall(10, 90, 170, 10, 0x000000));
		AddObject(new ObjWall(360, 90, 20, 50, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(190, 100, 10, 10, 0xFF9999)));
		AddObject(new ObjWall(200, 100, 110, 10, 0x000000));
		AddObject(new ObjWall(0, 110, 170, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(170, 110, 10, 10, 0xFF9999)));
		AddObject(new ObjWall(190, 120, 140, 20, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(0, 130, 10, 10, 0xFF9999)));
		AddObject(new ObjWall(10, 130, 170, 10, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(0, 160, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(10, 160, 370, 10, 0x000000));
		AddObject(new ObjWall(180, 170, 200, 10, 0x000000));
		AddObject(new ObjWall(0, 180, 170, 10, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(170, 180, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(180, 180, 10, 80, 0x000000));
		AddObject(new ObjWall(330, 180, 50, 30, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(190, 190, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(200, 190, 120, 10, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(0, 200, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(10, 200, 170, 10, 0x000000));
		AddObject(new ObjWall(310, 200, 10, 100, 0x000000));
		AddObject(new ObjWall(190, 210, 110, 10, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(300, 210, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(330, 210, 30, 70, 0x000000));
		AddObject(new ObjWall(0, 220, 170, 10, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(170, 220, 10, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(190, 230, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(200, 230, 110, 10, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(0, 240, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(10, 240, 170, 10, 0x000000));
		AddObject(new ObjWall(170, 250, 10, 40, 0x000000));
		AddObject(new ObjWall(190, 250, 110, 10, 0x000000));
		AddObject(new ObjWall(360, 250, 40, 10, 0x000000));
		AddObject(new ObjWall(0, 260, 160, 10, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(160, 260, 10, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(190, 260, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(210, 260, 10, 30, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(230, 260, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(250, 260, 10, 30, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(270, 260, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(290, 260, 10, 30, 0x000000));
		AddObject(new ObjWall(190, 270, 10, 30, 0x000000));
		AddObject(new ObjWall(230, 270, 10, 30, 0x000000));
		AddObject(new ObjWall(270, 270, 10, 30, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(0, 280, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(10, 280, 160, 10, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(340, 280, 20, 20, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(290, 290, 10, 10, 0x9999FF)));
		AddObject(new ObjClickBox(wallByColor[1], 365, 55, 30, 30, 5, 1000, 0xFF9999));
		AddObject(new ObjClickBox(wallByColor[2], 365, 215, 30, 30, 5, 1000, 0x9999FF));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 360, 260, 40, 40));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 360, 0, 40, 40));
	}
};

class Level0059 : public Level {
public:
	Level0059() : Level(200, 150){}

	void OnInit(){
		std::vector<LevelObject*> wallByColor[7];
		AddObject(new ObjWall(90, 0, 10, 40, 0x000000));
		AddObject(new ObjWall(130, 0, 10, 40, 0x000000));
		AddObject(new ObjWall(170, 0, 10, 120, 0x000000));
		AddObject(new ObjWall(220, 0, 10, 120, 0x000000));
		AddObject(new ObjWall(260, 0, 10, 40, 0x000000));
		AddObject(new ObjWall(300, 0, 10, 40, 0x000000));
		AddObject(new ObjWall(60, 10, 20, 10, 0x000000));
		AddObject(new ObjWall(110, 10, 10, 50, 0x000000));
		AddObject(new ObjWall(150, 10, 10, 50, 0x000000));
		AddObject(new ObjWall(240, 10, 10, 50, 0x000000));
		AddObject(new ObjWall(280, 10, 10, 50, 0x000000));
		AddObject(new ObjWall(320, 10, 20, 10, 0x000000));
		AddObject(new ObjWall(60, 20, 10, 60, 0x000000));
		AddObject(new ObjWall(330, 20, 10, 60, 0x000000));
		AddObject(new ObjWall(80, 30, 10, 30, 0x000000));
		AddObject(new ObjWall(310, 30, 10, 30, 0x000000));
		wallByColor[4].push_back(AddObject(new ObjWall(180, 40, 40, 20, 0x99FFFF)));
		AddObject(new ObjWall(0, 50, 60, 30, 0x000000));
		AddObject(new ObjWall(100, 50, 10, 30, 0x000000));
		AddObject(new ObjWall(120, 50, 30, 10, 0x000000));
		AddObject(new ObjWall(250, 50, 30, 10, 0x000000));
		AddObject(new ObjWall(290, 50, 10, 30, 0x000000));
		AddObject(new ObjWall(340, 50, 60, 30, 0x000000));
		wallByColor[3].push_back(AddObject(new ObjWall(180, 60, 40, 20, 0xFFFF99)));
		AddObject(new ObjWall(70, 70, 30, 10, 0x000000));
		AddObject(new ObjWall(120, 70, 50, 10, 0x000000));
		AddObject(new ObjWall(230, 70, 50, 10, 0x000000));
		AddObject(new ObjWall(300, 70, 30, 10, 0x000000));
		AddObject(new ObjWall(120, 80, 10, 20, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(180, 80, 40, 20, 0x9999FF)));
		AddObject(new ObjWall(270, 80, 10, 20, 0x000000));
		AddObject(new ObjWall(10, 90, 110, 10, 0x000000));
		AddObject(new ObjWall(140, 90, 20, 10, 0x000000));
		AddObject(new ObjWall(240, 90, 20, 10, 0x000000));
		AddObject(new ObjWall(280, 90, 110, 10, 0x000000));
		AddObject(new ObjWall(140, 100, 10, 20, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(180, 100, 40, 20, 0xFF9999)));
		AddObject(new ObjWall(250, 100, 10, 20, 0x000000));
		AddObject(new ObjWall(0, 110, 140, 10, 0x000000));
		AddObject(new ObjWall(160, 110, 10, 30, 0x000000));
		AddObject(new ObjWall(230, 110, 10, 30, 0x000000));
		AddObject(new ObjWall(260, 110, 140, 10, 0x000000));
		AddObject(new ObjWall(10, 130, 150, 10, 0x000000));
		AddObject(new ObjWall(240, 130, 150, 10, 0x000000));
		wallByColor[5].push_back(AddObject(new ObjWall(160, 140, 10, 20, 0xFF99FF)));
		wallByColor[5].push_back(AddObject(new ObjWall(230, 140, 10, 20, 0xFF99FF)));
		AddObject(new ObjWall(0, 160, 170, 10, 0x000000));
		AddObject(new ObjWall(230, 160, 170, 10, 0x000000));
		AddObject(new ObjWall(130, 170, 40, 20, 0x000000));
		AddObject(new ObjWall(230, 170, 40, 20, 0x000000));
		AddObject(new ObjWall(10, 180, 110, 10, 0x000000));
		AddObject(new ObjWall(170, 180, 10, 110, 0x000000));
		wallByColor[5].push_back(AddObject(new ObjWall(180, 180, 10, 10, 0xFF99FF)));
		AddObject(new ObjWall(190, 180, 20, 120, 0x000000));
		wallByColor[5].push_back(AddObject(new ObjWall(210, 180, 10, 10, 0xFF99FF)));
		AddObject(new ObjWall(220, 180, 10, 110, 0x000000));
		AddObject(new ObjWall(280, 180, 110, 10, 0x000000));
		AddObject(new ObjWall(110, 190, 10, 110, 0x000000));
		AddObject(new ObjWall(130, 190, 10, 100, 0x000000));
		AddObject(new ObjWall(260, 190, 10, 100, 0x000000));
		AddObject(new ObjWall(280, 190, 10, 110, 0x000000));
		AddObject(new ObjWall(0, 200, 100, 10, 0x000000));
		AddObject(new ObjWall(150, 200, 10, 100, 0x000000));
		AddObject(new ObjWall(240, 200, 10, 100, 0x000000));
		AddObject(new ObjWall(300, 200, 100, 10, 0x000000));
		AddObject(new ObjWall(90, 210, 10, 80, 0x000000));
		AddObject(new ObjWall(300, 210, 10, 80, 0x000000));
		AddObject(new ObjWall(10, 220, 70, 10, 0x000000));
		AddObject(new ObjWall(320, 220, 70, 10, 0x000000));
		AddObject(new ObjWall(70, 230, 10, 70, 0x000000));
		AddObject(new ObjWall(320, 230, 10, 70, 0x000000));
		AddObject(new ObjWall(0, 240, 60, 10, 0x000000));
		AddObject(new ObjWall(340, 240, 60, 10, 0x000000));
		AddObject(new ObjWall(50, 250, 10, 40, 0x000000));
		AddObject(new ObjWall(340, 250, 10, 40, 0x000000));
		AddObject(new ObjAreaCounter(wallByColor[5], 170, 120, 60, 60, 1, 0xFF99FF));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 180, 0, 40, 40));
		AddObject(new ObjClickBox(wallByColor[1], 5, 5, 40, 40, 5, 1000, 0xFF9999));
		AddObject(new ObjClickBox(wallByColor[2], 355, 5, 40, 40, 5, 1000, 0x9999FF));
		AddObject(new ObjClickBox(wallByColor[3], 355, 255, 40, 40, 5, 1000, 0xFFFF99));
		AddObject(new ObjClickBox(wallByColor[4], 5, 255, 40, 40, 5, 1000, 0x99FFFF));
	}
};

#endif