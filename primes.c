   // primes.c
   // Řešení IJC-DU1, příklad a), 13.3.2021
   // Autor: Júlia Mazáková, FIT
   // Přeloženo: gcc 9.3.0

#include "bitset.h"
#include "eratosthenes.h"
#include <time.h>
#define SIZEOFARRAY 200000000

int main(void)
{
    clock_t start;
    start = clock();
    bitset_create(array,SIZEOFARRAY);
    unsigned long result[10];
    int i = 0;
    int num = SIZEOFARRAY-1;
    Eratosthenes(array);
    while(i!=10)
    { 
        //store last 10 prime numbers into result
        if(bitset_getbit(array,num)==0)
        {
            result[i]=num;
            i++;
        }
        num--;
        
    }
    for(int j = 9;j>=0;j--)
    printf("%lu\n",result[j]);
    clock();
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
   


}