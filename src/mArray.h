#ifndef easeC_mArray

#define easeC_mArry

typedef void *data;

typedef struct _mArray
{
  data *start;
  unsigned int size;
} mArray;

mArray *new_mArray();
int resize_mArray(mArray *array, unsigned int length);
int insert_mArray(mArray *array, unsigned int index, data *toAdd);
int remove_mArray(mArray *array, unsigned int index);
int set_mArray(mArray *array, unsigned int index, data *toAdd);
data *get_mArray(mArray *array, unsigned int toGet);
int free_mArray(mArray *array);

#endif