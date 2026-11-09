#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX 100

void visualizzaMenu();
void caricaVettoreCasuale(int *v, int *dimV, int min, int max);
void caricaMultipli(int *v, int *dimV, int *X);
void stampaAux(int *aux, int *j);
void gnomeSort(char *s, int *dim);
void stampaStringa(char *s);
int *contaVocaliFunzione(char *alessiaStaiZittaPerFavore);
void cifreNonRipetute(int *v1, int *dim, int *b, int *dimB);
void stampaVettore(int *v, int *dimV);
void caratteriTuttiRipetuti(char *s);
void dispariepari(int *v, int *dim, int *v2);
void minuscoleMaiuscole(char *s);
void controlloContenuta(char *s1, char *s2);

int main(void)
{
    int *scelta;

    int *v;
    int *dimV;
    char *s;
    int *i;

    scelta = (int *)malloc(sizeof(int));

    srand(time(NULL));

    do
    {
        visualizzaMenu();
        printf("scelta: ");
        scanf("%d", scelta);

        system("@cls||clear");
        fflush(stdin);

        switch (*scelta)
        {
        case 1:
            dimV = (int *)malloc(sizeof(int));

            printf("Inserisci la dimesione del vettore: \n");
            scanf("%d", dimV);

            v = (int *)malloc(sizeof(int) * (*dimV));

            caricaVettoreCasuale(v, dimV, -100, 100);
            printf("vettore di valori casuali: ");
            i = (int *)malloc(sizeof(int));
            for (*i = 0; *i < *dimV; (*i)++)
            {
                printf("%d | ", v[*i]);
            }
            printf("\n");
            free(i);

            int *X;
            X = (int *)malloc(sizeof(int));
            printf("Inserisci X: \n");
            scanf("%d", X);

            caricaMultipli(v, dimV, X);
            free(dimV);
            free(v);
            free(X);
            break;
        case 2:
            dimV = (int *)malloc(sizeof(int));

            printf("Inserisci la lunghezza della stringa: \n");
            scanf("%d", dimV);

            s = (char *)malloc(sizeof(char) * (*dimV + 1));

            *(s + *dimV) = '\0';

            i = (int *)malloc(sizeof(int));

            for (*i = 0; *i < *dimV; (*i)++)
            {
                *(s + *i) = (rand() % ('z' - 'a' + 1)) + 'a';
            }
            free(i);
            stampaStringa(s);
            gnomeSort(s, dimV);
            stampaStringa(s);
            free(s);
            free(dimV);
            break;
        case 3:
            s = (char *)malloc(sizeof(char) * (MAX + 1));
            *(s + MAX) = '\0';

            printf("Inserisci la tua stringa: \n");
            getchar();
            gets(s);
            s = realloc(s, sizeof(char) * (strlen(s) + 1));
            int *contaVocali;
            contaVocali = contaVocaliFunzione(s);
            printf("le vocali sono: %d\n", *contaVocali);

            free(contaVocali);
            free(s);
            break;
        case 4:
            dimV = (int *)malloc(sizeof(int));
            printf("Inserisci lunghezza vettore: \n");
            scanf("%d", dimV);

            v = (int *)malloc(sizeof(int) * (*dimV));

            int *i = (int *)malloc(sizeof(int));
            for (*i = 0; *i < *dimV; (*i)++)
            {
                *(v + *i) = rand() % ((10 - 0 + 1) + 0);
            }
            free(i);
            stampaVettore(v, dimV);
            int *dimB = (int *)malloc(sizeof(int));
            *dimB = *dimV;
            int *b = (int *)malloc(sizeof(int) * (*dimB));

            cifreNonRipetute(v, dimV, b, dimB);
            stampaVettore(b, dimB);

            free(dimV);
            free(v);
            break;
        case 5:
            s = (char *)malloc(sizeof(char *) * MAX);
            getchar();
            gets(s);
            s = realloc(s, sizeof(char) * (strlen(s) + 1));
            caratteriTuttiRipetuti(s);

            free(s);
            break;
        case 6:
            dimV = (int *)malloc(sizeof(int));
            do
            {
                printf("Inserisci lunghezza vettore [2<DIM<MAX]: \n");
                scanf("%d", dimV);
            } while ((*dimV) < 2 || (*dimV) > MAX);

            v = (int *)malloc(sizeof(int) * (*dimV));
            i = (int *)malloc(sizeof(int));
            for (*i = 0; *i < *dimV; (*i)++)
            {
                *(v + *i) = rand() % ((50 - 0 + 1) + 0);
            }
            free(i);
            stampaVettore(v, dimV);
            int *v2;
            v2 = (int *)malloc(sizeof(int) * (*dimV));

            dispariepari(v, dimV, v2);
            stampaVettore(v2, dimV);

            free(v2);
            free(dimV);
            free(v);
            break;
        case 7:
            s = (char *)malloc(sizeof(char *) * MAX);
            getchar();
            gets(s);
            s = realloc(s, sizeof(char) * (strlen(s) + 1));
            minuscoleMaiuscole(s);
            stampaStringa(s);
            free(s);
            break;
        case 8:
            char *s1 = (char *)malloc(sizeof(char *) * MAX);
            printf("Inserisci la prima stringa: \n");
            getchar();
            gets(s1);
            s1 = realloc(s1, sizeof(char) * (strlen(s1) + 1));
            char *s2 = (char *)malloc(sizeof(char *) * MAX);
            printf("Inserisci la seconda stringa: \n");
            getchar();
            gets(s2);
            s2 = realloc(s2, sizeof(char) * (strlen(s2) + 1));

            controlloContenuta(s1, s2);

            break;
        case 0:
            break;
        default:
            printf("La scelta non è disponibile\n");
            break;
        }

    } while (*scelta != 0);
    free(scelta);
    return 0;
}

void visualizzaMenu()
{
    printf("--Simulazione Verifica--\n");
    printf("1. carica multipli di X\n");
    printf("2. gnome sort\n");
    printf("3. conta vocali\n");
    printf("4. cifre che non si ripetono\n");
    printf("5. verifica se tutti i caratteri si ripetono\n");
    printf("5. pari e dispari\n");
    printf("0. esci\n");
}

void caricaVettoreCasuale(int *v, int *dimV, int min, int max)
{
    int *i;
    i = (int *)malloc(sizeof(int));

    for (*i = 0; *i < *dimV; (*i)++)
    {
        *(v + *i) = ((rand() % (max - min + 1)) + min);
    }
    free(i);
}

void caricaMultipli(int *v, int *dimV, int *X)
{
    int *aux;
    aux = (int *)malloc(sizeof(int) * (*dimV));
    int *j;
    j = (int *)malloc(sizeof(int));
    *j = 0;

    int *i;

    i = (int *)malloc(sizeof(int));

    for (*i = 0; *i < *dimV; (*i)++)
    {
        if (*(v + *i) % *X == 0)
        {
            *(aux + *j) = *(v + *i);
            (*j)++;
        }
    }

    stampaAux(aux, j);

    free(aux);
    free(i);
    free(j);
}

void stampaAux(int *aux, int *j)
{
    int *i;
    i = (int *)malloc(sizeof(int));

    for (*i = 0; *i < *j; (*i)++)
    {
        printf("%d | ", aux[*i]);
    }
    printf("\n");
    free(i);
}

void gnomeSort(char *v, int *n)
{
    int *index = (int *)calloc(1, sizeof(int));
    char *tmp;
    tmp = (char *)malloc(sizeof(char));

    while (*index < *n)
    {
        if (*index == 0)
        {
            (*index)++;
        }
        if (*(v + *index) >= *(v + *index - 1))
        {
            (*index)++;
        }
        else
        {
            *tmp = *(v + *index);
            *(v + *index) = *(v + *index - 1);
            *(v + *index - 1) = *tmp;
            (*index)--;
        }
    }
}

void stampaStringa(char *s)
{
    int *i = (int *)calloc(1, sizeof(int));

    while (*(s + *i) != '\0')
    {
        printf("%c", *(s + *i));
        (*i)++;
    }

    printf("\n");

    free(i);
}
void stampaVettore(int *v, int *dimV)
{
    int *i;
    i = (int *)malloc(sizeof(int));
    for (*i = 0; *i < *dimV; (*i)++)
    {
        printf("%d | ", *(v + *i));
    }
    printf("\n");
    free(i);
}

int *contaVocaliFunzione(char *alessiaStaiZittaPerFavore)
{
    int *i = (int *)calloc(1, sizeof(int));
    int *cont = (int *)calloc(1, sizeof(int));

    while (*(alessiaStaiZittaPerFavore + *i) != '\0')
    {
        if (*(alessiaStaiZittaPerFavore + *i) == 'a' || *(alessiaStaiZittaPerFavore + *i) == 'e' || *(alessiaStaiZittaPerFavore + *i) == 'i' || *(alessiaStaiZittaPerFavore + *i) == 'o' || *(alessiaStaiZittaPerFavore + *i) == 'u' ||
            *(alessiaStaiZittaPerFavore + *i) == 'A' || *(alessiaStaiZittaPerFavore + *i) == 'E' || *(alessiaStaiZittaPerFavore + *i) == 'I' || *(alessiaStaiZittaPerFavore + *i) == 'O' || *(alessiaStaiZittaPerFavore + *i) == 'U')
        {
            (*cont)++;
        }
        (*i)++;
    }

    free(i);

    return cont;
}

void cifreNonRipetute(int *v, int *dim, int *b, int *dimB)
{
    int *i = (int *)malloc(sizeof(int));
    int *j = (int *)malloc(sizeof(int));
    int *val = (int *)malloc(sizeof(int));
    int *cont = (int *)calloc(1, sizeof(int));
    bool *ripetuto = (bool *)malloc(sizeof(bool));

    for (*i = 0; *i < *dim; (*i)++)
    {
        *val = *(v + *i);
        *ripetuto = false;
        for (*j = 0; *j < *dim; (*j)++)
        {
            if (*val == *(v + *j) && *j != *i)
            {
                *ripetuto = true;
            }
        }
        if (*ripetuto == false)
        {
            *(b + *cont) = *val;
            (*cont)++;
        }
    }

    *dimB = *cont;

    free(i);
    free(j);
    free(val);
    free(cont);
    free(ripetuto);
}

void caratteriTuttiRipetuti(char *v)
{
    int *i = (int *)calloc(1, sizeof(int));
    int *j = (int *)calloc(1, sizeof(int));
    char *val = (char *)malloc(sizeof(char));
    bool *tuttiRipetuti = (bool *)malloc(sizeof(bool));
    bool *ripetuto = (bool *)malloc(sizeof(bool));

    *tuttiRipetuti = true;

    while (*(v + *i) != '\0')
    {
        *j = 0;
        *val = *(v + *i);
        *ripetuto = false;
        while (*(v + *j) != '\0')
        {
            if (*val == *(v + *j) && *j != *i)
            {
                *ripetuto = true;
            }
            (*j)++;
        }
        if (*ripetuto == false)
        {
            *tuttiRipetuti = false;
        }
        (*i)++;
    }

    if (*tuttiRipetuti)
    {
        printf("tutti i caratteri si ripetono");
    }
    else
    {
        printf("NON tutti i caratteri si ripetono");
    }

    free(i);
    free(j);
    free(val);
    free(tuttiRipetuti);
    free(ripetuto);
}

void dispariepari(int *v, int *dim, int *v2)
{
    int *i = (int *)malloc(sizeof(int));
    int *pari = (int *)calloc(1, sizeof(int));
    int *dispari = (int *)calloc(1, sizeof(int));

    for (*i = 0; *i < *dim; (*i)++)
    {
        if (*(v + *i) % 2 == 0)
        {
            *(v2 + *pari) = *(v + *i);
            (*pari)++;
        }
        else
        {
            *(v2 + (*dim - 1 - *dispari)) = *(v + *i);
            (*dispari)++;
        }
    }
}

void minuscoleMaiuscole(char *s)
{
    int *i = (int *)calloc(1, sizeof(int));
    int *j = (int *)calloc(1, sizeof(int));
    char *s1 = (char *)malloc(sizeof(char) * (strlen(s) * 2 + 1));

    while (*(s + *i) != '\0')
    {
        *(s1 + *j) = *(s + *i);
        (*j)++;
        if ((*(s + *i)) <= 'z' && (*(s + *i)) >= 'a')
        {
            *(s1 + *j) = *(s + *i) - 32;
            (*j)++;
        }
        (*i)++;
    }

    *(s1 + *j) = '\0';

    strcpy(s, s1);

    free(i);
    free(j);
    free(s1);
}

void controlloContenuta(char *s1, char *s2)
{
    int *i = (int *)calloc(1, sizeof(int));
    int *j = (int *)calloc(1, sizeof(int));
    bool *uguali = (bool *)malloc(sizeof(bool));

    *uguali = false;

    while (*(s1 + *i) != '\0' && *uguali == false)
    {
        *j = 0;

        while (*(s1 + *i + *j) != '\0' && *(s2 + *j) != '\0' && *(s1 + *i + *j) == *(s2 + *j))
        {
            (*j)++;
        }

        if (*(s2 + *j) == '\0')
        {
            *uguali = true;
        }

        (*i)++;
    }

    if (*uguali == true)
    {
        printf("La seconda stringa e' contenuta nella prima\n");
    }
    else
    {
        printf("La seconda stringa non e' contenuta nella prima\n");
    }

    free(i);
    free(j);
    free(uguali);
}