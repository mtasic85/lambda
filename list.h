#ifndef L_LIST_H
#define L_LIST_H

#include <string.h>
#include <stdlib.h>
#include "object.h"

typedef struct l_list_t {
    L_OBJECT_HEAD
    int64_t len;
    struct l_object_t ** items;
} l_list_t;

#endif
