/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

 struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode* middleNode(struct ListNode* head);

int main()
{
    struct ListNode* result;
    struct ListNode head;
    struct ListNode second;
    struct ListNode third;
    struct ListNode forth;
    
    head.val = 1;
    head.next = &second;
    second.val = 2;
    second.next = &third;
    third.val = 3;
    third.next = &forth;
    forth.val = 4;
    forth.next = NULL;

    result = middleNode(&head);
    
    do {
        printf("%d ", result->val);
        result = result->next;
    }while(result != NULL);
    
    return 0;
}

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode** table;
    int index = 0;;
    struct ListNode* cur = head;
    
    table = malloc(sizeof(struct ListNode*)*100);
    
    do {
        table[index] = cur;
        cur = cur->next;
        index++;
    } while(cur != NULL);
    
    return table[index/2];
}
