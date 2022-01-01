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
 
struct ListNode* removeNthFromEnd(struct ListNode* head, int n);

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
    
    //rmove n'th node from the end of the list and return its head.
    result = removeNthFromEnd(&head, 2);
    
    do {
        printf("%d ", result->val);
        result = result->next;
    }while(result != NULL);
    
    return 0;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode** table;
    struct ListNode* tmp = head;
    int index = 0;
    
    table = malloc(sizeof(struct ListNode*)*30);
    
    do{
        table[index++] = tmp;
        tmp = tmp->next;
    }while(tmp != NULL);
    
    if(n == index) {
        if(index == 1) return NULL;
        else return table[1];
    }
    if(n == 1) {
        table[index-n-1]->next = NULL;
    } else {
        table[index-n-1]->next = table[index-n+1];
    }
    
    return table[0];
}
