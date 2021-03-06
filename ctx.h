#ifndef L_CTX_H
#define L_CTX_H

#include <threads.h>

struct l_ctx_t;

#include "vm.h"
#include "code.h"
#include "frame.h"


typedef struct l_ctx_t {
    struct l_vm_t * vm;
    struct l_ctx_t * parent_ctx;
    struct l_frame_t * parent_frame;
    struct l_frame_t * last_frame;
} l_ctx_t;

struct l_ctx_t * l_ctx_new(struct l_vm_t * vm, struct l_ctx_t * parent_ctx);
void l_ctx_del(struct l_ctx_t * ctx);
struct l_object_t * l_ctx_exec(struct l_ctx_t * ctx, struct l_object_t * code);

#endif
