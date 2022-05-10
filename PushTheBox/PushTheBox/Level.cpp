#include "Level.h"

Level::~Level()
{
	FreeMemMap();
}

void Level::SetGraphicsEngine(GraphicsEnginePtr graphicsEnginePtr)
{
	this->graphicsEnginePtr = graphicsEnginePtr;
}

void Level::SetPlayer(PlayerPtr playerPtr)
{
	this->playerPtr = playerPtr;
}

const bool Level::IsEmptyCell(int x, int y) const
{
	if (map[x][y] == CELL::EMPTY) {
		return true;
	}
	return false;
}

const bool Level::IsBoxOnField(int x, int y) const
{
	if (map[x][y] == CELL::BOX) {
		return true;
	}
	return false;
}

void Level::MoveBoxUp(int boxX, int boxY)
{
}

void Level::MoveBoxDown(int boxX, int boxY)
{
}

void Level::MoveBoxLeft(int boxX, int boxY)
{
}

void Level::MoveBoxRight(int boxX, int boxY)
{
}

void Level::LoadDefaultMap()
{
	SetMapSize(20, 10);

	for (int x = 0; x < mapSize.x; x++)
	{
		for (int y = 0; y < mapSize.y; y++)
		{
			if (x == 0 || y == 0 || x == mapSize.x - 1 || y == mapSize.y - 1)
			{
				map[x][y] = CELL::WALL;
			}
			else
			{
				map[x][y] = CELL::EMPTY;
			}
		}
	}
	map[3][3] = CELL::BOX;
	playerPtr->SetPosition(5, 5);
}

void Level::DrawMap() const
{
	for (int y = 0; y < mapSize.y; y++)
	{
		for (int x = 0; x < mapSize.x; x++)
		{
			graphicsEnginePtr->DrawCell(x, y, map[x][y]);
		}
	}
}

void Level::SetMapSize(int x, int y)
{
	FreeMemMap();
	mapSize = Point(x, y);

	map = new int* [mapSize.x];
	for (int i = 0; i < mapSize.x; i++)
	{
		map[i] = new int[mapSize.y];
	}

}

void Level::FreeMemMap()
{
	if (map == nullptr) {
		return;
	}
	for (int i = 0; i < mapSize.x; i++)
	{
		delete map[i];
	}
	delete map;
}
