/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize);

int main()
{
    int price[6] = {7,1,5,3,6,4};

    
    int ans = maxProfit(price, 6);
    printf("ans = %d\n", ans);

    return 0;
}

int maxProfit(int* prices, int pricesSize){
    if(pricesSize <= 0)
        return 0;
    int index;
    int price = *prices;
    int earn = 0;
    
    for(index = 1;index < pricesSize;index++)
    {
        if(prices[index] < price)
            price = prices[index];
        
        earn = prices[index]-price > earn ? prices[index]-price:earn;
    }
    
    return earn;
}