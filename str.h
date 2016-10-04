#ifndef L_STR_H
#define L_STR_H

#include <string.h>
#include "object.h"

typedef struct l_str_t {
    L_OBJECT_HEAD
    int64_t len;
    char * items;
} l_str_t;

#endif
