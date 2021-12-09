//�������������������ϰ
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>


////����Ϣ�Զ���������
////����ѧ����Ϣ�ṹ����
//struct Stu
//{
//	char name[20];
//	int age;
//	char sex[5];
//	char addr[30];
//	char school[20];
//};
//
////����������ṹ����
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
////ʵ�������ж���λ�õĲ���
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
//	struct Stu SZ[5] = {{"��˧",20,"��","���ճ���","�Ϸʴ�ѧ"},{"��᯴�",23,"Ů","���ճ���","�Ϸʹ�ҵ"},{"����",25,"��","��������","���տƼ���ѧ"},{"������",27,"��","��������","�й���ҵ��ѧ"},{"�����",23,"��","��������","���ϴ�ѧ"}};
//	//����������Ϣ��䵽������
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
//	//���������е�������Ϣ��ӡ����
//	P = L->ADDR;
//	printf("%-20s\t%-4s\t%-5s\t%-30s\t%-20s\n", "����", "����", "�Ա�", "��ַ", "ѧУ");
//	while (P != NULL)
//	{
//		printf("%-20s\t%-4d\t%-5s\t%-30s\t%-20s\n", P->S1.name, P->S1.age, P->S1.sex, P->S1.addr, P->S1.school);
//		P = P->ADDR;
//	}
//	return 0;
//}


//�ṩ�����������������������е���������ӡL����Pָ����λ�ô���Ԫ��


//����������ṹ����
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


//�����������ڽ����������ݴ�������
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