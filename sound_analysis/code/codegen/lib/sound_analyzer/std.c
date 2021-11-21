/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * std.c
 *
 * Code generation for function 'std'
 *
 */

/* Include files */
#include "std.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
double b_std(const double x[11248640])
{
  static double v[11248640];
  double bsum;
  double d;
  double t;
  double xbar;
  double y;
  int firstBlockLength;
  int hi;
  int k;
  int lastBlockLength;
  int nblocks;
  int nn_tmp;
  int nnans;
  int xblockoffset;
  memcpy(&v[0], &x[0], 11248640U * sizeof(double));
  nnans = 0;
  for (k = 0; k < 11248640; k++) {
    if (rtIsNaN(v[k])) {
      nnans++;
    } else {
      v[k - nnans] = v[k];
    }
  }
  nn_tmp = 11248639 - nnans;
  if (11248640 - nnans == 0) {
    y = rtNaN;
  } else if (11248640 - nnans == 1) {
    if ((!rtIsInf(v[0])) && (!rtIsNaN(v[0]))) {
      y = 0.0;
    } else {
      y = rtNaN;
    }
  } else {
    if (11248640 - nnans <= 1024) {
      firstBlockLength = 11248640 - nnans;
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = (11248640 - nnans) / 1024;
      lastBlockLength = 11248640 - (nnans + (nblocks << 10));
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    xbar = v[0];
    for (k = 2; k <= firstBlockLength; k++) {
      xbar += v[k - 1];
    }
    for (firstBlockLength = 2; firstBlockLength <= nblocks;
         firstBlockLength++) {
      xblockoffset = (firstBlockLength - 1) << 10;
      bsum = v[xblockoffset];
      if (firstBlockLength == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }
      for (k = 2; k <= hi; k++) {
        bsum += v[(xblockoffset + k) - 1];
      }
      xbar += bsum;
    }
    xbar /= (double)(11248640 - nnans);
    y = 0.0;
    bsum = 3.3121686421112381E-170;
    for (k = 0; k <= nn_tmp; k++) {
      d = fabs(v[k] - xbar);
      if (d > bsum) {
        t = bsum / d;
        y = y * t * t + 1.0;
        bsum = d;
      } else {
        t = d / bsum;
        y += t * t;
      }
    }
    y = bsum * sqrt(y);
    y /= sqrt(11248639 - nnans);
  }
  return y;
}

/* End of code generation (std.c) */
