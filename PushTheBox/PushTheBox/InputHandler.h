#ifndef _INPUT_HANDLER_H_
#define _INPUT_HANDLER_H_

class InputHandler {
public:
	virtual bool GetKeyDown(int) = 0;
	virtual bool GetKeyUp(int) = 0;
	virtual bool GetKeyPressed(int) = 0;
	virtual bool GetKeyReleased(int) = 0;
};

#endif // !_INPUT_HANDLER_H_
