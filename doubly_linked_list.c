//���������˫�������ز�����ʵ��
#define _CRT_SECURE_NO_WARNINGS 1

#define NAME_MAX 20
#define SEX_MAX 5
#define ADDR_MAX 30
#define SCHOOL_MAX 20
#define TELE_MAX 12

#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

//ѧ����Ϣ�ṹ��
struct PeoInfo
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
	char school[SCHOOL_MAX];
};

//˫����ṹ��
typedef struct Doubly_linked_list
{
	struct PeoInfo data;
	struct Doubly_linked_list* Prio;
	struct Doubly_linked_list* Next;
}Double_link;

typedef Double_link* List;

//����һ����˫����
void Create_list(List* L)
{
	Double_link* tmpcell = (Double_link*)malloc(sizeof(Double_link));
	if (tmpcell == NULL)
	{
		printf(strerror(errno));
	}
	else
	{
		memset(&((tmpcell)->data), 0, sizeof(Double_link));
		tmpcell->Next = NULL;
		tmpcell->Prio = (*L);
		(*L)->Prio = NULL;
		(*L)->Next = tmpcell;
	}
}

////�ڿ�˫���������Ԫ��
void ADD_element(List* L,struct PeoInfo* STU,int len)
{
	int i = 0;
	List tmp1 = (*L)->Next;
	(*L)->Next->data= (*STU);
	for (i = 1; i < len; i++)
	{
		Double_link* tmp = (Double_link*)malloc(sizeof(Double_link));
		if (tmp == NULL)
		{
			printf(strerror(errno));
		}
		else
		{
			tmp->data = *(STU + i);
			tmp->Next = (*L)->Next;
			tmp->Prio = (*L);
			tmp->Next->Prio = tmp;
			(*L)->Next = tmp;
		}
	}
}

//��ӡ�б�
void Print_list(List* L)
{
	List P = (*L)->Next;
	printf("%-20s\t%-5s\t%-4s\t%-12s\t%-30s\t%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ", "ѧУ");
	while (P)
	{
		printf("%-20s\t%-5s\t%-4d\t%-12s\t%-30s\t%-20s\n", 
			P->data.name,
			P->data.sex,
			P->data.age,
			P->data.tele,
			P->data.addr,
			P->data.school);
		P = P->Next;
	}
}

//ɾ��Ԫ��
void Del_element(List* L,const char* element)
{
	List P = (*L)->Next;
	while (strcmp(P->data.name, element))
	{
		P = P->Next;
	}
	P->Prio->Next = P->Next;
	P->Next->Prio = P->Prio;
}

int main()
{
	struct PeoInfo STU[] = { {"����","��",25,"15854542525","��������","�Ϸ�ѧԺ"},{"����","��",50,"17377497750","������������","����״�ѧ"},{"����","��",500,"16554554225","���Ͽ��⸮","����"},{"��ʥĸ","Ů",3000,"19899564832","�཭��","活ʹ�"} };
	int len = sizeof(STU) / sizeof(STU[0]);
	//����һ��˫����
	Double_link DL = { 0 };
	List L = &DL;
	Create_list(&L);
	//���Ԫ��
	ADD_element(&L,STU,len);
	//��ӡ�б�
	Print_list(&L);
	//ɾ��Ԫ��
	Del_element(&L, "����");
	printf("ɾ������б�Ϊ��\n");
	Print_list(&L);
	return 0;
}