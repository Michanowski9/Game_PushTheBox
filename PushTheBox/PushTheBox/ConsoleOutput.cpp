#include "ConsoleOutput.h"

ConsoleOutput::ConsoleOutput()
{
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
}

void ConsoleOutput::DrawCell(int x, int y, int cell)
{
	byte color = CellToColor(cell);
	this->SetColor(color);

	std::string fill = "  ";
	SetCursorPosition(x * fill.length(), y);
	printf(fill.c_str());

	this->SetColor(COLORS::BLACK);
}

void ConsoleOutput::SetCursorPosition(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(handle, pos);
}

void ConsoleOutput::SetColor(byte color)
{
	SetConsoleTextAttribute(handle, color);
}

byte ConsoleOutput::CellToColor(int cell)
{
	switch (cell) {
	case CELL::EMPTY:
		return COLORS::BLACK;
	case CELL::WALL:
		return COLORS::WHITE;
	case CELL::PLAYER:
		return COLORS::RED;
	case CELL::BOX:
		return COLORS::GREEN;
	default:
		return COLORS::BLACK;
	}
}
