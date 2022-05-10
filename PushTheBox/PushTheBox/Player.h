#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Point.h"

#include "Constants.h"

#include "GraphicsEngine.h"
#include "Map.h"
#include <memory>

class Player
{
public:
	Player();
	~Player() = default;

	void SetGraphicsEngine(GraphicsEnginePtr graphicsEnginePtr);
	void SetMap(MapPtr mapPtr);

	void Draw() const;
	void DrawIfMoved();
	void SetPosition(int x, int y);
	const Point GetPosition();

	void MoveUpIfPossible();
	void MoveDownIfPossible();
	void MoveLeftIfPossible();
	void MoveRightIfPossible();

private:
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	bool ifMoved = false;
	Point position;
	MapPtr mapPtr;
	GraphicsEnginePtr graphicsEnginePtr;
};

using PlayerPtr = std::shared_ptr<Player>;

#endif // !_PLAYER_H_