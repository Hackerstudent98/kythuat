#pragma once
#ifndef _MY_ARRAY1D_H
#define _MY_ARRAY1D_H

float *floatArrResize(float *a, int nItem);
int floatArrSize(float *a);
void floatArrFree(float *a);
float *floatArrPushBack(float *a, float x);
float floatArrPopBack(float *a);
#endif 