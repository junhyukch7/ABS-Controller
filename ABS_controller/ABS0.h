/*
 * ABS0.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ABS0".
 *
 * Model version              : 1.24
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Mon Mar  8 19:47:34 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ABS0_h_
#define RTW_HEADER_ABS0_h_
#include <cfloat>
#include <stddef.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "ABS0_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  boolean_T Relay_Mode;                /* '<S1>/Relay' */
} DW_ABS0_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState ABS_Trig_ZCE;             /* '<Root>/ABS' */
} PrevZCX_ABS0_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Pmcc;                         /* '<Root>/Pmcc' */
  real_T slip;                         /* '<Root>/slip' */
  real_T Trigger;                      /* '<Root>/Trigger' */
} ExtU_ABS0_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T T_brake;                      /* '<Root>/T_brake' */
} ExtY_ABS0_T;

/* Parameters (default storage) */
struct P_ABS0_T_ {
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Relay_OnVal;                  /* Expression: 0.2
                                        * Referenced by: '<S1>/Relay'
                                        */
  real_T Relay_OffVal;                 /* Expression: 0.1
                                        * Referenced by: '<S1>/Relay'
                                        */
  real_T Relay_YOn;                    /* Expression: 0
                                        * Referenced by: '<S1>/Relay'
                                        */
  real_T Relay_YOff;                   /* Expression: 1
                                        * Referenced by: '<S1>/Relay'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S1>/Switch'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ABS0_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Class declaration for model ABS0 */
class ABS0ModelClass {
  /* public data and function members */
 public:
  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  ABS0ModelClass();

  /* Destructor */
  ~ABS0ModelClass();

  /* Root-level structure-based inputs set method */

  /* Root inports set method */
  void setExternalInputs(const ExtU_ABS0_T* pExtU_ABS0_T)
  {
    ABS0_U = *pExtU_ABS0_T;
  }

  /* Root-level structure-based outputs get method */

  /* Root outports get method */
  const ExtY_ABS0_T & getExternalOutputs() const
  {
    return ABS0_Y;
  }

  /* Real-Time Model get method */
  RT_MODEL_ABS0_T * getRTM();

  /* private data and function members */
 private:
  /* Tunable parameters */
  static P_ABS0_T ABS0_P;

  /* Block states */
  DW_ABS0_T ABS0_DW;
  PrevZCX_ABS0_T ABS0_PrevZCX;         /* Triggered events */

  /* External inputs */
  ExtU_ABS0_T ABS0_U;

  /* External outputs */
  ExtY_ABS0_T ABS0_Y;

  /* Real-Time Model */
  RT_MODEL_ABS0_T ABS0_M;
};

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('longitudinal_model_abs/Vehicle Model/Wheel Dynamics/ABS')    - opens subsystem longitudinal_model_abs/Vehicle Model/Wheel Dynamics/ABS
 * hilite_system('longitudinal_model_abs/Vehicle Model/Wheel Dynamics/ABS/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'longitudinal_model_abs/Vehicle Model/Wheel Dynamics'
 * '<S1>'   : 'longitudinal_model_abs/Vehicle Model/Wheel Dynamics/ABS'
 */
#endif                                 /* RTW_HEADER_ABS0_h_ */
