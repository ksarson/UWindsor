/* Program-2 for Assignment-5
*/
#include <stdio.h>

int func1(int num1, int num2)
{
	int result = 0;
	result = num1*num1 - num2*num2;
	return result;
}

int main(void)
{
	int num1 = 5, num2 = 6, result = 0;
	if (num1 > num2)
	{
		result = func1(num1, num2);
	}
	else
	{
		result = func1(num2, num1);
	}
	printf("Result is %d", result);
	return 0;
}