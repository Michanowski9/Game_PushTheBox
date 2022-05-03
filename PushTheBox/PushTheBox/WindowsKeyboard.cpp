#include "WindowsKeyboard.h"

bool WindowsKeyboard::GetKeyState(int key)
{
    return GetAsyncKeyState(key);
}
