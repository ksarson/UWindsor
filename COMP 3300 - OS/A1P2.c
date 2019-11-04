/*	Name:		Kolby Sarson
	SID:		104232327
	Homework:	Assignment 1, Problem 2
	Due Date:	January 24, 2018
	Class:		COMP 3300
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>

int persistence(long);

int main(int argc, char *argv[]){
	int fd[2], nbytes;
	pid_t child[5];

	// Check Arguements
	if (argc < 2)
		printf("Error, Use: A1P2 [filename]");

	else {
		double timePassed = 0.0;
		clock_t begin = clock();
		FILE* file = fopen(argv[1], "r");
		char line[256];
		long array[125];
		int persistenceOfArray[125], arrayCount = 0, status, deadID, index;

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

		// Creating Children
		pipe(fd);
	 	for (int i = 0; i < 5; i++){
	 		child[i] = fork();
	 		if (child[i] == 0){
	 			close(fd[1]);
	 			read (fd[0], &index, sizeof(index));
	 			printf("\nnext child");
	 			int childnum, smallestPers = 12, largestPers = 0, p, smallestIndex, largestIndex;
				if (index == 0)
					childnum = 1;
				if (index == 25)
					childnum = 2;
				if (index == 50)
					childnum = 3;
				if (index == 75)
					childnum = 4;
				if (index == 100)
					childnum = 5;

				// Determining Persistences and Smallest/Largest
				for (int i = index; i < index+25; i++){
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
				printf("\nFrom index %d to %d\n", index, index+24);
				printf("Smallest Number: %lu\tPersistence: %d\n", array[smallestIndex], smallestPers);
				printf("Largest Number: %lu\tPersistence: %d\n", array[largestIndex], largestPers);
				printf("I am kid #%d and my id is %d\n", childnum, getpid());
	 			exit(childnum);
	 		}
	 	}

	 	// Outputs Processes
	 	printf("I am the father of the following: %d, %d, %d, %d, and %d\n", child[0], child[1], child[2], child[3], child[4]);
	 	for (int i = 0; i < 125; i += 25){
	 		close(fd[0]);
	 		write(fd[1], &i, sizeof(i));
	 		deadID = wait(&status);
	 		printf("From the main: child, id = %d ended with status %d\n", deadID, status);
	 	}

	 	// Determine and Output Time
	 	clock_t end = clock();
		timePassed += (double)(end - begin) / CLOCKS_PER_SEC;
		printf("\nTime elapsed is %f seconds\n\n", timePassed);
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