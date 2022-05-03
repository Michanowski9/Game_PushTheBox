#include "Game.h"
#include "ConsoleOutput.h"


int main() {

	ConsoleOutput consoleOutput;

	Game game(consoleOutput);
	game.MainLoop();

	return 0;
}