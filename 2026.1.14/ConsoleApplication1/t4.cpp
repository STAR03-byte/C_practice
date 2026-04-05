#include<stdio.h>
#include<float.h>

int main() {

	float num1 = 1.0/3.0;

	double num2 = 1.0/3.0;

	printf("normal num : %.20f\n",2.32);

	printf("float num : %.20f\n",num1);

	printf("double num : %.20f\n",num2);

	printf("Defined max precision : %d\n",FLT_DIG);

	printf("Defined max precision : %d\n",DBL_DIG);

	return 0;
}