//
//  main.c
//  rg-lib
//
//  Created by Rabin Gaire on 28/04/2024.
//

#include "lib/vector.h"
#include "lib/slice.h"

void example_vector_int(void) {
  Vector_t* values = vector_new(VECTOR_INT);
  int numbers[] = {12, 15, 16, 17, 18};
  
  for (int idx = 0; idx < 5; ++idx) vector_append(values, &numbers[idx]);
  
  int* value = vector_at(values, 4);
  printf("%d\n", *value);
  
  vector_print(values);
  printf("%s\n", vector_empty(values) ? "true" : "false");
  
  Slice_t* vec_slice = slice_new(VECTOR, values, 1, 3);
  slice_print(vec_slice);
  
  vector_clear(values);
  
  vector_print(values);
  printf("%s\n", vector_empty(values) ? "true" : "false");
  
  vector_free(values);
}

void example_vector_float(void) {
  Vector_t* values = vector_new(VECTOR_FLOAT);
  float numbers[] = {12.0f, 15.0f, 16.0f, 17.0f, 18.0f};
  
  for (int idx = 0; idx < 5; ++idx) vector_append(values, &numbers[idx]);
  
  float* value = vector_at(values, 4);
  printf("%f\n", *value);
  
  vector_print(values);
  printf("%s\n", vector_empty(values) ? "true" : "false");
  
  vector_clear(values);
  
  vector_print(values);
  printf("%s\n", vector_empty(values) ? "true" : "false");
  
  vector_free(values);
}

int main(void) {
  example_vector_int();
//  example_vector_float();
  return 0;
}
