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

/*   test tree 
 *      4
 *     / \
 *    2   6
 *   / \ / \
 *  1  3 5  7
 *   Pre-order  : 4 2 1 3 6 5 7
 *   In-order   : 1 2 3 4 5 6 7
  *  Post-order : 1 3 2 5 7 6 4
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };
 
int count_node(struct TreeNode* root);
void preorder(struct TreeNode* root, int* arr, int* index);
int* preorderTraversal(struct TreeNode* root, int* returnSize);
void inorder(struct TreeNode* root, int* arr, int* index);
int* inorderTraversal(struct TreeNode* root, int* returnSize);
void postorder(struct TreeNode* root, int* arr, int* index);
int* postorderTraversal(struct TreeNode* root, int* returnSize);

int main()
{
    struct TreeNode tree[7];
    int* result_arr;
    int result_size;
    int index;
    
    tree[0].val = 4;
    tree[0].left = tree+1;
    tree[0].right = tree+2;
    
    tree[1].val = 2;
    tree[1].left = tree+3;
    tree[1].right = tree+4;
    
    tree[2].val = 6;
    tree[2].left = tree+5;
    tree[2].right = tree+6;
    
    tree[3].val = 1;
    tree[3].left = NULL;
    tree[3].right = NULL;
    
    tree[4].val = 3;
    tree[4].left = NULL;
    tree[4].right = NULL;
    
    tree[5].val = 5;
    tree[5].left = NULL;
    tree[5].right = NULL;
    
    tree[6].val = 7;
    tree[6].left = NULL;
    tree[6].right = NULL;
    
    result_arr = preorderTraversal(tree, &result_size);
    printf("Preorder result : \n");
    for(index = 0;index < result_size;index++) 
        printf(" %d", result_arr[index]);
    printf("\n");
    
    result_arr = inorderTraversal(tree, &result_size);
    printf("Inorder result : \n");
    for(index = 0;index < result_size;index++) 
        printf(" %d", result_arr[index]);
    printf("\n");
    
    result_arr = postorderTraversal(tree, &result_size);
    printf("Postorder result : \n");
    for(index = 0;index < result_size;index++) 
        printf(" %d", result_arr[index]);
    printf("\n");
    
    return 0;
}

int count_node(struct TreeNode* root) {
    if(root == NULL) return 0;
    
    return count_node(root->left)+count_node(root->right)+1;
}

void preorder(struct TreeNode* root, int* arr, int* index) {
    if(root == NULL) return;
    
    *(arr+(*index)) = root->val;
    (*index)++;
    preorder(root->left, arr, index);
    preorder(root->right, arr, index);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int* arr;
    int index = 0;

    
    *returnSize = count_node(root);
    arr = malloc(sizeof(int)*(*returnSize));
    preorder(root, arr, &index);
    
    return arr;
}

void inorder(struct TreeNode* root, int* arr, int* index) {
    if(!root) return;
    
    inorder(root->left, arr, index);
    arr[(*index)++] = root->val;
    inorder(root->right, arr, index);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int* arr;
    int index = 0;
    
    *returnSize = count_node(root);
    arr = malloc(sizeof(int)*(*returnSize));
    
    inorder(root, arr, &index);
    
    return arr;
}

void postorder(struct TreeNode* root, int* arr, int* index) {
    if(!root) return;
    
    postorder(root->left, arr, index);
    postorder(root->right, arr, index);
    arr[(*index)++] = root->val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int* arr;
    int index = 0;
    
    *returnSize = count_node(root);
    arr = malloc(sizeof(int)*(*returnSize));
    
    postorder(root, arr, &index);
    
    return arr;
}


