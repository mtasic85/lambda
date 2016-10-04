#ifndef L_BYTES_H
#define L_BYTES_H

#include <string.h>
#include "object.h"

typedef struct l_bytes_t {
    L_OBJECT_HEAD
    int64_t len;
    char * items;
} l_bytes_t;

#endif
