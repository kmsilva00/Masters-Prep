#include <stdio.h>

typedef struct Node Node;

struct Node
{
    int data;
    Node* nodeL;
    Node* nodeR;
};

Node* createLeafNode(int i_data){
    Node* nodeLeaf = (Node*)malloc(sizeof(Node));
    nodeLeaf -> data = i_data;
    nodeLeaf -> nodeL = NULL; 
    nodeLeaf -> nodeR = NULL;
    return nodeLeaf; 
}

void addLeft(Node* parent,int i_data){
    
    Node* new_nodeL = (Node*)malloc(sizeof(Node));
    parent -> nodeL = new_nodeL;
}

void freeTree(Node* parent) { //ai input recursion
    if (parent == NULL) {
        return;
    }

    // 1. Recursively free the left subtree
    freeTree(parent->nodeL); 

    // 2. Recursively free the right subtree
    freeTree(parent->nodeR);

    // 3. Free the current node itself
    free(parent); 
}

int main()
{
    Node* myRoot = createLeafNode(5);
    addLeft(myRoot, 10);

    free(myRoot);
    free(myRoot);

}

