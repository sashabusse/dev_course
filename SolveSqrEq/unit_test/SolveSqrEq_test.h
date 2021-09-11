#ifndef SOLVE_SQR_EQ_TEST_H_
#define SOLVE_SQR_EQ_TEST_H_

#include "test_defs.h"
#include "SolveSqrEq.h"

/**
 * @brief tests SolveLinEq function (solves b*x + c = 0)
 * 
 * @return TEST_STATUS result of testing
 */
TEST_STATUS SolveLinEq_test();
TEST_STATUS SolveLinEqSingleTest(double b, double c, double exp_r, SOLVE_STATUS exp_status);

/**
 * @brief tests SolveSqrEq function (solves a*x^2 + b*x + c = 0)
 * 
 * @return TEST_STATUS result of testing
 */
TEST_STATUS SolveSqrEq_test();
TEST_STATUS SolveSqrEqSingleTest(
    double a, double b, double c,
    double exp_r1, double exp_r2, SOLVE_STATUS exp_status);

#endif