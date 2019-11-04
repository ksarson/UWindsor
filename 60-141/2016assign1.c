/*	
	Sarson, Kolby
	ID:  104232327
	Assignment #1
	Due Date:  January 27, 2016
	Purpose:  To reverse an arbitrary N of inputted Ns
	as well as perform calculations on those Ns and reverse these
	results again.
	"I acknowledge that this is my own work and did not receive any 
	unauthorized help with it."
*/

#include <stdio.h>
#include <math.h>

/* Function Prototypes */
int reverseInteger (unsigned int);
int generateMagicNumber (unsigned int, unsigned int, int*);

/* Main Function */
int main()
{
	int N, i, max = 0;
	unsigned int num, revnum, magic;

	printf ("Please enter the number of inputs you desire followed by\n");
	printf ("the input integers on the next line separated by spaces:\n");
	scanf ("%d", &N);  // Accepts input for number of inputs desired

	/* Loops for the number of inputs desired */
	for (i = 1; i < N + 1; i++)
	{	
	scanf ("%d", &num);  // Accepts input for each number

	/* Function Calls */
	revnum = reverseInteger (num);  // Reverses inputted number
	magic = generateMagicNumber (num, revnum, &max);  // Finds magic number for each number

	printf("%d ", magic);  // Prints all magic numbers in a single line
	}
	printf ("\n%d\n", max);  // Prints the max difference on a new line
	return 0;
}

/* Reverses the original number */
int reverseInteger (unsigned int num)
{	
	unsigned int revnum = 0;
	while (num != 0)  // Reverses the number 
	{
		revnum = revnum * 10;
		revnum = revnum + (num % 10);
		num = num / 10;
	}
	return revnum;
}

/* Generates a magic number (the reverse of the difference between
the original number and its reverse) */
int generateMagicNumber (unsigned int num, unsigned int revnum, int *max)
{
	int num2 = abs (num - revnum);  // Takes absolute value of difference
	unsigned int magicnum = 0;

	if (*max < num2)  // Calculates max difference
		*max = num2;

	while (num2 != 0)  // Reverses difference to find magic number
	{
		return reverseInteger (num2);
	}
}