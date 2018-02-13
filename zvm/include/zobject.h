#ifndef Z_OBJECT_H
#define Z_OBJECT_H

#include <stdbool.h>

enum z_type {
  Z_INT,
  Z_BOOL,
  Z_FLOAT,
  Z_FN,
  Z_LIST
};

typedef struct {
  union {
    int i;
    bool b;
    float f;

    struct {
      unsigned int ins_p;
    } fn;
  } data;

  enum z_type type;
} z_object;

#endif /* Z_OBJECT_H */
