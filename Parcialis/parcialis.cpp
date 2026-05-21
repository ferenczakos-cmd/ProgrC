#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iostream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// amit szabad hasznalni: listak: korkoros, egyszeresen es ketszeresen lancolt lista   binaris fa    hash_table     stack ?


#include "../functions/StealingBinaryTree.cpp"
#include "../functions/queue.cpp"
using namespace std;

void I() {
    ifstream f;
    f.open("szenzor.txt");
    if (f) {
        int N;
        f>>N;
        Queue queue;
        createQueue(N,&queue);
        float a;
        while (f>>a) {
            if (isFull(queue)) {
                dequeue(&queue);
            }
            enqueue(&queue,a);
        }
        display(queue);
        atlag(queue);
        kics_nagy(queue);
        novekvo(queue);
        destroyQueue(&queue);
    }else {
        cout<<"Error: file not found...";
        f.close();
        return;
    }
    f.close();
}

void II() {
    ifstream f;
    f.open("konyvtar.txt");
    if (f) {
        StealingBinaryTreeNode *root=NULL;

        int ISBN,counter;
        char Title[20],Writer[20];
        f>>ISBN>>Title>>Writer>>counter;
        root =createNewNode(ISBN,Title,Writer,counter);

        while (f>>ISBN>>Title>>Writer>>counter) {
            if (root == NULL) {
                root =createNewNode(ISBN,Title,Writer,counter);
            }else {
                bool inserted=false;
                StealingBinaryTreeNode *current=root;
                while (!inserted) {
                    if (current->ISBN==ISBN) {
                        current->counter+=counter;
                    }
                    if (current->ISBN>=ISBN) {
                        if (current->left==NULL) {
                            current->left= createNewNode(ISBN,Title,Writer,counter);
                            inserted=true;
                        }else {
                            current=current->left;
                        }
                    }
                    if (current->ISBN<=ISBN) {
                        if (current->right==NULL) {
                            current->right= createNewNode(ISBN,Title,Writer,counter);
                            inserted=true;
                        }else {
                            current=current->right;
                        }
                    }
                }
            }
        }

        inorderTraversal(root);

        search(root,4);
        kolcsonoz(root,4);
        kolcsonoz(root,4);
        viszahoz(root,4);
        kolcsonoz(root,4);
        kolcsonoz(root,4);


        destroyBinaryTree(&root);
    }else {
        cout<<"Error: file not found...";
        f.close();
        return;
    }
    f.close();
}

int main() {
    //I();
    II();
    return 0;
}