/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

int vist(int** grid, int gridSize, int* gridColSize, int x, int y, int **visted);
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize);

int main()
{
    int visted[9] = {0};
    int index;
    
    vist(visted, 0, 0);
    for(index = 0;index < 9;index++) printf(" %d", visted[index]);
    return 0;
}

int vist(int** grid, int gridSize, int* gridColSize, int x, int y, int **visted) {
    if(x < 0 || x >= gridSize) return 0;
    if(y < 0 || y >= gridColSize[0]) return 0;
    if(grid[x][y] == 0 || visted[x][y] == 1) return 0;

    visted[x][y] = 1;
    int left = vist(grid, gridSize, gridColSize, x-1, y, visted);
    int up = vist(grid, gridSize, gridColSize, x, y+1, visted);
    int right = vist(grid, gridSize, gridColSize, x+1, y, visted);
    int down = vist(grid, gridSize, gridColSize, x, y-1, visted);
    
    return left+up+down+right+1;
} 

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int **visted;
    int index1, index2;
    int max = -1;
    
    //create and initial visted table 
    visted = malloc(sizeof(int*)*gridSize);
    for(index1 = 0;index1 < gridSize;index1++) {
        visted[index1] = malloc(sizeof(int)*gridColSize[0]);
    }
    for(index1 = 0;index1 < gridSize;index1++)
        for(index2 = 0;index2 < gridColSize[0];index2++)
            visted[index1][index2] = 0;
    
    for(index1 = 0;index1 < gridSize;index1++) {
        for(index2 = 0;index2 < gridColSize[0];index2++) {
            int count = vist(grid, gridSize, gridColSize, index1, index2, visted);
            if(count > max) max = count;
        }
    }
    return max;
}

