#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "square_equation.h"

void scan_coefficient(struct equation *eq)
{
    while (scanf("%lg %lg %lg", &eq->a, &eq->b, &eq->c) != 3)
    {
        fflush(stdin);
        printf("Error format, try again. \n");
    }

    assert (isfinite(eq->a));
    assert (isfinite(eq->b));
    assert (isfinite(eq->c));
}

void print_answer(struct equation *eq)
{
    switch(eq->solutions)
    {
        case INF_ROOTS:
            printf("Infinitely many solutions\n");
            break;

        case NONE_ROOTS:
            printf("No solutions\n");
            break;

        case SINGLE_ROOT:
            printf ("Single root: %f\n", eq->x1);
            break;

        case TWO_ROOTS:
            printf("First solution: %f\n", eq->x1);
            printf("Second solution: %f", eq->x2);
            break;

        default:
            printf("Some problems with roots\n");
            break;
    }
}

void solve_equation(struct equation *eq)
{
    if (fabs(eq->a) > EDGE_OF_ZERO)
    {
        square(eq);
    }
    else
    {
        linear(eq);
    }
}

void linear(struct equation *eq)
{
    if (fabs(eq->b) < EDGE_OF_ZERO)
    {
        if (eq->c == 0)
        {
            eq->solutions = -1;
        }

        else
        {
            eq->solutions = 0;
        }
    }

    else
    {
        eq->solutions = 1;
        eq->x1 = (-eq->c) / eq->b;
    }
}

void swap(double *n, double *m)
{
    double t = *n;

    *n = *m;
    *m = t;

}

void square(struct equation *eq)
{
    if (eq->c == 0 && fabs(eq->b) > EDGE_OF_ZERO)
    {
        swap(&eq->a, &eq->b);
        swap(&eq->a, &eq->c);

        linear(eq);

        eq->solutions = 2;
        eq->x2 = 0;

        swap(&eq->c, &eq->b);
        swap(&eq->a, &eq->c);
    }
    else
    {
        double discriminant = eq->b * eq->b - 4 * eq->a * eq->c;

        if (discriminant < -EDGE_OF_ZERO)
        {
            eq->solutions = 0;
        }


        else if (fabs(discriminant) > EDGE_OF_ZERO)
        {
            discriminant = sqrt(discriminant);

            eq->solutions = 2;
            eq->x1 = (-eq->b + discriminant) / 2 / eq->a;
            eq->x2 = (-eq->b - discriminant) / 2 / eq->a;

            if (eq->x1 < eq->x2)
            {
                swap(&eq->x1, &eq->x2);
            }
        }

        else
        {
            eq->solutions = 1;
            eq->x1 = (-eq->b) / 2 / eq->a;
        }
    }
}