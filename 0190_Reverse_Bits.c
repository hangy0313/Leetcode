/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

// n = 110
//     1.
//     ans = 0
//     ans = 0
//     n = 11
    
//     2. 
//     ans = 00
//     ans = 01
//     n = 1
    
//     3. 
//     ans = 010
//     ans = 011
//     n = 0
uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;
    for(int index = 0;index < 32;index++) {
        ans <<= 1;
        ans |= (n&1);
        n >>= 1;
    }
    
    return ans;
}

int main()
{
    printf("Hello World");

    return 0;
}
