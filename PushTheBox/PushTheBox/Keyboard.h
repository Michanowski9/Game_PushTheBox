#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include "InputHandler.h"
#include "SystemKeyboard.h"

#define KEYBOARD_SIZE 0xFF

class Keyboard : public InputHandler
{
public:		
	Keyboard(SystemKeyboard& systemKeyboard);
	~Keyboard() = default;
	const bool GetKeyDown(int keyCode) const override;
	const bool GetKeyUp(int keyCode) const override;
	const bool GetKeyPressed(int keyCode) override;
	const bool GetKeyReleased(int keyCode) override;


private:
	int GetLastKeyStateSize();
	SystemKeyboard& systemKeyboard;
	bool lastKeyState[KEYBOARD_SIZE] = {};
};

#endif // !_KEYBOARD_H_