#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 100

void visualizzaMenu();
int verificaPalindroma(char *str);

int main(void)
{

    int* scelta;
    //ESE 1
    char *str;
   


    //ESE 2
    scelta = (int*) malloc(sizeof(int));

   
    do{
        visualizzaMenu();
        printf("\nscelta: ");
        scanf("%d", scelta);#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
void visualizzaMenu();

int main(void)
{
    int* scelta;
    //Ese1
    char* str;
    //

    scelta = (int*) malloc(sizeof(int));

    do{
        visualizzaMenu();
        printf("Scelta > ");
        scanf("%d", scelta); // pernde il valore traducibile in intero e lo salva in un area di memoria specifica, secondo parametro un INDIRIZZO

        system("@cls||clear");

        switch(*scelta)
        {
            case 1:
            // Data in input una stringa, verificare se è PALINDROMA
            str = (char*)malloc(sizeof(char) * MAX);
            printf("Inserisci stringa > ");
            gets(str);
            //Rialloco per ottimizzare spazio in memoria
            str = realloc(str, sizeof(char)  * (strlen(str)) + 1);
            printf("Stringa inserita > %s\n", str);
            printf("Dimensione > %d\n" , strlen(str));
            break;
            case 2:
            break;
            case 0:
            printf("Arrivederci....\n");
            break;
            default:
            printf("Opzione non disponibile\n");
        }

    }while(*scelta != 0);
    free(scelta);

    return 0;
}
void visualizzaMenu()
{
    printf("\nESERCITAZIONE - PUNTATORI\n");
    printf("1. Verifica se una stirnga e' palindroma\n");
    printf("2. Inverti una stringa\n");
    printf("3. Conta vocali e consonansti di una stringa\n");
    printf("4. Cerca una valore in un vetore\n");
    printf("5. Calcola minimo, massimo e media di un vettore\n");
    printf("6. Concatena due stringhe\n");
    printf("0. Esci\n");

}

        system("@cls||clear");

        fflush(stdin);
        switch (*scelta)
        {
            case 1:
                str = (char*) malloc(sizeof(char) * DIM);
                /* data in input una stringa verificare se è palindroma*/
                printf("inserisci stringa: ");
                gets(str);

                //Rialloco per ottimizzare spazio in memoria
                str = realloc(str, sizeof(char) * (strlen(str)) + 1);

                if(verificaPalindroma(str) == 1)
                    printf("La stringa %s e' palindroma\n", str);
                else
                    printf("La stringa %s NON e' palindroma\n", str);
 
                break;
            case 2:
                /* code */
                break;
            case 0:
                printf("Arrivederci... ");
                break;
            default:
                printf("Opzione non disponibile!");
       
       
        }

    }while(*scelta != 0);

    free(scelta);


    return 0;
}


void visualizzaMenu(){
    printf("\nESERCITAZIONE PUNTATORI");
    printf("\n1. Verifica se la stringa e' palindroma");
    printf("\n2. Inverti Una Stringa");
    printf("\n3. Conta vocali e consonanti in una stringa");
    printf("\n4. carca un valore in un vettore");
    printf("\n5. calcola min max e media di un vettore");
    printf("\n6. concatena una stringa");
    printf("\n0. esci");

}

int verificaPalindroma(char *str)
{
    char *inizio;
    char *fine;
    inizio = str;
    fine = inizio + (strlen(str) - 1);
    while (inizio < fine && *inizio == *fine)
    {
        inizio++;
        fine--;
    }
    if(*inizio == *fine)
       return 1;
    return 0;
}