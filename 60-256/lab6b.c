#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

//execl(/bin/bash/name, action, arg, (char*)0);
int main(char argc, char **argv){

	for (int i=1; i<argc; i=i+2){
		pid_t pid=fork();
		if (argv[i+1]==NULL){
			execl(argv[i], argv[i], (char*)0);
		}
		if (pid){
			sleep(1);
		}
		else{
			execlp(argv[i], argv[i], argv[i+1], (char*)0);
			exit(0);
		}
	}
	return 0;
}