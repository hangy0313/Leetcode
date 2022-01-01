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

void paint(int** image, int imageSize, int* imageColSize, int x, int y, int newColor, int oldColor);
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes);
int main()
{

    return 0;
}

void paint(int** image, int imageSize, int* imageColSize, int x, int y, int newColor, int oldColor) {
    if(x < 0 || x >= imageSize) return;
    if(y < 0 || y >= imageColSize[x]) return;
    
    if(image[x][y] == oldColor) {
        image[x][y] = newColor;
        paint(image, imageSize, imageColSize, x-1, y, newColor, oldColor);
        paint(image, imageSize, imageColSize, x, y-1, newColor, oldColor);
        paint(image, imageSize, imageColSize, x+1, y, newColor, oldColor);
        paint(image, imageSize, imageColSize, x, y+1, newColor, oldColor);
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes){
    int index;
    
    *returnSize = imageSize;
    *returnColumnSizes = malloc(sizeof(int)*imageSize);
    for(index = 0;index < imageSize;index++){
        (*returnColumnSizes)[index] = imageColSize[index];
    }
    
    if(image[sr][sc] != newColor)
        paint(image, imageSize, imageColSize, sr, sc, newColor, image[sr][sc]);
    
    return image;
}

