/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * normalize.c
 *
 * Code generation for function 'normalize'
 *
 */

/* Include files */
#include "normalize.h"
#include "rt_nonfinite.h"
#include "std.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void normalize(const double a[11248640], double n[11248640])
{
  double b;
  double bsum;
  double y;
  int counts;
  int ib;
  int k;
  int xblockoffset;
  if (rtIsNaN(a[0])) {
    y = 0.0;
    counts = 0;
  } else {
    y = a[0];
    counts = 1;
  }
  for (k = 0; k < 1023; k++) {
    b = a[k + 1];
    if (!rtIsNaN(b)) {
      y += b;
      counts++;
    }
  }
  for (ib = 0; ib < 10984; ib++) {
    xblockoffset = (ib + 1) << 10;
    bsum = a[xblockoffset];
    if (rtIsNaN(bsum)) {
      bsum = 0.0;
    } else {
      counts++;
    }
    for (k = 0; k < 1023; k++) {
      b = a[(xblockoffset + k) + 1];
      if (!rtIsNaN(b)) {
        bsum += b;
        counts++;
      }
    }
    y += bsum;
  }
  y /= (double)counts;
  b = b_std(a);
  for (k = 0; k < 11248640; k++) {
    n[k] = (a[k] - y) / b;
  }
}

/* End of code generation (normalize.c) */
