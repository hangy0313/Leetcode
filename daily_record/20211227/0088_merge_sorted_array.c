/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);

int main()
{
    int test1[1] = {0};
    int test2[1] = {1};
    int index;
    
    merge(test1, 1, 0, test2, 1, 1);
    for(index = 0;index < 1;index++) printf(" %d", test1[index]);

    return 0;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int index = m+n-1;
    int index1 = m-1;
    int index2 = n-1;
    
    while(index1 >= 0 && index2 >= 0) {
        if(nums1[index1] > nums2[index2]) {
            nums1[index] = nums1[index1];
            index--;
            index1--;
        } else {
            nums1[index] = nums2[index2];
            index--;
            index2--;
        }
    }
    
    while(index1 >= 0) 
        nums1[index--] = nums1[index1--];
    
    while(index2 >= 0) 
        nums1[index--] = nums2[index2--];
    
}