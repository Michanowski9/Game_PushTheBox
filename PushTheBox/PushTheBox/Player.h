#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Point.h"

#include "Constants.h"

#include "GraphicsEngine.h"
#include <memory>

class Player
{
public:
	Player();
	~Player() = default;

	void SetGraphicsEngine(GraphicsEnginePtr graphicsEnginePtr);

	void Draw() const;
	void SetPosition(int x, int y);

	void MoveUpIfPossible();
	void MoveDownIfPossible();
	void MoveLeftIfPossible();
	void MoveRightIfPossible();
private:
	Point position;
	GraphicsEnginePtr graphicsEnginePtr;
};

using PlayerPtr = std::shared_ptr<Player>;

#endif // !_PLAYER_H_