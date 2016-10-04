#ifndef L_FUNCTION_H
#define L_FUNCTION_H

#include "object.h"
#include "list.h"
#include "dict.h"
#include "code.h"
#include "closure.h"

typedef struct l_function_t {
    L_OBJECT_HEAD
    struct l_code_t * code;
    struct l_list_t * args_names;
    struct l_dict_t * kwargs_defaults;
    struct l_closure_t * closure;
} l_function_t;

#endif
