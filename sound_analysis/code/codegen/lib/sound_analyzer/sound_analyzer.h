/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sound_analyzer.h
 *
 * Code generation for function 'sound_analyzer'
 *
 */

#ifndef SOUND_ANALYZER_H
#define SOUND_ANALYZER_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern double sound_analyzer(double b_signal[11248640], double Fs,
                             double frame_time, const double mask[256]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (sound_analyzer.h) */
