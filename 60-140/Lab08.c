#include <stdio.h>

void readData(int [][6], int, int);
void rowCalc(int [][6], int, int);
void colCalc(int [][6], int, int);

int main (void)
{
	const int numrow = 3, numcol = 6;
	int score [numrow][numcol], r, c;
	readData(score, numrow, numcol);

	for (r = 0; r < numrow; r++)
	{
		for (c = 0; c < numcol; c++)
		{
			printf("%d ", score[r][c]);
		}
		printf("\n");
	}	

	rowCalc(score, numrow, numcol);
	printf("\n");
	colCalc(score, numrow, numcol);
	return 0;
}

void readData(int score[][6], int numrow, int numcol)
{
	int r, c;
	for (r = 0; r < numrow; r++)
	{
		for (c = 0; c < numcol; c++)
		{
			scanf("%d", &score[r][c]);
		}
	}
}

void rowCalc(int score[][6], int numrow, int numcol)
{
	int r, c, sum, max;
	float average;

	for (r = 0; r < numrow; r++)
	{
		sum = 0;
		max = 0;
		for (c = 0; c < numcol; c++)
		{
			sum += score[r][c];

			if (max < score[r][c])
			{
				max = score[r][c];
			}
		}
		average = (float)sum / numcol;
		printf("The average for row %d is %0.2f, \n", r + 1, average);
		printf("The max in row %d is %d \n", r + 1, max);
	}
}

void colCalc(int score[][6], int numrow, int numcol)
{
	int r, c, sum, max;
	float average;

	for (c = 0; c < numcol; c++)
	{
		sum = 0;
		max = 0;
		for (r = 0; r < numrow; r++)
		{
			sum += score[r][c];

			if (max < score[r][c])
			{
				max = score[r][c];
			}
		}
		average = (float)sum / numrow;
		printf("The average for column %d is %0.2f \n", c + 1, average);
		printf("The max in column %d is %d \n", c + 1, max);
	}
}