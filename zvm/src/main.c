#include <stdio.h>
#include <stdbool.h>

#include "zlist.h"
#include "zobject.h"

int main(int argc, char *argv[]) {
  z_object obj_a;
  obj_a.type = Z_BOOL;
  obj_a.data.b = true;

  z_list l = z_list_init();
  for (int j = 0; j < 128; j++) {
    z_list_push(&l, obj_a);
  }

  printf("\n");
  for (int j = 0; j < 128; j++) {
    z_object o = z_list_pop(&l);
  }

  return 0;
}
