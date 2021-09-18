#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "StrFunc.h"

int m_puts(const char *str)
{
    assert(str != NULL);

    int wrote = 0;
    for (; str[wrote] != '\0'; wrote++)
    {
        if (fputc(str[wrote], stdout) == EOF)
            return EOF;
    }

    // additional new line
    if (fputc('\n', stdout) == EOF)
    {
        return EOF;
    }

    return wrote;
}

const char *m_strchr(const char *str, int ch)
{
    assert(str != NULL);

    while (*str != ch)
    {
        if (*str == '\0')
            return NULL;
        str++;
    }
    return str;
}

size_t m_strlen(const char *str)
{
    assert(str != NULL);

    size_t len = 0;
    while (str[len] != '\0')
        len++;

    return len;
}

char *m_strcpy(char *dest, const char *src)
{
    assert(dest != NULL);
    assert(src != NULL);
    assert(src != dest);

    size_t ind = 0;
    do
    {
        dest[ind] = src[ind];
        ind++;
    } while (src[ind] != '\0');

    return dest;
}

char *m_strncpy(char *dest, const char *src, size_t count)
{
    assert(dest != NULL);
    assert(src != NULL);

    size_t ind = 0;
    for (; ind < count && src[ind] != '\0'; ind++)
    {
        dest[ind] = src[ind];
    }
    for (; ind < count; ind++)
    {
        dest[ind] = '\0';
    }
    return dest;
}

char *m_strcat(char *dest, const char *src)
{
    assert(dest != NULL);
    assert(src != NULL);
    assert(src != dest);

    size_t dest_len = m_strlen(dest);

    m_strcpy(dest + dest_len, src);

    return dest;
}

char *m_strncat(char *dest, const char *src, size_t count)
{
    assert(dest != NULL);
    assert(src != NULL);
    assert(src != dest);

    size_t dest_len = m_strlen(dest);

    m_strncpy(dest + dest_len, src, count);

    return dest;
}

char *m_strdup(const char *str1)
{
    assert(str1 != NULL);

    size_t len = m_strlen(str1);
    char *res = (char *)malloc(len + 1);
    if (res == NULL)
        return NULL;

    m_strcpy(res, str1);

    return res;
}

char *m_fgets(char *str, int count, FILE *stream)
{
    assert(str != NULL);
    assert(stream != NULL);

    int ind = 0;
    for (; ind < count - 1; ind++)
    {
        int n_ch = fgetc(stream);

        // EOF or error occured
        if (n_ch == EOF)
        {
            // return NULL in case of error
            if (ferror(stream) != 0)
                return NULL;

            break;
        }

        str[ind] = (char)n_ch;

        // end reading on endl
        if (n_ch == '\n')
            break;
    }

    str[ind] = '\0';

    return str;
}

char *m_getline_realloc(char **lineptr, size_t *n, size_t new_sz)
{
    assert(lineptr != NULL);
    assert(n != NULL);

    if (*lineptr == NULL)
    {
        *lineptr = (char *)malloc(new_sz);
    }
    else
    {
        *lineptr = (char *)realloc(*lineptr, new_sz);
    }

    *n = new_sz;

    return *lineptr;
}

/**
 * @brief value used to allocate *lineptr in m_getline if *lineptr was NULL
 * 
 */
const int getline_min_buf_size = 4;

ssize_t m_getline(char **lineptr, size_t *n, FILE *stream)
{
    assert(lineptr != NULL);
    assert(n != NULL);
    assert(stream != NULL);

    if (*lineptr == NULL)
    {
        if (m_getline_realloc(lineptr, n, getline_min_buf_size) == NULL)
        {
            //bad situation because standard requires to free *lineptr even if -1 returned
            return -1;
        }
    }

    ssize_t ch_read = 0;
    int n_ch = 0;

    while (true)
    {
        //allocate more space if needed
        if ((ssize_t)*n == ch_read)
        {
            //twice the space
            if (m_getline_realloc(lineptr, n, (*n) * 2) == NULL)
            {
                return -1;
            }
        }

        n_ch = getc(stream);
        if (n_ch == EOF)
        {
            if (ferror(stream) != 0)
                return -1;
            break;
        }

        (*lineptr)[ch_read] = (char)n_ch;
        ch_read++;

        if (n_ch == '\n')
            break;
    }

    // allocate more space if needed
    if ((ssize_t)*n == ch_read)
    {
        // add 1 more byte for null terminator
        if (m_getline_realloc(lineptr, n, (*n) + 1) == NULL)
        {
            return -1;
        }
    }
    (*lineptr)[ch_read] = '\0';

    return ch_read;
}