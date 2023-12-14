#include <iostream>
using namespace std;

bool isSafe(int** board, int row, int col, int n) 
{
    for (int i = 0; i < col; i++)  //checks in rows 
	{
        if (board[row][i]) 
        {
        	return false; //found another queen in the same row
		}
	}
	for (int i = 0; i < row; i++) // Checks in columns	
	{
        if (board[i][col])
        {
        	return false; //found another queen in the same column
		}
    }        
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) //checks in left diagonal
    {
	
        if (board[i][j])
        {
        	return false; //found another queen in the left diagonal
		}
    }
    for (int i = row, j = col; i < n && j >= 0; i++, j--) //checks in right diagonal
	{
        if (board[i][j])
        {
        	return false; //found another queen in the right diagonal
		}
            
    }
    return true; //no queen in same row, column, left diagonal, or right diagonal
}

bool solveNQueens(int** board, int col, int n) 
{
    if (col >= n) //the queens have been placed
    {
    	return true;
	}
        
    for (int i = 0; i < n; i++)  //checks in a column
	{
        if (isSafe(board, i, col, n)) //checking if the queen can be placed
		{
            board[i][col] = 1; //if true, queen is placed
            if (solveNQueens(board, col + 1, n)) //now checks in different columns
            {
            	return true; //solutions found
			}
                
            board[i][col] = 0; //no solution in the same row, tries out next row in the same column
        }
    }
    return false; //no solution found
}

int main() 
{
    int queens;
    cout << "For how many Queens do you want to set the board: ";
    cin >> queens;
    int** board = new int*[queens]; // Dynamic allocation for the board

    for (int i = 0; i < queens; i++) 
	{
        board[i] = new int[queens];
        for (int j = 0; j < queens; j++) 
		{
            board[i][j] = 0; // Initialize the board with zeros
        }
    }

    if (solveNQueens(board, 0, queens)) 
	{
        for (int i = 0; i < queens; i++) 
		{
            for (int j = 0; j < queens; j++) 
			{	
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } 
	else 
	{
        cout << "No solution exists." << endl;
    }

    // Deallocate memory
    for (int i = 0; i < queens; i++) 
	{
        delete[] board[i];
    }
    delete[] board;

    return 0;
}

