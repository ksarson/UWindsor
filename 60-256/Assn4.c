/*
Name:	Kolby Sarson
ID:		104232327
Due:	November 19, 2017
Item:	Assignement 4 
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/mman.h>
#include <sys/types.h>

void colour(char *, int *);
void red(int **);
void blue(int **);
void green(int **);
void yellow(int **);
void orange(int **);
void cyan(int **);
void magenta(int **);
void ocean(int **);
void violet(int **);
void sigHandler(int);
bool static writeFlag = false;
static int *diamond;

int main(int argc, char **argv){
	int k=0;
	int drawing = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	char header[] = "P6\n1000 1000\n255\n";
	diamond = mmap(NULL, sizeof *diamond, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	signal(SIGALRM, sigHandler);
	pid_t pid;
	char *c1=argv[2], *c2=argv[3], *c3=argv[4], *c4=argv[5], *c5=argv[6];

	//Parent process
	if((pid=fork()) > 0){
		sleep(4);
		write(drawing, &header, 17);
		//Return to child
		kill(pid, SIGALRM);
	}
	else{
		signal(SIGALRM, sigHandler);
		pause();
		//When parent signals to start file writing
		if(writeFlag){
			//child process 1
			for(int i=0; i<100; i++){
				for(int j=0; j<1000; j++){
					if(j<500)
						colour(c2, &drawing);
					else
						colour(c3, &drawing);
				}
			}
			//Child processes 2 through 10 created
			for(k;k<9;k++){
				pid = fork();
				if(pid==0)
					break;
			}
			//Within each child process
			if(pid==0){
				//Child process 2
				if(k==0){
					sleep(k);
					for(int i=0; i<100; i++){
						for(int j=0; j<1000; j++){
							if(j<500)
								colour(c2, &drawing);
							else
								colour(c3, &drawing);
						}
					}
				}
				//Child process 3
				else if(k==1){
					sleep(k);
					for(int i=0; i<100; i++){
						for(int j=0; j<1000; j++){
							if(j<500 && i<50)
								colour(c2, &drawing);
							else if(j>=500 && i<50)
								colour(c3, &drawing);
							else{
								if(j<(500-*diamond))
									colour(c2, &drawing);
								else if(j>(500+*diamond))
									colour(c3, &drawing);
								else if(j>=(500-*diamond) && j<=(500+*diamond))
									colour(c1, &drawing);
							}
						}
						if(i>=50)
							*diamond+=1;
					}
				}
				//Child process 4
				else if(k==2){
					sleep(k);
					for(int i=0; i<100; i++){
						for(int j=0; j<1000; j++){
							if(j<(500-*diamond))
								colour(c2, &drawing);
							else if(j>(500+*diamond))
								colour(c3, &drawing);
							else if(j>=(500-*diamond) && j<=(500+*diamond))
								colour(c1, &drawing);
						}
						*diamond+=1;
					}
				}
				//Child process 5
				else if(k==3){
					sleep(k);
					for(int i=0; i<100; i++){
						for(int j=0; j<1000; j++){
							if(j<(500-*diamond))
								colour(c2, &drawing);
							else if(j>(500+*diamond))
								colour(c3, &drawing);
							else if(j>=(500-*diamond) && j<=(500+*diamond))
								colour(c1, &drawing);
						}
						*diamond+=1;
					}
				}
				//Child process 6
				else if(k==4){
					sleep(k);
					for(int i=0; i<100; i++){
						for(int j=0; j<1000; j++){
							if(j<(500-*diamond))
								colour(c4, &drawing);
							else if(j>(500+*diamond))
								colour(c5, &drawing);
							else if(j>=(500-*diamond) && j<=(500+*diamond))
								colour(c1, &drawing);
						}
						*diamond-=1;
					}
				}
				//Child process 7
				else if(k==5){
					sleep(k);
					for(int i=0; i<100; i++){
						for(int j=0; j<1000; j++){
							if(j<(500-*diamond))
								colour(c4, &drawing);
							else if(j>(500+*diamond))
								colour(c5, &drawing);
							else if(j>=(500-*diamond) && j<=(500+*diamond))
								colour(c1, &drawing);
						}
						*diamond-=1;
					}
				}
				//Child process 8
				else if(k==6){
					sleep(k);
					for(int i=0; i<100; i++){
						for(int j=0; j<1000; j++){
							if(j<500 && i>50)
								colour(c4, &drawing);
							else if(j>=500 && i>50)
								colour(c5, &drawing);
							else{
								if(j<(500-*diamond))
									colour(c4, &drawing);
								else if(j>(500+*diamond))
									colour(c5, &drawing);
								else if(j>=(500-*diamond) && j<=(500+*diamond))
									colour(c1, &drawing);
							}
						}
						if(i<=50)
							*diamond-=1;
					}
				}
				//Child process 9
				else if(k==7){
					sleep(k);
					for(int i=0; i<100; i++){
						for(int j=0; j<1000; j++){
							if(j<500)
								colour(c4, &drawing);
							else
								colour(c5, &drawing);
						}
					}
				}
				//Child process 10
				else if(k==8){
					sleep(k);
					printf("Finished.");
					for(int i=0; i<100; i++){
						for(int j=0; j<1000; j++){
							if(j<500)
								colour(c4, &drawing);
							else
								colour(c5, &drawing);
						}
					}
				}
			}
		}
	}
	close(drawing);
}

void sigHandler(int signum){
	writeFlag = true;
}

//Draws pixel based on input colour
void colour(char *colour, int *drawing){
	if(strcmp(colour, "violet")==0)
		violet(&drawing);
	else if(strcmp(colour, "ocean")==0)
		ocean(&drawing);
	else if(strcmp(colour, "magenta")==0)
		magenta(&drawing);
	else if(strcmp(colour, "cyan")==0)
		cyan(&drawing);
	else if(strcmp(colour, "orange")==0)
		orange(&drawing);
	else if(strcmp(colour, "yellow")==0)
		yellow(&drawing);
	else if(strcmp(colour, "green")==0)
		green(&drawing);
	else if(strcmp(colour, "red")==0)
		red(&drawing);
	else if(strcmp(colour, "blue")==0)
		blue(&drawing);
	else
		printf("Not a valid colour");
}

//Drawing functions based on colour (Define RGB values, then write RGB pixel)
void red(int **drawing){
	char unsigned red = 255;
	char unsigned green = 0;
	char unsigned blue = 0;
	write(**drawing, &red, 1);
	write(**drawing, &green, 1);
	write(**drawing, &blue, 1);
}
void blue(int **drawing){
	char unsigned red = 0;
	char unsigned green = 0;
	char unsigned blue = 255;
	write(**drawing, &red, 1);
	write(**drawing, &green, 1);
	write(**drawing, &blue, 1);
}
void green(int **drawing){
	char unsigned red = 0;
	char unsigned green = 255;
	char unsigned blue = 0;
	write(**drawing, &red, 1);
	write(**drawing, &green, 1);
	write(**drawing, &blue, 1);
}
void yellow(int **drawing){
	char unsigned red = 255;
	char unsigned green = 255;
	char unsigned blue = 0;
	write(**drawing, &red, 1);
	write(**drawing, &green, 1);
	write(**drawing, &blue, 1);
}
void orange(int **drawing){
	char unsigned red = 255;
	char unsigned green = 153;
	char unsigned blue = 0;
	write(**drawing, &red, 1);
	write(**drawing, &green, 1);
	write(**drawing, &blue, 1);
}
void cyan(int **drawing){
	char unsigned red = 0;
	char unsigned green = 255;
	char unsigned blue = 255;
	write(**drawing, &red, 1);
	write(**drawing, &green, 1);
	write(**drawing, &blue, 1);
}
void magenta(int **drawing){
	char unsigned red = 255;
	char unsigned green = 0;
	char unsigned blue = 255;
	write(**drawing, &red, 1);
	write(**drawing, &green, 1);
	write(**drawing, &blue, 1);
}
void ocean(int **drawing){
	char unsigned red = 0;
	char unsigned green = 119;
	char unsigned blue = 190;
	write(**drawing, &red, 1);
	write(**drawing, &green, 1);
	write(**drawing, &blue, 1);
}
void violet(int **drawing){
	char unsigned red = 138;
	char unsigned green = 43;
	char unsigned blue = 226;
	write(**drawing, &red, 1);
	write(**drawing, &green, 1);
	write(**drawing, &blue, 1);
}