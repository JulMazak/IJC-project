   // ppm.h
   // Řešení IJC-DU1, příklad b), 13.3.2021
   // Autor: Júlia Mazáková, FIT
   // Přeloženo: gcc 9.3.0
  #ifndef PPM_H
  #define PPM_H
   struct ppm {
        unsigned xsize;
        unsigned ysize;
        char data[];    // RGB bajty, celkem 3*xsize*ysize
     };
     
     struct ppm * ppm_read(const char * filename);


     void ppm_free(struct ppm *p);

  #endif