/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool searchMatrix(int** matrix, int matrixSize, int matrixColSize, int target);

int main()
{
    return 0;
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int row = matrixSize;
    // int col = matrixColSize[0];
    int left = 0;
    int right = row*matrixColSize[0]-1;
    int mid;
    
    while(left <= right) {
        mid = (left+right)/2;
        if(target == matrix[mid/matrixColSize[0]][mid%matrixColSize[0]]) {
            return true;
        }else if(target > matrix[mid/matrixColSize[0]][mid%matrixColSize[0]]) {
            left = mid+1;
        }else {
            right = mid-1;
        } 
    }
    return false;
}
