/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, goodCoords)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.placePiece(0,2), X);
}

TEST(TicTacToeBoardTest, bothOutOfBoundsNeg)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.placePiece(-1,-1), Invalid);
}

TEST(TicTacToeBoardTest, bothOutOfBoundsPos)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.placePiece(5,3), Invalid);
}

TEST(TicTacToeBoardTest, oneOutOfBoundsPos)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.placePiece(1,3), Invalid);
}

TEST(TicTacToeBoardTest, oneOutOfBoundsNeg)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.placePiece(-10,2), Invalid);
}

TEST(TicTacToeBoardTest, toggleTurnOnce)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.toggleTurn(), O);
	ASSERT_EQ(game.toggleTurn(), X);
}

