/*  Name:     Kolby Sarson
    SID:      104232327
    Homework: Assignment 5
    Due Date: March 19, 2018
    Class:    COMP 3400
*/

#include <stdio.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h> 
#include <stdlib.h>
#include <time.h>

//prototype for persistence function
int persistence(long);

int globalRange = -1;

int main(int argc, char *argv[])
{
	int child[5], statuses[5];
	int pipeParentToC1[2], pipeParentToC2[2], pipeParentToC3[2], pipeParentToC4[2], pipeParentToC5[2];
	int pipeC1ToParent[2], pipeC2ToParent[2], pipeC3ToParent[2], pipeC4ToParent[2], pipeC5ToParent[2];
	char token[20], cToken[20];
	int childID, statusID, childDone;

	//Check for proper arguements
	if (argc < 2)
	{
		setbuf(stdout, NULL);
		printf("Error: Missing Argument(s)\nproper Use: A5 [filename]\n");
	}

	//Child Processes
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

		//Open communication channels
		pipe(pipeParentToC1);
		pipe(pipeParentToC2);
		pipe(pipeParentToC3);
		pipe(pipeParentToC4);
		pipe(pipeParentToC5);

		pipe(pipeC1ToParent);
		pipe(pipeC2ToParent);
		pipe(pipeC3ToParent);
		pipe(pipeC4ToParent);
		pipe(pipeC5ToParent);
		
		for (int i = 0; i < 5; i++)
		{
			childID = i + 1;
			globalRange++;

			//Parent
			if (child[i] = fork()){}

			//Children
			else
			{
				close(pipeC1ToParent[0]);
				close(pipeC2ToParent[0]);
				close(pipeC3ToParent[0]);
				close(pipeC4ToParent[0]);
				close(pipeC5ToParent[0]);

				int childnum;
	 			int smallestpersistence = 12, biggestPersistence = 0, p;
				int smallestIndex, biggestIndex;

				//Swtich case for 5 children
				switch(childID)
				{
					case 1: 
						read(pipeParentToC1[0], &token, sizeof(token));
						setbuf(stdout, NULL);
						printf("\nI am kid #: %d and my id is: %d\n", childID, getpid());

						//Calculation of persistence of array
						for (int k = globalRange*25; k <= globalRange*25 + 24; k++){
							p = persistence(array[k]);
							if (p < smallestpersistence){
								smallestpersistence = p;
								smallestIndex = k;
							}
						
							if (p > biggestPersistence){
								biggestPersistence = p;
								biggestIndex = k;
							}
						
						}
						
						//Output of persistences
						setbuf(stdout, NULL);
						printf("\nI am searching index %d to %d\n", globalRange*25, globalRange*25 + 24);
						setbuf(stdout, NULL);
						printf("Smallest\n\tNumber: %lu\n\tpersistence: %d\n", array[smallestIndex], smallestpersistence);
						setbuf(stdout, NULL);
						printf("Largest\n\tNumber: %lu\n\tpersistence: %d\n", array[biggestIndex], biggestPersistence);

						close(pipeC1ToParent[0]);
						write(pipeC1ToParent[1], "child1_done", sizeof("child1_done"));
						close(pipeC1ToParent[1]);
						break;

					case 2:
						read(pipeParentToC2[0], &token, sizeof(token));

						setbuf(stdout, NULL);
						printf("\nI am kid #: %d and my id is: %d\n", childID, getpid());

						//Calculation of persistence of array
						for (int k = globalRange*25; k <= globalRange*25 + 24; k++){
							p = persistence(array[k]);
							if (p < smallestpersistence){
								smallestpersistence = p;
								smallestIndex = k;
							}
						
							if (p > biggestPersistence){
								biggestPersistence = p;
								biggestIndex = k;
							}
						
						}
						
						//Output of persistences
						setbuf(stdout, NULL);
						printf("\nI am searching index %d to %d\n", globalRange*25, globalRange*25 + 24);
						setbuf(stdout, NULL);
						printf("Smallest\n\tNumber: %lu\n\tpersistence: %d\n", array[smallestIndex], smallestpersistence);
						setbuf(stdout, NULL);
						printf("Largest\n\tNumber: %lu\n\tpersistence: %d\n", array[biggestIndex], biggestPersistence);

						close(pipeC2ToParent[0]);
						write(pipeC2ToParent[1], "child2_done", sizeof("child2_done"));
						close(pipeC2ToParent[1]);
						break;

					case 3:
						read(pipeParentToC3[0], &token, sizeof(token));

						setbuf(stdout, NULL);
						printf("\nI am kid #: %d and my id is: %d\n", childID, getpid());

						//Calculation of persistence of array
						for (int k = globalRange*25; k <= globalRange*25 + 24; k++){
							p = persistence(array[k]);
							if (p < smallestpersistence){
								smallestpersistence = p;
								smallestIndex = k;
							}
						
							if (p > biggestPersistence){
								biggestPersistence = p;
								biggestIndex = k;
							}
						
						}
						
						//Output of persistences
						setbuf(stdout, NULL);
						printf("\nI am searching index %d to %d\n", globalRange*25, globalRange*25 + 24);
						setbuf(stdout, NULL);
						printf("Smallest\n\tNumber: %lu\n\tpersistence: %d\n", array[smallestIndex], smallestpersistence);
						setbuf(stdout, NULL);
						printf("Largest\n\tNumber: %lu\n\tpersistence: %d\n", array[biggestIndex], biggestPersistence);

						close(pipeC3ToParent[0]);
						write(pipeC3ToParent[1], "child3_done", sizeof("child3_done"));
						close(pipeC3ToParent[1]);
						break;

					case 4:
						read(pipeParentToC4[0], &token, sizeof(token));

						setbuf(stdout, NULL);
						printf("\nI am kid #: %d and my id is: %d\n", childID, getpid());

						//Calculation of persistence of array
						for (int k = globalRange*25; k <= globalRange*25 + 24; k++){
							p = persistence(array[k]);
							if (p < smallestpersistence){
								smallestpersistence = p;
								smallestIndex = k;
							}
						
							if (p > biggestPersistence){
								biggestPersistence = p;
								biggestIndex = k;
							}
						
						}
						
						//Output of persistences
						setbuf(stdout, NULL);
						printf("\nI am searching index %d to %d\n", globalRange*25, globalRange*25 + 24);
						setbuf(stdout, NULL);
						printf("Smallest\n\tNumber: %lu\n\tpersistence: %d\n", array[smallestIndex], smallestpersistence);
						setbuf(stdout, NULL);
						printf("Largest\n\tNumber: %lu\n\tpersistence: %d\n", array[biggestIndex], biggestPersistence);

						close(pipeC4ToParent[0]);
						write(pipeC4ToParent[1], "child4_done", sizeof("child4_done"));
						close(pipeC4ToParent[1]);
						break;

					case 5:
						read(pipeParentToC5[0], &token, sizeof(token));
						setbuf(stdout, NULL);
						printf("\nI am kid #: %d and my id is: %d\n", childID, getpid());	

						//Calculation of persistence of array
						for (int k = globalRange*25; k <= globalRange*25 + 24; k++){
							p = persistence(array[k]);
							if (p < smallestpersistence){
								smallestpersistence = p;
								smallestIndex = k;
							}
						
							if (p > biggestPersistence){
								biggestPersistence = p;
								biggestIndex = k;
							}
						
						}
						
						//Output of persistences
						setbuf(stdout, NULL);
						printf("\nI am searching index %d to %d\n", globalRange*25, globalRange*25 + 24);
						setbuf(stdout, NULL);
						printf("Smallest\n\tNumber: %lu\n\tpersistence: %d\n", array[smallestIndex], smallestpersistence);
						setbuf(stdout, NULL);
						printf("Largest\n\tNumber: %lu\n\tpersistence: %d\n", array[biggestIndex], biggestPersistence);

						close(pipeC5ToParent[0]);
						write(pipeC5ToParent[1], "child5_done", sizeof("child5_done"));
						close(pipeC5ToParent[1]);
						break;
				}
				exit(getpid());
			}
		}
		
		//Output child processes created by parent
		setbuf(stdout, NULL);
		printf("I am the father of the followings: %d, %d, %d, %d, %d\n", child[0], child[1], child[2], child[3], child[4]);

		//Child 1 initiation
		close(pipeParentToC1[0]);	//Open pipe from parent to child 1 for writing
		write(pipeParentToC1[1], "GO_AHEAD", sizeof("GO_AHEAD"));	//Send token from parent to child 1
		close(pipeParentToC1[1]);	//Open pipe from parent to child 1 for reading
		read(pipeC1ToParent[0], &cToken, sizeof(cToken));	//Requires the token from previous child
		close(pipeC1ToParent[0]);	//Open pipe from child 1 to parent for writing
		setbuf(stdout, NULL);	//Claer the buffer
		printf("\nChild Token: %s\n", cToken);
		child[0] = wait(&statusID);	//Wait for child 1 to finish and save child pid
		statuses[0] = statusID;	//Save child's exit statuses

		//Child 2 initiation
		close(pipeParentToC2[0]);
		write(pipeParentToC2[1], "GO_AHEAD", sizeof("GO_AHEAD"));
		close(pipeParentToC2[1]);
		read(pipeC2ToParent[0], &cToken, sizeof(cToken));
		close(pipeC2ToParent[0]);
		setbuf(stdout, NULL);
		printf("\nChild Token: %s\n", cToken);
		child[1] = wait(&statusID);
		statuses[1] = statusID;

		//Child 3 initiation
		close(pipeParentToC3[0]);
		write(pipeParentToC3[1], "GO_AHEAD", sizeof("GO_AHEAD"));
		close(pipeParentToC3[1]);
		read(pipeC3ToParent[0], &cToken, sizeof(cToken));
		close(pipeC3ToParent[0]);
		setbuf(stdout, NULL);
		printf("\nChild Token: %s\n", cToken);
		child[2] = wait(&statusID);
		statuses[2] = statusID;

		//Child 4 initiation
		close(pipeParentToC4[0]);
		write(pipeParentToC4[1], "GO_AHEAD", sizeof("GO_AHEAD"));
		close(pipeParentToC4[1]);
		read(pipeC4ToParent[0], &cToken, sizeof(cToken));
		close(pipeC4ToParent[0]);
		setbuf(stdout, NULL);
		printf("\nChild Token: %s\n", cToken);
		child[3] = wait(&statusID);
		statuses[3] = statusID;

		//Child 5 initiation
		close(pipeParentToC5[0]);
		write(pipeParentToC5[1], "GO_AHEAD", sizeof("GO_AHEAD"));
		close(pipeParentToC5[1]);
		read(pipeC5ToParent[0], &cToken, sizeof(cToken));
		close(pipeC5ToParent[0]);
		setbuf(stdout, NULL);
		printf("\nChild Token: %s\n", cToken);
		child[4] = wait(&statusID);
		statuses[4] = statusID;

		//Output child pids and exit statuses
		for (int j = 0; j < 5; j++)
		{	
			setbuf(stdout, NULL);
			printf("From the main: child, id = %d ended with status %d\n", child[j], statuses[j]);
		}

		//Calculation of CPU time
	 	clock_t end = clock();
		time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
		setbuf(stdout, NULL);
		printf("Time elapsed is %f seconds\n", time_spent);
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