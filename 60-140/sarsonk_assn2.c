/* CONFIDENTIALITY AGREEMENT & STATEMENT OF HONESTY
   I confirm that I will keep the content of this assignment/examination
   confidential.  I confirm that I have not recieved any unauthorized
   assistnace in preparing for or doing this assignment/examination.
   I confirm knowing that a mark of 0 may be assigned for copied work.
   Name:  Kolby Sarson
   Student Number:  104232327
   Lecture Section:  01
   Lab Section:  52
   Date:  Sept. 26, 2015 */

#include <stdio.h>
#include <math.h>

int main(void)
{
	float yardL, yardW;
	float houseL, houseW;
	float yardAF, yardAM;
	float houseAF, houseAM;
	float grassAF, grassAM;
	float yardPF, yardPM;
	float housePF, housePM;
	int totalseconds;
	float hours, minutes, seconds;

	/* Instructions */ 
	printf("\nWhat is the length of the rectangular yard? \t \t");
	scanf("%f", &yardL); // yardL = 200
	printf("What is the width of the rectangular yard? \t \t");
	scanf("%f", &yardW); // yardW = 100
	printf("Please scan in the length of the rectangular house \t");
	scanf("%f", &houseL); // houseL = 180
	printf("Please scan in the width of the rectangular house \t");
	scanf ("%f", &houseW); // houseW = 80

	yardAF = yardL * yardW; // yardAF = 200 * 100 = 20000.00
	yardAM = (yardL * 0.3048) * (yardW * 0.3048); // yardAM = (200 * 0.3048) * (100 * 0.3048) = 1858.06
	houseAF = houseL * houseW; // houseAF = 180 * 80 = 14400.00
	houseAM = (houseL * 0.3048) * (houseW * 0.3048); // houseAM = (180 * 0.3048) * (80 * 0.3048) = 1337.80
	grassAF = yardAF - houseAF; // grassAF = 20000 - 14400 = 5600.00
	grassAM = yardAM - houseAM; // grassAM = 1858.06 - 1337.80 = 520.26
	yardPF = 2 * (yardL + yardW); // yardPF = 2 * (200 + 100) = 600.00
	yardPM = 2 * ((yardL * 0.3048) + (yardW * 0.3048)); // yardPM = 2 * (200 * 0.3048 + 100 * 0.3048) = 182.88
	housePF = 2 * (houseL + houseW); // housePF = 2 * (180 + 80) = 520.00
	housePM = 2 * ((houseL * 0.3048) + (houseW * 0.3048)); // housePM = 2 * (180 * 0.3048 + 80 * 0.3048) = 158.50
	totalseconds = grassAF / 2; // totalseconds = 5600.00 / 2 = 2800.00
	hours = totalseconds / 3600; // hours = 2800.00 / 3600 = 0
	minutes = (totalseconds / 60) - (hours * 60); // minutes = (2800.00 / 60) - (0 * 60) = 46
	seconds = totalseconds - (minutes * 60) - (hours * 3600); // seconds = 2800.00 - (46 * 60) - (0 * 3600) = 40

	printf ("\nThe time required to cut the grass in the yeard is:  ");
	printf ("\t%0.0f hours %0.0f minutes %0.0f seconds \n", hours, minutes, seconds); // 0, 46, 40
	printf ("The area of the yard in square feet is:  \t\t%0.2f sq. ft. \n", yardAF); // 20000.00
	printf ("The area of the yard in square meters is:  \t\t%0.2f sq. meter. \n", yardAM); // 1858.06
	printf ("The area of the house in square feet is:  \t\t%0.2f sq. ft. \n", houseAF); // 14400.00
	printf ("The area of the house in square meters is:  \t\t%0.2f sq. meter. \n", houseAM); // 1337.80
	printf ("The area of the grass area in square feet is:  \t\t%0.2f sq. ft. \n", grassAF); // 5600.00
	printf ("The area of the grass area in square meters is:  \t%0.2f sq. meter. \n \n", grassAM); // 520.26

	printf ("The perimeter of the yard in feet is:  \t\t%0.2f ft. \n", yardPF); // 600.00
	printf ("The perimeter of the yard in meters is:  \t%0.2f meter. \n", yardPM); // 182.88
	printf ("The perimeter of the house in feet is:  \t%0.2f ft. \n", housePF); // 520.00
	printf ("The perimeter of the house in meters is:  \t%0.2f meter. \n \n", housePM); // 158.50

	printf ("Thank you for using our property evaluation software!! \n \n");
	printf ("Have a great day! \n \n");


    return 0;
}