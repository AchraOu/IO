#ifndef CURSORS_LEVEL006X_H
#define CURSORS_LEVEL006X_H

#include "LevelObjects.h"

class Level0060 : public Level {
public:
	Level0060() : Level(10, 10){}

	void OnInit(){
		std::vector<LevelObject*> wallByColor[7];
		wallByColor[1].push_back(AddObject(new ObjWall(30, 0, 10, 20, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(380, 0, 10, 190, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(20, 10, 10, 20, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(50, 10, 210, 10, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(260, 10, 10, 10, 0x9999FF)));
		wallByColor[1].push_back(AddObject(new ObjWall(270, 10, 100, 10, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(10, 20, 10, 60, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(50, 20, 10, 40, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(360, 20, 10, 150, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(40, 30, 10, 30, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(70, 30, 190, 10, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(260, 30, 10, 10, 0x9999FF)));
		wallByColor[1].push_back(AddObject(new ObjWall(270, 30, 80, 10, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(30, 40, 10, 20, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(340, 40, 10, 110, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(60, 50, 200, 10, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(260, 50, 10, 10, 0x9999FF)));
		wallByColor[1].push_back(AddObject(new ObjWall(110, 60, 10, 80, 0xFF9999)));
		wallByColor[3].push_back(AddObject(new ObjWall(120, 60, 140, 10, 0xFFFF99)));
		wallByColor[1].push_back(AddObject(new ObjWall(20, 70, 80, 10, 0xFF9999)));
		wallByColor[3].push_back(AddObject(new ObjWall(120, 70, 10, 70, 0xFFFF99)));
		wallByColor[1].push_back(AddObject(new ObjWall(130, 70, 130, 60, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(260, 70, 10, 60, 0x9999FF)));
		wallByColor[1].push_back(AddObject(new ObjWall(90, 80, 10, 130, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(10, 90, 70, 20, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(10, 110, 10, 120, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(60, 110, 20, 50, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(30, 120, 20, 90, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(270, 120, 70, 10, 0xFF9999)));
		wallByColor[3].push_back(AddObject(new ObjWall(130, 130, 130, 10, 0xFFFF99)));
		wallByColor[3].push_back(AddObject(new ObjWall(270, 130, 60, 10, 0xFFFF99)));
		wallByColor[1].push_back(AddObject(new ObjWall(330, 130, 10, 160, 0xFF9999)));
		AddObject(new ObjWall(110, 140, 150, 50, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(260, 140, 10, 160, 0x9999FF)));
		AddObject(new ObjWall(270, 140, 10, 160, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(280, 140, 40, 160, 0xFF9999)));
		wallByColor[3].push_back(AddObject(new ObjWall(320, 140, 10, 160, 0xFFFF99)));
		wallByColor[1].push_back(AddObject(new ObjWall(350, 160, 10, 10, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(50, 170, 40, 40, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(340, 180, 40, 10, 0xFF9999)));
		AddObject(new ObjWall(110, 190, 10, 20, 0x000000));
		AddObject(new ObjWall(170, 190, 90, 70, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(20, 220, 90, 10, 0xFF9999)));
		AddObject(new ObjWall(110, 220, 10, 40, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(50, 230, 10, 60, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(90, 230, 20, 30, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(30, 240, 10, 60, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(70, 240, 10, 60, 0xFF9999)));
		AddObject(new ObjWall(120, 240, 50, 20, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(90, 260, 10, 30, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(110, 260, 150, 10, 0x9999FF)));
		AddObject(new ObjWall(110, 270, 150, 30, 0x000000));
		wallByColor[3].push_back(AddObject(new ObjWall(330, 290, 10, 10, 0xFFFF99)));
		AddObject(new ObjClickBox(wallByColor[1], 345, 245, 40, 40, 5, 1000, 0xFF9999));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 340, 190, 50, 50));
		AddObject(new ObjClickBox(wallByColor[2], 295, 45, 40, 40, 5, 1000, 0x9999FF));
		AddObject(new ObjClickBox(wallByColor[3], 125, 195, 40, 40, 5, 1000, 0xFFFF99));
	}
};

class Level0061 : public Level {
public:
	Level0061() : Level(5, 295){}

	void OnInit(){
		std::vector<LevelObject*> wallByColor[7];
		wallByColor[1].push_back(AddObject(new ObjWall(30, 0, 10, 290, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(70, 0, 10, 290, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(130, 0, 30, 60, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(190, 0, 10, 290, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(230, 0, 10, 250, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(270, 0, 10, 230, 0x9999FF)));
		wallByColor[3].push_back(AddObject(new ObjWall(310, 0, 10, 290, 0xFFFF99)));
		wallByColor[3].push_back(AddObject(new ObjWall(350, 0, 10, 290, 0xFFFF99)));
		wallByColor[1].push_back(AddObject(new ObjWall(10, 10, 10, 290, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(50, 10, 10, 290, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(170, 10, 10, 290, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(210, 10, 10, 290, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(250, 10, 10, 240, 0x9999FF)));
		wallByColor[3].push_back(AddObject(new ObjWall(290, 10, 10, 290, 0xFFFF99)));
		wallByColor[3].push_back(AddObject(new ObjWall(330, 10, 10, 290, 0xFFFF99)));
		wallByColor[2].push_back(AddObject(new ObjWall(370, 30, 30, 10, 0x9999FF)));
		wallByColor[1].push_back(AddObject(new ObjWall(90, 50, 10, 250, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(110, 50, 20, 10, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(360, 50, 30, 10, 0x9999FF)));
		wallByColor[1].push_back(AddObject(new ObjWall(110, 60, 10, 230, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(150, 60, 10, 230, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(130, 70, 10, 230, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(370, 70, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(360, 90, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(370, 110, 30, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(360, 130, 30, 10, 0x9999FF)));
		wallByColor[1].push_back(AddObject(new ObjWall(370, 150, 30, 10, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(360, 170, 30, 10, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(370, 190, 30, 10, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(360, 210, 30, 10, 0xFF9999)));
		wallByColor[1].push_back(AddObject(new ObjWall(370, 230, 30, 10, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(260, 240, 20, 10, 0x9999FF)));
		wallByColor[3].push_back(AddObject(new ObjWall(280, 240, 10, 60, 0xFFFF99)));
		wallByColor[2].push_back(AddObject(new ObjWall(270, 250, 10, 50, 0x9999FF)));
		wallByColor[1].push_back(AddObject(new ObjWall(360, 250, 30, 10, 0xFF9999)));
		AddObject(new ObjClickBox(wallByColor[1], 85, 5, 40, 40, 5, 1000, 0xFF9999));
		AddObject(new ObjClickBox(wallByColor[2], 225, 255, 40, 40, 5, 1000, 0x9999FF));
		AddObject(new ObjClickBox(wallByColor[3], 365, 265, 30, 30, 5, 1000, 0xFFFF99));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 370, 0, 30, 30));
	}
};

class Level0062 : public Level {
public:
	Level0062() : Level(200, 150){}

	void OnInit(){
		std::vector<LevelObject*> wallByColor[7];
		wallByColor[2].push_back(AddObject(new ObjWall(0, 0, 190, 10, 0x9999FF)));
		AddObject(new ObjWall(190, 0, 20, 130, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(210, 0, 190, 10, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(0, 10, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(10, 10, 170, 10, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(180, 10, 10, 60, 0x9999FF)));
		wallByColor[1].push_back(AddObject(new ObjWall(210, 10, 10, 60, 0xFF9999)));
		AddObject(new ObjWall(220, 10, 170, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(390, 10, 10, 10, 0xFF9999)));
		AddObject(new ObjWall(50, 20, 130, 50, 0x000000));
		AddObject(new ObjWall(220, 20, 120, 50, 0x000000));
		wallByColor[5].push_back(AddObject(new ObjWall(0, 70, 20, 60, 0xFF99FF)));
		AddObject(new ObjWall(20, 70, 120, 60, 0x000000));
		AddObject(new ObjWall(260, 70, 120, 60, 0x000000));
		wallByColor[6].push_back(AddObject(new ObjWall(380, 70, 20, 60, 0x3333FF)));
		AddObject(new ObjWall(140, 120, 50, 10, 0x000000));
		AddObject(new ObjWall(210, 120, 50, 10, 0x000000));
		AddObject(new ObjWall(0, 180, 180, 20, 0x000000));
		wallByColor[3].push_back(AddObject(new ObjWall(180, 180, 40, 10, 0xFFFF99)));
		AddObject(new ObjWall(220, 180, 180, 20, 0x000000));
		wallByColor[4].push_back(AddObject(new ObjWall(180, 190, 40, 10, 0x99FFFF)));
		AddObject(new ObjWall(0, 200, 170, 100, 0x000000));
		AddObject(new ObjWall(230, 200, 170, 100, 0x000000));
		AddObject(new ObjWall(170, 260, 60, 40, 0x000000));
		AddObject(new ObjClickBox(wallByColor[1], 5, 25, 40, 40, 5, 1000, 0xFF9999));
		AddObject(new ObjClickBox(wallByColor[2], 345, 25, 40, 40, 5, 1000, 0x9999FF));
		AddObject(new ObjClickBox(wallByColor[3], 215, 75, 40, 40, 5, 1000, 0xFFFF99));
		AddObject(new ObjClickBox(wallByColor[4], 145, 75, 40, 40, 5, 1000, 0x99FFFF));
		AddObject(new ObjClickBox(wallByColor[5], 25, 135, 40, 40, 5, 1000, 0xFF99FF));
		AddObject(new ObjClickBox(wallByColor[6], 335, 135, 40, 40, 5, 1000, 0x3333FF));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 170, 200, 60, 60));
	}
};

class Level0063 : public Level {
public:
	Level0063() : Level(390, 202){}

	void OnInit(){
		std::vector<LevelObject*> wallByColor[7];
		wallByColor[2].push_back(AddObject(new ObjWall(50, 0, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(70, 0, 10, 80, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(90, 0, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(110, 0, 10, 120, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(130, 0, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(150, 0, 10, 160, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(170, 0, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(190, 0, 10, 200, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(210, 0, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(230, 0, 10, 240, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(250, 0, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(270, 0, 10, 290, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(290, 0, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(310, 0, 10, 290, 0x000000));
		AddObject(new ObjWall(50, 10, 10, 50, 0x000000));
		AddObject(new ObjWall(90, 10, 10, 90, 0x000000));
		AddObject(new ObjWall(130, 10, 10, 130, 0x000000));
		AddObject(new ObjWall(170, 10, 10, 170, 0x000000));
		AddObject(new ObjWall(210, 10, 10, 210, 0x000000));
		AddObject(new ObjWall(250, 10, 10, 250, 0x000000));
		AddObject(new ObjWall(290, 10, 10, 290, 0x000000));
		AddObject(new ObjWall(330, 10, 60, 10, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(390, 10, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(330, 20, 10, 280, 0x000000));
		AddObject(new ObjWall(350, 30, 50, 10, 0x000000));
		AddObject(new ObjWall(0, 50, 50, 10, 0x000000));
		AddObject(new ObjWall(340, 50, 50, 10, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(390, 50, 10, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(0, 70, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(10, 70, 60, 10, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(340, 70, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(350, 70, 50, 10, 0x000000));
		AddObject(new ObjWall(0, 90, 90, 10, 0x000000));
		AddObject(new ObjWall(340, 90, 50, 10, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(390, 90, 10, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(0, 110, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(10, 110, 100, 10, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(340, 110, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(350, 110, 50, 10, 0x000000));
		AddObject(new ObjWall(0, 130, 130, 10, 0x000000));
		AddObject(new ObjWall(340, 130, 50, 10, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(390, 130, 10, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(0, 150, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(10, 150, 140, 10, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(340, 150, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(350, 150, 50, 10, 0x000000));
		AddObject(new ObjWall(0, 170, 170, 10, 0x000000));
		AddObject(new ObjWall(340, 170, 50, 10, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(0, 190, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(10, 190, 180, 10, 0x000000));
		AddObject(new ObjWall(0, 210, 210, 10, 0x000000));
		wallByColor[1].push_back(AddObject(new ObjWall(340, 220, 60, 20, 0xFF9999)));
		wallByColor[2].push_back(AddObject(new ObjWall(0, 230, 10, 10, 0x9999FF)));
		AddObject(new ObjWall(10, 230, 220, 10, 0x000000));
		AddObject(new ObjWall(0, 250, 250, 10, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(0, 270, 10, 20, 0x9999FF)));
		AddObject(new ObjWall(10, 270, 260, 20, 0x000000));
		wallByColor[2].push_back(AddObject(new ObjWall(310, 290, 10, 10, 0x9999FF)));
		wallByColor[2].push_back(AddObject(new ObjWall(390, 170, 10, 10, 0x9999FF)));
		AddObject(new ObjClickBox(wallByColor[1], 5, 5, 40, 40, 5, 1000, 0xFF9999));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 340, 240, 60, 60));
		AddObject(new ObjClickBox(wallByColor[2], 345, 185, 30, 30, 5, 1000, 0x9999FF));
	}
};

#endif