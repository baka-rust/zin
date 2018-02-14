#ifndef Z_OP_H
#define Z_OP_H

#include <stdio.h>
#include <string.h>

enum z_op {
  OP_NOP = 0x20,

  OP_PUSH_ID,
  OP_PUSH_INT,
  OP_PUSH_BOOL,
  OP_PUSH_FLOAT,

  OP_POP,
  OP_POP_ID_INT,
  OP_POP_ID_BOOL,
  OP_POP_ID_FLOAT,

  OP_STORE_ID_INT,
  OP_STORE_ID_BOOL,
  OP_STORE_ID_FLOAT,

  OP_CALL,
  OP_CALL_ID
};

void z_run(const char *bytecode, size_t length);

size_t decode_op(const char *bc, size_t pc);

#endif /* Z_OP_H */
