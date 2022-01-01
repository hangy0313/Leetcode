/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPowerOfThree(int n);

int main()
{
    bool result;
    
    result = isPowerOfThree(0);
    printf("result = %d\n", result);
    
    result = isPowerOfThree(27);
    printf("result = %d\n", result);

    return 0;
}

bool isPowerOfThree(int n){
    if(!n) return false;
    while(n) {
        if(n == 1) return true;
        if(n%3 != 0) return false;
        n /= 3;
    }
    
    return true;
}