#include "../header/StealingBinaryTree.h"
#include <stdlib.h>
#include <stdio.h>
#include "../header/constants.h"

StealingBinaryTreeNode *createNewNode(int newData,char newName[20]) {
    StealingBinaryTreeNode *newItem = (StealingBinaryTreeNode*) malloc(sizeof (StealingBinaryTreeNode));
    if(!newItem)
    {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    newItem->info = newData;
    int i=0;
    while (newName[i]!='\0') {
        newItem->name[i] = newName[i];
        i++;
    }
    newItem->name[i] = newName[i]; // to add the backslash too

    newItem->left = newItem->right = NULL ;
    return newItem;
}
StealingBinaryTreeNode *insertLeft(StealingBinaryTreeNode *root, int newData, char newName[20]) {
    root->left = createNewNode(newData,newName);
    return root->left;
}
StealingBinaryTreeNode *insertRight(StealingBinaryTreeNode *root, int newData,char newName[20]) {
    root->right= createNewNode(newData,newName);
    return root->right;
    }
void preorderTraversal(StealingBinaryTreeNode *root) {
    if(root == NULL) return;
    printf("%d ", root->info);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void inorderTraversal(StealingBinaryTreeNode *root) {
    if(root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->info);
    inorderTraversal(root->right);
}
void postorderTraversal(StealingBinaryTreeNode *root) {
    if(root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->info);
}
void destroyBinaryTree(StealingBinaryTreeNode **root) {
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