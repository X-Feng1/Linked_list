//������ʵ��ѭ��������
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


//����ѧ����Ϣ�ṹ��
typedef struct PeoInfo
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
	char school[SCHOOL_MAX];
}PeoInfo;


//����ѭ�����ṹ��
typedef struct Node
{
	PeoInfo data;
	struct Node* Next;
}Node;

//��ʼ��ѭ��������
void Initialize_list(Node* L)
{
	memset(&(L->data), 0, sizeof(PeoInfo));
	L->Next = L;
}

//���Ԫ��
void ADD_element(Node* L, PeoInfo* STU, int len)
{
	if (len > 0)
	{
		L->data = *STU;
		Node* tmp = L;
		int i = 0;
		for (i = 1; i < len; i++)
		{
			Node* tmp1 = (Node*)malloc(sizeof(Node));
			if (tmp1 == NULL)
			{
				printf(strerror(errno));
			}
			else
			{
				tmp1->data = *(STU + i);
				tmp1->Next = tmp;
				L->Next = tmp1;
				tmp = tmp1;
			}
		}
	}
}

//��ӡ�б�
void Print_list(Node* L)
{
	Node* p = L;
	printf("%-20s\t%-5s\t%-4s\t%-12s\t%-30s\t%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ", "ѧУ");
	do
	{
		printf("%-20s\t%-5s\t%-4d\t%-12s\t%-30s\t%-20s\n",
			p->data.name,
			p->data.sex,
			p->data.age,
			p->data.tele,
			p->data.addr,
			p->data.school);
		p = p->Next;
	} while (strcmp(p->data.name, L->data.name));
}
int main()
{
	PeoInfo STU[] = { {"����","��",25,"15854542525","��������","�Ϸ�ѧԺ"},{"����","��",50,"17377497750","������������","����״�ѧ"},{"����","��",500,"16554554225","���Ͽ��⸮","����"},{"��ʥĸ","Ů",3000,"19899564832","�཭��","活ʹ�"} };
	int len = sizeof(STU) / sizeof(STU[0]);
	//����ѭ��������
	Node L = { 0 };
	Node* L1 = &L;
	//��ʼ��ѭ��������
	Initialize_list(L1);
	//���Ԫ�أ�ͷ�巨
	ADD_element(L1, STU, len);
	//��ӡ�б�
	Print_list(L1);
	return 0;
}