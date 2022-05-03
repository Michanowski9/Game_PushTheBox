#include "Level.h"

Level::Level(GraphicsEngine& graphicsEngine, Player& player)
	: graphicsEngine(graphicsEngine),
		player(player)
{
	map = nullptr;
}

Level::~Level()
{
	FreeMemMap();
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
	player.SetPosition(5, 5);
}

void Level::DrawMap() const
{
	for (int y = 0; y < mapSize.y; y++)
	{
		for (int x = 0; x < mapSize.x; x++)
		{
			graphicsEngine.DrawCell(x, y, map[x][y]);
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
