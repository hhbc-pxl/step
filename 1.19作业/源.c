#define _CRT_SECURE_NO_WARNINGS 1

//编写代码，，演示多个字符从两端移动向中间汇聚
//#include <stdio.h>
//#include <string.h>
//#include <windows.h>
//int main()
//{
//	char arr1[] = "裴娟娟是一名老师!";
//	char arr2[] = "#################";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);
//		system("cls");
//		left++;
//		right--;	
//	}
//	printf("%s\n", arr2);
//	return 0;
//}


//模拟用户登录，并且只能登三次（只允许输入三次密码，如果密码正确提示登陆成功，如果三次都输错，退出程序）
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	for (i = 0;i < 3;i++)
//	{
//		printf("请输入密码:");//假设密码是123456；
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)//比较字符串大小要用strcmp；
//		{
//			printf("密码正确");
//			break;
//		}
//		else
//		{
//			printf("密码错误");
//		}
//	}
//	if (i == 3)
//	{
//		printf("三次都错误，退出程序");
//	}
//	return 0;
//
//}

//猜数字游戏
#include<stdio.h>
void menu()
{ 
	printf("*********************\n");
	printf("*****1.0  play*******\n");
	printf("*****0.0  exit*******\n");
}

void game()
{
	int ret = rand() % 100 + 1;
	int guess;
	while (1)
	{   
		printf("请猜数字");
		scanf("%d", &guess);
		if (guess == ret)
		{
			printf("猜对了\n");
			break;
		}
		if (guess < ret)
		{
			printf("猜小了\n");
		}
		if (guess > ret)
		{
			printf("猜大了\n");
		}
	}

}
int main()
{ 
	int input;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("请输入1或者0\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("结束游戏");
			break;
		default:
			printf("发生错误");
			break;
		}
	} while (input);
	return 0;
}

