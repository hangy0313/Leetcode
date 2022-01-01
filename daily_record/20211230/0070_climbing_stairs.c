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

int climbStairs(int n);

int main()
{
    int result = climbStairs(5);
    printf("result = %d\n", result);

    return 0;
}

// n = 1 => 1
// n = 2 => 2
// n = 3 => 3
// n = 4 => 5
// n = 5 => 8
// f(n) = f(n-1)+f(n-2)
int climbStairs(int n){
    if(n < 4) return n;
    int a = 2, b = 3, c;
    
    while(n-- > 3) {
        c = a+b;
        a = b;
        b = c;
    }
    return c;
}

