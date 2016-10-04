#ifndef L_OBJECT_H
#define L_OBJECT_H

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
    L_TYPE_CLOSURE,
    L_TYPE_DYNAMIC
} l_type_t;

#define L_OBJECT_HEAD \
    int64_t rc; \
    enum l_type_t type; \
    int64_t hash;

typedef struct l_object_t {
    L_OBJECT_HEAD
} l_object_t;

struct l_object_t * l_is(struct l_object_t * a, struct l_object_t * b);
struct l_object_t * l_eq(struct l_object_t * a, struct l_object_t * b);
struct l_object_t * l_ne(struct l_object_t * a, struct l_object_t * b);
struct l_object_t * l_lt(struct l_object_t * a, struct l_object_t * b);
struct l_object_t * l_le(struct l_object_t * a, struct l_object_t * b);
struct l_object_t * l_gt(struct l_object_t * a, struct l_object_t * b);
struct l_object_t * l_ge(struct l_object_t * a, struct l_object_t * b);

#endif
