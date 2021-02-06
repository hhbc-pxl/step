#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void Initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0, j = 0;
	for(i = 0;i < rows;i++)
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
	printf("----------------扫雷游戏————————\n");
	for (i = 0;i <= col;i++)
	{
		printf("%d.",i);
	}
	printf("\n");
	for (i = 1;i <= row;i++)  //此处i与j都是从1开始
	{
		printf("%d.", i);
		for (j = 1;j <= col;j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("----------------扫雷游戏————————\n");

}


void SetMine(char mine[ROWS][COLS], int row, int col, int count)
{
	while (count)
	{
		int x =  rand() % row + 1;
		int y =  rand() % col + 1;
		if (mine[x][y] =='0')//x，y坐标处没有雷
		{
			mine[x][y] = '1';
			count--;
		}

	}

}

//统计x，y周围的一圈有几个雷
int GetMinecont(char mine[ROWS][COLS],int x, int y)
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
	while (win<row*col-EASY_COUNT)
	{
		printf("请输入要排查的坐标: ");
		int x = 0, y = 0;
		scanf("%d %d",&x,&y);
		//坐标的合法性
		//该坐标是不是雷，不是雷，统计雷的个数
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				displayboard(mine, row, col);
				break;
			}   
			else
			{
				int count = GetMinecont(mine, x, y);
				show[x][y] = count + '0';
				displayboard(show,row,col);
				win++;
			}
		}
		else
		{
			printf("该坐标不合法，请重新输入");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你排雷成功\n");
		displayboard(mine, row, col);
	}

}