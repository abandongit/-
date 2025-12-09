//对一个有N个学生的班级，
// 通过该系统实现对该班级学生的基本信息进行录入、显示、修改、除、保存等操作的管理。
//(1) 学生基本信息包括：学号、姓名、性别、出生日期、备注。
//(2) 本系统所涉及的所有数据都需要保存至文件。
/*本系统如下菜单形式显示：请选择系统功能项：
a 学生基本信息录入
b 学生基本信息显示
c 学生基本信息保存
d 学生基本信息删除
e 学生基本信息修改
f 学生基本信息查询
(1)按学号查询
(2)按姓名查询
(3)按性别查询
(4)按年龄查询
g.退出系统
(4)执行一个具体的功能之后，程序将重新显示菜单。
(5) 按菜单要求实现所有功能。
将学生基本信息保存到文件中。
进入系统之前要先输入密码。*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#define PASSWORD "123456789"//系统密码
typedef struct student//学生基本信息结构体
{
	char num[20];//学号
	char name[20];//姓名
	char gender[10];//性别
	char birth[20];//出生日期
	char remark[100];//备注
}stu;
stu students[100];//学生数组
int count = 0;//学生数量
void desktop();//菜单函数声明
int password();//登录函数声明



int main()//主函数
{
	if (!password()) return 0;
	char choice;
	do {
		desktop();

		scanf("%c", &choice);
		switch (choice) {
		case 'a': addstudent();//学生基本信息录入
			break;
		case 'b': showstudent();//学生基本信息显示
			break;
		case 'c': savestudent();//学生基本信息保存
			break;
		case 'd': deletestudent();//学生基本信息删除
			break;
		case 'e': revisestudent();//学生基本信息修改
			break;
		case 'f': findstudent();//学生基本信息查询
			break;
		case 'g': printf("成功退出系统!\n欢迎下次使用!\n");
			break;
		default: printf("输入错误，请重试!!!\n");
		}
	} while (choice != 'g');

	return 0;
}

void desktop()//菜单函数
{
	printf("\n*********************************欢迎使用班级档案管理系统*********************************\n");
	printf("\n");
	printf("a 学生基本信息录入\n");
	printf("b 学生基本信息显示\n");
	printf("c 学生基本信息保存\n");
	printf("d 学生基本信息删除\n");
	printf("e 学生基本信息修改\n");
	printf("f 学生基本信息查询\n");
	printf("g 退出系统");
	   printf("\n");
	printf("********************************************************************************************\n");
	printf("请选择：");
}

int password()//登录函数
{
	char password[10];
	int a = 0;
	while (a < 3)
	{
		printf("请输入密码:");
		scanf("%9s", &password);
		getchar();
		if (strcmp(password, PASSWORD) == 0)
		{
			printf("密码正确，欢迎使用本系统！\n");
			return 1;
		}
		else
		{
			if ((2 - a) > 0)
			{
				printf("密码错误，请重新输入！\n");
				printf("你还有%d次机会！\n", 2 - a);
			    if ((2 - a) == 1)
				{
					printf("\n");
					printf("请10秒后再输入 \n");
					Sleep(10 * 1000);
				}
			}

			printf("\n");
		}
		a++;
	}
	printf("三次密码输入错误，系统退出!!!\n");
	return 0;
}
