#ifndef L_LIST_H
#define L_LIST_H

#include <string.h>
#include <stdlib.h>
#include "object.h"

typedef struct _l_list_t {
    L_OBJECT_HEAD
    uint64_t len;
    uint64_t cap;
    struct l_object_t ** items;
} _l_list_t;

typedef struct l_list_t {
    L_OBJECT_HEAD
    struct _l_list_t * list;
    uint64_t start;
    uint64_t end;
} l_list_t;

struct l_object_t * l_object_new(struct l_ctx_t * ctx, struct l_func_args_t args);
struct l_object_t * l_object_del(struct l_ctx_t * ctx, struct l_func_args_t args);
struct l_object_t * l_object_getitem(struct l_ctx_t * ctx, struct l_func_args_t args);
struct l_object_t * l_object_setitem(struct l_ctx_t * ctx, struct l_func_args_t args);
struct l_object_t * l_object_delitem(struct l_ctx_t * ctx, struct l_func_args_t args);
struct l_object_t * l_object_append(struct l_ctx_t * ctx, struct l_func_args_t args);
struct l_object_t * l_object_prepend(struct l_ctx_t * ctx, struct l_func_args_t args);
struct l_object_t * l_object_remove(struct l_ctx_t * ctx, struct l_func_args_t args);

#endif
