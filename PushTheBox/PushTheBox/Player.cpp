#include "Player.h"

Player::Player(GraphicsEngine& graphicsEngine)
	: graphicsEngine(graphicsEngine),
		position(Point())
{

}

void Player::Draw() const
{
	graphicsEngine.DrawCell(position.x, position.y, CELL::PLAYER);
}

void Player::SetPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}