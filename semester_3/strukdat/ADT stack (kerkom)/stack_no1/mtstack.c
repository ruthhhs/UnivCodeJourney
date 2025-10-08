/* Program   : mtstack.c */

#include <stdio.h>
#include "tstack.h"
#include "boolean.h"


int main(){	
	
	char kata[] = "(]]})";
	char kata2[] = "(A+B)*C-(D/E)}";
	char kata3[] = "{[(A+B) * (C+D)] - (7*D)}" ;
	char kata4[] = "{[(A+B) * (C+D)] - (7*D)" ;
	char kata5[] = "{[(A+B) * (C+D]) - (7*D)}" ;
	char kata6[] = "{[(A+B) * (C+D)] - (7*D))} " ;

	printf("Apakah valid '%s'? : %s", kata,  isValidKurung(kata) ? "True\n" : "False\n");
	printf("Apakah valid '%s'? : %s", kata2,  isValidKurung(kata2) ? "True\n" : "False\n");
	printf("Apakah valid '%s'? : %s", kata3,  isValidKurung(kata3) ? "True\n" : "False\n");
	printf("Apakah valid '%s'? : %s", kata4,  isValidKurung(kata4) ? "True\n" : "False\n");
	printf("Apakah valid '%s'? : %s", kata5,  isValidKurung(kata5) ? "True\n" : "False\n");
	printf("Apakah valid '%s'? : %s", kata6,  isValidKurung(kata6) ? "True\n" : "False\n");
	
	return 0;
}
