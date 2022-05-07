#include "Game.h"
#include "ConsoleOutput.h"
#include "WindowsKeyboard.h"
#include "Keyboard.h"

int main() {

	auto consoleOutputPtr = std::make_shared<ConsoleOutput>();

	auto keyboardPtr = std::make_shared<Keyboard>();
	auto windowsKeyboardPtr = std::make_shared<WindowsKeyboard>();
	keyboardPtr->SetSystemKeyboard(windowsKeyboardPtr);

	Game game;
	game.SetGraphicsEngine(consoleOutputPtr);
	game.SetInputHandler(keyboardPtr);
	game.SetLevel();
	game.SetPlayer();

	game.MainLoop();

	return 0;
}