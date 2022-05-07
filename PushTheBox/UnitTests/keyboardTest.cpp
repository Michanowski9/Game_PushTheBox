#include "pch.h"
#include "../PushTheBox/Keyboard.h"
#include "../PushTheBox/Keyboard.cpp"

using ::testing::Return;

class SystemKeyboardMock : public SystemKeyboard {
public:
	MOCK_METHOD(const bool, GetKeyState, (int), (override));
};

TEST(KeyboardTest, KeyIsDown_GetKeyDown_ReturnTrue) {
	//Given
	SystemKeyboardMock systemKeyboardMock;
	EXPECT_CALL(systemKeyboardMock, GetKeyState('A'))
		.WillOnce(Return(1));

	Keyboard keyboard = Keyboard(systemKeyboardMock);

	//When
	auto result = keyboard.GetKeyDown('A');

	//Then
	ASSERT_TRUE(result);
}

TEST(KeyboardTest, KeyIsUp_GetKeyDown_ReturnFalse) {
	//Given
	SystemKeyboardMock systemKeyboardMock;
	EXPECT_CALL(systemKeyboardMock, GetKeyState('A'))
		.WillOnce(Return(0));

	Keyboard keyboard = Keyboard(systemKeyboardMock);

	//When
	auto result = keyboard.GetKeyDown('A');

	//Then
	ASSERT_FALSE(result);
}

TEST(KeyboardTest, KeyIsDown_GetKeyUp_ReturnFalse) {
	//Given
	SystemKeyboardMock systemKeyboardMock;
	EXPECT_CALL(systemKeyboardMock, GetKeyState('A'))
		.WillOnce(Return(1));

	Keyboard keyboard = Keyboard(systemKeyboardMock);

	//When
	auto result = keyboard.GetKeyUp('A');

	//Then
	ASSERT_FALSE(result);
}

TEST(KeyboardTest, KeyIsUp_GetKeyUp_ReturnTrue) {
	//Given
	SystemKeyboardMock systemKeyboardMock;
	EXPECT_CALL(systemKeyboardMock, GetKeyState('A'))
		.WillOnce(Return(0));

	Keyboard keyboard = Keyboard(systemKeyboardMock);

	//When
	auto result = keyboard.GetKeyUp('A');

	//Then
	ASSERT_TRUE(result);
}

TEST()