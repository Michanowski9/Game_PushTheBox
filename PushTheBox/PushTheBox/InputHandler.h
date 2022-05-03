#ifndef _INPUT_HANDLER_H_
#define _INPUT_HANDLER_H_

class InputHandler {
public:
	virtual const bool GetKeyDown(int) const = 0;
	virtual const bool GetKeyUp(int) const = 0;
	virtual const bool GetKeyPressed(int) = 0;
	virtual const bool GetKeyReleased(int) = 0;
};

#endif // !_INPUT_HANDLER_H_
