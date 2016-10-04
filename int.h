#ifndef L_INT_H
#define L_INT_H

#include <stdint.h>
#include "object.h"

typedef struct l_int_t {
    L_OBJECT_HEAD
    int64_t v;
} l_int_t;

#endif
