#include <cctype>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <sstream>

/*
 * UNCOMMENT TO RUN UNIT TESTING
 */
//#include "test.h"

using namespace std;

string player1;
string player2;
char player1Symbol;
char player2Symbol;
char currentPlayer;
int isWin = 0;
int full=0; //to check if the board is full which would cause it to be a draw
char board[3][3];
void initializegrid();
void displayboard();
bool isMoveValid(int row, int col);
void makeMove(int row, int col, char player);
int playGame(char player);
int getInput(string prompt);
bool validateInput(string input, int& value);
void horizontal(char player);
void vertical(char player);
void diagonall(char player);
void diagonalr(char player);
int isFull();
/*
 * UNCOMMENT TO RUN UNIT TESTING
 */
//void runTests();


int main()
{

	/*
	 * UNCOMMENT TO RUN UNIT TESTING
	 */
	//runTests();

    char playag = 'b';
    char choice;

    //continue playing until player doesn't quit
    while (playag != 'q')
    {
    	isWin = 0;
    	full = 0;
        cout << "Welcome players!" << endl;
        cout << "\nEnter Player 1 name: ";
        getline(cin, player1);

        cout << player1 + ", do you want to play as X or O? " << endl;
		cin >> choice;
		choice = toupper(choice); //convert choice to uppercase

		while (choice != 'X' && choice != 'O')
		{
			cout << "\nInvalid choice. Please enter X or O: ";
			cin >> choice;
			choice = toupper(choice); //convert choice to uppercase
		}

		cin.ignore(); //clear the input buffer
		player1Symbol = choice; //player 1 chooses their symbol
		player2Symbol = (choice == 'X') ? 'O' : 'X';   //player 2 is assigned the alternate symbol

		cout << "\nEnter Player 2 name: ";
		getline(cin, player2);

		cout << player1 << " is " << player1Symbol << " and " << player2 << " is " << player2Symbol << endl;


        initializegrid(); //reinitialize the board for the next game
        displayboard();

        currentPlayer = player1Symbol; //starts with player 1 symbol

        //game loop
        while (true)
        {
            playGame(currentPlayer);
            displayboard();
    		horizontal(currentPlayer);
    		vertical(currentPlayer);
    		diagonall(currentPlayer);
    		diagonalr(currentPlayer);
    		isFull();

    		//winning condition
    		if (isWin) //if isWin is 1, enter the loop
    		{
    			cout << ((currentPlayer == player1Symbol ) ? player1 : player2) << " is the winner." << endl;
    			break; // exit the loop when there's a winner
    		}


    		//draw condition for when the board is full
    		else if (full)
    		{
    			cout << "It's a draw." <<endl;  //if board is full it is a draw
    			break;
    		}

            //switch player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        cout << "Press 'q' to quit or any other key to continue another game: ";
        cin >> playag;
        cin.ignore(); // Ignore the newline character in the input buffer
    }

    cout << "Bye Bye!";
    return 0;
}



//****************************************************************
//initialize an empty board
void initializegrid()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}



//****************************************************************
//displays the state of the board
void displayboard()
{
	cout << endl;
	cout << "  1     2     3" << endl;
	cout << endl;
    for (int i = 0; i < 3; i++)
    {
    	cout << i + 1 << "  ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " ";

            if (j < 2)
            {
				cout << " | ";
			}
        }

        cout << endl;

        if (i < 2)
        {
            cout << "   -------------" << endl;
        }
    }

    cout << endl;
}



//****************************************************************
//returns true if the value received is within scope else returns false
//checks 3 things, if its within bounds, if its a digit, and if the place is not taken in the grid
bool isMoveValid(int row, int col)
{

	if(!(row >= 1 && row <= 3 && col >= 1 && col <= 3)) //if the row and column are not within the 3*3 bounds
	{
		cout << "\nPlease enter the row and column within bounds" << endl;
		return false;
	}

	if (!isdigit(row + '0') || !isdigit(col + '0'))  //check if row and columns are not digits
    {
        cout << "\nRow and column must be digits" << endl;
        return false;
    }

	if(board[row-1][col-1] != ' ')  //if the row and column is not empty
	{
		cout << "\nOops! That row and column is taken." << endl;
		return false;
	}

    return true;  //if none of the above problem persists return true
}



//****************************************************************
//makes changes to the board
void makeMove(int row, int col, char player)
{
    board[row-1][col-1] = player;
}



//****************************************************************
//the actual game controller
int playGame(char player)
{
    int row, col;

    //prompt for row input
    row = getInput(((player == player1Symbol) ? player1 : player2) + " please enter your desired row (1-3): ");

    //prompt for column input
    col = getInput(((player == player1Symbol) ? player1 : player2) + " please enter your desired column (1-3): ");

    while (!isMoveValid(row, col))
	{
    	row = getInput(((player == player1Symbol) ? player1 : player2) + " please enter your desired row (1-3): ");
    	col = getInput(((player == player1Symbol) ? player1 : player2) + " please enter your desired column (1-3): ");
	}

    //make the move
    makeMove(row, col, player);

    return 0;
}



//****************************************************************
//function to validate input for row and column
bool validateInput(string input, int& value)
{
    stringstream ss(input);
    if (ss >> value)
    {
        //check if the value is within bounds (1 to 3)
        if (value >= 1 && value <= 3)
        {
            //check if there are no extra characters after the number
            char remaining;
            if (ss >> remaining)
            {
                cout << "Invalid input. Please enter only a single numeric value." << endl;
                return false;
            }
            return true;
        }
        else
        {
            cout << "Invalid input. Please enter a value between 1 and 3." << endl;
            return false;
        }
    }
    else
    {
        cout << "Invalid input. Please enter a numeric value." << endl;
        return false;
    }
}



//****************************************************************
//function to get valid input for row and column
int getInput(string prompt)
{
    string input;
    int value;
    while (true)
    {
        cout << prompt;
        getline(cin, input);
        if (validateInput(input, value))
        {
            break;
        }
    }
    return value;
}



//****************************************************************
//checks the rows to see if a horizontal win condition is met
void horizontal(char player)
{
    int count; //initialize count to 0 to keep track of token sequence
    for (int i = 0; i < 3; i++) //run this for each row
    {
        count = 0; //reset count for every row
        for (int j = 0; j < 3; j++) //iterate over each column in the current row
        {
            if (board[i][j] == player)
            {
                count++; //increment count if there is a token belonging to the player
            }

            else
            {
            	count = 0;
            	break;
            }
        }

        if (count == 3)
        {
            isWin = 1; //set isWin to 1 if the desired sequence is found
            return;
        }
    }
}



//****************************************************************
//checks the columns to see if a vertical win condition is met
void vertical(char player)
{
    int count; //initialize count to 0 to keep track of token sequence
    for (int i = 0; i < 3; i++) //run this for each column
    {
        count = 0; //reset count for every row
        for (int j = 0; j < 3; j++) //iterate over each row in the column
        {
            if (board[j][i] == player)
            {
                count++; //increment count if there is a token belonging to the player
            }

            else
            {
            	count = 0;
            	break;
            }
        }

        if (count == 3)
        {
            isWin = 1; //set isWin to 1 if the desired sequence is found
            return;
        }
    }
}


//****************************************************************
//checks for the diagonal condition from top left to bottom right
void diagonall(char player)
{
    int count = 0; //initialize count to 0 to keep track of token sequence
    for (int i = 0; i < 3; i++) //iterate over the rows
    {
        if (board[i][i] == player)
        {
            count++; //increment count if there is a token belonging to the player
        }
        else
        {
            count = 0; //reset count if the sequence breaks
            break;
        }
    }

    if (count == 3)
    {
        isWin = 1; //set isWin to 1 if the desired sequence is found
    }
}


//****************************************************************
//checks for diagonal condition from top right to bottom left
void diagonalr(char player)
{
    int count = 0; //initialize count to 0 to keep track of token sequence
    for (int i = 0; i < 3; i++) //iterate over the rows
    {
        if (board[i][2 - i] == player) //indexing changes as we move from bottom right to top left
        {
            count++; //increment count if there is a token belonging to the player
        }
        else
        {
            count = 0; //reset count if the sequence breaks
            break;
        }
    }

    if (count == 3)
    {
        isWin = 1; //set isWin to 1 if the desired sequence is found
    }
}



//****************************************************************
//checks if the the board is full to declare a tie
int isFull()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0; //if any cell is empty, the board is not full
            }
        }
    }

    full = 1; //if all cells are occupied, the board is full
    return 0;
}
