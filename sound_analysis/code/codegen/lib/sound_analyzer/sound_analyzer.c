/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sound_analyzer.c
 *
 * Code generation for function 'sound_analyzer'
 *
 */

/* Include files */
#include "sound_analyzer.h"
#include "fft.h"
#include "normalize.h"
#include "rt_nonfinite.h"
#include "sound_analyzer_emxutil.h"
#include "sound_analyzer_types.h"
#include "sum.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static double rt_hypotd_snf(double u0, double u1);

/* Function Definitions */
static double rt_hypotd_snf(double u0, double u1)
{
  double a;
  double y;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = a * sqrt(y * y + 1.0);
  } else if (!rtIsNaN(y)) {
    y = a * 1.4142135623730951;
  }
  return y;
}

double sound_analyzer(double b_signal[11248640], double Fs, double frame_time,
                      const double mask[256])
{
  static double c_signal[11248640];
  emxArray_boolean_T *calc_mask;
  emxArray_creal_T *Y;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_int32_T *r2;
  emxArray_real_T *P1;
  emxArray_real_T *P2;
  emxArray_real_T *f;
  emxArray_real_T *features;
  emxArray_real_T *pad_signal;
  emxArray_real_T *y;
  double L;
  double N;
  double N_tmp;
  double ai;
  double b;
  double bsum;
  double power;
  int b_i;
  int b_loop_ub;
  int b_unnamed_idx_0;
  int c_i;
  int i;
  int i1;
  int i2;
  int i3;
  int i4;
  int i5;
  int k;
  int loop_ub;
  int nx;
  int unnamed_idx_0;
  int xblockoffset;
  (void)mask;
  emxInit_real_T(&pad_signal, 1);
  /*  Normalize Signal */
  memcpy(&c_signal[0], &b_signal[0], 11248640U * sizeof(double));
  normalize(c_signal, b_signal);
  N_tmp = Fs * frame_time;
  N = ceil(1.124864E+7 / N_tmp);
  xblockoffset = (int)(N * Fs);
  i = pad_signal->size[0];
  pad_signal->size[0] = xblockoffset;
  emxEnsureCapacity_real_T(pad_signal, i);
  for (i = 0; i < xblockoffset; i++) {
    pad_signal->data[i] = 0.0;
  }
  for (i = 0; i < 11248640; i++) {
    pad_signal->data[i] = b_signal[i];
  }
  emxInit_real_T(&features, 2);
  i = features->size[0] * features->size[1];
  features->size[0] = 2;
  b_i = (int)N;
  features->size[1] = (int)N;
  emxEnsureCapacity_real_T(features, i);
  xblockoffset = (int)N << 1;
  for (i = 0; i < xblockoffset; i++) {
    features->data[i] = 0.0;
  }
  for (k = 0; k < 11248640; k++) {
    bsum = b_signal[k];
    c_signal[k] = bsum * bsum;
  }
  power = c_signal[0];
  for (k = 0; k < 1023; k++) {
    power += c_signal[k + 1];
  }
  for (nx = 0; nx < 10984; nx++) {
    xblockoffset = (nx + 1) << 10;
    bsum = c_signal[xblockoffset];
    for (k = 0; k < 1023; k++) {
      bsum += c_signal[(xblockoffset + k) + 1];
    }
    power += bsum;
  }
  emxInit_real_T(&f, 2);
  if (0 <= (int)N - 1) {
    i1 = (int)N_tmp;
    L = N_tmp;
    i2 = (int)N_tmp - 1;
    loop_ub = (int)N_tmp - 1;
    bsum = N_tmp / 2.0 + 1.0;
    if (1.0 > bsum) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = (int)bsum;
    }
    if (2.0 > (double)b_loop_ub - 1.0) {
      i3 = 0;
      i4 = -1;
      i = 0;
    } else {
      i3 = 1;
      i4 = 0;
      i = b_loop_ub - 1;
    }
    i5 = i - 1;
    b = N_tmp / 2.0;
  }
  emxInit_creal_T(&Y, 1);
  emxInit_real_T(&P2, 1);
  emxInit_real_T(&P1, 1);
  emxInit_int32_T(&r, 2);
  emxInit_int32_T(&r1, 2);
  emxInit_int32_T(&r2, 2);
  emxInit_real_T(&y, 1);
  for (c_i = 0; c_i < b_i; c_i++) {
    i = P2->size[0];
    P2->size[0] = i1;
    emxEnsureCapacity_real_T(P2, i);
    if (0 <= i1 - 1) {
      unnamed_idx_0 = (int)N_tmp;
      b_unnamed_idx_0 = (int)N_tmp;
    }
    for (k = 0; k < i1; k++) {
      P2->data[k] = pad_signal->data[k + unnamed_idx_0 * c_i] *
                    pad_signal->data[k + b_unnamed_idx_0 * c_i];
    }
    features->data[2 * c_i] = sum(P2) / power;
    unnamed_idx_0 = (int)N_tmp;
    i = P2->size[0];
    P2->size[0] = i2 + 1;
    emxEnsureCapacity_real_T(P2, i);
    for (i = 0; i <= loop_ub; i++) {
      P2->data[i] = pad_signal->data[i + (int)N_tmp * c_i];
    }
    fft(P2, Y);
    xblockoffset = Y->size[0];
    for (i = 0; i < xblockoffset; i++) {
      bsum = Y->data[i].re;
      ai = Y->data[i].im;
      if (ai == 0.0) {
        N = bsum / L;
        bsum = 0.0;
      } else if (bsum == 0.0) {
        N = 0.0;
        bsum = ai / L;
      } else {
        N = bsum / L;
        bsum = ai / L;
      }
      Y->data[i].re = N;
      Y->data[i].im = bsum;
    }
    nx = Y->size[0];
    i = P2->size[0];
    P2->size[0] = Y->size[0];
    emxEnsureCapacity_real_T(P2, i);
    for (k = 0; k < nx; k++) {
      P2->data[k] = rt_hypotd_snf(Y->data[k].re, Y->data[k].im);
    }
    /* P1 = [P2(L/2+1:end); P2(1:L/2)]; */
    i = P1->size[0];
    P1->size[0] = b_loop_ub;
    emxEnsureCapacity_real_T(P1, i);
    for (i = 0; i < b_loop_ub; i++) {
      P1->data[i] = P2->data[i];
    }
    nx = i5 - i4;
    for (i = 0; i < nx; i++) {
      P1->data[(i4 + i) + 1] = 2.0 * P2->data[i3 + i];
    }
    if (rtIsNaN(b)) {
      i = f->size[0] * f->size[1];
      f->size[0] = 1;
      f->size[1] = 1;
      emxEnsureCapacity_real_T(f, i);
      f->data[0] = rtNaN;
    } else if (b < 0.0) {
      f->size[1] = 0;
    } else if (rtIsInf(b) && (0.0 == b)) {
      i = f->size[0] * f->size[1];
      f->size[0] = 1;
      f->size[1] = 1;
      emxEnsureCapacity_real_T(f, i);
      f->data[0] = rtNaN;
    } else {
      i = f->size[0] * f->size[1];
      f->size[0] = 1;
      xblockoffset = (int)floor(b);
      f->size[1] = xblockoffset + 1;
      emxEnsureCapacity_real_T(f, i);
      for (i = 0; i <= xblockoffset; i++) {
        f->data[i] = i;
      }
    }
    i = f->size[0] * f->size[1];
    f->size[0] = 1;
    emxEnsureCapacity_real_T(f, i);
    xblockoffset = f->size[1] - 1;
    for (i = 0; i <= xblockoffset; i++) {
      f->data[i] = Fs * f->data[i] / L;
    }
    xblockoffset = f->size[1] - 1;
    k = 0;
    for (i = 0; i <= xblockoffset; i++) {
      if (f->data[i] < 13000.0) {
        k++;
      }
    }
    i = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] = k;
    emxEnsureCapacity_int32_T(r, i);
    nx = 0;
    for (i = 0; i <= xblockoffset; i++) {
      if (f->data[i] < 13000.0) {
        r->data[nx] = i + 1;
        nx++;
      }
    }
    xblockoffset = r->size[1];
    i = P2->size[0];
    P2->size[0] = r->size[1];
    emxEnsureCapacity_real_T(P2, i);
    for (i = 0; i < xblockoffset; i++) {
      P2->data[i] = P1->data[r->data[i] - 1];
    }
    i = P1->size[0];
    P1->size[0] = P2->size[0];
    emxEnsureCapacity_real_T(P1, i);
    xblockoffset = P2->size[0];
    for (i = 0; i < xblockoffset; i++) {
      P1->data[i] = P2->data[i];
    }
    xblockoffset = f->size[1] - 1;
    k = 0;
    for (i = 0; i <= xblockoffset; i++) {
      if (f->data[i] < 13000.0) {
        k++;
      }
    }
    nx = 0;
    for (i = 0; i <= xblockoffset; i++) {
      if (f->data[i] < 13000.0) {
        f->data[nx] = f->data[i];
        nx++;
      }
    }
    i = f->size[0] * f->size[1];
    f->size[0] = 1;
    f->size[1] = k;
    emxEnsureCapacity_real_T(f, i);
    xblockoffset = k - 1;
    k = 0;
    for (i = 0; i <= xblockoffset; i++) {
      if (f->data[i] < 1000.0) {
        k++;
      }
    }
    i = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    r1->size[1] = k;
    emxEnsureCapacity_int32_T(r1, i);
    nx = 0;
    for (i = 0; i <= xblockoffset; i++) {
      if (f->data[i] < 1000.0) {
        r1->data[nx] = i + 1;
        nx++;
      }
    }
    k = 0;
    for (i = 0; i <= xblockoffset; i++) {
      if (f->data[i] >= 1000.0) {
        k++;
      }
    }
    i = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = k;
    emxEnsureCapacity_int32_T(r2, i);
    nx = 0;
    for (i = 0; i <= xblockoffset; i++) {
      if (f->data[i] >= 1000.0) {
        r2->data[nx] = i + 1;
        nx++;
      }
    }
    i = P2->size[0];
    P2->size[0] = r1->size[1];
    emxEnsureCapacity_real_T(P2, i);
    nx = r1->size[1];
    for (k = 0; k < nx; k++) {
      bsum = P1->data[r1->data[k] - 1];
      P2->data[k] = bsum * bsum;
    }
    i = y->size[0];
    y->size[0] = r2->size[1];
    emxEnsureCapacity_real_T(y, i);
    nx = r2->size[1];
    for (k = 0; k < nx; k++) {
      bsum = P1->data[r2->data[k] - 1];
      y->data[k] = bsum * bsum;
    }
    features->data[2 * c_i + 1] = sum(P2) / sum(y);
  }
  emxFree_real_T(&y);
  emxFree_int32_T(&r2);
  emxFree_int32_T(&r1);
  emxFree_int32_T(&r);
  emxFree_real_T(&f);
  emxFree_real_T(&P1);
  emxFree_real_T(&P2);
  emxFree_creal_T(&Y);
  emxFree_real_T(&pad_signal);
  emxInit_boolean_T(&calc_mask, 2);
  xblockoffset = features->size[1];
  i = calc_mask->size[0] * calc_mask->size[1];
  calc_mask->size[0] = 1;
  calc_mask->size[1] = features->size[1];
  emxEnsureCapacity_boolean_T(calc_mask, i);
  for (i = 0; i < xblockoffset; i++) {
    calc_mask->data[i] = (features->data[2 * i + 1] < 0.4);
  }
  emxFree_real_T(&features);
  xblockoffset = calc_mask->size[1];
  if (calc_mask->size[1] == 0) {
    nx = 0;
  } else {
    nx = calc_mask->data[0];
    for (k = 2; k <= xblockoffset; k++) {
      nx += calc_mask->data[k - 1];
    }
  }
  emxFree_boolean_T(&calc_mask);
  return nx;
  /*  Calc Accuracy */
  /* fp = (calc_mask == mask); */
  /* accuracy = sum(fp)/length(fp); */
  /* disp(accuracy) */
}

/* End of code generation (sound_analyzer.c) */
