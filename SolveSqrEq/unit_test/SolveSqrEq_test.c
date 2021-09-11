#include <stdio.h>
#include <math.h>

#include "SolveSqrEq_test.h"

TEST_STATUS SolveLinEqSingleTest(double b, double c, double exp_r, SOLVE_STATUS exp_status)
{
    double r = 0;
    SOLVE_STATUS status = SolveLinEq(b, c, &r);

    TEST_STATUS test_res = TestSoftAssert(
        status == exp_status && (is_eq(r, exp_r) || isnan(exp_r)),
        true);

    if (test_res != TEST_OK)
    {
        stdout_set_colour(STD_COL_RED);
        printf("input: b = %lg, c = %lg\n", b, c);
        printf("results: (got / expected)\n");
        printf("r: %lg / %lg\n", r, exp_r);
        printf("SOLVE_STATUS: %d / %d\n", status, exp_status);
        stdout_set_colour(STD_COL_WHITE);
    }

    return test_res;
}

TEST_STATUS SolveLinEq_test()
{
    TEST_STATUS test_result = TEST_OK;

    printf("testing SolveLinEq:\n");

    printf("\tSolveLinEq [inf root case]: ");
    if (SolveLinEqSingleTest(0., 0., NAN, SOLVE_INF_ROOTS) == TEST_FAIL)
        test_result = TEST_FAIL;

    printf("\tSolveLinEq [single root case]: ");
    if (SolveLinEqSingleTest(2., 2., -1, SOLVE_1_ROOT) == TEST_FAIL)
        test_result = TEST_FAIL;

    printf("\tSolveLinEq [no roots case]: ");
    if (SolveLinEqSingleTest(0., 1., NAN, SOLVE_0_ROOTS) == TEST_FAIL)
        test_result = TEST_FAIL;

    printf("SolveLinEq RESULT: ");
    print_test_result(test_result, true);
    printf("\n");
    return test_result;
}

TEST_STATUS SolveSqrEqSingleTest(
    double a, double b, double c,
    double exp_r1, double exp_r2, SOLVE_STATUS exp_status)
{
    double r1 = 0, r2 = 0;
    SOLVE_STATUS status = SolveSqrEq(a, b, c, &r1, &r2);

    TEST_STATUS test_res = TestSoftAssert(
        status == exp_status &&
            (is_eq(r1, exp_r1) || is_eq(r2, exp_r1) || isnan(exp_r1)) &&
            (is_eq(r1, exp_r2) || is_eq(r2, exp_r2) || isnan(exp_r2)),
        true);

    if (test_res != TEST_OK)
    {
        stdout_set_colour(STD_COL_RED);
        printf("input: a = %lg, b = %lg, c = %lg\n", a, b, c);
        printf("results: (got / expected)\n");
        printf("(r1, r2): (%lg, %lg) / (%lg, %lg)\n", r1, r2, exp_r1, exp_r2);
        printf("SOLVE_STATUS: %d / %d\n", status, exp_status);
        stdout_set_colour(STD_COL_WHITE);
    }

    return test_res;
}

TEST_STATUS SolveSqrEq_test()
{
    TEST_STATUS test_result = TEST_OK;
    printf("testing SolveSqrEq:\n");

    printf("\tSolveSqrEq [inf roots case]: ");
    if (SolveSqrEqSingleTest(0., 0., 0., NAN, NAN, SOLVE_INF_ROOTS) != TEST_OK)
        test_result = TEST_FAIL;

    printf("\tSolveSqrEq [1 root (linear) case]: ");
    if (SolveSqrEqSingleTest(0., 1., 1., -1, NAN, SOLVE_1_ROOT) != TEST_OK)
        test_result = TEST_FAIL;

    printf("\tSolveSqrEq [1 root (quadratic) case]: ");
    if (SolveSqrEqSingleTest(1., -4., 4., 2., NAN, SOLVE_1_ROOT) != TEST_OK)
        test_result = TEST_FAIL;

    printf("\tSolveSqrEq [no roots case]: ");
    if (SolveSqrEqSingleTest(1., 0., 1., NAN, NAN, SOLVE_0_ROOTS) != TEST_OK)
        test_result = TEST_FAIL;

    printf("\tSolveSqrEq [2 roots case]: ");
    if (SolveSqrEqSingleTest(1., 4., 3., -1, -3, SOLVE_2_ROOTS) != TEST_OK)
        test_result = TEST_FAIL;

    printf("SolveSqrEq RESULT: ");
    print_test_result(test_result, true);
    printf("\n");

    return test_result;
}