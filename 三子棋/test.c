#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("***************************************\n");
	printf("*********1   play game ****************\n");
	printf("*********0   exit game ****************\n");
	printf("***************************************\n");

}
void game()
{
	
	char ret;
	char board[ROW][COL];
	//初始化棋盘
	Init_board(board, ROW, COL );
	//打印棋盘
	print_board(board, ROW ,COL);
	while (1)
	{
		playermove(board, ROW, COL);//玩家下棋
		ret =checkwin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		print_board(board, ROW, COL);

		computermove(board, ROW, COL);//电脑下棋
		ret = checkwin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		print_board(board, ROW, COL);
	}
	if (ret == '#')
		printf("电脑赢了\n");
	if (ret == '*')
		printf("你赢了\n");
	if (ret == 'f')
		printf("双方平局\n");
	print_board(board, ROW, COL);
}

int main()
{   
	srand((unsigned)time(NULL));
	menu();
	int input=0;
	do
	{
		printf("请选择:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误");
			break;
		}

	} while (input);
   
	return 0;

}