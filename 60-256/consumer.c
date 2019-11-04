#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void){
	char num[20];
	int fd = open("storage.txt", O_RDWR,S_IWUSR|S_IRUSR);
	read(fd, &num, 2);
	int intNum = atoi(num) - 3;
	lseek(fd, 0, SEEK_SET);
	snprintf(num, 3, "%d", intNum);
	write(fd, &num, 2);
	printf("From Consumer:  Current total is %d\n", intNum);
	if(fork()==0){
		sleep(1);
		char *cmd[] = {"./producer.sh", NULL};
		execv(cmd[0], cmd);
	}
	sleep(25);
	exit(0);
	close(fd);
	return 0;
}
