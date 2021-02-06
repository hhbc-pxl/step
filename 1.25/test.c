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
	//创建棋盘对应的数组
	char mine[ROWS][COLS];//存放布置好的雷的信息
	char show[ROWS][COLS];//存放的是排查出的雷的信息
	//初始化棋盘
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show,ROWS, COLS, '*');
	//打印棋盘
	displayboard(mine, ROW, COL);
	displayboard(show, ROW, COL);
	//设置雷
	SetMine(mine ,ROW,COL, EASY_COUNT);
	displayboard(mine, ROW, COL);
	//排查雷
	Findmine(mine,show,ROW,COL);
}

int main()
{
	srand((unsigned)time(NULL));
	int input;
	do
	{
		menu();
		printf("请选择\n");
		scanf("%d",&input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("游戏结束\n");
				break;
			default:
				printf("选择错误,请重新选择\n");
				break;
		}

	} while (input);
	return 0;
}