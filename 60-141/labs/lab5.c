/*	
	SARSON, Kolby
	ID:  104232327
	Lab Exercise #5
	Date:  February 28, 2017
	Purpose:  This lab is to continue to practice using pointers.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 20

/* Function Prototypes */
void FillArray (int *array, int size);		//  Randomly populates an array
void PrintArray (int *array, int size);		//  Prints a given array 
void BubbleSort (int *array, int size);		//  Sorts the array in ascending order using the bubble method
void Swap (int *x, int *y);					//  Swaps two integer pointer values 

/* Main Function */
int main ()
{
	/* Part A */
	int a = 7;
	int *aPtr;
	aPtr = &a;
	printf("%p\n", &a);			//  Address of a
	printf("%p\n", aPtr);		//	Value of aPtr, which is the address of a
	printf("%p\n", &aPtr);		//  Address of aPtr
	printf("%d\n", a);			//  Value of a
	printf("%d\n", *aPtr);		//	Points to the value held in aPtr, which is a
	printf("%p\n", *&aPtr);		//  Points to the value at the address of aPtr, which is the address of a
	printf("%p\n", &*aPtr);		//  Address of what is pointed to by aPtr, which is the address of a
	printf("%d\n", *&a);		//  Points to value at the address of a, which is the value of a
	//printf("%d", &*a);		//  ERROR:  a itself is not a pointer

	/* Part B */
	int NumList [SIZE];
	FillArray (NumList, SIZE);
	printf ("\nThe Unsorted Array:\n");
	PrintArray(NumList, SIZE);
	BubbleSort(NumList, SIZE);
	printf ("\nThe Sorted Array:\n");
	PrintArray(NumList, SIZE);
	printf ("\n\n");
	return 0;
}

/* Populating Array Function 
Purpose:	Populate an array with random numbers between 0 and 99
Input:		1D array and size of the array
Output:		No output, only populates the array without printing */
void FillArray (int *array, int size)  
{
	int i, intsize = 100;  
	srand(time(NULL));  // Makes rand() random and differing between runs
	for (i = 0; i < size; i++)
		*(array+i) = 1 + (rand() % intsize);  // Populate array with random numbers between 1 and size
}

/* Displaying Array Function 
Purpose:	Prints the previously populated array
Input:		1D array and size of the array
Output:		Prints the given array for display */
void PrintArray (int *array, int size)  
{
	int i;
	for (i = 0; i < size - 1; i++)
		printf ("%d ", *(array+i));
	printf ("\n");
	return;  
}

/* Bubble Sort Function 
Purpose:	Sorts the array in ascending order
Input:		1D array and size of the array
Output:		No output, only sorts the values held in the array in ascending order */
void BubbleSort (int *array, int size)  
{
     int j, k;     
     for(j = 0; j < size-1 ; j++) 
          for(k = 0; k < size-j-1; k++) 
               if(*(array+k) < *(array+k+1))
                    Swap(array+k, array+k+1) ;
     return ;
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