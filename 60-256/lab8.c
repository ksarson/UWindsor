#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//void child(int*, char*[]);
//void parent(int*, char*[]);

int main(int argc, char *argv[]){
	int fd[2];
	if(fork()==0)
		execl("/bin/ls", "ls", NULL);
	else
		printf("hey");
	exit(0);
	return 0;
}

/*
void child(int *fd, char *argv[]){
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	execlp(argv[2], argv[2], NULL);
}

void parent(int *fd, char *argv[]){
	close(fd[0]);
	dup2(fd[1], STDIN_FILENO);
	close(fd[1]);
	execlp(argv[1], argv[1], NULL);
}
*/