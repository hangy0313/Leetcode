/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void sort(int* arr, int size);
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);

int main()
{
    int test1[4] = {1,2,2,1};
    int test2[2] = {2,2};
    int size;
    int index;
    
    int* result = intersect(test1, 4, test2, 2, &size);
    printf("size = %d\n", size);
    for(index = 0;index < size;index++) printf(" %d", result[index]);

    return 0;
}


void sort(int* arr, int size) {
    int index1, index2;
    
    for(index1 = 0;index1 < size-1;index1++) {
        for(index2 = index1+1;index2 < size;index2++) {
            if(arr[index1] > arr[index2]) {
                arr[index1] = arr[index1] ^ arr[index2];
                arr[index2] = arr[index1] ^ arr[index2];
                arr[index1] = arr[index1] ^ arr[index2];
            }
        }
    }
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int index1, index2;
    int* ans;
    
    if(nums1Size > nums2Size) ans = malloc(sizeof(int)*nums2Size);
    else ans = malloc(sizeof(int)*nums1Size);
    //malloc(sizeof(int)*100);
    
    sort(nums1, nums1Size);
    sort(nums2, nums2Size);
    
    *returnSize = 0;
    index1 = 0;
    index2 = 0;
    while(index1 < nums1Size && index2 < nums2Size) {
        if(nums1[index1] < nums2[index2]) {
            index1++;
        } else if(nums1[index1] > nums2[index2]) {
            index2++;
        } else {
            *(ans+(*returnSize)) = nums1[index1];
            (*returnSize)++;
            index1++;
            index2++;
        }
    }
    
    return ans;
}