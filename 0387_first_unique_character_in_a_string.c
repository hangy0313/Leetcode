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

int firstUniqChar(char * s);

int main()
{
    int result = firstUniqChar("leetcode");
    printf("result = %d\n", result);

    return 0;
}

int firstUniqChar(char * s){
    int hash[26] = {0};
    int index;
    int i;
    int pt = INT_MAX;
    
    for(index = 0;index < strlen(s);index++) 
        hash[s[index]-'a']++;
    
    for(index = 0;index < strlen(s);index++) {
        if(hash[s[index]-'a'] == 1) {
            if(index < pt) pt = index;
        }
    }
        
    if(pt == INT_MAX) return -1;
    return pt;
}

