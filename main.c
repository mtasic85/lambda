#include "lambda.h"

int main(int argc, char ** argv) {
    char * module_path = argv[1];
    char * module_name; // = ...;

    l_vm_t * vm = l_vm_new();
    l_compiler_t * compiler = l_compiler_new(vm);
    l_code_t * code = l_compiler_compile(compiler, module_path);
    l_ctx_t * ctx = l_ctx_new(vm, NULL);
    l_object_t * module = l_ctx_exec(ctx, code);
    l_vm_add_module(vm, module, module_path, module_name);
    
    L_UNREF(module);
    L_UNREF(code);
    l_ctx_del(ctx);
    l_compiler_del(compiler);
    l_vm_del(vm);
    return 0;
}
