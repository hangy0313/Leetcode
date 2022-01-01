/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes);

int main()
{
    return 0;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes){
    /*
     *  matSize : integet pointer represent input array row number
     *  matColSize : integer pointer represent every row's row number of input array
     *       ex : input array = {
     *                          {1, 2, 3},
     *                          {1, 2, 3, 4}
     *                         }
     *         matSize = 2
     *         matColSize[0] = 3
     *         matColSize[1] = 4
     *
     *  r : reshap row number
     *  c : reshap column number
     *
     *  returnSize : integet pointer represent return row number
     *  returnColumnSizes : integer pointer represent return every row's column number
     *       ex : output array = {
     *                           {1, 2, 3},
     *                           {1, 2, 3}
     *                           }
     *         r = 2, c = 4
     *         returnSize = 2
     *         (*returnColumnSizes)[0] = 3 => returnColumnSizes[0][0]
     *         (*returnColumnSizes)[1] = 4 => returnColumnSizes[0][1]
     *
     */
    int** arr;
    int index;
    int totalNum = r*c;
    
    if(totalNum != matSize*(*matColSize)){
        *returnSize = matSize;
        *returnColumnSizes = malloc(sizeof(int)*matSize);
        for(index = 0;index < matSize;index++) {
            (*returnColumnSizes)[index] = matColSize[index];
        }
        return mat;
    }
    
    *returnSize = r;
    *returnColumnSizes = malloc(sizeof(int)*r);
    
    arr = malloc(sizeof(int*)*r);
    for(index = 0;index < r;index++) {
        arr[index] = malloc(sizeof(int)*c);
        (*returnColumnSizes)[index] = c;
    }   
    
    for(index = 0;index < totalNum;index++) {
        arr[index/c][index%c] = mat[index/(*matColSize)][index%(*matColSize)];
    }
    
    return arr;
}
