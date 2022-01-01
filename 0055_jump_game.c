/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize);

int main()
{
    bool result;
    
    int path1[3] = {2,0,0};
    result = canJump(path1, 3);
    printf("result =  %d\n", result);
    
    int path2[5] = {2,3,1,1,4};
    result = canJump(path2, 5);
    printf("result =  %d\n", result);

    return 0;
}

bool canJump(int* nums, int numsSize){
    int position = numsSize-1;
    int index;
    
    for(index = numsSize-2;index >=0;index--) {
        if(index+nums[index] >= position) position = index;
    }
    
    return position==0;
}