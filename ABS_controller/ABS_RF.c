/*
 * ABS_RF.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ABS_RF".
 *
 * Model version              : 1.24
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Mon Mar  8 19:29:37 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ABS_RF.h"
#include "ABS_RF_private.h"

/* Block states (default storage) */
DW_ABS_RF_T ABS_RF_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ABS_RF_T ABS_RF_PrevZCX;

/* External inputs (root inport signals with default storage) */
ExtU_ABS_RF_T ABS_RF_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_ABS_RF_T ABS_RF_Y;

/* Real-time model */
RT_MODEL_ABS_RF_T ABS_RF_M_;
RT_MODEL_ABS_RF_T *const ABS_RF_M = &ABS_RF_M_;

/* Model output function */
static void ABS_RF_output(void)
{
  ZCEventType zcEvent;
  real_T rtb_Relay;

  /* Outputs for Triggered SubSystem: '<Root>/ABS_RF' incorporates:
   *  TriggerPort: '<S1>/Trigger'
   */
  /* Inport: '<Root>/Trigger' */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&ABS_RF_PrevZCX.ABS_RF_Trig_ZCE,
                     (ABS_RF_U.Trigger));
  if (zcEvent != NO_ZCEVENT) {
    /* Gain: '<S1>/Gain' incorporates:
     *  Inport: '<Root>/slip'
     */
    rtb_Relay = ABS_RF_P.Gain_Gain * ABS_RF_U.slip;

    /* Relay: '<S1>/Relay' */
    ABS_RF_DW.Relay_Mode = ((rtb_Relay >= ABS_RF_P.Relay_OnVal) || ((!(rtb_Relay
      <= ABS_RF_P.Relay_OffVal)) && ABS_RF_DW.Relay_Mode));
    if (ABS_RF_DW.Relay_Mode) {
      rtb_Relay = ABS_RF_P.Relay_YOn;
    } else {
      rtb_Relay = ABS_RF_P.Relay_YOff;
    }

    /* End of Relay: '<S1>/Relay' */

    /* Switch: '<S1>/Switch' */
    if (rtb_Relay > ABS_RF_P.Switch_Threshold) {
      /* Outport: '<Root>/T_brake' incorporates:
       *  Inport: '<Root>/Pmcc'
       */
      ABS_RF_Y.T_brake = ABS_RF_U.Pmcc;
    } else {
      /* Outport: '<Root>/T_brake' incorporates:
       *  Constant: '<S1>/Constant'
       */
      ABS_RF_Y.T_brake = ABS_RF_P.Constant_Value;
    }

    /* End of Switch: '<S1>/Switch' */
  }

  /* End of Outputs for SubSystem: '<Root>/ABS_RF' */
}

/* Model update function */
static void ABS_RF_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ABS_RF_M->Timing.clockTick0)) {
    ++ABS_RF_M->Timing.clockTickH0;
  }

  ABS_RF_M->Timing.t[0] = ABS_RF_M->Timing.clockTick0 *
    ABS_RF_M->Timing.stepSize0 + ABS_RF_M->Timing.clockTickH0 *
    ABS_RF_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void ABS_RF_initialize(void)
{
  ABS_RF_PrevZCX.ABS_RF_Trig_ZCE = UNINITIALIZED_ZCSIG;
}

/* Model terminate function */
static void ABS_RF_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  ABS_RF_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ABS_RF_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  ABS_RF_initialize();
}

void MdlTerminate(void)
{
  ABS_RF_terminate();
}

/* Registration function */
RT_MODEL_ABS_RF_T *ABS_RF(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ABS_RF_M, 0,
                sizeof(RT_MODEL_ABS_RF_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ABS_RF_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    ABS_RF_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ABS_RF_M->Timing.sampleTimes = (&ABS_RF_M->Timing.sampleTimesArray[0]);
    ABS_RF_M->Timing.offsetTimes = (&ABS_RF_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ABS_RF_M->Timing.sampleTimes[0] = (0.08);

    /* task offsets */
    ABS_RF_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(ABS_RF_M, &ABS_RF_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ABS_RF_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    ABS_RF_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ABS_RF_M, 4.0);
  ABS_RF_M->Timing.stepSize0 = 0.08;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    ABS_RF_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ABS_RF_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ABS_RF_M->rtwLogInfo, (NULL));
    rtliSetLogT(ABS_RF_M->rtwLogInfo, "tout");
    rtliSetLogX(ABS_RF_M->rtwLogInfo, "");
    rtliSetLogXFinal(ABS_RF_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ABS_RF_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ABS_RF_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ABS_RF_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ABS_RF_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &ABS_RF_Y.T_brake
      };

      rtliSetLogYSignalPtrs(ABS_RF_M->rtwLogInfo, ((LogSignalPtrsType)
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
        "ABS_RF/T_brake" };

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

      rtliSetLogYSignalInfo(ABS_RF_M->rtwLogInfo, rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
    }

    rtliSetLogY(ABS_RF_M->rtwLogInfo, "yout");
  }

  ABS_RF_M->solverInfoPtr = (&ABS_RF_M->solverInfo);
  ABS_RF_M->Timing.stepSize = (0.08);
  rtsiSetFixedStepSize(&ABS_RF_M->solverInfo, 0.08);
  rtsiSetSolverMode(&ABS_RF_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* parameters */
  ABS_RF_M->defaultParam = ((real_T *)&ABS_RF_P);

  /* states (dwork) */
  ABS_RF_M->dwork = ((void *) &ABS_RF_DW);
  (void) memset((void *)&ABS_RF_DW, 0,
                sizeof(DW_ABS_RF_T));

  /* external inputs */
  ABS_RF_M->inputs = (((void*)&ABS_RF_U));
  ABS_RF_U.Pmcc = 0.0;
  ABS_RF_U.slip = 0.0;
  ABS_RF_U.Trigger = 0.0;

  /* external outputs */
  ABS_RF_M->outputs = (&ABS_RF_Y);
  ABS_RF_Y.T_brake = 0.0;

  /* Initialize Sizes */
  ABS_RF_M->Sizes.numContStates = (0); /* Number of continuous states */
  ABS_RF_M->Sizes.numY = (1);          /* Number of model outputs */
  ABS_RF_M->Sizes.numU = (3);          /* Number of model inputs */
  ABS_RF_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  ABS_RF_M->Sizes.numSampTimes = (1);  /* Number of sample times */
  ABS_RF_M->Sizes.numBlocks = (7);     /* Number of blocks */
  ABS_RF_M->Sizes.numBlockIO = (1);    /* Number of block outputs */
  ABS_RF_M->Sizes.numBlockPrms = (7);  /* Sum of parameter "widths" */
  return ABS_RF_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
