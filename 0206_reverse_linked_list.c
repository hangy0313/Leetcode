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

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head);

int main()
{
    struct ListNode v1, v2, v3, v4, v5;
    
    v1.val = 1;
    v2.val = 2;
    v3.val = 3;
    v4.val = 4;
    v5.val = 5;
    v1.next = &v2;
    v2.next = &v3;
    v3.next = &v4;
    v4.next = &v5;
    v5.next = NULL;
    
    struct ListNode* reverse = reverseList(&v1);
    
    while(reverse) {
        printf("%d ->", reverse->val);
        reverse = reverse->next;
    }
    
    
    return 0;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* reverse = NULL;
    struct ListNode* cur = head;
    
    while(cur) {
        struct ListNode* next = cur->next;
        cur->next = reverse;
        reverse = cur;
        cur = next;
    }
    return reverse;
}

