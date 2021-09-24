#pragma once

#include <stdlib.h>

typedef struct
{
    char **_strs;
    size_t _mem_len;
    size_t len;
} vector_str;

typedef enum
{
    VEC_OK = 0,
    VEC_MEM_ERROR,
    VEC_IND_ERROR,
    VEC_ERROR
} VEC_RES;

VEC_RES vector_init(vector_str *p_vec, size_t len_reserved);
VEC_RES vector_free(vector_str *p_vec);
VEC_RES vector_push(vector_str *p_vec, char *str);
VEC_RES vector_get(vector_str *p_vec, size_t ind, char **p_str);
VEC_RES vector_set(vector_str *p_vec, size_t ind, char *new_str, char **p_old_str);

VEC_RES _vector_realloc(vector_str *p_vec, size_t new_sz);