//
//  slice.h
//  rg-lib
//
//  Created by Rabin Gaire on 28/04/2024.
//

#ifndef slice_h
#define slice_h

#include "vector.h"

typedef enum slice_type {
  VECTOR = 0,
} Slice_dt;

typedef struct slice {
  Slice_dt type;
  void *from;
  void *from_type;
  int size;
} Slice_t;

Slice_t *slice_new(Slice_dt type, void *from, int start, int end);
void slice_print(const Slice_t *slc);

static inline void _calculate_start_pointer_for_type(Slice_t *dest,
                                                     Slice_dt type, void *from,
                                                     int start) {
  if (type == VECTOR) {
    Vector_t *vec = (Vector_t *)from;
    dest->from = vec->values + start;
    dest->from_type = (void *)&vec->type;
  } else {
    _unsupported_type();
  }
}

#endif /* slice_h */
