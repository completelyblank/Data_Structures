#include <iostream>
using namespace std;

// Define the size of the Sudoku grid (typically 9x9)
const int N = 9; //Sudoku boards are 9 columns and 9 rows

// Function to print the Sudoku solved board 
void printGrid(int grid[N][N]) 
{
    for (int row = 0; row < N; row++) 
	{
        for (int col = 0; col < N; col++) 
		{
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Function to check if a number can be placed in a specific cell
bool isSafe(int grid[N][N], int row, int col, int num) 
{
    for (int i = 0; i < N; i++) // Check if the number is already in the current row or column
	{
        if (grid[row][i] == num || grid[i][col] == num) 
		{
            return false;
        }
    }

    // Check if the number is already in the current 3x3 box (can't enter same number)
    int startRow = row - row % 3; //startRow is the topmost row of the subgrid //we start rows from the top
    int startCol = col - col % 3; //startCol is the leftmost column of the subgrid //we start grids from the left
    for (int i = 0; i < 3; i++) //subgrid row iterator
	{
        for (int j = 0; j < 3; j++) //subgrid column iterator
		{
            if (grid[i + startRow][j + startCol] == num) //checking for number in subgrid //recursion to do until all cells checked
			{
                return false; //number found, can't enter the same number in the row
            }
        }
    }
    return true; // If a number is not found in the above checks, it can be placed in the cell
}

//Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(int grid[N][N]) 
{
    int row, col;

    // Find an empty cell (empty cells are 0)
    bool found = false; 
    for (row = 0; row < N; row++) //rows go from 0 to N which is 9
	{
        for (col = 0; col < N; col++) //columns go from 0 to N which is 9
		{
            if (grid[row][col] == 0) //if there is an empty space
			{
                found = true;
                break;
            }
        }
        if (found) 
		{
            break;
        }
    }

    // If no empty cell (0) is found, the puzzle is solved
    if (!found) 
	{
        return true;
    }

    // Try placing numbers from 1 to 9 in the empty cell
    for (int num = 1; num <= 9; num++) 
	{
        if (isSafe(grid, row, col, num)) //if the number is not present 
        
		{
            grid[row][col] = num; // Place the number in the cell

            if (solveSudoku(grid)) // Recursively try to solve the remaining puzzle
			{
                return true;
            }

            grid[row][col] = 0; // If placing the number does not lead to a solution, backtrack by letting the cell remain empty, and try with a different number
        }
    }
    return false; // If no number can be placed, return false to backtrack
}

int main() 
{
    int grid[N][N];
    for (int i=0; i<=N; i++) //manual sudoku maker //will randomize it 
    {
    	for (int j=0; j<=N;  j++)
    	{
    		cout << "Enter in a number from 1-9: ";
    		cin >>grid[i][i];
		}
	}

    if (solveSudoku(grid)) 
	{
        cout << "Solved Sudoku:" << endl;
        printGrid(grid);
    } 
	else 
	{
        cout << "No solution exists." << endl;
    }

    return 0;
}

