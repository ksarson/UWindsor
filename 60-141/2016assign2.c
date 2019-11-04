/*	
	Sarson, Kolby
	ID:  104232327
	Assignment #2
	Due Date:  February 10, 2016
	Purpose:  To populate an array and manipulate it in different ways
			  as well as perform tasks such as finding the largest value
			  and finding the sum of a column.
	"I acknowledge that this is my own work and did not receive any 
	unauthorized help with it."
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define COL 20
#define ROW 20

/* Function Prototypes */
void PopulateArray2DUnique (int A[][COL], unsigned int rowsize, unsigned int colsize, int min, int max);
void DisplayArray2D (int A[][COL], unsigned int rowsize, unsigned int colsize);
int FindLargest (int A[][COL], unsigned int rowsize, unsigned int colsize);
int FindColSum  (int A[][COL], unsigned int rowsize, unsigned int col_to_sum);
void Sort2DArray (int A[][COL], unsigned int rowsize, unsigned int colsize);
void CopyArray2D (int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize);
void CopyArray2DSpiral  (int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize);

/* Main Function */
int main ()
{
	unsigned int rowsize, colsize, col_to_sum;
	int max, min, A[ROW][COL], B[ROW][COL];

	/* User Inputs */
	printf ("Please enter the row size followed by the column size (Row: 0-%d, Column: 0-%d):\n", ROW, COL);
	scanf ("%u %u", &rowsize, &colsize);
	printf ("Please enter the min and max values to include in the array:\n");
	scanf ("%d %d", &max, &min);
	printf ("Please enter a column number to find the sum of (starts at 0):\n");
	scanf ("%u", &col_to_sum);

	/* Function Calls and Outputs */
	PopulateArray2DUnique (A, rowsize, colsize, max, min);
	printf ("Display2DArray:\n");
	DisplayArray2D (A, rowsize, colsize);	
	printf ("FindLargest: %d\n", FindLargest(A, rowsize, colsize));
	printf ("FindColSum of column %u: %d\n", col_to_sum, FindColSum (A, rowsize, col_to_sum));
	printf ("Sort2DArray:\n");
	Sort2DArray (A, rowsize, colsize);
	printf ("CopyArray2D:\n");
	CopyArray2D (A, B, rowsize, colsize);
	printf ("CopyArray2DSpiral:\n");
	CopyArray2DSpiral (A, B, rowsize, colsize);

	return 0;
}

/* Populates the 2D Array of sizes rowsize x colsize with random integers
ranging between min and max inclusive. */
void PopulateArray2DUnique (int A[][COL], unsigned int rowsize, unsigned int colsize, int min, int max)
{
	int i, j;
	srand(time(NULL));  // Makes rand() random and differing between runs
	for (i = 0; i < (int)rowsize; i++)
	{
		for (j = 0; j < (int)colsize; j++)
			A[i][j] = min + (rand() % (max + 1 - min));	// Populate array with random numbers
	}
}

/* Display the contents of a 2D array of size rowsize x colsize in a
table format; that is each line will display one row where the numbers
are separated by a single space character. */
void DisplayArray2D (int A[][COL], unsigned int rowsize, unsigned int colsize)
{
	int i, j;
	for (i = 0; i < (int)rowsize; i++)
	{
		for (j = 0; j < (int)colsize; j++)
			printf("%d\t", A[i][j]);	// Outputs array
	printf ("\n");
	}
}

/* Given a 2D array A of size rowsize x colsize, return the largest
integer number it contains. */
int FindLargest (int A[][COL], unsigned int rowsize, unsigned int colsize)
{
	int i, j, largest = 0;
	for (i = 0; i < (int)rowsize; i++)
	{
		for (j = 0; j < (int)colsize; j++)
		{
				if (largest < A[i][j])  // Checks for largest value in array
				largest = A[i][j];
		}
	}
	return largest;
}

/* Calculate the sum of a given column col of a 2D array of size rowsize
x colsize. Return the sum of that column. */
int FindColSum  (int A[][COL], unsigned int rowsize, unsigned int col_to_sum)
{
	int i, sum = 0;
	for (i = 0; i < (int)rowsize; i++)
		sum += A[i][col_to_sum];	// Finds sum in given column
	return sum;
}

/* Sort a 2D array of size rowsize x colsize in ascending order. i.e.
A[0][0] would have the smallest value. Example of a 3x3 sort:
1 2 3
4 5 6
7 8 9 */
void Sort2DArray (int A[][COL], unsigned int rowsize, unsigned int colsize)
{
	int i, j, k = 0, hold, pass, C[rowsize*colsize];

	/* Converts 2D to 1D array */
	for (i = 0; i < (int)rowsize; i++)
		{
			for (j = 0; j < (int)colsize; j++)
			{
				C[k] = A[i][j];	// Places 2D array into 1D array
				k++;
			}
		}

	/* Sorts 1D array */
	k = 0;
	for (pass = 0; pass < (int)(rowsize*colsize); pass++)	// Repeats sort "array size" times
	{
		for (k = 0; k < (int)(rowsize*colsize-1); k++)
		{
			if (C[k] > C[k+1])  // If value is greater than next value
			{
					hold = C[k];	// Switches value with next value
					C[k] = C[k+1];
					C[k+1] = hold;
			}
		}
	}

	/* Converts sorted 1D to 2D array */
	k = 0;
	for (i = 0; i < (int)rowsize; i++)
		{
			for (j = 0; j < (int)colsize; j++)
			{
				A[i][j] = C[k];	// Places 1D array back into 2D array
				k++;
			}
		}

	/* Outputs sorted array */
	for (i = 0; i < (int)rowsize; i++)
	{
		for (j = 0; j < (int)colsize; j++)
			printf("%d\t", A[i][j]);	// Outputs array
	printf ("\n");
	}
}

/* Copy the contents of array A into array B of the same size such that
the contents of B would be exactly the contents of A. e.g. copying A
into B:
A:        B:
1 2 3     1 2 3
4 5 6 --> 4 5 6
7 8 9     7 8 9 */
void CopyArray2D (int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize)
{
	int i, j;
	for (i = 0; i < (int)rowsize; i++)
	{
		for (j = 0; j < (int)colsize; j++)
			B[i][j] = A[i][j];	// Copies array A into B
	}

	for (i = 0; i < (int)rowsize; i++)
	{
		for (j = 0; j < (int)colsize; j++)
			printf("%d\t", B[i][j]);	// Outputs array
	printf ("\n");
	}
}

/* Copy the contents of array A into array B of the same size such that
the contents of B would be exactly the contents of A except they will
be in a clockwise spiral sorted order. e.g. copying A into B with
Spiral effects:
A:        B:
1 2 3     1 2 3
4 5 6 --> 8 9 4
7 8 9     7 6 5 */
void CopyArray2DSpiral (int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize)
{
	int rowstart, colstart, newrow, i, j, k;
	rowstart = 0; colstart = 0; newrow = 0;
	int holdrow = (int)rowsize, holdcol = (int)colsize;	// Holds rowsize and colsize
	newrow = rowstart, k = colstart; // Used to determine where A values are taken from 

	while ((rowstart < (int)rowsize) && (colstart < (int)colsize))	// While rectangle has positive side lengths
	{
		/* Places values in top row left to right */
		for (i = rowstart; i < rowstart + 1; i++)
		{
			for (j = colstart; j < (int)colsize; j++)
			{	
				if (k >= holdcol)	// Determine if next row of values is needed from A
					{
						newrow++;
						k = 0;
					}
				B[i][j] = A[newrow][k];	// Places A's ascending order values into B's spiral format
				k++;
			}
		}

		/* Places values in rightmost column top to bottom */
		for (j = (int)colsize - 1; j > (int)colsize - 2; j--)
		{
			for (i = rowstart + 1; i < (int)rowsize; i++)
			{
				if (k >= holdcol)	// Determine if next row of values is needed from A
					{
						newrow++;
						k = 0;
					}
				B[i][j] = A[newrow][k];	// Places A's ascending order values into B's spiral format
				k ++;
			}
		}

		/* Places values in bottom row right to left */
		if (((int)rowsize - rowstart) > 1)	// If statement to cancel loop if only one row left to fill
		{									// which would be filled by first nested for loop
			for (i = (int)rowsize - 1; i > (int)rowsize - 2; i--)
			{
				for (j = (int)colsize - 2; j > colstart - 1; j--)
				{
					if (k >= holdcol)	// Determine if next row of values is needed from A
						{
							newrow++;
							k = 0;
						}
					B[i][j] = A[newrow][k];	// Places A's ascending order values into B's spiral format
					k++;
				}
			}
		}

		/* Places values in leftmost column bottom to top */
		if (((int)colsize - colstart) > 1)	// If statement to cancel loop if only one column left to fill
		{									// which would be filled by second nested for loop
			for (j = colstart; j < colstart + 1; j++)
			{
				for (i = (int)rowsize - 2; i > rowstart; i--)
				{	
					if (k >= (int)holdcol)	// Determine if next row of values is needed from A
						{
							newrow++;
							k = 0;
						}
					B[i][j] = A[newrow][k];	// Places A's ascending order values into B's spiral format
					k++;
				}
			}
		}
		rowstart++; colstart++; rowsize--; colsize--;	// Removes outermost rows and columns from next round of sorting
	}

	rowsize = holdrow; colsize = holdcol;	// Reassigns rowsize and colsize

	/* Outputs spiral array */
	for (i = 0; i < (int)rowsize; i++)
	{
		for (j = 0; j < (int)colsize; j++)
			printf("%d\t", B[i][j]);
	printf ("\n");
	}
}
