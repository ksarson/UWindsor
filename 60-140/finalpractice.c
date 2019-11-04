/*#include <stdio.h>   // Question 1
#include <string.h>

int main(void)
{
	int att[4][5], av, max = 0, r, c;
	float avg[4];
	char rank[4][20];

	for (r = 0; r < 4; r++)
	{
		printf("Please enter the week %d attendances for all 5 departments:\n", r + 1);
		for (c = 0; c < 5; c++)
		{
			scanf("%d", &att[r][c]);
		}
	}
	
	for (r = 0; r < 4; r++)
	{
		av = 0;
		for (c = 0; c < 5; c++)
		{
			av += att[r][c];
		}
		avg[r] = av / 5;
	}

	for (r = 0; r < 4; r++)
	{
		if (max < avg[r])
		{
			max = avg[r];
		}

		if (avg[r] < 7)
		{
			strncpy(rank[r], "Low", 20);
			
		}
		else if (avg[r] >= 7 && avg[r] <= 8)
		{
			strncpy(rank[r], "Medium", 20);
		}
		else 
		{
			strncpy(rank[r], "High", 20);
		}
	}

	printf("\tDep1\tDep2\tDep3\tDep4\tDep5\tWeekly Average\tWeekly Rank");
	for (r = 0; r < 4; r++)
	{
		printf("\nWk%d\t", r + 1);
		for (c = 0; c < 5; c++)
		{
			printf("%d\t", att[r][c]);
		}
		printf("%0.2f\t\t", avg[r]);
		puts(rank[r]);
	}

	return 0;
}*/

/*#include <stdio.h>   // Question 2

int main(void)
{
	int num[2];
	int array[5][2];
	int r, c;

	printf("Please enter two 5 digit numbers:\n");
	scanf("%d %d", &num[0], &num[1]);

	for (c = 0; c < 2; c++)
	{
		
		for (r = 0; r < 5; r++)
		{
			array[r][c] = num[c] % 10;
			num[c] /= 10;
		}
	}

	for (r = 4; r >= 0; r--)
	{
		printf("\n");

		for (c = 0; c < 2; c++)
		{
			printf("%d\t", array[r][c]);
		}
	}

	printf("\n\n");
	return 0;
}*/

/*#include <stdio.h>   // Question 6

int main(void)
{

	int x[4], y[4], xy[4][4];
	int numx = 5;
	int numy = 1;
	int r, c;

	for (r = 0; r < 4; r++)
	{
		x[r] = numx;
		numx += 2;
	}

	for (c = 0; c < 4; c++)
	{
		y[c] = numy;
		numy += 1;
	}

	for (r = 0; r < 4; r++)
	{
		for (c = 0; c < 4; c++)
		{
			xy[c][r] = x[r] * y[c];
		}
	}

	printf("X\t5\t7\t9\t11");
	for (r = 0; r < 4; r++)
	{
		printf("\n%d\t", y[r]);

		for (c = 0; c < 4; c++)
		{
			printf("%d\t", xy[r][c]);
		}
	}

	printf("\n\n");
	return 0;
}*/

/*#include <stdio.h>   // Question 7

int main(void)
{
	int list[5];
	list[0] = 80;
	list[1] = 34;
	list[2] = 68;
	list[3] = 91;
	list[4] = 52;

	int r;

	for (r = 0; r < 5; r++)
	{
		if (list[r] == 91)
		{
			printf("\n91 is in the position %d in the list", r + 1);
			r = 5;
		}
		else if (list[r] != 91 && r == 4)
		{
			printf("\n91 is not in the list");
		}
	}

	printf("\n\n");
	return 0;
}*/

/*#include <stdio.h>   // Question 8.1 

int main(void)
{
	int n = 0;

	while (n <= 10)
	{
		n++;
		printf("%d ", n);
	}

	printf("\n\n");
	return 0;
}*/

/*#include <stdio.h>   // Question 8.1 a

int main(void)
{
	int n = 0;

	do
	{
		n++;
		printf("%d ", n);
	}
	while(n <= 10);

	printf("\n\n");
	return 0;
}*/

/*#include <stdio.h>   // Question 8.1 b

int main(void)
{
	int n;

	for (n = 1; n <= 11; n++)
	{
		printf("%d ", n);
	}

	printf("\n\n");
	return 0;
}*/

/*#include <stdio.h>   // Question 8.2 

int main(void)
{
	int a;
	int b;

	a = 5;

	while (a >= 1)
	{
		b = 1;
		while (b >= 1)
		{
			printf("%d ", b);
			b--;
		}
		printf("\n");
		a--;
	}

	printf("\n\n");
	return 0;
}*/

/*#include <stdio.h>   // Question 8.2 a

int main(void)
{
	int a;
	int b;

	a = 5;
	
	do
	{
		b = 1;

		do
		{
			printf("%d ", b);
			b--;
		}
		while (b >= 1);

		printf("\n");
		a--;
	}
	while (a >= 1);

	printf("\n\n");
	return 0;(void)
{
	int a;
	int b;

	for (a = 6; a > 1; a--)
	{
		b = 1;

		for (b = 1; b >= 1; b--)
		{
			printf("%d ", b);
		}

		printf("\n");
	}

	printf("\n\n");
	return 0;
}*/

/*#include <stdio.h>   // Question 9

int main(void)
{
	int num1, num2;
	float newnum;
	char oper;

	printf("Please enter an integer number: ");
	scanf("%d", &num1);
	printf("\nPlease enter an operator (+, -, *, /, %): ");
	scanf(" %c", &oper);
	printf("\nPlease enter another integer number: ");
	scanf("%d", &num2);

	if (oper == '+')
	{
		newnum = num1 + num2;
	}
	else if (oper == '-')
	{
		newnum = num1 - num2;
	}
	else if (oper == '*')
	{
		newnum = num1 * num2;
	}
	else if (oper == '/')
	{
		newnum = num1 / num2;
	}
	else if (oper == '%')
	{
		newnum = num1 % num2;
	}

	printf("\n%d %c %d = %0.2f\n\n", num1, oper, num2, newnum);
	return 0;
}*/

/*#include <stdio.h>   // Question 10

int main(void)
{
	char names[3][20];
	int r, c;

	for (r = 0; r < 3; r++)
	{
		printf("Enter name %d in the order lastname firstname:\n", r + 1);
		scanf(" %[^\n]s ", &names[r]);
	}

	printf("Lastname, Firstname");
	printf("-------------------");
	for (r = 0; r < 3; r++)
	{
		printf("\n%s", names[r]);
	}
	
	printf("\n\n");
	return 0;
}*/

/*#include <stdio.h>   // Question 11

int main(void)
{
	int r, c, space, star;

	for (r = 1; r < 5; r++)
	{
		space = 4 - r;
		star = (2 * r) - 1;

		for (c = 0; c < space; c++)
		{
			printf(" ");
		}
		for (c = 0; c < star; c++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}*/

/*#include <stdio.h>   // Question 12

int main(void)
{
	int array[5], r, max, min;

	printf("Please enter 5 integer numbers:\n");

	for (r = 0; r < 5; r++)
	{
		scanf("%d", &array[r]);
	}

	max = array[0];
	min = array[0];

	printf("The 5 integers entered are:\t");

	for (r = 0; r < 5; r++)
	{
		printf("%d ", array[r]);

		if (array[r] > max)
		{
			max = array[r];
		}
		else if (array[r] < min)
		{
			min = array[r];
		}
	}

	printf("\nThe max value is:\t\t%d", max);
	printf("\nThe min value is:\t\t%d", min);
	printf("\n\n");

	return 0;
}*/

/*#include <stdio.h>   // Question 13
#include <string.h>

int main(void)
{
	char first1[3][20], last1[3][20];
	char first2[3][20], last2[3][20];
	int r = 0;

	for (r = 0; r < 3; r++)
	{
		printf("Enter name %d in the order lastname firstname:\n", r + 1);
		scanf("%s %s", &first1[r], &last1[r]);
	}

	for (r = 2; r >= 0; r--)
	{
		strcpy(first2[r], first1[2-r]);
		strcpy(last2[r], last1[2-r]);
	}

	printf("Lastname, Firstname\tLastname, Firstname\n");
	printf("-------------------------------------------");

	for (r = 0; r < 3; r++)
	{
		printf("\n%s %s\t\t%s %s", first1[r], last1[r], first2[r], last2[r]);
	}
	
	printf("\n\n");
	return 0;
}*/

/*#include <stdio.h>   // Final A Q1

void large(int[], int *);

int main(void)
{
	int num[10], r, max;

	printf("Please enter ten integer numbers:\n");
	for (r = 0; r < 10; r++)
	{
		scanf("%d", &num[r]);
	}

	large(num, &max);
	printf("The largest number in the list is:\n%d\n\n", max);

	return 0;
}

void large(int num[], int *max)
{
	int r;

	for (r = 0; r < 10; r++)
	{
		if (*max < num[r])
		{
			*max = num[r];
		}
	}
}*/

#include <stdio.h>   // Final A Q3

int main(void)
{
	int r, c, array[4][4];
	FILE *input;

	input =	fopen("input.txt", "r");
	for (r = 0, r < 4; r++)
	{
		for (c = 0; c < 4; c++)
		{
			fscanf(p, "%d", &array[r][c]);
		}
	}
	fclose(input);

	for (r = 0; r < 4; r++)
	{
		for (c = 0; c < 4; c++)
		{
			printf("%d", array[r][c]);
		}
	}

	return 0;
}

/*#include <stdio.h>   // Final A Q6

int main(void)
{
	int r, c, x;

	for (r = 0; r < 5; r++)
	{
		for (c = r; c >= 0; c--)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}*/

/*#include <stdio.h>   // Final A Q7
#include <string.h>

int main(void)
{
	char first1[3][10], last1[3][10], first2[3][10], last2[3][10];
	int r;

	printf("Please enter three student names in the order lastname firstname:\n");
	for (r = 0; r < 3; r++)
	{
		scanf("%s %s", &first1[r], &last1[r]);
	}

	for (r = 2; r >= 0; r--)
	{
		strcpy(first2[r], first1[2-r]);
		strcpy(last2[r], last1[2-r]);
	}

	printf("Firstname 1, Lastname 1\t\t|\tFirstname 2, Lastname 2\n");
	printf("---------------------------------------------------------------");
	for (r = 0; r < 3; r++)
	{
		printf("\n%s, %s\t\t\t\t%s, %s", first1[r], last1[r], first2[r], last2[r]);
	}

	printf("\n");
	return 0;
}*/

/*#include <stdio.h>   // Final B Q1

void read(char[][20], int[][5]);
void find(float[], char[], int[][5], float *);
void print(char[][20], int[][5], float[], char[], float);

int main(void)
{
	char name[4][20], grade[4];
	int marks[4][5];
	float avg[4], max;

	read(name, marks);
	find(avg, grade, marks, &max);
	print(name, marks, avg, grade, max);

	return 0;
}

void read(char name[][20], int marks[][5])
{
	int r, c;

	for (r = 0; r < 4; r++)
	{
		printf("Please enter the name of student %d and their 5 test score:\n", r + 1);
		scanf("%s", &name[r]);

		for (c = 0; c < 5; c++)
		{
			scanf("%d", &marks[r][c]);
		}
		printf("\n");
	}
}

void find(float avg[], char grade[], int marks[][5], float *max)
{
	int r, c, av;

	for (r = 0; r < 4; r++)
	{
		av = 0;
		for (c = 0; c < 5; c++)
		{
			av += marks[r][c];
		}
		avg[r] = av / 5;
	}

	*max = 0;
	for (r = 0; r < 4; r++)
	{
		if (*max < avg[r])
		{
			*max = avg[r];
		}
	}

	for (r = 0; r < 4; r++)
	{
		if (avg[r] >= *max - 3)
		{
			grade[r] = 'A';
		}
		else if (avg[r] < *max - 3 && avg[r] >= *max - 5)
		{
			grade[r] = 'B';
		}
		else if (avg[r] < *max - 5 && avg[r] >= *max - 7)
		{
			grade[r] = 'C';
		}
		else if (avg[r] < *max - 7 && avg[r] >= *max - 9)
		{
			grade[r] = 'D';
		}
		else if (avg[r] < *max - 9)
		{
			grade[r] = 'F';
		}
	}
}

void print(char name[][20], int marks[][5], float avg[], char grade[], float max)
{
	int r, c;

	printf("Student Name\tAssignment Marks\tAverage\t\tGrade\n");

	for (r = 0; r < 4; r++)
	{
		printf("%s\t", name[r]);
		for (c = 0; c < 5; c++)
		{
			printf("%d  ", marks[r][c]);
		}
		printf("\t%0.1f\t%c\n", avg[r], grade[r]);
	}

	printf("\n");
}*/


