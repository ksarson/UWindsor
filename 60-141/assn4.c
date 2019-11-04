/*	
	Sarson, Kolby
	ID:  104232327

	Assignment #4
	Due Date:  March 25, 2017

	"I acknowledge that this is my own work and did not receive any 
	unauthorized help with it."
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define strL 50

/*
Content of a sample input:
programming,03,60,141,01,W,2015
programming,03,60,141,30,W,2015
Algebra,03,62,102,02,S,2013
Religion,08,98,938, 20,F,2014
*/

/* Structures */
struct CourseInfo
{
	int courseID;
	char courseName[50];
	char courseCode[12];
	char Term [6];
};

/* Function Prototypes */
void loadCourseInfo (struct CourseInfo courselist[strL], int linesN);		//  To read all data from input file and format and store them in an array of structures
void displayCourseInfo (struct CourseInfo courselist[strL], int linesN);	//  To print a table indicating the course information
void addCourseInfo (struct CourseInfo courselist[strL], int linesN);		//  To add a new course
void searchCourseInfo (struct CourseInfo courselist[strL], int linesN);		//  To search for a course information using courseID or course Name and print the course information if it exists


/* Main Function */
void main()
{
	struct CourseInfo courselist[strL];
    int linesN, i, j, add = 1, search = 1;

    printf ("Enter the number of courses you wish to input:\n");
	scanf ("%d", &linesN);
	while (getchar () != '\n');

	loadCourseInfo (courselist, linesN);
	displayCourseInfo (courselist, linesN);

	while (add == 1)
	{
		printf ("Would you like to add a course? (Type 1 for yes or 2 for no)\n");
		scanf ("%d", &add);
		if (add == 1)	//  Calls add function and adjusts # of lines based on whether course was added
		{
			addCourseInfo(courselist, linesN);
			for (i = 0; i < linesN; i++)
				if (courselist[linesN].courseID == 0)
						linesN -= 1;
			linesN += 1;
		}
	}

	displayCourseInfo (courselist, linesN);
	while (search == 1)		//  Calls search function 
	{
		printf ("Would you like to search for a course? (Type 1 for yes or 2 for no)\n");
		scanf ("%d", &search);
		if (search == 1)
			searchCourseInfo(courselist, linesN);
	}
}

/* Load Course Info 
Purpose:	To read all input and format and store them in a structure
Input:		Structure of course info and number of lines
Output:		No output*/
void loadCourseInfo (struct CourseInfo courselist[strL], int linesN)
{
	int i, j;
	char inputstring[strL][strL];
	char *token;

	printf ("Enter the course info:\n");
	for (i = 0; i < linesN; i++)	
		fgets (inputstring[i], strL, stdin);

	for (i = 0; i < linesN; i++)
		for(j = 0; j < strL; j++)
			inputstring[i][j] = toupper (inputstring[i][j]);	//  Converts input strings to uppercase

	for (i = 0; i < linesN; i++)
	{
		courselist[i].courseID = i + 1;		//  Sets course's ID
	    token = strtok(inputstring[i],", ");
	    strcpy (courselist[i].courseName, token);	//  Sets course's Name
		token = strtok(NULL, ", ");
	    
	    for (j = 0; j < 4; j++)		//  Sets course code formatted with hyphens
	    {
	    	strcat (courselist[i].courseCode, token);
		 	if (j > 0 && j < 3)
	  		{
	    		strcat (courselist[i].courseCode, "-");
	    	}
	    	token = strtok(NULL, ", ");
	    }

	    while (token != NULL)	//  Sets course's Term
	    {
	   		strcat (courselist[i].Term, token);
	    	token = strtok(NULL, ", ");
		}
	}
}

/* Display Course Info 
Purpose:	To print a table indicating the course information
Input:		Structure of course info and number of lines
Output:		Displays all courses in the structure with info in tabular format*/
void displayCourseInfo (struct CourseInfo courselist[strL], int linesN)
{
	int i;
	printf ("CourseID -  CourseName  -  CourseCode  - Term\n");

	for (i = 0; i < linesN; i++)
	{
    	printf ("%4d\t - %12s - %12s - %5s", courselist[i].courseID, courselist[i].courseName, courselist[i].courseCode, courselist[i].Term);
	}
}

/* Add Course Info 
Purpose:	To add a new course
Input:		Structure of course info and number of lines
Output:		No output*/
void addCourseInfo (struct CourseInfo courselist[strL], int linesN)
{
	int i, j, k, check = 0;
	char inputstring[strL][strL], temp[strL][strL];
	char *token;

	printf ("Enter the course info:\n");
	for (i = linesN; i < linesN + 1; i++)
	{
		while (getchar () != '\n');	
		fgets (inputstring[i], strL, stdin);
	}

	for (i = linesN; i < linesN + 1; i++)	//  Copies input to temp as uppercase and makes input uppercase
		for(j = 0; j < strL; j++)
		{
			temp[i][j] = toupper (inputstring[i][j]);
			inputstring[i][j] = toupper (inputstring[i][j]);
		}

	for (i = linesN; i < linesN + 1; i++)	//  Removes the comma between the first two parts of the course code
	{
		for (j = 0; j < 1; j++)
		{
			while (isalpha (inputstring[i][j]))
				j++;
			k = j + 3;
			for (j = k; j < strL; j++)
				temp [i][j] = inputstring[i][j+1];
		}
	}

	for (i = linesN; i < linesN + 1; i++)	//  Changes commas in temp array to hyphens
		for (j = 0; j < strL; j++)
			if (temp[i][j] == ',')
				temp[i][j] = '-';

	for (i = 0; i < linesN; i++)	//  Checks if course code is previously found
		if (strstr (temp[linesN], courselist[i].courseCode) != NULL)
		{
			check = 1;
			break;
		}

	if (check != 1)		//  If course code is new
	{
		for (i = linesN; i < linesN + 1; i++)
		{
			courselist[i].courseID = i + 1;		//  Sets course's ID
		    token = strtok(inputstring[i],", ");
		    strcpy (courselist[i].courseName, token);	// Sets course's Name
			token = strtok(NULL, ", ");
		    
		    for (j = 0; j < 4; j++)		//  Sets course code formatted with hyphens
		    {
		    	strcat (courselist[i].courseCode, token);
			 	if (j > 0 && j < 3)
		  		{
		    		strcat (courselist[i].courseCode, "-");
		    	}
		    	token = strtok(NULL, ", ");
		    }

		    while (token != NULL)	//  Sets course's term
		    {
		   		strcat (courselist[i].Term, token);
		    	token = strtok(NULL, ", ");
			}
			break;
		}
	}
	else
		printf ("Previously listed course code\n");
}

/* Search Course Info 
Purpose:	To search for a course information using courseID or course Name and print the course information if it exists
Input:		Structure of course info and number of lines
Output:		Outputs the course info if found otherwise a not found message */
void searchCourseInfo (struct CourseInfo courselist[strL], int linesN)
{
	int i;
	char searched[strL];

	printf ("Enter the courseID or course name to search for:\n");
	scanf ("%s", &searched);

	for (i = 0; i < strlen (searched); i++)
		searched[i] = toupper (searched[i]);	//  Converts input to uppercase

	for (i = 0; i < linesN; i++)
	{
		if (strcmp (courselist[i].courseName, searched) == 0 || courselist[i].courseID == atoi (searched))	//  Searches for input in both course names and ID
		{
			printf ("CourseID -  CourseName  -  CourseCode  - Term\n");
			printf ("%4d\t - %12s - %12s - %5s", courselist[i].courseID, courselist[i].courseName, courselist[i].courseCode, courselist[i].Term);
			break;
		}
	}
	if (i == linesN)
		printf ("The searched course does not exist\n");
}