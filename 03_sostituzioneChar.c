/*
Si scriva un programma che manipoli un array
di char tramite un puntatore
L'array deve avere valore iniziale ['L', 'U', 'C', 'A']
e, applicando le nozioni di aritmetica dei puntatori, si trasformi
in ['A', 'N', 'N', 'A']
*/

#include <stdio.h>

int main(void){
    char nome[] = "LUCA"; // {'L', 'U', 'C', 'A'};
    char *p = nome; //  &nome[0] passo la prima cella
    
    *p = 'A';
    p++;
    *p = 'N';
    p++;
    *p = 'N';
    p++;
    *p = 'A';
    p++;

    printf("%s", nome);
    return 0;

}