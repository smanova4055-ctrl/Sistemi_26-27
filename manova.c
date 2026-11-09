#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
    char* str;
    int* len;
    int* cont;
    int* arr;

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
            len = (int*)malloc(sizeof(int));
            do
            {
                printf("Inserisci la dimensione del vettore ");
                scanf("%d", len);
            } while (*len < 1);

            str = (char*)malloc(sizeof(char) * (*len));
            caricaCasualeChar(str, len, 'A', 'z');
            printf("Vettore ");
            stampaArrayChar(str, len);

            cont = contaLetterePrimaMeta(str, len);
            printf("Lettere nella prima meta' dell'alfabeto: %d\n", *cont);

            free(cont);
            free(str);
            free(len);
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
            len = (int*)malloc(sizeof(int));
            do
            {
                printf("Inserisci la dimensione del vettore ");
                scanf("%d", len);
            } while (*len < 1);

            arr = (int*)malloc(sizeof(int) * (*len));
            caricaCasualeInt(arr, len, 1, 100);
            printf("Vettore casuale: ");
            stampaArrayInt(arr, len);
            caricaMultipli(arr, len);

            free(arr);
            free(len);
            break;
        case 'c':
        case 'C':
            /*
            Data una stringa in input, sostituire tutte le consonanti con il carattere *, lasciando invariate le vocali.
            Es. stringa => “Allocazione dinamica” stringa modificata => “A**o*a*io*e *i*a*i*a”
            */
            str = (char *)malloc(sizeof(char) * MAX);

            printf("Inserisci una stringa > ");
            gets(str);
            str = (char*) realloc(str, sizeof(char) * (strlen(str) + 1));

            sostituisciConsonanti(str);
            printf("Stringa modificata: %s\n", str);
            free(str);
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
    // (char)(min + rand() % (max - min + 1));
    int *i = (int *)malloc(sizeof(int));
    for (i = str; i < str + *len; i++) {
            *(str + *i) = (char)(min + rand() % (max - min + 1));     
    }
    free(i);
}
void stampaArrayChar(char *str, int *len)
{
    int *i = (int *)malloc(sizeof(int));
    for (*i = 0; *i < *len; (*i)++)
        printf("%c ", *(str + *i));
    printf("\n");
    free(i);
}
int *contaLetterePrimaMeta(char *str, int *len)
{
    int *cont = (int *)calloc(1, sizeof(int));
    int *i = (int *)malloc(sizeof(int));

    for (*i = 0; *i < *len; (*i)++)
        if ((*(str + *i) >= 'A' && *(str + *i) <= 'M') ||
            (*(str + *i) >= 'a' && *(str + *i) <= 'm'))
            (*cont)++;

    free(i);
    return cont;
}
// ES 2
void caricaCasualeInt(int *arr, int *len, int min, int max)
{
    int *i = (int *)malloc(sizeof(int));
    for (*i = 0; *i < *len; (*i)++)
        *(arr + *i) = rand() % (max - min + 1) + min;
    free(i);
}
void stampaArrayInt(int *arr, int *len)
{
    int *i = (int *)malloc(sizeof(int));
    for (*i = 0; *i < *len; (*i)++)
        printf("%d ", *(arr + *i));
    printf("\n");
    free(i);
}
void caricaMultipli(int *arr, int *len)
{
    int *i = (int *)malloc(sizeof(int));    
    int *multipli3 = NULL;
    int *multipli5 = NULL;
    int *cont3 = (int *)calloc(1, sizeof(int));
    int *cont5 = (int *)calloc(1, sizeof(int));
    for (*i = 0; *i < *len; (*i)++)
    {
        if (*(arr + *i) % 3 == 0){

        }
    }
    free(multipli3);
    free(multipli5);
    free(cont3);
    free(cont5);
    free(i);

}
// ESERCIZIO 3
void sostituisciConsonanti(char *str)
{
     while (*str != '\0')
    {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
            if (*str != 'a' && *str != 'e' && *str != 'i' && *str != 'o' && *str != 'u' &&
                *str != 'A' && *str != 'E' && *str != 'I' && *str != 'O' && *str != 'U')
                *str = '*';
        str++;
    }
}