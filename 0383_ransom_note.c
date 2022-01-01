/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

bool canConstruct(char * ransomNote, char * magazine);

int main()
{
    int result = canConstruct("aa", "aab");
    printf("result = %d\n", result);

    return 0;
}

bool canConstruct(char * ransomNote, char * magazine){
    int table[26] = {0};
    int index;
    
    if(strlen(ransomNote) > strlen(magazine)) return false;
    
    while(*magazine) table[*magazine++ - 'a']++;
    while(*ransomNote) table[*ransomNote++ - 'a']--;
    
    for(index = 0;index < 26;index++) {
        if(table[index] < 0) return false;
    }
    return true;
}

