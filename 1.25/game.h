#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10  // 雷的个数
//初始化棋盘
void Initboard(char board[ROWS][COLS], int rows, int cols, char set);

//打印棋盘
void displayboard(char board[ROWS][COLS], int row, int col);

//布置雷
void SetMine(char mine[ROWS][COLS], int row,int col, int count);

//mine 存放雷的信息
//count 雷的个数
//row 行
//col 列

//排查雷
Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);