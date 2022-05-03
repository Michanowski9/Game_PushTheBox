#ifndef _GAME_H_
#define _GAME_H_

#include "GraphicsEngine.h"

class Game
{
public:
	Game() = default;
	Game(GraphicsEngine& graphicsEngine);
	~Game() = default;
	void MainLoop();

private:
	void HandleInput();
	void Update();
	void Render();

	GraphicsEngine& graphicsEngine;
};

#endif // !_GAME_H_