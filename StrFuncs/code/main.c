#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "StrFunc.h"

int main()
{
    // test  << M_PUTS >> ------------------------------------------------------------
    m_puts("test of m_puts should new line after this.");

    // test  << M_STR_CHR >> ---------------------------------------------------------
    const char *strchr_test_str = "find o here";
    const char *p_o = m_strchr(strchr_test_str, 'o');
    assert(p_o == strchr_test_str + 5);

    // test  << M_STRLEN >> -----------------------------------------------------------
    size_t strlen_res = m_strlen("abc");
    assert(strlen_res == 3);

    // test  << M_STRCPY >> ------------------------------------------------------------
    printf("\n");
    const char *cpy_src = "cpy_src";
    char cpy_dest[10] = {};
    char *cpy_res = m_strcpy(cpy_dest, cpy_src);
    assert(cpy_res == cpy_dest);
    assert(strcmp(cpy_src, cpy_dest) == 0);
    printf("test of strcpy:\n");
    printf("src: %s\n", cpy_src);
    printf("dest: %s\n", cpy_dest);

    // test  << M_STRNCPY >> ------------------------------------------------------------
    printf("\n");
    const char *cpyn_src = "cpyn_src";
    char cpyn_dest[5] = {};
    m_strncpy(cpyn_dest, cpyn_src, 4);
    printf("testing cpyn:\n");
    puts(cpyn_dest);

    // test  << M_STRCAT >> ------------------------------------------------------------
    printf("\n");
    char cat1[20] = "cat1";
    const char *cat2 = "cat2";
    m_strcat(cat1, cat2);
    puts("testing strcat");
    puts(cat1);

    // test  << M_STRCAT >> ------------------------------------------------------------
    printf("\n");
    char catn1[20] = "cat";
    m_strncat(catn1, cat2, 2);
    puts("testing strncat:");
    puts(catn1);

    // test  << M_STRDUP >> ------------------------------------------------------------
    printf("\n");
    char *dup_result = m_strdup("dup it!");
    puts("dup test:");
    puts(dup_result);

    free(dup_result);

    // test  << M_FGETS >> ------------------------------------------------------------
    printf("testing fgets input 4 symbols:\n");
    char fgets_result[5];
    m_fgets(fgets_result, 5, stdin);
    puts(fgets_result);

    // test  << M_GETLINE >> ------------------------------------------------------------
    FILE *file = fopen("data.txt", "r");

    char *line = NULL;
    size_t line_len = 0;
    m_getline(&line, &line_len, file);
    printf(line);
    free(line);

    fclose(file);

    return 0;
}