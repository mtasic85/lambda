#include "compiler.h"

struct l_compiler_t * l_compiler_new(struct l_vm_t * vm) {
    struct l_compiler_t * compiler = (struct l_compiler_t *)malloc(sizeof(struct l_compiler_t));
    compiler->vm = vm;
    return compiler;
}

void l_compiler_del(struct l_compiler_t * compiler) {
    free(compiler);
}

struct l_object_t * l_compiler_compile(struct l_compiler_t * compiler, char * path) {
    return NULL;
}
