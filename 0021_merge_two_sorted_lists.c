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

bool hasCycle(struct ListNode *head);

int main()
{
    return 0;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* head;
    struct ListNode* cur;
    
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    
    if(list1->val < list2->val) {
            cur = list1;
            list1 = list1->next;
        }else {
            cur = list2;
            list2 = list2->next;
    }
    head = cur;
    
    while(list1 && list2) {
        if(list1->val < list2->val) {
            cur->next = list1;
            list1 = list1->next;
            cur = cur->next;
        }else {
            cur->next = list2;
            list2 = list2->next;
            cur = cur->next;
        }
    }
    
    if(list1)
        cur->next = list1;
    
    if(list2)
        cur->next = list2;
       
    return head;
}

