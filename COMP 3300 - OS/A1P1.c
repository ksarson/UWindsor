/*	Name:		Kolby Sarson
	SID:		104232327
	Homework:	Assignment 1, Problem 1
	Due Date:	January 24, 2018
	Class:		COMP 3300
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int persistence(long);

int main(int argc, char *argv[]){

	// Check Arguements
	if (argc < 2)
		printf("Error, Use: A1P1 [filename]");

	else {
		double timePassed = 0.0;
		clock_t begin = clock();
		FILE* file = fopen(argv[1], "r");
		char line[256];
		long array[125];
		int persistenceOfArray[125], arrayCount = 0;

		// File Reading
		while (fgets(line, sizeof(line), file)){
			array[arrayCount] = atol(line);
			arrayCount++;
		}
		fclose(file);

		// Sorting
		for (int i = 0; i < 125; i++){
			for (int j = 0; j < 125; j++){
				if (array[j] > array[i]){
					int temp = array[i];
					array[i] = array[j];
					array[j] = temp;
				}
			}
		}

		// Determining Persistences and Smallest/Largest
		int smallestPers = 12, largestPers = 0, p, smallestIndex, largestIndex;
		for (int i = 0; i < 125; i++){
			p = persistence(array[i]);
			if (p < smallestPers){
				smallestPers = p;
				smallestIndex = i;
			}	
			if (p > largestPers){
				largestPers = p;
				largestIndex = i;
			}	
		}

		// Output Persistences
		printf("Smallest Number: %lu\tPersistence: %d\n", array[smallestIndex], smallestPers);
		printf("Largest Number: %lu\tPersistence: %d\n", array[largestIndex], largestPers);

		//Detemine and Output Time
		clock_t end = clock();
		timePassed += (double)(end - begin) / CLOCKS_PER_SEC;
		printf("Time elapsed is %f seconds\n", timePassed);
	}
	return 0;
}

// Persistence Function
int persistence(long num){
	int count = 0;
	while (num/10 != 0){
		long temp = num, newnum = 1;
		while (temp != 0){
			if (temp%10 != 0)
				newnum *= temp%10;		
			temp /= 10;
		}
		num = newnum;
		count++;
	}
	return count;
}