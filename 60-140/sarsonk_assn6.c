/* CONFIDENTIALITY AGREEMENT & STATEMENT OF HONESTY
   I confirm that I will keep the content of this assignment/examination
   confidential.  I confirm that I have not recieved any unauthorized
   assistnace in preparing for or doing this assignment/examination.
   I confirm knowing that a mark of 0 may be assigned for copied work.
   Name:  Kolby Sarson
   Student Number:  104232327
   Lecture Section:  01
   Lab Section:  52
   Date:  Nov. 12, 2015 */

// Comments for Tracing
   
#include <stdio.h>

void init(int[20], int);
void readD(char name[][10], int[][20], int[20], int, int);
void findGr(int[][20], int[20], int[], char[], int, int, int *);
void printAll(int[][20], int[], int[], char[][10], char[], int, int, int);


int main(void)
{
	const int numrow = 4, numcol = 20;
	int stuAns[numrow][numcol], ansKey[20], numCrrt[numrow], r, c;
	char name[numrow][10], letterGr[numrow];
	int max = 0;

	init(numCrrt, numcol);
	readD(name, stuAns, ansKey, numrow, numcol);
	findGr(stuAns, ansKey, numCrrt, letterGr, numrow, numcol, &max);
	printAll(stuAns, ansKey, numCrrt, name, letterGr, numrow, numcol, max);

	return 0;
}

void init(int numCrrt[], int numcol)
{
	int c;

		for (c = 0; c < numcol; c++)
		{
		numCrrt[c] = 0;
		}
}

void readD(char name[][10], int stuAns[][20], int ansKey[20], int numrow, int numcol)
{
	int r, c;

	for (r = 0; r < numrow; r++)
	{
		printf("Type student name and hit enter\n");
		scanf("%s", &name[r]);
		printf("Type student's answers in order\n");

		for (c = 0; c < numcol; c++)
		{
			scanf("%d", &stuAns[r][c]);
		}
	}
	for (r = 0; r < 1; r++)
	{
		printf("Type the teacher's answerkey in order\n");
	
		for (c = 0; c < numcol; c++)
		{
			scanf("%d", &ansKey[c]);
		}
	}
}

void findGr(int stuAns[][20], int ansKey[20], int numCrrt[], char letterGr[], int numrow, int numcol, int *max)
{
	int r, c;
	int correct = 0;

	for (r = 0; r < numrow; r++)
	{
		correct = 0;

		for (c = 0; c < numcol; c++)
		{
			if (stuAns[r][c] == ansKey[c])
			{
				correct += 1;
			}
		}

		numCrrt[r] = correct;

		if (*max < numCrrt[r])
		{
			*max = numCrrt[r];
		}
	}
	
	for (r = 0; r < numrow; r++)
	{
		if (*max - 3 <= numCrrt[r] && numCrrt[r] <= *max)
		{
			letterGr[r] = 'A';
		}
		else if (*max - 5 <= numCrrt[r] && numCrrt[r] <= *max - 4)
		{
			letterGr[r] = 'B';	
		}
		else if (*max - 7 <= numCrrt[r] && numCrrt[r] <= *max - 6)
		{
			letterGr[r] = 'C';
		}
		else if (*max - 9 <= numCrrt[r] && numCrrt[r] <= *max - 8)
		{
			letterGr[r] = 'D';
		}
		else 
		{
			letterGr[r] = 'F';
		}
	}

}

void printAll(int stuAns[][20], int ansKey[20], int numCrrt[], char name[][10], char letterGr[], int numrow, int numcol, int max)	
{
	int r, c;

	printf("\n");
	printf("Name\t\tStudent Answers\t\t\t\t\tAnswers-Correct\t\tGrade\n");

	for (r = 0; r < numrow; r++)
	{
		printf("%s\t\t", name[r]);
		for (c = 0; c < numcol; c++)
		{
			printf("%d ", stuAns[r][c]);
		}
		printf("\t\t%d ", numCrrt[r]);
		printf("\t\t%c ", letterGr[r]);
		printf("\n\n");
	}	
	printf("\t\tAnswer Key\t\t\tHighest Score\n");
	for (c = 0; c < numcol; c++)
	{	
		printf("%d ", ansKey[c]);
	}
	printf("\t\t%d", max);
	printf("\n\n");
}