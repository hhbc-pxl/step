#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3
#define COL 3
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
//��ʼ������
void Init_board(char board[ROW][COL], int row, int col);
//��ӡ����
void print_board(char board[ROW][COL], int row, int col);
//�������
void playermove(char board[ROW][COL], int row, int col);
//��������
void computermove(char board[ROW][COL], int row, int col);
//�����Ӯ
char checkwin(char board[ROW][COL], int row, int col);

//#  ����Ӯ 
//*  ��Ӯ
//c  ����
//f  ƽ��