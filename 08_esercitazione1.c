#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 100

void visualizzaMenu();
int verificaPalindroma(char *str);

int main(void)
{

    int* scelta;
    //Ese 1
    char* str;
    //Ese2
    char* str1;
    char* str2;
   


   
    scelta = (int*) malloc(sizeof(int));

   
    do{
        visualizzaMenu();
        printf("\nscelta: ");
        scanf("%d", scelta);

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
            case 6:
                str = (char*) malloc(sizeof(char) * DIM);
                printf("inserisci stringa: ");
                gets(str);
                
                break;
            case 0:
                printf("arrivederci... ");
                break;
            default:
                printf("opzione non disponibile!");
       
       
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