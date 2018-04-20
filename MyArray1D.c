#include <stdio.h>
#include <stdlib.h>

#include <memory.h>
#pragma pack(1)
typedef struct {
	int nItem, sizeItem;
	char Data[1];

}ArrayStruct;

void *arrInit(int nItem, int sizeItem)
{
	void *a = NULL;
	int sz = 17;
	a = malloc(sz);
	if (a != NULL)
	{
		ArrayStruct *aStruct = (ArrayStruct*)a;
		memset(a, 0, sz);
		aStruct->nItem = nItem;
		aStruct->sizeItem = sizeItem;
		a = aStruct->Data;
	}
	return a;
}
int main()
{
	arrInit(2, 4);
	printf("%d", sizeof(ArrayStruct));
	getchar();
	return 0;
}
