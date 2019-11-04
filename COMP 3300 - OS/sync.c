#include <stdio.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h> 
#include <stdlib.h>

int main(void)
{
	int child[2];
	int pipeParentToChild1[2], pipeParentToChild2[2], pipeParentToChild3[2], pipeParentToChild4[2], pipeParentToChild5[2];
	int pipeChild1ToChild2[2], pipeChild2ToChild3[2], pipeChild3ToChild4[2], pipeChild4ToChild5[2];

	int childID;
	char token[20], childToken[20];

	int statusId, childDone;

	pipe(pipeParentToChild1);
	pipe(pipeParentToChild2);
	pipe(pipeParentToChild3);
	pipe(pipeParentToChild4);
	pipe(pipeParentToChild5);

	pipe(pipeChild1ToChild2);
	pipe(pipeChild2ToChild3);
	pipe(pipeChild3ToChild4);
	pipe(pipeChild4ToChild5);
	

	
	
	

	for (int i = 0; i < 5; i++)
	{
		childID = i + 1;
		if (child[i] = fork())
		{
			//parent
			setbuf(stdout, NULL);
			printf("This is parent creating a new child with PID = %d\n", child[i]);
		}
		else
		{
			//child
			switch(childID)
			{
				case 1: 
					read(pipeParentToChild1[0], &token, sizeof(token));
					//printf("Token 1: %s\n", token);

					close(pipeChild1ToChild2[0]);
					write(pipeChild1ToChild2[1], "GO_AHEAD_CHILD", sizeof("GO_AHEAD_CHILD"));

					close(pipeChild1ToChild2[1]);
					break;
				case 2:
					read(pipeParentToChild2[0], &token, sizeof(token));
					//printf("Token 2: %s\n", token);

					close(pipeChild1ToChild2[0]);
					read(pipeChild1ToChild2[0], &childToken, sizeof(childToken));
					
					close(pipeChild2ToChild3[0]);
					write(pipeChild2ToChild3[1], childToken, sizeof(childToken));

					close(pipeChild2ToChild3[1]);
					break;
				case 3:
					read(pipeParentToChild3[0], &token, sizeof(token));
					//printf("Token 3: %s\n", token);

					close(pipeChild2ToChild3[0]);
					read(pipeChild2ToChild3[0], &childToken, sizeof(childToken));
					
					close(pipeChild3ToChild4[0]);
					write(pipeChild3ToChild4[1], childToken, sizeof(childToken));

					close(pipeChild3ToChild4[1]);
					break;
				case 4:
					read(pipeParentToChild4[0], &token, sizeof(token));
					//printf("Token 4: %s\n", token);

					close(pipeChild3ToChild4[0]);
					read(pipeChild3ToChild4[0], &childToken, sizeof(childToken));
					
					close(pipeChild4ToChild5[0]);
					write(pipeChild4ToChild5[1], childToken, sizeof(childToken));

					close(pipeChild4ToChild5[1]);
					break;
				case 5:
					read(pipeParentToChild5[0], &token, sizeof(token));
					//printf("Token 5: %s\n", token);

					close(pipeChild4ToChild5[0]);
					read(pipeChild4ToChild5[0], &childToken, sizeof(childToken));

					
					break;
			}

			exit(getpid());
		}

	}
	
	close(pipeParentToChild1[0]);
	write(pipeParentToChild1[1], "GO_AHEAD", sizeof("GO_AHEAD"));
	close(pipeParentToChild1[1]);
	
	close(pipeParentToChild2[0]);
	write(pipeParentToChild2[1], "GO_AHEAD", sizeof("GO_AHEAD"));
	close(pipeParentToChild2[1]);

	close(pipeParentToChild3[0]);
	write(pipeParentToChild3[1], "GO_AHEAD", sizeof("GO_AHEAD"));
	close(pipeParentToChild3[1]);
	
	close(pipeParentToChild4[0]);
	write(pipeParentToChild4[1], "GO_AHEAD", sizeof("GO_AHEAD"));
	close(pipeParentToChild4[1]);

	close(pipeParentToChild5[0]);
	write(pipeParentToChild5[1], "GO_AHEAD", sizeof("GO_AHEAD"));
	close(pipeParentToChild5[1]);
	
	for (int j = 0; j < 5; j++)
	{	
		childDone = wait(&statusId);
		setbuf(stdout, NULL);
		printf("Child %d ended with status code %d\n", childDone, statusId);
		statusId = 0;
	}

	return 0;
}
