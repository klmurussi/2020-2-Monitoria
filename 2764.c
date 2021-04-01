#include <stdio.h>

int main()
{
    char vetor[8];
    int i;
    
    for (i=0; i<8; i++) {
        scanf ("%c", &vetor[i]); 
    }
        printf ("%c%c/%c%c/%c%c\n", vetor[3], vetor[4], vetor[0], vetor[1], vetor[6], vetor[7]);
        printf ("%c%c/%c%c/%c%c\n", vetor[6], vetor[7], vetor[3], vetor[4], vetor[0], vetor[1]);
        printf ("%c%c-%c%c-%c%c\n", vetor[0], vetor[1], vetor[3], vetor[4], vetor[6], vetor[7]);
    return 0;
}