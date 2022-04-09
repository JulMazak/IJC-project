   // bitset.c
   // Řešení IJC-DU1, příklad a), 13.3.2021
   // Autor: Júlia Mazáková, FIT
   // Přeloženo: gcc 9.3.0
#include "bitset.h"
//definition of inline functions
#ifdef USE_INLINE

extern inline unsigned long bitset_size(bitset_t name);
extern inline unsigned long bitset_getbit(bitset_t name, bitset_index_t index);
extern inline void bitset_setbit(bitset_t name, bitset_index_t index, int vyraz);    

#endif 