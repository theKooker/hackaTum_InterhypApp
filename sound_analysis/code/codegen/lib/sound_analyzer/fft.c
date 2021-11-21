/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fft.c
 *
 * Code generation for function 'fft'
 *
 */

/* Include files */
#include "fft.h"
#include "FFTImplementationCallback.h"
#include "rt_nonfinite.h"
#include "sound_analyzer_emxutil.h"
#include "sound_analyzer_types.h"
#include <math.h>

/* Function Definitions */
void fft(const emxArray_real_T *x, emxArray_creal_T *y)
{
  emxArray_real_T *costab;
  emxArray_real_T *costab1q;
  emxArray_real_T *sintab;
  emxArray_real_T *sintabinv;
  double e;
  int k;
  int n;
  int pmax;
  int pmin;
  int pow2p;
  bool exitg1;
  bool useRadix2;
  if (x->size[0] == 0) {
    y->size[0] = 0;
  } else {
    useRadix2 = ((x->size[0] & (x->size[0] - 1)) == 0);
    pow2p = 1;
    if (useRadix2) {
      pmax = x->size[0];
    } else {
      n = (x->size[0] + x->size[0]) - 1;
      pmax = 31;
      if (n <= 1) {
        pmax = 0;
      } else {
        pmin = 0;
        exitg1 = false;
        while ((!exitg1) && (pmax - pmin > 1)) {
          k = (pmin + pmax) >> 1;
          pow2p = 1 << k;
          if (pow2p == n) {
            pmax = k;
            exitg1 = true;
          } else if (pow2p > n) {
            pmax = k;
          } else {
            pmin = k;
          }
        }
      }
      pow2p = 1 << pmax;
      pmax = pow2p;
    }
    emxInit_real_T(&costab1q, 2);
    e = 6.2831853071795862 / (double)pmax;
    n = pmax / 2 / 2;
    pmin = costab1q->size[0] * costab1q->size[1];
    costab1q->size[0] = 1;
    costab1q->size[1] = n + 1;
    emxEnsureCapacity_real_T(costab1q, pmin);
    costab1q->data[0] = 1.0;
    pmax = n / 2 - 1;
    for (k = 0; k <= pmax; k++) {
      costab1q->data[k + 1] = cos(e * ((double)k + 1.0));
    }
    pmin = pmax + 2;
    pmax = n - 1;
    for (k = pmin; k <= pmax; k++) {
      costab1q->data[k] = sin(e * (double)(n - k));
    }
    costab1q->data[n] = 0.0;
    emxInit_real_T(&costab, 2);
    emxInit_real_T(&sintab, 2);
    emxInit_real_T(&sintabinv, 2);
    if (!useRadix2) {
      n = costab1q->size[1] - 1;
      pmax = (costab1q->size[1] - 1) << 1;
      pmin = costab->size[0] * costab->size[1];
      costab->size[0] = 1;
      costab->size[1] = pmax + 1;
      emxEnsureCapacity_real_T(costab, pmin);
      pmin = sintab->size[0] * sintab->size[1];
      sintab->size[0] = 1;
      sintab->size[1] = pmax + 1;
      emxEnsureCapacity_real_T(sintab, pmin);
      costab->data[0] = 1.0;
      sintab->data[0] = 0.0;
      pmin = sintabinv->size[0] * sintabinv->size[1];
      sintabinv->size[0] = 1;
      sintabinv->size[1] = pmax + 1;
      emxEnsureCapacity_real_T(sintabinv, pmin);
      for (k = 0; k < n; k++) {
        sintabinv->data[k + 1] = costab1q->data[(n - k) - 1];
      }
      pmin = costab1q->size[1];
      for (k = pmin; k <= pmax; k++) {
        sintabinv->data[k] = costab1q->data[k - n];
      }
      for (k = 0; k < n; k++) {
        costab->data[k + 1] = costab1q->data[k + 1];
        sintab->data[k + 1] = -costab1q->data[(n - k) - 1];
      }
      pmin = costab1q->size[1];
      for (k = pmin; k <= pmax; k++) {
        costab->data[k] = -costab1q->data[pmax - k];
        sintab->data[k] = -costab1q->data[k - n];
      }
    } else {
      n = costab1q->size[1] - 1;
      pmax = (costab1q->size[1] - 1) << 1;
      pmin = costab->size[0] * costab->size[1];
      costab->size[0] = 1;
      costab->size[1] = pmax + 1;
      emxEnsureCapacity_real_T(costab, pmin);
      pmin = sintab->size[0] * sintab->size[1];
      sintab->size[0] = 1;
      sintab->size[1] = pmax + 1;
      emxEnsureCapacity_real_T(sintab, pmin);
      costab->data[0] = 1.0;
      sintab->data[0] = 0.0;
      for (k = 0; k < n; k++) {
        costab->data[k + 1] = costab1q->data[k + 1];
        sintab->data[k + 1] = -costab1q->data[(n - k) - 1];
      }
      pmin = costab1q->size[1];
      for (k = pmin; k <= pmax; k++) {
        costab->data[k] = -costab1q->data[pmax - k];
        sintab->data[k] = -costab1q->data[k - n];
      }
      sintabinv->size[0] = 1;
      sintabinv->size[1] = 0;
    }
    emxFree_real_T(&costab1q);
    if (useRadix2) {
      pmin = y->size[0];
      y->size[0] = x->size[0];
      emxEnsureCapacity_creal_T(y, pmin);
      if (x->size[0] != 1) {
        c_FFTImplementationCallback_doH(x, y, x->size[0], costab, sintab);
      } else {
        y->data[0].re = x->data[0];
        y->data[0].im = 0.0;
      }
    } else {
      c_FFTImplementationCallback_dob(x, pow2p, x->size[0], costab, sintab,
                                      sintabinv, y);
    }
    emxFree_real_T(&sintabinv);
    emxFree_real_T(&sintab);
    emxFree_real_T(&costab);
  }
}

/* End of code generation (fft.c) */
