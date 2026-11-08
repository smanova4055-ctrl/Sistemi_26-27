#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 1000

void visualizzaMenu(char* scelta);
void caricaVettoreCasuale(int* v, int* dimV, int min, int max);
void stampaVettore(int* v, int* dimV);
void caricaMultipli(int* v, int* dimV, int* X);

void generaStringaCasuale(char* str, int* dimStr, char min, char max);
void stampaStringa(char* str, int* dimStr);
void gnomeSort(char* v, int* n);
int* contaVocali(char* str);

int main(void)
{
    char* scelta;
    // Ese1
    int* dimV;
    int* v;
    int* X;
    // Ese2
    int* dimStr;
    char* vc;
    // Ese3
    char* str;
    int* vocali;

    srand(time(NULL));
    scelta = (char*) malloc(sizeof(char));

    do{
        visualizzaMenu(scelta);

        system("@cls||clear"); // pulizia della console
        fflush(stdin); // pulizia del buffer(memoria) di intro -- toglie l'invio nel testo a+invio perchè usiamo le lettere e non numeri

        switch(*scelta)
        {
            case 'a':
            case 'A':
                dimV = (int*) malloc(sizeof(int));
                do{                    
                    printf("Inserisci la dimensione del vettore > ");
                    scanf("%d", dimV);
                }while(*dimV <1);
                
                X = (int*) malloc(sizeof(int));
                v = (int*) malloc(sizeof(int) * (*dimV));

                caricaVettoreCasuale(v, dimV, -100, 100);
                printf("Vettore di valori casuali: ");
                stampaVettore(v, dimV);

                printf("Inserisci X > ");
                scanf("%d", X);
                
                caricaMultipli(v, dimV, X);

                free(v);               
                free(dimV);
                free(X);
            break;
            case 'b':
            case 'B':
                dimStr = (int*) malloc(sizeof(int));

                printf("Inserisci la dimensione del vettore > ");
                scanf("%d", dimStr);

                if(*dimStr > 0)
                {
                    vc = (char*) malloc(sizeof(char) * (*dimStr));

                    generaStringaCasuale(vc, dimStr, 'a', 'z');
                    printf("Prima del sort: ");
                    stampaStringa(vc, dimStr);

                    gnomeSort(vc, dimStr);
                    printf("Dopo il sort:  ");
                    stampaStringa(vc, dimStr);

                    free(vc);
                }
                else
                    printf("Dimensione non valida\n");

                free(dimStr);
            break;
            case 'c':
            case 'C':
                str = (char*) malloc(sizeof(char) * MAX);
                printf("Inserisci stringa > ");
                gets(str);
                // Rialloco per ottimizzare spazio in memoria
                str = realloc(str, sizeof(char) * (strlen(str)) + 1);

                vocali = contaVocali(str);
                printf("Il totale delle vocali presenti nella sotto stringa e': %d\n", *vocali);

                free(vocali);
                free(str);
            break;
            case 'q':
            case 'Q':
                printf("Arrivederci....\n");
            break;
            default:
                printf("Opzione non disponibile\n");
        }
        getchar(); // sospende l'escuzione fin quando non abbiamo un'invio nel programma così visualizzo bene tutti i dati
    }while(*scelta != 'q');
    free(scelta);
    return 0;
}

// Stampa il menu e legge la scelta
void visualizzaMenu(char* scelta){
    printf("\nSIMULAZIONE VERIFICA\n");
    printf("a. Svolgi esercizio 1\n");
    printf("b. Svolgi esercizio 2\n");
    printf("c. Svolgi esercizio 3\n");
    printf("q. Termina\n");
    printf("Scelta > ");
    scanf("%c", scelta);
    getchar(); // elimino l'invio rimasto nel buffer
}

void caricaVettoreCasuale(int* v, int* dimV, int min, int max){
    int* i;
    i = (int*) malloc(sizeof(int));

    for(*i = 0; *i < *dimV; (*i)++)
        *(v + *i) = ((rand() % (max - min + 1)) + min);

    free(i);
}

void stampaVettore(int* v, int* dimV){
    int* i;
    i = (int*) malloc(sizeof(int));

    for(*i = 0; *i < *dimV; (*i)++)
        printf("%d ", *(v + *i));
    printf("\n");

    free(i);
}

void caricaMultipli(int* v, int* dimV, int* X){
    int* aux;
    int* cont;
    int* i;
    int* j;

    if(*X == 0)
    {
        printf("X non puo' essere 0\n");
        return;
    }

    //cont = (int*) malloc(sizeof(int));
    cont = (int*) calloc(1, sizeof(int));  // così partirà da 1
    i = (int*) malloc(sizeof(int));
    // j = (int*) malloc(sizeof(int));
    //*cont = 0;

    for(*i = 0; *i < *dimV; (*i)++)
        if(*(v + *i) % *X == 0){            
            *(aux + *cont) = *(v + *i);
            (*cont)++;
        }

    printf("Multipli di %d: ", *X);
    aux = (int*) realloc(aux, (*cont) * sizeof(int));
    stampaVettore(aux, cont);
    free(aux);
    

    // for(*i = 0; *i < *dimV; (*i)++)
    //     if(*(v + *i) % *X == 0)
    //         (*cont)++;

    // if(*cont == 0)
    //     printf("Nessun multiplo di %d\n", *X);
    // else
    // {
    //     // 2) alloco SOLO lo spazio che serve
    //     aux = (int*) malloc(sizeof(int) * (*cont));
    //     *j = 0;

    //     for(*i = 0; *i < *dimV; (*i)++)
    //     {
    //         if(*(v + *i) % *X == 0)
    //         {
    //             *(aux + *j) = *(v + *i);
    //             (*j)++;
    //         }
    //     }

    //     printf("Multipli di %d: ", *X);
    //     stampaVettore(aux, cont);
    //     free(aux);
    // }

    free(cont);
    free(i);
    //free(j);
}

void generaStringaCasuale(char* str, int* dimStr, char min, char max){
    int* i;
    i = (int*) malloc(sizeof(int));

    for(*i = 0; *i < *dimStr; (*i)++)
        *(str + *i) = ((rand() % (max - min + 1)) + min);

    free(i);
}

void stampaStringa(char* str, int* dimStr){
    int* i;
    i = (int*) malloc(sizeof(int));

    for(*i = 0; *i < *dimStr; (*i)++)
        printf("%c ", *(str + *i));
    printf("\n");

    free(i);
}

void gnomeSort(char* v, int* n){

    int* index = (int*) calloc(1, sizeof(int));
    char* tmp;
    
    while(*index < *n)
    {
        if(*index == 0){
            (*index)++;
        }
        if(*(v + *index) >= *(v + (*index -1)))
            (*index)++;
        else
        {
            tmp= (char*) malloc(sizeof(char));
            *tmp = *(v + *index);
            *(v + *index) = *(v +*index -1);
            *(v + *index -1) = *tmp;
            (*index)--;
            free(tmp);
        }
    }
    free(index);

    // int index = 0;
    // char tmp;

    // while (index < *n) {
    //     if (index == 0) {
    //         index++;
    //     }
    //     if (v[index] >= v[index - 1]) {
    //         index++;
    //     } else {
    //         tmp = v[index];
    //         v[index] = v[index - 1];
    //         v[index - 1] = tmp;
    //         index--;
    //     }
    // }
}

int* contaVocali(char* str){

    int* cont = (int*) calloc(1, sizeof(int));
    int* second = (int*) calloc(1, sizeof(int));

    while(*str != '\0' || (*second <2)){
        if(*second ==1){

            if(*str == '*')
                (*second)++;
            else{
                if(*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u' ||
                *str == 'A' || *str == 'E' || *str == 'I' || *str == 'O' || *str == 'U')
                (*cont)++;
                str++;
            }
        }else{
            if(*str == '*')
                (*second)++;            
            str++;
        }
    }
    free(second);
    return cont;

}