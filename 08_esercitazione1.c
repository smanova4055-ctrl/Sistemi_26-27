#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIM 100

void visualizzaMenu();
int verificaPalindroma(char *str);
void concatenaStringhe(char* str1, char* str2);
void invertiStringa(char* inizio); 
void generaStringaCasuale(char* str, int* dimStr, char min, char max)

int main(void)
{
    int* scelta;
    //Ese 1
    char* str;
    //Ese2
    char* str1;
    char* str2;
    //Ese 7
    int* dimStr; // Dimensione della stringa casuale
    srand(time(NULL));
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
                str = realloc(str, sizeof(char) * (strlen(str) + 1));

                if(verificaPalindroma(str) == 1)
                    printf("La stringa %s e' palindroma\n", str);
                else
                    printf("La stringa %s NON e' palindroma\n", str);
                
                free(str);
                break;

            case 2:
                // Allocazione memoria mancante per str
                str = (char*) malloc(sizeof(char) * DIM); 

                printf("inserisci stringa: ");
                gets(str);
                str = realloc(str, sizeof(char) * (strlen(str) + 1));
                invertiStringa(str);
                printf("Contenuto della stringa inversa: %s\n", str); // Corretto 'prinf' in 'printf'
                free(str);
                break;

            case 6:
                str1 = (char*) malloc(sizeof(char) * DIM);
                str2 = (char*) malloc(sizeof(char) * DIM);
                if(str1 != NULL && str2 != NULL)
                {
                    printf("Stringa 1 > ");
                    gets(str1);
                    printf("Stringa 2 > ");
                    gets(str2);
                    
                    // Corretta la realloc per la dimensione complessiva
                    str1 = realloc(str1, sizeof(char) * (strlen(str1) + strlen(str2) + 1));
                    concatenaStringhe(str1, str2);
                    printf("Stringa concatenata %s\n", str1); // Corretto 'prinf' in 'printf'
                }
                free(str1);
                free(str2); // Liberato str2 per evitare memory leak
                break;
            case 7:
            dimStr = (int*) malloc(sizeof(int));
            printf("Inserisci dimensione stringa >");
            scanf("%d", dimStr);
            str = (char*) malloc(sizeof(char) * (*dimStr) + 1);

            *(str + strlen(str)) = '\0';
            generaStringaCasuale(str, dimStr, 'a', 'z');
            printf("Stringa finale: %s\n", str);

            free(dimStr);
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
    printf("\n1. Verifica se la stringa e' palindroma"); // Rimosso '1.' errato prima di printf
    printf("\n2. Inverti Una Stringa");
    printf("\n3. Conta vocali e consonanti in una stringa");
    printf("\n4. carca un valore in un vettore");
    printf("\n5. calcola min max e media di un vettore");
    printf("\n6. concatena una stringa");
    printf("\n7. Caricare stribga casuale (a-z) e trasformare in maiuscolo il contenuto");
    printf("\n0. esci");
}

int verificaPalindroma(char *str)
{
    char *inizio;
    char *fine;
    
    if (strlen(str) == 0) return 1;

    inizio = str;
    fine = inizio + (strlen(str) - 1);
    
    while (inizio < fine && *inizio == *fine)
    {
        inizio++;
        fine--;
    }

    // Se i puntatori si sono incrociati o sovrapposti senza trovare differenze, è palindroma
    if (inizio >= fine)
        return 1;
    
    return 0;
}

void concatenaStringhe(char* str1, char* str2)
{
    char* inizio = str1 + strlen(str1);

    for(; *str2 != '\0'; str2++, inizio++)
        *inizio = *str2;

    *inizio = '\0';
}

void invertiStringa(char* inizio)
{
    if (strlen(inizio) == 0) return;

    char* fine = inizio + (strlen(inizio) - 1);
    char aus; // Usata variabile sullo stack al posto di malloc non liberata

    while(inizio < fine)
    {
        aus = *inizio;
        *inizio = *fine;
        *fine = aus;

        inizio++;
        fine--;
    }
}

void generaStringaCasuale(char* str, int* dimStr, char min, char max)
{
    
}
