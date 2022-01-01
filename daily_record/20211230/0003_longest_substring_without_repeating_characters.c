/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int lengthOfLongestSubstring(char * s);

int main()
{
    int result = lengthOfLongestSubstring("abcabccc");
    printf("result = %d\n", result);

    return 0;
}


int lengthOfLongestSubstring(char * s){
    int max = 1;
    int count = 0;
    int index;
    int index2;
    bool table[128] = {0};
    
    if(strlen(s) == 0) return 0;
    
    for(index = 0;index < strlen(s);index++) {
        count = 0;
        for(index2 = index;index2 < strlen(s);index2++) {
            if(table[(int)s[index2]]) {
                memset(table, 0, 128);
                if(count > max) {
                    // printf("s[%d] %c\n", index2, s[index2]);
                    max = count;
                }
                count = 0;
            }
            table[(int)s[index2]] = true;
            count++;
        }
        memset(table, 0, 128);
        if(count > max) max = count;
    }
    
    
    return max;
}

