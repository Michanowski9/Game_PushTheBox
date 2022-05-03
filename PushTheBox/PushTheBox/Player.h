#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Point.h"
#include "GraphicsEngine.h"

class Player
{
public:
	Player(GraphicsEngine& graphicsEngine);
	~Player() = default;
	void Draw();
	void SetPosition(int x, int y);
private:
	Point position;
	GraphicsEngine& graphicsEngine;
};

#endif // !_PLAYER_H_