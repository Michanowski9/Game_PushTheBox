#ifndef _WINDOWS_KEYBOARD_H_
#define _WINDOWS_KEYBOARD_H_

#include "SystemKeyboard.h"
#include <Windows.h>

class WindowsKeyboard : public SystemKeyboard
{
	bool GetKeyState(int key) override;
};

#endif // !_WINDOWS_KEYBOARD_H_