#include <iostream>
using namespace std;

// Function to print the maze
void printMaze(int** maze, int numRows, int numCols) 
{
    for (int i = 0; i < numRows; i++) 
	{
        for (int j = 0; j < numCols; j++) 
		{
            if (maze[i][j] == 0) 
            {
            	cout << "|"; // Wall
			}
            else if (maze[i][j] == 1)
			{
				cout << " "; // Open path
        	}
			else if (maze[i][j] == 2) 
			{
                cout << "X"; // Path taken by the rat
            }
			else 
			{
                cout << "o"; // Visited but not on the solution path
            }
        }
        cout << endl;
    }
    }
	

// Function to check if a move is valid
bool isSafe(int** maze, int numRows, int numCols, int x, int y) 
{
    return (x >= 0 && x < numRows && y >= 0 && y < numCols && maze[x][y] == 1); 
    // x coordinate is more than 1 & x coordinate is not at last row //not going out of bounds
    // y coordinate is more than 1 & y coordinate is not at last column //not going out of bounds
    // the coordinate the loop is at doesn't have any wall on it
    // then return true //its's safe to be there
}

// Recursive function to solve the maze
bool solveMaze(int** maze, int numRows, int numCols, int x, int y) //2d maze, rows, columns, x coordinate, y coordinate
{
    if (x == numRows - 1 && y == numCols - 1) // rat reaches the exit
	{
        maze[x][y] = 2; // exit cell is 2
        return true; //maze solved
    }

    if (isSafe(maze, numRows, numCols, x, y)) // Check if the current cell is a valid move
	{
        maze[x][y] = 2; // Mark the current cell as part of the solution path

        // checks if rat can move right
        if (solveMaze(maze, numRows, numCols, x + 1, y)) // x+1 means going right
        {
        	return true;
		}
		
		// checks if rat can move left
        if (solveMaze(maze, numRows, numCols, x - 1, y)) // x-1 means going left
        {
        	return true;
		}
		
        // checks if rat can move down
        if (solveMaze(maze, numRows, numCols, x, y + 1)) // y+1 means going down 
        {
        	return true;	
		}
    
        // If no valid moves, backtrack
        maze[x][y] = 1; //dead end 
        return false;
    }

    return false;
}

// Function to solve the rat in a maze problem
bool solveRatMaze(int** maze, int numRows, int numCols) 
{
    if (maze != NULL && numRows > 0 && numCols > 0) //maze exists and row and column are positive
	{
        if (solveMaze(maze, numRows, numCols, 0, 0)) 
		{
            return true;
        }
    }
    return false;
}

int main() 
{
    int numRows, numCols;

    cout << "Enter the number of rows: ";
    cin >> numRows;
    cout << "Enter the number of columns: ";
    cin >> numCols;

    int** maze = new int*[numRows]; // Create dynamic 2D array for the maze
    for (int i = 0; i < numRows; i++) //row iterator
	{
        maze[i] = new int[numCols];
        for (int j = 0; j < numCols; j++) //column iterator
		{
            cout << "Enter maze cell [" << i << "][" << j << "] (0 for walls, 1 for open paths): ";
            cin >> maze[i][j];
        }
    }

    cout << "Maze:\n";
    printMaze(maze, numRows, numCols);

    if (solveRatMaze(maze, numRows, numCols)) //solution exists //function call is true
	{
        cout << "\nSolution path:\n";
        printMaze(maze, numRows, numCols);
    } 
	else //solution doesn't exist //function call is false
	{
        cout << "\nNo solution exists.\n";
    }

    // Deallocate memory
    for (int i = 0; i < numRows; i++) 
	{
        delete[] maze[i]; //maze deleted
    }
    delete[] maze;

    return 0;
}

