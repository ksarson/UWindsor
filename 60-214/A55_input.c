/* Program-5 (bonus) for Assignment-5
*/
#include <stdio.h>

int main(void)
{
	int i = 0, sum = 0;
	do
	{
		sum = sum + i;
		i++;
	}while(i<10);
	
	printf("Sum is: %d",sum);
	return 0;
}