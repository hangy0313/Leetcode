/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes);

int main()
{
    return 0;
}

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int** arr;
    int index;
    
    *returnSize = numRows;
    *returnColumnSizes = malloc(sizeof(int)*numRows);
    arr = malloc(sizeof(int*)*numRows);
    for(index = 0;index < numRows;index++) {
        (*returnColumnSizes)[index] = index + 1;
        arr[index] = malloc(sizeof(int)*(*returnColumnSizes)[index]);
    }
    
    for(index = 0;index < numRows;index++) {
        for(int col = 0;col < (*returnColumnSizes)[index];col++) {
            if(index == 0) {
                arr[index][col] = 1;
                continue;
            }
            
            if(col == 0 || col == (*returnColumnSizes)[index]-1) {
                arr[index][col] = 1;
                continue;
            }
            
            arr[index][col] = arr[index-1][col-1] + arr[index-1][col];
        }
    }
    
    return arr;
}
