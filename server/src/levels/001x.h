#ifndef CURSORS_LEVEL001X_H
#define CURSORS_LEVEL001X_H

#include "LevelObjects.h"

class Level0010 : public Level {
public:
	Level0010() : Level(12, 287){}

	void OnInit(){
		AddObject(new ObjWall(25, 25, 25, 275));
		AddObject(new ObjWall(75, 0, 25, 225));
		AddObject(new ObjWall(125, 25, 25, 225));
		AddObject(new ObjWall(75, 250, 300, 25));
		AddObject(new ObjWall(75, 275, 25, 25));
		AddObject(new ObjWall(250, 275, 25, 25));
		AddObject(new ObjWall(175, 0, 25, 225));
		AddObject(new ObjWall(225, 25, 25, 225));
		AddObject(new ObjWall(275, 0, 25, 225));
		AddObject(new ObjWall(325, 25, 25, 225));
		AddObject(new ObjWall(375, 0, 25, 225));

		AddObject(new ObjText("Just delaying the inevitable", 110, 293, false));

		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 275, 275, 50, 25));
	}
};

class Level0011 : public Level {
public:
	Level0011() : Level(12, 287){}

	void OnInit(){
		AddObject(new ObjWall(190, 0, 20, 100));
		AddObject(new ObjWall(190, 200, 20, 100));
		AddObject(new ObjClickBox(new ObjWall(190, 100, 20, 100, 0xFF9999), 25, 125, 50, 50, 50, 1000, 0xFF9999));
		
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 325, 125, 50, 50));
	}
};


class Level0012 : public Level {
public:
	Level0012() : Level(50, 150){}

	void OnInit(){
		AddObject(new ObjWall(225, 0, 175, 125));
		AddObject(new ObjWall(225, 175, 175, 125));
		AddObject(new ObjWall(0, 0, 175, 125));
		AddObject(new ObjWall(0, 175, 175, 125));
		AddObject(new ObjWall(0, 125, 25, 50));
		AddObject(new ObjWall(375, 125, 25, 50));
		AddObject(new ObjWall(175, 0, 50, 25));
		AddObject(new ObjWall(175, 275, 50, 25));

		AddObject(new ObjClickBox(new ObjWall(250, 125, 25, 50, 0xFF9999), 180, 30, 40, 40, 50, 1000, 0xFF9999));
		AddObject(new ObjClickBox(new ObjWall(275, 125, 25, 50, 0x9999FF), 180, 230, 40, 40, 50, 1000, 0x9999FF));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 325, 125, 50, 50));
	}
};


class Level0013 : public Level {
public:
	Level0013() : Level(200, 275){}

	void OnInit(){
		AddObject(new ObjWall(150, 0, 25, 250));
		AddObject(new ObjWall(225, 0, 25, 250));
		AddObject(new ObjWall(100, 50, 25, 250));
		AddObject(new ObjWall(275, 50, 25, 250));
		AddObject(new ObjWall(325, 0, 25, 250));
		AddObject(new ObjWall(50, 0, 25, 250));
		
		AddObject(new ObjClickBox(new ObjWall(175, 225, 50, 25, 0xFF9999), 5, 5, 40, 40, 50, 1000, 0xFF9999));
		AddObject(new ObjClickBox(new ObjWall(175, 200, 50, 25, 0x9999FF), 355, 5, 40, 40, 50, 1000, 0x9999FF));

		auto centerBox = new ObjClickBox(nullptr, 180, 255, 40, 40, 50, 1000, 0xFFFF99);
		centerBox->AddLinkedObject(new ObjWall(50, 250, 25, 50, 0xFFFF99));
		centerBox->AddLinkedObject(new ObjWall(325, 250, 25, 50, 0xFFFF99));
		AddObject(centerBox);

		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 175, 0, 50, 50));
	}
};

class Level0014 : public Level {
public:
	Level0014() : Level(200, 225){}

	void OnInit(){
		AddObject(new ObjWall(0, 150, 25, 25));
		AddObject(new ObjWall(25, 25, 25, 75));
		AddObject(new ObjWall(25, 150, 25, 25));
		AddObject(new ObjWall(25, 200, 25, 25));
		AddObject(new ObjWall(25, 250, 25, 25));
		AddObject(new ObjWall(50, 25, 25, 150));
		AddObject(new ObjWall(50, 200, 25, 25));
		AddObject(new ObjWall(50, 250, 25, 25));
		AddObject(new ObjWall(75, 200, 25, 25));
		AddObject(new ObjWall(75, 250, 25, 25));
		AddObject(new ObjWall(100, 0, 25, 225));
		AddObject(new ObjWall(100, 250, 25, 25));
		AddObject(new ObjWall(125, 0, 25, 150));
		AddObject(new ObjWall(125, 250, 25, 25));
		AddObject(new ObjWall(150, 0, 25, 150));
		AddObject(new ObjWall(150, 175, 25, 100));
		AddObject(new ObjWall(175, 0, 25, 25));
		AddObject(new ObjWall(175, 175, 25, 25));
		AddObject(new ObjWall(200, 0, 25, 25));
		AddObject(new ObjWall(200, 175, 25, 25));
		AddObject(new ObjWall(225, 0, 25, 150));
		AddObject(new ObjWall(225, 175, 25, 100));
		AddObject(new ObjWall(250, 0, 25, 150));
		AddObject(new ObjWall(250, 250, 25, 25));
		AddObject(new ObjWall(275, 0, 25, 225));
		AddObject(new ObjWall(275, 250, 25, 25));
		AddObject(new ObjWall(300, 200, 25, 25));
		AddObject(new ObjWall(300, 250, 25, 25));
		AddObject(new ObjWall(325, 25, 25, 150));
		AddObject(new ObjWall(325, 200, 25, 25));
		AddObject(new ObjWall(325, 250, 25, 25));
		AddObject(new ObjWall(350, 25, 25, 75));
		AddObject(new ObjWall(350, 150, 25, 25));
		AddObject(new ObjWall(350, 200, 25, 25));
		AddObject(new ObjWall(350, 250, 25, 25));
		AddObject(new ObjWall(375, 150, 25, 25));

		AddObject(new ObjTeleport(this, 0, 25, 10, 75, true));
		AddObject(new ObjTeleport(this, 15, 25, 10, 75, true));

		AddObject(new ObjTeleport(this, 375, 25, 10, 75, true));
		AddObject(new ObjTeleport(this, 390, 25, 10, 75, true));

		AddObject(new ObjTeleport(this, 25, 275, 25 * 5, 10, true));
		AddObject(new ObjTeleport(this, 25, 290, 25 * 5, 10, true));

		AddObject(new ObjTeleport(this, 250, 275, 25 * 5, 10, true));
		AddObject(new ObjTeleport(this, 250, 290, 25 * 5, 10, true));

		
		AddObject(new ObjTeleport(this, 75, 25, 6, 25 * 6, true));
		AddObject(new ObjTeleport(this, 75 + 25 - 6, 25, 6, 25 * 6, true));

		AddObject(new ObjTeleport(this, 300, 25, 6, 25 * 6, true));
		AddObject(new ObjTeleport(this, 300 + 25 - 6, 25, 6, 25 * 6, true));
		
		AddObject(new ObjTeleport(this, 25, 225, 25 *4, 6, true));
		AddObject(new ObjTeleport(this, 25, 225 + 25 - 6, 25 *4, 6, true));

		AddObject(new ObjTeleport(this, 275, 225, 25 *4, 6, true));
		AddObject(new ObjTeleport(this, 275, 225 + 25 - 6, 25 *4, 6, true));

		AddObject(new ObjClickBox(new ObjWall(175, 125, 50, 25, 0xFF9999), 5, 105, 40, 40, 10, 1000, 0xFF9999, 9000));
		AddObject(new ObjClickBox(new ObjWall(175, 100, 50, 25, 0x9999FF), 355, 105, 40, 40, 10, 1000, 0x9999FF, 9000));

		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 175, 25, 50, 50));
	}
};

class Level0015 : public Level {
public:
	Level0015() : Level(262, 132){}

	void OnInit(){
		AddObject(new ObjWall(0, 50, 25, 100));
		AddObject(new ObjWall(25, 175, 25, 100));
		AddObject(new ObjWall(50, 0, 25, 275));
		AddObject(new ObjWall(75, 0, 25, 25));
		AddObject(new ObjWall(75, 200, 25, 25));
		AddObject(new ObjWall(100, 0, 25, 25));
		AddObject(new ObjWall(100, 50, 25, 125));
		AddObject(new ObjWall(100, 200, 25, 25));
		AddObject(new ObjWall(100, 250, 25, 50));
		AddObject(new ObjWall(125, 0, 25, 25));
		AddObject(new ObjWall(125, 50, 25, 25));
		AddObject(new ObjWall(125, 150, 25, 25));
		AddObject(new ObjWall(125, 200, 25, 25));
		AddObject(new ObjWall(125, 250, 25, 50));
		AddObject(new ObjWall(150, 0, 25, 25));
		AddObject(new ObjWall(150, 50, 25, 25));
		AddObject(new ObjWall(150, 100, 25, 25));
		AddObject(new ObjWall(150, 150, 25, 25));
		AddObject(new ObjWall(150, 200, 25, 25));
		AddObject(new ObjWall(150, 275, 25, 25));
		AddObject(new ObjWall(175, 0, 25, 25));
		AddObject(new ObjWall(175, 50, 25, 25));
		AddObject(new ObjWall(175, 100, 25, 25));
		AddObject(new ObjWall(175, 150, 25, 25));
		AddObject(new ObjWall(175, 200, 25, 50));
		AddObject(new ObjWall(175, 275, 25, 25));
		AddObject(new ObjWall(200, 0, 25, 25));
		AddObject(new ObjWall(200, 50, 25, 25));
		AddObject(new ObjWall(200, 100, 25, 25));
		AddObject(new ObjWall(200, 150, 25, 25));
		AddObject(new ObjWall(225, 0, 25, 25));
		AddObject(new ObjWall(225, 50, 25, 25));
		AddObject(new ObjWall(225, 100, 25, 25));
		AddObject(new ObjWall(225, 150, 25, 150));
		AddObject(new ObjWall(250, 0, 25, 25));
		AddObject(new ObjWall(250, 50, 25, 25));
		AddObject(new ObjWall(250, 100, 25, 25));
		AddObject(new ObjWall(250, 150, 25, 50));
		AddObject(new ObjWall(250, 275, 25, 25));
		AddObject(new ObjWall(275, 0, 25, 25));
		AddObject(new ObjWall(275, 50, 25, 25));
		AddObject(new ObjWall(275, 100, 25, 100));
		AddObject(new ObjWall(275, 225, 25, 25));
		AddObject(new ObjWall(275, 275, 25, 25));
		AddObject(new ObjWall(300, 0, 25, 25));
		AddObject(new ObjWall(300, 50, 25, 25));
		AddObject(new ObjWall(300, 225, 25, 25));
		AddObject(new ObjWall(300, 275, 25, 25));
		AddObject(new ObjWall(325, 0, 25, 25));
		AddObject(new ObjWall(325, 50, 25, 200));
		AddObject(new ObjWall(350, 0, 25, 25));
		AddObject(new ObjWall(350, 50, 25, 100));
		AddObject(new ObjWall(350, 225, 25, 50));
		AddObject(new ObjWall(375, 0, 25, 25));
		AddObject(new ObjWall(375, 175, 25, 25));

		AddObject(new ObjTeleport(this, 150, 75, 25 * 6, 8, true));
		AddObject(new ObjTeleport(this, 150, 75 + 25 - 8, 25 * 6, 8, true));

		AddObject(new ObjTeleport(this, 100, 25, 25 * 11, 10, true));
		AddObject(new ObjTeleport(this, 100, 25 + 25 - 10, 25 * 11, 10, true));

		AddObject(new ObjTeleport(this, 100, 225, 25 * 2, 11, true));
		AddObject(new ObjTeleport(this, 100, 225 + 25 - 11, 25 * 2, 11, true));

		AddObject(new ObjTeleport(this, 100, 175, 25 * 4, 10, true));
		AddObject(new ObjTeleport(this, 100, 175 + 25 - 10, 25 * 4, 10, true));

		AddObject(new ObjTeleport(this, 25,           50, 10, 25 * 4, true));
		AddObject(new ObjTeleport(this, 25 + 25 - 10, 50, 10, 25 * 4, true));

		AddObject(new ObjTeleport(this, 0,           175, 10, 25 * 4, true));
		AddObject(new ObjTeleport(this, 0 + 25 - 10, 175, 10, 25 * 4, true));

		AddObject(new ObjTeleport(this, 350,           175, 11, 25, true));
		AddObject(new ObjTeleport(this, 350 + 25 - 11, 175, 11, 25, true));

		AddObject(new ObjTeleport(this, 375,           50, 10, 25 * 4, true));
		AddObject(new ObjTeleport(this, 375 + 25 - 10, 50, 10, 25 * 4, true));


		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 0, 0, 50, 50));
	}
};

class Level0016 : public Level {
public:
	Level0016() : Level(25, 25){}

	void OnInit(){
		AddObject(new ObjWall(50, 0, 25, 75));
		AddObject(new ObjWall(50, 125, 25, 75));
		AddObject(new ObjWall(50, 250, 25, 25));
		AddObject(new ObjWall(75, 0, 25, 75));
		AddObject(new ObjWall(75, 125, 25, 75));
		AddObject(new ObjWall(75, 250, 25, 25));
		AddObject(new ObjWall(100, 0, 25, 75));
		AddObject(new ObjWall(100, 125, 25, 75));
		AddObject(new ObjWall(100, 250, 25, 25));
		AddObject(new ObjWall(125, 0, 25, 275));
		AddObject(new ObjWall(150, 0, 25, 75));
		AddObject(new ObjWall(150, 125, 25, 75));
		AddObject(new ObjWall(150, 250, 25, 25));
		AddObject(new ObjWall(175, 0, 25, 75));
		AddObject(new ObjWall(175, 125, 25, 75));
		AddObject(new ObjWall(175, 250, 25, 25));
		AddObject(new ObjWall(200, 0, 25, 75));
		AddObject(new ObjWall(200, 125, 25, 75));
		AddObject(new ObjWall(200, 250, 25, 25));
		AddObject(new ObjWall(275, 25, 25, 275));
		AddObject(new ObjWall(300, 25, 25, 275));
		AddObject(new ObjWall(325, 275, 25, 25));
		AddObject(new ObjWall(350, 275, 25, 25));
		AddObject(new ObjWall(375, 0, 25, 300));

		auto c1 = new ObjClickBox(nullptr, 80, 80, 40, 40, 10, 1000, 0xFF9999);
		c1->AddLinkedObject(new ObjWall(0, 150, 50, 25, 0xFF9999));
		c1->AddLinkedObject(new ObjWall(325, 25, 50, 25, 0xFF9999));
		AddObject(c1);

		auto c2 = new ObjClickBox(nullptr, 80, 205, 40, 40, 10, 1000, 0x9999FF);
		c2->AddLinkedObject(new ObjWall(0, 250, 50, 25, 0x9999FF));
		c2->AddLinkedObject(new ObjWall(325, 75, 50, 25, 0x9999FF));
		AddObject(c2);

		auto c3 = new ObjClickBox(nullptr, 155, 205, 40, 40, 10, 1000, 0xFFFF99);
		c3->AddLinkedObject(new ObjWall(225, 150, 50, 25, 0xFFFF99));
		c3->AddLinkedObject(new ObjWall(325, 125, 50, 25, 0xFFFF99));
		AddObject(c3);

		auto c4 = new ObjClickBox(nullptr, 155, 80, 40, 40, 10, 1000, 0x99FFFF);
		c4->AddLinkedObject(new ObjWall(225, 25, 50, 25, 0x99FFFF));
		c4->AddLinkedObject(new ObjWall(325, 175, 50, 25, 0x99FFFF));
		AddObject(c4);


		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 325, 225, 50, 50));
	}

};

class Level0017 : public Level {
public:
	Level0017() : Level(200, 200){}

	void OnInit(){
		AddObject(new ObjWall(0, 50, 25, 250));
		AddObject(new ObjWall(25, 50, 25, 250));
		AddObject(new ObjWall(50, 50, 25, 250));
		AddObject(new ObjWall(75, 50, 25, 250));
		AddObject(new ObjWall(100, 50, 25, 250));
		AddObject(new ObjWall(125, 50, 25, 100));
		AddObject(new ObjWall(125, 275, 25, 25));
		AddObject(new ObjWall(150, 50, 25, 100));
		AddObject(new ObjWall(150, 275, 25, 25));
		AddObject(new ObjWall(175, 275, 25, 25));
		AddObject(new ObjWall(200, 275, 25, 25));
		AddObject(new ObjWall(225, 50, 25, 100));
		AddObject(new ObjWall(225, 275, 25, 25));
		AddObject(new ObjWall(250, 50, 25, 100));
		AddObject(new ObjWall(250, 275, 25, 25));
		AddObject(new ObjWall(275, 50, 25, 250));
		AddObject(new ObjWall(300, 50, 25, 250));
		AddObject(new ObjWall(325, 50, 25, 25));
		AddObject(new ObjWall(325, 150, 25, 150));
		AddObject(new ObjWall(350, 150, 25, 150));
		AddObject(new ObjWall(375, 0, 25, 75));
		AddObject(new ObjWall(375, 150, 25, 150));

		AddObject(new ObjClickBox(new ObjWall(175, 50, 50, 25, 0xFF9999), 162, 170, 75, 75, 300, 300, 0xFF9999));
		AddObject(new ObjClickBox(new ObjWall(75, 0, 25, 50, 0x9999FF), 330, 80, 65, 65, 100, 300, 0x9999FF));


		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 0, 0, 50, 50));
	}
};

class Level0018 : public Level {
public:
	Level0018() : Level(200, 125){}

	void OnInit(){
		AddObject(new ObjWall(0, 0, 25, 100));
		AddObject(new ObjWall(0, 175, 25, 25));
		AddObject(new ObjWall(0, 275, 25, 25));
		AddObject(new ObjWall(25, 0, 25, 100));
		AddObject(new ObjWall(25, 175, 25, 25));
		AddObject(new ObjWall(25, 275, 25, 25));
		AddObject(new ObjWall(50, 0, 25, 100));
		AddObject(new ObjWall(50, 150, 25, 100));
		AddObject(new ObjWall(50, 275, 25, 25));
		AddObject(new ObjWall(75, 0, 25, 100));
		AddObject(new ObjWall(75, 150, 25, 100));
		AddObject(new ObjWall(75, 275, 25, 25));
		AddObject(new ObjWall(100, 0, 25, 100));
		AddObject(new ObjWall(100, 150, 25, 100));
		AddObject(new ObjWall(100, 275, 25, 25));
		AddObject(new ObjWall(125, 0, 25, 100));
		AddObject(new ObjWall(125, 275, 25, 25));
		AddObject(new ObjWall(150, 0, 25, 100));
		AddObject(new ObjWall(150, 275, 25, 25));
		AddObject(new ObjWall(175, 150, 25, 150));
		AddObject(new ObjWall(200, 150, 25, 150));
		AddObject(new ObjWall(225, 50, 25, 50));
		AddObject(new ObjWall(225, 275, 25, 25));
		AddObject(new ObjWall(250, 50, 25, 50));
		AddObject(new ObjWall(250, 275, 25, 25));
		AddObject(new ObjWall(275, 50, 25, 50));
		AddObject(new ObjWall(275, 150, 25, 100));
		AddObject(new ObjWall(275, 275, 25, 25));
		AddObject(new ObjWall(300, 50, 25, 50));
		AddObject(new ObjWall(300, 150, 25, 100));
		AddObject(new ObjWall(300, 275, 25, 25));
		AddObject(new ObjWall(325, 0, 25, 100));
		AddObject(new ObjWall(325, 150, 25, 100));
		AddObject(new ObjWall(325, 275, 25, 25));
		AddObject(new ObjWall(350, 0, 25, 100));
		AddObject(new ObjWall(350, 175, 25, 25));
		AddObject(new ObjWall(350, 275, 25, 25));
		AddObject(new ObjWall(375, 0, 25, 100));
		AddObject(new ObjWall(375, 175, 25, 25));
		AddObject(new ObjWall(375, 275, 25, 25));
		AddObject(new ObjWall(0, 150, 50, 25));
		AddObject(new ObjWall(350, 150, 50, 25));
		
		AddObject(new ObjClickBox(new ObjWall(100, 100, 25, 50, 0xFF9999), 180, 105, 40, 40, 10, 1000, 0xFF9999));

		auto c1 = new ObjClickBox(new ObjWall(125, 150, 50, 25, 0x9999FF), 5, 105, 40, 40, 10, 1000, 0x9999FF);
		AddObject(c1);

		auto c2 = new ObjClickBox(new ObjWall(275, 100, 25, 50, 0xFFFF99), 5, 205, 40, 40, 10, 1000, 0xFFFF99);
		AddObject(c2);

		auto c3 = new ObjClickBox(new ObjWall(225, 150, 50, 25, 0x99FFFF), 355, 105, 40, 40, 10, 1000, 0x99FFFF);
		AddObject(c3);

		auto c4 = new ObjClickBox(new ObjWall(175, 75, 50, 25, 0x2E62FF), 355, 205, 40, 40, 10, 1000, 0x2E62FF);
		AddObject(c4);

		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 275, 0, 50, 50));
	}
};

class Level0019 : public Level {
public:
	Level0019() : Level(350, 250){}

	void OnInit(){
		AddObject(new ObjWall(0, 0, 25, 300));
		AddObject(new ObjWall(25, 0, 25, 25));
		AddObject(new ObjWall(25, 275, 25, 25));
		AddObject(new ObjWall(50, 0, 25, 25));
		AddObject(new ObjWall(50, 275, 25, 25));
		AddObject(new ObjWall(75, 0, 25, 25));
		AddObject(new ObjWall(75, 75, 25, 225));
		AddObject(new ObjWall(100, 0, 25, 25));
		AddObject(new ObjWall(100, 75, 25, 225));
		AddObject(new ObjWall(125, 0, 25, 25));
		AddObject(new ObjWall(125, 75, 25, 75));
		AddObject(new ObjWall(125, 275, 25, 25));
		AddObject(new ObjWall(150, 0, 25, 25));
		AddObject(new ObjWall(150, 75, 25, 75));
		AddObject(new ObjWall(150, 275, 25, 25));
		AddObject(new ObjWall(175, 0, 25, 25));
		AddObject(new ObjWall(175, 275, 25, 25));
		AddObject(new ObjWall(200, 0, 25, 25));
		AddObject(new ObjWall(200, 275, 25, 25));
		AddObject(new ObjWall(225, 0, 25, 25));
		AddObject(new ObjWall(225, 75, 25, 75));
		AddObject(new ObjWall(225, 275, 25, 25));
		AddObject(new ObjWall(250, 0, 25, 25));
		AddObject(new ObjWall(250, 75, 25, 75));
		AddObject(new ObjWall(250, 275, 25, 25));
		AddObject(new ObjWall(275, 0, 25, 25));
		AddObject(new ObjWall(275, 75, 25, 225));
		AddObject(new ObjWall(300, 0, 25, 25));
		AddObject(new ObjWall(300, 75, 25, 225));
		AddObject(new ObjWall(325, 0, 25, 25));
		AddObject(new ObjWall(325, 275, 25, 25));
		AddObject(new ObjWall(350, 0, 25, 25));
		AddObject(new ObjWall(350, 275, 25, 25));
		AddObject(new ObjWall(375, 0, 25, 300));

		
		AddObject(new ObjAreaCounter(new ObjWall(175, 100, 50, 25, 0xFF9999), 130, 155, 40, 40, 1, 0xFF0000));

		AddObject(new ObjWall(175 + 12, 175 + 12, 75, 75, 0xFFFF00));
		AddObject(new ObjText("Gold", 225, 230, true, 30));

		AddObject(new ObjText("You can't always get what you want", 200, 55, true));

		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 25, 225, 50, 50));
	}
};

#endif