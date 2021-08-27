#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define EDGE_OF_ZERO 0.000001

/*!
 * Variations of roots count
 */
enum COUNTS_OF_ROOTS
{
    INF_ROOTS   = -1,
    NONE_ROOTS  =  0,
    SINGLE_ROOT =  1,
    TWO_ROOTS   =  2
};

/*!
 * Structer of equation
 */
struct equation
{
    /*! First or high coefficient of equation */
    double a;
    /*! Second coefficient of equation */
    double b;
    /*! Third or free coefficient of equation */
    double c;

    /*! count of solutions of equation, -1 - infinity, 0 - no solutions, 1 - single, 2 - two */
    int solutions;

    /*! first root (if there is) */
    double x1;
    /*! second root (if there is) */
    double x2;
};

/*!
 * run_tests runs all tests
 */
void run_tests(void);

/*!
 * check_test checks one test
 * @param numeric numeric of test
 * @param target example of test
 */
void check_test(int numeric, struct equation target);

/*!
 *
 * @param error_name name of error
 * @param target right value
 * @param result result of program
 * @param numeric count of solutions
 */
void print_failed_example(char error_name[], struct equation target, struct equation result, int numeric);

/*!
 * scan_coefficient add coefficient in pointer struct of equation
 * @param eq Pointer on structure of equation
 */
void scan_coefficient(struct equation *eq);

/*!
 * print_answer prints answer with checking count of roots
 * @param[in] eq Pointer on structure of equation
 */
void print_answer(struct equation *eq);

/*!
 * solve_equation distributes equation to linar or square equation by checking a and call functions
 * @param[in]  eq Pointer on structure of equation
 * @param[out] eq Pointer on changed structure with new count of solutions and roots (if it's)
 */
void solve_equation(struct equation *eq);

/*!
 * linear solves linear equation with checking another coefficient
 * @param[in] eq Pointer on structure of equation
 * @param[out] eq Pointer on changed structure with new count of solutions and roots (if it's)
 */
void linear(struct equation *eq);

/*!
 * square solves square equation with checking discriminant
 * @param[in] eq Pointer on example of equationPointer on structure of equation
 * @param[out] eq Pointer on changed structure with new count of solutions and roots (if it's)
 */
void square(struct equation *eq);

/*!
 * swap swaps elements
 * @param n
 * @param m
 */
void swap(double *n, double *m);
