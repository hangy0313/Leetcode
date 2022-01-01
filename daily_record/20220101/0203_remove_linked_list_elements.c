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

struct ListNode* removeElements(struct ListNode* head, int val);

int main()
{
    struct ListNode v1, v2, v3, v4, v5;
    
    v1.val = 1;
    v2.val = 3;
    v3.val = 3;
    v4.val = 5;
    v5.val = 5;
    v1.next = &v2;
    v2.next = &v3;
    v3.next = &v4;
    v4.next = &v5;
    v5.next = NULL;
    
    struct ListNode* ans = removeElements(&v1, 3);
    
    while(ans) {
        printf("%d ->", ans->val);
        ans = ans->next;
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

struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* ans;
    struct ListNode* cur;
    struct ListNode* pre = NULL;
    
    while(head) {
        if(head->val != val) break;
        head = head->next;
    }
    cur = head;
    if(!cur) return NULL;
    
    ans = cur;
    while(cur) {
        if(cur->val == val) {
            pre->next = cur->next;
        } else {
            pre = cur;
        } 
        cur = cur->next;
    }
    
    return ans;
}

