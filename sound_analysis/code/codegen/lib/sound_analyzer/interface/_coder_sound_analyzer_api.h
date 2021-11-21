/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_sound_analyzer_api.h
 *
 * Code generation for function 'sound_analyzer'
 *
 */

#ifndef _CODER_SOUND_ANALYZER_API_H
#define _CODER_SOUND_ANALYZER_API_H

/* Include files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
real_T sound_analyzer(real_T b_signal[11248640], real_T Fs, real_T frame_time,
                      real_T mask[256]);

void sound_analyzer_api(const mxArray *const prhs[4], const mxArray **plhs);

void sound_analyzer_atexit(void);

void sound_analyzer_initialize(void);

void sound_analyzer_terminate(void);

void sound_analyzer_xil_shutdown(void);

void sound_analyzer_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_sound_analyzer_api.h) */
