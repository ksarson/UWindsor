/*	
	Sarson, Kolby
	ID:  104232327

	Assignment #6
	Due Date:  April 12, 2017

	"I acknowledge that this is my own work and did not receive any 
	unauthorized help with it."
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Students
{
	int ID;
	float marks[10];
	float GPA;
}
typedef struct Students stud;

void main()
{
	int inB, outB, i, j;
	float total = 0, gpa;
	FILE *fp;
	char line[100];
	char *tok;

	fp = fopen ("assn6.dat", "r");

	while (fscanf (fp, "%s\n", line) != EOF)
	{
		tok = strtok(line, " ");
		stud.ID = atof (tok);
		tok = strtok (NULL, " ");
		for (i = 0; i < 10; i++)
		{
			total += atof (tok);
			stud.marks = atof (tok);
			tok = strtok (NULL, " ");
		}
		gpa = total / 10;
		stud.GPA = gpa;
	}
}