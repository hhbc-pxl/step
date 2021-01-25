#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3
#define COL 3
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
//初始化棋盘
void Init_board(char board[ROW][COL], int row, int col);
//打印棋盘
void print_board(char board[ROW][COL], int row, int col);
//玩家下棋
void playermove(char board[ROW][COL], int row, int col);
//电脑下棋
void computermove(char board[ROW][COL], int row, int col);
//检测输赢
char checkwin(char board[ROW][COL], int row, int col);

//#  电脑赢 
//*  人赢
//c  继续
//f  平局