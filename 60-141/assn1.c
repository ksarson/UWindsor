/*	
	Sarson, Kolby
	ID:  104232327

	Assignment #1
	Due Date:  January 29, 2016

	Purpose:	Write a complete, well documented C program that will read in an integer number N (limited by 2
	< N < 100) and write out its factorial in terms of the numbers of its prime factors, using the output
	notation 825 = (2^0)*(3^1)*(5^2)*(7^0)*(11^1).
 
	"I acknowledge that this is my own work and did not receive any 
	unauthorized help with it."
*/

#include <stdio.h>

/* Function Prototypes */
int find_prime_count(int, int); // Will count the number of a given prime in N!
int find_next_prime(int);		// Given a prime number, will determine the next prime number
int is_prime(int); 				// Will determine whether a number is a prime number or not

/* Main Function */
int main()
{	
	int N, prime, count, num;

	scanf("%d", &N);
	while (N != 0) 	// 0 terminates the program
	{
		num = 2;	// Start with num = 2, since 1 does not effect multiplication
		printf("%d! = ", N);	
		while (num <= N)	// While num <= factorial (num <= largest possible prime number for given factorial)
		{
			prime = find_next_prime(num);	// Call find_next_prime, passing value of num (testing numbers in order to find next prime)
			num = prime + 1;	// Increment num to (1 + next prime)
			count = find_prime_count(N, prime);	// Call find_prime_count, passing values of given factorial and current prime being used
			printf("(%d^%d)", prime, count);	
			if (prime < N)	// If current prime is less than the factorial being calculated
			{
				printf("*");	
			}
		}
		printf("\n\n");
		scanf("%d", &N);
	}

	return 0;
}

/* Find the number of a prime number that are present (i.e. 7 2s) */
int find_prime_count(int N, int prime)
{
	int count = 0, i = 2, j;  // i starts at 2, first factor other than 1

	while (i <= N)	// While i is less than factorial number
	{
		j = i;	// Hold value of i
		while (i % prime == 0)	// While the prime number is a factor of i
		{
			count++;	// Count occurances of prime number as factor
			i /= prime;	// Follow through on division to see if quotient is also divisible by prime number
		}
		i = j;	// Reassign i its counter value
	i++;	// Increment i
	}
	return count; // Returns count, the number of times the current prime is multiplied into the factorial
}

/* Find the next prime number after the given prime number */
int find_next_prime(int num)
{
	int nextPrime, maxN = 100;

	while (num <= maxN)  // Loop while num does not exceed maxN
	{
		if (is_prime(num) == 1)	// Calls is_prime and if is_prime returns 1 then num is prime
		{
			nextPrime = num;		// Next prime becomes num
			return nextPrime;	// Returns the next prime number after given prime number
		}
		num++;	// Increment num if last value of num wasn't prime
	}
}

/* Check if a number is prime */
int is_prime(int num)
{
	int count = 0, primeTest = 1;  // primeTest is the number being checked as a factor of num

	while (num >= primeTest)  // Loop while primeTest does not exceed the number being checked as prime
	{
		if (num % primeTest == 0)  // If primeTest is a factor add 1 to count
		{		
			count ++;
			if (count > 2)	// If count (# of factors) exceeds 2 then not prime
			{
				primeTest = num + 1;  // Set primeTest to num + 1, so primeTest != num + 1 (See next commentted code line) if num is not prime
			}
		}
		primeTest++;  // Add 1 to primeTest
	}
	// primeTest = num + 1 if num is prime || primeTest != num + 1 if num is not prime

	if (primeTest == num + 1)
	{
		return 1;	// Return 1 if prime
	}
	else
	{
		return 0;	// Return 0 if not prime
	}
}