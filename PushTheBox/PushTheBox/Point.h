#ifndef _POINT_H_
#define _POINT_H_

struct Point
{
	Point();
	Point(int x, int y);
	~Point() = default;

	int x;
	int y;
};

#endif // !_POINT_H_