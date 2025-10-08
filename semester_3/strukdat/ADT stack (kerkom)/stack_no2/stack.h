#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

#define MAX 100

typedef struct {
    char wadah[MAX][50];
    int top;
} TStack;

void CreateStack(TStack *S);
bool isEmpty(TStack *S);
bool isFull(TStack *S);
void push(TStack *S, const char *str);
void pop(TStack *S, char *out);
void undo(TStack *undoStack, TStack *redoStack);
void redo(TStack *undoStack, TStack *redoStack);
void printStack(TStack S);

#endif