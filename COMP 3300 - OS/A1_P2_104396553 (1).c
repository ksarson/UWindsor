/*	Name:		Kolby Sarson
	SID:		104232327
	Homework:	Assignment 3
	Due Date:	February 26, 2018
	Class:		COMP 3300
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>
#include <time.h>

//Prototype for persistence function
int persistence(long);

int globalRange = -1;
int globalChild = 0;

int main(int argc, char *argv[]){
	int fd[2], nbytes;
	pid_t child[5];
	
	if (argc < 2){
		printf("Error: Missing Argument(s)\nProper Use: A1_P2_104396553 [filename]");
	} else {
		double time_spent = 0.0;
		clock_t begin = clock();
		
		//Read from file
		FILE* file = fopen(argv[1], "r");
		char token[20];
		char line[256];
		long array[125];
		int persistenceOfArray[125];
		int arrayKnt = 0;
		int statuscode;
		int deadChild;
		while (fgets(line, sizeof(line), file)){
			array[arrayKnt] = atol(line);
			arrayKnt++;
		}
		fclose(file);

		//Sorting Algorithm for array
		for (int i = 0; i < 125; i++){
			for (int j = 0; j < 125; j++){
				if (array[j] > array[i]){
					int temp = array[i];
					array[i] = array[j];
					array[j] = temp;
				}
			}
		}

		pipe(fd);
		
		//Creates the 5 child processes
	 	for (int i = 0; i < 5; i++){
	 		child[i] = fork();
	 		globalRange++;
	 		globalChild++;
	 		if (child[i] == 0){
	 			//child process
	 			close(fd[1]);
	 			read (fd[0], &token, sizeof(token));
	 			int childnum;
	 			int smallestP = 12, biggestP = 0, p;
				int smallestI, biggestI;
				
				
				//Calculation of persistence of array
				for (int i = globalRange*25; i <= globalRange*25 + 24; i++){
					p = persistence(array[i]);
					if (p < smallestP){
						smallestP = p;
						smallestI = i;
					}
				
					if (p > biggestP){
						biggestP = p;
						biggestI = i;
					}
				
				}
				
				//Output
				printf("\nFrom index %d to %d\n", globalRange*25, globalRange*25 + 24);
				printf("Smallest\n\tNumber: %lu\n\tPersistence: %d\n", array[smallestI], smallestP);
				printf("Largest\n\tNumber: %lu\n\tPersistence: %d\n", array[biggestI], biggestP);
				printf("I am kid #: %d and my id is: %d\n\n", globalChild, getpid());
	 			exit(globalChild);
	 		}
	 		
	 	}
	 	//Parent Process
	 	printf("I am the father of the followings: %d, %d, %d, %d, and %d\n", child[0], child[1], child[2], child[3], child[4]);
	 	for (int i = 0; i < 5; i++){
	 		close(fd[0]);
	 		write(fd[1], "GO_AHEAD", sizeof("GO_AHEAD"));
	 		deadChild = wait(&statuscode);
	 		
	 		
	 		printf("From the main: child, id = %d ended with status %d\n", deadChild, statuscode);
	 	}
	 	//Calculation of CPU time
	 	clock_t end = clock();
		time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
		printf("Time elapsed is %f seconds\n", time_spent);
		printf("Goodbye!\n");
	 	
	}
	
	
 	return(0);
}

//This function takes in a number and returns the persistence of that number
int persistence(long num){
	int knt = 0;
	while (num/10 != 0){
		long temp = num;
		long newnum = 1;
		while (temp != 0){
			newnum *= temp%10;
			temp /= 10;
		}
		num = newnum;
		knt++;
	}
	return knt;
}
