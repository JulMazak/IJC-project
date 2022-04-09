// ppm.c
// Řešení IJC-DU1, příklad b), 13.3.2021
// Autor: Júlia Mazáková, FIT
// Přeloženo: gcc 9.3.0
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ppm.h"
#include "error.h"
#define MAX_SIZE 8000 * 8000 * 3
struct ppm *ppm_read(const char *filename)
{
      // error opening file
      FILE *file = fopen(filename, "r");
      if (file == NULL)
      {
            warning_msg("Subor sa nepodarilo otvorit");
            fclose(file);
            return NULL;
      }
      char format[3];
      int x, y, color;
      // wrong header
      if (fscanf(file, "%s %d %d %d ", format, &x, &y, &color) != 4)
      {
            warning_msg("Nespravna hlavicka suboru");
            fclose(file);
            return NULL;
      }
      if (strcmp(format, "P6"))
      {
            warning_msg("Nespravna hlavicka suboru");
            fclose(file);
            return NULL;
      }

      if (color > 255 || x <= 0 || y <= 0)
      {
            warning_msg("Nespravne hodnoty hlavicky");
            fclose(file);
            return NULL;
      }

      unsigned long size = 3 * x * y;
      //big size error
      if (size > MAX_SIZE)
      {
            warning_msg("Obrazok je prilis velky");
            fclose(file);
            return NULL;
      }
      //dynamic allocation
      struct ppm *p = (struct ppm *)malloc(sizeof(struct ppm) + size);
      if (p == NULL)
      {
            warning_msg("Chyba pri alokovani");
            fclose(file);
            return NULL;
      }
      p->xsize = x;
      p->ysize = y;
      //error reading file
      unsigned long fr = fread(p->data, sizeof(char), size, file);
      
      if(fr!=size)
      {
            warning_msg("Chyba pri nacitani obrazka");
            fclose(file);
            return NULL;
      }

      fclose(file);
      return p;
}

void ppm_free(struct ppm *p)
{
      free(p);
}
