/*	
	SARSON, Kolby
	ID:  104232327
	Lab Exercise #8 a
	Date:  March 28, 2017
	Purpose:  Sequential Files
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee
{
    char firstName[40];
    char lastName[40];
    int id;
	int GPA;
};
typedef struct employee Employee;

void InputEmpRecord (Employee *EmpList);					// User inputs each employee data
void PrintEmpList (const Employee *EmpList);				// Prints the employee's information
void SaveEmpList (const Employee *EmpList, FILE *EmpFile);	// Saves the employee information to the text file

int main() {
	
	FILE *EmpFile;
	EmpFile = fopen ("employee.dat", "wb");
	
    Employee EmpList[4];
    InputEmpRecord (EmpList);
    PrintEmpList (EmpList);
    SaveEmpList (EmpList, EmpFile);
	fclose (EmpFile);

    return 0;
}

/*  Add Employees
Purpose:	User inputs each employee data
Input: 		The EmpList and the users inputs to it
Output:		Outputs nothing as it is a void function, only prints data asking for info */
void InputEmpRecord (Employee *EmpList)
{
    int i;
	
    for (i = 0; i < 4; i++)
    {
        printf ("\nEnter data for employee:\n", i+1);
        printf ("ID: ");
        scanf ("%d", &EmpList[i].id);
		
        printf ("Employee's First Name: ");
        scanf ("%s", EmpList[i].firstName);
		
        printf ("Employee's Last Name: ");
        scanf ("%s", EmpList[i].lastName);
		
		printf ("Employee's GPA: ");
        scanf ("%d", &EmpList[i].GPA);
		
    }
}

/*  Print Employee List
Purpose:	Prints the employee's information
Input: 		The employee list
Output: 	Outputs nothing as it is a void function, but prints the information in the function */
void PrintEmpList (const Employee *EmpList)
{
    int i;

    printf ("ID\tFirst Name\tLast Name\tGPA\n\n");
    for (i = 0; i < 4; i++)
    {
        printf ("%d\t%s\t\t%s\t\t%d\n", EmpList[i].id, EmpList[i].firstName, EmpList[i].lastName, EmpList[i].GPA);
    }
}

/*  Save Employee List
Purpose:	Saves the employee information to the text file
Input:		The employee list and the file name (employee.dat)
Output:		Outputs nothing as it is a void function, rather prints the information to the file */
void SaveEmpList (const Employee *EmpList, FILE *EmpFile)
{
    int i;
	
    for (i = 0 ; i < 4; i++)
    {
        fprintf(EmpFile, " %d %s %s %d\n", EmpList[i].id, EmpList[i].firstName, EmpList[i].lastName, EmpList[i].GPA); // Writing to the sequential file
    }
}
	