#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
void visualizzaMenu();
int verificaPalindroma(char* str);

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
        fflush(stdin);

        switch(*scelta)
        {
            case 1:
            // Data in input una stringa, verificare se è PALINDROMA
            str = (char*)malloc(sizeof(char) * MAX);
            printf("Inserisci stringa > ");
            gets(str);
            //Rialloco per ottimizzare spazio in memoria
            str = realloc(str, sizeof(char)  * (strlen(str)) + 1);
            // printf("Stringa inserita > %s\n", str);
            // printf("Dimensione > %d\n" , strlen(str));
            if(verificaPalindroma(str) == 1)
              printf("La stinga %s e' PALINDROMA\n",str);
            else
              printf("La stinga %s NON e' PALINDROMA\n",str);
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
int verificaPalindroma(char* str)
{
    // 'a' 'n' 'n' 'a'
    // 'l 'u' 'c' 'a'
    char* inizio;
    char* fine;
    inizio = str;
    fine = inizio + (strlen(str) - 1);
    while(inizio < fine && *inizio == *fine );
    {
        inizio++;
        fine--;
    }
    if(*inizio == *fine)
        return 1;
    return 0;   

}