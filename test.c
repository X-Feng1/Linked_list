//本程序进行链表的相关练习
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>


////将信息自动传入链表
////定义学生信息结构属性
//struct Stu
//{
//	char name[20];
//	int age;
//	char sex[5];
//	char addr[30];
//	char school[20];
//};
//
////定义链表结点结构属性
//struct List_Nodes
//{
//	struct Stu S1;
//	struct List_Nodes* ADDR;
//};
//
//typedef struct List_Nodes* List;
//typedef struct List_Nodes* Position;
//
//
////实现链表中对象位置的查找
//Position Find_element(char* name, List L)
//{
//	Position P = 0;
//	P = L->ADDR;
//	while (P != NULL && strcmp(P->S1.name, name) != 0)
//		P = P->ADDR;
//	return P;
//}
//
//int main()
//{
//	List P = 0;
//	struct List_Nodes list = { 0 };
//	struct Stu SZ[5] = {{"张帅",20,"男","安徽滁州","合肥大学"},{"张岑春",23,"女","安徽巢湖","合肥工业"},{"蓝号",25,"男","安徽亳州","江苏科技大学"},{"王春波",27,"男","江苏徐州","中国矿业大学"},{"帐蓬壶",23,"男","河南商丘","河南大学"}};
//	//将上述的信息填充到链表中
//	int i = 0;
//	List L = &list;
//	for (i = 0; i < 5; i++)
//	{
//		struct List_Nodes* P = 0;
//		struct List_Nodes* TmpCell = 0;
//		TmpCell = malloc(sizeof(struct List_Nodes));
//		if (TmpCell == NULL)
//		{
//			printf(strerror(errno));
//		}
//		if (i == 0)
//		{
//			L->ADDR = TmpCell;
//			TmpCell->S1 = SZ[i];
//		}
//		else if(i<4)
//		{
//			P = Find_element(SZ[i-1].name, L);
//			TmpCell->S1 = SZ[i];
//			P->ADDR = TmpCell;
//		}
//		else
//		{
//			P = Find_element(SZ[i - 1].name, L);
//			TmpCell->S1 = SZ[i];
//			P->ADDR = TmpCell;
//			TmpCell->ADDR = NULL;
//		}
//		
//	}
//
//	//将单链表中的所有信息打印出来
//	P = L->ADDR;
//	printf("%-20s\t%-4s\t%-5s\t%-30s\t%-20s\n", "姓名", "年龄", "性别", "地址", "学校");
//	while (P != NULL)
//	{
//		printf("%-20s\t%-4d\t%-5s\t%-30s\t%-20s\n", P->S1.name, P->S1.age, P->S1.sex, P->S1.addr, P->S1.school);
//		P = P->ADDR;
//	}
//	return 0;
//}


//提供两个链表，均包含以升序排列的整数，打印L中由P指定的位置处的元素


//定义链表结点结构属性
struct List_Nodes
{
	int value;
	struct List_Nodes* NEXT;
};

typedef struct List_Nodes* List;
typedef struct List_Nodes* Position;

Position Find_element(int value, List L)
{
	Position P = 0;
	P = L->NEXT;
	while (P != NULL && (P->value != value))
		P = P->NEXT;
	return P;
}


//创建函数用于将数组中数据传入链表
void Add_element(List* L, int num,int* a)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		Position TemCell = 0;
		TemCell = malloc(sizeof(struct List_Nodes));
		if (TemCell == NULL)
		{
			printf(strerror(errno));
		}
		else
		{
			if (i == 0)
			{
				TemCell->value = a[i];
				(*L)->NEXT = TemCell;
			}
			else if (i <num-1)
			{
				Position P = 0;
				P = Find_element(a[i - 1], (*L));
				TemCell->value = a[i];
				P->NEXT = TemCell;
			}
			else
			{
				Position P = 0;
				P = Find_element(a[i - 1], (*L));
				TemCell->value = a[i];
				P->NEXT = TemCell;
				TemCell->NEXT = NULL;
			}
		}
	}
}


void Print(List* L, List* P)
{
	Position tmp1 = (*L)->NEXT;
	Position tmp2 = (*P)->NEXT;
	int tmp = tmp2->value;
	while (tmp)
	{
		int i = 0;
		tmp1 = (*L)->NEXT;
		for (i = 1; i < tmp; i++)
		{
			tmp1 = tmp1->NEXT;
		}
		printf("%d ", tmp1->value);
		tmp2 = tmp2->NEXT;
		tmp = tmp2->value;
	}
}


int main()
{
	int i = 0;
	int a[9] = { 11, 22, 33, 44, 55, 66, 77, 88,99 };
	int b[3] = { 3, 5, 8 };
	struct List_Nodes S = { 0 };
	struct List_Nodes SS = { 0 };
	List L = &S;
	List P = &SS;
	Add_element(&L, 9, a);
	Add_element(&P, 3, b);
	Print(&L, &P);
	return 0;
}