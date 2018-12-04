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
}

TEST(TicTacToeBoardTest, toggleTurnTwice)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.toggleTurn(), O);
	ASSERT_EQ(game.toggleTurn(), X);
}

TEST(TicTacToeBoardTest, toggleTurnTrice)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.toggleTurn(), O);
	ASSERT_EQ(game.toggleTurn(), X);
	ASSERT_EQ(game.toggleTurn(), O);
}

TEST(TicTacToeBoardTest, placeValidOne)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.placePiece(0, 2), X);
}

TEST(TicTacToeBoardTest, placeValidTwo)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.placePiece(0, 2), X);
	ASSERT_EQ(game.placePiece(1, 2), O);
}

TEST(TicTacToeBoardTest, placeInvalidOne)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.placePiece(0, 5), Invalid);
}
 
TEST(TicTacToeBoardTest, placeInvalidOneNeg)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.placePiece(-123456, 2), Invalid);
}

TEST(TicTacToeBoardTest, placeInvalidTwoNeg)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.placePiece(0, 2), X);
	ASSERT_EQ(game.placePiece(-123456, 2), Invalid);
}

TEST(TicTacToeBoardTest, placeInvalidTwo)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.placePiece(0, 2), X);
	ASSERT_EQ(game.placePiece(12, 2), Invalid);
}

TEST(TicTacToeBoardTest, placeInvalidOnNonBlank)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.placePiece(0, 2), X);
	ASSERT_EQ(game.placePiece(0, 2), X);
}

TEST(TicTacToeBoardTest, noWinnerGetWinner)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.placePiece(0, 2), X);
	ASSERT_EQ(game.placePiece(0, 1), O);
	ASSERT_EQ(game.placePiece(0, 0), X);
	ASSERT_EQ(game.getWinner(), Invalid);
}

TEST(TicTacToeBoardTest, catsGameGetWinner)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.placePiece(0, 2), X);
	ASSERT_EQ(game.placePiece(0, 1), O);
	ASSERT_EQ(game.placePiece(0, 0), X);
	
	ASSERT_EQ(game.placePiece(2, 0), O);
	ASSERT_EQ(game.placePiece(2, 1), X);
	ASSERT_EQ(game.placePiece(2, 2), O);
	
	ASSERT_EQ(game.placePiece(1, 2), X);
	ASSERT_EQ(game.placePiece(1, 1), O);
	ASSERT_EQ(game.placePiece(1, 0), X);
	
	ASSERT_EQ(game.getWinner(), Blank);
}

TEST(TicTacToeBoardTest, xWinsGetWinner)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.placePiece(0, 0), X);
	ASSERT_EQ(game.placePiece(0, 1), O);
	ASSERT_EQ(game.placePiece(1, 0), X);
	
	ASSERT_EQ(game.placePiece(1, 1), O);
	ASSERT_EQ(game.placePiece(2, 0), X);
	
	ASSERT_EQ(game.getWinner(), X);
}

TEST(TicTacToeBoardTest, oWinsGetWinner)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.placePiece(0, 0), X);
	ASSERT_EQ(game.placePiece(0, 1), O);
	
	ASSERT_EQ(game.placePiece(1, 0), X);
	ASSERT_EQ(game.placePiece(1, 1), O);
	
	ASSERT_EQ(game.placePiece(2, 2), X);
	ASSERT_EQ(game.placePiece(2, 1), O);
	
	ASSERT_EQ(game.getWinner(), O);
}

TEST(TicTacToeBoardTest, xWinsDiagGetWinner)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.placePiece(0, 0), X);
	ASSERT_EQ(game.placePiece(0, 2), O);
	
	ASSERT_EQ(game.placePiece(1, 1), X);
	ASSERT_EQ(game.placePiece(1, 0), O);
	
	ASSERT_EQ(game.placePiece(2, 2), X);
	
	ASSERT_EQ(game.getWinner(), X);
}

TEST(TicTacToeBoardTest, oWinsOppoDiagGetWinner)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.placePiece(0, 0), X);
	ASSERT_EQ(game.placePiece(0, 2), O);
	
	ASSERT_EQ(game.placePiece(1, 2), X);
	ASSERT_EQ(game.placePiece(1, 1), O);
	
	ASSERT_EQ(game.placePiece(2, 2), X);
	ASSERT_EQ(game.placePiece(2, 0), O);
	
	ASSERT_EQ(game.getWinner(), O);
}

TEST(TicTacToeBoardTest, topRowGetWinner)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.placePiece(0, 0), X);
	ASSERT_EQ(game.placePiece(1, 2), O);
	
	ASSERT_EQ(game.placePiece(0, 1), X);
	ASSERT_EQ(game.placePiece(1, 1), O);
	
	ASSERT_EQ(game.placePiece(0, 2), X);
	
	ASSERT_EQ(game.getWinner(), X);
}

TEST(TicTacToeBoardTest, midRowGetWinner)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.placePiece(0, 0), X);
	ASSERT_EQ(game.placePiece(1, 0), O);
	
	ASSERT_EQ(game.placePiece(0, 1), X);
	ASSERT_EQ(game.placePiece(1, 1), O);
	
	ASSERT_EQ(game.placePiece(2, 2), X);
	ASSERT_EQ(game.placePiece(1, 2), O);
	
	ASSERT_EQ(game.getWinner(), O);
}

TEST(TicTacToeBoardTest, bottemRowGetWinner)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.placePiece(2, 0), X);
	ASSERT_EQ(game.placePiece(1, 0), O);
	
	ASSERT_EQ(game.placePiece(2, 1), X);
	ASSERT_EQ(game.placePiece(1, 1), O);
	
	ASSERT_EQ(game.placePiece(2, 2), X);
	
	ASSERT_EQ(game.getWinner(), X);
}

TEST(TicTacToeBoardTest, rightColGetWinner)
{
	TicTacToeBoard game;
	ASSERT_EQ(game.placePiece(2, 0), X);
	ASSERT_EQ(game.placePiece(0, 2), O);
	
	ASSERT_EQ(game.placePiece(1, 1), X);
	ASSERT_EQ(game.placePiece(1, 2), O);
	
	ASSERT_EQ(game.placePiece(2, 1), X);
	ASSERT_EQ(game.placePiece(2, 2), O);
	
	ASSERT_EQ(game.getWinner(), O);
}
