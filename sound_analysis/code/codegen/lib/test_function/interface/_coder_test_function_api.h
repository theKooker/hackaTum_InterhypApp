/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_test_function_api.h
 *
 * Code generation for function 'test_function'
 *
 */

#ifndef _CODER_TEST_FUNCTION_API_H
#define _CODER_TEST_FUNCTION_API_H

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
real_T test_function(real_T x, real_T y);

void test_function_api(const mxArray *const prhs[2], const mxArray **plhs);

void test_function_atexit(void);

void test_function_initialize(void);

void test_function_terminate(void);

void test_function_xil_shutdown(void);

void test_function_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_test_function_api.h) */
