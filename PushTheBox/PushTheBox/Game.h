#ifndef _GAME_H_
#define _GAME_H_

#include "GraphicsEngine.h"
#include "InputHandler.h"
#include "Level.h"
#include "Player.h"

class Game
{
public:
	Game() = default;
	Game(GraphicsEngine& graphicsEngine, InputHandler& inputHandler);
	~Game() = default;
	void MainLoop();

private:
	void HandleInput();
	void Update();
	void Render();

	Level level;
	Player player;

	InputHandler& inputHandler;
	GraphicsEngine& graphicsEngine;
};

#endif // !_GAME_H_