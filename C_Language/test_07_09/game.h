//
// Created by 旭哥 on 2022-07-09.
//

#ifndef TEST_07_09_GAME_H
#define TEST_07_09_GAME_H

#include <stdio.h>

#define ROW 9
#define COL 9

#define ROWS ROW + 2
#define COLS COL + 2

// 初始化棋盘
void init_board(char arr[ROWS][COLS], int rows, int cols, char set);

// 打印棋盘
void show_board(char arr[ROWS][COLS], int row, int col);
#endif//TEST_07_09_GAME_H
