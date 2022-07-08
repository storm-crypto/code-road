//
// Created by 旭哥 on 2022-07-08.
//
void InitBoard(char board[3][3], int row, int col)
{
    int i = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }
}