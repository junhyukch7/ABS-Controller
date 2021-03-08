/*
 * ABS0.cpp
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

#include "ABS0.h"
#include "ABS0_private.h"

/* Model step function */
void ABS0ModelClass::step()
{
  ZCEventType zcEvent;
  real_T rtb_Relay;

  /* Outputs for Triggered SubSystem: '<Root>/ABS' incorporates:
   *  TriggerPort: '<S1>/Trigger'
   */
  /* Inport: '<Root>/Trigger' */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&ABS0_PrevZCX.ABS_Trig_ZCE,
                     (ABS0_U.Trigger));
  if (zcEvent != NO_ZCEVENT) {
    /* Gain: '<S1>/Gain' incorporates:
     *  Inport: '<Root>/slip'
     */
    rtb_Relay = ABS0_P.Gain_Gain * ABS0_U.slip;

    /* Relay: '<S1>/Relay' */
    ABS0_DW.Relay_Mode = ((rtb_Relay >= ABS0_P.Relay_OnVal) || ((!(rtb_Relay <=
      ABS0_P.Relay_OffVal)) && ABS0_DW.Relay_Mode));
    if (ABS0_DW.Relay_Mode) {
      rtb_Relay = ABS0_P.Relay_YOn;
    } else {
      rtb_Relay = ABS0_P.Relay_YOff;
    }

    /* End of Relay: '<S1>/Relay' */

    /* Switch: '<S1>/Switch' */
    if (rtb_Relay > ABS0_P.Switch_Threshold) {
      /* Outport: '<Root>/T_brake' incorporates:
       *  Inport: '<Root>/Pmcc'
       */
      ABS0_Y.T_brake = ABS0_U.Pmcc;
    } else {
      /* Outport: '<Root>/T_brake' incorporates:
       *  Constant: '<S1>/Constant'
       */
      ABS0_Y.T_brake = ABS0_P.Constant_Value;
    }

    /* End of Switch: '<S1>/Switch' */
  }

  /* End of Outputs for SubSystem: '<Root>/ABS' */

  /* Matfile logging */
  rt_UpdateTXYLogVars((&ABS0_M)->rtwLogInfo, (&(&ABS0_M)->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.08s, 0.0s] */
    if ((rtmGetTFinal((&ABS0_M))!=-1) &&
        !((rtmGetTFinal((&ABS0_M))-(&ABS0_M)->Timing.taskTime0) > (&ABS0_M)
          ->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus((&ABS0_M), "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++(&ABS0_M)->Timing.clockTick0)) {
    ++(&ABS0_M)->Timing.clockTickH0;
  }

  (&ABS0_M)->Timing.taskTime0 = (&ABS0_M)->Timing.clockTick0 * (&ABS0_M)
    ->Timing.stepSize0 + (&ABS0_M)->Timing.clockTickH0 * (&ABS0_M)
    ->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void ABS0ModelClass::initialize()
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal((&ABS0_M), 4.0);
  (&ABS0_M)->Timing.stepSize0 = 0.08;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    (&ABS0_M)->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo((&ABS0_M)->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs((&ABS0_M)->rtwLogInfo, (NULL));
    rtliSetLogT((&ABS0_M)->rtwLogInfo, "tout");
    rtliSetLogX((&ABS0_M)->rtwLogInfo, "");
    rtliSetLogXFinal((&ABS0_M)->rtwLogInfo, "");
    rtliSetLogVarNameModifier((&ABS0_M)->rtwLogInfo, "rt_");
    rtliSetLogFormat((&ABS0_M)->rtwLogInfo, 0);
    rtliSetLogMaxRows((&ABS0_M)->rtwLogInfo, 1000);
    rtliSetLogDecimation((&ABS0_M)->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[1];
      rt_LoggedOutputSignalPtrs[0] = &ABS0_Y.T_brake;
      rtliSetLogYSignalPtrs((&ABS0_M)->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0
      };

      static RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs[] = {
        (NULL)
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "ABS0/T_brake" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          1,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),
          rt_LoggingPreprocessingFcnPtrs,

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo((&ABS0_M)->rtwLogInfo, rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
    }

    rtliSetLogY((&ABS0_M)->rtwLogInfo, "yout");
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime((&ABS0_M)->rtwLogInfo, 0.0, rtmGetTFinal
    ((&ABS0_M)), (&ABS0_M)->Timing.stepSize0, (&rtmGetErrorStatus((&ABS0_M))));
  ABS0_PrevZCX.ABS_Trig_ZCE = UNINITIALIZED_ZCSIG;
}

/* Model terminate function */
void ABS0ModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
ABS0ModelClass::ABS0ModelClass():
  ABS0_DW()
  ,ABS0_PrevZCX()
  ,ABS0_U()
  ,ABS0_Y()
  ,ABS0_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
ABS0ModelClass::~ABS0ModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_ABS0_T * ABS0ModelClass::getRTM()
{
  return (&ABS0_M);
}
