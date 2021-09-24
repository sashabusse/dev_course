#include <string.h>
#include <assert.h>
#include <stdlib.h>

#include "Utility.h"

OP_RES get_file_sz(FILE *file, size_t *p_sz)
{
    assert(file != NULL);
    assert(p_sz != NULL);

    long st_pos = ftell(file);

    if (fseek(file, 0, SEEK_END) != 0)
        return OP_ERROR;

    *p_sz = ftell(file);

    if (fseek(file, st_pos, SEEK_SET) != 0)
        return OP_ERROR;

    return OP_OK;
}

size_t count_lines(char *text)
{
    assert(text != NULL);

    size_t line_cnt = 1;
    size_t ind;
    for (ind = 0; text[ind] != '\0'; ind++)
    {
        if (text[ind] == '\n')
            line_cnt += 1;
    }
    return line_cnt;
}

OP_RES text_to_lines(const char *text, size_t lines_cnt, char **lines)
{
    for (size_t i = 0; i < lines_cnt - 1; i++)
    {
        char *line_end = strchr(text, '\n') + 1;
        
        size_t line_len = line_end - text;
        lines[i] = (char *)calloc(line_len + 1, sizeof(char));
        if(lines[i] == NULL)
        {
            // free all the allocated memory before return err
            for(size_t j = 0; j < i; j++)
            {
                free(lines[j]);
            }
            return OP_ERROR;
        }
        
        // copy everything excluding \n
        memcpy(lines[i], text, line_len);
        lines[i][line_len] = '\0';

        text = line_end;
    }
    lines[lines_cnt - 1] = (char *)calloc(strlen(text) + 1, sizeof(char));
    strcpy(lines[lines_cnt - 1], text);
    return OP_OK;
}

OP_RES read_file_by_lines(FILE *file, char ***lines, size_t *p_lines_cnt)
{
    // read full file text
    size_t file_sz = 0;
    if (get_file_sz(file, &file_sz) != OP_OK)
        return OP_ERROR;

    char *file_text = (char *)malloc(file_sz);
    if (file_text == NULL)
        return OP_ERROR;

    if (fread(file_text, sizeof(char), file_sz, file) != file_sz)
        return OP_ERROR;

    // allocate memory to store pointers
    *p_lines_cnt = count_lines(file_text);
    *lines = (char **)calloc(*p_lines_cnt, sizeof(char *));
    if(*lines == NULL)
    {
        free(file_text);
        return OP_ERROR;
    }

    // get lines from text
    if(text_to_lines(file_text, *p_lines_cnt, *lines) != OP_OK)
    {
        free(file_text);
        free(*lines);
        return OP_ERROR;
    }

    free(file_text);
    return OP_OK;
}