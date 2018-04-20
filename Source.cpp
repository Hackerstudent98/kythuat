#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define MAX 255

typedef struct
{
	unsigned int SVmalop;
	unsigned int SVmssv;
	char SVten[MAX];
	double SVtoan;
	double SVhoa;
	double SVly;
	double SVdiemtb;

}SINHVIEN;
int  kiemtraSV(SINHVIEN dulieu[], int size, int mssv)
{

	for (int i = 0; i < size; i++)
	{
		if (dulieu[i].SVmssv == mssv)
		{
			return 1;
		}
	}
	return 0;
}

int menu()
{
	int result;
		printf("1. Nhap mssv");
		printf("\n2. Xuat mssv");
		printf("\n3. Push mssv");
		printf("\n4. Pop mssv");
		printf("\n5. Xoa Mssv");
		printf("\n6. Xap Xep");
		printf("\nVui Long Nhap Lua Chon :");
		scanf("%d", &result);
	return result;
}
bool swapSV(SINHVIEN *sv1, SINHVIEN *sv2)
{
	SINHVIEN temp;
	if (sv1 != NULL && sv2 != NULL)
	{
		temp = *sv1;
		*sv1 = *sv2;
		*sv2 = *sv1;
		return true;
	}
	else
	{
		return false;
	}
}
int nhapsv(SINHVIEN *dulieu)
{
	if (dulieu != NULL)
	{
		fflush(stdin);
		printf("Nhap Ma Lop sinh vien :");
		scanf("%u", &(dulieu->SVmalop));
		printf("Nhap ten :");
		fflush(stdin);
		scanf("%s[^\n]", dulieu->SVten);
		fflush(stdin);
		printf("Nhap diem toan :");
		scanf("%lf", &(dulieu->SVtoan));
		printf("Nhap diem hoa :");
		scanf("%lf", &(dulieu->SVhoa));
		printf("Nhap diem ly :");
		scanf("%lf", &(dulieu->SVly));
		
		dulieu->SVdiemtb = (dulieu->SVtoan + dulieu->SVhoa + dulieu->SVly) / 3.0;

	}
	else
	{
		return 0; 
	}
	return 1;
}
void nhap(SINHVIEN dulieu[], int *size)
{
	int n,mssv;
	printf("Nhap bao nhieu sinh vien\n");
	scanf("%d", &n);
	*size = n;
	int i;
	for (i = 0; i < *size; i++)
	{	
		printf("Nhap sinh vien thu %d\n", (i + 1));
		do
		{
			printf("Nhap Mssv ");
			scanf("%d", &mssv);

		} while (kiemtraSV(dulieu, *size, mssv));
		dulieu[i].SVmssv = mssv;
		nhapsv(&(dulieu[i]));
	}
}
void xuatsv(SINHVIEN dulieu)
{
	printf("\t%s\t%u\t%u\t%.2lf\t%.2lf\t%.2lf\t%.2lf", dulieu.SVten, dulieu.SVmalop, dulieu.SVmssv, dulieu.SVtoan, dulieu.SVhoa, dulieu.SVly, dulieu.SVdiemtb);
}
void xuat(SINHVIEN dulieu[], int size)
{
	printf("STT\tTen Sinh Vien \tMa So\ttMSSV\tToan\tLy\tHoa\tDiemTb");
	int i;
	for (i = 0; i < size; i++)
	{
		printf("\n");
		printf("%d", i);
		xuatsv(dulieu[i]);
	}
	printf("\n");
}
int pushSV(SINHVIEN dulieu[], int *size)
{
	int mssv;
	if (*size != MAX && *size > 0)
	{
		do
		{
			printf("Nhap Mssv ");
			scanf("%d", &mssv);

		} while (kiemtraSV(dulieu, *size, mssv) == 1);
		dulieu[*size].SVmssv = mssv;
		nhapsv(&(dulieu[*size]));
		++(*size);
		return 1;
	}
	else
	{
		return 0;
	}
	
}
int popSV(SINHVIEN dulieu[], int *size)
{
	if (*size > 0)
	{
		--(*size);
		return 1;
	}
	else
		return 0;
}
bool xoavitri(SINHVIEN dulieu[], int *size, int vitri)
{
	
	if (vitri < *size && vitri > 0 && *size < MAX)
	{
		for (int i = vitri - 1; i < *size - 1; i++)
		{
			for (int j = i; j < *size; j++)
			{
				swapSV(&dulieu[i], &dulieu[j]);
			}
		}
		*size--;
		return true;
	}
	else
	{
		return false;
	}

}
void sapxepSV(SINHVIEN dulieusv[], int size)
{
	for (int i = 0; i < size-1; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (strcmpi(dulieusv[i].SVten, dulieusv[j].SVten) > 0)
			{
				swapSV(&dulieusv[i], &dulieusv[j]);
			}
		}
	}
}

int main()
{
	SINHVIEN test[10] = {1,122,"TEN NGUYEN ",2.5,2.5,2.5,2.5};
	int *item = (int *)malloc(sizeof(int));
	int n,vitri;
	
	do
	{
		switch (n = menu())
		{
		case 1:
			nhap(test, item);
			break;
		case 2:
			xuat(test, *item);
			break;
		case 3:
			pushSV(test, item);
			break;
		case 4:
			popSV(test, item);
			break;
		case 5:
			printf("\n Vi Tri can Xoa : ");
			scanf("%d", &vitri);
			xoavitri(test, item, vitri);
			break;
		case 6:
			sapxepSV(test, *item);
		default:
			break;
		}
	} while (n > 0 && n < 5);
	return 0;
}
