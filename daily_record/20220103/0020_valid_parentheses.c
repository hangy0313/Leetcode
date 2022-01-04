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

bool isValid(char * s);

int main()
{
    int result = isValid("({[]})");
    printf("%s valid = %d\n", "({[]})", result);
    
    return 0;
}

bool isValid(char * s){
    char* stack;
    int pt = -1;
    int index = 0;
    
    stack = malloc(sizeof(char)*5000);
    while(s[index]) {
        if(s[index] == ')') {
            if(pt < 0) return false;
            if(stack[pt] != '(') return false;
            pt--;
        }
        else if(s[index] == ']') {
            if(pt < 0) return false;
            if(stack[pt] != '[') return false;
            pt--;
        }
        else if(s[index] == '}') {
            if(pt < 0) return false;
            if(stack[pt] != '{') return false;
            pt--;
        } else {
            stack[++pt] = s[index];
        }
        // for(int i = 0;i <= pt;i++) printf(" %c", stack[pt]);
        // printf("\n");
        index++;
    }
    
    if(pt != -1) return false;
    
    return true;
}


