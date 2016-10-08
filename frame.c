#include "frame.h"

struct l_frame_t * l_frame_new(struct l_ctx_t * ctx, struct l_frame_t * parent_frame) {
    struct l_frame_t * frame = (struct l_frame_t *)malloc(sizeof(struct l_frame_t));
    frame->ctx = ctx;
    frame->parent_frame = parent_frame;
    frame->regs = NULL; // FIXME
    return frame;
}

void l_frame_del(struct l_frame_t * frame) {
    free(frame);
}
