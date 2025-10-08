// ======================================================
// Nama Program: mainStack.h
// Deskripsi   : driver ADT Tstack
// NIM/Nama    :
// 24060124120024/Ruth Septriana Sipangkar
// 24060124130088 / Syafira Azka Ramadhani
// 24060124130116 / Yasmina Syahidah
// 24060124130082 / Sarifa Nuha Ardanti Jusmar
// ======================================================
#include <stdio.h>
#include <string.h>
#include "stack.h"

int main(){
    printf("\n=========== NO 3 ==========\n");
    char infix[] = "3+(4*3)/4";
    char postfix[10];
    InfixToPostfix(infix, postfix);
    printf("Infix   : %s\n", infix);
    printf("Postfix : %s\n", postfix);

    char infix1[] = "3*(4+5)/2";
    char postfix1[10];
    InfixToPostfix(infix1, postfix1);
    printf("Infix   : %s\n", infix1);
    printf("Postfix : %s\n", postfix1);

    char infix2[] = "3+(4*5)-2";
    char postfix2[10];
    InfixToPostfix(infix2, postfix2);
    printf("Infix   : %s\n", infix2);
    printf("Postfix : %s\n", postfix2);

    return 0;
}
