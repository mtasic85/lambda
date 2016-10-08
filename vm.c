#include "vm.h"

struct l_vm_t * l_vm_new(void) {
    struct l_vm_t * vm = (struct l_vm_t *)malloc(sizeof(struct l_vm_t));
    return vm;
}

void l_vm_del(struct l_vm_t * vm) {
    free(vm);
}

void l_vm_add_module(struct l_vm_t * vm, struct l_object_t * module) {
    
}