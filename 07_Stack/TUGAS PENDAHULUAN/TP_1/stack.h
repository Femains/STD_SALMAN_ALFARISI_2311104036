#ifndef STACK_H
#define STACK_H

const int MAX = 15;

struct Stack {
    char info[MAX + 1];
    int Top;
};

// Function prototypes
void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, char element);
char pop(Stack &S);
void printInfo(Stack S);

#endif // STACK_H
