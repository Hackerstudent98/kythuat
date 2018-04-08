#include <stdio.h>
#include "Header.h"

void floatArrOut(float *a)
{
	int i, n = floatArrSize(a);
	for ( i = 0; i < n; i++)
	{
		printf("%f\n", a[i]);
	}
}

float *floatArrInput()
{
	float *anew, *a = NULL;
	float x;
	while (scanf("%f", &x) > 0)
	{
		anew = floatArrPushBack(a, x);
		if (anew != NULL)
			a = anew;
	}
	return a;
}
void main()
{
	float *B;
	float x;

	printf("Input elemts:\n");

	B = floatArrInput();
	
	printf("%d element(s):\n", floatArrSize(B));
	floatArrOut(B);

	x = floatArrPopBack(B);
	printf("\n After Pop :\n");
	floatArrOut(B);
	printf("\nPop element %f \n", x);
	
	// Free Allocated memory 
	floatArrFree(B);
	
}