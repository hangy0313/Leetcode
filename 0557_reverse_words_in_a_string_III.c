/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void reverseWord(char * s, int left, int right);
char * reverseWords(char * s);

int main()
{
    char test[] = "Let's take LeetCode contest";
    char* result;
    
    printf("before reverse => test = %s\n", test);
    result = reverseWords(test);
    printf("after  reverse => test = %s\n", test);
    return 0;
}

void reverseWord(char * s, int left, int right) {    
    while(left < right) {
        s[left] = s[left] ^ s[right];
        s[right] = s[left] ^ s[right];
        s[left] = s[left] ^ s[right];
        
        left++;
        right--;
    }
}

char * reverseWords(char * s){
    int left = 0;
    int right;
    
    for(right = 1;right < strlen(s);right++) {
        if(s[right] == ' ') {
            reverseWord(s, left, right-1);
            left = right+1;
        }
    }
    reverseWord(s, left, right-1);
    
    return s;
}
