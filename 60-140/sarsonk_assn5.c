/* CONFIDENTIALITY AGREEMENT & STATEMENT OF HONESTY
   I confirm that I will keep the content of this assignment/examination
   confidential.  I confirm that I have not recieved any unauthorized
   assistnace in preparing for or doing this assignment/examination.
   I confirm knowing that a mark of 0 may be assigned for copied work.
   Name:  Kolby Sarson
   Student Number:  104232327
   Lecture Section:  01
   Lab Section:  52
   Date:  Nov. 8, 2015 */

// Comments for Tracing
   
#include <stdio.h>

int Tax_Bracket_Identification(float);
void Tax_Calculation(float, int, float *);
void PrintAll (int, float);

int main(void)
{
	int numIncomes;
	float income, tax;
	int bracket;

	int x = 1;

	printf("\nPlease type in the number of incomes to be processed:\t");
	scanf("%d", &numIncomes);

	while (x <= numIncomes)
	{
		printf("\n\nPlease scan in income number %d:\t", x);
		scanf("%f", &income);
		x++;

		bracket = Tax_Bracket_Identification(income);
		Tax_Calculation(income, bracket, &tax);

		PrintAll(bracket, tax);
	}	
	printf("\n\nThank you for using our Computing tax program.");
	printf("\nPlease visit us again!!!\n\n\n");
	return 0;
}

int Tax_Bracket_Identification(float income)
{
	int bracket;

	if (income <= 10000)		
	{	
		bracket = 1;
	}
		else 
		{
			if (income <= 20000)
			{
				bracket = 2;
			}	
				else 
				{
					if (income <= 30000)
					{
						bracket = 3;
					}	
						else 
						{
							if (income <= 50000)
							{
								bracket = 4;
							}
								else
								{
									if (income <= 100000)
									{
										bracket = 5;
									}
										else 
										{
											if (income > 100000)
											{
											bracket = 6;
											}
										}
								}
						}
				}
		}									
	return bracket;
}

void Tax_Calculation(float income, int bracket, float *tax)
{
	switch(bracket)
		{
			case 1:
				*tax = income * 0.05;
				break;
			case 2:
				*tax = 500 + ((income - 10000) * 0.10);
				break;
			case 3:
				*tax = 1500 + ((income - 20000) * 0.15);
				break;
			case 4:
				*tax = 3000 + ((income - 30000) * 0.20);
				break;
			case 5:	
				*tax = 7000 + ((income - 50000) * 0.25);
				break;
			case 6:
				*tax = 19500 + ((income - 100000) * 0.30);
				break;			
		} 
}
void PrintAll (int bracket, float tax)
{
	printf("\nYour tax bracket is:\t%d", bracket);
	printf("\nYour tax is:\t\t%0.2f\n", tax);
}