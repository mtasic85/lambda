/*
make clean; clear; make all; ls -l lambda; ./lambda
*/
#include "lambda.h"

int main(int argc, char ** argv) {
    char * module_path = argv[1];

    l_vm_t * vm = l_vm_new();
    l_ctx_t * ctx = l_ctx_new(vm, NULL);
    l_compiler_t * compiler = l_compiler_new(vm);

    l_object_t * code = l_compiler_compile(compiler, module_path);
    l_object_t * module = l_ctx_exec(ctx, code);
    l_vm_add_module(vm, module);
    
    L_UNREF(ctx, module);
    L_UNREF(ctx, code);
    l_compiler_del(compiler);
    l_ctx_del(ctx);
    l_vm_del(vm);
    return 0;
}
