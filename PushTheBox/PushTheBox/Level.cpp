#include "Level.h"

Level::Level()
{
	fieldsToRefresh = std::queue<Point>();
}

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
	if (map[x][y] == CELL::EMPTY || map[x][y] == CELL::TARGET) {
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
	if (map[boxX][boxY - 1] != CELL::EMPTY) {
		return;
	}
	map[boxX][boxY] = CELL::EMPTY;
	fieldsToRefresh.push(Point(boxX, boxY));
	map[boxX][boxY - 1] = CELL::BOX;
	fieldsToRefresh.push(Point(boxX, boxY - 1));
}

void Level::MoveBoxDown(int boxX, int boxY)
{
	if (map[boxX][boxY + 1] != CELL::EMPTY) {
		return;
	}
	map[boxX][boxY] = CELL::EMPTY;
	fieldsToRefresh.push(Point(boxX, boxY));
	map[boxX][boxY + 1] = CELL::BOX;
	fieldsToRefresh.push(Point(boxX, boxY + 1));
}

void Level::MoveBoxLeft(int boxX, int boxY)
{
	if (map[boxX - 1][boxY] != CELL::EMPTY) {
		return;
	}
	map[boxX][boxY] = CELL::EMPTY;
	fieldsToRefresh.push(Point(boxX, boxY));
	map[boxX - 1][boxY] = CELL::BOX;
	fieldsToRefresh.push(Point(boxX - 1, boxY));
}

void Level::MoveBoxRight(int boxX, int boxY)
{
	if (map[boxX + 1][boxY] != CELL::EMPTY) {
		return;
	}
	map[boxX][boxY] = CELL::EMPTY;
	fieldsToRefresh.push(Point(boxX, boxY));
	map[boxX + 1][boxY] = CELL::BOX;
	fieldsToRefresh.push(Point(boxX + 1, boxY));
}

void Level::AddFieldToRefresh(int x, int y)
{
	fieldsToRefresh.push(Point(x, y));
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
	map[10][4] = CELL::TARGET;
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

void Level::RefreshPartOfMap()
{
	while (fieldsToRefresh.size() > 0)
	{
		auto field = fieldsToRefresh.front();
		fieldsToRefresh.pop();
		graphicsEnginePtr->DrawCell(field.x, field.y, map[field.x][field.y]);
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
