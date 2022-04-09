   // eratosthenes.c
   // Řešení IJC-DU1, příklad a), 13.3.2021
   // Autor: Júlia Mazáková, FIT
   // Přeloženo: gcc 9.3.0
#include <math.h>
#include "bitset.h"

void Eratosthenes(bitset_t array){
  unsigned long end = sqrt(bitset_size(array));
  bitset_setbit(array, 0, 1);
  bitset_setbit(array, 1, 1);
  for(unsigned long i = 2; i < end; i++)
  {
    //if it's prime number
     if(bitset_getbit(array, i) == 0)
     {
       //set value of 1 for all multiples
      for(unsigned long n = 2; (n * i) < bitset_size(array); n++){
        bitset_setbit(array, n * i, 1);
      }
    }
  }
}