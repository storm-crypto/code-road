//
// Created by 旭哥 on 2022-07-08.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 3
#define COL 3
// 初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);
// 打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);
// 玩家下棋
void play_move(char board[ROW][COL], int row, int col);
// 电脑下棋
void computer_move(char board[ROW][COL], int row, int col);
#endif//GAME_GAME_H
