#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void alarmHandler(){};

int main(int argc, char **argv){
	const char *buf[3];
	buf[0] = "EXAM! EXAM! EXAM!\n";
	buf[1] = "HELP! HELP! HELP!\n";
	buf[2] = "STUDY! STUDY! STUDY!\n";
	int fd=open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR);
	printf("Parent has opened file: %s\n", argv[1]);
	pid_t pid = fork();
    if(pid==0){
    	printf("Parent created child process: %d\n", getpid());
    	write(fd, buf[0], 18);
    	printf("Child process %d has written to file: %s", getpid(), buf[0]);
    	sleep(5);
    	kill(getpid(), SIGALRM);
    } 
    else{
    	sleep(5);
    	pid = fork();
    	if(pid==0){
    		printf("Parent created child process: %d\n", getpid());
    		signal(SIGALRM, alarmHandler);
    		write(fd, buf[1], 18);
    		printf("Child process %d has written to file: %s", getpid(), buf[1]);
    		sleep(5);
    		kill(getpid(), SIGALRM);
    	}
    	else{
    		sleep(5);
    		signal(SIGALRM, alarmHandler);
    		write(fd, buf[2], 21);
    		printf("Parent process %d has written to file: %s", getpid(), buf[2]);
    		sleep(5);
    		printf("Parent closed the file\n");
    		close(fd);
    	}
    }
	return 0;
}