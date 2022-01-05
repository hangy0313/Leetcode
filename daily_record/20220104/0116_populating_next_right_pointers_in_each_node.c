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

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *next;
 };
 
 void connect_left_to_right(struct TreeNode* root);
 struct TreeNode* connect(struct TreeNode* root);

int main()
{
    
    return 0;
}

void connect_left_to_right(struct TreeNode* root) {
    if(!root->left) return;
    
    root->left->next = root->right;
     if(root->next) {
        root->right->next = root->next->left;
    } else {
        root->right->next = NULL;
    }
    connect_left_to_right(root->left);
    connect_left_to_right(root->right);
}

struct TreeNode* connect(struct TreeNode* root) {
    if(root)
	    connect_left_to_right(root);
    
    return root;
}


