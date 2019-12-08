#include "app.h"





int taskInsertHelper(Node* root,int data, Stack* stack){  // Delete data from tree and add task to stack
    printf(" %s", "\n task->");
    printf(" %s", "insert:");
    printf(" %d", data);
    printf(" %s", "\n");

    if(!isFull(stack)){
        insert(root, data);

        printf(" %s", "the value:");
        printf(" %d", data);
        printf(" %s", " is inserted\n");
        inorder(root);
        printf(" %s", "\n");
        return 1;
    }
    printf(" %s", "The task stack is full.");
    return 0;
}

int taskDeleteHelper(Node* root,int data, Stack* stack){ // Insert data from tree and add task to stack
    printf(" %s", "\n task->");
    printf(" %s", "delete:");
    printf(" %d", data);
    printf(" %s", "\n");

    if(!isFull(stack)){
        if((deleteNode(root, data) != NULL) ){
            printf(" %s", "the value:");
            printf(" %d", data);
            printf(" %s", "is deleted\n");
            inorder(root);
            printf(" %s", "\n");
            return 1;
        }
        printf(" %s", "The data not found!");
        return 0;
    }
    printf(" %s", "The task stack is full.");
    return 0;
}


void taskInsert(Node* root,int data, Stack* stack){  // Insert data from tree and add task to stack
    if (taskInsertHelper(root, data, stack) == 1){
        push(stack, 1, data);
    }
}

void taskDelete(Node* root,int data, Stack* stack){ // Delete data from tree and add task to stack
    if (taskDeleteHelper(root, data, stack) == 1){
        push(stack, 2, data);
    }
}

void taskMinimum(Node* root){  // Find minimum data on tree
    printf(" %s", "\n task->");
    printf(" %s", "minimum\n");

    printf(" %s", "minval ");
    printf(" %d", minValueNode(root)->data);
    printf(" %s", " is found\n");
}

void taskSearch(Node* root, int data){  // Search a data on tree
    printf(" %s", "\n task->");
    printf(" %s", "search:");
    printf(" %d", data);
    printf(" %s", "\n");

    printf(" %s", "searched");
    printf(" %d", data);

    int count = search(root,data);
    if(count == -1){
        printf(" %s", " is not found\n");
        return;
    }

    printf(" %s", "is found in");
    printf(" %d", count);
    printf(" %s", "step\n");
}


void throwBack(Node* root, Stack* stack, int count){

    printf(" %s", "\n\n");
    while(count != 0 && !isEmpty(stack)){
        count --;
        int task = stack->task[stack->top];
        int value = pop(stack);
        if(task ==1){
            taskDeleteHelper(root,value,stack);
        }
        else{
            taskInsertHelper(root,value, stack);
        }
    }printf(" %s", "There is no task to be undone.");
}

void tree_toList(Node *root, int index, int list[100]){  //Helper for random task generate

    if (root == NULL)
        return;

    tree_toList(root->left, index + 1, list);  // Recursive on left side childs
    tree_toList(root->right, index + 1, list);  //Recursive on right side childs

    list[index] = root->data;
}

int sizeofList(int list[100]){  //Helper for random task generate
    int index = 0;
    while(list[index] != '\0'){
        index += 1;
    }
    return index;

}


void randomTask(Node* root, Stack* stack, int n_task){ //Generate random tasks

    int list[100];
    int n_index = 0;
    if (n_task < 0) return;
    while(n_task > 0){
        int random = (rand() % 4) + 1;
        if (random ==1){  //Insert the data
            int r_number = (rand() % 100);
            taskInsert(root,r_number,stack);
        }
        else if(random == 2){   //Delete the data
            tree_toList(root, 0, list);
            n_index = sizeofList(list);


            if(n_index == 0) continue;

            int r = (rand() % (n_index));
            taskDelete(root, list[r], stack);
        }
        else if(random == 3){  // Find minimum
            taskMinimum(root);
        }
        else if(random == 4){  // Search a item
            tree_toList(root, 0, list);
            n_index = sizeofList(list);
            if(n_index == 0) continue;

            int r = (rand() % (n_index));
            taskSearch(root, list[r]);
        }

        n_task --;
    }
}
