#include "Game.h"

Game::Game(GraphicsEngine& graphicsEngine, InputHandler& inputHandler)
	: graphicsEngine(graphicsEngine),
		inputHandler(inputHandler),
		player(Player(graphicsEngine)),
		level(Level(graphicsEngine, player))
{
	level.LoadDefaultMap();
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
	//TODO
}

void Game::Update()
{
	//TODO
}

void Game::Render()
{
	level.DrawMap();
	player.Draw();
}
