#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void game_menu(void)
{
	printf("*********************************\n");
	printf("********* 1.play game ***********\n");
	printf("********* 0.exit game ***********\n");
	printf("*********************************\n");

}
void play_game(void)
{
	char board[ROW][COL] = { 0 };//������ά�������洢������������
	Init_board(board,ROW,COL);//��ʼ������
	Display_board(board, ROW, COL);//��ӡ����
	char ret = 0;//������Ϸ���еĽ�չ
	//���Ӯ��*  ����Ӯ��#  ƽ�֣�Q   ������C
	while (1)
	{
		Player_move(board, ROW, COL);//�������
		Display_board(board, ROW, COL);//��ӡ����
		ret = Is_win(board, ROW, COL);//�ж���Ϸ�Ƿ����
		if (ret != 'C')
			break;
		Computer_move(board, ROW, COL);//��������
		Display_board(board, ROW, COL);//��ӡ����
		ret = Is_win(board, ROW, COL);//�ж���Ϸ�Ƿ����
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("��ϲ�㣬���Ӯ����Ϸ��\n");
	}
	else if (ret == '#')
	{
		printf("���ź�������Ӯ����Ϸ��\n");
	}
	else if (ret == 'Q')
	{
		printf("���ƽ�֣�����һ����Ӯ��Ŷ��\n");
	}
	Display_board(board, ROW, COL);//��ӡ����
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		game_menu();//��ӡ��Ϸ�˵�
		printf("��ѡ��>>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			play_game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������ѡ\n");
			break;
		}

	} while (input);
	
	return 0;
}


