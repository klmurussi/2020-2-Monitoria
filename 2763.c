#include <stdio.h>

int main()
{
  char vetor[14];
  int i;
  
  for (i = 0; i<14; i++){
      scanf ("%c", &vetor[i]);
  }
  if (vetor[3] == '.' && vetor[7] == '.' && vetor[11] == '-'){
      if ((vetor[0] == '0' || vetor[0] == '1' || vetor[0] == '2' || vetor[0] == '3' || vetor[0] == '4' || vetor[0] == '5'
       || vetor[0] == '6' || vetor[0] == '7' || vetor[0] == '8' || vetor[0] == '9') && (vetor[1] == '0' || 
       vetor[1] == '1' || vetor[1] == '2' || vetor[1] == '3' || vetor[1] == '4' || vetor[1] == '5'
       || vetor[1] == '6' || vetor[1] == '7' || vetor[1] == '8' || vetor[1] == '9') && (vetor[2] == '0' 
       || vetor[2] == '1' || vetor[2] == '2' || vetor[2] == '3' || vetor[2] == '4' || vetor[2] == '5'
       || vetor[2] == '6' || vetor[2] == '7' || vetor[2] == '8' || vetor[2] == '9') && (vetor[4] == '0' || 
       vetor[4] == '1' || vetor[4] == '2' || vetor[4] == '3' || vetor[4] == '4' || vetor[4] == '5'
       || vetor[4] == '6' || vetor[4] == '7' || vetor[4] == '8' || vetor[4] == '9') && (vetor[5] == '0' || 
       vetor[5] == '1' || vetor[5] == '2' || vetor[5] == '3' || vetor[5] == '4' || vetor[5] == '5'
       || vetor[5] == '6' || vetor[5] == '7' || vetor[5] == '8' || vetor[5] == '9') && (vetor[6] == '0' ||
       vetor[6] == '1' || vetor[6] == '2' || vetor[6] == '3' || vetor[6] == '4' || vetor[6] == '5'
       || vetor[6] == '6' || vetor[6] == '7' || vetor[6] == '8' || vetor[6] == '9') && (vetor[8] == '0' || 
       vetor[8] == '1' || vetor[8] == '2' || vetor[8] == '3' || vetor[8] == '4' || vetor[8] == '5'
       || vetor[8] == '6' || vetor[8] == '7' || vetor[8] == '8' || vetor[8] == '9') && (vetor[9] == '0' || 
       vetor[9] == '1' || vetor[9] == '2' || vetor[9] == '3' || vetor[9] == '4' || vetor[9] == '5'
       || vetor[9] == '6' || vetor[9] == '7' || vetor[9] == '8' || vetor[9] == '9') && (vetor[10] == '0' || 
       vetor[10] == '1' || vetor[10] == '2' || vetor[10] == '3' || vetor[10] == '4' || vetor[10] == '5'
       || vetor[10] == '6' || vetor[10] == '7' || vetor[10] == '8' || vetor[10] == '9') && (vetor[12] == '0' || 
       vetor[12] == '1' || vetor[12] == '2' || vetor[12] == '3' || vetor[12] == '4' || vetor[12] == '5'
       || vetor[12] == '6' || vetor[12] == '7' || vetor[12] == '8' || vetor[12] == '9') && (vetor[13] == '0' || 
       vetor[13] == '1' || vetor[13] == '2' || vetor[13] == '3' || vetor[13] == '4' || vetor[13] == '5'
       || vetor[13] == '6' || vetor[13] == '7' || vetor[13] == '8' || vetor[13] == '9')) {
           printf ("%c%c%c\n", vetor[0], vetor[1], vetor[2]);
           printf ("%c%c%c\n", vetor[4], vetor[5], vetor[6]);
           printf ("%c%c%c\n", vetor[8], vetor[9], vetor[10]);
           printf ("%c%c\n", vetor[12], vetor[13]);
       }
  }