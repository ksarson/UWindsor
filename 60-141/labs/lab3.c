/*	
	Title: lab3
	Name: SARSON, Kolby
	ID:  104232327
	Date Last Modified:  January 31, 2017
	Purpose:  This lab is to practice manipulating arrays.
*/

#include <stdio.h>
#include <time.h>
#define M 6
#define N 5

/* Function Prototypes */
void printArray2D (int [M][N]);			// Prints a 
void populateRandom2D (int [M][N]);		//
int linearSearch (int [M][N], int);		//
void leftShift2D (int [M][N]);			//
int checkDuplicate (int, int [M][N]);	//

/* Main Function */
int main()
{
	int A[M][N], n, num = 1, search;

/* Menu Number Selection */
	while (num != 0)
	{	
		/* Menu Selection */
		printf ("Please enter the number correspoding to the ");
		printf ("action to be performed on the array:\n0.  To end the program\n");
		printf ("1.  Populate\n2.  Print\n3.  Search\n4.  Left Shift\n");
		scanf ("%d", &num);

				/* Function Call and Output Based on Menu Selection */
				if (num == 0)	// Ends program
					printf ("\n");
				else if (num == 1)	// Populating call and output
				{
					populateRandom2D(A);
					printf ("\n");
				}
				else if (num == 2)	// Printing call and output
				{
					printArray2D(A);
					printf ("\n");
				}
				else if (num == 3)	// Searching call and output
				{
					printf ("Please enter a value to search for:\n");
					scanf ("%d", &n);
					search = linearSearch(A, n);
					if (search == 1)
						printf ("The value is in the array.\n\n");
					else
						printf ("The value is not in the array.\n\n");
				}
				else if (num == 4)	// Left shift call and output
				{
					leftShift2D(A);
					printf ("\n");
				}
				else // Outputs if invalid selection made
					printf ("Please enter a valid selection.\n\n");
	}
	return 0;	
}

/*
Objective: Populates the 2D Array of sizes M x N with random integers
ranging between min and max inclusive
Input: A 2D array size M by N
Output: No output, only populates array, does not print the array
*/
void populateRandom2D(int A[M][N])
{
	int i, j, newNum;
	srand(time(NULL));  // Makes rand() random and differing between runs
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			newNum = (1 + rand() % (M * N));  // Generate random number between 1 and M*N
			if (checkDuplicate (newNum, A) == 0)  // Checks if newNum is already in the array
			{
				j -= 1;  // Sets j back one so that only unique numbers are added to array
			}
			else
			{
			A[i][j] = newNum;  // Populate array with random, unique numbers between 1 and M*N
			}
		}
	}
}

/*
Objective: Given a 2D array, checks to see if a new element is already present in the array
Input: An int value of a new number to be added to the 2D array and the 2D array in question
Output: No output, only checks if int value is present in 2D array
*/
int checkDuplicate (int newNum, int A[M][N])
{
	int i, j;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (newNum == A[i][j])  // if newNum is already in array returns 0 (not unique)
			{
				return 0;
			}
		}
	}
	return 1;  //if newNum is not already in array returns 1 (unique)
}

/*
Objective: Prints a given 2D array A of size M by N
Input: A 2D array size M by N
Output: Prints inputted 2D array by size M by N in array format
*/
void printArray2D(int A[M][N])
{
	int i, j;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
			printf("%d\t", A[i][j]);  // Prints array element
	printf ("\n");  // Prints new line each row
	}
}

/*
Objective: Given a 2D array, searches linearly for a given value
Input: A 2D array size M by N and an int value to search the array for
Output: 1 or 0 to represent whether the desired int is present in the array
*/
int linearSearch(int A[M][N], int n)
{
	int i, j;
	int x = 0;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (A[i][j] == n)
			{
				x = 1;
				break;	// Breaks if number is found
			}
		}
	}
	return x;  // Returns x (1 if found and 0 if not found)
}

/*
Objective: Given a 2D array, shifts each element to the left one place, to the
end of the previous line if in the 0 position of a row, and to the last element
in the array if in the 0, 0 position
Input: A 2D array size M by N
Output: Prints inputted 2D array size M by N in array format
*/
void leftShift2D(int A[M][N])
{
	int i, j, k = 0, first, C[M*N];

	/* Converts 2D to 1D array */
	for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{ 
				C[k] = A[i][j];	 // Places 2D array into 1D array
				k++;  // Counter for 1D array
			}
		}

	/* Shifts 1D array left and places first value in final spot*/
	k = 0;  // Resets counter to 0
	first = C[0];  // Holds first element in the array
	for (k = 0; k < M*N; k++)
		C[k] = C[k+1];  // Copies element from the right of desired location into the desired location
	C[M*N-1] = first;  // Places first element into last location in array

	/* Converts sorted 1D to 2D array */
	k = 0;  // Resets counter to 0
	for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
				A[i][j] = C[k];	// Places 1D array back into 2D array
				k++;  // Counter for 1D array
			}
		}

	printArray2D(A);  // Outputs new shifted array
}
