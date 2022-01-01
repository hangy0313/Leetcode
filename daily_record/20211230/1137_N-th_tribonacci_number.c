/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int tribonacci(int n);

int main()
{
    printf("tribonacci N0.10 = %d\n", tribonacci(10));

    return 0;
}


int tribonacci(int n){
    int a = 0, b = 1, c = 1, d;
    
    if(n == 0) return 0;
    if(n < 3) return 1;
    
    while(n > 2) {
        d = a+b+c;
        a = b;
        b = c;
        c = d;
        n--;
    }
    
    return d;
}

