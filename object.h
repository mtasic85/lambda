#ifndef L_OBJECT_H
#define L_OBJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

enum l_type_t;
struct l_object_t;

#define L_OBJECT_HEAD \
    int64_t rc; \
    enum l_type_t type; \
    int64_t hash;

typedef enum l_type_t {
    L_TYPE_NULL,
    L_TYPE_BOOL,
    L_TYPE_INT,
    L_TYPE_FLOAT,
    L_TYPE_BYTES,
    L_TYPE_STR,
    L_TYPE_LIST,
    L_TYPE_DICT,
    L_TYPE_SET,
    L_TYPE_CODE,
    L_TYPE_FUNCTION,
    L_TYPE_DYNAMIC
} l_type_t;

typedef struct l_object_t {
    L_OBJECT_HEAD
} l_object_t;

typedef enum l_func_args_flag_t {
    L_FUNC_ARGS_NO_ARGS,
    L_FUNC_ARGS_1_ARG,
    L_FUNC_ARGS_2_ARG,
    L_FUNC_ARGS_3_ARG,
    L_FUNC_ARGS_ARGS,
    L_FUNC_ARGS_KWARGS,
    L_FUNC_ARGS_ARGS_KWARGS,
    L_FUNC_ARGS_CBOOL,
    L_FUNC_ARGS_CINT,
    L_FUNC_ARGS_CFLOAT,
    L_FUNC_ARGS_CCHARP,
    L_FUNC_ARGS_CSTRING,
    L_FUNC_ARGS_CVOIDP
} l_func_args_flag_t;

typedef struct l_func_args_2_args_t {
    struct l_object_t * o0;
    struct l_object_t * o1;
} l_func_args_2_args_t;

typedef struct l_func_args_3_args_t {
    struct l_object_t * o0;
    struct l_object_t * o1;
    struct l_object_t * o2;
} l_func_args_3_args_t;

typedef struct l_cstring_t {
    size_t len;
    char * items;
} l_cstring_t;

typedef union l_func_args_args_t {
    struct l_object_t * o;
    struct l_func_args_2_args_t oo;
    struct l_func_args_3_args_t ooo;
    bool b;
    int64_t i;
    double f;
    char * c;
    struct l_cstring_t s;
    void * v;
} l_func_args_args_t;

typedef struct l_func_arg_t {
    struct l_object_t * o;
    bool b;
    int64_t i;
    double f;
    char * c;
    struct l_cstring_t s;
    void * v;
} l_func_arg_t;

typedef struct l_func_args_t {
    enum l_func_args_flag_t flag;
    struct l_func_arg_t args[3];
} l_func_args_t;

#define L_REF(ctx, o) \
    if (o) { \
        o->rc++; \
    }

#define L_UNREF(ctx, o) \
    if (o) { \
        o->rc--; \
        if (o->rc == 0) l_object_del(ctx, (l_func_args_t){L_FUNC_ARGS_1_ARG, {o}}); \
    }

#include "ctx.h"
#include "bool.h"

struct l_object_t * l_object_del(struct l_ctx_t * ctx, struct l_func_args_t args);

struct l_object_t * l_object_is(struct l_ctx_t * ctx, struct l_object_t * a, struct l_object_t * b);
struct l_object_t * l_object_eq(struct l_ctx_t * ctx, struct l_object_t * a, struct l_object_t * b);
struct l_object_t * l_object_ne(struct l_ctx_t * ctx, struct l_object_t * a, struct l_object_t * b);
struct l_object_t * l_object_lt(struct l_ctx_t * ctx, struct l_object_t * a, struct l_object_t * b);
struct l_object_t * l_object_le(struct l_ctx_t * ctx, struct l_object_t * a, struct l_object_t * b);
struct l_object_t * l_object_gt(struct l_ctx_t * ctx, struct l_object_t * a, struct l_object_t * b);
struct l_object_t * l_object_ge(struct l_ctx_t * ctx, struct l_object_t * a, struct l_object_t * b);

#endif
