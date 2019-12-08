#include<stdio.h>
#include<stdlib.h>

struct stack {
    int top;
    int capacity;
    int* task;
    int* values;
};
typedef struct stack Stack;
Stack* createStack(int capacity);
int isFull(Stack* stack);
int isEmpty(Stack* stack);
void push(Stack* stack, int t, int item);
int pop(Stack* stack);