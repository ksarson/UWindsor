/* CONFIDENTIALITY AGREEMENT & STATEMENT OF HONESTY
   I confirm that I will keep the content of this assignment/examination
   confidential.  I confirm that I have not recieved any unauthorized
   assistnace in preparing for or doing this assignment/examination.
   I confirm knowing that a mark of 0 may be assigned for copied work.
   Name:  Kolby Sarson
   Student Number:  104232327
   Lecture Section:  01
   Lab Section:  52
   Date:  Oct. 11, 2015 */

// Comments for Tracing
   
#include <stdio.h>
#include <math.h>

/* Global Variables */
float c1, c2, c3; 
float f1, f2, f3; 
float CtoF1, CtoF2, CtoF3; 
float FtoC1, FtoC2, FtoC3; 

/* Function Prototypes */ 
void Calc_Celcius(); 
void Calc_Fahrenheit();
void PrintAll();

/* Main Funtion */
int main(void)
{
	/* Instructions */
	printf("\nPlease type the three Fahrenheit temperatures to be converted to \nCelcius: \n");
	scanf("%f %f %f", &f1, &f2, &f3); // f1 = 68, f2 = -40, f3 = 100
	printf("Please type the three Celcius temperatures to be converted to \nFahrenheit: \n");
	scanf("%f %f %f", &c1, &c2, &c3); // c1 = 0, c2 = -40, c3 = 20

	/* Function Calls */
	Calc_Celcius (); // Calculates all Fahrenheit to Celcius Conversions
	Calc_Fahrenheit (); // Calculates all Celcius to Fahrenheit Conversions
	PrintAll (); // Prints all data in tabular form

    return 0;
}

/* Function Definitions */
void Calc_Celcius () 
{
	FtoC1 = (5.0 / 9.0 * (f1 - 32)); // (FtoC1 = 20.00 for f1 = 68)
	FtoC2 = (5.0 / 9.0 * (f2 - 32)); // (FtoC2 = -40.00 for f2 = -40)
	FtoC3 = (5.0 / 9.0 * (f3 - 32)); // (FtoC3 = 37.78 for f3 = 100)
}

void Calc_Fahrenheit ()
{
	CtoF1 = 9.0 / 5.0 * c1 + 32; // (CtoF1 = 32.00 for c1 = 0)  
	CtoF2 = 9.0 / 5.0 * c2 + 32; // (CtoF2 = -40.00 for c2 = -40)
	CtoF3 = 9.0 / 5.0 * c3 + 32; // (CtoF3 = 68.00 for c3 = 20)
}

void PrintAll ()
{
	printf("\nThe Temperature Conversions from Fahrenheit to Celcius are\n\n");
	printf("\tFahrenheit\t|\tCelcius\n");
	printf("**************************************************\n");
	printf("\t%0.2f\t\t|\t%0.2f\n", f1, FtoC1); // f1 = 68.00, FtoC1 = 20.00
	printf("\t%0.2f\t\t|\t%0.2f\n", f2, FtoC2); // f2 = -40.00, FtoC2 = -40.00
	printf("\t%0.2f\t\t|\t%0.2f\n", f3, FtoC3); // f3 = 100.00, FtoC3 = 37.78
	printf("**************************************************\n");
	printf("\nThe Temperature Conversions from Celcius to Fahrenheit are\n\n");
	printf("\tCelcius\t\t|\tFahrenheit\n");
	printf("*************************************************\n");
	printf("\t%0.2f\t\t|\t%0.2f\n", c1, CtoF1); // c1 = 0.00, CtoF1 = 32.00
	printf("\t%0.2f\t\t|\t%0.2f\n", c2, CtoF2); // c2 = -40.00, CtoF2 = -40.00
	printf("\t%0.2f\t\t|\t%0.2f\n", c3, CtoF3); // c3 = 20.00, CtoF3 = 68.00
	printf("**************************************************\n\n");
	printf("Thank You for Using the UWin_60-140 Temperature Conversion System!!\n");
	printf("Have a Nice Day and Come Again!!\n\n");
}