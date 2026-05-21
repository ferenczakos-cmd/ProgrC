#include "../header/StealingBinaryTree.h"
#include <stdlib.h>
#include <stdio.h>
#include "../header/constants.h"

#include <iostream>
#include <fstream>

using namespace std;

StealingBinaryTreeNode *createNewNode(int ISBN,char Title[20], char Writer[20], int counter) {
    StealingBinaryTreeNode *newItem = (StealingBinaryTreeNode*) malloc(sizeof (StealingBinaryTreeNode));
    if(!newItem)
    {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }

    newItem->ISBN = ISBN;

    int i=0;
    while (Title[i]!='\0') {
        newItem->Title[i] = Title[i];
        i++;
    }
    newItem->Title[i] = Title[i]; // to add the backslash too

    i=0;
    while (Writer[i]!='\0') {
        newItem->Writer[i] = Writer[i];
        i++;
    }
    newItem->Writer[i] = Writer[i]; // to add the backslash too

    newItem->counter = counter;

    newItem->left = newItem->right = NULL ;
    return newItem;
}
StealingBinaryTreeNode *insertLeft(StealingBinaryTreeNode *root, int ISBN, char Title[20], char Writer[], int counter) {
    root->left = createNewNode(ISBN,Title,Writer, counter);
    return root->left;
}
StealingBinaryTreeNode *insertRight(StealingBinaryTreeNode *root, int ISBN,char Title[20], char Writer[], int counter) {
    root->right= createNewNode(ISBN,Title,Writer, counter);
    return root->right;
    }
// void preorderTraversal(StealingBinaryTreeNode *root) {
//     if(root == NULL) return;
//     printf("%d ", root->info);
//     int i=0;
//     while (root->name[i]!='\0') {printf("%c", root->name[i]); i++;}
//     printf(" ");
//     preorderTraversal(root->left);
//     preorderTraversal(root->right);
// }
void inorderTraversal(StealingBinaryTreeNode *root) {
    if(root == NULL) return;
    inorderTraversal(root->left);
    cout<<"ID: "<<root->ISBN<<" Title: "<<root->Writer<<" Writer: "<<root->Title<<" counter: "<<root->counter<<endl;
    inorderTraversal(root->right);
}
// void postorderTraversal(StealingBinaryTreeNode *root) {
//     if(root == NULL) return;
//     postorderTraversal(root->left);
//     postorderTraversal(root->right);
//     printf("%d ", root->info);
// }

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

void search(StealingBinaryTreeNode *root, int ISBN) {
    if(root == NULL) return;
    if (root->ISBN == ISBN) {
        cout<<endl<<"A keresett konyv: "<<root->Writer<<" by "<<root->Title<<endl;
        cout<<"Rendelkezesre allo konyvek szama: "<<root->counter<<endl;
    }
    search(root->left,ISBN);
    search(root->right,ISBN);

}

void kolcsonoz(StealingBinaryTreeNode *root, int ISBN) {
    if(root == NULL) return;
    if (root->ISBN == ISBN) {
        if (root->counter==0) {
             cout<<endl<<"A konyvbol nincs jelenleg egy sem a konyvtarban"<<endl;
        }else {
            cout<<endl<<"A konyv kiadva!"<<endl;
            cout<<"A keresett konyv: "<<root->Writer<<" by "<<root->Title<<endl;
            cout<<"Rendelkezesre allo konyvek szama: "<<root->counter<<endl;
            root->counter--;
        }

    }
    kolcsonoz(root->left,ISBN);
    kolcsonoz(root->right,ISBN);

}

void viszahoz(StealingBinaryTreeNode *root, int ISBN) {
    if(root == NULL) return;
    if (root->ISBN == ISBN) {
        root->counter++;
        cout<<endl<<"A konyvet visszahoztak!"<<endl;
        cout<<"A keresett konyv: "<<root->Writer<<" by "<<root->Title<<endl;
        cout<<"Rendelkezesre allo konyvek szama: "<<root->counter<<endl;
    }
    viszahoz(root->left,ISBN);
    viszahoz(root->right,ISBN);

}