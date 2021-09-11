#include "SolveSqrEq.h"

#include <assert.h>
#include <stdbool.h>
#include <math.h>
#include <stddef.h>

const double EPS = 1e-8;

bool is_eq(double a, double b)
{
    return fabs(b - a) < EPS;
}

SOLVE_STATUS SolveLinEq(double b, double c, double *r)
{
    if (!isfinite(b) || !isfinite(c))
        return SOLVE_ERR_INF;

    if (r == NULL)
        return SOLVE_ERR_BAD_PTR;

    *r = NAN;

    if (is_eq(b, 0))
    {
        if (is_eq(c, 0))
        {
            return SOLVE_INF_ROOTS;
        }
        return SOLVE_0_ROOTS;
    }
    *r = -c / b;
    return SOLVE_1_ROOT;
}

SOLVE_STATUS SolveSqrEq(double a, double b, double c, double *r1, double *r2)
{
    if (!isfinite(a) ||
        !isfinite(b) ||
        !isfinite(c))
        return SOLVE_ERR_INF;

    if (r1 == NULL ||
        r2 == NULL ||
        r1 == r2)
        return SOLVE_ERR_BAD_PTR;

    *r1 = NAN;
    *r2 = NAN;

    //case of linear equation
    if (is_eq(a, 0))
    {
        return SolveLinEq(b, c, r1);
    }

    double d = b * b - 4 * a * c;

    if (is_eq(d, 0))
    {
        *r1 = -b / (2 * a);
        return SOLVE_1_ROOT;
    }
    if (d < 0)
    {
        return SOLVE_0_ROOTS;
    }

    double sqrt_d = sqrt(d);
    *r1 = (-b + sqrt_d) / (2 * a);
    *r2 = (-b - sqrt_d) / (2 * a);

    return SOLVE_2_ROOTS;
}