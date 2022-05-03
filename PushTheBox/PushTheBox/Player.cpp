#include "Player.h"

Player::Player(GraphicsEngine& graphicsEngine)
	: graphicsEngine(graphicsEngine),
		position(Point())
{

}

void Player::Draw()
{
	graphicsEngine.DrawCell(position.x, position.y, 2);
}

void Player::SetPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}
