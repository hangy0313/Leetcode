/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    if(!root) return 0;
    
    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);
    
    if(left_depth > right_depth) return left_depth+1;
    else return right_depth+1;
}

int main()
{
    printf("Hello World");

    return 0;
}
