#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include <assert.h>
#include "square_equation.h"

void print_failed_example(char error_name[], struct equation target, struct equation result, int numeric)
{
    printf("%d Failed: %s\n Must be: a: %f  b: %f  c: %f solutions: %d  x1: %f  x2: %f\n", numeric, error_name, target.a, target.b, target.c, target.solutions, target.x1, target.x2);
    printf("Be: a: %f  b: %f  c: %f solutions: %d  x1: %f  x2: %f\n", result.a, result.b, result.c, result.solutions, result.x1, result.x2);
}

void check_test(int numeric, struct equation target)
{
    struct equation test = {target.a, target.b, target.c, -100, NAN, NAN};

    solve_equation(&test);

    if (test.a == target.a && test.b == target.b && test.c == target.c)
    {
        if (test.solutions == target.solutions)
        {
            if (test.solutions == -1 || test.solutions == 0)
            {
                printf("%d Accepted\n", numeric);
            }

            else if (test.x1 == target.x1)
            {
                if (test.solutions == 1)
                {
                    printf("%d Accepted\n", numeric);
                }
                else if (test.x2 == target.x2)
                {
                    printf("%d Accepted\n", numeric);
                }
                else
                {
                    print_failed_example("Error x2", target, test, numeric);
                }
            }

            else
            {
                print_failed_example("Error x1", target, test, numeric);
            }
        }

        else
        {
            print_failed_example("Error solutions", target, test, numeric);
        }
    }

    else
    {
        print_failed_example("Error coefficients", target, test, numeric);
    }
}

void run_tests()
{
    struct equation tests[] = {{ 1, -5, 4, 2,    4, 1},
                                {1, -3, 2, 2,    2, 1},
                                {5,  3, 4, 0,      NAN,   NAN},
                                {8, 12, 7, 0,      NAN,   NAN},
                                {4,  4, 1, 1, -0.5,   NAN}};
    struct equation test = {NAN, NAN, NAN, -100, NAN, NAN};

    for (int i = 0; i < 5; i ++)
    {
        check_test(i, tests[i]);
    }
}