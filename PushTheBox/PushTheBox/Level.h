#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "Point.h"

#include "GraphicsEngine.h"
#include "Player.h"

class Level
{
public:
	Level() = delete;
	Level(GraphicsEngine& graphicsEngine, Player& player);

	~Level() = default;
	void LoadDefaultMap();
	void DrawMap();
private:
	void SetMapSize(int x, int y);

	Point mapSize;
	int** map; //TODO: memory dealocation
	GraphicsEngine& graphicsEngine;
	Player& player;
};

#endif // !_LEVEL_H_