#ifndef _MAP_H_
#define _MAP_H_

#include <memory>

class Map {
public:
	virtual const bool IsEmptyCell(int x, int y) const = 0;
};

using MapPtr = std::shared_ptr<Map>;

#endif // !_MAP_H_