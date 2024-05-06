

#ifndef GAME_H
#define GAME_H

//function declarations for game logic
extern char board[3][3];
extern int isWin;
extern int full;

void initializegrid();
void displayboard();
bool isMoveValid(int row, int col);
void makeMove(int row, int col, char player);
int playGame(char player);
void horizontal(char player);
void vertical(char player);
void diagonall(char player);
void diagonalr(char player);
int isFull();

#endif // GAME_H
