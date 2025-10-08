#include <stdio.h>
#include <string.h>
#include "stack.h"
#include <stdbool.h>

// KONSTRUKTOR
void createStack(TStack *S) {
    S->top = -1;
    for(int i=0; i<20; i++){
        S->wadah[i]= ' ';
    }
}

// SELEKTOR
// #define top(S) (S).top
// #define infotop(S) (S).wadah[(T).top]

// PREDIKAT
bool isEmpty(TStack S) {
    return S.top == -1;
}

bool isFull(TStack S) {
    return S.top == 19;
}

// MUTATOR
void push(TStack *S, char c) {
    if (!isFull(*S)) {
        S->top ++;
        S->wadah[S->top] = c;
    }
}

void pop(TStack *S, char *c) {
    if (!isEmpty(*S)) {
        *c = S->wadah[S->top];
        S->top--;
    }
}

// BACA TULIS
void printStack(TStack S) {
    printf("Isi stack sekarang: ");
    int i;
    for(i = 0; i <= S.top; i++) {
        printf("%c", S.wadah[i]);
    }
    printf("\n");
}

// OPERASI LAINNYA
// NO 3
// mengelkuarkan prioritas operator
int operator(char op) {
    if (op == '*' || op == '/'){
        return 2;
    }
    else if (op == '+' || op == '-'){
        return 1;
    }
    else {
        return 0;
    }
}

// mengubah operasi infix ke bentuk posfix
// asumsi semua input adalah valid
// string tidak ada spasi
void InfixToPostfix(char infix[], char postfix[]){
    // kamus
    TStack tampung;
    char token, c;
    int i, j = 0;

    // algoritma
    createStack(&tampung);
    for(i=0;i<strlen(infix);i++){
        token = infix[i];

        // angka
        if(token=='1' || token=='2' || token=='3' || token=='4' || token=='5' || token=='6' || token=='7' || token=='8' || token=='9' || token=='0'){
            postfix[j++] = token;
        }

        // kurung buka
        else if (token == '(') {
            push(&tampung, token);
        }

        // kurung tutup
        else if (token == ')') {
            while (!isEmpty(tampung) && tampung.wadah[tampung.top] != '(') {
                pop(&tampung, &c);
                postfix[j++] = c;
            }
            pop(&tampung, &c);
        }

        // operator
        else {
            while (!isEmpty(tampung) && operator(tampung.wadah[tampung.top]) >= operator(token)) {
                pop(&tampung, &c);
                postfix[j++] = c;
            }
            push(&tampung, token);
        }
    }

    // pop sisa operator
    while (!isEmpty(tampung)) {
        pop(&tampung, &c);
        postfix[j++] = c;
    }

    postfix[j] = '\0';
}