#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 100

void menu(char *scelta);
// ES 1
void caricaCasualeChar(char *str, int *len, char min, char max);
void stampaArrayChar(char *str, int *len);
int *contaCharAlfabeto(char *str, int *len);
// ES 2
void caricaCasualeInt(int *arr, int *len, int min, int max);
void stampaArrayInt(int *arr, int *len);
void caricaPositiviNegativi(int *arr, int *len);
// ES 3
void cifrarioCesare(char *str, int *shift);

int main(void)
{
    char *scelta = (char *)malloc(sizeof(char));

    srand(time(NULL));

    do
    {
        menu(scelta);
        switch (*scelta)
        {
        case 'a':
        case 'A':
            /*
            Dato un array di char, caricarlo casualmente con valori compresi tra '!' e '}',
            stamparlo e contare quanti caratteri dell'alfabeto contiene
            */
            {
                int *charAlfabeto = (int*)malloc(sizeof(int));
                int *dim = (int*)malloc(sizeof(int));
                printf("inserisci la dimensione della stringa: \n");
                scanf("%d", dim);
                char *s = (char*)malloc(sizeof(char)*(*dim + 1));
                caricaCasualeChar(s,dim,'!','}');
                stampaArrayChar(s,dim);
                charAlfabeto = contaCharAlfabeto(s,dim);
                printf("Nella stringa i caratteri dell'alfabeto sono: %d\n", *charAlfabeto);
                free(dim);
                free(s);
                free(charAlfabeto);
            }
            break;
        case 'b':
        case 'B':
            /*
            Date un array di interi, caricarlo casualmente con valori compresi tra -20 e 20 e stamparlo.
            Caricare in un array positivi tutti i valori > 0 presenti nell'array originale.
            Caricare in un array negativi tutti i valori < 0 presenti nell'array originale.
            Stampare entrambi gli array risultanti.
            OTTIMIZZARE L'OCCUPAZIONE DI MEMORIA: i due array devono aumentare di dimensione
            solo quando un valore viene caricato
            */
            {
                int *dim = (int*)malloc(sizeof(int));
                printf("inserisci la dimensione del vettore: \n");
                scanf("%d", dim);
                int *v = (int*)malloc(sizeof(int)*(*dim));

                caricaCasualeInt(v,dim,-20,20);
                printf("vettore: \n");
                stampaArrayInt(v,dim);
                caricaPositiviNegativi(v,dim);
                free(dim);
                free(v);
            }
            break;
        case 'c':
        case 'C':
            /*
            Cifrario cesare: data una stringa in input e uno shift,
            cifrarla spostando ogni carattere dell'alfabeto di shift posizioni.
            */
            {
                int *shift = (int*)malloc(sizeof(int));
                printf("inserisci lo shift: \n");
                scanf("%d", shift);
                fflush(stdin);
                char *s = (char*)malloc(sizeof(char)*(MAX));
                printf("inserisci la stringa: \n");
                gets(s);
                s = realloc(s,sizeof(char)*(strlen(s)+1));
                *(s+strlen(s)) = '\0';
                cifrarioCesare(s,shift);

            }
            break;
        }
        getchar();
    } while (*scelta != 'q');
    printf("programma terminato...\n");
    free(scelta);
    return 0;
}

void menu(char *scelta)
{
    printf("=== VERIFICA ===\n");
    printf("a. Esercizio 1\n");
    printf("b. Esercizio 2\n");
    printf("c. Esercizio 3\n");
    printf("q. Termina\n");
    printf("Scelta > ");
    scanf("%c", scelta);
    fflush(stdin);
    system("@cls||clear");
}

void caricaCasualeChar(char *str, int *len, char min, char max)
{
    int* i = (int*)malloc(sizeof(int));
    for(*i=0; *i<*len; (*i)++){
        *(str+*i) = (char)(min + rand() % (max - min + 1));
    }
    *(str+*len) = '\0';
    free(i);
}
void stampaArrayChar(char *str, int *len)
{
    int* i = (int*)malloc(sizeof(int));
    for(*i=0; *i<*len; (*i)++){
        printf(" %c |",*(str+*i));
    }
    printf("\n");
    free(i);
}
int *contaCharAlfabeto(char *str, int *len)
{
    int* i = (int*)malloc(sizeof(int));
    int* cont = (int*)calloc(1,sizeof(int));
    for(*i=0; *i<*len; (*i)++){
        if((*(str+*i)>='a'&&*(str+*i)<='z')||(*(str+*i)>='A'&&*(str+*i)<='Z')){
            (*cont)++;
        }
    }
    free(i);
    return cont;
}
// ES 2
void caricaCasualeInt(int *arr, int *len, int min, int max)
{
    int* i = (int*)malloc(sizeof(int));
    for(*i=0; *i<*len; (*i)++){
        *(arr+*i) = (int)(min + rand() % (max - min + 1));
    }
    free(i);
}
void stampaArrayInt(int *arr, int *len)
{
    int* i = (int*)malloc(sizeof(int));
    for(*i=0; *i<*len; (*i)++){
        printf(" %d |",*(arr+*i));
    }
    printf("\n");
    free(i);
}
void caricaPositiviNegativi(int *arr, int *len)
{
    int *pos = (int*)malloc(sizeof(int));
    int *neg = (int*)malloc(sizeof(int));
    int *contPos = (int*)calloc(1,sizeof(int));
    int *contNeg = (int*)calloc(1,sizeof(int));

    int* i = (int*)malloc(sizeof(int));
    for(*i=0; *i<*len; (*i)++){
        if((*(arr+*i))<0){
            *(neg+*contNeg) = *(arr+*i);
            (*contNeg)++;
            neg = realloc(neg, sizeof(int)*(*(contNeg)+1));
        }else{
            *(pos+*contPos) = *(arr+*i);
            (*contPos)++;
            pos = realloc(pos, sizeof(int)*(*(contPos)+1));
        }
    }
    printf("numeri negativi: \n");
    stampaArrayInt(neg,contNeg);
    printf("numeri positivi: \n");
    stampaArrayInt(pos,contPos);
    free(i);
    free(pos);
    free(neg);
    free(contPos);
    free(contNeg);
}
// ESERCIZIO 3
void cifrarioCesare(char *str, int *shift)
{
    int* i = (int*)calloc(1,sizeof(int));
    char* c = (char*)malloc(sizeof(char));
    while(*(str+*i)!='\0'){
        *c = (char)(*(str+*i) + *shift);
        if(*c>'Z'){
          *(str+*i)='A' + (*c-'Z');
        }
        *(str+*i)=*c;
        (*i)++;
    }
    (*i)=0;
    
    while(*(str+*i)!='\0'){
        printf("%c", *(str+*i));
        (*i)++;
    }

    free(i);
    free(c);
}