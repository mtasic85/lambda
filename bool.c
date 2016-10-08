#include "bool.h"

struct l_object_t * l_bool_new_with_cbool(struct l_ctx_t * ctx, bool value) {
    return NULL;
}

struct l_object_t * l_bool_new_with_object(struct l_ctx_t * ctx, struct l_object_t * a) {
    return NULL;
}

struct l_object_t * l_bool_new(struct l_ctx_t * ctx, struct l_func_args_t args) {
    struct l_bool_t * self = (struct l_bool_t *)malloc(sizeof(struct l_bool_t));
    bool v;

    if (args.n_args == 1) {
        switch (args.args[0].type) {
            case L_FUNC_ARG_OBJECT:
                v = ((struct l_bool_t *)(args.args[0].value.o))->v;
                break;
            case L_FUNC_ARG_CBOOL:
                v = args.args[0].value.b;
                break;
            default:
                // FIXME: raise exception
                ;
        }
    } else if (args.n_args > 1) {
        // FIXME: raise exception
    }

    self->rc = 1;
    self->type = L_TYPE_BOOL;
    self->v = v;
    struct l_object_t * res = (struct l_object_t *)self;
    return res;
}

struct l_object_t * l_bool_del(struct l_ctx_t * ctx, struct l_func_args_t args) {
    struct l_bool_t * self;

    if (args.n_args != 1) {
        // FIXME: raise exception
    }

    self = (struct l_bool_t *)(args.args[0].value.o);
    free(self);

    struct l_object_t * res = NULL;
    return res;
}
