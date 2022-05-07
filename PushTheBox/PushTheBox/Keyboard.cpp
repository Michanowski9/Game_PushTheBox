#include "Keyboard.h"

Keyboard::Keyboard(SystemKeyboard& systemKeyboard)
	: systemKeyboard(systemKeyboard)
{
	for (int i = 0; i < this->GetLastKeyStateSize(); i++)
	{
		lastKeyState[i] = false;
	}
}

const bool Keyboard::GetKeyDown(int keyCode) const
{
	return systemKeyboard.GetKeyState(keyCode);
}

const bool Keyboard::GetKeyUp(int keyCode) const
{
	return !systemKeyboard.GetKeyState(keyCode);
}

const bool Keyboard::GetKeyPressed(int keyCode)
{
	bool result = false;
	bool keyState = systemKeyboard.GetKeyState(keyCode);
	if (keyState && !lastKeyState[keyCode]) {
		result = true;
	}
	lastKeyState[keyCode] = keyState;
	return result;
}

const bool Keyboard::GetKeyReleased(int keyCode)
{
	bool result = false;
	bool keyState = systemKeyboard.GetKeyState(keyCode);
	if (!keyState && lastKeyState[keyCode]) {
		result = true;
	}
	lastKeyState[keyCode] = keyState;
	return result;
}

int Keyboard::GetLastKeyStateSize()
{
	return sizeof(lastKeyState) / sizeof(bool);
}
