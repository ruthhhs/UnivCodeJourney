/* Program   : boolean.h */

#ifndef BOOLEAN_H
#define BOOLEAN_H

/* Definisi tipe boolean */
#define boolean unsigned char
#define true 1
#define false 0

/* Makro untuk operasi boolean */
#define BOOLEAN(b) ((b) ? true : false)

#endif /* BOOLEAN_H */