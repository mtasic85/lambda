#include "object.h"

struct l_object_t * l_object_del(struct l_ctx_t * ctx, struct l_object_t * self) {
    return NULL;
}

struct l_object_t * l_object_is(struct l_ctx_t * ctx, struct l_object_t * a, struct l_object_t * b) {
    bool c_res = (a == b);
    struct l_object_t * res = l_bool_new_with_cbool(ctx, c_res);
    return res;
}

struct l_object_t * l_object_eq(struct l_ctx_t * ctx, struct l_object_t * a, struct l_object_t * b) {
    return NULL;
}

struct l_object_t * l_object_ne(struct l_ctx_t * ctx, struct l_object_t * a, struct l_object_t * b) {
    return NULL;
}

struct l_object_t * l_object_lt(struct l_ctx_t * ctx, struct l_object_t * a, struct l_object_t * b) {
    return NULL;
}

struct l_object_t * l_object_le(struct l_ctx_t * ctx, struct l_object_t * a, struct l_object_t * b) {
    return NULL;
}

struct l_object_t * l_object_gt(struct l_ctx_t * ctx, struct l_object_t * a, struct l_object_t * b) {
    return NULL;
}

struct l_object_t * l_object_ge(struct l_ctx_t * ctx, struct l_object_t * a, struct l_object_t * b) {
    return NULL;
}
