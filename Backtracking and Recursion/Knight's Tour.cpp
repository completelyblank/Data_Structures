#include <iostream>
using namespace std;

const int N = 8; // The size of the chessboard (8x8 for a standard chessboard)

// Function to print the chessboard
void printBoard(int** board, int n) 
{
    for (int i = 0; i < n; i++) 
	{
        for (int j = 0; j < n; j++) 
		{
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}

// Function to check if a knight move is valid
bool isSafe(int** board, int x, int y, int n) 
{
    return (x >= 0 && y >= 0 && x < n && y < n && board[x][y] == -1);
    // x coordinate is more than 1 & x coordinate is not at last row //not going out of bounds
    // y coordinate is more than 1 & y coordinate is not at last column //not going out of bounds
    // the coordinate the loop is at doesn't have any wall on it
    // then return true //its's safe to be there
}

// Recursive function to find the Knight's Tour
bool solveKnightTour(int** board, int n, int x, int y, int moveCount) 
{
    // If all squares have been visited, the tour is complete
    if (moveCount == n * n) 
	{
        return true;
    }

    // Possible moves for a knight
    // Horses move 2.5 in a single time, in an L shape always
    int xMove[] = {2, 1, -1, -2, -2, -1, 1, 2}; //positive means right and negative means left
    int yMove[] = {1, 2, 2, 1, -1, -2, -2, -1}; //positive means up and negative means down

    // Try all next moves from the current coordinate (x, y)
    for (int k = 0; k < 8; k++) 
	{
        int nextX = x + xMove[k]; //new x coordinate
        int nextY = y + yMove[k]; //new y coordinate
        
        if (isSafe(board, nextX, nextY, n)) //using new coordinate, do recursion to check if the move is possible
		{
            board[nextX][nextY] = moveCount; //store number of the current move in the cell
            if (solveKnightTour(board, n, nextX, nextY, moveCount + 1)) //move count updated and used in recursion to put knight in new cell
			{
                return true; 
            }
            board[nextX][nextY] = -1; // Backtrack if the move doesn't lead to a solution
        }
    }

    return false; //can't enter in cell
}

// Function to find and print the Knight's Tour
bool knightTour(int n) 
{
    // Create a chessboard and initialize all cells to -1
    int** board = new int*[n];
    for (int i = 0; i < n; i++) 
	{
        board[i] = new int[n];
        for (int j = 0; j < n; j++) 
		{
            board[i][j] = -1;
        }
    }

    board[0][0] = 0; // Start the Knight's Tour from cell (0, 0)

    if (solveKnightTour(board, n, 0, 0, 1)) //recursion at start	
	{
        cout << "Knight's Tour:\n";
        printBoard(board, n);
        return true;
    } 
	else 
	{
        cout << "No solution exists.\n";
        return false;
    }

    // Deallocate memory
    for (int i = 0; i < n; i++) {
        delete[] board[i];
    }
    delete[] board;
}

int main() 
{
    int n;
    cout << "Enter the size of the chessboard (n x n): ";
    cin >> n;

    if (n <= 0 || n > N) 
	{
        cout << "Invalid board size. Please enter a value between 1 and " << N << ".\n";
    } 
	else 
	{
        knightTour(n);
    }

    return 0;
}

