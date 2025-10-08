#include <stdio.h>

int main() {
    int a = 10;
    int b = 2;
    int c = a + b;
    float d = c;
    double e = d;
    printf("%f\n", d);
    printf("%lf\n", e);

    char f ='a';
    char g = 'b';
    char h = f + g;
    printf("%c\n", f);
    printf("%c\n", g);
    printf("%c\n", h);

    int i = 65;
    printf("%c\n", i);

    return 0;
}