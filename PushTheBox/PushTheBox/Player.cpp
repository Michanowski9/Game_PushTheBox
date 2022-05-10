#include "Player.h"

Player::Player()
	: position(Point())
{

}

void Player::SetGraphicsEngine(GraphicsEnginePtr graphicsEnginePtr)
{
	this->graphicsEnginePtr = graphicsEnginePtr;
}

void Player::SetMap(MapPtr mapPtr)
{
	this->mapPtr = mapPtr;
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

const Point Player::GetPosition()
{
	return position;
}

void Player::MoveUpIfPossible()
{
	if (!mapPtr->IsEmptyCell(position.x, position.y - 1)) {
		return;
	}
	position.y--;
}

void Player::MoveDownIfPossible()
{
	if (!mapPtr->IsEmptyCell(position.x, position.y + 1)) {
		return;
	}
	position.y++;
}

void Player::MoveLeftIfPossible()
{
	if (!mapPtr->IsEmptyCell(position.x - 1, position.y)) {
		return;
	}
	position.x--;
}

void Player::MoveRightIfPossible()
{
	if (!mapPtr->IsEmptyCell(position.x + 1, position.y)) {
		return;
	}
	position.x++;
}
