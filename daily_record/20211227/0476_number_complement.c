/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int findComplement(int num);

int main()
{
    int test = 5;
    
    int result = findComplement(test);
    printf("result =  %d", result);

    return 0;
}

int findComplement(int num){
    int tmp = num;
    long res = 1;
    
    while(tmp > 0) {
        tmp >>= 1;
        res <<= 1;
    }
    
    return num^(res-1);
}