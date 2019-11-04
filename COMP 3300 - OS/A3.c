/*	Name:		Kolby Sarson
	SID:		104232327
	Homework:	Assignment 3
	Due Date:	February 26, 2018
	Class:		COMP 3300
*/

#include <stdio.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h> 
#include <stdlib.h>
#include <time.h>

//Prototype for persistence function
int persistence(long);

int globalRange = -1;

int main(int argc, char *argv[])
{
	int child[5], statuses[5];
	int pipeParentToC1[2], pipeParentToC2[2], pipeParentToC3[2], pipeParentToC4[2], pipeParentToC5[2];
	int pipeC1ToC2[2], pipeC2ToC3[2], pipeC3ToC4[2], pipeC4ToC5[2];
	char token[20], cToken[20];
	int childID, statusID, childDone;

	//Check for proper arguements
	if (argc < 2)
	{
		setbuf(stdout, NULL);
		printf("Error: Missing Argument(s)\nProper Use: A3 [filename]\n");
	}

	else
	{
		double time_spent = 0.0;
		clock_t begin = clock();

		//Read from file
		FILE* file = fopen(argv[1], "r");
		char line[256];
		long array[125];
		int arrayKnt = 0;

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

		//Open pipes for parent to child
		pipe(pipeParentToC1);
		pipe(pipeParentToC2);
		pipe(pipeParentToC3);
		pipe(pipeParentToC4);
		pipe(pipeParentToC5);

		//Open pipes for child to child
		pipe(pipeC1ToC2);
		pipe(pipeC2ToC3);
		pipe(pipeC3ToC4);
		pipe(pipeC4ToC5);
		
		for (int i = 0; i < 5; i++)
		{
			childID = i + 1;
			globalRange++;

			//Parent Process
			if (child[i] = fork())
			{
				setbuf(stdout, NULL);
				printf("This is parent creating a new child with PID = %d\n", child[i]);
			}

			//Child Processes
			else
			{
				//Open all child to child pipes for writing (blocks reading)
				close(pipeC1ToC2[0]);
				close(pipeC2ToC3[0]);
				close(pipeC3ToC4[0]);
				close(pipeC4ToC5[0]);

				int childnum;
	 			int smallestP = 12, biggestP = 0, p;
				int smallestI, biggestI;

				//Switch case for 5 child processes
				switch(childID)
				{
					case 1: 
						read(pipeParentToC1[0], &token, sizeof(token));	//Requires the token from parent
						setbuf(stdout, NULL);
						printf("\nI am kid #: %d and my id is: %d", childID, getpid());

						//Calculation of persistence of array
						for (int k = globalRange*25; k <= globalRange*25 + 24; k++){
							p = persistence(array[k]);
							if (p < smallestP){
								smallestP = p;
								smallestI = k;
							}
							if (p > biggestP){
								biggestP = p;
								biggestI = k;
							}
						}
						
						//Output the persistences
						setbuf(stdout, NULL);
						printf("\nFrom index %d to %d\n", globalRange*25, globalRange*25 + 24);
						setbuf(stdout, NULL);
						printf("Smallest Number: %lu\tPersistence: %d\n", array[smallestI], smallestP);
						setbuf(stdout, NULL);
						printf("Largest Number: %lu\tPersistence: %d\n", array[biggestI], biggestP);

						close(pipeC1ToC2[0]);	//Open child 1 to 2 pipe for writing
						write(pipeC1ToC2[1], "GO_AHEAD_CHILD", sizeof("GO_AHEAD_CHILD"));	//Send token to child 2
						close(pipeC1ToC2[1]);	//Open child 1 to 2 pipe for reading
						break;

					case 2:
						read(pipeParentToC2[0], &token, sizeof(token));	//Requires the token from parent
						read(pipeC1ToC2[0], &cToken, sizeof(cToken));	//Requires the token from previous child
						setbuf(stdout, NULL);
						printf("\nI am kid #: %d and my id is: %d", childID, getpid());

						//Calculation of persistence of array
						for (int k = globalRange*25; k <= globalRange*25 + 24; k++){
							p = persistence(array[k]);
							if (p < smallestP){
								smallestP = p;
								smallestI = k;
							}
							if (p > biggestP){
								biggestP = p;
								biggestI = k;
							}
						}
						
						//Output the persistences
						setbuf(stdout, NULL);
						printf("\nFrom index %d to %d\n", globalRange*25, globalRange*25 + 24);
						setbuf(stdout, NULL);
						printf("Smallest Number: %lu\tPersistence: %d\n", array[smallestI], smallestP);
						setbuf(stdout, NULL);
						printf("Largest Number: %lu\tPersistence: %d\n", array[biggestI], biggestP);

						close(pipeC2ToC3[0]);	//Open child 1 to 2 pipe for writing
						write(pipeC2ToC3[1], cToken, sizeof(cToken));	//Send token to child 2
						close(pipeC2ToC3[1]);	//Open child 1 to 2 pipe for reading
						break;

					case 3:
						read(pipeParentToC3[0], &token, sizeof(token));	//Requires the token from parent
						read(pipeC2ToC3[0], &cToken, sizeof(cToken));	//Requires the token from previous child
						setbuf(stdout, NULL);
						printf("\nI am kid #: %d and my id is: %d", childID, getpid());

						//Calculation of persistence of array
						for (int k = globalRange*25; k <= globalRange*25 + 24; k++){
							p = persistence(array[k]);
							if (p < smallestP){
								smallestP = p;
								smallestI = k;
							}
							if (p > biggestP){
								biggestP = p;
								biggestI = k;
							}
						}
						
						//Output the persistences
						setbuf(stdout, NULL);
						printf("\nFrom index %d to %d\n", globalRange*25, globalRange*25 + 24);
						setbuf(stdout, NULL);
						printf("Smallest Number: %lu\tPersistence: %d\n", array[smallestI], smallestP);
						setbuf(stdout, NULL);
						printf("Largest Number: %lu\tPersistence: %d\n", array[biggestI], biggestP);

						close(pipeC3ToC4[0]);	//Open child 1 to 2 pipe for writing
						write(pipeC3ToC4[1], cToken, sizeof(cToken));	//Send token to child 2
						close(pipeC3ToC4[1]);	//Open child 1 to 2 pipe for reading
						break;

					case 4:
						read(pipeParentToC4[0], &token, sizeof(token));	//Requires the token from parent
						read(pipeC3ToC4[0], &cToken, sizeof(cToken));	//Requires the token from previous child
						setbuf(stdout, NULL);
						printf("\nI am kid #: %d and my id is: %d", childID, getpid());

						//Calculation of persistence of array
						for (int k = globalRange*25; k <= globalRange*25 + 24; k++){
							p = persistence(array[k]);
							if (p < smallestP){
								smallestP = p;
								smallestI = k;
							}
							if (p > biggestP){
								biggestP = p;
								biggestI = k;
							}
						}
						
						//Output the persistences
						setbuf(stdout, NULL);
						printf("\nFrom index %d to %d\n", globalRange*25, globalRange*25 + 24);
						setbuf(stdout, NULL);
						printf("Smallest Number: %lu\tPersistence: %d\n", array[smallestI], smallestP);
						setbuf(stdout, NULL);
						printf("Largest Number: %lu\tPersistence: %d\n", array[biggestI], biggestP);

						close(pipeC4ToC5[0]);	//Open child 1 to 2 pipe for writing
						write(pipeC4ToC5[1], cToken, sizeof(cToken));	//Send token to child 2
						close(pipeC4ToC5[1]);	//Open child 1 to 2 pipe for reading
						break;

					case 5:
						read(pipeParentToC5[0], &token, sizeof(token));	//Requires the token from parent
						read(pipeC4ToC5[0], &cToken, sizeof(cToken));	//Requires the token from previous child
						setbuf(stdout, NULL);
						printf("\nI am kid #: %d and my id is: %double", childID, getpid());	

						//Calculation of persistence of array
						for (int k = globalRange*25; k <= globalRange*25 + 24; k++){
							p = persistence(array[k]);
							if (p < smallestP){
								smallestP = p;
								smallestI = k;
							}
							if (p > biggestP){
								biggestP = p;
								biggestI = k;
							}
						}
						
						//Output the persistences
						setbuf(stdout, NULL);
						printf("\nFrom index %d to %d\n", globalRange*25, globalRange*25 + 24);
						setbuf(stdout, NULL);
						printf("Smallest Number: %lu\tPersistence: %d\n", array[smallestI], smallestP);
						setbuf(stdout, NULL);
						printf("Largest Number: %lu\tPersistence: %d\n\n", array[biggestI], biggestP);
						break;
				}
				exit(getpid());
			}
		}
		
		//Output child processes created by parent
		setbuf(stdout, NULL);
		printf("\nI am the father of the followings: %d, %d, %d, %d, %d\n", child[0], child[1], child[2], child[3], child[4]);

		//Child 1 initiation
		close(pipeParentToC1[0]);	//Open pipe from parent to child 1 for writing
		write(pipeParentToC1[1], "GO_AHEAD", sizeof("GO_AHEAD"));	//Send token from parent to child 1
		close(pipeParentToC1[1]);	//Open pipe from parent to child 1 for reading
		child[0] = wait(&statusID);	//Wait for child 1 to finish and save child pid
		statuses[0] = statusID;	//Save child's exit status

		//Child 2 initiation
		close(pipeParentToC2[0]);	//Open pipe from parent to child 2 for writing
		write(pipeParentToC2[1], "GO_AHEAD", sizeof("GO_AHEAD"));	//Send token from parent to child 2
		close(pipeParentToC2[1]);	//Open pipe from parent to child 2 for reading
		child[1] = wait(&statusID);	//Wait for child 2 to finish and save child pid
		statuses[1] = statusID;	//Save child's exit status

		//Child 3 initiation
		close(pipeParentToC3[0]);	//Open pipe from parent to child 3 for writing
		write(pipeParentToC3[1], "GO_AHEAD", sizeof("GO_AHEAD"));	//Send token from parent to child 3
		close(pipeParentToC3[1]);	//Open pipe from parent to child 3 for reading
		child[2] = wait(&statusID);	//Wait for child 3 to finish and save child pid
		statuses[2] = statusID;	//Save child's exit status

		//Child 4 initiation
		close(pipeParentToC4[0]);	//Open pipe from parent to child 4 for writing
		write(pipeParentToC4[1], "GO_AHEAD", sizeof("GO_AHEAD"));	//Send token from parent to child 4
		close(pipeParentToC4[1]);	//Open pipe from parent to child 4 for reading
		child[3] = wait(&statusID);	//Wait for child 4 to finish and save child pid
		statuses[3] = statusID;	//Save child's exit status

		//Child 5 initiation
		close(pipeParentToC5[0]);	//Open pipe from parent to child 5 for writing
		write(pipeParentToC5[1], "GO_AHEAD", sizeof("GO_AHEAD"));	//Send token from parent to child 5
		close(pipeParentToC5[1]);	//Open pipe from parent to child 5 for reading
		child[4] = wait(&statusID);	//Wait for child 5 to finish and save child pid
		statuses[4] = statusID;	//Save child's exit status

		//Output child pids and exit statuses
		for (int j = 0; j < 5; j++)
		{	
			setbuf(stdout, NULL);
			printf("From the main: child, id = %d ended with status %d\n", child[j], statuses[j]);
		}

		//Calculation and output of CPU time
	 	clock_t end = clock();
		time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
		setbuf(stdout, NULL);
		printf("\nTime elapsed is %f seconds\n", time_spent);
		setbuf(stdout, NULL);
		printf("Goodbye!\n");
	}
	return 0;
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