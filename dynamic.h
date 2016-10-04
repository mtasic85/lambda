#ifndef L_DYNAMIC_H
#define L_DYNAMIC_H

#include "object.h"
#include "dict.h"

typedef struct l_dynamic_t {
    L_OBJECT_HEAD
    struct l_dict_t * dict;
} l_dynamic_t;

#endif
