#include "Game.h"
#include "ConsoleOutput.h"
#include "WindowsKeyboard.h"
#include "Keyboard.h"

int main() {

	ConsoleOutput consoleOutput;

	WindowsKeyboard windowsKeyboard;
	Keyboard keyboard(windowsKeyboard);

	Game game(consoleOutput, keyboard);
	game.MainLoop();

	return 0;
}