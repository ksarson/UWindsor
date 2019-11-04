/* Program-4 for Assignment-5
*/
#include <stdio.h>

int main(void)
{
	int i = 0, sum = 0;
	while(i<10)
	{
		sum = sum + i;
		i++;
	}
	printf("Sum is: %d",sum);
	return 0;
}