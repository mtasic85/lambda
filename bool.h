#ifndef L_BOOL_H
#define L_BOOL_H

#include <stdbool.h>
#include "object.h"

typedef struct l_bool_t {
    L_OBJECT_HEAD
    bool v;
} l_bool_t;

struct l_object_t * l_bool_init(struct l_ctx * ctx, struct l_object_t * a);

#endif
