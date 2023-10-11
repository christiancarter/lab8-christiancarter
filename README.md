Lab8: Recursion: maze
Learner Objectives
At the conclusion of this lab assignment, participants should be able to:

Use recursion to find the pass in the maze
Overview
A robot needs to navigate a maze. The robot, at a starting position S, is tasked to try to reach the goal position G. Positions in the maze will either be open . or blocked # with an obstacle. Positions are identified (row, col) coordinates.

The robot can only move 1 step in one of the 4 directions. Valid moves are:

Go North: (row, col) -> (row-1, col)
Go East: (row, col) -> (row, col+1)
Go South: (row, col) -> (row+1, col)
Go West: (row, col) -> (row, col-1)
The robot cannot go outside the bounds of the maze and the robot can only move to positions without obstacles.

The robot should search for a path from the starting position to the goal position (a solution path) until it finds one or until it has exhausted (exhaustive algorithm) all possibilities. It should also mark the path it finds (if any) in the maze.

In the C++ program, the maze will be represented by a two-dimensional array of characters. Below is an example of the 6x6 maze:

S#####     ‘.’ - where the robot can move (open positions)
.....#     ‘#’ - obstacles (blocked positions)
#.####     ‘S’ - start (row=0, col=0)
#.####     ‘G’ - goal (row=4, col=5)
...#.G     
##...#
A path in the maze can be marked by the + symbol. During the execution, the robot may take a path that does not lead to a solution

+##### 
++++.#     
#.####     
#.####     
...#.G     
##...#
Or, a solution path:

+##### 
++...#     
#+####     
#+####     
.++#+G     
##+++#
Your Task
You have to write a recursive function to guide the robot to a solution path.

Copy the source code bellow robotmaze.cpp,
 Update the header comment
 Read the comments in the code, it should guide you to what needs to be done
Don't be afraid to experiment. The best way to understand recursion is to try it