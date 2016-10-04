#ifndef L_SET_H
#define L_SET_H

#include <string.h>
#include <stdlib.h>
#include "object.h"

typedef struct l_set_t {
    L_OBJECT_HEAD
    int64_t len;
    struct l_object_t ** items;
} l_set_t;

#endif
