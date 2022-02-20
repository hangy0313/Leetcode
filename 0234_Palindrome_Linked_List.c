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

// bool isPalindrome(struct ListNode* head){
//     int* arr;
//     int num = 0;
//     int left = 0;
//     int right = 0;
    
//     arr = malloc(sizeof(int)*100000);
    
//     while(head) {
//         arr[num++] = head->val;
//         head = head->next;
//     }
//     right = num-1;
    
//     while(left < right) {
//         if(arr[left++] == arr[right--])
//             continue;
//         else return false;
//     }
    
//     return true;
// }
// 0->0->0->NULL
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* reverse = NULL;
    struct ListNode* cur = head;
    struct ListNode* next;
    
    while(cur) {
        next = cur->next;
        cur->next = reverse;
        reverse = cur;
        cur = next;
    } 
    
    return reverse;

}

bool isPalindrome(struct ListNode* head){

    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    
    slow->next=reverse(slow->next);
    slow=slow->next;
    
    while(slow) {
        if(head->val == slow->val) {
            head = head->next;
            slow = slow->next;
        } else {
            return false;
        }
    }
    
    return true;
}

int main()
{
    printf("Hello World");

    return 0;
}
