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

void Player::DrawIfMoved()
{
	if (ifMoved)
	{
		graphicsEnginePtr->DrawCell(position.x, position.y, CELL::PLAYER);
		ifMoved = false;
	}
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
	if (mapPtr->IsEmptyCell(position.x, position.y - 1)) 
	{
		MoveUp();
		return;
	}
	else if (mapPtr->IsBoxOnField(position.x, position.y - 1) 
			&& mapPtr->IsEmptyCell(position.x, position.y - 2)) 
	{
		mapPtr->MoveBoxUp(position.x, position.y - 1);
		MoveUp();
		return;
	}
}

void Player::MoveDownIfPossible()
{
	if (mapPtr->IsEmptyCell(position.x, position.y + 1)) 
	{
		MoveDown();
		return;
	}
	else if (mapPtr->IsBoxOnField(position.x, position.y + 1)
		&& mapPtr->IsEmptyCell(position.x, position.y + 2)) 
	{
		mapPtr->MoveBoxDown(position.x, position.y + 1);
		MoveDown();
		return;
	}
}

void Player::MoveLeftIfPossible()
{
	if (mapPtr->IsEmptyCell(position.x - 1, position.y)) 
	{
		MoveLeft();
		return;
	}
	else if (mapPtr->IsBoxOnField(position.x - 1, position.y)
		&& mapPtr->IsEmptyCell(position.x - 2, position.y)) 
	{
		mapPtr->MoveBoxLeft(position.x - 1, position.y);
		MoveLeft();
		return;
	}
}

void Player::MoveRightIfPossible()
{

	if (mapPtr->IsEmptyCell(position.x + 1, position.y)) 
	{
		MoveRight();
		return;
	}
	else if (mapPtr->IsBoxOnField(position.x + 1, position.y)
		&& mapPtr->IsEmptyCell(position.x + 2, position.y)) 
	{
		mapPtr->MoveBoxRight(position.x + 1, position.y);
		MoveRight();
		return;
	}
}

void Player::MoveUp()
{
	mapPtr->AddFieldToRefresh(position.x, position.y);
	position.y--;
	ifMoved = true;
}

void Player::MoveDown()
{
	mapPtr->AddFieldToRefresh(position.x, position.y);
	position.y++;
	ifMoved = true;
}

void Player::MoveLeft()
{
	mapPtr->AddFieldToRefresh(position.x, position.y);
	position.x--;
	ifMoved = true;
}

void Player::MoveRight()
{
	mapPtr->AddFieldToRefresh(position.x, position.y);
	position.x++;
	ifMoved = true;
}
