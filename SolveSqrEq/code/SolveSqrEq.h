#ifndef SOLVE_SQR_EQ_H_
#define SOLVE_SQR_EQ_H_

#define SS_INFINITE_ROOT_NUM -1

/*! 
 *  \brief solves suare equation a*x^2 + b*x + c = 0
 *  \param a
 *  \param b
 *  \param c
 *  \param r1 pointer to the first root if present
 *  \param r2 pointer to the second root if present
 *  \return number of roots or SS_INFINITE_ROOT_NUM
 */
int SolveSqrEq(double a, double b, double c, double *r1, double *r2);

#endif