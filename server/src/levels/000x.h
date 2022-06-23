#ifndef CURSORS_LEVEL000X_H
#define CURSORS_LEVEL000X_H

#include "LevelObjects.h"


class EmptyLevel : public Level {
public:
	EmptyLevel() : Level(LEVEL_WIDTH / 2, LEVEL_HEIGHT / 2){}
};

class LastLevel : public Level {
public:
	LastLevel() : Level(LEVEL_WIDTH / 2, LEVEL_HEIGHT / 2){}

	void OnInit(){
		AddObject(new ObjText("The End", 200, 140, true, 68));
		AddObject(new ObjText("That's it. We plan to add more levels frequently, so come back soon!", 200, 165, true));
		AddObject(new ObjText("Or you can stay here and enjoy the company of other winners...", 200, 178, true, 15));
		AddObject(new ObjText("You can also continue going, repeating the same levels, but now with less players", 200, 191, true, 15));
		AddObject(new ObjWall(360, 270, 40, 10, 0x000000));
		AddObject(new ObjWall(360, 280, 10, 10, 0x000000));
		AddObject(new ObjWall(380, 290, 10, 10, 0x000000));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 390, 290, 10, 10));
	}
};

class Level0001 : public Level {
public:
	Level0001() : Level(LEVEL_WIDTH / 2, LEVEL_HEIGHT / 2){}

	void OnInit(){
		SetSoloLevel(true);
		AddObject(new ObjText("Welcome", 200, 50, true, 68));
		AddObject(new ObjText("You participate in this experiment with your mouse cursor", 200, 75, true));
		AddObject(new ObjText("Move to the next level by putting your mouse on the green area", 200, 92, true));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 300, 175, 50, 50));
	}
};

class Level0002 : public Level {
public:
	Level0002() : Level(250, 150){}

	void OnInit(){
		AddObject(new ObjText("Sometimes you might need to", 300, 75, true));
		AddObject(new ObjText("think about the needs of others", 300, 85, true));
		
		AddObject(new ObjWall(190, 0, 20, 100));
		AddObject(new ObjWall(190, 200, 20, 100));
		AddObject(new ObjAreaCounter(new ObjWall(190, 100, 20, 100, 0xFF9999), 325, 125, 50, 50, 2, 0xFF0000));
		
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 25, 125, 50, 50));
	}
};

class Level0003 : public Level {
public:
	Level0003() : Level(25, 25){}

	void OnInit(){

		AddObject(new ObjWall(0, 50, 350, 25));
		AddObject(new ObjWall(50, 125, 350, 25));
		AddObject(new ObjWall(0, 200, 350, 25));

		AddObject(new ObjAreaCounter(new ObjWall(350, 50, 50, 25, 0xFF9999), 175, 0, 50, 50, 1, 0xFF0000));
		AddObject(new ObjAreaCounter(new ObjWall(0, 125, 50, 25, 0x9999FF), 175, 75, 50, 50, 1, 0x0000FF));
		AddObject(new ObjAreaCounter(new ObjWall(350, 200, 50, 25, 0xFFFF99), 175, 150, 50, 50, 1, 0xFFFF00));
		
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 0, 225, 75, 75));
	}
};


class Level0004 : public Level {
public:
	Level0004() : Level(200, 25){}
	void OnInit(){
		AddObject(new ObjWall(150, 0, 25, 75));
		AddObject(new ObjWall(50, 50, 100, 25));
		
		AddObject(new ObjWall(225, 0, 25, 75));
		AddObject(new ObjWall(250, 50, 100, 25));

		AddObject(new ObjWall(50, 175, 125, 125));
		AddObject(new ObjWall(225, 175, 125, 125));

		AddObject(new ObjAreaCounter(new ObjWall(175, 175, 50, 25, 0xFF9999), 100, 0, 50, 50, 1, 0xFF0000));
		AddObject(new ObjAreaCounter(new ObjWall(175, 175, 50, 25, 0xFF9999), 250, 0, 50, 50, 1, 0xFF0000));

		AddObject(new ObjAreaCounter(new ObjWall(175, 200, 50, 25, 0x9999FF), 0, 250, 50, 50, 1, 0x0000FF));
		AddObject(new ObjAreaCounter(new ObjWall(175, 200, 50, 25, 0x9999FF), 350, 250, 50, 50, 1, 0x0000FF));

		auto centerCounter = new ObjAreaCounter(nullptr, 175, 100, 50, 50, 1, 0xFFFF00);
		centerCounter->AddLinkedObject(new ObjWall(0, 50, 50, 25, 0xFFFF99));
		centerCounter->AddLinkedObject(new ObjWall(350, 50, 50, 25, 0xFFFF99));
		centerCounter->AddLinkedObject(new ObjWall(0, 175, 50, 25, 0xFFFF99));
		centerCounter->AddLinkedObject(new ObjWall(350, 175, 50, 25, 0xFFFF99));

		AddObject(centerCounter);


		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 175, 250, 50, 50));
	}
};

class Level0005 : public Level {
public:
	Level0005() : Level(25, 150){}

	void OnInit(){
		AddObject(new ObjWall(0, 50, 350, 75));
		AddObject(new ObjWall(0, 175, 350, 75));

		AddObject(new ObjAreaCounter(new ObjWall(325, 125, 25, 50, 0xFFFF99), 275 + 13, 125, 50, 50, 1, 0xFFFF00));

		AddObject(new ObjAreaCounter(new ObjWall(75, 0, 25, 50, 0xFF9999), 125, 250, 50, 50, 2, 0xFF0000));
		AddObject(new ObjAreaCounter(new ObjWall(75, 250, 25, 50, 0x9999FF), 125, 0, 50, 50, 2, 0x0000FF));

		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 0, 0, 50, 50));
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 0, 250, 50, 50));
	}
};

class Level0006 : public Level {
public:
	Level0006() : Level(12, 190){}

	void OnInit(){
		const int width = 20;
		const int height = 15;
		static uint8_t grid[height][width] = {
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
			{0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
			{0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0},
			{0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
			{0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
			{1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0},
			{0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0},
			{1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
			{0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0},
			{1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0},
			{0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0},
			{0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0},
			{0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
			{0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0}
		};
		
		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 0, 140, 20, 20));
		AddObject(new ObjAreaCounter(new ObjWall(20, 120, 20, 20, 0xFF9999), 60, 120, 20, 20, 1, 0xFF0000));

		for(int y = 0; y < height; ++y){
			for(int x = 0; x < width; ++x){

				int xStart = x;
				while(x < width && grid[y][x]) ++x;
				int xEnd = x;
				if(xStart == xEnd) continue;

				int objWidth = (xEnd - xStart) * (LEVEL_WIDTH / width);
				assert(xStart * (LEVEL_WIDTH / width) + objWidth <= LEVEL_WIDTH);
				AddObject(new ObjWall(xStart * (LEVEL_WIDTH / width), y * (LEVEL_HEIGHT / height), objWidth, (LEVEL_HEIGHT / height)));
			}
		}
	}
};

class Level0007 : public Level {
public:
	Level0007() : Level(130, 150){}
	void OnInit(){
		AddObject(new ObjText("Wrong choice and you go back to the maze", 35, 153, false, 20));
		AddObject(new ObjWall(0, 0, 250, 125));
		AddObject(new ObjWall(0, 175, 250, 125));
		AddObject(new ObjWall(0, 125, 25, 50));
		AddObject(new ObjWall(300, 0, 100, 125));
		AddObject(new ObjWall(300, 175, 100, 125));
		AddObject(new ObjWall(250, 0, 50, 75));
		AddObject(new ObjWall(250, 225, 50, 75));
		AddObject(new ObjWall(350, 125, 50, 50));

		
		std::vector<ObjTeleport*> teleports;
		teleports.push_back(new ObjTeleport(LevelManager::GetPreviousLevel(this), 250, 75, 50, 50));
		teleports.push_back(new ObjTeleport(LevelManager::GetPreviousLevel(this), 300, 125, 50, 50));
		teleports.push_back(new ObjTeleport(LevelManager::GetPreviousLevel(this), 250, 175, 50, 50));
		
		teleports[rand() % teleports.size()]->SetNextLevel(LevelManager::GetNextLevel(this));

		for(auto t : teleports){
			AddObject(t);
		}
	}
};

class Level0008 : public Level {
public:
	Level0008() : Level(50, 275){}

	void OnInit(){
		AddObject(new ObjText("One of these is not like the others", 200, 153, true, 20));

		AddObject(new ObjWall(0, 0, 25, 300));
		AddObject(new ObjWall(375, 0, 25, 300));

		AddObject(new ObjWall(25, 0, 75, 125));
		
		AddObject(new ObjWall(125, 0, 25, 75));
		AddObject(new ObjWall(175, 0, 25, 75));
		AddObject(new ObjWall(225, 0, 25, 75));
		AddObject(new ObjWall(275, 0, 25, 75));
		AddObject(new ObjWall(325, 0, 25, 75));

		AddObject(new ObjWall(100, 100, 250, 25));
		AddObject(new ObjWall(100, 175, 250, 25));

		AddObject(new ObjWall( 75, 175, 25, 125));
		AddObject(new ObjWall(125, 225, 25, 75));
		AddObject(new ObjWall(175, 225, 25, 75));
		AddObject(new ObjWall(225, 225, 25, 75));
		AddObject(new ObjWall(275, 225, 25, 75));
		AddObject(new ObjWall(325, 225, 25, 75));

		std::vector<ObjTeleport*> teleports;
		
		teleports.push_back(new ObjTeleport(this, 250, 275, 25, 25));
		teleports.push_back(new ObjTeleport(this, 100, 0, 25, 25));
		teleports.push_back(new ObjTeleport(this, 150, 0, 25, 25));
		teleports.push_back(new ObjTeleport(this, 200, 0, 25, 25));
		teleports.push_back(new ObjTeleport(this, 250, 0, 25, 25));
		teleports.push_back(new ObjTeleport(this, 300, 0, 25, 25));
		teleports.push_back(new ObjTeleport(this, 350, 0, 25, 25));
		teleports.push_back(new ObjTeleport(this, 100, 275, 25, 25));
		teleports.push_back(new ObjTeleport(this, 150, 275, 25, 25));
		teleports.push_back(new ObjTeleport(this, 200, 275, 25, 25));
		teleports.push_back(new ObjTeleport(this, 300, 275, 25, 25));
		teleports.push_back(new ObjTeleport(this, 350, 275, 25, 25));

		teleports[rand() % teleports.size()]->SetNextLevel(LevelManager::GetNextLevel(this));

		for(auto t : teleports) AddObject(t);
	}
};

class Level0009 : public Level {
public:
	Level0009() : Level(25, 275){}

	void OnInit(){
		AddObject(new ObjWall(25, 225, 50, 25));
		AddObject(new ObjWall(50, 250, 25, 50));
		AddObject(new ObjTeleport(this, 25, 25, 50, 200, true));
		AddObject(new ObjTeleport(this, 95, 0, 63, 275, true));

		AddObject(new ObjTeleport(this, 75, 25, 5, 275, true));

		
		AddObject(new ObjTeleport(this, 167, 25, 68, 275, true));
		AddObject(new ObjTeleport(this, 240, 0, 60, 275, true));
		
		AddObject(new ObjWall(300, 0, 25, 275));

		AddObject(new ObjTeleport(LevelManager::GetNextLevel(this), 325, 0, 75, 75));
		
		AddObject(new ObjTeleport(this, 325, 75, 25, 200, true));
		AddObject(new ObjTeleport(this, 375, 75, 25, 200, true));
	}
};

#endif