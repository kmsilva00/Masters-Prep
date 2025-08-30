#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node Node; //AI input, forward declaration, so I can use Node pointers in Node def

struct Node {
    int data;
    Node* address;
};

typedef struct {
    Node* addressFirstNode;
} LinkedList;

void printNode (Node* node){
    if (node->address != NULL){
            printf("nodedata:  {%d}  ,  nodeTail:  {%p}  ,  dataAtNextNode: {%d} \n", node->data, node->address, node -> address -> data);        
    } else {
            printf("SAFEPRINT: nodedata:  {%d}  ,  nodeTail:  {NULL}  \n", node -> data);

    }
    }


void printTraverseLinkedList(LinkedList* LL){

    if (LL == NULL || LL->addressFirstNode == NULL){ // AI input, lazy to do edge cases
        printf("Linked List is empty.\n"); 
        return;
    }

    Node* current_node_p = LL->addressFirstNode;
    while (current_node_p != NULL){
        printNode(current_node_p);
        current_node_p = current_node_p->address;
    }
}
Node* createNodeTail(LinkedList* LL, int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    
    // AI input,  Handle error, e.g., print error and exit or return NULL
    if (new_node == NULL) { // 
        fprintf(stderr, "Memory allocation failed for new node!\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = data;
    new_node->address = NULL;

    if (LL->addressFirstNode == NULL) { // AI input, lazy to do edge cases
        LL->addressFirstNode = new_node;
        return new_node;
    }

    Node* current_Node_P = LL->addressFirstNode;
    while (current_Node_P->address != NULL) {
        current_Node_P = current_Node_P->address;
    }

    current_Node_P->address = new_node;
    return new_node;
}

void freeLinkedList(LinkedList* LL){

    if (LL == NULL || LL->addressFirstNode == NULL) {  // AI input, lazy to do edge cases
        free(LL); 
        return;
    }

    Node* current_node = LL->addressFirstNode;
    Node* next_node_add;
    while(current_node != NULL) { 
        next_node_add = current_node->address;
        free(current_node); 
        current_node = next_node_add; 
    }
    free(LL); // AI Input, oops forgot
}

Node* createNodeHead(LinkedList* LL,int node_data){

    Node* previousFirstNode = LL -> addressFirstNode;

    Node* newNode = (Node*)malloc(sizeof(Node));
    // AI input,  Handle error , fprintf and exit(), look into
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed for new node!\n");
        exit(EXIT_FAILURE);
    }

    newNode -> data = node_data;
    newNode -> address = previousFirstNode;

    LL -> addressFirstNode = newNode;
    
    return newNode;
    
};

// my main() function :^ )
// int main()
// {

//     Node* oneNode = (Node*)malloc(sizeof(Node));
//     oneNode -> data = 1;
//     oneNode -> address = NULL;

//     LinkedList* myLL = (LinkedList*)malloc(sizeof(LinkedList));
//     myLL -> addressFirstNode = oneNode;

//     Node* node_test_1 = createNodeHead(myLL,21);
//     Node* node_test_2 = createNodeHead(myLL,5);

//     Node* node_test_3 = createNodeTail(myLL, 33);
//     Node* node_test_4 = createNodeTail(myLL, 45);



//     // createNodeHead(&myLL,4);

//     // printf("myLL adress is {%p} , data at first node {%d} \n", myLL.addressFirstNode, myLL.addressFirstNode -> data);
//     // printNode(oneNode);

//     printTraverseLinkedList(myLL);
//     // printNode(*node_test_l_3);
//     // printf("%d \n", node_test_2->data);
//     // printf("%d \n", node_test_2->address->data);
//     // printf("%d \n", node_test_2->address->address->data);
//     // printf("%d \n", node_test_2->address->address->address->data);
    

//     // printf("%d \n", node_test_3->address->data);



//     return 0;
//     freeLinkedList(myLL);
// }





//-----------------------------------------------
//-----------------------------------------------
//-----------------------------------------------
//-----------------------------------------------
//-----------------------------------------------





// AI input - whole main() fn and all the test cases 
int main()
{
    // Initialize an empty linked list
    LinkedList* myLL = (LinkedList*)malloc(sizeof(LinkedList));
    if (myLL == NULL) {
        fprintf(stderr, "Memory allocation failed for LinkedList!\n");
        return 1;
    }
    myLL->addressFirstNode = NULL; // Crucial: start with an empty list

    printf("--- Initial empty list ---\n");
    printTraverseLinkedList(myLL);

    // Add nodes to the head
    Node* node_test_1 = createNodeHead(myLL, 21);
    printf("--- After adding 21 to head ---\n");
    printTraverseLinkedList(myLL);

    Node* node_test_2 = createNodeHead(myLL, 5);
    printf("--- After adding 5 to head ---\n");
    printTraverseLinkedList(myLL); // Should print 5, 21

    // Add nodes to the tail
    Node* node_test_3 = createNodeTail(myLL, 33);
    printf("--- After adding 33 to tail ---\n");
    printTraverseLinkedList(myLL); // Should print 5, 21, 33

    Node* node_test_4 = createNodeTail(myLL, 45);
    printf("--- After adding 45 to tail ---\n");
    printTraverseLinkedList(myLL); // Should print 5, 21, 33, 45

    // Test with a completely new (empty) list
    LinkedList* myTestLL = (LinkedList*)malloc(sizeof(LinkedList));
    if (myTestLL == NULL) {
        fprintf(stderr, "Memory allocation failed for myTestLL!\n");
        // Don't forget to free myLL before exiting
        freeLinkedList(myLL);
        return 1;
    }
    myTestLL->addressFirstNode = NULL;

    printf("\n--- Test with a new empty list (myTestLL) ---\n");
    printTraverseLinkedList(myTestLL);

    createNodeTail(myTestLL, 100);
    printf("--- myTestLL after adding 100 to tail ---\n");
    printTraverseLinkedList(myTestLL);

    createNodeHead(myTestLL, 99);
    printf("--- myTestLL after adding 99 to head ---\n");
    printTraverseLinkedList(myTestLL); // Should print 99, 100

    // Free all allocated memory
    printf("\n--- Freeing myLL ---\n");
    freeLinkedList(myLL);
    printf("--- Freeing myTestLL ---\n");
    freeLinkedList(myTestLL);

    return 0;
}