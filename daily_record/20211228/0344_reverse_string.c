/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void reverseString(char* s, int sSize);

int main()
{
    char test[5] = "abcde";
    
    printf("before reverse => test = %s\n", test);
    reverseString(test, 5);
    printf("after  reverse => test = %s\n", test);
    return 0;
}

void reverseString(char* s, int sSize){
    int left = 0;
    int right = sSize-1;
    
    while(left < right) {
        s[left] = s[left] ^ s[right];
        s[right] = s[left] ^ s[right];
        s[left] = s[left] ^ s[right];
        left++;
        right--;
    }
}
