// steg-decode.c
// Řešení IJC-DU1, příklad b), 13.3.2021
// Autor: Júlia Mazáková, FIT
// Přeloženo: gcc 9.3.0
#include <stdio.h>
#include "error.h"
#include "math.h"
#include "bitset.h"
#include "eratosthenes.h"
#include "ppm.h"

int main(int argc, char const *argv[])
{
  if (argc != 2)
  {
    error_exit("nesprávny počet argumentov\n");
  }
  struct ppm *p = ppm_read(argv[1]);
  int limit = 3 * p->xsize * p->ysize;
  bitset_alloc(array, limit);
  if (array == NULL)
  {
    error_exit("Chyba v alokacii pamati.\n");
  }
  Eratosthenes(array);

  int count = 0;
  bitset_create(message, CHAR_BIT);
  //from 23th prime number
  for (int i = 23; i <= limit - 1; i++)
  {
    //checks if it's prime number
    if (!(bitset_getbit(array, i)))
    {
      int value = (p->data[i] & 1);
      bitset_setbit(message, count, value);
      count++;
      if (count == CHAR_BIT)
      {
        //end of message
        if (message[1] == '\0')
        {
          putchar('\n');
          bitset_free(array);
          ppm_free(p);
          return 0;
        }
        //print character
        else
        {
          int mes = message[1];
          printf("%c", mes);
        }
        count = 0;
      }
    }
  }
  bitset_free(array);
  ppm_free(p);
  //bad ending error
  error_exit("Sprava nespravne ukoncena.\n");
}
