#include "ConsoleOutput.h"

ConsoleOutput::ConsoleOutput()
{
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	TurnOffCursor();
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

const byte ConsoleOutput::CellToColor(int cell) const
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

void ConsoleOutput::TurnOffCursor()
{
	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(handle, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(handle, &cursorInfo);
}
