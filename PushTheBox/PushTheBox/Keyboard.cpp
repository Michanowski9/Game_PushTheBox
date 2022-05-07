#include "Keyboard.h"

Keyboard::Keyboard(SystemKeyboard& systemKeyboard)
	: systemKeyboard(systemKeyboard)
{
	for (int i = 0; i < KEYBOARD_SIZE; i++)
	{
		lastKeyState[i] = false;
	}
}

const bool Keyboard::GetKeyDown(int keyCode) const
{
	if (isOutOfRange(keyCode)) {
		throw std::out_of_range("Out of range");
	}
	return systemKeyboard.GetKeyState(keyCode);
}

const bool Keyboard::GetKeyUp(int keyCode) const
{
	if (isOutOfRange(keyCode)) {
		throw std::out_of_range("Out of range");
	}
	return !systemKeyboard.GetKeyState(keyCode);
}

const bool Keyboard::GetKeyPressed(int keyCode)
{
	if (isOutOfRange(keyCode)) {
		throw std::out_of_range("Out of range");
	}
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
	if (isOutOfRange(keyCode)) {
		throw std::out_of_range("Out of range");
	}
	bool result = false;
	bool keyState = systemKeyboard.GetKeyState(keyCode);
	if (!keyState && lastKeyState[keyCode]) {
		result = true;
	}
	lastKeyState[keyCode] = keyState;
	return result;
}

const bool Keyboard::isOutOfRange(int keyCode) const
{
	return keyCode < 0 || keyCode >= KEYBOARD_SIZE;
}
