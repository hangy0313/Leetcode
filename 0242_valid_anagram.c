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

bool isAnagram(char * s, char * t);

int main()
{
    int result = isAnagram("leetcode", "coleedet");
    printf("result = %d\n", result);

    return 0;
}

bool isAnagram(char * s, char * t){
    int table1[26] = {0};
    int table2[26] = {0};
    int index = 0;
    
    if(strlen(s) != strlen(t)) return false;
    
    while(index < strlen(s)) {
        table1[s[index]-'a']++;
        table2[t[index++]-'a']++;
    }
    
    if(memcmp(table1, table2, sizeof(table1)) == 0) return true;
    
    return false;
}

