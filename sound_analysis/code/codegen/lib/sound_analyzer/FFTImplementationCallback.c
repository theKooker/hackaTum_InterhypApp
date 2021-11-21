/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * FFTImplementationCallback.c
 *
 * Code generation for function 'FFTImplementationCallback'
 *
 */

/* Include files */
#include "FFTImplementationCallback.h"
#include "rt_nonfinite.h"
#include "sound_analyzer_emxutil.h"
#include "sound_analyzer_types.h"
#include <math.h>

/* Function Declarations */
static void c_FFTImplementationCallback_r2b(const emxArray_creal_T *x,
                                            int unsigned_nRows,
                                            const emxArray_real_T *costab,
                                            const emxArray_real_T *sintab,
                                            emxArray_creal_T *y);

static void d_FFTImplementationCallback_doH(
    const emxArray_real_T *x, emxArray_creal_T *y, int nrowsx, int nRows,
    int nfft, const emxArray_creal_T *wwc, const emxArray_real_T *costab,
    const emxArray_real_T *sintab, const emxArray_real_T *costabinv,
    const emxArray_real_T *sintabinv);

/* Function Definitions */
static void c_FFTImplementationCallback_r2b(const emxArray_creal_T *x,
                                            int unsigned_nRows,
                                            const emxArray_real_T *costab,
                                            const emxArray_real_T *sintab,
                                            emxArray_creal_T *y)
{
  double temp_im;
  double temp_re;
  double twid_im;
  double twid_re;
  int i;
  int iDelta2;
  int iheight;
  int ihi;
  int iy;
  int j;
  int ju;
  int k;
  int nRowsD2;
  int temp_re_tmp;
  bool tst;
  iy = y->size[0];
  y->size[0] = unsigned_nRows;
  emxEnsureCapacity_creal_T(y, iy);
  if (unsigned_nRows > x->size[0]) {
    iy = y->size[0];
    y->size[0] = unsigned_nRows;
    emxEnsureCapacity_creal_T(y, iy);
    for (iy = 0; iy < unsigned_nRows; iy++) {
      y->data[iy].re = 0.0;
      y->data[iy].im = 0.0;
    }
  }
  iDelta2 = x->size[0];
  if (iDelta2 >= unsigned_nRows) {
    iDelta2 = unsigned_nRows;
  }
  iheight = unsigned_nRows - 2;
  nRowsD2 = unsigned_nRows / 2;
  k = nRowsD2 / 2;
  iy = 0;
  ju = 0;
  for (i = 0; i <= iDelta2 - 2; i++) {
    y->data[iy] = x->data[i];
    iy = unsigned_nRows;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }
    iy = ju;
  }
  y->data[iy] = x->data[iDelta2 - 1];
  if (unsigned_nRows > 1) {
    for (i = 0; i <= iheight; i += 2) {
      temp_re = y->data[i + 1].re;
      temp_im = y->data[i + 1].im;
      twid_re = y->data[i].re;
      twid_im = y->data[i].im;
      y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
      y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
      twid_re += temp_re;
      twid_im += temp_im;
      y->data[i].re = twid_re;
      y->data[i].im = twid_im;
    }
  }
  iy = 2;
  iDelta2 = 4;
  iheight = ((k - 1) << 2) + 1;
  while (k > 0) {
    for (i = 0; i < iheight; i += iDelta2) {
      temp_re_tmp = i + iy;
      temp_re = y->data[temp_re_tmp].re;
      temp_im = y->data[temp_re_tmp].im;
      y->data[temp_re_tmp].re = y->data[i].re - temp_re;
      y->data[temp_re_tmp].im = y->data[i].im - temp_im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }
    ju = 1;
    for (j = k; j < nRowsD2; j += k) {
      twid_re = costab->data[j];
      twid_im = sintab->data[j];
      i = ju;
      ihi = ju + iheight;
      while (i < ihi) {
        temp_re_tmp = i + iy;
        temp_re = twid_re * y->data[temp_re_tmp].re -
                  twid_im * y->data[temp_re_tmp].im;
        temp_im = twid_re * y->data[temp_re_tmp].im +
                  twid_im * y->data[temp_re_tmp].re;
        y->data[temp_re_tmp].re = y->data[i].re - temp_re;
        y->data[temp_re_tmp].im = y->data[i].im - temp_im;
        y->data[i].re += temp_re;
        y->data[i].im += temp_im;
        i += iDelta2;
      }
      ju++;
    }
    k /= 2;
    iy = iDelta2;
    iDelta2 += iDelta2;
    iheight -= iy;
  }
}

static void d_FFTImplementationCallback_doH(
    const emxArray_real_T *x, emxArray_creal_T *y, int nrowsx, int nRows,
    int nfft, const emxArray_creal_T *wwc, const emxArray_real_T *costab,
    const emxArray_real_T *sintab, const emxArray_real_T *costabinv,
    const emxArray_real_T *sintabinv)
{
  emxArray_creal_T *fv;
  emxArray_creal_T *fy;
  emxArray_creal_T *reconVar1;
  emxArray_creal_T *reconVar2;
  emxArray_creal_T *ytmp;
  emxArray_int32_T *wrapIndex;
  emxArray_real_T *b_costab;
  emxArray_real_T *b_sintab;
  emxArray_real_T *costab1q;
  emxArray_real_T *hcostabinv;
  emxArray_real_T *hsintab;
  emxArray_real_T *hsintabinv;
  double temp_im;
  double temp_re;
  double twid_im;
  double twid_re;
  double z_tmp;
  int hnRows;
  int hszCostab;
  int i;
  int ihi;
  int istart;
  int j;
  int ju;
  int k;
  int nRowsD2;
  int nd2;
  int temp_re_tmp;
  bool tst;
  emxInit_creal_T(&ytmp, 1);
  hnRows = nRows / 2;
  istart = ytmp->size[0];
  ytmp->size[0] = hnRows;
  emxEnsureCapacity_creal_T(ytmp, istart);
  if (hnRows > nrowsx) {
    istart = ytmp->size[0];
    ytmp->size[0] = hnRows;
    emxEnsureCapacity_creal_T(ytmp, istart);
    for (istart = 0; istart < hnRows; istart++) {
      ytmp->data[istart].re = 0.0;
      ytmp->data[istart].im = 0.0;
    }
  }
  if ((x->size[0] & 1) == 0) {
    tst = true;
    ju = x->size[0];
  } else if (x->size[0] >= nRows) {
    tst = true;
    ju = nRows;
  } else {
    tst = false;
    ju = x->size[0] - 1;
  }
  emxInit_real_T(&costab1q, 2);
  if (ju >= nRows) {
    ju = nRows;
  }
  nd2 = nRows << 1;
  twid_re = 6.2831853071795862 / (double)nd2;
  j = nd2 / 2 / 2;
  istart = costab1q->size[0] * costab1q->size[1];
  costab1q->size[0] = 1;
  costab1q->size[1] = j + 1;
  emxEnsureCapacity_real_T(costab1q, istart);
  costab1q->data[0] = 1.0;
  nd2 = j / 2 - 1;
  for (k = 0; k <= nd2; k++) {
    costab1q->data[k + 1] = cos(twid_re * ((double)k + 1.0));
  }
  istart = nd2 + 2;
  nd2 = j - 1;
  for (k = istart; k <= nd2; k++) {
    costab1q->data[k] = sin(twid_re * (double)(j - k));
  }
  emxInit_real_T(&b_costab, 2);
  emxInit_real_T(&b_sintab, 2);
  costab1q->data[j] = 0.0;
  j = costab1q->size[1] - 1;
  nd2 = (costab1q->size[1] - 1) << 1;
  istart = b_costab->size[0] * b_costab->size[1];
  b_costab->size[0] = 1;
  b_costab->size[1] = nd2 + 1;
  emxEnsureCapacity_real_T(b_costab, istart);
  istart = b_sintab->size[0] * b_sintab->size[1];
  b_sintab->size[0] = 1;
  b_sintab->size[1] = nd2 + 1;
  emxEnsureCapacity_real_T(b_sintab, istart);
  b_costab->data[0] = 1.0;
  b_sintab->data[0] = 0.0;
  for (k = 0; k < j; k++) {
    b_costab->data[k + 1] = costab1q->data[k + 1];
    b_sintab->data[k + 1] = -costab1q->data[(j - k) - 1];
  }
  istart = costab1q->size[1];
  for (k = istart; k <= nd2; k++) {
    b_costab->data[k] = -costab1q->data[nd2 - k];
    b_sintab->data[k] = -costab1q->data[k - j];
  }
  emxInit_real_T(&hsintab, 2);
  emxInit_real_T(&hcostabinv, 2);
  emxInit_real_T(&hsintabinv, 2);
  hszCostab = costab->size[1] / 2;
  istart = costab1q->size[0] * costab1q->size[1];
  costab1q->size[0] = 1;
  costab1q->size[1] = hszCostab;
  emxEnsureCapacity_real_T(costab1q, istart);
  istart = hsintab->size[0] * hsintab->size[1];
  hsintab->size[0] = 1;
  hsintab->size[1] = hszCostab;
  emxEnsureCapacity_real_T(hsintab, istart);
  istart = hcostabinv->size[0] * hcostabinv->size[1];
  hcostabinv->size[0] = 1;
  hcostabinv->size[1] = hszCostab;
  emxEnsureCapacity_real_T(hcostabinv, istart);
  istart = hsintabinv->size[0] * hsintabinv->size[1];
  hsintabinv->size[0] = 1;
  hsintabinv->size[1] = hszCostab;
  emxEnsureCapacity_real_T(hsintabinv, istart);
  for (i = 0; i < hszCostab; i++) {
    nd2 = ((i + 1) << 1) - 2;
    costab1q->data[i] = costab->data[nd2];
    hsintab->data[i] = sintab->data[nd2];
    hcostabinv->data[i] = costabinv->data[nd2];
    hsintabinv->data[i] = sintabinv->data[nd2];
  }
  emxInit_int32_T(&wrapIndex, 2);
  emxInit_creal_T(&reconVar1, 1);
  emxInit_creal_T(&reconVar2, 1);
  istart = reconVar1->size[0];
  reconVar1->size[0] = hnRows;
  emxEnsureCapacity_creal_T(reconVar1, istart);
  istart = reconVar2->size[0];
  reconVar2->size[0] = hnRows;
  emxEnsureCapacity_creal_T(reconVar2, istart);
  istart = wrapIndex->size[0] * wrapIndex->size[1];
  wrapIndex->size[0] = 1;
  wrapIndex->size[1] = hnRows;
  emxEnsureCapacity_int32_T(wrapIndex, istart);
  for (i = 0; i < hnRows; i++) {
    istart = i << 1;
    twid_re = b_sintab->data[istart];
    twid_im = b_costab->data[istart];
    reconVar1->data[i].re = twid_re + 1.0;
    reconVar1->data[i].im = -twid_im;
    reconVar2->data[i].re = 1.0 - twid_re;
    reconVar2->data[i].im = twid_im;
    if (i + 1 != 1) {
      wrapIndex->data[i] = (hnRows - i) + 1;
    } else {
      wrapIndex->data[0] = 1;
    }
  }
  emxFree_real_T(&b_sintab);
  emxFree_real_T(&b_costab);
  z_tmp = (double)ju / 2.0;
  istart = (int)((double)ju / 2.0);
  for (hszCostab = 0; hszCostab < istart; hszCostab++) {
    temp_re_tmp = (hnRows + hszCostab) - 1;
    temp_re = wwc->data[temp_re_tmp].re;
    temp_im = wwc->data[temp_re_tmp].im;
    nd2 = hszCostab << 1;
    twid_re = x->data[nd2];
    twid_im = x->data[nd2 + 1];
    ytmp->data[hszCostab].re = temp_re * twid_re + temp_im * twid_im;
    ytmp->data[hszCostab].im = temp_re * twid_im - temp_im * twid_re;
  }
  if (!tst) {
    temp_re_tmp = (hnRows + (int)z_tmp) - 1;
    temp_re = wwc->data[temp_re_tmp].re;
    temp_im = wwc->data[temp_re_tmp].im;
    twid_re = x->data[(int)z_tmp << 1];
    ytmp->data[(int)z_tmp].re = temp_re * twid_re + temp_im * 0.0;
    ytmp->data[(int)z_tmp].im = temp_re * 0.0 - temp_im * twid_re;
    if ((int)z_tmp + 2 <= hnRows) {
      istart = (int)((double)ju / 2.0) + 2;
      for (i = istart; i <= hnRows; i++) {
        ytmp->data[i - 1].re = 0.0;
        ytmp->data[i - 1].im = 0.0;
      }
    }
  } else if ((int)z_tmp + 1 <= hnRows) {
    istart = (int)((double)ju / 2.0) + 1;
    for (i = istart; i <= hnRows; i++) {
      ytmp->data[i - 1].re = 0.0;
      ytmp->data[i - 1].im = 0.0;
    }
  }
  emxInit_creal_T(&fy, 1);
  z_tmp = (double)nfft / 2.0;
  nd2 = (int)z_tmp;
  istart = fy->size[0];
  fy->size[0] = (int)z_tmp;
  emxEnsureCapacity_creal_T(fy, istart);
  if ((int)z_tmp > ytmp->size[0]) {
    istart = fy->size[0];
    fy->size[0] = (int)z_tmp;
    emxEnsureCapacity_creal_T(fy, istart);
    for (istart = 0; istart < nd2; istart++) {
      fy->data[istart].re = 0.0;
      fy->data[istart].im = 0.0;
    }
  }
  ju = ytmp->size[0];
  istart = (int)z_tmp;
  if (ju < istart) {
    istart = ju;
  }
  hszCostab = (int)z_tmp - 2;
  nRowsD2 = (int)z_tmp / 2;
  k = nRowsD2 / 2;
  nd2 = 0;
  ju = 0;
  for (i = 0; i <= istart - 2; i++) {
    fy->data[nd2] = ytmp->data[i];
    j = (int)z_tmp;
    tst = true;
    while (tst) {
      j >>= 1;
      ju ^= j;
      tst = ((ju & j) == 0);
    }
    nd2 = ju;
  }
  fy->data[nd2] = ytmp->data[istart - 1];
  if ((int)z_tmp > 1) {
    for (i = 0; i <= hszCostab; i += 2) {
      temp_re = fy->data[i + 1].re;
      temp_im = fy->data[i + 1].im;
      twid_re = fy->data[i].re;
      twid_im = fy->data[i].im;
      fy->data[i + 1].re = fy->data[i].re - fy->data[i + 1].re;
      fy->data[i + 1].im = fy->data[i].im - fy->data[i + 1].im;
      twid_re += temp_re;
      twid_im += temp_im;
      fy->data[i].re = twid_re;
      fy->data[i].im = twid_im;
    }
  }
  nd2 = 2;
  hszCostab = 4;
  ju = ((k - 1) << 2) + 1;
  while (k > 0) {
    for (i = 0; i < ju; i += hszCostab) {
      temp_re_tmp = i + nd2;
      temp_re = fy->data[temp_re_tmp].re;
      temp_im = fy->data[temp_re_tmp].im;
      fy->data[temp_re_tmp].re = fy->data[i].re - temp_re;
      fy->data[temp_re_tmp].im = fy->data[i].im - temp_im;
      fy->data[i].re += temp_re;
      fy->data[i].im += temp_im;
    }
    istart = 1;
    for (j = k; j < nRowsD2; j += k) {
      twid_re = costab1q->data[j];
      twid_im = hsintab->data[j];
      i = istart;
      ihi = istart + ju;
      while (i < ihi) {
        temp_re_tmp = i + nd2;
        temp_re = twid_re * fy->data[temp_re_tmp].re -
                  twid_im * fy->data[temp_re_tmp].im;
        temp_im = twid_re * fy->data[temp_re_tmp].im +
                  twid_im * fy->data[temp_re_tmp].re;
        fy->data[temp_re_tmp].re = fy->data[i].re - temp_re;
        fy->data[temp_re_tmp].im = fy->data[i].im - temp_im;
        fy->data[i].re += temp_re;
        fy->data[i].im += temp_im;
        i += hszCostab;
      }
      istart++;
    }
    k /= 2;
    nd2 = hszCostab;
    hszCostab += hszCostab;
    ju -= nd2;
  }
  emxInit_creal_T(&fv, 1);
  c_FFTImplementationCallback_r2b(wwc, (int)z_tmp, costab1q, hsintab, fv);
  nd2 = fy->size[0];
  emxFree_real_T(&costab1q);
  emxFree_real_T(&hsintab);
  for (istart = 0; istart < nd2; istart++) {
    twid_im = fy->data[istart].re * fv->data[istart].im +
              fy->data[istart].im * fv->data[istart].re;
    fy->data[istart].re = fy->data[istart].re * fv->data[istart].re -
                          fy->data[istart].im * fv->data[istart].im;
    fy->data[istart].im = twid_im;
  }
  c_FFTImplementationCallback_r2b(fy, (int)z_tmp, hcostabinv, hsintabinv, fv);
  emxFree_creal_T(&fy);
  emxFree_real_T(&hsintabinv);
  emxFree_real_T(&hcostabinv);
  if (fv->size[0] > 1) {
    twid_re = 1.0 / (double)fv->size[0];
    nd2 = fv->size[0];
    for (istart = 0; istart < nd2; istart++) {
      fv->data[istart].re *= twid_re;
      fv->data[istart].im *= twid_re;
    }
  }
  istart = wwc->size[0];
  for (k = hnRows; k <= istart; k++) {
    nd2 = k - hnRows;
    ytmp->data[nd2].re = wwc->data[k - 1].re * fv->data[k - 1].re +
                         wwc->data[k - 1].im * fv->data[k - 1].im;
    ytmp->data[nd2].im = wwc->data[k - 1].re * fv->data[k - 1].im -
                         wwc->data[k - 1].im * fv->data[k - 1].re;
  }
  emxFree_creal_T(&fv);
  for (i = 0; i < hnRows; i++) {
    istart = wrapIndex->data[i];
    twid_re = ytmp->data[istart - 1].re;
    twid_im = -ytmp->data[istart - 1].im;
    y->data[i].re =
        0.5 *
        ((ytmp->data[i].re * reconVar1->data[i].re -
          ytmp->data[i].im * reconVar1->data[i].im) +
         (twid_re * reconVar2->data[i].re - twid_im * reconVar2->data[i].im));
    y->data[i].im =
        0.5 *
        ((ytmp->data[i].re * reconVar1->data[i].im +
          ytmp->data[i].im * reconVar1->data[i].re) +
         (twid_re * reconVar2->data[i].im + twid_im * reconVar2->data[i].re));
    istart = hnRows + i;
    y->data[istart].re =
        0.5 *
        ((ytmp->data[i].re * reconVar2->data[i].re -
          ytmp->data[i].im * reconVar2->data[i].im) +
         (twid_re * reconVar1->data[i].re - twid_im * reconVar1->data[i].im));
    y->data[istart].im =
        0.5 *
        ((ytmp->data[i].re * reconVar2->data[i].im +
          ytmp->data[i].im * reconVar2->data[i].re) +
         (twid_re * reconVar1->data[i].im + twid_im * reconVar1->data[i].re));
  }
  emxFree_creal_T(&reconVar2);
  emxFree_creal_T(&reconVar1);
  emxFree_int32_T(&wrapIndex);
  emxFree_creal_T(&ytmp);
}

void c_FFTImplementationCallback_doH(const emxArray_real_T *x,
                                     emxArray_creal_T *y, int unsigned_nRows,
                                     const emxArray_real_T *costab,
                                     const emxArray_real_T *sintab)
{
  emxArray_creal_T *reconVar1;
  emxArray_creal_T *reconVar2;
  emxArray_int32_T *bitrevIndex;
  emxArray_int32_T *wrapIndex;
  emxArray_real_T *hcostab;
  emxArray_real_T *hsintab;
  double b_y_im;
  double temp2_im;
  double temp2_re;
  double temp_im;
  double temp_re;
  double y_im;
  double y_im_tmp;
  double z_tmp;
  int b_j1;
  int hszCostab;
  int i;
  int iDelta;
  int ihi;
  int istart;
  int ju;
  int k;
  int nRows;
  int nRowsD2;
  bool tst;
  emxInit_real_T(&hcostab, 2);
  emxInit_real_T(&hsintab, 2);
  nRows = unsigned_nRows / 2;
  istart = y->size[0];
  if (istart >= nRows) {
    istart = nRows;
  }
  ihi = nRows - 2;
  nRowsD2 = nRows / 2;
  k = nRowsD2 / 2;
  hszCostab = costab->size[1] / 2;
  b_j1 = hcostab->size[0] * hcostab->size[1];
  hcostab->size[0] = 1;
  hcostab->size[1] = hszCostab;
  emxEnsureCapacity_real_T(hcostab, b_j1);
  b_j1 = hsintab->size[0] * hsintab->size[1];
  hsintab->size[0] = 1;
  hsintab->size[1] = hszCostab;
  emxEnsureCapacity_real_T(hsintab, b_j1);
  for (i = 0; i < hszCostab; i++) {
    iDelta = ((i + 1) << 1) - 2;
    hcostab->data[i] = costab->data[iDelta];
    hsintab->data[i] = sintab->data[iDelta];
  }
  emxInit_int32_T(&wrapIndex, 2);
  emxInit_creal_T(&reconVar1, 1);
  emxInit_creal_T(&reconVar2, 1);
  b_j1 = reconVar1->size[0];
  reconVar1->size[0] = nRows;
  emxEnsureCapacity_creal_T(reconVar1, b_j1);
  b_j1 = reconVar2->size[0];
  reconVar2->size[0] = nRows;
  emxEnsureCapacity_creal_T(reconVar2, b_j1);
  b_j1 = wrapIndex->size[0] * wrapIndex->size[1];
  wrapIndex->size[0] = 1;
  wrapIndex->size[1] = nRows;
  emxEnsureCapacity_int32_T(wrapIndex, b_j1);
  for (i = 0; i < nRows; i++) {
    temp2_re = sintab->data[i];
    y_im = costab->data[i];
    reconVar1->data[i].re = temp2_re + 1.0;
    reconVar1->data[i].im = -y_im;
    reconVar2->data[i].re = 1.0 - temp2_re;
    reconVar2->data[i].im = y_im;
    if (i + 1 != 1) {
      wrapIndex->data[i] = (nRows - i) + 1;
    } else {
      wrapIndex->data[0] = 1;
    }
  }
  emxInit_int32_T(&bitrevIndex, 1);
  z_tmp = (double)unsigned_nRows / 2.0;
  ju = 0;
  hszCostab = 1;
  iDelta = (int)z_tmp;
  b_j1 = bitrevIndex->size[0];
  bitrevIndex->size[0] = (int)z_tmp;
  emxEnsureCapacity_int32_T(bitrevIndex, b_j1);
  for (b_j1 = 0; b_j1 < iDelta; b_j1++) {
    bitrevIndex->data[b_j1] = 0;
  }
  for (b_j1 = 0; b_j1 <= istart - 2; b_j1++) {
    bitrevIndex->data[b_j1] = hszCostab;
    iDelta = (int)z_tmp;
    tst = true;
    while (tst) {
      iDelta >>= 1;
      ju ^= iDelta;
      tst = ((ju & iDelta) == 0);
    }
    hszCostab = ju + 1;
  }
  bitrevIndex->data[istart - 1] = hszCostab;
  if ((x->size[0] & 1) == 0) {
    tst = true;
    istart = x->size[0];
  } else if (x->size[0] >= unsigned_nRows) {
    tst = true;
    istart = unsigned_nRows;
  } else {
    tst = false;
    istart = x->size[0] - 1;
  }
  if (istart < unsigned_nRows) {
    iDelta = istart;
  } else {
    iDelta = unsigned_nRows;
  }
  temp2_re = (double)iDelta / 2.0;
  if (istart >= unsigned_nRows) {
    istart = unsigned_nRows;
  }
  b_j1 = (int)((double)istart / 2.0);
  for (i = 0; i < b_j1; i++) {
    hszCostab = i << 1;
    y->data[bitrevIndex->data[i] - 1].re = x->data[hszCostab];
    y->data[bitrevIndex->data[i] - 1].im = x->data[hszCostab + 1];
  }
  if (!tst) {
    b_j1 = bitrevIndex->data[(int)temp2_re] - 1;
    y->data[b_j1].re = x->data[(int)temp2_re << 1];
    y->data[b_j1].im = 0.0;
  }
  emxFree_int32_T(&bitrevIndex);
  if (nRows > 1) {
    for (i = 0; i <= ihi; i += 2) {
      temp_re = y->data[i + 1].re;
      temp_im = y->data[i + 1].im;
      y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
      y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }
  }
  iDelta = 2;
  hszCostab = 4;
  ju = ((k - 1) << 2) + 1;
  while (k > 0) {
    for (i = 0; i < ju; i += hszCostab) {
      b_j1 = i + iDelta;
      temp_re = y->data[b_j1].re;
      temp_im = y->data[b_j1].im;
      y->data[b_j1].re = y->data[i].re - temp_re;
      y->data[b_j1].im = y->data[i].im - temp_im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }
    istart = 1;
    for (nRows = k; nRows < nRowsD2; nRows += k) {
      temp2_re = hcostab->data[nRows];
      temp2_im = hsintab->data[nRows];
      i = istart;
      ihi = istart + ju;
      while (i < ihi) {
        b_j1 = i + iDelta;
        temp_re = temp2_re * y->data[b_j1].re - temp2_im * y->data[b_j1].im;
        temp_im = temp2_re * y->data[b_j1].im + temp2_im * y->data[b_j1].re;
        y->data[b_j1].re = y->data[i].re - temp_re;
        y->data[b_j1].im = y->data[i].im - temp_im;
        y->data[i].re += temp_re;
        y->data[i].im += temp_im;
        i += hszCostab;
      }
      istart++;
    }
    k /= 2;
    iDelta = hszCostab;
    hszCostab += hszCostab;
    ju -= iDelta;
  }
  emxFree_real_T(&hsintab);
  emxFree_real_T(&hcostab);
  iDelta = (int)z_tmp / 2;
  temp2_re = y->data[0].re;
  temp_im = y->data[0].im;
  b_y_im = y->data[0].re * reconVar1->data[0].im +
           y->data[0].im * reconVar1->data[0].re;
  y_im = -y->data[0].im;
  y->data[0].re =
      0.5 * ((y->data[0].re * reconVar1->data[0].re -
              y->data[0].im * reconVar1->data[0].im) +
             (temp2_re * reconVar2->data[0].re - y_im * reconVar2->data[0].im));
  y->data[0].im = 0.5 * (b_y_im + (temp2_re * reconVar2->data[0].im +
                                   y_im * reconVar2->data[0].re));
  y->data[(int)z_tmp].re =
      0.5 *
      ((temp2_re * reconVar2->data[0].re - temp_im * reconVar2->data[0].im) +
       (temp2_re * reconVar1->data[0].re - -temp_im * reconVar1->data[0].im));
  y->data[(int)z_tmp].im =
      0.5 *
      ((temp2_re * reconVar2->data[0].im + temp_im * reconVar2->data[0].re) +
       (temp2_re * reconVar1->data[0].im + -temp_im * reconVar1->data[0].re));
  for (i = 2; i <= iDelta; i++) {
    temp_re = y->data[i - 1].re;
    temp_im = y->data[i - 1].im;
    b_j1 = wrapIndex->data[i - 1];
    y_im = y->data[b_j1 - 1].re;
    temp2_im = y->data[b_j1 - 1].im;
    b_y_im = y->data[i - 1].re * reconVar1->data[i - 1].im +
             y->data[i - 1].im * reconVar1->data[i - 1].re;
    y_im_tmp = -y->data[b_j1 - 1].im;
    y->data[i - 1].re = 0.5 * ((y->data[i - 1].re * reconVar1->data[i - 1].re -
                                y->data[i - 1].im * reconVar1->data[i - 1].im) +
                               (y_im * reconVar2->data[i - 1].re -
                                y_im_tmp * reconVar2->data[i - 1].im));
    y->data[i - 1].im = 0.5 * (b_y_im + (y_im * reconVar2->data[i - 1].im +
                                         y_im_tmp * reconVar2->data[i - 1].re));
    hszCostab = ((int)z_tmp + i) - 1;
    y->data[hszCostab].re = 0.5 * ((temp_re * reconVar2->data[i - 1].re -
                                    temp_im * reconVar2->data[i - 1].im) +
                                   (y_im * reconVar1->data[i - 1].re -
                                    -temp2_im * reconVar1->data[i - 1].im));
    y->data[hszCostab].im = 0.5 * ((temp_re * reconVar2->data[i - 1].im +
                                    temp_im * reconVar2->data[i - 1].re) +
                                   (y_im * reconVar1->data[i - 1].im +
                                    -temp2_im * reconVar1->data[i - 1].re));
    y->data[b_j1 - 1].re = 0.5 * ((y_im * reconVar1->data[b_j1 - 1].re -
                                   temp2_im * reconVar1->data[b_j1 - 1].im) +
                                  (temp_re * reconVar2->data[b_j1 - 1].re -
                                   -temp_im * reconVar2->data[b_j1 - 1].im));
    y->data[b_j1 - 1].im = 0.5 * ((y_im * reconVar1->data[b_j1 - 1].im +
                                   temp2_im * reconVar1->data[b_j1 - 1].re) +
                                  (temp_re * reconVar2->data[b_j1 - 1].im +
                                   -temp_im * reconVar2->data[b_j1 - 1].re));
    hszCostab = (b_j1 + (int)z_tmp) - 1;
    y->data[hszCostab].re = 0.5 * ((y_im * reconVar2->data[b_j1 - 1].re -
                                    temp2_im * reconVar2->data[b_j1 - 1].im) +
                                   (temp_re * reconVar1->data[b_j1 - 1].re -
                                    -temp_im * reconVar1->data[b_j1 - 1].im));
    y->data[hszCostab].im = 0.5 * ((y_im * reconVar2->data[b_j1 - 1].im +
                                    temp2_im * reconVar2->data[b_j1 - 1].re) +
                                   (temp_re * reconVar1->data[b_j1 - 1].im +
                                    -temp_im * reconVar1->data[b_j1 - 1].re));
  }
  emxFree_int32_T(&wrapIndex);
  if (iDelta != 0) {
    temp2_re = y->data[iDelta].re;
    temp_im = y->data[iDelta].im;
    b_y_im = y->data[iDelta].re * reconVar1->data[iDelta].im +
             y->data[iDelta].im * reconVar1->data[iDelta].re;
    y_im_tmp = -y->data[iDelta].im;
    y->data[iDelta].re =
        0.5 * ((y->data[iDelta].re * reconVar1->data[iDelta].re -
                y->data[iDelta].im * reconVar1->data[iDelta].im) +
               (temp2_re * reconVar2->data[iDelta].re -
                y_im_tmp * reconVar2->data[iDelta].im));
    y->data[iDelta].im =
        0.5 * (b_y_im + (temp2_re * reconVar2->data[iDelta].im +
                         y_im_tmp * reconVar2->data[iDelta].re));
    b_j1 = (int)z_tmp + iDelta;
    y->data[b_j1].re = 0.5 * ((temp2_re * reconVar2->data[iDelta].re -
                               temp_im * reconVar2->data[iDelta].im) +
                              (temp2_re * reconVar1->data[iDelta].re -
                               -temp_im * reconVar1->data[iDelta].im));
    y->data[b_j1].im = 0.5 * ((temp2_re * reconVar2->data[iDelta].im +
                               temp_im * reconVar2->data[iDelta].re) +
                              (temp2_re * reconVar1->data[iDelta].im +
                               -temp_im * reconVar1->data[iDelta].re));
  }
  emxFree_creal_T(&reconVar2);
  emxFree_creal_T(&reconVar1);
}

void c_FFTImplementationCallback_dob(const emxArray_real_T *x, int n2blue,
                                     int nfft, const emxArray_real_T *costab,
                                     const emxArray_real_T *sintab,
                                     const emxArray_real_T *sintabinv,
                                     emxArray_creal_T *y)
{
  emxArray_creal_T *fv;
  emxArray_creal_T *fy;
  emxArray_creal_T *wwc;
  double nt_im;
  double nt_re;
  double twid_im;
  double twid_re;
  int i;
  int ihi;
  int j;
  int k;
  int minNrowsNx;
  int nInt2;
  int nInt2m1;
  int nRowsD2;
  int nt_re_tmp;
  int rt;
  bool tst;
  emxInit_creal_T(&wwc, 1);
  if ((nfft != 1) && ((nfft & 1) == 0)) {
    j = nfft / 2;
    nInt2m1 = (j + j) - 1;
    ihi = wwc->size[0];
    wwc->size[0] = nInt2m1;
    emxEnsureCapacity_creal_T(wwc, ihi);
    rt = 0;
    wwc->data[j - 1].re = 1.0;
    wwc->data[j - 1].im = 0.0;
    nInt2 = j << 1;
    for (k = 0; k <= j - 2; k++) {
      minNrowsNx = ((k + 1) << 1) - 1;
      if (nInt2 - rt <= minNrowsNx) {
        rt += minNrowsNx - nInt2;
      } else {
        rt += minNrowsNx;
      }
      nt_im = -3.1415926535897931 * (double)rt / (double)j;
      if (nt_im == 0.0) {
        nt_re = 1.0;
        nt_im = 0.0;
      } else {
        nt_re = cos(nt_im);
        nt_im = sin(nt_im);
      }
      ihi = (j - k) - 2;
      wwc->data[ihi].re = nt_re;
      wwc->data[ihi].im = -nt_im;
    }
    ihi = nInt2m1 - 1;
    for (k = ihi; k >= j; k--) {
      wwc->data[k] = wwc->data[(nInt2m1 - k) - 1];
    }
  } else {
    nInt2m1 = (nfft + nfft) - 1;
    ihi = wwc->size[0];
    wwc->size[0] = nInt2m1;
    emxEnsureCapacity_creal_T(wwc, ihi);
    rt = 0;
    wwc->data[nfft - 1].re = 1.0;
    wwc->data[nfft - 1].im = 0.0;
    nInt2 = nfft << 1;
    for (k = 0; k <= nfft - 2; k++) {
      minNrowsNx = ((k + 1) << 1) - 1;
      if (nInt2 - rt <= minNrowsNx) {
        rt += minNrowsNx - nInt2;
      } else {
        rt += minNrowsNx;
      }
      nt_im = -3.1415926535897931 * (double)rt / (double)nfft;
      if (nt_im == 0.0) {
        nt_re = 1.0;
        nt_im = 0.0;
      } else {
        nt_re = cos(nt_im);
        nt_im = sin(nt_im);
      }
      ihi = (nfft - k) - 2;
      wwc->data[ihi].re = nt_re;
      wwc->data[ihi].im = -nt_im;
    }
    ihi = nInt2m1 - 1;
    for (k = ihi; k >= nfft; k--) {
      wwc->data[k] = wwc->data[(nInt2m1 - k) - 1];
    }
  }
  ihi = y->size[0];
  y->size[0] = nfft;
  emxEnsureCapacity_creal_T(y, ihi);
  if (nfft > x->size[0]) {
    ihi = y->size[0];
    y->size[0] = nfft;
    emxEnsureCapacity_creal_T(y, ihi);
    for (ihi = 0; ihi < nfft; ihi++) {
      y->data[ihi].re = 0.0;
      y->data[ihi].im = 0.0;
    }
  }
  emxInit_creal_T(&fy, 1);
  emxInit_creal_T(&fv, 1);
  if ((n2blue != 1) && ((nfft & 1) == 0)) {
    d_FFTImplementationCallback_doH(x, y, x->size[0], nfft, n2blue, wwc, costab,
                                    sintab, costab, sintabinv);
  } else {
    minNrowsNx = x->size[0];
    if (nfft < minNrowsNx) {
      minNrowsNx = nfft;
    }
    for (k = 0; k < minNrowsNx; k++) {
      nt_re_tmp = (nfft + k) - 1;
      y->data[k].re = wwc->data[nt_re_tmp].re * x->data[k];
      y->data[k].im = wwc->data[nt_re_tmp].im * -x->data[k];
    }
    ihi = minNrowsNx + 1;
    for (k = ihi; k <= nfft; k++) {
      y->data[k - 1].re = 0.0;
      y->data[k - 1].im = 0.0;
    }
    ihi = fy->size[0];
    fy->size[0] = n2blue;
    emxEnsureCapacity_creal_T(fy, ihi);
    if (n2blue > y->size[0]) {
      ihi = fy->size[0];
      fy->size[0] = n2blue;
      emxEnsureCapacity_creal_T(fy, ihi);
      for (ihi = 0; ihi < n2blue; ihi++) {
        fy->data[ihi].re = 0.0;
        fy->data[ihi].im = 0.0;
      }
    }
    nInt2m1 = y->size[0];
    if (nInt2m1 >= n2blue) {
      nInt2m1 = n2blue;
    }
    rt = n2blue - 2;
    nRowsD2 = n2blue / 2;
    k = nRowsD2 / 2;
    minNrowsNx = 0;
    nInt2 = 0;
    for (i = 0; i <= nInt2m1 - 2; i++) {
      fy->data[minNrowsNx] = y->data[i];
      minNrowsNx = n2blue;
      tst = true;
      while (tst) {
        minNrowsNx >>= 1;
        nInt2 ^= minNrowsNx;
        tst = ((nInt2 & minNrowsNx) == 0);
      }
      minNrowsNx = nInt2;
    }
    fy->data[minNrowsNx] = y->data[nInt2m1 - 1];
    if (n2blue > 1) {
      for (i = 0; i <= rt; i += 2) {
        nt_re = fy->data[i + 1].re;
        nt_im = fy->data[i + 1].im;
        twid_re = fy->data[i].re;
        twid_im = fy->data[i].im;
        fy->data[i + 1].re = fy->data[i].re - fy->data[i + 1].re;
        fy->data[i + 1].im = fy->data[i].im - fy->data[i + 1].im;
        twid_re += nt_re;
        twid_im += nt_im;
        fy->data[i].re = twid_re;
        fy->data[i].im = twid_im;
      }
    }
    minNrowsNx = 2;
    nInt2m1 = 4;
    rt = ((k - 1) << 2) + 1;
    while (k > 0) {
      for (i = 0; i < rt; i += nInt2m1) {
        nt_re_tmp = i + minNrowsNx;
        nt_re = fy->data[nt_re_tmp].re;
        nt_im = fy->data[nt_re_tmp].im;
        fy->data[nt_re_tmp].re = fy->data[i].re - nt_re;
        fy->data[nt_re_tmp].im = fy->data[i].im - nt_im;
        fy->data[i].re += nt_re;
        fy->data[i].im += nt_im;
      }
      nInt2 = 1;
      for (j = k; j < nRowsD2; j += k) {
        twid_re = costab->data[j];
        twid_im = sintab->data[j];
        i = nInt2;
        ihi = nInt2 + rt;
        while (i < ihi) {
          nt_re_tmp = i + minNrowsNx;
          nt_re = twid_re * fy->data[nt_re_tmp].re -
                  twid_im * fy->data[nt_re_tmp].im;
          nt_im = twid_re * fy->data[nt_re_tmp].im +
                  twid_im * fy->data[nt_re_tmp].re;
          fy->data[nt_re_tmp].re = fy->data[i].re - nt_re;
          fy->data[nt_re_tmp].im = fy->data[i].im - nt_im;
          fy->data[i].re += nt_re;
          fy->data[i].im += nt_im;
          i += nInt2m1;
        }
        nInt2++;
      }
      k /= 2;
      minNrowsNx = nInt2m1;
      nInt2m1 += nInt2m1;
      rt -= minNrowsNx;
    }
    c_FFTImplementationCallback_r2b(wwc, n2blue, costab, sintab, fv);
    minNrowsNx = fy->size[0];
    for (ihi = 0; ihi < minNrowsNx; ihi++) {
      twid_im = fy->data[ihi].re * fv->data[ihi].im +
                fy->data[ihi].im * fv->data[ihi].re;
      fy->data[ihi].re = fy->data[ihi].re * fv->data[ihi].re -
                         fy->data[ihi].im * fv->data[ihi].im;
      fy->data[ihi].im = twid_im;
    }
    c_FFTImplementationCallback_r2b(fy, n2blue, costab, sintabinv, fv);
    if (fv->size[0] > 1) {
      twid_re = 1.0 / (double)fv->size[0];
      minNrowsNx = fv->size[0];
      for (ihi = 0; ihi < minNrowsNx; ihi++) {
        fv->data[ihi].re *= twid_re;
        fv->data[ihi].im *= twid_re;
      }
    }
    ihi = wwc->size[0];
    for (k = nfft; k <= ihi; k++) {
      minNrowsNx = k - nfft;
      y->data[minNrowsNx].re = wwc->data[k - 1].re * fv->data[k - 1].re +
                               wwc->data[k - 1].im * fv->data[k - 1].im;
      y->data[minNrowsNx].im = wwc->data[k - 1].re * fv->data[k - 1].im -
                               wwc->data[k - 1].im * fv->data[k - 1].re;
    }
  }
  emxFree_creal_T(&fv);
  emxFree_creal_T(&fy);
  emxFree_creal_T(&wwc);
}

/* End of code generation (FFTImplementationCallback.c) */
