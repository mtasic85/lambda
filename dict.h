#ifndef L_DICT_H
#define L_DICT_H

#include <string.h>
#include <stdlib.h>
#include "object.h"

typedef struct l_dict_entry_t {
    struct l_object_t * key;
    struct l_object_t * value;
} l_dict_entry_t;

typedef struct l_dict_t {
    L_OBJECT_HEAD
    int64_t len;
    struct l_dict_entry_t * entries;
} l_dict_t;

#endif
