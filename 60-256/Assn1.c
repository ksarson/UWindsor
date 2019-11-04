/*
Name:	Kolby Sarson
ID:		104232327
Due:	October 8, 2017
Item:	Assingment 1
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
 
void merge(int*, int*, int*, int*, int*);
void dimensions(int*, int*, int*);
 
int main(int argc, char **argv){
    int w1=0, h1=0, w2=0, h2=0;

    //Open image files
    int firstFile=open(argv[1], O_RDWR);
    int secondFile=open(argv[2], O_RDWR);

    //Start at measument positions
    lseek(firstFile, 3, SEEK_SET);
    lseek(secondFile, 3, SEEK_SET);

    //Get dimensions
    dimensions(&w1, &h1, &firstFile);
    dimensions(&w2, &h2, &secondFile);


    //Terminate if second picture is wider or taller than first
    if(w1<w2 || h1<h2)
        return 0;

    //Move beyond graphics maximum line
    lseek(firstFile, 4, SEEK_CUR);
    lseek(secondFile, 4, SEEK_CUR);

    //Merge images
    merge(&w1, &w2, &h2, &firstFile, &secondFile);

    //Change first image's file name
    link(argv[1], argv[3]);

    //Remove first image file
    unlink(argv[1]);

    //Close images
    close(firstFile);
    close(secondFile);
   
}
 
void dimensions(int*width, int*height, int*file){
    int decimal=0, whCounter=0, sizew=0 ,sizeh=0, widthArray[10]={0}, heightArray[10]={0};
    
    //Taking ASCII values of width and height into arrays
    while(decimal!=10){
        read(*file, &decimal, 1);

        ////ASCII space character represents changing from width to height
        if (decimal==32)
            whCounter=1;

        //ASCII new line character represents end of width and height
        else if (decimal==10)
            break;

        //Width Array
        else if (!whCounter){
            widthArray[sizew]=decimal-48;
            sizew++;
        }

        //Height Array
        else{
            heightArray[sizeh]=decimal-48;
            sizeh++;
        }
    }

    //Convert width array to width value
    for (int i=0; i<sizew; i++){
        *width = 10*(*width)+widthArray[i];
    }
    //Converting height array to height value
    for (int i=0; i<sizeh; i++){
        *height = 10*(*height)+heightArray[i];
    }
}
 
void merge(int*width1, int*width2, int*height2, int*firstFile, int*secondFile){
    int tempByte=0;

    //Loops for pixel height
    for(int i=0; i<*height2; i++){

        //Seeks top left corner of second image 
        //(3bytes per pixel in .ppm)
        lseek(*firstFile, (*width1-*width2)*3, SEEK_CUR);

        //Copy secondFile to firstFile byte by byte
        //from previously found corner ^
        for (int j=0; j<*width2*3; j++){
            read(*secondFile, &tempByte, 1);
            write(*firstFile, &tempByte, 1);
        }
    }
}