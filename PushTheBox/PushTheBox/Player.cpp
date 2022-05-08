#include "Player.h"

Player::Player()
	: position(Point())
{

}

void Player::SetGraphicsEngine(GraphicsEnginePtr graphicsEnginePtr)
{
	this->graphicsEnginePtr = graphicsEnginePtr;
}

void Player::Draw() const
{
	graphicsEnginePtr->DrawCell(position.x, position.y, CELL::PLAYER);
}

void Player::SetPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}

void Player::MoveUpIfPossible()
{
	position.y--;
}

void Player::MoveDownIfPossible()
{
	position.y++;
}

void Player::MoveLeftIfPossible()
{
	position.x--;
}

void Player::MoveRightIfPossible()
{
	position.x++;
}
