#ifndef L_FLOAT_H
#define L_FLOAT_H

#include <float.h>
#include "object.h"

typedef struct l_float_t {
    L_OBJECT_HEAD
    double v;
} l_float_t;

#endif
