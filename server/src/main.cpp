#include "stdafx.h"
#include "LevelManager.h"

int main(int argc, char *argv[]){
	
	LevelManager::Init();
	LevelManager::Run();
	LevelManager::Destroy();

	return 0;
}

