#include <stdio.h>
#include <assert.h>

#include "SolveSqrEq.h"

int main()
{
    printf("\n"
           "##  square equation solver  ##\n"
           "##  CAT EDITION 1.0         ##\n"
           "\t  ^~^     \n"
           "\t ('Y') )  \n"
           "\t /   \\/  \n"
           "\t(\\|||/)  \n\n"
           "to solve a*x^2 + b*x + c = 0\n"
           "enter a b c : ");

    double a = 0, b = 0, c = 0;
    scanf("%lg %lg %lg", &a, &b, &c);

    double r1 = 0, r2 = 0;
    SOLVE_STATUS n_roots = SolveSqrEq(a, b, c, &r1, &r2);

    switch (n_roots)
    {
    case SOLVE_0_ROOTS:
        printf("this equation doesn't have roots\n");
        break;

    case SOLVE_1_ROOT:
        printf("found 1 root: r1 = %lg\n", r1);
        break;

    case SOLVE_2_ROOTS:
        printf("found 2 roots: r1 = %lg, r2 = %lg\n", r1, r2);
        break;

    case SOLVE_INF_ROOTS:
        printf("solution: x is any value\n");
        break;
    case SOLVE_ERR_BAD_PTR:
    case SOLVE_ERR_INF:
    default:
        printf("error occured\n");
        break;
    }

    return 0;
}
