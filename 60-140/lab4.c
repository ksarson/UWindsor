/*#include <stdio.h>

void FindSum(int, int, int *);
int main(void){

	int a = 2, b = 5, c = 1, x =3, y = 4,z = 7;
	
	FindSum(a,b,&c);
	printf("first call in main %d %d %d %d %d %d \n",a,b,c,x,y,z);
	FindSum(x,y,&z);
	printf("second call in main %d %d %d %d %d %d \n",a,b,c,x,y,z);
	return 0;
}

void FindSum(int a, int b, int *c){
	a += (b*2);
	b += (b*2);
	*c+= (b*2);
	printf("in FindSum: %d %d %d \n",a,b,*c);
}



#include <stdio.h>
float FindDiff(float,float);
int main(void){
	float Num1,Num2;
	float diff;
	
	scanf("%f %f", &Num1, &Num2);
	diff = FindDiff(Num1,Num2);
	printf("The difference between Num1 and Num2 is %f\n", diff);
	return 0;
}

float FindDiff(float first, float second){
	float differ;
	differ = first - second;
	return(differ);
}
*/
#include <stdio.h>

void FindDiff(float,float,float *);
int main(void){
	float Num1,Num2;
	float diff;

	scanf("%f %f",&Num1,&Num2);
	FindDiff(Num1,Num2,&diff);
	printf("The difference between Num1 and Num2 is %f\n",diff);
	return 0;
}

void FindDiff(float Num1,float Num2,float *differ){
	*differ = Num1 - Num2;
}





