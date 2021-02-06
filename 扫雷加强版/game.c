#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void Initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0, j = 0;
	for (i = 0;i < rows;i++)
	{
		for (j = 0;j < cols;j++)
		{
			board[i][j] = set;
		}
	}

}

void displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;
	printf("----------------ɨ����Ϸ����������������\n");
	for (i = 0;i <= col;i++)
	{
		printf("%d.", i);
	}
	printf("\n");
	for (i = 1;i <= row;i++)  //�˴�i��j���Ǵ�1��ʼ
	{
		printf("%d.", i);
		for (j = 1;j <= col;j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("----------------ɨ����Ϸ����������������\n");

}


void SetMine(char mine[ROWS][COLS], int row, int col, int count)
{
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')//x��y���괦û����
		{
			mine[x][y] = '1';
			count--;
		}

	}

}

//ͳ��x��y��Χ��һȦ�м�����
int GetMinecont(char mine[ROWS][COLS], int x, int y)
{
	int i = 0, j = 0, sum = 0;
	for (i = x - 1;i <= x + 1;i++)
	{
		for (j = y - 1;j <= y + 1;j++)
		{
			sum += mine[i][j];
		}

	}
	return sum - 9 * '0';


}




Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	while (win < row * col - EASY_COUNT)
	{
		printf("������Ҫ�Ų������: ");
		int x = 0, y = 0;
		scanf("%d %d", &x, &y);
		//����ĺϷ���
		//�������ǲ����ף������ף�ͳ���׵ĸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը����\n");
				displayboard(mine, row, col);
				break;
			}
			else
			{
				int count = GetMinecont(mine, x, y);
				show[x][y] = count + '0';
				if (count == 0)
				{
					openMine(mine, show, x, y);

				}
				displayboard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("�����겻�Ϸ�������������");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("��ϲ�����׳ɹ�\n");
		displayboard(mine, row, col);
	}

}


//չ��
void openMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int ret = GetMinecont(mine, x, y);
	if (ret == 0)
	{
		show[x][y] = ' ';
		if ((x - 1) > 0 && (y - 1) > 0 && (show[x - 1][y - 1] == '*'))
			openMine(mine, show, x - 1, y - 1);
		if ((x - 1) > 0 && (y) > 0 && (show[x - 1][y] == '*'))
			openMine(mine, show, x - 1, y);
		if ((x - 1) > 0 && (y + 1) > 0 && (show[x - 1][y + 1] == '*'))
			openMine(mine, show, x - 1, y + 1);
		if ((x) > 0 && (y - 1) > 0 && (show[x][y - 1] == '*'))
			openMine(mine, show, x, y - 1);
		if ((x) > 0 && (y + 1) > 0 && (show[x][y + 1] == '*'))
			openMine(mine, show, x, y + 1);
		if ((x + 1) > 0 && (y - 1) > 0 && (show[x + 1][y - 1] == '*'))
			openMine(mine, show, x + 1, y - 1);
		if ((x + 1) > 0 && (y) > 0 && (show[x + 1][y] == '*'))
			openMine(mine, show, x + 1, y);
		if ((x + 1) > 0 && (y + 1) > 0 && (show[x + 1][y + 1] == '*'))
			openMine(mine, show, x + 1, y + 1);
	}
	else
		show[x][y] = ret + '0';
}
