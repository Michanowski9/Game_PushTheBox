#include "pch.h"
#include "../PushTheBox/Player.h"
#include "../PushTheBox/Player.cpp"
#include "../PushTheBox/Point.h"
#include "../PushTheBox/Point.cpp"

using ::testing::Return;

class GraphicsEngineMock : public GraphicsEngine {
public:
	MOCK_METHOD(void, DrawCell, (int, int, int), (override));
};

class MapMock : public Map {
public:
	MOCK_METHOD(const bool, IsEmptyCell, (int, int), (const override));
	MOCK_METHOD(const bool, IsBoxOnField, (int, int), (const override));
	MOCK_METHOD(void, MoveBoxUp, (int, int), (override));
	MOCK_METHOD(void, MoveBoxDown, (int, int), (override));
	MOCK_METHOD(void, MoveBoxLeft, (int, int), (override));
	MOCK_METHOD(void, MoveBoxRight, (int, int), (override));
};

class PlayerTest : public ::testing::Test {
public:
	PlayerTest() {
		graphicsEngineMock = std::make_shared<GraphicsEngineMock>();
		mapMock = std::make_shared<MapMock>();

		player = Player();
		player.SetGraphicsEngine(graphicsEngineMock);
		player.SetMap(mapMock);
	}
	Player player;
	std::shared_ptr<MapMock> mapMock;
	std::shared_ptr<GraphicsEngineMock> graphicsEngineMock;
};

TEST_F(PlayerTest, MoveUpIfPossible_EmptyCell_Move) {
	//Given
	player.SetPosition(2, 2);
	EXPECT_CALL(*mapMock, IsEmptyCell(2, 1))
		.WillOnce(Return(true));

	Point shouldBe(2, 1);

	//When
	player.MoveUpIfPossible();

	//Then
	auto result = player.GetPosition();
	EXPECT_EQ(shouldBe.x, result.x);
	EXPECT_EQ(shouldBe.y, result.y);
}
TEST_F(PlayerTest, MoveUpIfPossible_WallInCell_NotMove) {
	//Given
	player.SetPosition(2, 2);
	EXPECT_CALL(*mapMock, IsEmptyCell(2, 1))
		.WillOnce(Return(false));

	Point shouldBe(2, 2);

	//When
	player.MoveUpIfPossible();

	//Then
	auto result = player.GetPosition();
	EXPECT_EQ(shouldBe.x, result.x);
	EXPECT_EQ(shouldBe.y, result.y);
}
TEST_F(PlayerTest, MoveUpIfPossible_BoxOnFieldAndEmpty_Move) {
	//Given
	player.SetPosition(2, 2);
	EXPECT_CALL(*mapMock, IsEmptyCell(2, 1))
		.WillOnce(Return(false));
	
	EXPECT_CALL(*mapMock, IsBoxOnField(2, 1))
		.WillOnce(Return(true));
	EXPECT_CALL(*mapMock, IsEmptyCell(2, 0))
		.WillOnce(Return(true));

	EXPECT_CALL(*mapMock, MoveBoxUp(2, 1));

	Point shouldBe(2, 1);

	//When
	player.MoveUpIfPossible();

	//Then
	auto result = player.GetPosition();
	EXPECT_EQ(shouldBe.x, result.x);
	EXPECT_EQ(shouldBe.y, result.y);
}
TEST_F(PlayerTest, MoveUpIfPossible_BoxOnFieldAndNotEmpty_NotMove) {
	//Given
	player.SetPosition(2, 2);
	EXPECT_CALL(*mapMock, IsEmptyCell(2, 1))
		.WillOnce(Return(false));

	EXPECT_CALL(*mapMock, IsBoxOnField(2, 1))
		.WillOnce(Return(true));
	EXPECT_CALL(*mapMock, IsEmptyCell(2, 0))
		.WillOnce(Return(false));

	Point shouldBe(2, 2);

	//When
	player.MoveUpIfPossible();

	//Then
	auto result = player.GetPosition();
	EXPECT_EQ(shouldBe.x, result.x);
	EXPECT_EQ(shouldBe.y, result.y);
}

TEST_F(PlayerTest, MoveDownIfPossible_EmptyCell_Move) {
	//Given
	player.SetPosition(2, 2);
	EXPECT_CALL(*mapMock, IsEmptyCell(2, 3))
		.WillOnce(Return(true));

	Point shouldBe(2, 3);

	//When
	player.MoveDownIfPossible();

	//Then
	auto result = player.GetPosition();
	EXPECT_EQ(shouldBe.x, result.x);
	EXPECT_EQ(shouldBe.y, result.y);
}
TEST_F(PlayerTest, MoveDownIfPossible_WallInCell_NotMove) {
	//Given
	player.SetPosition(2, 2);
	EXPECT_CALL(*mapMock, IsEmptyCell(2, 3))
		.WillOnce(Return(false));

	Point shouldBe(2, 2);

	//When
	player.MoveDownIfPossible();

	//Then
	auto result = player.GetPosition();
	EXPECT_EQ(shouldBe.x, result.x);
	EXPECT_EQ(shouldBe.y, result.y);
}
TEST_F(PlayerTest, MoveDownIfPossible_BoxOnFieldAndEmpty_Move) {
	//Given
	player.SetPosition(2, 2);
	EXPECT_CALL(*mapMock, IsEmptyCell(2, 3))
		.WillOnce(Return(false));

	EXPECT_CALL(*mapMock, IsBoxOnField(2, 3))
		.WillOnce(Return(true));
	EXPECT_CALL(*mapMock, IsEmptyCell(2, 4))
		.WillOnce(Return(true));

	EXPECT_CALL(*mapMock, MoveBoxDown(2, 3));

	Point shouldBe(2, 3);

	//When
	player.MoveDownIfPossible();

	//Then
	auto result = player.GetPosition();
	EXPECT_EQ(shouldBe.x, result.x);
	EXPECT_EQ(shouldBe.y, result.y);
}
TEST_F(PlayerTest, MoveDownIfPossible_BoxOnFieldAndNotEmpty_NotMove) {
	//Given
	player.SetPosition(2, 2);
	EXPECT_CALL(*mapMock, IsEmptyCell(2, 3))
		.WillOnce(Return(false));

	EXPECT_CALL(*mapMock, IsBoxOnField(2, 3))
		.WillOnce(Return(true));
	EXPECT_CALL(*mapMock, IsEmptyCell(2, 4))
		.WillOnce(Return(false));

	Point shouldBe(2, 2);

	//When
	player.MoveDownIfPossible();

	//Then
	auto result = player.GetPosition();
	EXPECT_EQ(shouldBe.x, result.x);
	EXPECT_EQ(shouldBe.y, result.y);
}

TEST_F(PlayerTest, MoveLeftIfPossible_EmptyCell_Move) {
	//Given
	player.SetPosition(2, 2);
	EXPECT_CALL(*mapMock, IsEmptyCell(1, 2))
		.WillOnce(Return(true));

	Point shouldBe(1, 2);

	//When
	player.MoveLeftIfPossible();

	//Then
	auto result = player.GetPosition();
	EXPECT_EQ(shouldBe.x, result.x);
	EXPECT_EQ(shouldBe.y, result.y);
}
TEST_F(PlayerTest, MoveLeftIfPossible_WallInCell_NotMove) {
	//Given
	player.SetPosition(2, 2);
	EXPECT_CALL(*mapMock, IsEmptyCell(1, 2))
		.WillOnce(Return(false));

	Point shouldBe(2, 2);

	//When
	player.MoveLeftIfPossible();

	//Then
	auto result = player.GetPosition();
	EXPECT_EQ(shouldBe.x, result.x);
	EXPECT_EQ(shouldBe.y, result.y);
}
TEST_F(PlayerTest, MoveLeftIfPossible_BoxOnFieldAndEmpty_Move) {
	//Given
	player.SetPosition(2, 2);
	EXPECT_CALL(*mapMock, IsEmptyCell(1, 2))
		.WillOnce(Return(false));

	EXPECT_CALL(*mapMock, IsBoxOnField(1, 2))
		.WillOnce(Return(true));
	EXPECT_CALL(*mapMock, IsEmptyCell(0, 2))
		.WillOnce(Return(true));

	EXPECT_CALL(*mapMock, MoveBoxLeft(1, 2));

	Point shouldBe(1, 2);

	//When
	player.MoveLeftIfPossible();

	//Then
	auto result = player.GetPosition();
	EXPECT_EQ(shouldBe.x, result.x);
	EXPECT_EQ(shouldBe.y, result.y);
}
TEST_F(PlayerTest, MoveLeftIfPossible_BoxOnFieldAndNotEmpty_NotMove) {
	//Given
	player.SetPosition(2, 2);
	EXPECT_CALL(*mapMock, IsEmptyCell(1, 2))
		.WillOnce(Return(false));

	EXPECT_CALL(*mapMock, IsBoxOnField(1, 2))
		.WillOnce(Return(true));
	EXPECT_CALL(*mapMock, IsEmptyCell(0, 2))
		.WillOnce(Return(false));

	Point shouldBe(2, 2);

	//When
	player.MoveLeftIfPossible();

	//Then
	auto result = player.GetPosition();
	EXPECT_EQ(shouldBe.x, result.x);
	EXPECT_EQ(shouldBe.y, result.y);
}

TEST_F(PlayerTest, MoveRightIfPossible_EmptyCell_Move) {
	//Given
	player.SetPosition(2, 2);
	EXPECT_CALL(*mapMock, IsEmptyCell(3, 2))
		.WillOnce(Return(true));

	Point shouldBe(3, 2);

	//When
	player.MoveRightIfPossible();

	//Then
	auto result = player.GetPosition();
	EXPECT_EQ(shouldBe.x, result.x);
	EXPECT_EQ(shouldBe.y, result.y);
}
TEST_F(PlayerTest, MoveRightIfPossible_WallInCell_NotMove) {
	//Given
	player.SetPosition(2, 2);
	EXPECT_CALL(*mapMock, IsEmptyCell(3, 2))
		.WillOnce(Return(false));

	Point shouldBe(2, 2);

	//When
	player.MoveRightIfPossible();

	//Then
	auto result = player.GetPosition();
	EXPECT_EQ(shouldBe.x, result.x);
	EXPECT_EQ(shouldBe.y, result.y);
}
TEST_F(PlayerTest, MoveRightIfPossible_BoxOnFieldAndEmpty_Move) {
	//Given
	player.SetPosition(2, 2);
	EXPECT_CALL(*mapMock, IsEmptyCell(3, 2))
		.WillOnce(Return(false));

	EXPECT_CALL(*mapMock, IsBoxOnField(3, 2))
		.WillOnce(Return(true));
	EXPECT_CALL(*mapMock, IsEmptyCell(4, 2))
		.WillOnce(Return(true));

	EXPECT_CALL(*mapMock, MoveBoxRight(3, 2));

	Point shouldBe(3, 2);

	//When
	player.MoveRightIfPossible();

	//Then
	auto result = player.GetPosition();
	EXPECT_EQ(shouldBe.x, result.x);
	EXPECT_EQ(shouldBe.y, result.y);
}
TEST_F(PlayerTest, MoveRightIfPossible_BoxOnFieldAndNotEmpty_NotMove) {
	//Given
	player.SetPosition(2, 2);
	EXPECT_CALL(*mapMock, IsEmptyCell(3, 2))
		.WillOnce(Return(false));

	EXPECT_CALL(*mapMock, IsBoxOnField(3, 2))
		.WillOnce(Return(true));
	EXPECT_CALL(*mapMock, IsEmptyCell(4, 2))
		.WillOnce(Return(false));

	Point shouldBe(2, 2);

	//When
	player.MoveRightIfPossible();

	//Then
	auto result = player.GetPosition();
	EXPECT_EQ(shouldBe.x, result.x);
	EXPECT_EQ(shouldBe.y, result.y);
}