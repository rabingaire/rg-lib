//
//  vector.c
//  rg-lib
//
//  Created by Rabin Gaire on 28/04/2024.
//

#include "vector.h"

Vector_t* vector_new(Vector_dt type) {
  Vector_t* vec = vector_with_capacity(type, VECTOR_DEFAULT_CAPACITY);
  return vec;
}

Vector_t* vector_with_capacity(Vector_dt type, int capacity) {
  Vector_t* vec = {0};
  vec = (Vector_t*) malloc(sizeof(*vec));
  
  vec->type = type;
  vec->size = 0;
  vec->capacity = capacity;
  vec->values = _alloc_vector_internal_array(capacity);
  
  return vec;
}

void vector_append(Vector_t* vec, void* value) {
  if (vec->size >= vec->capacity) {
    int new_capacity = pow(vec->capacity, 2);
    void** new_values = _alloc_vector_internal_array(new_capacity);
    
    for (int idx = 0; idx < vec->capacity; ++idx) {
      new_values[idx] = vec->values[idx];
    }
    
    free(vec->values);
    
    vec->capacity = new_capacity;
    vec->values = new_values;
  }
  
  vec->values[vec->size] = value;
  vec->size += 1;
}

void vector_clear(Vector_t* vec) {
  for (int idx = 0; idx <= vec->size; ++idx) {
    vec->values[idx] = 0;
  }
  
  vec->size = 0;
}

void vector_print(const Vector_t* vec) {
  _vector_print(vec->values, vec->type, vec->size);
  printf("Size: %d, Capacity: %d\n", vec->size, vec->capacity);
}

bool vector_empty(const Vector_t* vec) {
  return vec->size == 0;
}

void* vector_at(const Vector_t* vec, int index) {
  assert(index < vec->size);
  
  return vec->values[index];
}

void vector_free(Vector_t* vec) {
  free(vec->values);
  free(vec);
}
