#include <cassert>
#include <iostream>
#include "game.h"

//tests for initializegrid() method
void testInitializeGrid()
{
    initializegrid();
    //check if all elements in the board are empty
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            assert(board[i][j] == ' ');
        }
    }
}

//tests for isMoveValid() method
void testIsMoveValid()
{
    initializegrid();
    assert(isMoveValid(1, 1) == true); // Valid move
    assert(isMoveValid(2, 2) == true); // Valid move
    assert(isMoveValid(0, 0) == false); // Out of bounds
    assert(isMoveValid(4, 2) == false); // Out of bounds
    assert(isMoveValid(2, 0) == false); // Out of bounds
}

//tests for horizontal() method
void testHorizontal()
{
    initializegrid();
    //test horizontal win condition
    board[0][0] = 'X';
    board[0][1] = 'X';
    board[0][2] = 'X';
    horizontal('X');
    assert(isWin == 1);
}

//unit tests for vertical() method
void testVertical()
{
    initializegrid();
    //test vertical win condition
    board[0][0] = 'O';
    board[1][0] = 'O';
    board[2][0] = 'O';
    vertical('O');
    assert(isWin == 1);
}

//unit tests for diagonall() method
void testDiagonall()
{
    initializegrid();
    //test diagonal win condition
    board[0][0] = 'X';
    board[1][1] = 'X';
    board[2][2] = 'X';
    diagonall('X');
    assert(isWin == 1);
}

//unit tests for diagonalr() method
void testDiagonalr()
{
    initializegrid();
    //test diagonal win condition
    board[0][2] = 'O';
    board[1][1] = 'O';
    board[2][0] = 'O';
    diagonalr('O');
    assert(isWin == 1);
}

//unit tests for isFull() method
void testIsFull()
{
    initializegrid();
    //fill the board
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            board[i][j] = 'X';
        }
    }
    isFull();
    assert(full == 1); //the board is full
}

//function to run all the tests
void runTests()
{
    testInitializeGrid();
    testIsMoveValid();
    testHorizontal();
    testVertical();
    testDiagonall();
    testDiagonalr();
    testIsFull();

    std::cout << "All tests passed!\n";
}
