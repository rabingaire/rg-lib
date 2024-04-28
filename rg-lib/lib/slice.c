//
//  slice.c
//  rg-lib
//
//  Created by Rabin Gaire on 28/04/2024.
//

#include "slice.h"

Slice_t *slice_new(Slice_dt type, void *from, int start, int end) {
  Slice_t *slc = {0};
  slc = (Slice_t *)malloc(sizeof(*slc));

  int len = end - start;
  slc->size = len;
  // TODO: rename this
  _calculate_start_pointer_for_type(slc, type, from, start);

  return slc;
}

void slice_print(const Slice_t *slc) {
  if (slc->type == VECTOR) {
    _vector_print(slc->from, *(Vector_dt *)slc->from_type, slc->size);
  } else {
    _unsupported_type();
  }
  printf("Size: %d\n", slc->size);
}
