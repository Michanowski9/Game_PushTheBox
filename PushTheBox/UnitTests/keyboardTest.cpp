#include "pch.h"
#include "../PushTheBox/Keyboard.h"
#include "../PushTheBox/Keyboard.cpp"

using ::testing::Return;

class SystemKeyboardMock : public SystemKeyboard {
public:
	MOCK_METHOD(const bool, GetKeyState, (int), (override));
};

TEST(KeyboardTest, GetKeyDown_KeyIsDown_ReturnTrue) {
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
TEST(KeyboardTest, GetKeyDown_KeyIsUp_ReturnFalse) {
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
TEST(KeyboardTest, GetKeyUp_KeyIsDown_ReturnFalse) {
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
TEST(KeyboardTest, GetKeyUp_KeyIsUp_ReturnTrue) {
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
TEST(KeyboardTest, GetKeyPressed_KeyIsUpThanDown_ReturnTrue) {
	//Given
	SystemKeyboardMock systemKeyboardMock;
	EXPECT_CALL(systemKeyboardMock, GetKeyState('A'))
		.WillOnce(Return(0))
		.WillRepeatedly(Return(1));

	Keyboard keyboard = Keyboard(systemKeyboardMock);

	//When
	auto result1 = keyboard.GetKeyPressed('A');
	auto result2 = keyboard.GetKeyPressed('A');
	auto result3 = keyboard.GetKeyPressed('A');

	//Then
	EXPECT_FALSE(result1);
	EXPECT_TRUE(result2);
	EXPECT_FALSE(result3);
}
TEST(KeyboardTest, GetKeyPressed_KeyIsDownThanUp_ReturnFalse) {
	//Given
	SystemKeyboardMock systemKeyboardMock;
	EXPECT_CALL(systemKeyboardMock, GetKeyState('A'))
		.WillOnce(Return(1))
		.WillRepeatedly(Return(0));

	Keyboard keyboard = Keyboard(systemKeyboardMock);

	//When

	//this is to skip not pressed state when constructing object 
	//(by default is setting to 0 in array)
	keyboard.GetKeyPressed('A');

	auto result1 = keyboard.GetKeyPressed('A');
	auto result2 = keyboard.GetKeyPressed('A');

	//Then
	EXPECT_FALSE(result1);
	EXPECT_FALSE(result2);
}
TEST(KeyboardTest, GetKeyReleased_KeyIsDownThanUp_ReturnTrue) {
	//Given
	SystemKeyboardMock systemKeyboardMock;
	EXPECT_CALL(systemKeyboardMock, GetKeyState('A'))
		.WillOnce(Return(1))
		.WillOnce(Return(0));

	Keyboard keyboard = Keyboard(systemKeyboardMock);

	//When
	auto result1 = keyboard.GetKeyReleased('A');
	auto result2 = keyboard.GetKeyReleased('A');

	//Then
	EXPECT_FALSE(result1);
	EXPECT_TRUE(result2);
}
TEST(KeyboardTest, GetKeyReleased_KeyIsUpThanDown_ReturnFalse) {
	//Given
	SystemKeyboardMock systemKeyboardMock;
	EXPECT_CALL(systemKeyboardMock, GetKeyState('A'))
		.WillOnce(Return(0))
		.WillOnce(Return(1));

	Keyboard keyboard = Keyboard(systemKeyboardMock);

	//When
	auto result1 = keyboard.GetKeyReleased('A');
	auto result2 = keyboard.GetKeyReleased('A');

	//Then
	EXPECT_FALSE(result1);
	EXPECT_FALSE(result2);
}
