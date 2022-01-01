/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool checkInclusion(char * s1, char * s2);

int main()
{
    bool result = checkInclusion("abc", "bbbca");
    printf("result = %d\n", result);

    return 0;
}

bool checkInclusion(char * s1, char * s2){
    int index1;
    int index2;
    int table1[128] = {0};
    int table2[128] = {0};
    
    if(strlen(s1) > strlen(s2)) return false;
    
    for(index1 = 0;index1 < strlen(s1);index1++) {
        table1[s1[index1]]++;
        table2[s2[index1]]++;
    }
    
    if(memcmp(table1, table2, sizeof(table1)) == 0) {
        // printf("TEST\n");
        return true;
    }
    
    for(index1 = strlen(s1);index1 < strlen(s2);index1++) {
        // printf("%d %d\n", index1-strlen(s1), index1);
        table2[s2[index1-strlen(s1)]]--;
        table2[s2[index1]]++;
        if(memcmp(table1, table2, sizeof(table1)) == 0) return true;
    }
    return false;
}

