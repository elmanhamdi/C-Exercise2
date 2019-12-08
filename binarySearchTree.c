#include"binarySearchTree.h"

//Create and return a node with the given value
Node* createNode(int value){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
}


//Print the tree with inorder processor
void inorder(Node *root){
    if (root == NULL)
        return;

    inorder(root->left);  // Recursive on left side childs

    // Prints data
    printf("%d ", root->data);
    printf("%s ", "->");

    inorder(root->right);  //Recursive on right side childs
}

//Take tree and a data and insert it in data
Node* insert(Node* root, int data){
    Node *newNode = createNode(data);  // new data's node
    Node *current = root;

    while(1){
        if(current->data == data)  //if the data and current node's data is equal then not to need to insert it
            return NULL;
        else if(current->data < data){  //if the data bigger than current node's than continue with right side of tree
            if(current->right != NULL)   current = current->right;
            else {
                current->right = newNode;
                break;
            }
        }
        else if  (current->data > data){
            if(current->left != NULL)   current = current->left;
            else {
                current->left = newNode;
                break;
            }
        }
    }
    return newNode;

}


//Find a data on tree and return how much spent to search it
int search(Node* root, int data){
    Node *current = root;
    int count= 1;  // to know step

    while(current->data != data){
        if(current == NULL){  // if current equal NULL then data not in tree
            return -1;
        }
        else if(current->data < data){  //if the data bigger than current node's than continue with right side of tree
            if(current->right != NULL)   current = current->right;
            else return -1;
        }
        else{
            if(current->left != NULL)   current = current->left;
            else return -1;
        }
        count += 1;
    }
    return count;
}


//Find a data on tree and return how much spent to search it
Node * minValueNode(Node* node){
    Node *current = node;
    while(current->left != NULL){
        current = current->left;
    }
    return current;
}






//Delete a node on binary tree
//When I am coding delete method I searched some thing on internet so this part can like some code on internet but not same
Node* deleteNode(Node* root, int data)
{
    if (root == NULL) return root;  // if root is NULL than is mean data not found on the tree


    if (data < root->data) // if data smaller than root than searching on left side of tree
        root->left = deleteNode(root->left, data);


    else if (data > root->data) // if data smaller than root than searching on left side of tree
        root->right = deleteNode(root->right, data);


    else // data founded on tree and this part will be delete it on tree
    {
        // if root have one child or dont have childs
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);  // for make free address
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root); // for make free address
            return temp;
        }

        // Node has two children then delete node with using inorder successor
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
