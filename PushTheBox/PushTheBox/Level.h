#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "Point.h"

#include "Constants.h"

#include "GraphicsEngine.h"
#include "Player.h"

#include <memory>
#include "Map.h"
#include <queue>

class Level : public Map
{
public:
	Level();
	~Level();

	void SetGraphicsEngine(GraphicsEnginePtr graphicsEnginePtr);
	void SetPlayer(PlayerPtr playerPtr);

	const bool IsEmptyCell(int x, int y) const override;
	const bool IsBoxOnField(int x, int y) const override;

	void MoveBoxUp(int boxX, int boxY) override;
	void MoveBoxDown(int boxX, int boxY) override;
	void MoveBoxLeft(int boxX, int boxY) override;
	void MoveBoxRight(int boxX, int boxY) override;

	void AddFieldToRefresh(int x, int y) override;

	void LoadDefaultMap();
	void DrawMap() const;
	void RefreshPartOfMap();
private:
	void SetField(int x, int y, int field);
	void SetMapSize(int x, int y);
	void FreeMemMap();

	std::queue<Point> fieldsToRefresh;

	Point mapSize;
	int** map = nullptr;
	GraphicsEnginePtr graphicsEnginePtr;
	PlayerPtr playerPtr;
};

using LevelPtr = std::shared_ptr<Level>;

#endif // !_LEVEL_H_