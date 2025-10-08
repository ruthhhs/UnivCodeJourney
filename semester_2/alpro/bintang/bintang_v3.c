#include <stdio.h>

int main(){
// kamus
  int i, j, n, space;

// algoritma
printf("masukkan bilangan ganjil (int): ");
scanf("%d", &n);

  for (i=1; i<=n; i+=2){
    for (space=1; space<=(n-i)/2; space++){
      printf("  ");
    }
    for (j=1; j<=i; j++){
      printf("* ");
    }
  printf("\n");
}

  return 0;
}