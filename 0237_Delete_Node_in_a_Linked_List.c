/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode* ptr = node;
    struct ListNode* tmp;
    
    while(ptr->next) {
        tmp = ptr;
        ptr->val = ptr->next->val;
        ptr = ptr->next;
    }
    
    tmp->next = NULL;
    
    return;
}

int main()
{
    printf("Hello World");

    return 0;
}
