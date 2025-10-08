#include <stdio.h>

int main(){
// kamus
  int i, j, n;

// algoritma
printf("masukkan bilangan sembarang (int): ");
scanf("%d", &n);

  for (i=1; i<=n; i++){
    for (j=1; j<=i; j++){
        printf("* ");
    }
  printf("\n");
}

  return 0;
}