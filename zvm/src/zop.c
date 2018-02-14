#include "zop.h"

void z_run(const char *bytecode, size_t length) {
  size_t pc = 0;
  while (pc < length) {
    pc = decode_op(bytecode, pc);
  }
}

size_t decode_op(const char *bc, size_t pc) {
  const char op = bc[pc];
  switch (op) {

    case OP_PUSH_INT:
      pc++;
      int i;
      memcpy(&i, &bc[pc], sizeof(int));
      pc += sizeof(int);
      printf("push int %d\n", i);
      break;

    case OP_PUSH_FLOAT:
      pc++;
      float f;
      memcpy(&f, &bc[pc], sizeof(float));
      pc += sizeof(float);
      printf("push float %f\n", f);
      break;

    default:
      pc++;
      break;
  }
  return pc;
}
