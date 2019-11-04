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

/* Function Prototypes */ 
void Calc_Celcius(float, float *); 
void Calc_Fahrenheit(float, float *);
void PrintAll(float, float, float, float, float, float, float, float, float, float, float, float);

/* Main Funtion */
int main(void)
{
	float c1, c2, c3; 
	float f1, f2, f3; 
	float CtoF1, CtoF2, CtoF3; 
	float FtoC1, FtoC2, FtoC3; 

	/* Instructions */
	printf("\nPlease type the three Fahrenheit temperatures to be converted to \nCelcius: \n");
	scanf("%f %f %f", &f1, &f2, &f3); // f1 = 68, f2 = -40, f3 = 100
	printf("Please type the three Celcius temperatures to be converted to \nFahrenheit: \n");
	scanf("%f %f %f", &c1, &c2, &c3); // c1 = 0, c2 = -40, c3 = 20

	/* Function Calls */
	Calc_Celcius (f1, &FtoC1); // f1 = 68, FtoC1 = 20.00
	Calc_Celcius (f2, &FtoC2); // f2 = -40, FtoC2 = -40.00
	Calc_Celcius (f3, &FtoC3); // f3 = 100, FtoC3 = 37.78
	Calc_Fahrenheit (c1, &CtoF1); // c1 = 0, CtoF1 = 32.00
	Calc_Fahrenheit (c2, &CtoF2); // c2 = -40, CtoF2 = -40.00
	Calc_Fahrenheit (c3, &CtoF3); // c3 = 20, CtoF3 = 68.00
	PrintAll (f1, FtoC1, f2, FtoC2, f3, FtoC3, c1, CtoF1, c2, CtoF2, c3, CtoF3); // Prints all data in tabular form

    return 0;
}

/* Function Definitions */
void Calc_Celcius (float fahr, float *celcius) // Accepts a value for degrees fahrenheit and calculates and assigns degrees celcius to second parameter
{
	*celcius = (5.0 / 9.0 * (fahr - 32)); // (FtoC1 = 20.00 for f1 = 68),  (FtoC2 = -40.00 for f2 = -40),  (FtoC3 = 37.78 for f3 = 100)
}

void Calc_Fahrenheit (float celcius, float *fahr) // Accepts a value for degrees celcius and calculates and assigns degrees fahrenheit to second parameter
{
	*fahr = 9.0 / 5.0 * celcius + 32; // (CtoF1 = 32.00 for c1 = 0),  (CtoF2 = -40.00 for c2 = -40),  (CtoF3 = 68.00 for c3 = 20)
}

void PrintAll (float f1, float FtoC1, float f2, float FtoC2, float f3, float FtoC3, float c1, float CtoF1, float c2, float CtoF2, float c3, float CtoF3)
	// Accepts all values of inputted fahrenheit and celcius temperatures as well as their converted equivilancies and prints them in tabular form
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