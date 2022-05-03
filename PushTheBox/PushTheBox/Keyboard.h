#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include "InputHandler.h"
#include "SystemKeyboard.h"

class Keyboard : public InputHandler
{
public:		
	Keyboard(SystemKeyboard& systemKeyboard);
	~Keyboard() = default;
	bool GetKeyDown(int keyCode) override;
	bool GetKeyUp(int keyCode) override;
	bool GetKeyPressed(int keyCode) override;
	bool GetKeyReleased(int keyCode) override;


private:
	SystemKeyboard& systemKeyboard;
	bool lastKeyState[0xFF] = {};
};

#endif // !_KEYBOARD_H_