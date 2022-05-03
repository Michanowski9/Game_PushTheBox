#include "Game.h"

Game::Game(GraphicsEngine& graphicsEngine, InputHandler& inputHandler) 
	: graphicsEngine(graphicsEngine), 
		inputHandler(inputHandler),
		level(Level(graphicsEngine)) 
{

};

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

}

void Game::Update()
{

}

void Game::Render()
{
	level.DrawMap();
}
