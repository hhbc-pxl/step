#define _CRT_SECURE_NO_WARNINGS 1

//��д���룬����ʾ����ַ��������ƶ����м���
//#include <stdio.h>
//#include <string.h>
//#include <windows.h>
//int main()
//{
//	char arr1[] = "������һ����ʦ!";
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


//ģ���û���¼������ֻ�ܵ����Σ�ֻ���������������룬���������ȷ��ʾ��½�ɹ���������ζ�����˳�����
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	for (i = 0;i < 3;i++)
//	{
//		printf("����������:");//����������123456��
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)//�Ƚ��ַ�����СҪ��strcmp��
//		{
//			printf("������ȷ");
//			break;
//		}
//		else
//		{
//			printf("�������");
//		}
//	}
//	if (i == 3)
//	{
//		printf("���ζ������˳�����");
//	}
//	return 0;
//
//}

//��������Ϸ
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
		printf("�������");
		scanf("%d", &guess);
		if (guess == ret)
		{
			printf("�¶���\n");
			break;
		}
		if (guess < ret)
		{
			printf("��С��\n");
		}
		if (guess > ret)
		{
			printf("�´���\n");
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
		printf("������1����0\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("������Ϸ");
			break;
		default:
			printf("��������");
			break;
		}
	} while (input);
	return 0;
}

