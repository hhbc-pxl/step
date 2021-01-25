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
	//��ʼ������
	Init_board(board, ROW, COL );
	//��ӡ����
	print_board(board, ROW ,COL);
	while (1)
	{
		playermove(board, ROW, COL);//�������
		ret =checkwin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		print_board(board, ROW, COL);

		computermove(board, ROW, COL);//��������
		ret = checkwin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		print_board(board, ROW, COL);
	}
	if (ret == '#')
		printf("����Ӯ��\n");
	if (ret == '*')
		printf("��Ӯ��\n");
	if (ret == 'f')
		printf("˫��ƽ��\n");
	print_board(board, ROW, COL);
}

int main()
{   
	srand((unsigned)time(NULL));
	menu();
	int input=0;
	do
	{
		printf("��ѡ��:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����");
			break;
		}

	} while (input);
   
	return 0;

}