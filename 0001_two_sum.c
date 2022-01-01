/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main()
{
    int test1[4] = {-3, 4, 3, 90};
    int target = 0;
    int returnSize;
    int* ans;
    int index;
    
    ans = twoSum(test1, 4, target, &returnSize);
    
    for(index = 0;index < returnSize;index++) printf("%d ", *(ans+index));

    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int min = *nums;
    int max = *nums;
    int* hash_table;
    int hash_table_size;
    int index;
    int *ans;
    
    for(index = 1;index < numsSize;index++) {
        max = nums[index] > max ? nums[index]:max;
        min = nums[index] < min ? nums[index]:min;
    }
    
    hash_table_size = max-min+1;
    hash_table = calloc(hash_table_size, sizeof(int));
    
    *returnSize = 2;
    ans = calloc(*returnSize, sizeof(int));
    
    for(index = 0;index < numsSize;index++) {
        hash_table[nums[index]-min] = index;
    }
    
    for(index = 0;index < numsSize;index++) {
        int tmp = target - nums[index] - min;
        if(tmp < 0 || tmp >= hash_table_size) continue;
        if(hash_table[tmp]) {
            ans[0] = index;
            ans[1] = hash_table[tmp];
        }
        if(ans[0] == ans[1]) continue;
        free(hash_table);
        return ans;
    }
    
    return ans;
}