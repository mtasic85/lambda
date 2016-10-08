#ifndef L_VM_H
#define L_VM_H

struct l_vm_t;

#include "ctx.h"
#include "code.h"
#include "object.h"

typedef struct l_vm_t {
    void * _void;
} l_vm_t;

struct l_vm_t * l_vm_new(void);
void l_vm_del(struct l_vm_t * vm);
void l_vm_add_module(struct l_vm_t * vm, struct l_object_t * module);

#endif
