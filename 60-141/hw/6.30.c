#include <stdio.h>

int main()
{
	int max = 1000, array[max], i, j;

	for (i = 0; i < max; i++)
		array[i] = 1;

	for (i = 2; i < max; i++)
	{
		for (j = i + 1; j < max; j++)
		{
			if (j % i == 0)
				array[j] = 0;
		}
	}

	for (i = 0; i < max; i++)
	{
		if (array[i] == 1)
		printf ("%d ", i);
	}

	return 0;
}
