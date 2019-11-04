#include <stdio.h>

int main(void)
{
	int numWater = 3, numChips = 4, numMilk = 2;
	float priceWater, priceChips, priceMilk;
	float waterCost, chipsCost, milkCost, totalCost;
	int age;
	float subTotal, totalTax;

	printf("\nPlease enter the price of a water bottle:\n$");
	scanf("%f", &priceWater);
	printf("\nPlease enter the number of a bag of chips:\n$");
	scanf("%f", &priceChips);
	printf("\nPlease enter the number of a carton of milk:\n$");
	scanf("%f", &priceMilk);
	printf("\nPlease enter your age:\n");
	scanf("%d", &age);

	if (age < 65)
	{
		waterCost = numWater * priceWater;
		chipsCost = numChips * priceChips;
		milkCost = numMilk * priceMilk;
		subTotal = waterCost + chipsCost + milkCost;
		totalCost = (waterCost + chipsCost + milkCost) * 1.13;
		totalTax = (waterCost + chipsCost + milkCost) * 0.13;
	}
	else
	{
		waterCost = numWater * priceWater;
		chipsCost = numChips * priceChips;
		milkCost = numMilk * priceMilk;
		totalCost = waterCost + chipsCost + milkCost;
		subTotal = totalCost;
		totalTax = 0;
	}

	printf("\n%d water bottles @ $%0.2f each:\t$%0.2f\n", numWater, priceWater, waterCost);
	printf("%d bags of chips @ $%0.2f each:\t$%0.2f\n", numChips, priceChips, chipsCost);
	printf("%d cartons of milk @ $%0.2f each:\t$%0.2f\n", numMilk, priceMilk, milkCost);
	printf("Sub Total:\t\t\t$%0.2f\n", subTotal);
	printf("Total Tax:\t\t\t$%0.2f\n", totalTax);
	printf("Total Cost:\t\t\t$%0.2f\n\n", totalCost);

}

/*#include <stdio.h>

int sum_Array(int[], int[], int[], int);


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

	sum_Array(array1, array2, array3, numVal);

	printf("\nArray 1\t\tArray2\t\t|\tsum_Array\n");
	printf("------------------------------------------------------------\n");
	for (i = 0; i < numVal; i++)
	{
		printf("%d\t\t%d\t\t|\t%d\n", array1[i], array2[i], array3[i]);
	}

	printf("\n");
	return 0;
}

int sum_Array(int array1[], int array2[], int array3[], int numVal)
{
	int i;

	for (i = 0; i < numVal; i++)
	{
		array3[i] = array1[i] + array2[i];
	}
}*/