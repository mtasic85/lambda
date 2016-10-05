#ifndef L_VM_H
#define L_VM_H

#include "ctx.h"
#include "code.h"

typedef struct l_vm_t {
    
} l_vm_t;

struct l_vm_t * l_vm_new(void);
void l_vm_del(struct l_vm_t * vm);
struct l_ctx_t * l_vm_exec(struct l_vm_t * vm, struct l_code_t * code);

#endif
