#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "Point.h"

#include "Constants.h"

#include "GraphicsEngine.h"
#include "Player.h"

#include <memory>

class Level
{
public:
	Level() = default;
	~Level();

	void SetGraphicsEngine(GraphicsEnginePtr graphicsEnginePtr);
	void SetPlayer(PlayerPtr playerPtr);

	void LoadDefaultMap();
	void DrawMap() const;
private:
	void SetMapSize(int x, int y);
	void FreeMemMap();

	Point mapSize;
	int** map = nullptr;
	GraphicsEnginePtr graphicsEnginePtr;
	PlayerPtr playerPtr;
};

using LevelPtr = std::shared_ptr<Level>;

#endif // !_LEVEL_H_