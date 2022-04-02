#define _CRT_SECURE_NO_WARNINGS 1 
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//�����кź��к�
#define ROW  3
#define COL  3
//��ʼ����������
void Init_board(char board[ROW][COL], int row, int col);
//��ӡ��������
void Display_board(char board[ROW][COL], int row, int col);

//�����������
void Player_move(char board[ROW][COL], int row, int col);
//������������
void Computer_move(char board[ROW][COL], int row, int col);

//�ж���Ϸ��չ
char Is_win(char board[ROW][COL], int row, int col);

//�жϵ����ܷ�Ӯ
int Check_computer(char board[ROW][COL], int row, int col);

//�ж�����ܷ�Ӯ
int Judge_player(char board[ROW][COL], int row, int col, int k);