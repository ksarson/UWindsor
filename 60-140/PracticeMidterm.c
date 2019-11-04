/*#include <stdio.h>

int UCeil(float);
int UFloor(float);

int main(void)
{
	float num1, num2, num3, num4;
	int ceil1, ceil2, floor1, floor2;
	int v;

	printf("\nPlease type in the values of the 4 numbers: \n");
	scanf("%f %f %f %f", &num1, &num2, &num3, &num4);

	ceil1 = UCeil(num1);
	floor1 = UFloor(num2);
	ceil2 = UCeil(num3);
	floor2 = UFloor(num4);

	v = (ceil1 + floor1 - ceil2) * floor2;

	printf("\nThe expression is:  V = (UCeil(%0.1f) + UFloor(%0.1f) - UCeil(%0.1f)) * UFloor(%0.1f)", num1, num2, num3, num4);
	printf("\nThe value of the expression V = %d\n\n", v);

	return 0;
}

int UCeil(float num)
{
	return (num + 1) / 1;
}

int UFloor(float num)
{
	return num / 1;
}*/

/*#include <stdio.h>

float FindSum(float, float);
float FindDiff(float, float);

int main(void)
{
	float x, y, u, w;
	float sum1, diff1, sum2;

	printf("\nPlease enter 4 numbers to be assigned to the variable X, Y, U and W respectively:\n");
	scanf("%f %f %f %f", &x, &y, &u, &w);

	sum1 = FindSum(x, y);
	diff1 = FindDiff(sum1, u);
	sum2 = FindSum(diff1, w);

	printf("\nThe given expression is V = X + Y - U + W or V = %0.2f + %0.2f - %0.2f + %0.2f", x, y, u, w);
	printf("\nThe value of the expression is V = %0.2f\n\n", sum2);

	return 0;
}

float FindSum(float num1, float num2)
{
	return num1 + num2;
}

float FindDiff(float num1, float num2)
{
	return num1 - num2;
}*/

/*#include <stdio.h>

float CalcSpent(float, float);

int main(void)
{
	float meg, kat;
	float megSpent, katSpent;

	float megPercent = 0.15;
	float katPercent = 0.08;

	printf("\nIf the input school money is as follows:\n");
	printf("Megan money = $");
	scanf("%f", &meg);
	printf("Katie money = $");
	scanf("%f", &kat);

	megSpent = CalcSpent(meg, megPercent);
	katSpent = CalcSpent(kat, katPercent);

	printf("\nAmount spent on clothing by each student:");
	printf("\nMegan\t$%0.2f", megSpent);
	printf("\nKatie\t$%0.2f\n\n", katSpent);

	return 0;
}

float CalcSpent(float money, float percent)
{
	return money * percent;
}*/

/*#include <stdio.h>

float CalcSum(float);

int main(void)
{
	float num1, num2;
	float sum1, sum2;
	int newNum1, newNum2;
	int decimal1, decimal2;
	int sumParts;

	printf("\nPlease enter 2 numbers less than 1000 to 2 decimal place accuracy:\n");
	scanf("%f %f", &num1, &num2);

	sum1 = CalcSum(num1);
	sum2 = CalcSum(num2);

	newNum1 = num1 * 100;
	newNum2 = num2 * 100;
	decimal1 = newNum1 % 100;
	decimal2 = newNum2 % 100;
	sumParts = decimal1 + decimal2;

	printf("\nThe sum of the digits of %0.2f is %0.2f", num1, sum1);
	printf("\nThe sum of the digits of %0.2f is %0.2f", num2, sum2);
	printf("\nThe sum of the decimal parts is %d + %d = %d\n\n", decimal1 , decimal2, sumParts);

	return 0;
}

float CalcSum(float num)
{
	int newNum = num * 100;

	if (newNum >= 10000)
	{
		return ((newNum / 10000) + (newNum / 1000 % 10) + (newNum / 100 % 10) + (newNum / 10 % 10) + (newNum % 10));
	}
	else if (1000 <= newNum < 10000)
	{
		return ((newNum / 1000) + (newNum / 100 % 10) + (newNum / 10 % 10) + (newNum % 10));
	}
	else if (100 <= newNum < 1000)
	{
		return ((newNum / 100) + (newNum / 10 % 10) + (newNum % 10));
	}
	else if (10 <= newNum < 100)
	{
		return ((newNum / 10) + (newNum % 10));
	}
	else if (newNum < 10)
	{
		return (newNum / 10);
	}
}*/

/*#include <stdio.h>

float CalcCelcius(float);

int main(void)
{
	float fahr;
	float celcius;

	printf("\nPlease enter a fahrenheit tempererature to be converted to celcius:\n");
	scanf("%f", &fahr);

	celcius = CalcCelcius(fahr);

	printf("\nThe celcius temperature is:  %0.2f\n\n", celcius);

	return 0;
}

float CalcCelcius (float fahr) 
{
	return (5.0 / 9.0 * (fahr - 32)); 
}*/

#include <stdio.h>

float FindProd(int, float);
float FindSum(int, float);

int main(void)
{
	char name1[20], name2[20];
	int cd1, cd2, mem1, mem2;
	float spent1, spent2, totalSpent;

	float cdCost = 10.00;
	float memCost = 20.00;

	printf("Type Name 1\tNumber of CDs\tNumber of Memory Keys:\n");
	scanf("%s %d %d", name1, &cd1, &mem1);
	printf("Type Name 2\tNumber of CDs\tNumber of Memory Keys:\n");
	scanf("%s %d %d", name2, &cd2, &mem2);

	spent1 = FindSum(FindProd(cd1, cdCost), FindProd(mem1, memCost));
	spent2 = FindSum(FindProd(cd2, cdCost), FindProd(mem2, memCost));
	totalSpent = FindSum(spent1, spent2);

	printf("%s\t spent \t$%0.2f\n", name1, spent1);
	printf("%s\t spent \t$%0.2f\n", name2, spent2);
	printf("They both spent\t$%0.2f\n\n", totalSpent);

	return 0;
}

float FindProd(int num1, float num2)
{
	return (num1 * num2);
}
float FindSum(int num1, float num2)
{
	return (num1 + num2);
}
