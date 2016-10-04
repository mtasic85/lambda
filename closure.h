#ifndef L_CLOSURE_H
#define L_CLOSURE_H

#include "object.h"

struct l_closure_t;

typedef struct l_closure_t {
    L_OBJECT_HEAD
    struct l_closure_t * prev;
    struct l_dict_t * vars;
} l_closure_t;

#endif
