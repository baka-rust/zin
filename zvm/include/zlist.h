#ifndef Z_LIST_H
#define Z_LIST_H

#include <stdlib.h>
#include <stdio.h>

#include "zobject.h"

#define Z_LIST_BASE_CAPACITY  16
#define Z_LIST_GROWTH_FACTOR  2
#define Z_LIST_SHRINK_FACTOR  2
#define Z_LIST_SHRINK_POINT   3

typedef struct {
  unsigned int capacity;
  unsigned int length;
  z_object *data;
} z_list;

z_list z_list_init();
void z_list_free(z_list *l);
void z_list_push(z_list *l, z_object o);
z_object z_list_pop(z_list *l);

#endif /* Z_LIST_H */
