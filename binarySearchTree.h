#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node Node;

Node* createNode(int value);
void inorder(Node *root);
Node* insert(Node* root, int data);
int search(Node* root, int data);
Node * minValueNode(Node* node);
Node* deleteNode(Node* root, int data);