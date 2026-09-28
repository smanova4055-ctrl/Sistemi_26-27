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
    printf("L'indirizzo di pi e' %p e contiene %'p\n", &pi, pi); // & rappresenta l'indirizzo

//      ogni cella è indicato da un indirizzo UNIVOCO
//      i puntatori a livello di codice sono obbligato a specificare il TIPO  "star" * davanti  SEMRE
//      l'indirizzo delle variabili è sempre il primo
//      la funzione scanf obbliga l'utilizzo della & passaggio di parametri per valore o ref
//      *a passagio per referenza
//      per richiamare un sotto programma devo scrivere func(&i);
//      DEALLOCATA-->liberata non è stata modificata l'area vera e propriva quando passi per valore essendo che si lavora su un altra area di memoria
//     quando passo per ref stiamo facendo unaltra copia dell'area di memoria di 8byte dove copio l'indirizzo (0x003), non lo sto direttamente
//      passando ma lo copio per ospitarla lo copio per ospitarla. modifica PERMANENTE
//      se non metto *a=1000;  cerca di sovrastarlo

    return 0;
}