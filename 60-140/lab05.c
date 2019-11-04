/*#include <stdio.h>

int main(void)
{
	float days, miles;
	float ConstMiles;

	scanf("%d %d", &days, &miles);

	ConstMiles = miles * 0.15;

	if (ConstMiles > (10 * days))
	{
		printf("Plan A is better");
	}
	else 
	{
		printf("Plan B is better");
	}

	return 0;
}*/

#include <stdio.h>

int TaxBracket(float);

int main(void)
{
	float income;
	float tax;
	int bracket;

	scanf("%f", &income);

	bracket = TaxBracket(income);
    printf("%d\n", bracket );
	switch(bracket)
	{
		case 1:
			tax = income * 0.50;
			break;

		case 2:
			tax = income * 0.36;
			break;
			
		case 3:
			tax = income * 0.30;
			break;
			
		case 4:
			tax = income * 0.20;
			break;
			
		case 5:
			tax = income * 0.10;
			break;

		case 6:
			tax = income * 0.00;
			break;
	} 
		printf("Your income tax is %f", tax);
	return 0;
}

int TaxBracket(float income)
{
	int bracket;

	if (income >= 200000.00)
	{
		bracket = 1;
	}
	else if (150000.00 <= income < 200000.00)
	{
		bracket = 2;
	}
	else if (100000.00 <= income < 150000.00)
	{
		bracket = 3;
	}	
	else if (50000.00 <= income < 100000.00)
	{
		bracket = 4;
	}
	else if (20000.00 <= income < 50000.00)
	{
		bracket = 5;
	}
	else if (income < 20000.00)		
	{
		bracket = 6;
	}	
	return bracket;
}