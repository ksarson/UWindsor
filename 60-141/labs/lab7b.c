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

/* structures */
struct myword
{
	char word[21];
	int length;
};

/* Function Prototypes */
void BubbleSort (struct myword list[], int size);		//  Sorts the array in ascending order using the bubble method

/* Main Function */
void main()
{
	struct myword wordlist[20];
	char myString[] = "the cat in the hat jumped over the lazy fox";
    const char s[2] = " ";
    char *token;
    int i = 0, j;

    token = strtok(myString, s);
    while(token != NULL) 
    {
    	strcpy (wordlist[i].word, token);
    	wordlist[i].length = strlen (wordlist[i].word);
    	token = strtok(NULL, s);
    	i++;
    }

    printf ("The unsorted array\n");
    for (j = 0; j < i; j++)
	{
    	printf ("%s - %d\n", wordlist[j].word, wordlist[j].length);
	}

    BubbleSort(wordlist, i);

    printf ("The sorted array\n");
    for (j = 0; j < i; j++)
	{
    	printf ("%s - %d\n", wordlist[j].word, wordlist[j].length);
	}

}

/* Bubble Sort Function 
Purpose:	Sorts the array in ascending order
Input:		1D array and size of the array
Output:		No output, only sorts the values held in the array in ascending order */
void BubbleSort (struct myword wordlist[80], int size)  
{
     int j, k;  
     struct myword temp;

     for(j = 0; j < size-1 ; j++) 
          for(k = 0; k < size-j-1; k++) 
               if (strcmp (wordlist[k].word, wordlist[k + 1].word) > 0)
            {
                temp = wordlist[k];
                wordlist[k] = wordlist[k + 1];
                wordlist[k + 1] = temp;
            } 
     return;
}
