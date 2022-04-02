#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//ʵ�ֳ�ʼ������
void Init_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//ʵ�ִ�ӡ����
void Display_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)//��ӡrow��,������һ�� + ___����һ�д�ӡ���� 
	{
		for (j = 0; j < col; j++)//��ӡcol��
		{
			printf(" %c ", board[i][j]);//�� %c ����һ����ӡ��λ
			if (j < col - 1)//һ�о�ǰcol-1����Ҫ��ӡ|,���һ������ӡ
				printf("|");
		}
		printf("\n");//һ�����ݴ�ӡ�����
		if (i < row - 1)//���һ�в���ӡ
		{
			for (j = 0; j < col; j++)
			{
				printf("---");//��___��Ϊһ������
				if (j < col - 1)//һ�о�ǰcol-1����Ҫ��ӡ|,���һ������ӡ
					printf("|");
			}
		}
			//printf("___|___|___\n");//���ִ�ӡ��ʽ���ܴ�ӡ�������е����̣����Ƽ�
		printf("\n");//һ�����ݴ�ӡ�����
	}
}

//ʵ���������
void Player_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������ӣ�>>\n");
	while (1)
	{
		printf("���������ӵ����꣺>>");
		scanf("%d %d", &x, &y);
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))//����������ж�
		{
			//�жϸ������Ƿ�ռ��
			if (board[x-1][y-1] == ' ')//��������1 1 ��Ӧ���±���ʵ�� 0 0
			{
				board[x-1][y-1] = '*';
				break;
			}
			else
			{
				printf("�����ѱ�ռ�ã�����������\n");
			}
		}
		else
		{
			printf("���������������������\n");
		}
	}

}

//ʵ�ֵ�������
//void Computer_move(char board[ROW][COL], int row, int col)
//{
//
//	while (1)
//	{
//		int x = rand() % row;
//		int y = rand() % col;
//		if (board[x][y] == ' ')
//		{
//			board[x][y] = '#';
//			break;
//		}
//	}
//}

int Judge_player(char board[ROW][COL], int row, int col, int k)
{
	//����������������ж�����Ƿ��л���Ӯ�������Ӯ�Ͷ�ס��

	int i = 0;
	int j = 0;
	while (0 == k)
	{
		//�ж�����ں������Ƿ��Ӯ
		for (i = 0; i < row; i++)
		{
			if (board[i][0] == board[i][1] && board[i][1] == '*' && board[i][2] == ' ')
			{
				board[i][2] = '#';
				k = 1;
				break;
			}

			if (board[i][0] == board[i][2] && board[i][0] == '*' && board[i][1] == ' ')
			{
				board[i][1] = '#';
				k = 1;
				break;
			}

			if (board[i][1] == board[i][2] && board[i][1] == '*' && board[i][0] == ' ')
			{
				board[i][0] = '#';
				k = 1;
				break;
			}
		}
		if (k != 0)
			break;

		//�ж�������������Ƿ��Ӯ
		for (j = 0; j < col; j++)
		{
			if (board[0][j] == board[1][j] && board[1][j] == '*' && board[2][j] == ' ')
			{
				board[2][j] = '#';
				k = 1;
				break;
			}

			if (board[0][j] == board[2][j] && board[2][j] == '*' && board[1][j] == ' ')
			{
				board[1][j] = '#';
				k = 1;
				break;
			}

			if (board[1][j] == board[2][j] && board[2][j] == '*' && board[0][j] == ' ')
			{
				board[0][j] = '#';
				k = 1;
				break;
			}
		}
		break;
	}

	//�ж�����ڶԽ������Ƿ��Ӯ,�ּ���һ��while��Ϊ�����ж϶Խ��ߵĴ���ɿ顣
	while (0 == k)
	{
		if (board[0][0] == board[1][1] && board[1][1] == '*' && board[2][2] == ' ')
		{
			board[2][2] = '#';
			k = 1;
			break;
		}

		if (board[0][0] == board[2][2] && board[2][2] == '*' && board[1][1] == ' ')
		{
			board[1][1] = '#';
			k = 1;
			break;
		}

		if (board[1][1] == board[2][2] && board[1][1] == '*' && board[0][0] == ' ')
		{
			board[0][0] = '#';
			k = 1;
			break;
		}

		if (board[0][2] == board[1][1] && board[0][2] == '*' && board[2][0] == ' ')
		{
			board[2][0] = '#';
			k = 1;
			break;
		}

		if (board[0][2] == board[2][0] && board[2][0] == '*' && board[1][1] == ' ')
		{
			board[1][1] = '#';
			k = 1;
			break;
		}

		if (board[1][1] == board[2][0] && board[2][0] == '*' && board[0][2] == ' ')
		{
			board[0][2] = '#';
			k = 1;
			break;
		}
		break;
	}
	return k;//����ֵ�����1��ô�Ѿ�����ҽ����������������0������������
}



int Check_computer(char board[ROW][COL], int row, int col)//�жϵ�����һ�������ܷ�Ӯ��Ϸ
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (k == 0)
	{
		//�жϵ��������ܷ�Ӯ
		for (i = 0; i < row; i++)
		{
			if (board[i][0] == board[i][1] && board[i][0] == '#' && board[i][2] == ' ')
			{
				board[i][2] = '#';
				k = 1;
				break;
			}
			if (board[i][0] == board[i][2] && board[i][0] == '#' && board[i][1] == ' ')
			{
				board[i][1] = '#';
				k = 1;
				break;
			}
			if (board[i][1] == board[i][2] && board[i][1] == '#' && board[i][0] == ' ')
			{
				board[i][0] = '#';
				k = 1;
				break;
			}
		}
		if (k != 0)//���Ӻ�����
			break;
		//�жϵ��������ܷ�Ӯ
		for (j = 0; j < col; j++)
		{
			if (board[0][j] == board[1][j] && board[0][j] == '#' && board[2][j] == ' ')
			{
				board[2][j] = '#';
				k = 1;
				break;
			}
			if (board[0][j] == board[2][j] && board[0][j] == '#' && board[1][j] == ' ')
			{
				board[1][j] = '#';
				k = 1;
				break;
			}
			if (board[2][j] == board[1][j] && board[0][j] == '#' && board[0][j] == ' ')
			{
				board[0][j] = '#';
				k = 1;
				break;
			}
		}
		break;
	}
	//�жϵ��ԶԽ����ܷ�Ӯ
	while (0 == k)
	{
		//���Ͻǵ����½ǶԽ����ж�
		if (board[0][0] == board[1][1] && board[0][0] == '#' && board[2][2] == ' ')
		{
			board[2][2] = '#';
			k = 1;
			break;
		}
		if (board[0][0] == board[2][2] && board[0][0] == '#' && board[1][1] == ' ')
		{
			board[1][1] = '#';
			k = 1;
			break;
		}
		if (board[1][1] == board[2][2] && board[0][0] == '#' && board[0][0] == ' ')
		{
			board[0][0] = '#';
			k = 1;
			break;
		}
		//���½ǵ����ϽǶԽ����ж�
		if (board[2][0] == board[1][1] && board[2][0] == '#' && board[0][2] == ' ')
		{
			board[0][2] = '#';
			k = 1;
			break;
		}
		if (board[2][0] == board[0][2] && board[2][0] == '#' && board[1][1] == ' ')
		{
			board[1][1] = '#';
			k = 1;
			break;
		}
		if (board[0][2] == board[1][1] && board[0][2] == '#' && board[2][0] == ' ')
		{
			board[2][0] = '#';
			k = 1;
			break;
		}
		break;
	}
	k = Judge_player(board, row, col, k);
	return k;
}

//ʵ�ֵ��������Ż�
void Computer_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	int ret = 0;
	ret = Check_computer(board, row, col);
	while (0 == ret)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//�ж������Ƿ�����
int Is_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				count++;
		}
	}
	if (count == 0)
		return 1;
	else
		return 0;
}

//ʵ���ж���Ϸ��չ
char Is_win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//�ж�����
	for (i = 0; i < row; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][0] == board[i][2]) && (board[i][0] != ' '))
		{
			return board[i][0];
		}
	}
	//�ж�����
	for (i = 0; i < row; i++)
	{
		if ((board[0][i] == board[1][i]) && (board[0][i] == board[2][i]) && (board[0][i] != ' '))
		{
			return board[0][i];
		}
	}
	//�ж������Խ���
	if ((board[0][0] == board[1][1]) && (board[0][0] == board[2][2]) && (board[0][0] != ' '))
	{
		return board[0][0];
	}
	if ((board[0][2] == board[1][1]) && (board[0][2] == board[2][0]) && (board[0][2] != ' '))
	{
		return board[0][2];
	}
	//�ж�ƽ��  �������˷���1����������0
	int ret = Is_full(board, row, col);
	if (ret == 1)
		return 'Q';
	else
		return 'C';

}