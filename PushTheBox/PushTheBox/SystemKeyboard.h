#ifndef _SYSTEM_KEYBOARD_H_
#define _SYSTEM_KEYBOARD_H_

class SystemKeyboard {
public:
	virtual bool GetKeyState(int key) = 0;
};

#endif // !_SYSTEM_KEYBOARD_H_