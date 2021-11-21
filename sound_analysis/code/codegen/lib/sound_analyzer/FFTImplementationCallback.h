/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * FFTImplementationCallback.h
 *
 * Code generation for function 'FFTImplementationCallback'
 *
 */

#ifndef FFTIMPLEMENTATIONCALLBACK_H
#define FFTIMPLEMENTATIONCALLBACK_H

/* Include files */
#include "rtwtypes.h"
#include "sound_analyzer_types.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void c_FFTImplementationCallback_doH(const emxArray_real_T *x,
                                     emxArray_creal_T *y, int unsigned_nRows,
                                     const emxArray_real_T *costab,
                                     const emxArray_real_T *sintab);

void c_FFTImplementationCallback_dob(const emxArray_real_T *x, int n2blue,
                                     int nfft, const emxArray_real_T *costab,
                                     const emxArray_real_T *sintab,
                                     const emxArray_real_T *sintabinv,
                                     emxArray_creal_T *y);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (FFTImplementationCallback.h) */
