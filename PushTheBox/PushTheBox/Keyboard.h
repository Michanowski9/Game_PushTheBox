#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include "InputHandler.h"
#include "SystemKeyboard.h"

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
	SystemKeyboard& systemKeyboard;
	bool lastKeyState[0xFF] = {};
};

#endif // !_KEYBOARD_H_