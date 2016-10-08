#ifndef L_FRAME_H
#define L_FRAME_H

struct l_frame_t;

#include "ctx.h"
#include "object.h"

typedef struct l_frame_t {
    struct l_ctx_t * ctx;
    struct l_frame_t * parent_frame;
    struct l_object_t ** regs;
} l_frame_t;

struct l_frame_t * l_frame_new(struct l_ctx_t * ctx, struct l_frame_t * parent_frame);
void l_frame_del(struct l_frame_t * frame);

#endif
