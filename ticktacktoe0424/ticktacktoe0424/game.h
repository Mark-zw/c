#define _CRT_SECURE_NO_WARNINGS 1 
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//定义行号和列号
#define ROW  3
#define COL  3
//初始化棋盘声明
void Init_board(char board[ROW][COL], int row, int col);
//打印棋盘声明
void Display_board(char board[ROW][COL], int row, int col);

//玩家下棋声明
void Player_move(char board[ROW][COL], int row, int col);
//电脑下棋声明
void Computer_move(char board[ROW][COL], int row, int col);

//判断游戏进展
char Is_win(char board[ROW][COL], int row, int col);

//判断电脑能否赢
int Check_computer(char board[ROW][COL], int row, int col);

//判断玩家能否赢
int Judge_player(char board[ROW][COL], int row, int col, int k);