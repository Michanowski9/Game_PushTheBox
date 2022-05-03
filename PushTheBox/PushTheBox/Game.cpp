#include "Game.h"

Game::Game(GraphicsEngine& graphicsEngine) 
	: graphicsEngine(graphicsEngine), 
		level(Level(graphicsEngine)) 
{

};

void Game::MainLoop()
{
	//TODO: add loop
	//while (true) {
		HandleInput();
		Update();
		Render();
	//}
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
