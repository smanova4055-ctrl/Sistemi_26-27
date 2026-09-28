#include <stdio.h>

int main(void)
{
    int i;          // 0x005 
    char c = 'c';   // 0x00A

    int *pi; // 0x01B

    i = 10;
    printf("La variabile i occupa %d byte in memoria\n", sizeof(i));
    printf("Il tipo char occupa %d byte in memoria\n", sizeof(char));
    printf("Il tipo puntatore occupa %d byte in memoria\n", sizeof(pi));

    printf("L'indirizzo di i e' %p e contiene %d\n", &i, i);
    printf("L'indirizzo di c e' %p e contiene %c\n", &c, c);
    printf("L'indirizzo di pi e' %p e contiene %'p\n", &pi, pi); 

    return 0;
}