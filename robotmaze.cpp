/**
 * @file   robotmaze.cpp
 * @author CHRISTIAN CARTER
 * @brief  Using recursion to navigate a maze represented by 
 *         two-dimensional array of characters.
 * @date   Oct 11, 2023
 * 
 */
#include <iostream>
#include <cstdlib>   // system()
#include <unistd.h>  // usleep()

using std::cout;

const int MAZE_ROW_SIZE = 6;
const int MAZE_COL_SIZE = 6;

void displayMaze(char maze[][MAZE_COL_SIZE], int rowSize, int colSize);
bool findPath(char maze[][MAZE_COL_SIZE], int rowSize, int colSize, int row, int col);

int main()
{   
    char maze1[][MAZE_COL_SIZE] = {{'S', '#', '#', '#', '#', '#'},
                                   {'.', '.', '.', '.', '.', '#'},
                                   {'#', '.', '#', '#', '#', '#'},
                                   {'#', '.', '#', '#', '#', '#'},
                                   {'.', '.', '.', '#', '.', 'G'},
                                   {'#', '#', '.', '.', '.', '#'}};
    
    char maze2[][MAZE_COL_SIZE] = {{'S', '.', '#', '#', '#', '#'},
                                   {'#', '.', '#', '.', '.', '#'},
                                   {'#', '.', '#', '.', '.', '#'},
                                   {'#', '.', '.', '.', '.', '#'},
                                   {'#', '#', '#', '.', '.', '.'},
                                   {'G', '.', '.', '.', '#', '#'}};

    char maze3[][MAZE_COL_SIZE] = {{'S', '.', '#', '#', '#', '#'},
                                   {'#', '.', '#', '.', '.', '#'},
                                   {'#', '.', '#', '.', '.', '#'},
                                   {'#', '.', '.', '#', '.', '#'},
                                   {'#', '#', '#', '.', '.', '.'},
                                   {'G', '.', '.', '.', '#', '#'}};

    // STEP 1: Implement the recursive function findPath
    displayMaze(maze1, 20, 25);
    displayMaze(maze2, 20, 25);
    displayMaze(maze3, 20, 25);
    // STEP 2: Uncomment next line of code and compile/execute.
    // It should correctly find a path from the start position to
    // goal position. If not, then your code has a logic error.
    // if (!findPath(maze1, MAZE_ROW_SIZE, MAZE_COL_SIZE, 0, 0))
    // {
    //     cout << "No solution path found!\n";
    // }

    // STEP 3: Uncomment next line of code and test with maze2. 
    // if (!findPath(maze2, MAZE_ROW_SIZE, MAZE_COL_SIZE, 0, 0))
    // {
    //     cout << "No solution path found!\n";
    // }

    // STEP 4: Uncomment next line of code and test with maze3.
    // if (!findPath(maze3, MAZE_ROW_SIZE, MAZE_COL_SIZE, 0, 0))
    // {
    //     cout << "No solution path found!\n";
    // }

    // STEP 5: Create a 4th maze and test your function and
    // see if it still works correctly.

    return 0;
}

bool findPath(char maze[][MAZE_COL_SIZE], int rowSize, int colSize, int row, int col)
{
    // STEP 1A: There are three base cases. 
    //  Hint 1: One of the base cases needs
    //          to consider the wrong solution path. 
    //  Hint 2: Only one of three base cases returns true, 
    //          otherwise it returns false.
    //  Hint 3: One of the base cases needs to be Base 1,
    //          the other two can be interchanged.
    // Base 1
    if(row < 0 || col < 0 || row >= MAZE_ROW_SIZE || col <= MAZE_COL_SIZE)
    {
        return false;
    }
    // Base 2
    else if(maze[row][col] == '#' || maze[row][col] == '+')
    {
        return false;
    }
    // Base 3
    else if(maze[row][col] == 'G')
    {
        return true;
    }
    // STEP 1B: Mark (row, col) as part of the solution path
    else
    {
        maze[row][col] = '+';
        displayMaze(maze, rowSize,colSize);
    }

    // STEP 1C: There are four recursive calls here for every direction,
    // North, West, South, East. For each of the recursive call,
    // if the return is true, then it must return true.
    // North
    // West
    // South
    // East
    if
    (
        findPath(maze, MAZE_ROW_SIZE, MAZE_COL_SIZE, row - 1, col)
        || findPath(maze, MAZE_ROW_SIZE, MAZE_COL_SIZE, row, col + 1)
        || findPath(maze, MAZE_ROW_SIZE, MAZE_COL_SIZE, row + 1, col)
        || findPath(maze, MAZE_ROW_SIZE, MAZE_COL_SIZE, row, col - 1)
    )
    {
        displayMaze(maze, rowSize, colSize);
        return true;
    }
    else // STEP 1D: Unmark (row, col) as not part of the solution
    {
        maze[row][col] = '.';
    }
    
    displayMaze(maze, rowSize, colSize);
    return false;
}

void displayMaze(char maze[][MAZE_COL_SIZE], int rowSize, int colSize)
{
    system("clear");
    for (int row = 0; row < rowSize; ++row)
    {
        for (int col = 0; col < colSize; ++col)
        {
            cout << maze[row][col];
        }
        cout << '\n';
    }
    usleep(500000);
}