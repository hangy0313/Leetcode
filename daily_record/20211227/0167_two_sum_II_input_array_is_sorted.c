/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize);

int main()
{
    int test[4] = {2,7,11,15};
    int index;
    int size;
    
    int* result = twoSum(test, 4, 9, &size);
    for(index = 0;index < size;index++) printf(" %d", result[index]);

    return 0;
}

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int low = 0;
    int high = numbersSize-1;
    int *ans;
    
    while(low < high) {
        int tmp = numbers[low] + numbers[high];
        if(tmp > target) {
            high--;
        } else if(tmp < target) {
            low++;
        } else {
            *returnSize = 2;
            ans = malloc(sizeof(int)*2);
            ans[0] = low+1;
            ans[1] = high+1;
            return ans;
        }
    }
    
    *returnSize = 2;
    return ans;
}