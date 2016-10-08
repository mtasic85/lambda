#include "object.h"

struct l_object_t * l_object_del(struct l_ctx_t * ctx, struct l_func_args_t args) {
    struct l_object_t * self;

    switch (args.flag) {
        case L_FUNC_ARGS_1_ARG:
            self = args.args.o;

            switch (self->type) {
                case L_TYPE_NULL:
                    break;
                case L_TYPE_BOOL:
                    break;
                case L_TYPE_INT:
                    break;
                case L_TYPE_FLOAT:
                    break;
                case L_TYPE_BYTES:
                    break;
                case L_TYPE_STR:
                    break;
                case L_TYPE_LIST:
                    break;
                case L_TYPE_DICT:
                    break;
                case L_TYPE_SET:
                    break;
                case L_TYPE_CODE:
                    break;
                case L_TYPE_FUNCTION:
                    break;
                case L_TYPE_DYNAMIC:
                    break;
            }

            break;
        default:
            // FIXME: raise exception
            ;
    }
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
