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

    double a, b, c;
    scanf("%lg %lg %lg", &a, &b, &c);

    double r1, r2;
    int n_roots = SolveSqrEq(a, b, c, &r1, &r2);

    switch (n_roots)
    {
    case 0:
        printf("this equation doesn't have roots\n");
        break;

    case 1:
        printf("found 1 root: r1 = %lg\n", r1);
        break;

    case 2:
        printf("found 2 roots: r1 = %lg, r2 = %lg\n", r1, r2);
        break;

    case SS_INFINITE_ROOT_NUM:
        printf("solution: x is any value\n");
        break;

    default:
        assert(0);
        break;
    }

    return 0;
}
