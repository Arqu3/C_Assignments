#include <string>
#include "VGCVirtualGameConsole.h"
#include "Game.h"

using namespace std;

int VGCMain(const VGCStringVector &arguments){

	//Create and start game
	Game game;
	game.start();

	return 0;
}