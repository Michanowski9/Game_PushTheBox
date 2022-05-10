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
	if (mapPtr->IsEmptyCell(position.x, position.y - 1)) {
		position.y--;
		return;
	}
	else if (mapPtr->IsBoxOnField(position.x, position.y - 1) 
			&& mapPtr->IsEmptyCell(position.x, position.y - 2)) {
		mapPtr->MoveBoxUp(position.x, position.y - 1);
		position.y--;
		return;
	}
}

void Player::MoveDownIfPossible()
{
	if (mapPtr->IsEmptyCell(position.x, position.y + 1)) {
		position.y++;
		return;
	}
	else if (mapPtr->IsBoxOnField(position.x, position.y + 1)
		&& mapPtr->IsEmptyCell(position.x, position.y + 2)) {
		mapPtr->MoveBoxDown(position.x, position.y + 1);
		position.y++;
		return;
	}
}

void Player::MoveLeftIfPossible()
{
	if (mapPtr->IsEmptyCell(position.x - 1, position.y)) {
		position.x--;
		return;
	}
	else if (mapPtr->IsBoxOnField(position.x - 1, position.y)
		&& mapPtr->IsEmptyCell(position.x - 2, position.y)) {
		mapPtr->MoveBoxLeft(position.x - 1, position.y);
		position.x--;
		return;
	}
}

void Player::MoveRightIfPossible()
{

	if (mapPtr->IsEmptyCell(position.x + 1, position.y)) {
		position.x++;
		return;
	}
	else if (mapPtr->IsBoxOnField(position.x + 1, position.y)
		&& mapPtr->IsEmptyCell(position.x + 2, position.y)) {
		mapPtr->MoveBoxRight(position.x + 1, position.y);
		position.x++;
		return;
	}
}
