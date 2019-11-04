/*
Tara Vulakovich
Assignment 2
Oct 26th 2017
**sleep is set to 2 only because file takes a long time to compile!**
*/

#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
 
int main(int argc, char **argv){
	
	unsigned char center[3];
	unsigned char topleft[3];
	unsigned char topright[3];
	unsigned char bottomleft[3];
	unsigned char bottomright[3];

	char name[] = "P6\n1000 1000\n255\n";

    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, S_IXUSR | S_IRUSR | S_IWUSR);

	write(fd, &name, 17);
	
	//Center 
	if(strcmp(argv[2],"red")==0){
		center[0] = 255; center[1] = 0; center[2] = 0;
	}
	else if(strcmp(argv[2],"green")==0){
		center[0] = 0; center[1] = 255; center[2] = 0;
	}
	else if(strcmp(argv[2],"blue")==0){
		center[0] = 0; center[1] = 0; center[2] = 255;
	}
	else if(strcmp(argv[2],"yellow")==0){
		center[0] = 255; center[1] = 255; center[2] = 0;
	}
	else if(strcmp(argv[2],"orange")==0){
		center[0] = 255; center[1] = 165; center[2] = 0;
	}
	else if(strcmp(argv[2],"cyan")==0){
		center[0] = 0; center[1] = 255; center[2] = 255;
	}
	else if(strcmp(argv[2],"magenta")==0){
		center[0] = 255; center[1] = 0; center[2] = 255;
	}
	else if(strcmp(argv[2],"ocean")==0){
		center[0] = 78; center[1] = 119; center[2] = 229;
	}
	else if(strcmp(argv[2],"violet")==0){
		center[0] = 238; center[1] = 130; center[2] = 238;
	}

	//Top left
	if(strcmp(argv[3],"red")==0){
		topleft[0] = 255; topleft[1] = 0; topleft[2] = 0;
	}
	else if(strcmp(argv[3],"green")==0){
		topleft[0] = 0; topleft[1] = 255; topleft[2] = 0;
	}
	else if(strcmp(argv[3],"blue")==0){
		topleft[0] = 0; topleft[1] = 0; topleft[2] = 255;
	}
	else if(strcmp(argv[3],"yellow")==0){
		topleft[0] = 255; topleft[1] = 255; topleft[2] = 0;
	}
	else if(strcmp(argv[3],"orange")==0){
		topleft[0] = 255; topleft[1] = 165; topleft[2] = 0;
	}
	else if(strcmp(argv[3],"cyan")==0){
		topleft[0] = 0; topleft[1] = 255; topleft[2] = 255;
	}
	else if(strcmp(argv[3],"magenta")==0){
		topleft[0] = 255; topleft[1] = 0; topleft[2] = 255;
	}
	else if(strcmp(argv[3],"ocean")==0){
		topleft[0] = 78; topleft[1] = 119; topleft[2] = 229;
	}
	else if(strcmp(argv[3],"violet")==0){
		topleft[0] = 238; topleft[1] = 130; topleft[2] = 238;
	}

	//Top right
	if(strcmp(argv[4],"red")==0){
		topright[0] = 255; topright[1] = 0; topright[2] = 0;
	}
	else if(strcmp(argv[4],"green")==0){
		topright[0] = 0; topright[1] = 255; topright[2] = 0;
	}
	else if(strcmp(argv[4],"blue")==0){
		topright[0] = 0; topright[1] = 0; topright[2] = 255;
	}
	else if(strcmp(argv[4],"yellow")==0){
		topright[0] = 255; topright[1] = 255; topright[2] = 0;
	}
	else if(strcmp(argv[4],"orange")==0){
		topright[0] = 255; topright[1] = 165; topright[2] = 0;
	}
	else if(strcmp(argv[4],"cyan")==0){
		topright[0] = 0; topright[1] = 255; topright[2] = 255;
	}
	else if(strcmp(argv[4],"magenta")==0){
		topright[0] = 255; topright[1] = 0; topright[2] = 255;
	}
	else if(strcmp(argv[4],"ocean")==0){
		topright[0] = 78; topright[1] = 119; topright[2] = 229;
	}
	else if(strcmp(argv[4],"violet")==0){
		topright[0] = 238; topright[1] = 130; topright[2] = 238;
	}

	//Bottom left
	if(strcmp(argv[5],"red")==0){
		bottomleft[0] = 255; bottomleft[1] = 0; bottomleft[2] = 0;
	}
	else if(strcmp(argv[5],"green")==0){
		bottomleft[0] = 0; bottomleft[1] = 255; bottomleft[2] = 0;
	}
	else if(strcmp(argv[5],"blue")==0){
		bottomleft[0] = 0; bottomleft[1] = 0; bottomleft[2] = 255;
	}
	else if(strcmp(argv[5],"yellow")==0){
		bottomleft[0] = 255; bottomleft[1] = 255; bottomleft[2] = 0;
	}
	else if(strcmp(argv[5],"orange")==0){
		bottomleft[0] = 255; bottomleft[1] = 165; bottomleft[2] = 0;
	}
	else if(strcmp(argv[5],"cyan")==0){
		bottomleft[0] = 0; bottomleft[1] = 255; bottomleft[2] = 255;
	}
	else if(strcmp(argv[5],"magenta")==0){
		bottomleft[0] = 255; bottomleft[1] = 0; bottomleft[2] = 255;
	}
	else if(strcmp(argv[5],"ocean")==0){
		bottomleft[0] = 78; bottomleft[1] = 119; bottomleft[2] = 229;
	}
	else if(strcmp(argv[5],"violet")==0){
		bottomleft[0] = 238; bottomleft[1] = 130; bottomleft[2] = 238;
	}

	//Bottom right
	if(strcmp(argv[6],"red")==0){
		bottomright[0] = 255; bottomright[1] = 0; bottomright[2] = 0;
	}
	else if(strcmp(argv[6],"green")==0){
		bottomright[0] = 0; bottomright[1] = 255; bottomright[2] = 0;
	}
	else if(strcmp(argv[6],"blue")==0){
		bottomright[0] = 0; bottomright[1] = 0; bottomright[2] = 255;
	}
	else if(strcmp(argv[6],"yellow")==0){
		bottomright[0] = 255; bottomright[1] = 255; bottomright[2] = 0;
	}
	else if(strcmp(argv[6],"orange")==0){
		bottomright[0] = 255; bottomright[1] = 165; bottomright[2] = 0;
	}
	else if(strcmp(argv[6],"cyan")==0){
		bottomright[0] = 0; bottomright[1] = 255; bottomright[2] = 255;
	}
	else if(strcmp(argv[6],"magenta")==0){
		bottomright[0] = 255; bottomright[1] = 0; bottomright[2] = 255;
	}
	else if(strcmp(argv[6],"ocean")==0){
		bottomright[0] = 78; bottomright[1] = 119; bottomright[2] = 229;
	}
	else if(strcmp(argv[6],"violet")==0){
		bottomright[0] = 238; bottomright[1] = 130; bottomright[2] = 238;
	}
	
	static unsigned char colour[3];
		
	//child 1
	if (fork() == 0){
		sleep(1);
		for (int i= 0; i < 100; i++){
			for(int j = 0; j<1000;j++){
				if (j<500){
					write(fd, topleft, 3);
				}
				else{
					write(fd, topright,3);
				}
			}
		}
		//child 2
		if (fork()==0){
			sleep(2);
			for (int i= 0; i < 100; i++){
				for(int j = 0; j<1000;j++){
					if (j<500){
						write(fd, topleft, 3);
					}
					else{
						write(fd, topright,3);
					}
				}
			}
			//child 3
			if (fork()==0){
				sleep(2);
				int counter=0;
				for (int i = 0; i < 100; i++){
					for(int j = 0; j<1000;j++){
						if(i<50){
							if (j<500){
								write(fd, topleft, 3);
							}
							else{
								write(fd, topright,3);
							}
						}
						else{
							if(j<500-counter){
								write(fd,topleft,3);
							}
							else if(j> 500+counter){
								write(fd,topright,3);
							}
							else{
								write(fd,center,3);
							}
						}	
						
					}
					if (i>=50) counter++;
				}
				//child 4
				if (fork()==0){
					sleep(2);
					for (int i = 0; i < 100; i++){
						for(int j = 0; j<1000;j++){
							if(j<500-counter){
								write(fd,topleft,3);
							}
							else if(j> 500+counter){
								write(fd,topright,3);
							}
							else{
								write(fd,center,3);
							}	
							
						}
						counter++;
					}
					//child 5
					if (fork()==0){
						sleep(2);
						for (int i = 0; i < 100; i++){
							for(int j = 0; j<1000;j++){
								if(j<500-counter){
									write(fd,topleft,3);
								}
								else if(j> 500+counter){
									write(fd,topright,3);
								}
								else{
									write(fd,center,3);
								}	
								
							}
							counter++;
						}
						//child 6
						if (fork()==0){
							sleep(2);
							for (int i = 0; i < 100; i++){
								for(int j = 0; j<1000;j++){
									if(j<500-counter){
										write(fd,bottomleft,3);
									}
									else if(j> 500+counter){
										write(fd,bottomright,3);
									}
									else{
										write(fd,center,3);
									}	
									
								}
								counter--;
							}
							//child 7
							if (fork()==0){
								sleep(2);
								for (int i = 0; i < 100; i++){
									for(int j = 0; j<1000;j++){
										if(j<500-counter){
											write(fd,bottomleft,3);
										}
										else if(j> 500+counter){
											write(fd,bottomright,3);
										}
										else{
											write(fd,center,3);
										}	
										
									}
									counter--;
								}
								//child 8
								if (fork()==0){
									sleep(2);
									for (int i = 0; i < 100; i++){
										for(int j = 0; j<1000;j++){
											if(i>50){
												if (j<500){
													write(fd, bottomleft, 3);
												}
												else{
													write(fd, bottomright,3);
												}
											}
											else{
												if(j<500-counter){
													write(fd,bottomleft,3);
												}
												else if(j> 500+counter){
													write(fd,bottomright,3);
												}
												else{
													write(fd,center,3);
												}
											}	
											
										}
										if (i<50) counter--;
									}
									//child 9
									if (fork()==0){
										sleep(2);
										for (int i= 0; i < 100; i++){
											for(int j = 0; j<1000;j++){
												if (j<500){
													write(fd, bottomleft, 3);
												}
												else{
													write(fd, bottomright,3);
												}
											}
										}
										//child 10
										if (fork()==0){
											sleep(2);
											for (int i= 0; i < 100; i++){
												for(int j = 0; j<1000;j++){
													if (j<500){
														write(fd, bottomleft, 3);
													}
													else{
														write(fd, bottomright,3);
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	close(fd);
}
