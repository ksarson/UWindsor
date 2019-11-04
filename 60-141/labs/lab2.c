/*	
	Title: lab2
	Name: SARSON, Kolby
	ID:  104232327
	Date Last Modified:  January 29, 2017
	Purpose:  This lab is to practice using recursion.
*/

#include <stdio.h>
#include <math.h>

/* Function Prototypes */
int summation (int);
int factorial (int);
int fibonacci (int);
int gcdivisor (int, int);
int power (int, int);

/* Main Function */
int main()
{
	int num = 1, sum, n, m, fact, fib, gcdiv, pwr;

	/* Runs the menu selection until sentinal (0) is entered */
	while (num != 0) // Sentinal Value
	{
		/* Menu Number Selection */
		printf ("Please enter the number correspoding to the ");
		printf ("calculations to be performed:\n0.  To end the program\n");
		printf ("1.  Summation\n2.  Factorial\n3.  Fibonacci\n4.  GCD\n");
		printf ("5.  Power\n");
		scanf ("%d", &num);

		/* Function Call and Output Based on Menu Selection */
		if (num == 1)
		{
			printf ("Please enter an integer value for n:\t");
			scanf ("%d", &n);
			sum = summation (n);

			/* Input value of -1 represents invalid */
			if (sum == -1)
				printf ("Not a valid input\n");
			else
				printf ("The Summation is of %d is %d\n", n, sum);
		}
		else if (num == 2)
		{
			printf ("Please enter an integer value for n (n >= 0):\t");
			scanf ("%d", &n);
			fact = factorial (n);
			
			/* Input value of -1 represents invalid */
			if (fact == -1)
				printf ("Not a valid input\n");
			else
				printf ("The Factorial is of %d is %d\n", n, fact);
		}
		else if (num == 3)
		{
			printf ("Please enter an integer value for n (n >= 0):\t");
			scanf ("%d", &n);
			fib = fibonacci (n);

			/* Input value of -1 represents invalid */
			if (fib == -1)
				printf ("Not a valid input\n");
			else
				printf ("The Fibonacci of %d is %d\n", n, fib);
		}
		else if (num == 4)
		{
			printf ("Please enter two integer values for n and m (n,m >= 0):\t");
			scanf ("%d %d", &n, &m);
			gcdiv = gcdivisor (n, m);

			/* Input value of -1 represents invalid */
			if (gcdiv == -1)
				printf ("Not a valid input\n");
			else
			printf ("The GCD of %d and %d is %d\n", n, m, gcdiv);
		}
		else if (num == 5)
		{
			printf ("Please enter two integer values for n and m (n > 0,m >= 0, raises n to the m):\t");
			scanf ("%d %d", &n, &m);
			pwr = power (n, m+1);

			/* Input value of -1 represents invalid */
			if (pwr == -1)
				printf ("Not a valid input\n");
			else
			printf ("The Power of %d to the %d is %d\n", n, m, pwr);
		}
		else if (num == 0)
			printf ("\n");
		else 
			printf ("Please enter a valid selection.\n");
	}
	printf ("Thank you for using our software.\n");
	return 0;	
}

/* Summation Function 
Adds every integer from 0 to the inputted number together */
int summation (int n)
{
	/* Invlaid Input */
	if (n < 0)
		return -1;

	/* Calculation */
	else if (n != 0)
		return (n + summation (n - 1));
}

/* Factorial Function 
Mulitplies the inputted number by every integer between 0 and itself */
int factorial (int n)
{
	/* Invlaid Input */
	if (n < 0)
		return -1;

	/* Calculation */
	else if (n != 1)
		return (n * factorial (n - 1));
}

/* Fibonacci Function 
Gives the value of the fibonacci squence at the inputted number's location */
int fibonacci (int n)
{
	int first = 0, second = 1;

	/* Invlaid Input */
	if (n < 0)
		return -1;

	/* Base Cases */
	else if (n == 1)
		return 0;
	else if (n == 2)
		return 1;

	/* Caluclation */
	while (n > 2)
		return (fibonacci(n-1) + fibonacci(n-2));
}

/* GCD Function 
Finds the greatest common divisor between the 2 inputted values */
int gcdivisor (int n, int m)
{
	int i;

	/* Invalid Input */
	if (n < 0 || m < 0)
		return -1;

	/* Calculation for cases where first number is the smaller/larger number */
	else if (n < m)
    {
    	if (n % m == 0) 
    		return gcdivisor (m, n % m);
    }
    else if (n > m)
    {
    	if (m % n == 0)
    		return gcdivisor (n, m % n);
    }
}

/* Power Function 
Raises the first inputted value to the power of the second inputted value */
int power (int n, int m)
{
	int i;

	/* Invalid Input */
	if (n <= 0 || m < 0)
		return -1;

	/* Calculation */
	else
	{
		while (m > 2)
		{
			return (n * power (n, m - 1));
		}
	}
}