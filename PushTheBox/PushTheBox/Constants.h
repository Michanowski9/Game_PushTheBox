#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

namespace CELL {
	const int EMPTY = 0;
	const int WALL = 1;
	const int PLAYER = 2;
	const int BOX = 3;
	const int TARGET = 4;
}

namespace KEY {
	const int UP = 0x26;
	const int DOWN = 0x28;
	const int LEFT = 0x25;
	const int RIGHT = 0x27;
	const int RESET = 'R';
	const int EXIT = 'Q';
}

#endif // !_CONSTANTS_H_