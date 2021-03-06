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
	playerPtr->SetMap(levelPtr);
	levelPtr->LoadDefaultMap();
}

void Game::MainLoop()
{
	levelPtr->DrawMap();
	playerPtr->Draw();
	while (!IsWin() && !IsExit()) {
		HandleInput();
		Update();
		Render();
	}
}

void Game::HandleInput()
{
	if (inputHandlerPtr->GetKeyPressed(KEY::UP)) {
		playerPtr->MoveUpIfPossible();
	}
	if (inputHandlerPtr->GetKeyPressed(KEY::DOWN)) {
		playerPtr->MoveDownIfPossible();
	}
	if (inputHandlerPtr->GetKeyPressed(KEY::LEFT)) {
		playerPtr->MoveLeftIfPossible();
	}
	if (inputHandlerPtr->GetKeyPressed(KEY::RIGHT)) {
		playerPtr->MoveRightIfPossible();
	}
	if (inputHandlerPtr->GetKeyPressed(KEY::RESET)) {
		levelPtr->LoadDefaultMap();
		levelPtr->DrawMap();
		playerPtr->Draw();
	}
	if (inputHandlerPtr->GetKeyPressed(KEY::EXIT)) {
		isExit = true;
	}
}

void Game::Update()
{
	//no actions to do without player input
}

void Game::Render()
{
	levelPtr->RefreshPartOfMap();
	playerPtr->DrawIfMoved();
}

const bool Game::IsWin() const
{
	if (levelPtr->GetNumberOfTargets() > 0) {
		return false;
	}
	return true;
}

const bool Game::IsExit() const
{
	return isExit;
}
