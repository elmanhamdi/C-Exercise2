#include"stack.h"
#include <limits.h>

Stack* createStack(int capacity){
    Stack* stack = malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->task = (int*)malloc(stack->capacity * sizeof(int));
    stack->values = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(Stack* stack){
    if(stack->top == stack->capacity) return 1;  // if top is equal to capacity of stack then stack is full
    else return 0;
}

int isEmpty(Stack* stack){
    if(stack->top == -1) return 1;   //if top is equal -1 then
    else return 0;
}


// if stack is full it cannot be push item on it else push it
void push(Stack* stack, int t, int item){
    if(!isFull(stack)){
        stack->top += 1;
        stack->values[stack->top] = item;
        stack->task[stack->top] = t;
    }
    else printf(" %s", "Out of stack");
}


int pop(Stack* stack){
    if(!isEmpty(stack)){
        stack->top -= 1;
        return  stack->values[stack->top + 1];
    }
    return INT_MIN;
}
