/*	
	SARSON, Kolby
	ID:  104232327
	Lab Exercise #8 b
	Date:  March 28, 2017
	Purpose:  Sequential Files
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct employee{
    char firstName[40];
    char lastName[40];
    int id;
	int GPA;
};
typedef struct employee Employee;

char CapWord (char *word);											// To convert the first letter of a word to a capital letter
void PrintEmpList (const Employee *EmpList);						// Prints the employees info
void SaveEmpList (const Employee *EmpList, const char *FileName);	// Saves the employee info to the text file

int main()
{
	int i;
	FILE *input;
	input = fopen ("employee.dat", "r");
	Employee EmpList[4];
	
    for (i = 0; i < 4; i++)
    {
		fscanf (input, "%d %s %s %d", &EmpList[i].id, EmpList[i].firstName, EmpList[i].lastName, &EmpList[i].GPA);
		CapWord (EmpList[i].firstName);
		CapWord (EmpList[i].lastName);
	}

	PrintEmpList (EmpList);
	fclose (input);
    SaveEmpList (EmpList, "employee.dat");
	
    return 0;
}

/*	Capitalize Word
Purpose:	To convert the first letter of a word to a capital letter
Input:		The word
Output:		The capitalized word */
char CapWord (char *word)
{
	word[0] = toupper (word[0]);
}

/*	Save Employee List
Purpose:	Saves the employee info to the text file
Input:		The employee list and the file to save it to
Output: 	Nothing as it is a void function, rather prints the updated info in the function */
void SaveEmpList (const Employee *EmpList, const char *FileName)
{
	int i;
	FILE *fps;
	fps = fopen ("employee.dat", "wb");
	
    for (i = 0 ; i < 4; i++)
    {
        fprintf (fps, "%d %s %s %d\n", EmpList[i].id, EmpList[i].firstName, EmpList[i].lastName, EmpList[i].GPA);	// Writing to the sequential file
    }
	fclose (fps);
}

/*	Print Employee List
Purpose:	Prints the employees info
Input:		The employee list information
Output: 	othing as it is a void function, rather prints the employees info inside of the function */
void PrintEmpList (const Employee *EmpList)
{
    int i;

    printf ("ID\tFirst Name\tLast Name\tGPA\n\n");
    for (i = 0; i < 4; i++)
    {
        printf ("%d\t%s\t\t%s\t\t%d\n", EmpList[i].id, EmpList[i].firstName, EmpList[i].lastName, EmpList[i].GPA);
    }
}
