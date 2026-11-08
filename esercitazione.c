#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 1000

void visualizzaMenu(char* scelta);
void caricaVettoreCasuale(int* v, int* dimV, int min, int max);
void stampaVettore(int* v, int* dimV);

void generaStringaCasuale(char* str, int* dimStr, char min, char max);
void stampaStringa(char* str, int* dimStr);

int* trovaCifreNonRipetute(int* V, int* dimV, int* dimB);
void controllaContenuto(char* s1, char* s2);

void verificaCaratteriRipetuti(char* s1);
int* separaPariDispari(int* A, int* dimV);
char* duplicaEInvertiMinuscole(char* str);

int main(void)
{
    char* scelta;
    // Ese1
    int* dimV;
    int* dimB;
    int* A;
    // Ese2
    char* s1;
    // Ese3
    int* A3;
    int* B3;
    // Ese4
    char* str4;
    char* strModificata;
    // Ese5
    char* s2;

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

                A = (int*) malloc(sizeof(int) * (*dimV));

                caricaVettoreCasuale(A, dimV, 0, 10);
                printf("Vettore di valori casuali: ");
                stampaVettore(A, dimV);

                dimB = (int*) malloc(sizeof(int));
                int *B = trovaCifreNonRipetute(A, dimV, dimB);
                if (*dimB > 0) {
                    printf("Vettore senza ripetizioni: ");
                    stampaVettore(B, dimB);
                } else {
                    printf("Nessun elemento unico trovato.\n");
                }
                free(A);
                free(B);
                free(dimV);
                free(dimB);
                break;
            case 'b':
            case 'B':
                s1 = (char*) malloc(sizeof(char) * MAX);
                printf("Inserisci stringa > ");
                gets(s1);
                // Rialloco per ottimizzare spazio in memoria
                s1 = realloc(s1, sizeof(char) * (strlen(s1)) + 1);
                printf("Stringa inserita: %s\n", s1);
                verificaCaratteriRipetuti(s1);
                free(s1);
            break;
            case 'c':
            case 'C':
                dimV = (int*) malloc(sizeof(int));
                do{
                    printf("Inserisci la dimensione del vettore (tra 3 e %d) > ", MAX - 1);
                    scanf("%d", dimV);
                }while(*dimV <= 2 || *dimV >= MAX);

                A3 = (int*) malloc(sizeof(int) * (*dimV));
                caricaVettoreCasuale(A3, dimV, 0, 50);

                printf("Vettore originale: ");
                stampaVettore(A3, dimV);

                B3 = separaPariDispari(A3, dimV);
                printf("Vettore con pari in testa e dispari in coda: ");
                stampaVettore(B3, dimV);

                free(A3);
                free(B3);
                free(dimV);
            break;
            case 'd':
            case 'D':
                str4 = (char*) malloc(sizeof(char) * MAX);
                printf("Inserisci stringa > ");
                gets(str4);
                str4 = (char*) realloc(str4, sizeof(char) * (strlen(str4) + 1));
                strModificata = duplicaEInvertiMinuscole(str4);
                printf("Stringa modificata: %s\n", strModificata);

                free(str4);
                free(strModificata);
                break;
            case 'e':
            case 'E':s1 = (char*) malloc(sizeof(char) * MAX);
                printf("Inserisci stringa > ");
                gets(s1);
                s1 = realloc(s1, sizeof(char) * (strlen(s1)) + 1);
                printf("%s\n", s1);

                s2 = (char*) malloc(sizeof(char) * MAX);
                printf("Inserisci stringa > ");
                gets(s2);
                // Rialloco per ottimizzare spazio in memoria
                s2 = realloc(s2, sizeof(char) * (strlen(s2)) + 1);
                printf("%s\n", s2);

                controllaContenuto(s1, s2);

                free(s1);
                free(s2);
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
    printf("d. Svolgi esercizio 4\n");
    printf("e. Svolgi esercizio 5\n");
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

int* trovaCifreNonRipetute(int* A, int* dimV, int* dimB){
    int* i = (int*) calloc(1, sizeof(int));
    int* j = (int*) calloc(1, sizeof(int));
    int* B = NULL;
    int* cont = (int*) calloc(1,sizeof(int));
    *dimB = 0;
    for(*i = 0; *i < *dimV; (*i)++){
        *cont = 0;
        for(*j = 0; *j < *dimV; (*j)++){
            if(*(A + *i) == *(A + *j)){
                (*cont)++;
            }
        }
        if (*cont == 1) {
            (*dimB)++;
            B = (int*) realloc(B, sizeof(int) * (*dimB));
            *(B + (*dimB) - 1) = *(A + *i);
        }
    }
    free(i);
    free(j);
    free(cont);
    return B;
}

void controllaContenuto(char* s1, char* s2){
    int* i = (int*) calloc(1, sizeof(int));
    int* j = (int*) calloc(1, sizeof(int));
    bool* uguali = (bool*) malloc(sizeof(bool));

    *uguali = false;

    while(*(s1 + *i) != '\0' && *uguali == false){
        *j=0;
        while(*(s1 + *i + *j) !='\0' && *(s2 + *i) != '\0' && *(s1 + *i + *j) == *(s2 + *j)){
            (*j)++;
        }

        if(*(s2 +*j) == '\0'){
            *uguali = true;
        }
        (*i)++;
    }
    if(*uguali == true){
        printf("La seconda stringa e' contenuta nella prima\n");
    }else{

        printf("La seconda stringa non e' contenuta nella prima\n");
    }
    free(i);
    free(j);
    free(uguali);
}

void verificaCaratteriRipetuti(char* s1){
    int* i = (int*) calloc(1, sizeof(int));
    int* j = (int*) calloc(1, sizeof(int));
    int* conteggio = (int*) calloc(1, sizeof(int));
    bool* tuttiRipetuti = (bool*) malloc(sizeof(bool));
    int* len = (int*) malloc(sizeof(int));

    *len = (int)strlen(s1);
    *tuttiRipetuti = true;

    for(*i = 0; *i < *len && *tuttiRipetuti; (*i)++){
        *conteggio = 0;
        for(*j = 0; *j < *len; (*j)++){
            if(*(s1 + *i) == *(s1 + *j)){
                (*conteggio)++;
            }
        }
        if(*conteggio < 2){
            *tuttiRipetuti = false;
        }
    }

    if(*tuttiRipetuti && *len > 0){
        printf("Tutti i caratteri compaiono piu' di una volta\n");
    } else {
        printf("Non tutti i caratteri compaiono piu' di una volta\n");
    }

    free(i);
    free(j);
    free(conteggio);
    free(tuttiRipetuti);
    free(len);
}

int* separaPariDispari(int* A, int* dimV){
    int* B = (int*) malloc(sizeof(int) * (*dimV));
    int* i = (int*) calloc(1, sizeof(int));
    int* testa = (int*) calloc(1, sizeof(int));
    int* coda = (int*) malloc(sizeof(int));

    *coda = *dimV - 1;

    for(*i = 0; *i < *dimV; (*i)++){
        if(*(A + *i) % 2 == 0){
            *(B + *testa) = *(A + *i);
            (*testa)++;
        } else {
            *(B + *coda) = *(A + *i);
            (*coda)--;
        }
    }

    free(i);
    free(testa);
    free(coda);
    return B;
}

char* duplicaEInvertiMinuscole(char* str){
    int* i = (int*) calloc(1, sizeof(int));
    int* j = (int*) calloc(1, sizeof(int));
    int* len = (int*) malloc(sizeof(int));

    *len = (int)strlen(str);

    char* risultato = (char*) malloc(sizeof(char) * ((*len * 2) + 1));

    for(*i = 0; *i < *len; (*i)++){
        char ch = *(str + *i);
        if(ch >= 'a' && ch <= 'z'){
            *(risultato + *j) = ch;
            (*j)++;
            *(risultato + *j) = (char)toupper((unsigned char)ch);
            (*j)++;
        } else {
            *(risultato + *j) = ch;
            (*j)++;
        }
    }
    *(risultato + *j) = '\0';
    risultato = (char*) realloc(risultato, sizeof(char) * (*j + 1));

    free(i);
    free(j);
    free(len);
    return risultato;
}