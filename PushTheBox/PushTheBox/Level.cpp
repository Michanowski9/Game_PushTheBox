#include "Level.h"

Level::Level(GraphicsEngine& graphicsEngine, Player& player)
	: graphicsEngine(graphicsEngine),
		player(player)
{
	map = nullptr;
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
				map[x][y] = 1;
			}
			else
			{
				map[x][y] = 0;
			}
		}
	}
	player.SetPosition(5, 5);
}

void Level::DrawMap()
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
	mapSize = Point(x, y);

	map = new int* [mapSize.x];
	for (int i = 0; i < mapSize.x; i++)
	{
		map[i] = new int[mapSize.y];
	}

}
