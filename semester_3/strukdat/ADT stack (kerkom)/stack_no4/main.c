#include <stdio.h>
#include "stack.h"
#include "stack.c"

int main() {
    char postfix[] = "934*8+4/-"; // 9 3 4 * 8 + 4 / -
    evaluatePostfix(postfix);

    char postfix2[] = "76*9+2/"; // 9 3 4 * 8 + 4 / -
    evaluatePostfix(postfix2);

    return 0;
}
