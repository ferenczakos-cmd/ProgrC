#include <complex.h>
#include <iostream>
#include <ctime>
#include "header/constants.h"
#include "functions/BinaryTree.cpp"
#include "functions/StealingBinaryTree.cpp"
#include "functions/array.cpp"
#include "functions/queue.cpp"
#include "functions/stack.cpp"
#include "functions/CardStack.cpp"
#include "functions/stringQueue.cpp"
#include "functions/List.cpp"
#include "functions/CircularList.cpp"
#include "functions/hash_table.cpp"
#include <fstream>
#include <filesystem>

using namespace std;

// Az éleket reprezentáló struktúra


int main() {
    // Create root
    StealingBinaryTreeNode *root = createNewNode(100, "Boss");

    // Left side
    StealingBinaryTreeNode *left1 = insertLeft(root, 30, "Tom");
    insertLeft(left1, 20, "Jerry");
    insertRight(left1, 50, "Mike");

    // Right side
    StealingBinaryTreeNode *right1 = insertRight(root, 60, "Anna");
    insertLeft(right1, 40, "Kate");
    insertRight(right1, 70, "John");

    // Traversals
    printf("Preorder Traversal:\n");
    preorderTraversal(root);
    printf("\n\n");

    printf("Inorder Traversal:\n");
    inorderTraversal(root);
    printf("\n\n");

    printf("Postorder Traversal:\n");
    postorderTraversal(root);
    printf("\n\n");

    // Custom functions
    printf("Okos path:\n");
    Okos(root, 0);
    printf("\n\n");

    printf("Buta path:\n");
    Buta(root, 0);
    printf("\n\n");

    // Free memory
    destroyBinaryTree(&root);

    if(root == NULL) {
        printf("Tree successfully destroyed.\n");
    }

    return 0;
}
