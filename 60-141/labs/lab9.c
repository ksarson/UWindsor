/*	
	SARSON, Kolby
	ID:  104232327
	Lab Exercise #9
	Date:  March 28, 2017
	Purpose:  
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student 
{
   int ID;
   char name[40];
   struct student *next;
};
typedef struct student Student;

/* Function Protoypes*/
int getChoice();					// Gets the user's desired action to perform in regards to the list
Student *addToList(Student *List);	// Will ask for a new student ID and name, dynamically create a new Student structure, assign the values for 
									// the members and add the new student structure at the END of the student list “SLIST”
void printList(Student *List);		// Will traverse through the list and will print info for each student in the format “ID Name\n”
void printListRR(Student *List);	// Will traverse through the list from the END and will print info for each student, RECURSIVELY, in the format “ID Name\n”
void searchList(Student *List);		// Will ask the user for a student’s ID, search for the ID ,then print the data in the format “ID Name\n”. If failed, “ID "ID" not found" is printed

/* Main Function */
int main() 
{
    int choice = 0;
    Student *SLIST = NULL;

    choice = getChoice();

    while(choice >= 0) 
    {
        switch(choice) 
        {
            case 0 : printf("Bye...\n"); 
            		 exit(0);
            case 1 : SLIST = addToList(SLIST); 
            		 break;
            case 2 : printList(SLIST); 
            		 break;
            case 3 : printListRR(SLIST);
            		 break;
            case 4 : searchList(SLIST);
            		 break;
            default: printf("That is not a valid choice\n");
        }
        choice = getChoice();
    }

    if(SLIST)  
    	free(SLIST);
    return 0;
}

/* Get Choice
Purpose:	Gets the user's desired action in regards to the list
Input:		None
Output:		A list of options, returning a value corresponding to a choice*/
int getChoice() 
{
    int choice = 0;

    printf("\n****** MENU ******\n");
    printf("1. Add new student to list.\n");
    printf("2. Print the student list, beginning to end.\n");
    printf("3. Recursively print the student list from the end.\n");
    printf("4. Search the list for a student.\n");
    printf("0. Quit.\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    return choice;
}

/* Add to List
Purpose:	Will ask for a new student ID and name, dynamically create a new Student structure, assign the values for 
			the members and add the new student structure at the END of the student list “SLIST”
Input:		The current list
Output:		The modified list*/
Student *addToList(Student *List)
{
	Student *aStudent = (Student *)malloc(sizeof(Student));

    printf("Enter student's ID: ");
    scanf("%d", &(aStudent->ID));
    printf("Enter student's name: ");
    scanf(" %[^\n]", aStudent->name);

    if (List == NULL) 
    	return aStudent;

    Student *pStudent = List;

    while(pStudent->next != NULL)
        pStudent = pStudent->next;

    pStudent->next = aStudent;

    return List;
}

/* Print List
Purpose:	Will traverse through the list from the START and will print info for each student in the format “ID Name\n”
Input:		The current list
Output:		The list*/
void printList(Student *List)
{
	while (List != NULL) 
	{
        printf("%d %s\n", List->ID, List->name);
        List = List->next;
    } 
}

/* Print List Reverse Recursive
Purpose:	Will traverse through the list from the END and will print info for each student, RECURSIVELY, in the format “ID Name\n”
Input:		The current list
Output:		The reversed list*/
void printListRR(Student *List)
{
	if(List == NULL) return;
    	printListRR(List->next);
    printf("%d %s\n", List->ID, List->name);
}

/* Search List
Purpose:	Will ask the user for a student’s ID, search for the ID ,then print the data in the format “ID Name\n”. If failed, “ID "ID" not found" is printed
Input:		The current list
Output:		The ID and the student's name with the corresponding ID, or ID 'ID' not found if not in list*/
void searchList(Student *List)
{
	int sid;
    printf("Enter student's ID: ");
    scanf("%d", &sid);

    while(List != NULL) 
    {
        if(List->ID == sid)
        {
            printf("%d %s\n", List->ID, List->name);
            return;
        }
        List = List->next;
    }
    printf("ID %d not found", sid);
}
