#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "Point.h"

#include "GraphicsEngine.h"

class Level
{
public:
	Level() = delete;
	Level(GraphicsEngine& graphicsEngine);
	~Level() = default;
	void LoadDefaultMap();
	void DrawMap();
private:
	void SetMapSize(int x, int y);

	Point mapSize;
	int** map; //TODO: memory dealocation
	GraphicsEngine& graphicsEngine;
};


#endif // !_LEVEL_H_