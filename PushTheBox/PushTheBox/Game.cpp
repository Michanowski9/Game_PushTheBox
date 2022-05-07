#include "Game.h"

void Game::SetGraphicsEngine(GraphicsEnginePtr graphicsEnginePtr)
{
	this->graphicsEnginePtr = graphicsEnginePtr;
}

void Game::SetInputHandler(InputHandlerPtr inputHandlerPtr)
{
	this->inputHandlerPtr = inputHandlerPtr;
}

void Game::SetLevel(LevelPtr levelPtr)
{
	this->levelPtr = levelPtr;
}

void Game::SetPlayer(PlayerPtr playerPtr)
{
	this->playerPtr = playerPtr;
}

void Game::SetLevel()
{
	levelPtr = std::make_shared<Level>();
	levelPtr->SetGraphicsEngine(graphicsEnginePtr);
}

void Game::SetPlayer()
{
	playerPtr = std::make_shared<Player>();
	playerPtr->SetGraphicsEngine(graphicsEnginePtr);
	levelPtr->SetPlayer(playerPtr);
	levelPtr->LoadDefaultMap();
}

void Game::MainLoop()
{
	while (true) {
		HandleInput();
		Update();
		Render();
	}
}

void Game::HandleInput()
{
	//TODO
}

void Game::Update()
{
	//TODO
}

void Game::Render()
{
	levelPtr->DrawMap();
	playerPtr->Draw();
}
