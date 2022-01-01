/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);

int main()
{
    int arr1[2] = {1,3};
    int arr2[1] = {2};
    double result = findMedianSortedArrays(arr1, 2, arr2, 1);
    printf("result = %f\n", result);

    return 0;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int* arr;
    int arr_size;
    int index = 0, index1 = 0, index2 = 0;
    
    arr_size = nums1Size+nums2Size;
    arr = malloc(sizeof(int)*arr_size);
    
    while(index1 < nums1Size && index2 < nums2Size) {
        if(nums1[index1] < nums2[index2]) {
            arr[index++] = nums1[index1++];
        } else {
            arr[index++] = nums2[index2++];
        }
    }
    
    while(index1 < nums1Size)
        arr[index++] = nums1[index1++];
    
    while(index2 < nums2Size)
        arr[index++] = nums2[index2++];
    
    if(arr_size%2 == 0) {
        return (arr[arr_size/2]+arr[arr_size/2-1])/2.0;
    } else {
        return (double)arr[arr_size/2];
    }
}