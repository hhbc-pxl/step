#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10  // �׵ĸ���
//��ʼ������
void Initboard(char board[ROWS][COLS], int rows, int cols, char set);

//��ӡ����
void displayboard(char board[ROWS][COLS], int row, int col);

//������
void SetMine(char mine[ROWS][COLS], int row,int col, int count);

//mine ����׵���Ϣ
//count �׵ĸ���
//row ��
//col ��

//�Ų���
Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);