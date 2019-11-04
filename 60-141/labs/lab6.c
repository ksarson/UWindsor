/*	
	SARSON, Kolby
	ID:  104232327
	Lab Exercise #6
	Date:  March 7, 2017
	Purpose:  To learn to use and manipulate strings and arrays of characters
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Prototypes */
void reverse (char *array);			// Reverses the inputted array
void parseSentence (char *str);		// Places each word on a new line

/* Main Function */
void main()
{
	char buffer1[80] = {'t','h','i','s',' ','i','s',' ','t','h','e',' ','f','i','r','s','t',' ','b','u','f','f','e','r','\0'};
	char buffer2[80] = {'t','h','i','s',' ','i','s',' ','t','h','e',' ','s','e','c','o','n','d',' ','b','u','f','f','e','r','\0'};
	char buffer3[80];
	char str[80];
	char *pstr = str;
	char *pbuffer = buffer3;

	printf ("Please enter a sentence to be reversed and parsed:\n");
	scanf ("%[^\n]s", buffer3);
	printf ("\nThe buffers and your sentence are as follows:\n");
	printf ("%s\n%s\n%s\n", buffer1, buffer2, pbuffer);
	printf ("\nPartial output of Sentence:\n");
	printf ("%s\n", pbuffer+5);
	reverse (pbuffer);
	printf ("\nReversed Sentence:\n");
	printf ("%s\n", pbuffer);
	printf ("\nParsed Sentence:\n");
	reverse (pbuffer);
	parseSentence (pbuffer);
}

/* Reverse Array Function 
Purpose:	Reverses an array of char values
Input:		A 1D char array
Output:		No output, only reverse the char array in memory */
void reverse (char *array)
{
	int count = 0;
	int i;
	char temp;

	while (*(array+count) != '\0')
		count++;

	count--;

	for (i = 0; i < count; i++, count--)
	{
		temp = *(array+i);
		*(array+i) = *(array+count);
		*(array+count) = temp;
	}
}

/* Parse Sentence Function 
Purpose:	Parses a sentence placing one word per line without space or punctuation
Input:		A 1D char array
Output:		No output, only reverse the char array in memory */
void parseSentence (char *str)
{
	int i = 0;
	while (*(str+i) != '\0')
	{
		for (i = 0; i < strlen(str); i++)
		{
				if (*(str+i) == ' ')
					printf ("\n");
				else if (*(str+i) == ',' || *(str+i) == ';' || *(str+i) == '.')
					printf ("");
				else
					printf ("%c", *(str+i));
		}
	}
	printf ("\n\n");
}