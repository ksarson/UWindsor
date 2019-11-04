/*	
	Sarson, Kolby
	ID:  104232327

	Assignment #3
	Due Date:  March 12, 2017

	Purpose:  	Solve any given maze using the right hand rule, accounting for passing spaces previously
				traversed and when the only exit is the entrance.  Also prints the maze after each step. 

	"I acknowledge that this is my own work and did not receive any 
	unauthorized help with it."
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define strL 80

/* Function Prototypes */
void letterAnalysis(char inputstring[][strL], int linesN);					//  Find the number of times each letter appears in the strings	
int wordLengthAnalysis(char inputstring[][strL], int linesN, int wordL);	//  Find the number of words of each word legth
void wordAnalysis(char inputstring[][strL], int linesN);					//  Find the frequency of each word (punctuation is attached to words, making them different)

/* Main Function */
void main()
{	
	int linesN, i, words, wordL; 

	printf ("Enter the number of lines you wish to input:\n");
	scanf ("%d", &linesN);
	while (getchar () != '\n');

	char inputstring[linesN][strL];

	for (i = 0; i < linesN; i++)	
		fgets (inputstring[i], strL, stdin);

	printf ("\nLetter Counts:\n");

	letterAnalysis(inputstring, linesN);

	printf ("\nWord Counts:\n");

	for (wordL = 1; wordL < 21; wordL++)
	{
		words = wordLengthAnalysis(inputstring, linesN, wordL);
		if (words > 1)
			printf ("Words of length %d: %d\n", wordL, words);
		else if (words == 1)
			printf ("Word of length %d: %d\n", wordL, words);
	}

	printf("\nWord Occurences:\n");
	wordAnalysis(inputstring, linesN);
}

/*  Objective: Find the number of times each letter appears in the strings
    Input: 2D char inputstring of strings and the number of lines (sentences each on new lines)
    Output: Prints each letter along with the number of occurances of said letter  */
void letterAnalysis(char inputstring[][strL], int linesN)
{
	int i, j, k;
	int letters[26] = {0};
	char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

	for (i = 0; i < linesN; i++)	//  For loop for each string
		for(j = 0; j < strL; j++)		//  For loop for each character in a line
		{
			inputstring[i][j] = tolower (inputstring[i][j]);	//  Makes all letters lowercase
			if (inputstring[i][j] == '\n')
				break;
			else
			{
				for (k = 0; k < 26; k++)	//  For loop for the alphabet
				{
					if (inputstring[i][j] == alphabet[k])
						letters[k]++;
				}
			}
		}

	for (i = 0; i < 26; i++)
		printf ("%c:  %2d\n", alphabet[i], letters[i]);
}

/*  Objective: Find the number of words of each word legth
    Input: 2D char inputstring of strings, the number of lines (sentences each on new lines) and the word length to be counted
    Output: Returns an int value indicating the number of words of the inputted length  */
int wordLengthAnalysis(char inputstring[][strL], int linesN, int wordL)
{
	int i, j, words = 0, letters = 0;

 	for (i = 0; i < linesN; i++)	//  For loop for each string
 	{
  		letters = 0;
    	for (j = 0; inputstring[i][j] != '\0'; j++)	//  For loop for each character in a line
	    {
		    if (isalpha(inputstring[i][j])) 	//  Check if character is an alphabetic character
		        letters++; 
		    else if (letters == wordL)
		    {
		        words++; 
		        letters = 0; 
		    }
		    else
		        letters = 0; 
	    }
  	}
  return words;
}

/*  Objective: Find the frequency of each word (punctuation is attached to words, making them different)
    Input: 2D char inputstring of strings and the number of lines (sentences each on new lines)
    Output: Prints each word with the number of times it occurs in the 2D inputstring  */
void wordAnalysis(char inputstring[][strL], int linesN)
{
	int i, j, k = 0, l = 0, space = 0, count = 0;
  	static char uniquewords[100][20], allwords[100][20];

  	for (i = 0; i < linesN; i++)	//  For loop for each string
  	{
		for (j = 0; inputstring[i][j] != '\0'; j++)	//  For loop for each character in a line
		{
  	    	if (isblank (inputstring[i][j]) || inputstring[i][j] == '\n')	//  Checks for spaces and new lines
  	    	{
		    	allwords[k][l] = '\0';	//  Adds a delimiter to the end of each word in inputstring 
     			space++;
     			k++;          
     			l = 0;
      		}
        	else
        	{
       			allwords[k][l] = inputstring[i][j];	//  If not space or new line, add to an array of all words
       			l++;
       		}
    	} 
	} 
  
	for (i = 0, k = 0; k <= space; k++)	//  For loop for each word
	{
	    for (j = 0; j <= space; j++)	//  For loop for each character in a line
	    {
	        if (k == j)
	        {
	            strcpy(uniquewords[i], allwords[k]);   //  Copies only unique words from allwords to uniquewords
	            i++; 
	            count++;	//  Count of unique words         
	            break;
	        }
	        else
	        {
	            if (strcmp(uniquewords[j], allwords[k]) == 0)	// Breaks if word is not unique
	                break;
	        }
	    }
	}
  
	for (k = 0, i = 0; i < count; i++)
	{
	    for (j = 0; j <= space; j++)
	    {
	        if (strcmp(uniquewords[i], allwords[j]) == 0)	// Increment k for each repeated word
	            k++;
	    }
	    if (k > 1) 
		    printf("'%-20s'\t\t appeared %d times\n", uniquewords[i], k);

	    else
	        printf("'%-20s'\t\t appeared %d time\n", uniquewords[i], k);
	    k = 0;    
	} 
}