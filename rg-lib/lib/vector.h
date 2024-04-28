//
//  vector.h
//  rg-lib
//
//  Created by Rabin Gaire on 28/04/2024.
//

#ifndef vector_h
#define vector_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "type.h"

#define VECTOR_DEFAULT_CAPACITY 4

enum vector_type {
  VECTOR_INT = 0,
  VECTOR_FLOAT,
};
typedef enum vector_type Vector_dt;

typedef struct vector {
  Vector_dt type;
  void** values;
  int size;
  int capacity;
} Vector_t;

Vector_t* vector_new(Vector_dt type);
Vector_t* vector_with_capacity(Vector_dt type, int capacity);

void vector_append(Vector_t* vec, void* value);
void vector_clear(Vector_t* vec);
void vector_print(const Vector_t* vec);
bool vector_empty(const Vector_t* vec);
void* vector_at(const Vector_t* vec, int index);
void vector_free(Vector_t* vec);

static inline void** _alloc_vector_internal_array(int capacity) {
  void** values = {0};
  values = malloc(sizeof(void*) * capacity);
  return values;
}

static inline void _vector_print(void** values, Vector_dt type, int size) {
  printf("[ ");
  for (int idx = 0; idx < size; ++idx) {
    if (type == VECTOR_INT) {
      int * value = values[idx];
      printf("%d ", *value);
    } else if (type == VECTOR_FLOAT) {
      float * value = values[idx];
      printf("%f ", *value);
    } else {
      _unsupported_type();
    }
  }
  printf("]\n");
}

#endif /* vector_h */
