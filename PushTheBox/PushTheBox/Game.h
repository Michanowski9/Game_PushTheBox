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
	~Game() = default;

	void SetGraphicsEngine(GraphicsEnginePtr graphicsEnginePtr);
	void SetInputHandler(InputHandlerPtr inputHandlerPtr);
	void SetLevel(LevelPtr levelPtr);
	void SetPlayer(PlayerPtr playerPtr);

	void SetLevel();
	void SetPlayer();

	void MainLoop();

private:
	void HandleInput();
	void Update();
	void Render();
	const bool IsWin() const;

	LevelPtr levelPtr;
	PlayerPtr playerPtr;

	InputHandlerPtr inputHandlerPtr;
	GraphicsEnginePtr graphicsEnginePtr;
};

using GamePtr = std::shared_ptr<Game>;

#endif // !_GAME_H_