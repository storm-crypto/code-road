//
// Created by ???? on 2022-07-08.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 3
#define COL 3
// ??ʼ??????
void InitBoard(char board[ROW][COL], int row, int col);

// ??ӡ????
void DisplayBoard(char board[ROW][COL], int row, int col);

// ????????
void play_move(char board[ROW][COL], int row, int col);

// ????????
void computer_move(char board[ROW][COL], int row, int col);

// ?ж???Ӯ?ĺ???
char is_win(char board[ROW][COL], int row, int col);

#endif//GAME_GAME_H
