#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("EXAM! EXAM! EXAM!\n");
	if (fork() == 0){
		system("./lab6bash.sh");
	}
	return 0;
}