/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int prefixCount(char ** words, int wordsSize, char * pref){
    int count = 0;
    char* ptr;
    int index;
    printf("%d\n", wordsSize);
    for(int i = 0;i < wordsSize;i++) {
        ptr = pref;
        index = 0;
        while((*ptr) != '\0') {
            if((*ptr) != words[i][index] || words[i][index] == '\0') {
                count--;
                break;
            }
            index++;
            ptr++;
        }
            count++;
    }
    
    return count;
}

int main()
{
    printf("Hello World");

    return 0;
}
