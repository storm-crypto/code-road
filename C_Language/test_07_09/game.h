//
// Created by ��� on 2022-07-09.
//

#ifndef TEST_07_09_GAME_H
#define TEST_07_09_GAME_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 9
#define COL 9

#define ROWS ROW + 2
#define COLS COL + 2

#define EASY_COUNT 10

// ��ʼ������
void init_board(char arr[ROWS][COLS], int rows, int cols, char set);

// ��ӡ����
void show_board(char arr[ROWS][COLS], int row, int col);

// ������
void set_mine(char mine[ROWS][COLS], int row, int col);

// �Ų���
void fine_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
#endif//TEST_07_09_GAME_H
