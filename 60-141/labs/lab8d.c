/*	
	SARSON, Kolby
	ID:  104232327
	Lab Exercise #8 d
	Date:  March 28, 2017
	Purpose:  Direct Access Files
*/

#include <stdio.h>

struct employee {
	char firstName[40];
	char lastName[40];
	int id;
	int GPA;
};

typedef struct employee Employee;

void InputEmpRecord(Employee *EmpList);								// User inputs each employee data
void PrintEmpList(const Employee *EmpList);							// Prints the employee's information
void SortEmpList(const Employee *EmpList, const char *FileName);	// Sorts the employee information
int main() 
{
	Employee EmpList[4];
	InputEmpRecord(EmpList);
	PrintEmpList(EmpList);
	SortEmpList(EmpList, "employee.dat");

	return 0;
}

/*	Add Employees
Purpose:	User inputs each employee data
Input:		The EmpList and the users inputs to it
Output:		Outputs nothing as it is a void function, only prints data asking for info */
void InputEmpRecord(Employee *EmpList)
{
    FILE *p = fopen ("employee.dat", "rb");

    fread (EmpList, sizeof (struct employee), 4, p);
	fclose (p);
}

/*	Print Employee List
Objective:	Prints the employee's information
Input:		The employee list
Output:		Outputs nothing as it is a void function, but prints the information in the function */
void PrintEmpList(const Employee *EmpList)
{
    int i;

    printf("\nID\tFirst Name\tLast Name\tGPA\n\n");
    for(i=0; i < 4; i++)
    {
        printf("%d\t%s\t\t%s\t\t%d\n", EmpList[i].id, EmpList[i].firstName, EmpList[i].lastName, EmpList[i].GPA);
    }
}

void SortEmpList(const Employee *EmpList, const char *FileName)
{
	int i, j, tempID, tempGPA;
	char tempF, tempL;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4 - i - 1; j++)
		{
			tempID = EmpList[i].ID;
		}
	}
}

