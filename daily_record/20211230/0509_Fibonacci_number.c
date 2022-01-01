/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int fib(int n);

int main()
{
    printf("fib N0.10 = %d\n", fib(10));

    return 0;
}


int fib(int n){
    int a = 0;
    int b = 1;
    int c;
    
    if(n == 0) return 0;
    if(n < 3) return 1;
    
    // return fib(n-1)+fib(n-2);
    while(n > 1) {
        c = a+b;
        a = b;
        b = c;
        n--;
    }
    
    return c;
}

