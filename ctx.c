#include "ctx.h"

struct l_ctx_t * l_ctx_new(struct l_vm_t * vm, struct l_ctx_t * parent_ctx) {
    struct l_ctx_t * ctx = (struct l_ctx_t *)malloc(sizeof(struct l_ctx_t));
    ctx->vm = vm;
    ctx->parent_ctx = parent_ctx;
    ctx->parent_frame = NULL;
    ctx->last_frame = NULL;
    return ctx;
}

void l_ctx_del(struct l_ctx_t * ctx) {
    // FIXME: do something with frames
    free(ctx);
}

struct l_object_t * l_ctx_exec(struct l_ctx_t * ctx, struct l_object_t * code) {
    return NULL;
}
