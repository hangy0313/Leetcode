/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void moveZeroes(int* nums, int numsSize);

int main()
{
    int test[6] = {7,1,6,0,9,4};
    int index;
    
    moveZeroes(test, 6);
    for(index = 0;index < 6;index++) printf(" %d", test[index]);

    return 0;
}

void moveZeroes(int* nums, int numsSize){
    int cur, index;
    
    cur = 0;
    for(index = 0;index < numsSize;index++) {
        if(nums[index] != 0) {
            nums[cur] = nums[index];
            cur++;
        }
    }
    while(cur < numsSize)
        nums[cur++] = 0;

}