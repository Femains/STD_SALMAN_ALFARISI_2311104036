#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

typedef int infotype;

struct Stack{
    int array[20];
    int top;
};

void createStack(Stack &S);
void push(Stack &S,infotype x);
infotype pop(Stack &S);
void printInfo(Stack &S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);
#endif