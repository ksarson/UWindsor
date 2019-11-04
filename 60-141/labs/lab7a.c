/*	
	SARSON, Kolby
	ID:  104232327
	Lab Exercise #7
	Date:  March 14, 2017
	Purpose:  To learn to use and manipulate strings and arrays of characters
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Prototypes */
int AtoI (const char *str);								// Converts a string to an integer
int strcmp (const char *str1, const char *str2);		// Compares two strings
char *StrCpy (char *destination, const char *source);	// Copies a string into another location
char *StrCat (char *destination, const char *source);	// Appends one string to the end of another string
char *StrChr (char *str, int ch)		;				// Finds the first occurence of a character

/* Main Function */
void main()
{
	char buffer1[80] = {'t','h','i','s',' ','i','s',' ','t','h','e',' ','f','i','r','s','t',' ','b','u','f','f','e','r','\0'};
	char buffer2[80] = {'t','h','i','s',' ','i','s',' ','t','h','e',' ','s','e','c','o','n','d',' ','b','u','f','f','e','r','\0'};
	char num[10] = {'7','4','1','9','2','\0'};
	char cpy[80] = {'\0'};
	char cat[80] = {'h','e','l','l','o',' ','\0'};
	int comp;

	printf ("%d\n", AtoI (num));
	comp = strcmp (buffer1, buffer2);
	if (comp < 0)
		printf ("Buffer 1 is less than buffer 2\n");
	else if (comp > 0)
		printf ("Buffer 1 is greater than buffer 2\n");
	else 
		printf ("Buffer 1 is equal to buffer 2\n");
	printf ("%s\n", StrCpy (cpy, buffer1));
	printf ("%s\n", StrCat (cat, buffer2));
	if (StrChr (buffer1, 'z') == NULL)
		printf ("NULL\n");
	else
		printf ("%s\n", StrChr (buffer1, 'z'));
}

/* String to Integer 
Purpose:	Converts a string to an integer
Input:		A 1D char array
Output:		Retrurns the integer value of the string */
int AtoI (const char * str)
{
	int res = 0, i; 
  
    for (i = 0; str[i] != '\0'; ++i)
        res = res*10 + str[i] - '0';

    return res;
}

/* String Compare 
Purpose:	Compares two strings
Input:		Two string pointers
Output:		Retrurns an integer value indicating which string is greater */
int strcmp (const char *str1, const char *str2)
{
    if (*str1 < *str2)
        return -1;
 
    if (*str1 > *str2)
        return 1;
 
    if (*str1 == '\0' && *str2 == '\0')
        return 0;

    if (*str1 == '\0' && *str2 != '\0')
        return 1;

    if (*str1 != '\0' && *str2 == '\0')
        return -1;
 
    return strcmp(str1+1, str2+1);
}

/* String Copy 
Purpose:	Copies a string into another location
Input:		Two string pointers
Output:		Retrurns copied string */
char *StrCpy (char *destination, const char *source)
{
	char *strresult = destination;
	    while (*source != '\0')
 	    	*destination++ = *source++;
 	    destination = '\0';
 	return strresult;
}

/* String Concatenate 
Purpose:	Appends one string to the end of another string
Input:		Two string pointers
Output:		Retrurns the new string */
char *StrCat (char *destination, const char *source)
{
	char *strreturned = destination;
 		if(('\0' != *destination) && ('\0' != *source))
 		{
 	    	while('\0' != *destination)
 	    	{
		 	    destination++;
	 	    }
 		    while('\0' != *source)
 	    	{
 	   			*destination++ = *source++;
	 	    }
 	    destination = '\0';
 		}
 	return strreturned;
}

/* String Character Occurence 
Purpose:	Finds the first occurence of a character
Input:		A string pointer and a character
Output:		Retrurns the string from the found character to the end of the string, or NULL if not found */
char *StrChr (char *str, int ch)
{
	int i = 0;

	while (str[i] != (char)ch && str[i] != '\0')
		i++;

	if (str[i] == (char)ch) 
		return str+i;

	return NULL;
}