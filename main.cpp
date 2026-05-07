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
#include <fstream>
#include <filesystem>

using namespace std;

int main() {
    ifstream f("BinaryTree.txt");
    int a;
    if (!(f >> a)) return 0;

    StealingBinaryTreeNode* root = createNewNode(6,"alma");
    insertLeft(root,7,"korte");
    /*
    while (f >> a) {
        StealingBinaryTreeNode* curr = root;
        bool inserted = false;

        while (!inserted) {
            if (a < curr->info) {
                if (curr->left != nullptr) {
                    curr = curr->left;
                } else {
                    curr->left = createNewNode(a,"alma");
                    inserted = true;
                }
            } else if (a > curr->info) {
                if (curr->right != nullptr) {
                    curr = curr->right;
                } else {
                    curr->right = createNewNode(a,"alma");
                    inserted = true;
                }
            } else {
                inserted = true;
            }
        }
    }
    */
    cout<<"PreOrder: ";
    preorderTraversal(root);
    cout<<endl<<"InOrder: ";
    inorderTraversal(root);
    cout<<endl<<"PostOrder: ";
    postorderTraversal(root);

    destroyBinaryTree(&root);
    return 0;
}