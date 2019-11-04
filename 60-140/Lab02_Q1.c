#include <stdio.h>
#include <math.h>

int main(void)

{
	int num1, num2;
	int thousands, hundreds, tens, ones;
	int newnum;
	int count = 52;
	int total = 120;

	/* Instructions */
	printf ("Please enter 2 4-digit integer numbers:  ");
	scanf ("%d %d", &num1, &num2);

	thousands = ((num1 / 1000) + (num2 / 1000)) / 2;
	hundreds = (((num1 / 100) - (num1 / 1000 * 10)) + ((num2 / 100) - (num2 / 1000 * 10))) / 2;
	tens = (((num1 / 10) - (num1 / 100 * 10)) + ((num2 / 10) - (num2 / 100 * 10))) / 2;
	ones = ((num1 - (num1 / 10 * 10)) + (num2 - (num2 / 10 * 10))) / 2;
	newnum = thousands * 1000 + hundreds * 100 + tens * 10 + ones;

	printf ("%d %d", --count, count--);

	printf ("The new number is:  ");
	printf ("%d \n", newnum);

	return 0;
}