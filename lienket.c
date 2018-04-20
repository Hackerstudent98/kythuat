#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)

typedef struct node *ref;
struct node
{
	int key;
	ref next;
};
ref getNode(int k)
{
	ref p;
	p = (ref)malloc(sizeof(struct node));
	if (p == NULL)
	{
		printf("Khong du bo nho \n");
		exit(0);
	}
	p->key = k;
	p->next = NULL;
}

void addFirst(ref &head, ref &tail, int k)
{
	ref p = getNode(k);
	if (head == NULL)
		head = tail = p;
	else
	{
		p->next = head;
		head = p;
	}
}
void printlist(ref head)
{
	ref p;
	if (head == NULL)
	{
		printf("\n Danh Sach Rong");
	}
	else
	{
		for (p = head; p; p = p->next)
			printf("%d\n", p->key);
	}
}
int main()
{
	int k;

	ref head = NULL, tail = NULL;
	while (1)
	{
		printf("Nhap so nguyen nhap so 0 de thoat: ");
		scanf("%d", &k);
		if (k == 0)
			break;
		addFirst(head, tail, k);
	}
	printlist(head);
	getchar();
	return 0;
}
