#include <cassert>
#include <iostream>
#include "game.h"
// Include your methods declarations here

// Unit tests for initializegrid() method
void testInitializeGrid() {
    initializegrid();
    // Check if all elements in the board are empty
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            assert(board[i][j] == ' ');
        }
    }
}

// Unit tests for isMoveValid() method
void testIsMoveValid() {
    initializegrid();
    assert(isMoveValid(1, 1) == true); // Valid move
    assert(isMoveValid(2, 2) == true); // Valid move
    assert(isMoveValid(0, 0) == false); // Out of bounds
    assert(isMoveValid(4, 2) == false); // Out of bounds
    assert(isMoveValid(2, 0) == false); // Out of bounds
    assert(isMoveValid(1, 1) == false); // Already taken
}

// Unit tests for horizontal() method
void testHorizontal() {
    initializegrid();
    // Test horizontal win condition
    board[0][0] = 'X';
    board[0][1] = 'X';
    board[0][2] = 'X';
    horizontal('X');
    assert(isWin == 1);
}

// Unit tests for vertical() method
void testVertical() {
    initializegrid();
    // Test vertical win condition
    board[0][0] = 'O';
    board[1][0] = 'O';
    board[2][0] = 'O';
    vertical('O');
    assert(isWin == 1);
}

// Unit tests for diagonall() method
void testDiagonall() {
    initializegrid();
    // Test diagonal win condition
    board[0][0] = 'X';
    board[1][1] = 'X';
    board[2][2] = 'X';
    diagonall('X');
    assert(isWin == 1);
}

// Unit tests for diagonalr() method
void testDiagonalr() {
    initializegrid();
    // Test diagonal win condition
    board[0][2] = 'O';
    board[1][1] = 'O';
    board[2][0] = 'O';
    diagonalr('O');
    assert(isWin == 1);
}

// Unit tests for isFull() method
void testIsFull() {
    initializegrid();
    // Fill the board
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = 'X';
        }
    }
    isFull();
    assert(full == 1); // The board is full
}

// Function to run all the tests
void runTests() {
    testInitializeGrid();
    testIsMoveValid();
    testHorizontal();
    testVertical();
    testDiagonall();
    testDiagonalr();
    testIsFull();

    std::cout << "All tests passed!\n";
}
