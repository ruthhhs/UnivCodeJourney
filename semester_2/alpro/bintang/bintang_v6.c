#include <stdio.h>

int main(){
// kamus
  int i, j, n, space;

// algoritma
printf("masukkan bilangan ganjil (int): ");
scanf("%d", &n);

  for (i=n; i>=1; i-=1){
    for (space=1; space<=(n-i); space++){
      printf("  ");
    }
    for (j=1; j<=i; j++){
      printf("* ");
    }
  printf("\n");
}

  return 0;
}