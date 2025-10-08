/* Program   : tstack.c */

#include <stdio.h>
#include "tstack.h"
#include "boolean.h"

/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T){
    for (int i = 0; i < 10; i++)
    {
        T->wadah[i] = '#';
        T->top = 0 ;
        
    }
    
}

/*function top( T: Tstack) -> integer
	{mengembalikan posisi puncak stack } */
//int top (Tstack T);
//dalam praktikum ini, fungsi dapat direalisasikan
//menjadi macro dalam bahasa C.
#define top(T) (T).top

/*function infotop( T: Tstack) -> character
	{mengembalikan nilai elemen top stack } */
//char infotop (Tstack T);
#define infotop(T) (T).wadah[(T).top]

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T){
    return T.top == 0;
}

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T){
    return T.top == 10;
}

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E){
    if (!isFullStack(*T))
    {
        T->top = T->top + 1;
        T->wadah[T->top] = E;
    }
    
}

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X){
    if (!isEmptyStack(*T))
    {
        *X = T->wadah[T->top];
        T->top = T->top - 1;
        T->wadah[T->top+1] = '#'; 
    }
    
}

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T){
    for (int i = 0; i < 10; i++)
    {
        printf("%c\n", T.wadah[i]);
    }
    
}

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack T){
    for (int i = 1; i <= T.top; i++)
    {
        printf("%c\n", T.wadah[i]);

    }
}
/* kerjakan latihan aplikasi stack di file mbrowser.c */

/*kata adalah string yang didalamnya dapat berisi tanda kurung (), {}, ataupun [].
Fungsi ini mengecek apakah pasangan kurung buka dan kurung tutup di dalam kata sesuai. Fungsi mengembalikan true jika sesuai, dan false jika sebaliknya}
*/
boolean isValidKurung(char kata[100]){
    Tstack S;
    createStack(&S);
    int i = 0;
    boolean valid = true;
    while (kata[i] != '\0' && valid)
    {
        if (kata[i] == '(' || kata[i] == '{' || kata[i] == '[')
        {
            push(&S, kata[i]);
        } else if (kata[i] == ')' || kata[i] == '}' || kata[i] == ']')
        {
            if (isEmptyStack(S))
            {
                valid = false;
            } else {
                char topChar;
                pop(&S, &topChar);
                if ((kata[i] == ')' && topChar != '(') ||
                    (kata[i] == '}' && topChar != '{') ||
                    (kata[i] == ']' && topChar != '[')) {
                    valid = false;
                }
            }
        }
        i++;
    }
    if (!isEmptyStack(S)) {
        valid = false;
    }    
    return valid;
}
