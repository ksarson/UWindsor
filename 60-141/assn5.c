/*	
	Sarson, Kolby
	ID:  104232327

	Assignment #5
	Due Date:  March 29, 2017

	"I acknowledge that this is my own work and did not receive any 
	unauthorized help with it."
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct CourseInfo
{
	int courseID;
	char courseName[30];
};
typedef struct CourseInfo CInfo;

struct studentInfo
{
	char StudentID[10];
	char FirstName[20];
	char LastName[25];
	int numCourses;
	CInfo cinfo[10];
	struct studentInfo *link;
};
typedef struct studentInfo SInfo;
SInfo *head = NULL;

int loadStudentInfo (FILE *input, int, int*);	// To add a new student and his/her registered courses. 
void displayStudentInfo ();						// To display the current student information that exists in the linked list
int searchStudentID (char[]);					// To search for a student using studentID
void searchStudentName (char[]);				// To search for a student using his/her last name and display the related
												// information if the student exists
int addStudent ();								// To read all the student information from an input file
int deleteStudent (char[]);						// To delete a student information using its StudentID
void saveStudentInfo (FILE *input2);			// To save student information from the sorted linked list to a file

void main ()
{
	int done = 0, choice, i = 0, stop = 0;
	int*stopPtr;
	stopPtr = &stop;
	char name[256], inputID[256];
	FILE *input;
	input = fopen ("studentList.txt", "r");

	while (!stop)
		i = loadStudentInfo (input, i, &stop);	// Loads info until file is empty
	
	while (done != 1)
	{
		printf ("\n1.Add new student\n2.Delete a student\n3.Search for a student\n4.Display current students\n5.Save student information to file\n6.Exit\n");
		printf ("Please enter a selection: ");
		scanf ("%d", &choice);
		switch (choice)
		{
			case 1: 
				printf ("--Adding new student--\n");
				addStudent ();
				break;
			case 2:
				printf ("Enter a student ID to remove: ");
				scanf ("%s", inputID);
				deleteStudent (inputID);
				break;
			case 3: 
				printf ("Enter a student last name: ");
				scanf ("%s", name);
				searchStudentName (name); 
				break;
			case 4: 
				displayStudentInfo (); 
				break;
			case 5:
				fclose (input);
				FILE *input2;
				input2 = fopen ("studentList.txt", "wb");
				saveStudentInfo (input2);
				fclose (input2);
				FILE *input = fopen ("studentList.txt", "r");
				break;
			case 6: 
				input2 = fopen ("studentList.txt", "wb");
				saveStudentInfo (input2);
				fclose (input2);
				done = 1;
				break;
			default: 
				printf ("That is not a valid option");
				break;
		}
	}
	fclose (input);
}

/* Load student Info
Purpose:	To add a new student and his/her registered courses
Input:		An input file, the number of the input and a pointer to stop the function
Output:		Loadds the information into the linnked list*/
int loadStudentInfo (FILE* input, int i, int*stopPtr)
{
	int j, k, repeat = 1, numCourse, num, inputIDasNum, numID, check;
	char inputLine[256];
	SInfo* temp = (SInfo*) malloc (sizeof (SInfo));
	for(; repeat; i++)
	{
		fscanf (input, "%s", inputLine);	// Student ID
		if (!strcmp (inputLine, "***"))		// End of inputs
		{
			repeat = 0;
			*stopPtr = 1;
			break;
		}

		strcpy (temp->StudentID, inputLine);
		strcpy (inputLine, "");

		fscanf (input, "%s", inputLine);		// Student's First Name
		strcpy (temp->FirstName, inputLine);
		strcpy (inputLine, "");

		fscanf (input, "%s", inputLine);		// Student's Last Name
		strcpy (temp->LastName, inputLine);
		strcpy (inputLine, "");

		fscanf (input, "%s", inputLine);		// Number of Student Courses
		numCourse = atoi (inputLine);
		temp->numCourses = numCourse;
		strcpy (inputLine, "");
		
		for (j = 0; j < (temp->numCourses); j++)
		{
			fscanf (input, "%s", inputLine);				// Course name
			strcpy (temp->cinfo[j].courseName, inputLine);
			strcpy (inputLine, "");
			fscanf (input, "%s", inputLine);	//Course ID
			num = atoi (inputLine);
			temp->cinfo[j].courseID = num;
			strcpy (inputLine, "");
		}

		temp->link = NULL;
		int k = 0;

		if (i==0)
		{
			head = temp;
			temp = (SInfo*) malloc (sizeof (SInfo));
		}

		else if (i==1)
		{
			SInfo *next;
			next = head;
			inputIDasNum = atoi (temp -> StudentID);
			numID = atoi (next->StudentID);
			if (numID  > inputIDasNum)
			{
				temp->link = head;
				head = temp;
			}
			else
				next->link = temp;
			temp = (SInfo*) malloc (sizeof (SInfo));
		}
		
		else	// Sorting
		{
			temp->link = NULL;
			SInfo *next,*prev,*first;
			next = head;
			prev = NULL;
			k=0, check=0;
			inputIDasNum = atoi (temp->StudentID);
			while (next->link != NULL)
			{
				numID = atoi (next->StudentID);
				if (numID > inputIDasNum)
				{
					if (k==0)
					{
						temp->link = head;
						head = temp;
					}
					else
					{
						prev->link = temp;
						temp->link = next;
					}
					return i;
				}
				else
				{
					prev = next;
					next = next->link;
					k++;
				}
			}

			numID = atoi (next->StudentID);

			if (numID > inputIDasNum)
			{
				prev->link = temp;
				temp->link = next;
			}

			else
			{
				next->link = temp;
				temp->link = NULL;
			}
			
			temp = (SInfo*) malloc (sizeof (SInfo));
		}
	}
}

/* Display Student ID
Purpose:	To display the current student information that exists in the linked list
Input:		No Input
Output:		Prints the contents of the linked list*/
void displayStudentInfo ()
{
	int i = 0;
	SInfo*temp1 = head;

	while (temp1->link != NULL)
	{
		printf ("%s\n%s\n%s\n%d\n", temp1->StudentID, temp1->FirstName, temp1->LastName, temp1->numCourses);
		for (i = 0; i < temp1->numCourses; i++)
			printf ("%s %d\n", temp1->cinfo[i].courseName, temp1->cinfo[i].courseID);
		temp1 = temp1->link;
	}

	printf ("%s\n%s\n%s\n%d\n", temp1->StudentID, temp1->FirstName, temp1->LastName, temp1->numCourses);

	for (i = 0; i < temp1->numCourses; i++)
		printf ("%s %d\n", temp1->cinfo[i].courseName, temp1->cinfo[i].courseID);
	
}

/* Search Student ID
Purpose:	To search for a student using studentID
Input:		Array of IDs
Output:		Retruns 1 if found and 0 otherwise*/
int searchStudentID (char searchID[256])
{
	int intSearchID = atoi (searchID);
	int intStudentID;
	SInfo*temp1 = head;

	while (temp1->link != NULL)
	{
		intStudentID = atoi (temp1->StudentID);
		if (intStudentID == intSearchID)
			return 1;
		temp1 = temp1->link;
	}

	if (intStudentID == intSearchID)
			return 1;

	return 0;
}

/* Search Student Name
Purpose:	To search for a student using his/her last name and display the related
			information if the student exists
Input:		Character array for a name
Output:		Prints the information for the student if student name is found*/
void searchStudentName (char name[256])
{
	int i;
	SInfo*temp1 = head;

	if (name[0] != toupper (name[0]))
		name[0] = toupper (name[0]);
	
	while(temp1->link != NULL)
	{
		if (!strcmp (name, temp1->LastName))
		{
			printf ("%s\n%s\n%s\n%d\n", temp1->StudentID, temp1->FirstName, temp1->LastName, temp1->numCourses);
			for (i = 0; i< temp1->numCourses; i++)
				printf("%s %d\n", temp1->cinfo[i].courseName, temp1->cinfo[i].courseID);
		}
		temp1 = temp1->link;
	}

	if (!strcmp (name, temp1->LastName))
	{
		printf ("%s\n%s\n%s\n%d\n", temp1->StudentID, temp1->FirstName, temp1->LastName, temp1->numCourses);
		for (i = 0; i < temp1->numCourses; i++)
			printf ("%s %d\n", temp1->cinfo[i].courseName, temp1->cinfo[i].courseID);
	}
}

/* Add Student
Purpose:	To read all the student information from an input file
Input:		No Input
Output:		No output, adds the student's information to the linked list*/
int addStudent ()
{
	int i, intID, intStructID;
	char name[256], id[10];
	SInfo* temp = (SInfo*) malloc (sizeof (SInfo));
	
	/* Taking All Student Info */
	printf ("Student ID: ");
	scanf ("%s", id);
	if (searchStudentID (id))
	{
		printf ("Student ID must be unique.");
		return 0;
	}
	strcpy (temp->StudentID, id);
	
	printf ("First Name: ");
	scanf ("%s", name);
	name[0] = toupper (name[0]);
	strcpy (temp->FirstName, name);
	strcpy (name, "");
	
	printf ("Last Name: ");
	scanf ("%s", name);
	name[0] = toupper (name[0]);
	strcpy (temp->LastName, name);
	strcpy (name, "");
	
	printf ("Number of courses: ");
	scanf ("%d", &temp->numCourses);
	
	for (i = 0; i < temp->numCourses; i++)	// Loops for number of courses being added 
	{
		printf ("Course ID: ");
		scanf ("%d", &temp->cinfo[i].courseID);
		printf ("Course Name: ");
		scanf ("%s", temp->cinfo[i].courseName);
	}

	temp->link = NULL;
	intID = atoi (temp->StudentID);
	SInfo *next, *prev;
	next = head;
	prev = NULL;
	i = 0;
	
	while (next->link != NULL)		// Loops through linked list
	{
		intStructID = atoi (next->StudentID);
		if (intStructID > intID)
		{
			if (i == 0)
			{
				temp->link = head;
				head = temp;
				return 0;
			}
			else
			{
				prev->link = temp;
				temp->link = next;
				return 0;
			}
		}
		else
		{
			prev = next;
			next = next->link;
		}
		i++;
	}
	intStructID = atoi (next->StudentID);
	if (intStructID > intID)
	{
		prev->link = temp;
		temp->link = next;
		return 0;
	}

	else if (intStructID < intID)
	{
		next->link = temp;
		return 0;
	}
	
	return 0;
}

/* Delete Student
Purpose:	To delete a student information using its StudentID
Input:		Takes a character array for student ID
Output:		Deletes and reroutes around the deleted student information container*/
int deleteStudent (char inputID[256])
{
	int intEnterID = atoi (inputID), i=0, intStudentID;
	SInfo*next, *prev;
	next = head;
	prev = NULL;
	
	while (next->link != NULL)	// Loops through the linked list
	{
		intStudentID = atoi (next->StudentID);
		if (intStudentID == intEnterID)
		{
			if (i == 0)
			{
				head = next->link;
				return 0;
			}
			else
			{
				prev->link = next->link;
				free(next);
				return 0;
			}
		}
		prev = next;
		next = next->link;
		i++;
	}

	intStudentID = atoi (next->StudentID);

	if (intStudentID == intEnterID)
	{
		prev->link = NULL;
		free (next);
	}
	
}

/* Save Student Info
Purpose:	To save student information from the sorted linked list to a file
Input:		An input file
Output:		Saves the entire linked list to a file*/
void saveStudentInfo(FILE *input2)
{
	int i;
	SInfo *temp = head;

	while (temp->link != NULL)
	{
		fprintf (input2, "%s\n%s\n%s\n%d\n", temp->StudentID, temp->FirstName, temp->LastName, temp->numCourses);
		for (i = 0;i< temp->numCourses;i++)
			fprintf (input2, "%s %d\n", temp->cinfo[i].courseName, temp->cinfo[i].courseID);
		temp = temp->link;
	}

	fprintf (input2, "%s\n%s\n%s\n%d\n", temp->StudentID, temp->FirstName, temp->LastName, temp->numCourses);

	for (i = 0; i < temp->numCourses; i++)
		fprintf (input2, "%s %d\n", temp->cinfo[i].courseName, temp->cinfo[i].courseID);

	fprintf (input2, "***");
}



