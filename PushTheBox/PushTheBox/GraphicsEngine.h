#ifndef _GRAPHICS_ENGINE_H_
#define _GRAPHICS_ENGINE_H_

class GraphicsEngine {
public:
	virtual void DrawCell(int x, int y, int fill) = 0;
};

#endif // !_GRAPHICS_ENGINE_H_