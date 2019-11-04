#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/*
int main(){
	fork();
	fork();
	fork();
	printf("%d\n", getpid());
}

int main(){
	if (fork()==0)
		fork();
	else{
		fork();
		fork();
		printf("%d\n", getpid());
	}	
}

int main(){
	if (fork()==0)
		fork();
	else{
		fork();
		fork();
	}
	printf("%d\n", getpid());
}*/

int main(){
	if (fork()==0)
		fork();
	else{
		fork();
		fork();
		exit(0);
	}
	printf("%d\n", getpid());
}