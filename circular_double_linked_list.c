//本程序进行循环双链表相关操作的实现

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


//学生信息结构体
typedef struct PeoInfo
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
	char school[SCHOOL_MAX];
}PeoInfo;


//创建结点结构体
typedef struct Node
{
	struct Node* Prev;
	PeoInfo DATA;
	struct Node* Next;
	int mark;//标志位，用来标记是否为首尾元素，首元素为1，尾元素为0，其他位置为-1
}Node;


//初始化双链表
void Initialize_list(Node* L)
{
	memset(&(L->DATA), 0, sizeof(PeoInfo));
	L->mark = 1;
	L->Prev = NULL;
	L->Next = NULL;
}


//将数据添加到链表中,采用尾插法
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

//打印列表
void Print_list(Node* L)
{
	Node* p = L;
	while (p->mark != 1)
	{
		p = p->Next;
	}
	printf("%-20s\t%-5s\t%-4s\t%-12s\t%-30s\t%-20s\n", "姓名", "性别", "年龄", "电话", "地址", "学校");
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

//删除元素
void Del_element(Node** L, const char* element)
{
	Node* p = (*L);
	while (strcmp(p->DATA.name, element))
	{
		p = p->Next;
	}
	//判断所要删除的内容是否为首尾元素
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
	PeoInfo STU[] = { {"张三","男",25,"15854542525","安徽亳州","合肥学院"},{"赵四","男",50,"17377497750","东北莲花铁岭","家里蹲大学"},{"王五","男",500,"16554554225","河南开封府","县衙"},{"三圣母","女",3000,"19899564832","灌江口","娲皇宫"} };
	int len = sizeof(STU) / sizeof(STU[0]);
	 //创建循环双链表，无表头的循环列表
	Node L = { 0 };
	Node* L1 = &L;
	//初始化双链表
	Initialize_list(L1);
	//将STU表中的数据导入链表中
	ADD_element(L1, len,STU);
	//打印列表
	Print_list(L1);
	//删除元素
	Del_element(&L1, "王五");
	Print_list(L1);
	return 0;
}