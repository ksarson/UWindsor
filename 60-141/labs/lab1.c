/*	
	Title: lab1
	Name: SARSON, Kolby
	ID:  104232327
	Date Last Modified:  January 17, 2017
	Purpose:  This lab is to practice using recursion.
*/

#include <stdio.h>

/* Function Prototypes */
void summation (int*, int*);				// Calculates sum of 1 to n
void factorial (int*, int*);				// Calculates factorial of n
void fibonacci (int*, int*);				// Calculates fibonacci of nth position
void gcdivisor (int*, int*, int*);			// Calculates greatest common divisor of n & m
void power (int*, int*, int*);				// Calculates n to the power of m

/* Main Function */
int main()
{
	int num = 1, sum, n, m, fact, fib, gcdiv, pwr;

	/* Runs the menu selection until sentinal (0) is entered */
	while (num != 0) // Sentinal Value
	{
		/* Menu Number Selection */
		printf ("Please enter the number correspoding to the");
		printf ("calculations to be performed:\n0.  To end the program\n");
		printf ("1.  Summation\n2.  Factorial\n3.  Fibonacci\n4.  GCD\n");
		printf ("5.  Power\n");
		scanf ("%d", &num);

		/* Function Call and Output Based on Menu Selection */
		
		/* Summation if */
		if (num == 1)
		{
			printf ("Please enter an integer value for n:\t");
			scanf ("%d", &n);
			summation (&sum, &n);

			/* Input value of -1 represents invalid */
			if (sum == -1)
				printf ("Not a valid input\n");
			else
				printf ("The Summation of %d is %d\n", n, sum);
		}
		/* Factorial if */
		else if (num == 2)
		{
			printf ("Please enter an integer value for n (n >= 0):\t");
			scanf ("%d", &n);
			factorial (&fact, &n);
			
			/* Input value of -1 represents invalid */
			if (fact == -1)
				printf ("Not a valid input\n");
			else
				printf ("The Factorial of %d is %d\n", n, fact);
		}
		/* Fibonacci if */
		else if (num == 3)
		{
			printf ("Please enter an integer value for n (n >= 0):\t");
			scanf ("%d", &n);
			fibonacci (&fib, &n);

			/* Input value of -1 represents invalid */
			if (fib == -1)
				printf ("Not a valid input\n");
			else
				printf ("The Fibonacci of %d is %d\n", n, fib);
		}
		/* GCD if */
		else if (num == 4)
		{
			printf ("Please enter two integer values for n and m (n,m >= 0):\t");
			scanf ("%d %d", &n, &m);
			gcdivisor (&n, &m, &gcdiv);

			/* Input value of -1 represents invalid */
			if (gcdiv == -1)
				printf ("Not a valid input\n");
			else
			printf ("The GCD of %d and %d is %d\n", n, m, gcdiv);
		}
		/* Power if */
		else if (num == 5)
		{
			printf ("Please enter two integer values for n and m (n > 0,m >= 0, raises n to the m):\t");
			scanf ("%d %d", &n, &m);
			power (&n, &m, &pwr);

			/* Input value of -1 represents invalid */
			if (pwr == -1)
				printf ("Not a valid input\n");
			else
			printf ("The Power of %d to the %d is %d\n", n, m, pwr);
		}
		/* Invalid Input */
		else 
			printf ("Please enter a valid selection.\n");
	}
	return 0;	
}

/* Summation Function 
Adds every integer from 0 to the inputted number together */
void summation (int *sum, int *n)
{
	int i = 0;
	*sum = 0;
	
	/* Invalid Input */
	if (*n < 0)
		*sum = -1;
	/* Calculation */
	else
		*sum = (*n*(*n+1))/2;
}

/* Factorial Function 
Mulitplies the inputted number by every integer between 0 and itself */
void factorial (int *fact, int *n)
{
	int factor = 1, n2 = *n;

	/* Base Case */
	if (n2 == 0 || n2 == 1) 
		factor = 1;
	/* Invalid Input */
	else if (n2 < 0)
		factor = -1;
	/* Calculation */
	else  
	{
		for (n2; n2 > 0; n2--)
			factor *= n2;
	}
	*fact = factor;
}

/* Fibonacci Function 
Gives the value of the fibonacci squence at the inputted numbers location */
void fibonacci (int *fib, int *n)
{
	int i, first = 0, second = 1, new;

	/* Invlaid Input */
	if (*n < 0)
		new = -1;
	/* Base Cases */
	else if (*n == 1)
		new = 0;
	else if (*n == 2)
		new = 1;
	/* Caluclation */
	else
	{
		for (i = 2; i < *n; i++)
		{
			new = first + second;
			first = second;
			second = new;
		}
	}
	*fib = new;	
}

/* GCD Function 
Finds the greatest common divisor between the 2 inputted values */
void gcdivisor (int *n, int *m, int *gcdiv)
{
	int i;

	/* Base Cases */
	if (*n == 0)
		*gcdiv = *n;
	else if (*m == 0)
		*gcdiv = *m;
	/* Invalid Input */
	else if (n < 0 || m < 0)
		*gcdiv = -1;
	/* Calculation */
	else
    {
    	for (i = 1; i <= *n || i <= *m; ++i)
    		{
    			if (*n % i == 0 && *m % i == 0)
    				*gcdiv = i;
    		}
    }
}

/* Power Function 
Raises the first inputted value to the power of the second inputted value */
void power (int *n, int *m, int *pwr)
{
	int pwr2 = 1, i;

	/* Invalid Input */
	if (n <= 0 || m < 0)
		pwr2 = -1;
	/* Calculation */
	else
	{
		for (i = 0; i < *m; i++)
			pwr2 *= *n;
	}
	*pwr = pwr2;
}