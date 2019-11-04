#include <stdio.h>
#define SIZE 10

int someFunction (const int a[], size_t size, int num);

int main(void)
{	
	int num, loc, a[SIZE] = {8, 3, 1, 2, 6, 0, 9, 7, 4, 5};

	printf ("Please enter a number to search for: ");
	scanf ("%d", &num);
	printf ("%d is found at array location(s):\n", num);
	loc = someFunction (a, SIZE, num);
	printf ("%d\n", loc);

	return 0;
}

int someFunction (const int a[], size_t size, int num)
{
	int i, b[SIZE];
	for (i = 0; i < size; i++)
	{
		if (a[i] == num)
			return i;
	}
	return -1;
}