#include <stdio.h>
#include <math.h>

int main(void)

{
	float far, cel;

	printf ("\n Please enter a temperature in celcius:  ");
	scanf ("%f", &cel);

	far = cel * 1.8 + 32;

	printf ("\n The temperature in farenheit is %0.2f\n", far);

	return 0;
}