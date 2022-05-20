#include<stdio.h>
#define MaxSize 50
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length;
}SqList;
void PrintList(SqList&L)
{
	for (int i = 0; i <= L.length; i++)
	{
		printf("%4d", L.data[i]);
		/*printf("\n");*/
	}
}
bool ListInsert(SqList& L, int i, ElemType x)
{
	if (L.length >= MaxSize)
		return false;
	if (i <= 1 || i > L.length + 1)
		return false;
	for (int j = L.length; j >= i-1; j--)
		L.data[j] = L.data[j - 1];
	L.data[i-1] = x;
	L.length++;
	return true;
}
bool ListDel(SqList& L, int x, ElemType &t)
{
	if (x<1 || x>L.length)
		return false;
	t = L.data[x];
	for (int j = x - 1; j <= L.length; j++)
	{
		L.data[j] = L.data[j+1];
	}
	L.length--;
	return true;
}
bool ListChg(SqList& L, int k,ElemType y)
{
	if (k<1 || k>L.length)
		return false;
	L.data[k-1] = y;
	return true;
}
bool ListFind(SqList& L, ElemType c)
{
	int f, g=0;
	for (int i = 0; i <= L.length; i++)
	{
		if (L.data[i] == c)
		{
			f = i + 1;
			printf("是第%d个\n", f);
			g++;
		}
	}
	if (g == 0)
	{
		return false;
	}
	else
	return true;
}
int main()
{
	bool ret, del, ch,fin;
	ElemType t, f;
	SqList L;
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.data[3] = 4;
	L.data[4] = 5;
	L.length = 5;
	ret=ListInsert(L, 3, 60);
	if (ret)
	{
		printf("成功\n");
		PrintList(L);
		printf("\n");
	}
	else
	{
		printf("失败\n");
		printf("\n");
	}
	del = ListDel(L, 3, t);
	if (del)
	{
		printf("成功\n");
		
		PrintList(L);
		printf("%4d", t);
		printf("\n");
	}
	else
	{
		printf("失败\n");
		printf("\n");
	}
	ch = ListChg(L, 3, 60);
	if (ch)
	{
		printf("成功\n");
		PrintList(L);
		printf("\n");
	}
	else
	{
		printf("失败\n");
		printf("\n");
	}
	fin = ListFind(L, 5);
	if (fin)
	{
		printf("成功\n");
		PrintList(L);
		printf("\n");
	}
	else
	{
		printf("无\n");
		printf("\n");
	}
	return 0;
}