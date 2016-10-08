#ifndef L_COMPILER_H
#define L_COMPILER_H

struct l_compiler_t;

#include "vm.h"
#include "code.h"

typedef struct l_compiler_t {
    struct l_vm_t * vm;
} l_compiler_t;

struct l_compiler_t * l_compiler_new(struct l_vm_t * vm);
void l_compiler_del(struct l_compiler_t * compiler);
struct l_object_t * l_compiler_compile(struct l_compiler_t * compiler, char * path);

#endif
