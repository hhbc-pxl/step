#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("******************************\n");
	printf("******* 1   play  ************\n");
	printf("********0   exit  ************\n");
	printf("******************************\n");

}
void game()
{
	//�������̶�Ӧ������
	char mine[ROWS][COLS];//��Ų��úõ��׵���Ϣ
	char show[ROWS][COLS];//��ŵ����Ų�����׵���Ϣ
	//��ʼ������
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show,ROWS, COLS, '*');
	//��ӡ����
	displayboard(mine, ROW, COL);
	displayboard(show, ROW, COL);
	//������
	SetMine(mine ,ROW,COL, EASY_COUNT);
	displayboard(mine, ROW, COL);
	//�Ų���
	Findmine(mine,show,ROW,COL);
}

int main()
{
	srand((unsigned)time(NULL));
	int input;
	do
	{
		menu();
		printf("��ѡ��\n");
		scanf("%d",&input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("��Ϸ����\n");
				break;
			default:
				printf("ѡ�����,������ѡ��\n");
				break;
		}

	} while (input);
	return 0;
}