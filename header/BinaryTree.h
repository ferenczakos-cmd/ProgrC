#ifndef PROGRC_BINARYTREE_H
#define PROGRC_BINARYTREE_H

/**
* Egy csomópontot reprezentáló struktúra a bináris fán.
* @param info - a csomópont által tárolt adat (egész szám)
* @param left - pointer a bal oldali gyermekcsomópontra
* @param right - pointer a jobb oldali gyermekcsomópontra
*/
typedef struct BinaryTreeNode {
    int info;
    struct BinaryTreeNode *left, *right;
} BinaryTreeNode;

/**
* Memóriát foglal egy új csomóponthoz.
* @param newData - az új csomópont adata
* @return a lefoglalt csomópont pointere
*/
BinaryTreeNode *createNewNode(int newData);
/**
* Beszúr egy új csomópontot a gyökér bal oldalára.
* @param root - a gyökér csomópontja
* @param newData - az új csomópont adata
* @return pointer a beszúrt csomópontra
*/
BinaryTreeNode *insertLeft(BinaryTreeNode *root, int newData);
/**
* Beszúr egy új csomópontot a gyökér jobb oldalára.

2
* @param root - a gyökér csomópontja
* @param newData - az új csomópont adata
* @return pointer a beszúrt csomópontra
*/
BinaryTreeNode *insertRight(BinaryTreeNode *root, int newData);
/**
* Bejárás előrendben (GYÖKÉR-BAL-JOBB sorrend).
* @param root - a bináris fa gyökércsomópontja
*/
void preorderTraversal(BinaryTreeNode *root);
/**
* Bejárás középrendben (BAL-GYÖKÉR-JOBB sorrend).
* @param root - a bináris fa gyökércsomópontja
*/
void inorderTraversal(BinaryTreeNode *root);
/**
* Bejárás utórendben (BAL-JOBB-GYÖKÉR sorrend).
* @param root - a bináris fa gyökércsomópontja
*/
void postorderTraversal(BinaryTreeNode *root);
/**
* Felszabadítja a bináris fához lefoglalt memóriát.
* @param root - pointer a bináris fa gyökércsomópontjára mutató pointerre
*/
void destroyBinaryTree(BinaryTreeNode **root);

#endif //PROGRC_BINARYTREE_H