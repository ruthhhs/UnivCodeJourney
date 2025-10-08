#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct {
    float wadah[11];
    int top;
} TStack;

void createStack(TStack *S);
bool isEmpty(TStack S);
bool isFull(TStack S);
void push(TStack *S, float c);
void pop(TStack *S, float *c);
void printStack(TStack S);
void evaluatePostfix(char postfix[]);

#endif
