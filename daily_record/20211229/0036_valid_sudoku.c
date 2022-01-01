/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    char board[9][9] = 
    // {{'5','3','.','.','7','.','.','.','.'}
    // ,{'6','.','.','1','9','5','.','.','.'}
    // ,{'.','9','8','.','.','.','.','6','.'}
    // ,{'8','.','.','.','6','.','.','.','3'}
    // ,{'4','.','.','8','.','3','.','.','1'}
    // ,{'7','.','.','.','2','.','.','.','6'}
    // ,{'.','6','.','.','.','.','2','8','.'}
    // ,{'.','.','.','4','1','9','.','.','5'}
    // ,{'.','.','.','.','8','.','.','7','9'}};
    {{'.','.','4','.','.','.','6','3','.'},
    {'.','.','.','.','.','.','.','.','.'},
    {'5','.','.','.','.','.','.','9','.'},
    {'.','.','.','5','6','.','.','.','.'},
    {'4','.','3','.','.','.','.','.','1'},
    {'.','.','.','7','.','.','.','.','.'},
    {'.','.','.','5','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.','.'}};

    bool flag_col[10] = {0};
    bool flag_row[9][10] = {0};
    bool flag_block[9][10] = {0};
    int row, col;
    
    for(row = 0;row < 9;row++) {
        for(col = 0;col <9;col++) {
            if(board[row][col] == '.') continue;
            
            int num = board[row][col] - '0';
            int block_num = row/3 + (col/3)*3;
            // printf("row = %d, col = %d\n", row, col);
            if(flag_col[num]) {
                // printf("col not valid\n");
                return false;
            }
            if(flag_row[col][num]) {
                // printf("row not valid\n");
                return false;
            }
            if(flag_block[block_num][num]) {
                // printf("block not valid\n");
                return false;
            }
            flag_row[col][num] = true;
            flag_col[num] = true;
            flag_block[block_num][num] = true;
        }
        memset(flag_col, 0, 10);
    }  

    return 0;
}



bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    bool flag_col[10] = {0};
    bool flag_row[9][10] = {0};
    bool flag_block[9][10] = {0};
    int row, col;
    
    for(row = 0;row < 9;row++) {
        for(col = 0;col <9;col++) {
            if(board[row][col] == '.') continue;
            
            int num = board[row][col] - '0';
            int block_num = row/3 + (col/3)*3;
            // printf("row = %d, col = %d\n", row, col);
            if(flag_col[num]) {
                // printf("col not valid\n");
                return false;
            }
            if(flag_row[col][num]) {
                // printf("row not valid\n");
                return false;
            }
            if(flag_block[block_num][num]) {
                // printf("block not valid\n");
                return false;
            }
            flag_row[col][num] = true;
            flag_col[num] = true;
            flag_block[block_num][num] = true;
        }
        memset(flag_col, 0, 10);
    }  
    
    return true;
}

