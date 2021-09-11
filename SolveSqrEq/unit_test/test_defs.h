#ifndef TEST_DEFS_H_
#define TEST_DEFS_H_

#include "stdbool.h"

typedef enum
{
    TEST_OK = 0,
    TEST_FAIL
} TEST_STATUS;

typedef enum
{
    STD_COL_WHITE,
    STD_COL_RED,
    STD_COL_YELLOW,
    STD_COL_GREEN
} STDOUT_COLOUR;

/**
 * @brief sets stdout colour
 * 
 * @param col STDOUT_COLOUR colour
 */
void stdout_set_colour(STDOUT_COLOUR col);

/**
 * @brief prints test result with apropriate colour
 * 
 * @param status TEST_STATUS status of test
 * @param new_line if true prints \n
 */
void print_test_result(TEST_STATUS status, bool new_line);

/**
 * @brief asser
 * 
 * @param cond 
 * @return TEST_STATUS 
 */
TEST_STATUS TestSoftAssert(bool cond, bool print);

#endif