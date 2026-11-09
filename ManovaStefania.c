#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 100 

void menu(char *scelta);
// ES 1
void caricaCasualeChar(char *str, int *len, char min, char max);
void stampaArrayChar(char *str, int *len);
int *contaLetterePrimaMeta(char *str, int *len);
// ES 2
void caricaCasualeInt(int *arr, int *len, int min, int max);
void stampaArrayInt(int *arr, int *len);
void caricaMultipli(int *arr, int *len);
// ES 3
void sostituisciConsonanti(char *str);

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
            Generare un array di caratteri il cui range è compreso tra ‘A’-‘Z’ e ‘a’-‘z’. 
            Contare quante lettere appartengono alla prima metà dell'alfabeto (A-M o a-m)
            */
            int *charLettere = (int*)malloc(sizeof(int));
            int *dim = (int*)malloc(sizeof(int));
                printf("inserisci la dimensione della stringa: \n");
                scanf("%d", dim);
                char *s = (char*)malloc(sizeof(char)*(*dim + 1));
                caricaCasualeChar(s,dim, "a", "Z");
                stampaArrayChar(s,dim);
                charLettere = contaLetterePrimaMeta(s,dim);
                printf("Nella stringa appartengono alla prima metà dell'alfabeto: %d\n", *charLettere);
                
                free(s);
                free(dim);
                free(charLettere);
                
            break;
        case 'b':
        case 'B':
            /*
            Dato un array di interi, caricarlo casualmente con valori compresi tra 1 e 100.
            Caricare in un array multipli3 tutti i valori divisibili per 3.
            Caricare in un array multipli5 tutti i valori divisibili per 5.
            Stampare entrambi gli array.
            Attenzione: un numero divisibile sia per 3 che per 5 deve comparire in entrambi gli array.
            Ottimizzare l'occupazione di memoria.: i due array devono aumentare di dimensione solo quando un valore viene caricato
            */
            int *arr = (int*)malloc(sizeof(int));
            int *dim = (int*)malloc(sizeof(int));
            arr = caricaCasualeInt(arr, dim,1,100);
            stampaArrayInt(arr,dim);

            int *arr1 = (int*)malloc(sizeof(int));
            int *dim1 = (int*)malloc(sizeof(int));
            arr = caricaMultipli(arr1, dim1);
            stampaArrayInt(arr1,dim1);

            int *arr2 = (int*)malloc(sizeof(int));
            int *dim2 = (int*)malloc(sizeof(int));
            arr = caricaMultipli(arr2, dim2);
            stampaArrayInt(arr2,dim2);

            free(dim);
            free(arr);
            free(dim1);
            free(arr1);
            free(dim2);
            free(arr2);

            break;
        case 'c':
        case 'C':
            /*
            Data una stringa in input, sostituire tutte le consonanti con il carattere *, lasciando invariate le vocali.
            Es. stringa => “Allocazione dinamica” stringa modificata => “A**o*a*io*e *i*a*i*a”
            */
            s = (char *)malloc(sizeof(char) * (MAX + 1));
            *(s + MAX) = '\0';

            printf("Inserisci la tua stringa: \n");
            getchar();
            gets(s);
            s = realloc(s, sizeof(char) * (strlen(s) + 1));
            sostituisciConsonanti(s);
            stampaStringa(s);
            free(s);
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
int *contaLetterePrimaMeta(char *str, int *len)
{
    int* i = (int*)malloc(sizeof(int));
    int* cont = (int*)calloc(1,sizeof(int));
    for(*i=0; *i<*len; (*i)++){
        if((*(str+*i)>='a'&&*(str+*i)<='m')||(*(str+*i)>='A'&&*(str+*i)<='M')){
            (*cont)++;
        }
    }
    free(i);
    return cont, cont2;
}
// ES 2
void caricaCasualeInt(int *arr, int *len, int min, int max)
{
    int* i = (int*)malloc(sizeof(int));
    for(*i=0; *i<*len; (*i)++){
        *(arr+*i) = (char)(min + rand() % (max - min + 1));
    }
    *(arr+*len) = '\0';
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
void caricaMultipli(int *arr, int *len)
{
    int *aux;
    aux = (int *)malloc(sizeof(int) * (*len));
    int *aux2;
    aux2 = (int *)malloc(sizeof(int) * (*len));
    int *j;
    j = (int *)malloc(sizeof(int));
    *j = 0;
    k = (int *)malloc(sizeof(int));
    *k = 0;

    int *i;
    i = (int *)malloc(sizeof(int));

    for (*i = 0; *i < *len; (*i)++)
    {
        if (*(arr + *i) % 3 == 0)
        {
            *(aux + *j) = *(arr + *i);
            (*j)++;
        }
        else if (*(arr + *i) % 5 == 0)
        {
            *(aux2 + *k) = *(arr + *i);
            (*k)++;
        }
    }
}
// ESERCIZIO 3
void sostituisciConsonanti(char *str)
{
     int *i = (int *)calloc(1, sizeof(int));
    int *j = (int *)calloc(1, sizeof(int));
    char *s1 = (char *)malloc(sizeof(char) * (strlen(s) * 2 + 1));

    while (*(str + *i) != '\0')
    {
        *(s1 + *j) = *(str + *i);
        (*j)++;
        if ((*(str + *i)) !='a' && (*(str + *i)) != 'e' && (*(str + *i)) != 'i'  && (*(str + *i)) != 'o'  && (*(str + *i)) != 'u')
        {
            *(s1 + *j) = "*";
            (*j)++;
        }
        (*i)++;
    }

    *(s1 + *j) = '\0';

    strcpy(str, s1);
    free(i);
    free(j);
    free(s1);
}