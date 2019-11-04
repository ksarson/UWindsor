// Document your own information here

#include <stdio.h>

/* Function Prototypes */
int SumDigits_Iterative(int);
int SumDigits_Recursive(int);

// Function prototype statements must appear below this line and above main()

/* Main Function */
int main( )
{
    int V1;	// This is the only variable needed in the main function

    printf ("Enter an integer number in the range from 0 to 1 billion: ");
    scanf ("%d", &V1);

    printf("Iteration: the sum of the digits is %d\n", SumDigits_Iterative(V1));
   printf("Recursion: the sum of the digits is %d\n", SumDigits_Recursive(V1));

    return 0 ;
}

// Function definitions must appear below this line

/* Takes an integer and sums its digits using iteration */
int SumDigits_Iterative (int V1)
{
	int i, sum = 0, rem;

	while (V1 > 0)	// Executes only while V1 is positive (not 0 either)
	{
		rem = V1 % 10;	// Finds the value of the last digit
		sum += rem;		// Adds the last digit to sum
		V1 /= 10;		// Removes the last digit from V1
	}
	return sum;
}

/* Takes an integer and sums its digits using recursion */
int SumDigits_Recursive (int V1)
{
	int i, sum = 0, rem;

	if (V1 < 10)	// If V1 < 10, V1 is a single digit and therefore the sum
		return V1;	

	rem = V1 % 10;	// Finds value of last digit
	V1 /= 10;		// Removes last digit from V1

	return (rem + SumDigits_Recursive (V1));	// Adds remainder to the recursive call
}
