#include "Game.h"

Game::Game(GraphicsEngine& graphicsEngine) : graphicsEngine(graphicsEngine) {

};

void Game::MainLoop()
{
	//TODO: add loop
	HandleInput();
	Update();
	Render();
}

void Game::HandleInput()
{
}

void Game::Update()
{
}

void Game::Render()
{
	graphicsEngine.DrawMap();
}
