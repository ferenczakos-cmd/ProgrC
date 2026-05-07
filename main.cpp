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
    int value;
    char newName[20];
    f>>newName>>value;
    StealingBinaryTreeNode* root = createNewNode(value,newName);
    for (int i=1;i<a;i++) {
        f>>newName>>value;
        StealingBinaryTreeNode* curr = root;
        bool inserted = false;

        while (!inserted) {
            if (value < curr->info) {
                if (curr->left != nullptr) {
                    curr = curr->left;
                } else {
                    curr->left = createNewNode(value,newName);
                    inserted = true;
                }
            } else if (value > curr->info) {
                if (curr->right != nullptr) {
                    curr = curr->right;
                } else {
                    curr->right = createNewNode(value,newName);
                    inserted = true;
                }
            } else {
                inserted = true;
            }
        }
    }

    cout<<"PreOrder: ";
    preorderTraversal(root);
    cout<<endl<<"InOrder: ";
    inorderTraversal(root);
    cout<<endl<<"PostOrder: ";
    postorderTraversal(root);

    destroyBinaryTree(&root);
    return 0;
}