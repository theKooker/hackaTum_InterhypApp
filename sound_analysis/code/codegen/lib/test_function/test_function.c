/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * test_function.c
 *
 * Code generation for function 'test_function'
 *
 */

/* Include files */
#include "test_function.h"

/* Function Definitions */
double test_function(double x, double y)
{
  static const signed char iv[9] = {5, 14, 26, 40, 55, 40, 26, 14, 5};
  double b_y;
  int k;
  b_y = 5.0;
  for (k = 0; k < 8; k++) {
    b_y += (double)iv[k + 1];
  }
  return (x + y) + b_y;
}

/* End of code generation (test_function.c) */
