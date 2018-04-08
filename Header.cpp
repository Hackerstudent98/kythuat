#include "Header.h"
#include <malloc.h>
#include <stdio.h>
#include <memory.h>
static int dummy_nItem;
static int headSize = sizeof(dummy_nItem);
// kich thuoc cong them byte dau
static int memSize(int nItem)
{
	if (nItem < 0) nItem = -nItem;
	return headSize + nItem*sizeof(float);
}
// Tinh dia chi goc (luc cap phap)
static void *origin_addr(float *aData)
{
	return (char*)aData - headSize;
}
// tinh dia chi vung bat dau du lieu
static float *data_addr(void *origin)
{
	return (float*)((char*)origin + headSize);
}
// cap nhap phan tu mang
static void set_nItem(float *aData, int nItem)
{
	*(int*)origin_addr(aData) = nItem;
}
// doc so phan tu mang
static int get_nItem(float *aData)
{
	return *(int*)origin_addr(aData);
}
float *floatArrResize(float *aData, int nItem)
{
	int sz = memSize(nItem);
	float *aNew = NULL;
	void *originAddr = NULL;
	if (aData != NULL)
	{
		originAddr = origin_addr(aData);
	}
	aNew = (float*)realloc(originAddr, sz);
	if (aNew != NULL)
	{
		if (aData == NULL)
		{
			// First Allocation
			memset(aNew, 0, sz);
		}
		aData = data_addr(aNew);
		set_nItem(aData, nItem);
	}
	return aData;
}
int floatArrSize(float *aData)
{
	if (aData != NULL)
	{
		return get_nItem(aData);
	}
	return 0;
}
void floatArrFree(float *aData)
{
	if (aData != NULL)
	{
		free(origin_addr(aData));
	}
}


float *floatArrPushBack(float *aData, float x)
{
	int nItem = floatArrSize(aData);
	float *aNew = floatArrResize(aData, 1 + nItem);
	if (aNew != NULL)
	{
		aNew[nItem] = x;
		aData = aNew;			
	}

	return aData;
}

float floatArrPopBack(float *aData)
{
	int nItem = floatArrSize(aData);
	float x;
	if (aData != NULL && nItem > 0)
	{
		nItem--;
		x = aData[nItem];
		set_nItem(aData, nItem);
	}
	return x;
}