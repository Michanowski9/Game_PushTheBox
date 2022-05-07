#ifndef _MAP_H_
#define _MAP_H_

#include "Point.h"
#include <memory>

class Map {
public:
	virtual const bool IsEmpty(Point p) const = 0;
};

using MapPtr = std::shared_ptr<Map>;

#endif // !_MAP_H_
