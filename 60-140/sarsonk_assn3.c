/* CONFIDENTIALITY AGREEMENT & STATEMENT OF HONESTY
   I confirm that I will keep the content of this assignment/examination
   confidential.  I confirm that I have not recieved any unauthorized
   assistnace in preparing for or doing this assignment/examination.
   I confirm knowing that a mark of 0 may be assigned for copied work.
   Name:  Kolby Sarson
   Student Number:  104232327
   Lecture Section:  01
   Lab Section:  52
   Date:  Oct. 10, 2015 */

#include <stdio.h>
#include <math.h>

/* Function Prototypes */ 
float Calc_Celcius(float); 
float Calc_Fahrenheit(float);
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
	FtoC1 = Calc_Celcius (f1); // ftoC1 = 20.00
	FtoC2 = Calc_Celcius (f2); // ftoC2 = -40.00
	FtoC3 = Calc_Celcius (f3); // ftoC3 = 37.78
	CtoF1 = Calc_Fahrenheit (c1); // ftoC1 = 32.00
	CtoF2 = Calc_Fahrenheit (c2); // ftoC2 = -40.00
	CtoF3 = Calc_Fahrenheit (c3); // ftoC3 = 68.00
	PrintAll (f1, FtoC1, f2, FtoC2, f3, FtoC3, c1, CtoF1, c2, CtoF2, c3, CtoF3); // Prints all data in tabular form

    return 0;
}

/* Function Definitions */
float Calc_Celcius (float fahr) // Accepts a value for degrees fahrenheit and calculates degrees celcius
{
	return (5.0 / 9.0 * (fahr - 32)); // (FtoC1 = 20.00 for f1 = 68),  (FtoC2 = -40.00 for f2 = -40)  (FtoC3 = 37.78 for f3 = 100)
}

float Calc_Fahrenheit (float celcius) // Accepts a value for degrees celcius and calculates degrees fahrenheit
{
	return (9.0 / 5.0 * celcius + 32); // (CtoF1 = 32.00 for c1 = 0),  (CtoF2 = -40.00 for c2 = -40)  (CtoF3 = 68.00 for c3 = 20)
}

void PrintAll (float f1, float FtoC1, float f2, float FtoC2, float f3, float FtoC3, float c1, float CtoF1, float c2, float CtoF2, float c3, float CtoF3)
	// Accepts all values of inputted fahrenheit and celcius temperatures as well as their converted equivilancies and prints them in tabular form
{
	printf("\nThe Temperature Conversions from Fahrenheit to Celcius are\n\n");
	printf("\tFahrenheit\t|\tCelcius\n");
	printf("**************************************************\n");
	printf("\t%0.2f\t\t|\t%0.2f\n", f1, FtoC1); // f1 = 68.00 and FtoC1 = 20.00
	printf("\t%0.2f\t\t|\t%0.2f\n", f2, FtoC2); // f2 = -40.00 and FtoC2 = -40.00
	printf("\t%0.2f\t\t|\t%0.2f\n", f3, FtoC3); // f3 = 100.00 and FtoC3 = 37.78
	printf("**************************************************\n");
	printf("\nThe Temperature Conversions from Celcius to Fahrenheit are\n\n");
	printf("\tCelcius\t\t|\tFahrenheit\n");
	printf("*************************************************\n");
	printf("\t%0.2f\t\t|\t%0.2f\n", c1, CtoF1); // f1 = 0.00 and FtoC1 = 32.00
	printf("\t%0.2f\t\t|\t%0.2f\n", c2, CtoF2); // f1 = -40.00 and FtoC1 = -40.00
	printf("\t%0.2f\t\t|\t%0.2f\n", c3, CtoF3); // f1 = 20.00 and FtoC1 = 68.00
	printf("**************************************************\n\n");
	printf("Thank You for Using the UWin_60-140 Temperature Conversion System!!\n");
	printf("Have a Nice Day and Come Again!!\n\n");
}