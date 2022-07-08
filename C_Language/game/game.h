//
// Created by –Ò∏Á on 2022-07-08.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H
#include <stdio.h>

#define ROW 3
#define COL 3
// ≥ı ºªØ∆Â≈Ã
void InitBoard(char board[ROW][COL], int row, int col);
// ¥Ú”°∆Â≈Ã
void DisplayBoard(char board[ROW][COL], int row, int col);
// ÕÊº“œ¬∆Â
void play_move(char board[ROW][COL], int row, int col);
#endif//GAME_GAME_H
