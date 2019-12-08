#include "app.h"
#include <time.h>


int main(){
    srand(time(NULL));
    Node *newNode = createNode(55);
    Node *root = newNode;

    Stack *newStack = createStack(100);
    Stack *stack = newStack;

    printf(" %s", "Initial tree \n");
    insert(root,50);
    insert(root,40);
    insert(root,60);
    insert(root,15);
    insert(root,10);
    inorder(root);
    printf(" %s", "\n");

    randomTask(root,stack,10);

    int number;
    printf("\n\nhow many steps back:");
    scanf("%d", &number);
    throwBack(root,stack,number);



}