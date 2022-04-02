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
	char board[ROW][COL] = { 0 };//创建二维数组来存储棋盘下棋数据
	Init_board(board,ROW,COL);//初始化棋盘
	Display_board(board, ROW, COL);//打印棋盘
	char ret = 0;//接收游戏进行的进展
	//玩家赢：*  电脑赢：#  平局：Q   继续：C
	while (1)
	{
		Player_move(board, ROW, COL);//玩家下棋
		Display_board(board, ROW, COL);//打印棋盘
		ret = Is_win(board, ROW, COL);//判断游戏是否继续
		if (ret != 'C')
			break;
		Computer_move(board, ROW, COL);//电脑下棋
		Display_board(board, ROW, COL);//打印棋盘
		ret = Is_win(board, ROW, COL);//判断游戏是否继续
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("恭喜你，玩家赢得游戏！\n");
	}
	else if (ret == '#')
	{
		printf("很遗憾，电脑赢得游戏！\n");
	}
	else if (ret == 'Q')
	{
		printf("这把平局，还差一点点就赢了哦！\n");
	}
	Display_board(board, ROW, COL);//打印棋盘
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		game_menu();//打印游戏菜单
		printf("请选择：>>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			play_game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重选\n");
			break;
		}

	} while (input);
	
	return 0;
}


