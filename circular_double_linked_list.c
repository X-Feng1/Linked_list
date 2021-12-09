//���������ѭ��˫������ز�����ʵ��

#define _CRT_SECURE_NO_WARNINGS 1

#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30
#define SCHOOL_MAX 20


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>


//ѧ����Ϣ�ṹ��
typedef struct PeoInfo
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
	char school[SCHOOL_MAX];
}PeoInfo;


//�������ṹ��
typedef struct Node
{
	struct Node* Prev;
	PeoInfo DATA;
	struct Node* Next;
	int mark;//��־λ����������Ƿ�Ϊ��βԪ�أ���Ԫ��Ϊ1��βԪ��Ϊ0������λ��Ϊ-1
}Node;


//��ʼ��˫����
void Initialize_list(Node* L)
{
	memset(&(L->DATA), 0, sizeof(PeoInfo));
	L->mark = 1;
	L->Prev = NULL;
	L->Next = NULL;
}


//��������ӵ�������,����β�巨
void ADD_element(Node* L, int len,PeoInfo* STU)
{
	int i = 0;
	Node* tmp1 = L;
	Node* head = L;
	L->DATA = *STU;
	for (i = 1; i < len; i++)
	{
		Node* tmpcell = (Node*)malloc(sizeof(Node));
		if (tmpcell == NULL)
		{
			printf(strerror(errno));
		}
		else
		{
			tmpcell->DATA = *(STU + i);
			tmpcell->Next = L;
			tmpcell->Prev = tmp1;
			tmpcell->mark = 0;
			tmp1->Next = tmpcell;
			if (tmp1->mark != 1)
				tmp1->mark = -1;
			L->Prev = tmpcell;
			tmp1 = tmpcell;
		}
	}
}

//��ӡ�б�
void Print_list(Node* L)
{
	Node* p = L;
	while (p->mark != 1)
	{
		p = p->Next;
	}
	printf("%-20s\t%-5s\t%-4s\t%-12s\t%-30s\t%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ", "ѧУ");
	do
	{
		printf("%-20s\t%-5s\t%-4d\t%-12s\t%-30s\t%-20s\n",
			p->DATA.name,
			p->DATA.sex,
			p->DATA.age,
			p->DATA.tele,
			p->DATA.addr,
			p->DATA.school);
		p = p->Next;
	} while (p->mark != 1);

}

//ɾ��Ԫ��
void Del_element(Node** L, const char* element)
{
	Node* p = (*L);
	while (strcmp(p->DATA.name, element))
	{
		p = p->Next;
	}
	//�ж���Ҫɾ���������Ƿ�Ϊ��βԪ��
	if (p->mark < 0)
	{
		p->Prev->Next = p->Next;
		p->Next->Prev = p->Prev;
	}
	else if(p->mark == 1)
	{
		*L = p->Next;
		p->Next->mark = 1;
		p->Next->Prev = p->Prev;
	}
	else
	{
		p->Prev->mark = 0;
		p->Prev->Next = p->Next;
	}
}
int main()
{
	PeoInfo STU[] = { {"����","��",25,"15854542525","��������","�Ϸ�ѧԺ"},{"����","��",50,"17377497750","������������","����״�ѧ"},{"����","��",500,"16554554225","���Ͽ��⸮","����"},{"��ʥĸ","Ů",3000,"19899564832","�཭��","活ʹ�"} };
	int len = sizeof(STU) / sizeof(STU[0]);
	 //����ѭ��˫�����ޱ�ͷ��ѭ���б�
	Node L = { 0 };
	Node* L1 = &L;
	//��ʼ��˫����
	Initialize_list(L1);
	//��STU���е����ݵ���������
	ADD_element(L1, len,STU);
	//��ӡ�б�
	Print_list(L1);
	//ɾ��Ԫ��
	Del_element(&L1, "����");
	Print_list(L1);
	return 0;
}