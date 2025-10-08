// ======================================================
// Nama Program: mainStack.c
// Deskripsi   : driver ADT Tstack
// NIM/Nama    :
// 24060124120024 / Ruth Septriana Sipangkar
// 24060124130088 / Syafira Azka Ramadhani
// 2406014130082 / Sarifa Nuha Ardanti Jusmar
// 24060124130116 / Yasmina Syahidah
// ======================================================

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

int main() {
    TStack undoStack, redoStack;
    CreateStack(&undoStack);
    CreateStack(&redoStack);

    push(&undoStack, "Ruth");
    push(&undoStack, ", Nuha");
    push(&undoStack, ", Azka");
    push(&undoStack, ", Yasmin");
    printStack(undoStack);

    printf("Undo: ");
    undo(&undoStack, &redoStack);
    printStack(undoStack);
    printf("Undo: ");
    undo(&undoStack, &redoStack);
    printStack(undoStack);
    printf("Undo: ");
    undo(&undoStack, &redoStack);
    printStack(undoStack);
    printf("Undo: ");
    undo(&undoStack, &redoStack);
    printStack(undoStack);

    printf("Redo: ");
    redo(&undoStack, &redoStack);
    printStack(undoStack);
    printf("Redo: ");
    redo(&undoStack, &redoStack);
    printStack(undoStack);
    printf("Redo: ");
    redo(&undoStack, &redoStack);
    printStack(undoStack);
    printf("Redo: ");
    redo(&undoStack, &redoStack);
    printStack(undoStack);

    return 0;
}
