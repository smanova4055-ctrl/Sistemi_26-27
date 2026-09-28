#include <stdio.h>

int main(void)
{
    int v[] = {33, 44, 55};
    int i;
    int *pV;

    for(i = 0; i < 3; i++)
        //printf("v[%d]: %d indirizzo: %p\n", i, v[i], &v[i]);
        printf("v[%d]: %d indirizzo: %p\n", i, *(v+i), (v+i));



    pV = v;
    printf("Prima cella: %d con indirizzo %p\n", *pV, pV);
    pV++; 
    printf("Seconda cella: %d con indirizzo %p\n", *pV, pV);
    
    return 0;
}
