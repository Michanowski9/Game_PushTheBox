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

	//this is to skip not pressed state when constructing object 
	//(by default is setting to false in array)
	keyboard.GetKeyPressed('A');

	//When
	auto result1 = keyboard.GetKeyPressed('A');
	auto result2 = keyboard.GetKeyPressed('A');

	//Then
	EXPECT_FALSE(result1);
	EXPECT_FALSE(result2);
}
TEST(KeyboardTest, GetKeyPressed_TwoKeysIsUpThanDownInTheSameTime_ReturnTrueForBoth) {
	//Given
	SystemKeyboardMock systemKeyboardMock;
	EXPECT_CALL(systemKeyboardMock, GetKeyState('A'))
		.WillOnce(Return(0))
		.WillRepeatedly(Return(1));
	EXPECT_CALL(systemKeyboardMock, GetKeyState('B'))
		.WillOnce(Return(0))
		.WillRepeatedly(Return(1));

	Keyboard keyboard = Keyboard(systemKeyboardMock);

	//When
	auto result1a = keyboard.GetKeyPressed('A');
	auto result1b = keyboard.GetKeyPressed('B');

	auto result2a = keyboard.GetKeyPressed('A');
	auto result2b = keyboard.GetKeyPressed('B');

	//Then
	EXPECT_FALSE(result1a);
	EXPECT_FALSE(result1b);

	EXPECT_TRUE(result2a);
	EXPECT_TRUE(result2b);
}
TEST(KeyboardTest, GetKeyPressed_TwoKeysIsDownThanUpInTheSameTime_ReturnFalseForBoth) {
	//Given
	SystemKeyboardMock systemKeyboardMock;
	EXPECT_CALL(systemKeyboardMock, GetKeyState('A'))
		.WillOnce(Return(1))
		.WillRepeatedly(Return(0));
	EXPECT_CALL(systemKeyboardMock, GetKeyState('B'))
		.WillOnce(Return(1))
		.WillRepeatedly(Return(0));

	Keyboard keyboard = Keyboard(systemKeyboardMock);

	//this is to skip not pressed state when constructing object 
	//(by default is setting to false in array)
	keyboard.GetKeyPressed('A');
	keyboard.GetKeyPressed('B');

	//When
	auto result1a = keyboard.GetKeyPressed('A');
	auto result1b = keyboard.GetKeyPressed('B');

	auto result2a = keyboard.GetKeyPressed('A');
	auto result2b = keyboard.GetKeyPressed('B');

	//Then
	EXPECT_FALSE(result1a);
	EXPECT_FALSE(result1b);

	EXPECT_FALSE(result2a);
	EXPECT_FALSE(result2b);
}
TEST(KeyboardTest, GetKeyPressed_OneKeyIsDownThanUpSecondIsUpThanDown_ReturnFalseForFirstTrueForSecond) {
	//Given
	SystemKeyboardMock systemKeyboardMock;
	EXPECT_CALL(systemKeyboardMock, GetKeyState('A'))
		.WillOnce(Return(1))	//used to skip
		.WillOnce(Return(1))
		.WillOnce(Return(0));
	EXPECT_CALL(systemKeyboardMock, GetKeyState('B'))
		.WillOnce(Return(0))	//used to skip
		.WillOnce(Return(0))
		.WillOnce(Return(1));

	Keyboard keyboard = Keyboard(systemKeyboardMock);

	//this is to skip not pressed state when constructing object 
	//(by default is setting to false in array)
	keyboard.GetKeyPressed('A');
	keyboard.GetKeyPressed('B');

	//When
	auto result1a = keyboard.GetKeyPressed('A');
	auto result1b = keyboard.GetKeyPressed('B');

	auto result2a = keyboard.GetKeyPressed('A');
	auto result2b = keyboard.GetKeyPressed('B');

	//Then
	EXPECT_FALSE(result1a);
	EXPECT_FALSE(result1b);

	EXPECT_FALSE(result2a);
	EXPECT_TRUE(result2b);
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
TEST(KeyboardTest, GetKeyReleased_TwoKeysIsDownThanUpInTheSameTime_ReturnTrueForBoth) {
	//Given
	SystemKeyboardMock systemKeyboardMock;
	EXPECT_CALL(systemKeyboardMock, GetKeyState('A'))
		.WillOnce(Return(1))
		.WillRepeatedly(Return(0));
	EXPECT_CALL(systemKeyboardMock, GetKeyState('B'))
		.WillOnce(Return(1))
		.WillRepeatedly(Return(0));

	Keyboard keyboard = Keyboard(systemKeyboardMock);

	//When
	auto result1a = keyboard.GetKeyReleased('A');
	auto result1b = keyboard.GetKeyReleased('B');

	auto result2a = keyboard.GetKeyReleased('A');
	auto result2b = keyboard.GetKeyReleased('B');

	//Then
	EXPECT_FALSE(result1a);
	EXPECT_FALSE(result1b);

	EXPECT_TRUE(result2a);
	EXPECT_TRUE(result2b);
}
TEST(KeyboardTest, GetKeyReleased_TwoKeysIsUpThanDownInTheSameTime_ReturnFalseForBoth) {
	//Given
	SystemKeyboardMock systemKeyboardMock;
	EXPECT_CALL(systemKeyboardMock, GetKeyState('A'))
		.WillOnce(Return(0))
		.WillRepeatedly(Return(1));
	EXPECT_CALL(systemKeyboardMock, GetKeyState('B'))
		.WillOnce(Return(0))
		.WillRepeatedly(Return(1));

	Keyboard keyboard = Keyboard(systemKeyboardMock);

	//When
	auto result1a = keyboard.GetKeyReleased('A');
	auto result1b = keyboard.GetKeyReleased('B');

	auto result2a = keyboard.GetKeyReleased('A');
	auto result2b = keyboard.GetKeyReleased('B');

	//Then
	EXPECT_FALSE(result1a);
	EXPECT_FALSE(result1b);

	EXPECT_FALSE(result2a);
	EXPECT_FALSE(result2b);
}
TEST(KeyboardTest, GetKeyReleased_OneKeyIsDownThanUpSecondIsUpThanDown_ReturnTrueForFirstFalseForSecond) {
	//Given
	SystemKeyboardMock systemKeyboardMock;
	EXPECT_CALL(systemKeyboardMock, GetKeyState('A'))
		.WillOnce(Return(1))
		.WillOnce(Return(0));
	EXPECT_CALL(systemKeyboardMock, GetKeyState('B'))
		.WillOnce(Return(0))
		.WillOnce(Return(1));

	Keyboard keyboard = Keyboard(systemKeyboardMock);

	//When
	auto result1a = keyboard.GetKeyReleased('A');
	auto result1b = keyboard.GetKeyReleased('B');

	auto result2a = keyboard.GetKeyReleased('A');
	auto result2b = keyboard.GetKeyReleased('B');

	//Then
	EXPECT_FALSE(result1a);
	EXPECT_FALSE(result1b);

	EXPECT_TRUE(result2a);
	EXPECT_FALSE(result2b);
}