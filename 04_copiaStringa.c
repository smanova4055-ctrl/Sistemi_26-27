/*
Dichiarare due stringhe di uguale dimensione.
Acquisire in una stringa una sequenza di caratteri,
quindi copiare, usando i puntatori, tutti i caratteri dalla
stringa acquisita all'altra, accedendo in modo indiretto a ciascuna
delle locazioni delle due stringhe
*/

#include <stdio.h>
#include <string.h>

int main(void){
    char string1[7]="Andrea";
    char string2[7];

    char *p1 = string1;
    char *p2 = string2;

    while(*p1 != '\0'){
        *p2=*p1;
        p1++;
        p2++;
    }
    *p2='\0';

    printf("\n%s", stringa2);
    return 0;
}