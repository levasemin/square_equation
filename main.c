#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "square_equation.h"
/*! @mainpage
 * - main.c
 */

int main()
{
    struct equation equat = {NAN, NAN, NAN, -100, NAN, NAN};

    scan_coefficient (&equat);

    solve_equation (&equat);

    print_answer (&equat);
}

