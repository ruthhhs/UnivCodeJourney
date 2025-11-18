#include "list1.h"

int main(){
    // kamus
    address A; List1 senarai;

    // algoritma
    create(&senarai);
    printf("Is Empty: %s", isempty(senarai) ? "True" : "False");

    return 0;
}