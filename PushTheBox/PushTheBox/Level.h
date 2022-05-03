#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "Point.h"

#include "Constants.h"

#include "GraphicsEngine.h"
#include "Player.h"

class Level
{
public:
	Level() = delete;
	Level(GraphicsEngine& graphicsEngine, Player& player);

	~Level();
	void LoadDefaultMap();
	void DrawMap() const;
private:
	void SetMapSize(int x, int y);
	void FreeMemMap();

	Point mapSize;
	int** map;
	GraphicsEngine& graphicsEngine;
	Player& player;
};

#endif // !_LEVEL_H_