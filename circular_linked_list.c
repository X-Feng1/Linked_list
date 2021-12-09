//本程序实现循环单链表
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


//创建学生信息结构体
typedef struct PeoInfo
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
	char school[SCHOOL_MAX];
}PeoInfo;


//创建循环结点结构体
typedef struct Node
{
	PeoInfo data;
	struct Node* Next;
}Node;

//初始化循环单链表
void Initialize_list(Node* L)
{
	memset(&(L->data), 0, sizeof(PeoInfo));
	L->Next = L;
}

//添加元素
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

//打印列表
void Print_list(Node* L)
{
	Node* p = L;
	printf("%-20s\t%-5s\t%-4s\t%-12s\t%-30s\t%-20s\n", "姓名", "性别", "年龄", "电话", "地址", "学校");
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
	PeoInfo STU[] = { {"张三","男",25,"15854542525","安徽亳州","合肥学院"},{"赵四","男",50,"17377497750","东北莲花铁岭","家里蹲大学"},{"王五","男",500,"16554554225","河南开封府","县衙"},{"三圣母","女",3000,"19899564832","灌江口","娲皇宫"} };
	int len = sizeof(STU) / sizeof(STU[0]);
	//创建循环单链表
	Node L = { 0 };
	Node* L1 = &L;
	//初始化循环单链表
	Initialize_list(L1);
	//添加元素，头插法
	ADD_element(L1, STU, len);
	//打印列表
	Print_list(L1);
	return 0;
}