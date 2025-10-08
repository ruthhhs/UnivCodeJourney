#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "stack.h"


void createStack(TStack *S) {
    S->top = -1;
    for (int i = 0; i < 11; i++) {
        S->wadah[i] = 0.0;
    }
}

bool isEmpty(TStack S) {
    return S.top == -1;
}

bool isFull(TStack S) {
    return S.top == 9;
}

void push(TStack *S, float c) {
    if (!isFull(*S)) {
        S->top++;
        S->wadah[S->top] = c;
    }
}

void pop(TStack *S, float *c) {
    if (!isEmpty(*S)) {
        *c = S->wadah[S->top];
        S->top--;
    }
}

void printStack(TStack S) {
    printf("Isi stack sekarang: ");
    for (int i = 0; i <= S.top; i++) {
        printf("%.2f ", S.wadah[i]);
    }
    printf("\n");
}

// NO 4
// mengoperasikan postfix dan mengembalikan hasilnya
void evaluatePostfix(char postfix[]) {
    TStack S;
    createStack(&S);
    int i;
    char token;
    float b, a, result;

    for (i = 0; i < strlen(postfix); i++) {
        token = postfix[i];
        // jika angka → push ke stack
        if (isdigit(token)) {
            push(&S, (float)(token - '0'));
        }
        // jika operator → pop 2 angka, hitung, push kembali
        else {
            pop(&S, &b);
            pop(&S, &a);

            if (token == '+') {
                result = a + b;
            }
            else if (token == '-') {
                result = a - b;
            }
            else if (token == '*') {
                result = a * b;
            }
            else if (token == '/') {
                result = a / b;
            }
            else {
                printf("Operator tidak dikenal: %c\n", token);
                return;
            }
            push(&S, result);
        }
    }
    pop(&S, &result);
    printf("Hasil evaluasi: %.2f\n", result);
}