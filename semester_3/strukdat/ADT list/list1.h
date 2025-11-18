#ifndef LIST1_H
#define LIST1_H
#include <stdio.h>
#include <stdlib.h>

typedef enum {False, True} boolean;

typedef char infotype;
typedef struct telm * address;
typedef struct telm {infotype info; address next;} elm;
typedef struct {address Fisrt;} List1;

void create(List1 *L);
boolean isempty(List1 L);

#endif