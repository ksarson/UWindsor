#include <stdio.h>

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

	printf("\n\nThe expression is:  V = (UCeil(%f) + UFloor(%f) - UCeil(%f)) * UFloor(%f)", num1, num2, num3, num4);
	printf("\nThe value of the expression V = %d", v);

	return 0;
}

int UCeil(float num)
{
	return (num + 1) / 1;
}

int UFloor(float num)
{
	return num / 1;
}