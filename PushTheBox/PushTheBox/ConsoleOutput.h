#ifndef _CONSOLE_OUTPUT_H_
#define _CONSOLE_OUTPUT_H_

#include "GraphicsEngine.h"

#include <iostream>

class ConsoleOutput : public GraphicsEngine
{
public:
	ConsoleOutput() = default;
	~ConsoleOutput() = default;

	void DrawMap() override;
};

#endif // !_CONSOLE_OUTPUT_H_