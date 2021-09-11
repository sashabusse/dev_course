#ifndef SOLVE_SQR_EQ_H_
#define SOLVE_SQR_EQ_H_

#include <stdbool.h>

extern const double EPS;

/**
 * @brief 
 * 
 * @param a first value to compare
 * @param b second value to compare
 * @return true if equal else false
 */
bool is_eq(double a, double b);

typedef enum
{
    SOLVE_0_ROOTS = 0,
    SOLVE_1_ROOT,
    SOLVE_2_ROOTS,
    SOLVE_INF_ROOTS,
    // ERR codes
    SOLVE_ERR_BAD_PTR,
    SOLVE_ERR_INF
} SOLVE_STATUS;

/**
 * @brief solve linear equation b*x + c = 0
 * 
 * @param b 
 * @param c 
 * @param r pointer to the root if present (else NAN will be stored)
 * @return SOLVE_CODE - number of roots or code of error
 */
SOLVE_STATUS SolveLinEq(double b, double c, double *r);

/*! 
 *  @brief solves square equation a*x^2 + b*x + c = 0
 *  @param a
 *  @param b
 *  @param c
 *  @param r1 pointer to the first root if present (else NAN will be saved)
 *  @param r2 pointer to the second root if present (else NAN will be saved)
 *  @return SOLVE_CODE - number of roots or code of error
 */
SOLVE_STATUS SolveSqrEq(double a, double b, double c, double *r1, double *r2);

#endif