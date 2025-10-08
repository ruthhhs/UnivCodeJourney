#ifndef STACK_H
#define STACK_H

#include<stdbool.h>

typedef struct {
    char wadah[20];
    int top;
} TStack;

// KONSTRUKTOR
void createStack(TStack *S);

// SELEKTOR
#define top(S) (S).top
#define infotop(S) (S).wadah[(T).top]

// PREDIKAT
bool isEmpty(TStack S);
bool isFull(TStack S);

// MUTATOR
void push(TStack *S, char c);
void pop(TStack *S, char *c);

// NO 3
int operator(char op);
void InfixToPostfix(char infix[], char postfix[]);

#endif
