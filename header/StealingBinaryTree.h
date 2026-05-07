//
// Created by Crusher on 5/7/2026.
//

#ifndef PROGRC_STEALINGBINARYTREE_H
#define PROGRC_STEALINGBINARYTREE_H

/**
* Egy csomópontot reprezentáló struktúra a bináris fán.
* @param info - a csomópont által tárolt adat (egész szám)
* @param left - pointer a bal oldali gyermekcsomópontra
* @param right - pointer a jobb oldali gyermekcsomópontra
*/
typedef struct StealingBinaryTreeNode {
    int info;
    char name[20];
    struct  StealingBinaryTreeNode *left, *right;
}  StealingBinaryTreeNode;

/**
* Memóriát foglal egy új csomóponthoz.
* @param newData - az új csomópont adata
* @return a lefoglalt csomópont pointere
*/
 StealingBinaryTreeNode *createNewNode(int newData, char newName[]);
/**
* Beszúr egy új csomópontot a gyökér bal oldalára.
* @param root - a gyökér csomópontja
* @param newData - az új csomópont adata
* @return pointer a beszúrt csomópontra
*/
 StealingBinaryTreeNode *insertLeft( StealingBinaryTreeNode *root, int newData,char newName[]);
/**
* Beszúr egy új csomópontot a gyökér jobb oldalára.

2
* @param root - a gyökér csomópontja
* @param newData - az új csomópont adata
* @return pointer a beszúrt csomópontra
*/
 StealingBinaryTreeNode *insertRight( StealingBinaryTreeNode *root, int newData,char newName[]);
/**
* Bejárás előrendben (GYÖKÉR-BAL-JOBB sorrend).
* @param root - a bináris fa gyökércsomópontja
*/
void preorderTraversal( StealingBinaryTreeNode *root);
/**
* Bejárás középrendben (BAL-GYÖKÉR-JOBB sorrend).
* @param root - a bináris fa gyökércsomópontja
*/
void inorderTraversal( StealingBinaryTreeNode *root);
/**
* Bejárás utórendben (BAL-JOBB-GYÖKÉR sorrend).
* @param root - a bináris fa gyökércsomópontja
*/
void postorderTraversal( StealingBinaryTreeNode *root);
/**
* Felszabadítja a bináris fához lefoglalt memóriát.
* @param root - pointer a bináris fa gyökércsomópontjára mutató pointerre
*/
void destroyBinaryTree( StealingBinaryTreeNode **root);


#endif //PROGRC_STEALINGBINARYTREE_H