/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int hammingWeight(uint32_t n) {
    int count = 0;
    
    while(n) {
        count += (n & 1);
        n >>= 1;
    }
    
    return count;
}

int main()
{
    printf("Hello World");

    return 0;
}
