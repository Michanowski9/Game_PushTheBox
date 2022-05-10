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

TEST_F(PlayerTest, MoveUpI1fPossible_EmptyCell_Move) {
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