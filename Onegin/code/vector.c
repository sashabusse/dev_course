#include <memory.h>
#include <assert.h>

#include "vector.h"

VEC_RES vector_init(vector_str *p_vec, size_t len_reserved)
{
    assert(len_reserved >= 1);

    p_vec->_strs = (char **)calloc(len_reserved, sizeof(char *));
    if (p_vec->_strs == NULL)
    {
        return VEC_MEM_ERROR;
    }
    p_vec->_mem_len = len_reserved;
    p_vec->len = 0;

    return VEC_OK;
}

VEC_RES vector_free(vector_str *p_vec)
{
    free(p_vec->_strs);
    return VEC_OK;
}

VEC_RES vector_push(vector_str *p_vec, char *str)
{
    if (p_vec->len == p_vec->_mem_len)
    {
        VEC_RES realloc_res = _vector_realloc(p_vec, 2 * (p_vec->_mem_len));
        if (realloc_res != VEC_OK)
            return realloc_res;
    }

    p_vec->_strs[p_vec->len] = str;
    p_vec->len++;
    return VEC_OK;
}

VEC_RES vector_get(vector_str *p_vec, size_t ind, char **p_str)
{
    if (ind >= p_vec->len)
        return VEC_IND_ERROR;

    *p_str = p_vec->_strs[ind];
    return VEC_OK;
}

VEC_RES vector_set(vector_str *p_vec, size_t ind, char *new_str, char **p_old_str)
{
    if (ind >= p_vec->len)
        return VEC_IND_ERROR;

    VEC_RES get_res = vector_get(p_vec, ind, p_old_str);
    if (get_res != VEC_OK)
    {
        return get_res;
    }

    p_vec->_strs[ind] = new_str;

    return VEC_OK;
}

VEC_RES _vector_realloc(vector_str *p_vec, size_t new_sz)
{
    p_vec->_strs = (char **)realloc(p_vec->_strs, new_sz * sizeof(char *));
    if (p_vec->_strs == NULL)
    {
        return VEC_MEM_ERROR;
    }
    p_vec->_mem_len = new_sz;
    return VEC_OK;
}
