// bitset.h
// Řešení IJC-DU1, příklad a), 13.3.2021
// Autor: Júlia Mazáková, FIT
// Přeloženo: gcc 9.3.0
#include <assert.h>
#include "error.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
//type of bit array
typedef unsigned long bitset_t[];
//type of bit array index
typedef unsigned long bitset_index_t;

#ifndef BITSET_H
#define BITSET_H
//number of bits in unsigned long
#define SIZE (sizeof(unsigned long) * CHAR_BIT)

//create bit array
#define bitset_create(name, size)                                                \
  unsigned long name[1 + (size / SIZE) + ((size % SIZE) != 0 ? 1 : 0)] = {size}; \
  name[0] = (size);\
  _Static_assert(size > 0, "Nespravna velkost pola!");

//dynamic allocation of bit array
#define bitset_alloc(name, size)                                                                                          \
  assert((size > 0));                                                                                                     \
  bitset_index_t *name = (bitset_index_t *)calloc((1 + (size / SIZE) + ((size % SIZE) ? 1 : 0)), sizeof(bitset_index_t)); \
  name[0] = (size);                                                                                                       \
  if (name == NULL)                                                                                                       \
  {                                                                                                                       \
    fprintf(stderr, "bitset_alloc: Chyba alokace paměti\n");                                                              \
    return 1;                                                                                                             \
  }

#define bitset_free(name) free(name);

//inline function for bitset_size
#ifdef USE_INLINE
inline unsigned long bitset_size(bitset_t name)
{
  return name[0];
}
#else
// size of bit array
#define bitset_size(name) (name[0])
#endif

//inline function for bitset_setbit
#ifdef USE_INLINE
inline void bitset_setbit(bitset_t name, bitset_index_t index, int value)
{
  if ((index >= bitset_size(name)))
    error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", (bitset_index_t)index, bitset_size(name));
  else if (value != 1 && value != 0)
    error_exit("výraz nie je ani 1 ani 0 ale: %d\n", value);
  (value) ? (name[1+(index) / SIZE ] |= (1UL << ((index) % SIZE))) : (name[1+(index) / SIZE ] &= ~(1UL << ((index) % SIZE)));
  
}

#else
//set value
#define bitset_setbit(name, index, value)                                                                   \
  if ((bitset_index_t)index >= bitset_size(name))                                                           \
    error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", (bitset_index_t)index, bitset_size(name), 0); \
  value ? (name[1+((bitset_index_t)index) / SIZE ] |= (1UL << (((bitset_index_t)index) % SIZE))) : (name[1+((bitset_index_t)index) / SIZE ] &= ~(1UL << (((bitset_index_t)index) % SIZE)))
#endif

//inline function for bitset_getbit
#ifdef USE_INLINE
inline unsigned long bitset_getbit(bitset_t name, bitset_index_t index)
{
  if ((index >= bitset_size(name)))
    error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu", (bitset_index_t)index, bitset_size(name));

  return ((name[((index) / SIZE) + 1] & (1UL << ((index) % SIZE))));
}
#else
//get value of element at a specific index
#define bitset_getbit(name, index) \
  ((bitset_index_t)index >= bitset_size(name)) ? (error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu", (bitset_index_t)index, bitset_size(name)), 0) : ((name[(((bitset_index_t)index) / SIZE) + 1] & (1UL << (((bitset_index_t)index) % SIZE))))

#endif //for USE_INLINE
#endif //for BITSET_H
