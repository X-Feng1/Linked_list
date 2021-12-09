//本程序进行双链表的相关操作的实现
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

//学生信息结构体
struct PeoInfo
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
	char school[SCHOOL_MAX];
};

//双链表结构体
typedef struct Doubly_linked_list
{
	struct PeoInfo data;
	struct Doubly_linked_list* Prio;
	struct Doubly_linked_list* Next;
}Double_link;

typedef Double_link* List;

//创建一个空双链表
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

////在空双链表中添加元素
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

//打印列表
void Print_list(List* L)
{
	List P = (*L)->Next;
	printf("%-20s\t%-5s\t%-4s\t%-12s\t%-30s\t%-20s\n", "姓名", "性别", "年龄", "电话", "地址", "学校");
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

//删除元素
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
	struct PeoInfo STU[] = { {"张三","男",25,"15854542525","安徽亳州","合肥学院"},{"赵四","男",50,"17377497750","东北莲花铁岭","家里蹲大学"},{"王五","男",500,"16554554225","河南开封府","县衙"},{"三圣母","女",3000,"19899564832","灌江口","娲皇宫"} };
	int len = sizeof(STU) / sizeof(STU[0]);
	//创建一个双链表
	Double_link DL = { 0 };
	List L = &DL;
	Create_list(&L);
	//添加元素
	ADD_element(&L,STU,len);
	//打印列表
	Print_list(&L);
	//删除元素
	Del_element(&L, "赵四");
	printf("删除后的列表为：\n");
	Print_list(&L);
	return 0;
}