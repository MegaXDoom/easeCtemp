#include "mArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

mArray *new_mArray() {
  mArray *return_mArray;

  return_mArray = (mArray *)malloc(sizeof(mArray));

  return_mArray->size = 0;

  return_mArray->start = malloc(sizeof(data));

  return return_mArray;
}

int expand_mArray(mArray *arr, unsigned int length) {
  arr->start = realloc(arr->start, sizeof(data) * length);
  arr->size = length;
}

int insert_mArray(mArray *arr, unsigned int index, data *toAdd) {
  expand_mArray(arr, arr->size + 1);

  memmove(&arr->start[index + 1], &arr->start[index],
          (arr->size - index) * sizeof(data));

  arr->start[index] = toAdd;

  return 1;
}

data *get_mArray(mArray *arr, unsigned int toGet) { return arr->start[toGet]; };

int main() {
  mArray *arr = new_mArray();
  char *test = "Hello World";
  insert_mArray(arr, 0, (data *)test);
  printf("%s\n", test);
  printf("%s\n", (char *)get_mArray(arr, 0));
}