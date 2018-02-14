#include "zop.h"

void z_run(const char *bytecode, size_t length) {
  size_t pc = 0;
  while (pc < length) {
    decode_op(bytecode, &pc);
  }
}

void decode_op(const char *bc, size_t *pc) {
  const char *id;
  int i;
  float f;

  const char op = bc[*pc];
  (*pc)++;

  switch (op) {
    case OP_PUSH_ID:
      id = get_id(bc, pc);
      printf("push id %s\n", id);
      break;

    case OP_PUSH_INT:
      i = get_int(bc, pc);
      printf("push int %d\n", i);
      break;

    case OP_PUSH_FLOAT:
      f = get_float(bc, pc);
      printf("push float %f\n", f);
      break;

    default:
      break;
  }
}

const char *get_id(const char *bc, size_t *pc) {
  const char *id = &bc[*pc];
  *pc += strlen(id) + 1; // for null term
  return id;
}

int get_int(const char *bc, size_t *pc) {
  int i;
  memcpy(&i, &bc[*pc], sizeof(int));
  *pc += sizeof(int);
  return i;
}

float get_float(const char *bc, size_t *pc) {
  float f;
  memcpy(&f, &bc[*pc], sizeof(float));
  *pc += sizeof(float);
  return f;
}
