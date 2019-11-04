#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(char argc, char** argv){

	int a[] = {atoi(argv[1]),atoi(argv[2]),atoi(argv[3]),atoi(argv[4]),atoi(argv[5]),atoi(argv[6]),atoi(argv[7])};
    if(fork() == 0){ //Process 2
    	int proc2 = 2;
    	
    	if(fork() == 0){ //Process 4
    		int proc4 = 4;
    		sleep(a[3]);
    		printf("Process %d terminated, pid %d\n", proc4, getpid());
    		exit(0);
    	}
    	else{
    		if(fork() == 0){ //Process 5
    			int proc5 = 5;
    			sleep(a[4]);
    			printf("Process %d terminated, pid %d\n", proc5, getpid());
    			exit(0);
    		}
    	}
    	sleep(a[1]);
    	printf("Process %d terminated, pid %d\n", proc2, getpid());
    }
    else{ //Process 1
    	int proc1 = 1;
    	if(fork() == 0){ //Process 3
    		int proc3 = 3;
    		sleep(a[2]);
    		printf("Process %d terminated, pid %d\n", proc3, getpid());
    		exit(0);
    	}
    	else{
    		if(fork() == 0){ //Process 6
    			int proc6 = 6;
    			sleep(a[5]);
    			printf("Process %d terminated, pid %d\n", proc6, getpid());
    			exit(0);
    		}
    		else{
    			if(fork() == 0){ //Process 7
    				int proc7 = 7;
    				sleep(a[6]);
    				printf("Process %d terminated, pid %d\n", proc7, getpid());
    				exit(0);
    			}
    		}
    	}
    	sleep(a[0]);
		printf("Process %d terminated, pid %d\n", proc1, getpid());
    }
	return 0;
}