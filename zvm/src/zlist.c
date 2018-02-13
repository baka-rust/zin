#include "zlist.h"

z_list z_list_init() {
  z_list l;
  l.capacity = Z_LIST_BASE_CAPACITY;
  l.length = 0;
  l.data = malloc(sizeof(z_object) * Z_LIST_BASE_CAPACITY);
  return l;
}

void z_list_free(z_list *l) {
  free(l->data);
}

void z_list_push(z_list *l, z_object o) {
  if (l->length == l->capacity) {
    printf("up-sizing\n");
    l->capacity = l->capacity * Z_LIST_GROWTH_FACTOR;
    l->data = realloc(l->data, sizeof(z_object) * (size_t)l->capacity);

    if (l->data == NULL) {
      // TODO: error out
      printf("realloc error\n");
    }
  }

  l->data[l->length] = o;
  l->length++;
}

z_object z_list_pop(z_list *l) {
  z_object o = l->data[l->length - 1];
  l->length--;

  if (l->capacity > Z_LIST_BASE_CAPACITY && l->length == l->capacity / Z_LIST_SHRINK_POINT) {
    printf("down-sizing\n");
    l->capacity = l->capacity / Z_LIST_SHRINK_FACTOR;
    l->data = realloc(l->data, sizeof(z_object) * (size_t)l->capacity);

    if (l->data == NULL) {
      // TODO: error out
      printf("realloc error\n");
    }
  }

  return o;
}
