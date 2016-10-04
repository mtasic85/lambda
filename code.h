#ifndef L_CODE_H
#define L_CODE_H

#include "object.h"

typedef struct l_code_t {
    L_OBJECT_HEAD
    int64_t len;
    char * items;
} l_code_t;

#endif
