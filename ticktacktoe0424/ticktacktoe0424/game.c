#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//实现初始化棋盘
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
//实现打印棋盘
void Display_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)//打印row行,将棋盘一行 + ___看作一行打印内容 
	{
		for (j = 0; j < col; j++)//打印col列
		{
			printf(" %c ", board[i][j]);//将 %c 看作一个打印单位
			if (j < col - 1)//一行就前col-1个需要打印|,最后一个不打印
				printf("|");
		}
		printf("\n");//一行内容打印完后换行
		if (i < row - 1)//最后一行不打印
		{
			for (j = 0; j < col; j++)
			{
				printf("---");//将___视为一个整体
				if (j < col - 1)//一行就前col-1个需要打印|,最后一个不打印
					printf("|");
			}
		}
			//printf("___|___|___\n");//这种打印方式仅能打印三行三列的棋盘，不推荐
		printf("\n");//一行内容打印完后换行
	}
}

//实现玩家下棋
void Player_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家落子：>>\n");
	while (1)
	{
		printf("请输入落子的坐标：>>");
		scanf("%d %d", &x, &y);
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))//坐标合理性判断
		{
			//判断该坐标是否被占用
			if (board[x-1][y-1] == ' ')//玩家输入的1 1 对应的下标其实是 0 0
			{
				board[x-1][y-1] = '*';
				break;
			}
			else
			{
				printf("坐标已被占用，请重新输入\n");
			}
		}
		else
		{
			printf("坐标输入错误，请重新输入\n");
		}
	}

}

//实现电脑下棋
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
	//下面这个函数就是判断玩家是否有机会赢，如果能赢就堵住他

	int i = 0;
	int j = 0;
	while (0 == k)
	{
		//判断玩家在横行上是否会赢
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

		//判断玩家在竖列上是否会赢
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

	//判断玩家在对角线上是否会赢,又加了一个while是为了让判断对角线的代码成块。
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
	return k;//返回值如果是1那么已经对玩家进行了阻拦，如果是0则无需阻拦。
}



int Check_computer(char board[ROW][COL], int row, int col)//判断电脑下一步落子能否赢游戏
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (k == 0)
	{
		//判断电脑行排能否赢
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
		if (k != 0)//落子后跳出
			break;
		//判断电脑列排能否赢
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
	//判断电脑对角线能否赢
	while (0 == k)
	{
		//左上角到右下角对角线判断
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
		//左下角到右上角对角线判断
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

//实现电脑下棋优化
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

//判断棋盘是否满了
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

//实现判断游戏进展
char Is_win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//判断三行
	for (i = 0; i < row; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][0] == board[i][2]) && (board[i][0] != ' '))
		{
			return board[i][0];
		}
	}
	//判断三列
	for (i = 0; i < row; i++)
	{
		if ((board[0][i] == board[1][i]) && (board[0][i] == board[2][i]) && (board[0][i] != ' '))
		{
			return board[0][i];
		}
	}
	//判断两条对角线
	if ((board[0][0] == board[1][1]) && (board[0][0] == board[2][2]) && (board[0][0] != ' '))
	{
		return board[0][0];
	}
	if ((board[0][2] == board[1][1]) && (board[0][2] == board[2][0]) && (board[0][2] != ' '))
	{
		return board[0][2];
	}
	//判断平局  棋盘满了返回1，不满返回0
	int ret = Is_full(board, row, col);
	if (ret == 1)
		return 'Q';
	else
		return 'C';

}