#include "SolveSqrEq.h"

#include <assert.h>
#include <math.h>
#include <stddef.h>

#define EPS 1e-8
#define FLOAT_EQ_CHECK(a, b) (abs(b - a) < EPS)

/*! 
 *  \brief solves suare equation a*x^2 + b*x + c = 0
 *  \param a
 *  \param b
 *  \param c
 *  \param r1 pointer to the first root if present
 *  \param r2 pointer to the second root if present
 *  \return number of roots or SS_INFINITE_ROOT_NUM
 */
int SolveSqrEq(double a, double b, double c, double *r1, double *r2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(r1 != r2);
    assert(r1 != NULL);
    assert(r2 != NULL);

    //case of linear equation
    if (FLOAT_EQ_CHECK(a, 0))
    {
        if (FLOAT_EQ_CHECK(b, 0))
        {
            if (FLOAT_EQ_CHECK(c, 0))
            {
                return SS_INFINITE_ROOT_NUM;
            }
            return 0;
        }
        *r1 = -c / b;
        return 1;
    }

    double d = b * b - 4 * a * c;

    if (FLOAT_EQ_CHECK(d, 0))
    {
        *r1 = -b / (2 * a);
        return 1;
    }
    if (d < 0)
    {
        return 0;
    }

    double sqrt_d = sqrt(d);
    *r1 = (-b + sqrt_d) / (2 * a);
    *r2 = (-b - sqrt_d) / (2 * a);

    return 2;
}