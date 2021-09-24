#pragma once
#include <stdio.h>

/**
 * @brief return codes of utility functions
 * 
 */
typedef enum
{
    OP_OK = 0,
    OP_ERROR
} OP_RES;

/**
 * @brief Returns size of file in bytes
 * 
 * @param file 
 * @param p_sz 
 * @return OP_RES 
 */
OP_RES get_file_sz(FILE *file, size_t *p_sz);

/**
 * @brief count lines in c style string
 * 
 * @param text 
 * @return size_t 
 */
size_t count_lines(char *text);

/**
 * @brief creates array of char* that holds lines from text
 *        user should free all the memory after use
 * 
 * @param text          text to break in strings
 * @param lines_cnt     count of lines in text
 * @param lines         array of lines (will hold address of allocated memory)
 * @return OP_RES
 */
OP_RES text_to_lines(const char *text, size_t lines_cnt, char **lines);

/**
 * @brief return array of char* holding lines of text file
 *          user should free memory after use
 * 
 * @param file 
 * @param lines 
 * @param p_lines_cnt 
 * @return OP_RES 
 */
OP_RES read_file_by_lines(FILE *file, char ***lines, size_t *p_lines_cnt);