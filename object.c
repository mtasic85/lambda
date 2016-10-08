#include "object.h"

struct l_object_t * l_object_del(struct l_ctx_t * ctx, struct l_func_args_t args) {
    struct l_object_t * self;
    struct l_object_t * res;

    if (args.n_args != 1) {
        // FIXME: raise exception
    }

    self = (struct l_object_t *)(args.args[0].value.o);

    switch (self->type) {
        case L_TYPE_NULL:
            // res = l_null_del(ctx, args);
            break;
        case L_TYPE_BOOL:
            res = l_bool_del(ctx, args);
            break;
        case L_TYPE_INT:
            // res = l_int_del(ctx, args);
            break;
        case L_TYPE_FLOAT:
            // res = l_float_del(ctx, args);
            break;
        case L_TYPE_BYTES:
            // res = l_bytes_del(ctx, args);
            break;
        case L_TYPE_STR:
            // res = l_str_del(ctx, args);
            break;
        case L_TYPE_LIST:
            // res = l_list_del(ctx, args);
            break;
        case L_TYPE_DICT:
            // res = l_dict_del(ctx, args);
            break;
        case L_TYPE_SET:
            // res = l_set_del(ctx, args);
            break;
        case L_TYPE_CODE:
            // res = l_code_del(ctx, args);
            break;
        case L_TYPE_FUNCTION:
            // res = l_function_del(ctx, args);
            break;
        case L_TYPE_DYNAMIC:
            // res = l_dynamic_del(ctx, args);
            break;
    }

    return res;
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
