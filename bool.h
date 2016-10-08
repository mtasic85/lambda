#ifndef L_BOOL_H
#define L_BOOL_H

#include <stdbool.h>

struct l_bool_t;

#include "ctx.h"
#include "object.h"

typedef struct l_bool_t {
    L_OBJECT_HEAD
    bool v;
} l_bool_t;

struct l_object_t * l_bool_new_with_cbool(struct l_ctx_t * ctx, bool value);
struct l_object_t * l_bool_new_with_object(struct l_ctx_t * ctx, struct l_object_t * a);

#endif
