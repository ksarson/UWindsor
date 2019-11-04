/*	
	Sarson, Kolby
	ID:  104232327

	Assignment #2
	Due Date:  February 12, 2017

	Purpose:  	Solve any given maze using the right hand rule, accounting for passing spaces previously
				traversed and when the only exit is the entrance.  Also prints the maze after each step. 

	"I acknowledge that this is my own work and did not receive any 
	unauthorized help with it."
*/

#include <stdio.h>

/* Function Prototypes */
void findStart(char[12][12]); 						// Finds the start point from the first column of the input maze (maze[][0])
int mazeTraversal(char[12][12], int, int, int); 	// Recursive function that gives maze movements
void printMaze(char[12][12]);						// Prints the current state of the maze after each movement
int validMove(char[12][12], int, int);				// Determines the validity of the next movement (input coordinates)
int coordsAreEdge(int, int);						// Checks if the input coordinate is an edge or not

/* Main Function */
int main()
{	
	int *dir = 0;		// right = 0, up = 1, left = 2, down = 3;

	char maze[12][12] = {	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
							{'1', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '1'},
							{'0', '0', '1', '0', '1', '0', '1', '1', '1', '1', '0', '1'},
							{'1', '1', '1', '0', '1', '0', '0', '0', '0', '1', '0', '1'},
							{'1', '0', '0', '0', '0', '1', '1', '1', '0', '1', '0', '0'},
							{'1', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
							{'1', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
							{'1', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
							{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
							{'1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1'},
							{'1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1'},
							{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}};

	printf("Inital Maze\n");
	printMaze(maze);
	findStart(maze);
	printf("Solved Maze\n");
	printMaze(maze);

	return 0;
}

/*
Objective:  Finds the start point from the first column of the input maze (maze[][0])
Input: 		Maze array
Output: 	Calls print function followed by maze traversal function
*/
void findStart(char maze[12][12])
{
	int i, row;
	for (i = 1; i < 11; i++)
	{
		if (maze[i][0] == '0')
		{
			maze[i][0] = 'X';	// Places X in the array at the starting location
			row = i;			// Holds row at which starting location is found
		}
	}
	//printMaze(maze);
	mazeTraversal(maze, row, 0, 0);
}

/*
Objective:  Recursive function that gives maze movements
Input:  	(x,y) Coordinates, maze array and direction pointer
Output: 	Calls print function followed by maze traversal function again
*/
int mazeTraversal(char maze[12][12], int row, int col, int dir)
{
	if (col == 0 && maze[row][col] == 'X' && maze[row][col+1] == '0')	// When currently at the starting postion, and next position is still 0
	{
		col += 1;									// Since start is on left edge, first move must be right
		maze [row][col] = 'X';						// Second space assigned 'X'
		//printMaze(maze);
		return mazeTraversal(maze, row, col, dir);	// Recursive call for mazeTraversal
	}
	else if (col == 0 && maze[row][col] == 'X')		// When you exit the maze through the same way as you entered
	{
		printf ("You exited through the entrance, there was no other exit\n");
	}
	else if (coordsAreEdge(row, col) == 1)			//  When currently on the edge of the maze, but not at starting position (Based on previous ifs)
	{
		return 0;
	}	
	else
	{
		int prevMove = dir % 4;		// Modding direction by 4 will always return 0 through 3 (Cases)
			switch (prevMove)		// Previous Move:  right = 0, up = 1, left = 2, down = 3;
			{
				case 0:
					if (validMove(maze, row+1, col) == 0)	// When previous move right, check down as next move
					{
						row += 1;
						maze [row][col] = 'X';
						dir = 3;
						//printMaze(maze);
						break;
					}
					else 		// Otherwise add 1 to direction so next call will check other directions in counterclockwise order
					{
						dir += 1;
						break;
					}
				case 1:
					if (validMove(maze, row, col+1) == 0)	// When previous move right, check down as next move
					{
						col += 1;
						maze [row][col] = 'X';
						dir = 0;							
						//printMaze(maze);
						break;
					}
					else 		// Otherwise add 1 to direction so next call will check other directions in counterclockwise order
					{
						dir += 1;
						break;
					}
				case 2:
					if (validMove(maze, row-1, col) == 0)	// When previous move right, check down as next move
					{
						row -= 1;
						maze [row][col] = 'X';
						dir = 1;
						//printMaze(maze);
						break;
					}
					else 		// Otherwise add 1 to direction so next call will check other directions in counterclockwise order
					{
						dir += 1;
						break;
					}
				case 3:
					if (validMove(maze, row, col-1) == 0)	// When previous move right, check down as next move
					{
						col -= 1;
						maze [row][col] = 'X';
						dir = 2;
						//printMaze(maze);
						break;
					}
					else 		// Otherwise add 1 to direction so next call will check other directions in counterclockwise order
					{
					dir += 1;
					break;
					}
			}
		return mazeTraversal(maze, row, col, dir);		// Recursive call of mazeTraversal
	}
}

/*
Objective:  Prints the current state of the maze after each movement
Input: 		Maze array
Output:  	Prints the current state of the array
*/
void printMaze(char maze[12][12])
{
	int i, j;
	//printf ("New Move\n");
	for (i = 0; i < 12; i++)
	{
		for (j = 0; j < 12; j++)
		{
			printf(" %c ", maze[i][j]);
		}
		printf("\n");
	}
}

/*
Objective:  Determines the validity of the next movement
Input: 		(x,y) Coordinates and maze array
Output: 	0 for valid move; 1 for wall
*/
int validMove(char maze[12][12], int row, int col)
{
	if (maze [row][col] != '1')
	{
		return 0;		// Returns 0 if next move is not a wall
	}
	else 
	{
		return 1;		// Retruns 1 if next move is a wall
	}
}

/*
Objective:  Checks if the input coordinate is an edge or not
Input: 		(x,y) Coordinates
Output: 	0 for non-edge; 1 for edge
*/
int coordsAreEdge(int row, int col)
{
	if (row == 0 || row == 11 || col == 0 || col == 11)
	{
		return 1;		// Returns 1 if coordinates are on the edge of the maze
	}
	else
	{
		return 0;		// Returns 0 if coordinates are not on the edge of the maze
	}
}