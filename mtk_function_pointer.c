/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>


void func1(void){printf("func1\n");};
void func2(void){printf("func2\n");};
void func3(void){printf("func3\n");};
void func4(void){printf("func4\n");};
void func5(void){printf("func5\n");};

// if n==1 execute func1;
// if n==2 execute func2;
// if n==3 execute func3;
// if n==4 execute func4;
// if n==5 execute func5;
// 保證 n 一定是上面五個數字之一 不能用if 和 switch case , 請用你認為最快的方法實作main
void test1(int n) {
    void (*fp[5])() = {func1, func2, func3, func4, func5};
    fp[n-1]();
}

// if n==33 execute func1;
// if n==67 execute func2;
// if n==324 execute func3;
// if n==231 execute func4;
// if n==687 execute func5;
// 保證 n 一定是上面五個數字之一
// 使用if, 請用你認為最快的方法實作main
void test2(int n) {
    void (*fp[16])() = {
        [1] = func1,
        [3] = func2,
        [4] = func3,
        [7] = func4,
        [15] = func5};
    fp[n%16]();
}


int main()
{
    test1(1);
    test2(33);
    test2(67);
    test2(324);
    test2(231);
    test2(687);

    return 0;
}
