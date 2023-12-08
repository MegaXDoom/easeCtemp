#include "mArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

mArray *new_mArray()
{
  mArray *return_mArray;

  return_mArray = (mArray *)malloc(sizeof(mArray));

  return_mArray->size = 0;

  return_mArray->start = malloc(sizeof(data));

  return return_mArray;
}

int resize_mArray(mArray *array, unsigned int length)
{
  array->start = realloc(array->start, sizeof(data) * length);
  array->size = length;
}

int insert_mArray(mArray *array, unsigned int index, data *toAdd)
{
  resize_mArray(array, array->size + 1);

  memmove(&array->start[index + 1], &array->start[index], (array->size - index) * sizeof(data));

  array->start[index] = toAdd;

  return 1;
}

int remove_mArray(mArray *array, unsigned int index)
{

  memmove(&array->start[index], &array->start[index + 1], (array->size - (index)) * sizeof(data));

  resize_mArray(array, array->size - 1);

  array->size = array->size - 1;

  return 1;
}

int set_mArray(mArray *array, unsigned int index, data *toAdd)
{
  array->start[index] = toAdd;

  return 1;
};

data *get_mArray(mArray *array, unsigned int toGet) { return array->start[toGet]; };

int free_mArray(mArray *array)
{

  free(array->start);
  free(array);

  return 1;
}

int main()
{
  mArray *array = new_mArray();
  char *test = "Hello World";
  insert_mArray(array, 0, (data *)test);
  printf("%s\n", test);
  printf("%s\n", (char *)get_mArray(array, 0));

  char *test2 = "Hello World2";
  printf("%s\n", test2);
  set_mArray(array, 0, (data *)test2);
  printf("%s\n", (char *)get_mArray(array, 0));

  free_mArray(array);
}