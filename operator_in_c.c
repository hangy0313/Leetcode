/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// Operators of C language

#include <stdio.h>

int main()
{
    int x = 2, y = 1, z = 0;
    x = x && y || z;
    printf("%d => x && y || z\n", x);
    printf("%d => x || !y\n", x || !y);
    printf("%d => (x || !y) && z\n", (x || !y) && z);
    printf("%d => x || !y && z\n\n", x || !y && z);
    
    x = y = 1;
    printf("x = %d, y = %d, z = %d\n", x, y, z);
    
    z = x++-1;
    printf("z = x++-1\n");
    printf("x = %d, y = %d, z = %d\n", x, y, z);
    
    z += -x++ + ++y;
    printf("z += -x++ + ++y\n");
    printf("x = %d, y = %d, z = %d\n", x, y, z);
    
    z = x / ++x;
    printf("z = x / ++x\n");
    printf("x = %d, y = %d, z = %d\n\n", x, y, z);
    
    x = 03, y = 02, z = 01;
    printf("Initial : x = 03, y = 02, z = 01\n");
    printf("%d => x | y & z\n", x | y & z);
    printf("%d => x | y & ~z\n", x | y & ~z);
    printf("%d => x ^ y & ~z\n", x ^ y & ~z);
    printf("%d => x & y && z\n\n", x ^ y & ~z);
    
    x = 1, y = -1;
    printf("Initial : x = 1, y = -1\n");
    printf("%x => !x\n", !x); //not 0->1 1->0
    printf("%x => ~x\n", ~x); //補數 x = 001(十進位：1), ~x = 110(十進位：-2)
    printf("%d => !x | x\n", !x | x);
    printf("%d => ~x | x\n", ~x | x);
    printf("%d => x ^ x\n", x ^ x);
    printf("%d => x<<=3\n", x<<=3);
    printf("%d => y<<=3\n", y<<=3);
    printf("%d => y>>=3\n\n", y>>=3);
    
    x = 1, y =1, z = 1;
    printf("Initial : x = 1, y =1, z = 1\n");
    x+=y+=z;
    printf("Operation : x+=y+=z\n");
    printf("x = %d, y = %d, z = %d\n", x, y, z);
    printf("%d => x<y ? y:x\n", x<y?y:x);
    printf("%d => x<y ? x++:y++\n", x<y ? x++:y++);
    printf("x = %d, y = %d, z = %d\n", x, y, z);
    printf("%d => z+=x<y?x++:y++\n", z+=x<y?x++:y++);
    printf("x = %d, y = %d, z = %d\n", x, y, z);
    printf("%d => z>=y>=x?1:0\n", z>=y>=x?1:0);
    printf("%d => z>=y && y>= x\n\n", z>=y && y>= x);
    
    x = 1, y =1, z = 1;
    printf("Initial : x = 1, y =1, z = 1\n");
    ++x || ++y && ++z;
    printf("Operation : ++x || ++y && ++z\n");
    printf("x = %d, y = %d, z = %d\n", x, y, z);
    
    ++x && ++y || ++z;
    printf("Operation : ++x || ++y && ++z\n");
    printf("x = %d, y = %d, z = %d\n", x, y, z);
    
    x = 1, y =1, z = 1;
    printf("Initial : x = 1, y =1, z = 1\n");
    ++x && ++y && ++z;
    printf("Operation : ++x || ++y && ++z\n");
    printf("x = %d, y = %d, z = %d\n", x, y, z);
    
    x = -1, y = -1, z = -1;
    printf("Initial : x = -1, y = -1, z = -1\n");
    ++x && ++y || ++z;
    printf("Operation : ++x && ++y || ++z\n");
    printf("x = %d, y = %d, z = %d\n", x, y, z);
    
    x = -1, y = -1, z = -1;
    printf("Initial : x = -1, y = -1, z = -1\n");
    ++x || ++y && ++z;
    printf("Operation : ++x || ++y && ++z\n");
    printf("x = %d, y = %d, z = %d\n", x, y, z);
    
    x = -1, y = -1, z = -1;
    printf("Initial : x = -1, y = -1, z = -1\n");
    ++x && ++y && ++z;
    printf("Operation : ++x || ++y && ++z\n");
    printf("x = %d, y = %d, z = %d\n", x, y, z);

    return 0;
}
