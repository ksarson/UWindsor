#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(char argc, char** argv){

	pid_t pid;
	pid = fork();
	int i;
	if(pid==-1){
	printf("\nError");
       exit(1);
	}
	else if(pid == 0){
     	printf("\nHello I am the child process");
        printf("\nMy pid is %d \n",getpid());
        if(0 == access("/home/sarsonk/60-256/data.dat", 0)){
    		int num = atoi(argv[1]);
    		int fact = 1;
    		for(i=num; i>0; i--)
    			fact *= i;
    		if(num >= 1 && num <= 10)
    		    printf("\nFactorial = %d\n", fact);
        }
        exit(0);
  	}
   	else{
    	printf("\nHello I am the parent process");
        printf("\nMy actual pid is %d \n",getpid());
        int num = atoi(argv[1]);
        if(num >= 1 && num <= 10){
        	int fd = open("data.dat", O_CREAT|O_WRONLY, 0777);
        	write(fd, argv[1], 2);
        	close(fd);
        }
        else{
        	printf("\nError\n");
        }
        exit(1);
	}
	return 0;
}
