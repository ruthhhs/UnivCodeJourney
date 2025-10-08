#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

// void createStack(TStack *S) {
//     S->top = -1;
//     for(int i=0; i<10; i++){
//         S->wadah[i]= ' ';
//     }
// }

// bool isEmpty(TStack S) {
//     return S.top == -1;
// }

// bool isFull(TStack S) {
//     return S.top == 9;
// }

// void push(TStack *S, char c) {
//     if (!isFull(*S)) {
//         S->top ++;
//         S->wadah[S->top] = c;
//     }
// }

// void pop(TStack *S, char *c) {
//     if (!isEmpty(*S)) {
//         *c = S->wadah[S->top];
//         S->top--;
//     }
// }

// void undo(TStack *undoStack, TStack *redoStack) {
//     char c;
//     if (!isEmpty(*undoStack)) {
//         pop(undoStack, &c);
//         push(redoStack, c);
//         printf("Undo: %s\n", c);
//     } else {
//         printf("Tidak ada yang bisa di-undo\n");
//     }
// }

// void redo(TStack *undoStack, TStack *redoStack) {
//     char c;
//     if (!isEmpty(*redoStack)) {
//         pop(redoStack, &c);
//         push(undoStack, c);
//         printf("Redo: %s\n", c);
//     } else {
//         printf("Tidak ada yang bisa di-redo\n");
//     }
// }

// void printStack(TStack S) {
//     printf("Isi stack sekarang: ");
//     int i;
//     for(i = 0; i <= S.top; i++) {
//         printf("%s", S.wadah[i]);
//     }
//     printf("\n");
// }

#define MAX 100

void CreateStack(TStack *S) {
    S->top = -1;
}

bool isEmpty(TStack *S) {
    return S->top == -1;
}

bool isFull(TStack *S) {
    return S->top == MAX - 1;
}

void push(TStack *S, const char *str) {
    if (!isFull(S)) {
        strcpy(S->wadah[++(S->top)], str);
    }
}

void pop(TStack *S, char *out) {
    if (!isEmpty(S)) {
        strcpy(out, S->wadah[(S->top)--]);
    }
}

void undo(TStack *undoStack, TStack *redoStack) {
    char s[50];
    if (!isEmpty(undoStack)) {
        pop(undoStack, s);
        push(redoStack, s);
    }
}

void redo(TStack *undoStack, TStack *redoStack) {
    char s[50];
    if (!isEmpty(redoStack)) {
        pop(redoStack, s);
        push(undoStack, s);
    }
}

void printStack(TStack S) {
    int i;
    for(i = 0; i <= S.top; i++) {
        printf("%s", S.wadah[i]);
    }
    printf("\n");
}