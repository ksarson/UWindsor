/*#include <stdio.h>

int main(void)
{
	int loc1, loc2, loc3;
	int north1, north2, north3;
	int south1, south2, south3;
	float northAvg, southAvg;
	int gameNum = 0;

	printf("\nType Game location Team North points and Team South Points\n");
	printf("Game 1: ");
	scanf("%d %d %d", &loc1, &north1, &south1);
	printf("\nType Game location Team North points and Team South Points\n");
	printf("Game 2: ");
	scanf("%d %d %d", &loc2, &north2, &south2);
	printf("\nType Game location Team North points and Team South Points\n");
	printf("Game 3: ");
	scanf("%d %d %d", &loc3, &north3, &south3);

	if (loc1 == 1)
	{
		south1 += 10;
	}
	else if (loc1 == 2)
	{
		north1 += 10;
	}

	if (loc2 == 1)
	{
		south2 += 10;
	}
	else if (loc2 == 2)
	{
		north2 += 10;
	}

	if (loc3 == 1)
	{
		south3 += 10;
	}
	else if (loc3 == 2)
	{
		north3 += 10;
	}

	northAvg = ((float)north1 + (float)north2 + (float)north3) / 3;
	southAvg = ((float)south1 + (float)south2 + (float)south3) / 3;

	printf("\nAverage points for Team North is:\t%0.2f", northAvg);
	printf("\nAverage points for Team South is:\t%0.2f\n\n", southAvg);

	return 0;
}*/

#include <stdio.h>

int product_Array(int[], int[], int[], int);


int main(void)
{
	int numVal;

	printf("\nPlease enter the number of values you wish to place in each array:\n");
	scanf("%d", &numVal);

	int array1[numVal], array2[numVal], array3[numVal], i;

	printf("\nPlease enter %d integer values to be placed into the first array:\n", numVal);

	for (i = 0; i < numVal ; i++)
	{
	scanf("%d", &array1[i]);
	}

	printf("\nPlease enter %d integer values to be placed into the second array:\n", numVal);

	for (i = 0; i < numVal; i++)
	{
	scanf("%d", &array2[i]);
	}

	product_Array(array1, array2, array3, numVal);

	printf("\nArray 1\t\tArray2\t\t|\tproduct_Array\n");
	printf("------------------------------------------------------------\n");
	for (i = 0; i < numVal; i++)
	{
		printf("%d\t\t%d\t\t|\t%d\n", array1[i], array2[i], array3[i]);
	}

	printf("\n");
	return 0;
}

int product_Array(int array1[], int array2[], int array3[], int numVal)
{
	int i;

	for (i = 0; i < numVal; i++)
	{
		array3[i] = array1[i] * array2[i];
	}
}

/*#include <stdio.h>

int main(void)
{
	int numWater, numChips, numMilk;
	float priceWater, priceChips, priceMilk;
	float waterCost, chipsCost, milkCost, totalCost;
	int age;
	float totalTax;

	printf("\nPlease enter the number of water bottles purchased:\n");
	scanf("%d", &numWater);
	printf("\nPlease enter the price of a water bottle:\n$");
	scanf("%f", &priceWater);
	printf("\nPlease enter the number of bags of chips purchased:\n");
	scanf("%d", &numChips);
	printf("\nPlease enter the number of a bag of chips:\n$");
	scanf("%f", &priceChips);
	printf("\nPlease enter the number of cartons of milk purchased:\n");
	scanf("%d", &numMilk);
	printf("\nPlease enter the number of a carton of milk:\n$");
	scanf("%f", &priceMilk);
	printf("\nPlease enter your age:\n");
	scanf("%d", &age);

	if (age < 65)
	{
		waterCost = numWater * priceWater;
		chipsCost = numChips * priceChips;
		milkCost = numMilk * priceMilk;
		totalCost = (waterCost + chipsCost + milkCost) * 1.15;
		totalTax = (waterCost + chipsCost + milkCost) * 0.15;
	}
	else
	{
		waterCost = numWater * priceWater;
		chipsCost = numChips * priceChips;
		milkCost = numMilk * priceMilk;
		totalCost = waterCost + chipsCost + milkCost;
		totalTax = 0;
	}

	printf("\n%d water bottles @ $%0.2f each:\t$%0.2f\n", numWater, priceWater, waterCost);
	printf("%d bags of chips @ $%0.2f each:\t$%0.2f\n", numChips, priceChips, chipsCost);
	printf("%d cartons of milk @ $%0.2f each:\t$%0.2f\n", numMilk, priceMilk, milkCost);
	printf("Total Tax:\t\t\t$%0.2f\n", totalTax);
	printf("Total Cost:\t\t\t$%0.2f\n\n", totalCost);
}*/