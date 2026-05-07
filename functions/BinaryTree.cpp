#include "../header/BinaryTree.h"
#include <stdlib.h>
#include <stdio.h>
#include "../header/constants.h"

BinaryTreeNode *createNewNode(int newData) {
    BinaryTreeNode *newItem = (BinaryTreeNode*) malloc(sizeof (BinaryTreeNode));
    if(!newItem)
    {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    newItem->info = newData;
    newItem->left = newItem->right = NULL ;
    return newItem;
}
BinaryTreeNode *insertLeft(BinaryTreeNode *root, int newData) {
    root->left = createNewNode(newData);
    return root->left;
}
BinaryTreeNode *insertRight(BinaryTreeNode *root, int newData) {
    root->right= createNewNode(newData);
    return root->right;
    }
void preorderTraversal(BinaryTreeNode *root) {
    if(root == NULL) return;
    printf("%d ", root->info);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void inorderTraversal(BinaryTreeNode *root) {
    if(root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->info);
    inorderTraversal(root->right);
}
void postorderTraversal(BinaryTreeNode *root) {
    if(root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->info);
}
void destroyBinaryTree(BinaryTreeNode **root) {
    if((*root)->right == NULL && (*root)->left == NULL)
    {
        free(*root);
        *root = NULL;
        return;
    }
    destroyBinaryTree(&(*root)->left);
    destroyBinaryTree(&(*root)->right);
    free(*root);
    *root = NULL;
}