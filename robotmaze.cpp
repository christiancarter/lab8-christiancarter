/**
 * @file   robotmaze.cpp
 * @author Christian Carter
 * @brief  Using recursion to navigate a maze represented by 
 *         two-dimensional array of characters.
 * @date   November 1, 2023
 * 
 */
#include <iostream>
#include <unistd.h>  // usleep()

const int MAZE_ROW_SIZE = 6;
const int MAZE_COL_SIZE = 6;
int steps = 0;

void displayMaze(char maze[][MAZE_COL_SIZE], int rowSize, int colSize);
bool findPath(char maze[][MAZE_COL_SIZE], int rowSize, int colSize, int row, int col);

int main()
{
    // maze 1
    char maze1[][MAZE_COL_SIZE] = {{'S', '#', '#', '#', '#', '#'},
                                   {'.', '.', '.', '.', '.', '#'},
                                   {'#', '.', '#', '#', '#', '#'},
                                   {'#', '.', '#', '#', '#', '#'},
                                   {'.', '.', '.', '#', '.', 'G'},
                                   {'#', '#', '.', '.', '.', '#'}};
    if (!findPath(maze1, MAZE_ROW_SIZE, MAZE_COL_SIZE, 0, 0))
    {
        std::cout << "\nPath not found.";
    }
    else
    {
        std::cout << "\nPath found.";
    }
    std::cout << "\nPress enter to continue to next maze...";
    std::cin.ignore();

    // maze 2
    steps = 0;
    char maze2[][MAZE_COL_SIZE] = {{'S', '.', '#', '#', '#', '#'},
                                   {'#', '.', '#', '.', '.', '#'},
                                   {'#', '.', '#', '.', '.', '#'},
                                   {'#', '.', '.', '.', '.', '#'},
                                   {'#', '#', '#', '.', '.', '.'},
                                   {'G', '.', '.', '.', '#', '#'}};
    if (!findPath(maze2, MAZE_ROW_SIZE, MAZE_COL_SIZE, 0, 0))
    {
        std::cout << "\nPath not found.";
    }
    else
    {
        std::cout << "\nPath found.";
    }
    std::cout << "\nPress enter to continue to next maze...";
    std::cin.ignore();

    // maze 3
    steps = 0;
    char maze3[][MAZE_COL_SIZE] = {{'S', '.', '#', '#', '#', '#'},
                                   {'#', '.', '#', '.', '.', '#'},
                                   {'#', '.', '#', '.', '.', '#'},
                                   {'#', '.', '.', '#', '.', '#'},
                                   {'#', '#', '#', '.', '.', '.'},
                                   {'G', '.', '.', '.', '#', '#'}};
    if (!findPath(maze3, MAZE_ROW_SIZE, MAZE_COL_SIZE, 0, 0))
    {
        std::cout << "\nPath not found.";
    }
    else
    {
        std::cout << "\nPath found.";
    }
    std::cout << "\nPress enter to continue to next maze...";
    std::cin.ignore();

    // maze 4
    steps = 0;
    char maze4[][MAZE_COL_SIZE] = {{'S', '#', '.', '.', '.', '#'},
                                   {'.', '#', '.', '#', '.', '.'},
                                   {'.', '#', '.', '#', '#', '.'},
                                   {'.', '#', '.', '#', '.', '.'},
                                   {'.', '.', '.', '#', '#', '.'},
                                   {'.', '.', '.', '.', '#', 'G'}};
    if (!findPath(maze4, MAZE_ROW_SIZE, MAZE_COL_SIZE, 0, 0))
    {
        std::cout << "\nPath not found.";
    }
    else
    {
        std::cout << "\nPath found.";
    }
    std::cout << "\nPress enter to quit program...";
    std::cin.ignore();

    return 0;
}

/**
 * @brief iteratively traverse through maze
 * @param maze maze to traverse through, iteratively, reaching G (goal)
 * @param rowSize total number of rows for maze
 * @param colSize total number of columns for maze
 * @param row current row through which traversing is done
 * @param col current column through which traversing is done
*/
bool findPath(char maze[][MAZE_COL_SIZE], int rowSize, int colSize, int row, int col)
{
    if (row < 0 || row >= rowSize || col < 0 || col >= colSize)
    {
        return false;
    }
    else if (maze[row][col] == '#' || maze[row][col] == '+')
    {
        return false;
    }
    else if (maze[row][col] == 'G')
    {
        return true;
    }
    else
    {
        maze[row][col] = '+';
    }
    displayMaze(maze, rowSize, colSize);
    if (findPath(maze, MAZE_ROW_SIZE, MAZE_COL_SIZE, row, col + 1) ||
        findPath(maze, MAZE_ROW_SIZE, MAZE_COL_SIZE, row + 1, col) ||
        findPath(maze, MAZE_ROW_SIZE, MAZE_COL_SIZE, row, col - 1) ||
        findPath(maze, MAZE_ROW_SIZE, MAZE_COL_SIZE, row - 1, col))
    {
        return true;
    }
    else
    {
        maze[row][col] = '.';
    }
    displayMaze(maze, rowSize, colSize);
    
    return false;
}

/**
 * @brief maze is played to keep up-to-date view of traversing through it
 * @param maze maze to traverse through, iteratively, reaching G (goal)
 * @param rowSize total number of rows for maze
 * @param colSize total number of columns for maze
*/
void displayMaze(char maze[][MAZE_COL_SIZE], int rowSize, int colSize)
{
    usleep(200000); // wait for next move within maze
    system("clear");
    for (int row = 0; row < rowSize; ++row)
    {
        for (int col = 0; col < colSize; ++col)
        {
            std::cout << maze[row][col];
        }
        std::cout << '\n';
    }
}