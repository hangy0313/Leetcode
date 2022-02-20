/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int missingNumber(int* nums, int numsSize)
{
    //we want to Xor all numbers from 0 to n twice so should be zero
    //because num^num = 0 
    //but number that is missing will appear only once in Xor, and that's what will be left..
    
    int missing_number = numsSize;
    for(int i =0; i < numsSize; i++)
        missing_number ^= nums[i] ^ i;
    
    return missing_number;
}

int main()
{
    printf("Hello World");

    return 0;
}
