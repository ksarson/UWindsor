/*
Name:	Kolby Sarson
ID:		104232327
Due:	October 29, 2017
Item:	Assingment 2
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
 
int main(int argc, char **argv){
	const int height = 1000;
	const int width = 1000;
	const int hSize = 17;

	/*
	Colours
	Red: 255,0,0
	Green: 0,128,0
	Blue: 0,0,255
	Yellow: 255,255,0
	Orange: 255,165,0
	Cyan: 0,255,255
	Magenta: 255,0,255
	Ocean: 78,119,229
	Violet: 238,130,238
	*/

	unsigned char CValueR, CValueG, CValueB;
	unsigned char TLValueR, TLValueG, TLValueB;
	unsigned char TRValueR, TRValueG, TRValueB;
	unsigned char BLValueR, BLValueG, BLValueB;
	unsigned char BRValueR, BRValueG, BRValueB;

	//Center corner
	if(strcmp(argv[2],"red")==0){
		CValueR = 255; CValueG = 0; CValueB = 0;
	}
	else if(strcmp(argv[2],"green")==0){
		CValueR = 0; CValueG = 255; CValueB = 0;
	}
	else if(strcmp(argv[2],"blue")==0){
		CValueR = 0; CValueG = 0; CValueB = 255;
	}
	else if(strcmp(argv[2],"yellow")==0){
		CValueR = 255; CValueG = 255; CValueB = 0;
	}
	else if(strcmp(argv[2],"orange")==0){
		CValueR = 255; CValueG = 165; CValueB = 0;
	}
	else if(strcmp(argv[2],"cyan")==0){
		CValueR = 0; CValueG = 255; CValueB = 255;
	}
	else if(strcmp(argv[2],"magenta")==0){
		CValueR = 255; CValueG = 0; CValueB = 255;
	}
	else if(strcmp(argv[2],"ocean")==0){
		CValueR = 78; CValueG = 119; CValueB = 229;
	}
	else if(strcmp(argv[2],"violet")==0){
		CValueR = 238; CValueG = 130; CValueB = 238;
	}

	//Top left corner
	if(strcmp(argv[3],"red")==0){
		TLValueR = 255; TLValueG = 0; TLValueB = 0;
	}
	else if(strcmp(argv[3],"green")==0){
		TLValueR = 0; TLValueG = 255; TLValueB = 0;
	}
	else if(strcmp(argv[3],"blue")==0){
		TLValueR = 0; TLValueG = 0; TLValueB = 255;
	}
	else if(strcmp(argv[3],"yellow")==0){
		TLValueR = 255; TLValueG = 255; TLValueB = 0;
	}
	else if(strcmp(argv[3],"orange")==0){
		TLValueR = 255; TLValueG = 165; TLValueB = 0;
	}
	else if(strcmp(argv[3],"cyan")==0){
		TLValueR = 0; TLValueG = 255; TLValueB = 255;
	}
	else if(strcmp(argv[3],"magenta")==0){
		TLValueR = 255; TLValueG = 0; TLValueB = 255;
	}
	else if(strcmp(argv[3],"ocean")==0){
		TLValueR = 78; TLValueG = 119; TLValueB = 229;
	}
	else if(strcmp(argv[3],"violet")==0){
		TLValueR = 238; TLValueG = 130; TLValueB = 238;
	}

	//Top right corner
	if(strcmp(argv[4],"red")==0){
		TRValueR = 255; TRValueG = 0; TRValueB = 0;
	}
	else if(strcmp(argv[4],"green")==0){
		TRValueR = 0; TRValueG = 255; TRValueB = 0;
	}
	else if(strcmp(argv[4],"blue")==0){
		TRValueR = 0; TRValueG = 0; TRValueB = 255;
	}
	else if(strcmp(argv[4],"yellow")==0){
		TRValueR = 255; TRValueG = 255; TRValueB = 0;
	}
	else if(strcmp(argv[4],"orange")==0){
		TRValueR = 255; TRValueG = 165; TRValueB = 0;
	}
	else if(strcmp(argv[4],"cyan")==0){
		TRValueR = 0; TRValueG = 255; TRValueB = 255;
	}
	else if(strcmp(argv[4],"magenta")==0){
		TRValueR = 255; TRValueG = 0; TRValueB = 255;
	}
	else if(strcmp(argv[4],"ocean")==0){
		TRValueR = 78; TRValueG = 119; TRValueB = 229;
	}
	else if(strcmp(argv[4],"violet")==0){
		TRValueR = 238; TRValueG = 130; TRValueB = 238;
	}

	//Bottom left corner
	if(strcmp(argv[5],"red")==0){
		BLValueR = 255; BLValueG = 0; BLValueB = 0;
	}
	else if(strcmp(argv[5],"green")==0){
		BLValueR = 0; BLValueG = 255; BLValueB = 0;
	}
	else if(strcmp(argv[5],"blue")==0){
		BLValueR = 0; BLValueG = 0; BLValueB = 255;
	}
	else if(strcmp(argv[5],"yellow")==0){
		BLValueR = 255; BLValueG = 255; BLValueB = 0;
	}
	else if(strcmp(argv[5],"orange")==0){
		BLValueR = 255; BLValueG = 165; BLValueB = 0;
	}
	else if(strcmp(argv[5],"cyan")==0){
		BLValueR = 0; BLValueG = 255; BLValueB = 255;
	}
	else if(strcmp(argv[5],"magenta")==0){
		BLValueR = 255; BLValueG = 0; BLValueB = 255;
	}
	else if(strcmp(argv[5],"ocean")==0){
		BLValueR = 78; BLValueG = 119; BLValueB = 229;
	}
	else if(strcmp(argv[5],"violet")==0){
		BLValueR = 238; BLValueG = 130; BLValueB = 238;
	}

	//Bottom right colour
	if(strcmp(argv[6],"red")==0){
		BRValueR = 255; BRValueG = 0; BRValueB = 0;
	}
	else if(strcmp(argv[6],"green")==0){
		BRValueR = 0; BRValueG = 255; BRValueB = 0;
	}
	else if(strcmp(argv[6],"blue")==0){
		BRValueR = 0; BRValueG = 0; BRValueB = 255;
	}
	else if(strcmp(argv[6],"yellow")==0){
		BRValueR = 255; BRValueG = 255; BRValueB = 0;
	}
	else if(strcmp(argv[6],"orange")==0){
		BRValueR = 255; BRValueG = 165; BRValueB = 0;
	}
	else if(strcmp(argv[6],"cyan")==0){
		BRValueR = 0; BRValueG = 255; BRValueB = 255;
	}
	else if(strcmp(argv[6],"magenta")==0){
		BRValueR = 255; BRValueG = 0; BRValueB = 255;
	}
	else if(strcmp(argv[6],"ocean")==0){
		BRValueR = 78; BRValueG = 119; BRValueB = 229;
	}
	else if(strcmp(argv[6],"violet")==0){
		BRValueR = 238; BRValueG = 130; BRValueB = 238;
	}

	//Array for header
	char p[hSize];
	p[0] = 'P';	p[1] = 54; p[2] = 10; p[3] = 49; p[4] = 48; p[5] = 48; 
	p[6] = 48; p[7] = 32; p[8] = 49; p[9] = 48; p[10] = 48; p[11] = 48;
	p[12] = 10; p[13] = 50; p[14] = 53; p[15] = 53; p[16] = 10;

    //Create image file
    int ppmNew=open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 7);

    //Write header to file
	write(ppmNew, p, hSize);
	int h1=250, w1=500, h2=251, w2=501, h3=501, w3=251, h4=501, w4=750;
	int temp1=250, temp2=251, temp3=501, temp4=750;
	static unsigned char colour[3];
	int next=0, endNext=100;

	//Create 10 child processes
	for(int k=0; k<10; ++k){
	    pid_t pid=fork();
	    //next=(k)*100;
	  	//endNext=next+100;
	    if(pid){
	    	sleep(5);
	    	//next=(k+1)*100;
	  		//endNext=next+100;
	  		continue;
	    } 
	    else if(pid==0){
	    	//Loop 100x1000 pixels
	    	for(int i=0; i<1000; i++){
				for(int j=0; j<width; j++){
					//Top left corner
					if(i<=500 && j<=500){
						//Check if center
						if (i>=h1 && j>=w1){
		      				colour[0] = CValueR;
		      				colour[1] = CValueG;
		      				colour[2] = CValueB;
		    				if(!(temp1==h1)){
		    					h1++;
		    					w1--;
		    				}
		    				temp1=i;
		      				write(ppmNew, colour, 3);
						}
						else{
				      		colour[0] = TLValueR;
				      		colour[1] = TLValueG;
				      		colour[2] = TLValueB;
				      		write(ppmNew, colour, 3);
			      		}
		      		}
		      		//Top right corner
		      		else if(i<=500 && j>=501){
		      			//Check if center
						if (i>=h2 && j<=w2){
		      				colour[0] = CValueR;
		      				colour[1] = CValueG;
		      				colour[2] = CValueB;
		    				if(!(temp2==h2)){
		    					h2++;
		    					w2++;
		    				}
		    				temp2=i;
		      				write(ppmNew, colour, 3);
						}
						else{
				      		colour[0] = TRValueR;
				      		colour[1] = TRValueG;
				      		colour[2] = TRValueB;
				      		write(ppmNew, colour, 3);
				      	}
		      		}
		      		//Bottom left corner
		      		else if(i>=501 && j<=501){
		      			//Check if center
						if (i<=h3 && j>=w3){
		      				colour[0] = CValueR;
		      				colour[1] = CValueG;
		      				colour[2] = CValueB;
		    				if(temp3==500){
		    					h3++;
		    					w3++;
		    					temp3=0;
		    				}
		    				temp3=j;
		      				write(ppmNew, colour, 3);
						}
						else{
				      		colour[0] = BLValueR;
				      		colour[1] = BLValueG;
				      		colour[2] = BLValueB;
				      		write(ppmNew, colour, 3);
				      	}
		      		}
		      		//Bottom right corner
		      		else if(i>=501 && j>=502){
		      			//Check if center
						if (i<=h4 && j<=w4){
		      				colour[0] = CValueR;
		      				colour[1] = CValueG;
		      				colour[2] = CValueB;
		    				if(temp4==w4){
		    					h4++;
		    					w4--;
		    				}
		    				temp4=j;
		      				write(ppmNew, colour, 3);
						}
						else{
				      		colour[0] = BRValueR;
				      		colour[1] = BRValueG;
				      		colour[2] = BRValueB;
				      		write(ppmNew, colour, 3);
			      		}
		      		}
		      	}
			}
	        break;
	    } 
	    else{
	        printf("Fork Error\n");
	        exit(1);
	    }
	}
	//Close file
	close(ppmNew);
}