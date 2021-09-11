#include "test_defs.h"
#include <assert.h>
#include <stdio.h>

void stdout_set_colour(STDOUT_COLOUR col)
{
    switch (col)
    {
    case STD_COL_WHITE:
        printf("\033[0;37m");
        break;
    case STD_COL_RED:
        printf("\033[0;31m");
        break;
    case STD_COL_YELLOW:
        printf("\033[0;33m");
        break;
    case STD_COL_GREEN:
        printf("\033[0;32m");
        break;
    default:
        assert(0);
        break;
    }
}

void print_test_result(TEST_STATUS status, bool new_line)
{
    if (status == TEST_OK)
    {
        stdout_set_colour(STD_COL_GREEN);
        printf("SUCCESS");
        if (new_line)
            printf("\n");
        stdout_set_colour(STD_COL_WHITE);
    }
    else // TEST_FAIL
    {
        stdout_set_colour(STD_COL_RED);
        printf("FAIL");
        if (new_line)
            printf("\n");
        stdout_set_colour(STD_COL_WHITE);
    }
}

TEST_STATUS TestSoftAssert(bool cond, bool print)
{
    TEST_STATUS result;
    if (!cond)
        result = TEST_FAIL;
    else
        result = TEST_OK;

    if (print)
        print_test_result(result, true);

    return result;
}
