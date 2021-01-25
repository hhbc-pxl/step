#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
#include <stdio.h>
 void  Init_board(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0;i < ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			board[i][j] = ' ';
		}

	}

}

 //打印棋盘
 /*void print_board(char board[ROW][COL], int row, int col)
 {
	 int i = 0;
	 for (i = 0;i < row;i++)
	 {
		 printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
		 if(i<row-1)
		 printf("---|---|---\n");

	 }
 
 }*/
 void print_board(char board[ROW][COL], int row, int col)
 {
	 int i = 0,j=0;
	 for (i = 0;i < row;i++)
	 {

		 for (j = 0;j < col;j++)
		 {
			 printf(" %c ", board[i][j]);
			 if (j < col - 1)
				 printf("|");
		 }
		 printf("\n");
		 if (i < row - 1)
		 {
			 for (j = 0;j < col;j++)
			 {
				 printf("---");
				 if (j < col - 1)
					 printf("|");

			 }
			 printf("\n");
		 }
			 
	 
	 }

 }

 void playermove(char board[ROW][COL], int row, int col)
 {
	 int x = 0, y = 0;
	 printf("玩家走\n");
	 while (1)
	 {
		 printf("请输入一个坐标");
		 scanf("%d%d", &x, &y);
		 if (x >= 1 && x <= row && y >= 1 && y <=col)
		 {
			 if (board[x - 1][y - 1] != ' ')
			 {
				 printf("该坐标已被占用，请重新输入");
			 }
			 else
			 {
				 board[x - 1][y - 1] = '*';
				 break;
			 }
		 }
		 else
		 {
			 printf("坐标错误，请重新输入");
		 }
	 }
 }



 void computermove(char board[ROW][COL], int row, int col)
 {
	 printf("电脑走\n");
	 
	 while (1)
	 {
		 int x = rand() % row;
		 int y = rand() % col;
		 if (board[x][y] == ' ')
		 {
			 board[x][y] = '#';
			 break;
		 }
	 }
 }

 int full(char board[ROW][COL], int row, int col)
 {
	 int j = 0, i = 0;
	 for (i = 0;i < row;i++)
	 {
		 for (j = 0;j < col;j++)
		 {
			 if (board[i][j] == ' ')
				 return 0;
		 }
	 }
	 return 1;
 
 }


 char checkwin(char board[ROW][COL], int row, int col)
 {
	 int i = 0;
	 //三行
	 for (i = 0;i < row;i++)
	 {
		 if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		 {
			 return board[i][0];
		 }
	 }
     //三列 
	 for (i = 0;i < col;i++)
	 {
		 if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		 {
			 return board[0][i];
		 }
	 }
	 //对角线
	 if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	 {
		 return board[1][1];
	 }
	 if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	 {
		 return board[1][1];
	 }
	 //平局
	 if (full(board,row,col) == 1)
	 {
		 return 'f';
	 }
	 //游戏继续,没有赢和平局
	 return 'c';
 }