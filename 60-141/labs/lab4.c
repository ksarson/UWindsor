/*	
	SARSON, Kolby
	ID:  104232327
	Lab Exercise #4
	Date:  February 22, 2016
	Purpose:  This lab is to practice using pointers.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* Function Prototypes */
int *Largest (int *array, int size);			//  Finds and returns the address of the largest value in an array
void Swap (int *x, int *y);						//  Swaps two integer pointer values
void populateRandom (int *array, int size);		//  Randomly populates an array
void DisplayArray (int *array, int size);		//  Prints a given array

/* Main Function */
int main()
{
	int size = 10, *l, x, y;
	int array[size];

	populateRandom (array, size);  
	DisplayArray (array, size);  
	l = (int*) Largest (array, size);  
	printf ("\nLargest Element's Address: %x\n", l);  
	printf ("Please enter two numbers to swap:\n");  
	scanf ("%d %d", &x, &y);  
	printf ("Before Swap x = %d and y = %d\n", x, y);  
	Swap (&x, &y);  
	printf ("After Swap x = %d and y = %d\n", x, y); 

	return 0;
}

/* Populating Array Function 
Purpose:	Populate an array with random numbers between 0 and 99
Input:		1D array and size of the array
Output:		No output, only populates the array without printing */
void populateRandom (int *array, int size)  
{
	int i, intsize = 99;  
	srand(time(NULL));  // Makes rand() random and differing between runs
	for (i = 0; i < size; i++)
		array[i] = 1 + (rand() % intsize);  // Populate array with random numbers between 1 and size
}

/* Displaying Array Function 
Purpose:	Prints the previously populated array
Input:		1D array and size of the array
Output:		Prints the given array for display */
void DisplayArray (int *array, int size)  
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", array[i]);  // Outputs array
}

/* Finding Largest Function 
Purpose:	Searches for the largest element in the array and returns it's address
Input:		1D array and size of the array
Output:		The address of the largest element from the array */
int *Largest (int *array, int size)  
{
	int *l, largest = 0, i, j;
	for (i = 0; i < size; i++)
		{
			if (largest < array[i])  // Checks for largest value in array
			j = i;  // Saves the location of the largest
		}
	l = &array[j];  // Takes the address of the largest element from the array
	return l;  // Returns the address of the largest element from the array
}

/* Swapping Numbers Function 
Purpose:	Swaps two pointer values
Input:		Two integer pointer values
Output:		No output, only swaps the values held in the two integer pointers */
void Swap (int *x, int *y) 
{
	int hold;  
	hold = *x;  
	*x = *y;  
	*y = hold; 
}