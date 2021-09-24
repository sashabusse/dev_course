#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Utility.h"

int m_strcmp(const void *f, const void *s);

int m_strcmp(const void *f, const void *s)
{
    return strcmp(*((char *const *)f), *((char *const *)s));
}

int main()
{
    const char *fname_in = "D:/dev/dev_course/Onegin/data/onegin_in.txt";
    const char *fname_out = "D:/dev/dev_course/Onegin/data/onegin_out.txt";
    FILE *file_in = fopen(fname_in, "r");

    char **lines = NULL;
    size_t lines_cnt = 0;
    read_file_by_lines(file_in, &lines, &lines_cnt);

    fclose(file_in);

    //sort lexicographically
    qsort((void *)lines, lines_cnt, sizeof(char *), m_strcmp);

    // write output
    FILE *file_out = fopen(fname_out, "w");
    for (size_t i = 0; i < lines_cnt; i++)
    {
        fputs(lines[i], file_out);
    }
    fclose(file_out);

    // free everything
    for (size_t i = 0; i < lines_cnt; i++)
    {
        free(lines[i]);
    }
    free(&lines);

    return 0;
}