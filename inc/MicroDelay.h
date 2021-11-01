#ifndef __MICRODELAY_H
#define __MICRODELAY_H

#include "main.h"

extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim7;

/*
  TIMER_CLOCK = 84000000Hz
  
  if PRESCALE = 4200
  RESULT_CLOCK = TIMER_CLOCK / PRESCALE = 20000Hz
  RESULT_TIME = 1 / RESULT_CLOCK = 0.00005s = 50us
  
  if PRESCALE = 84
  RESULT_CLOCK = TIMER_CLOCK / PRESCALE = 1000000Hz
  RESULT_TIME = 1 / RESULT_CLOCK = 0.0000001s = 1us
  
  if PRESCALE = 840
  RESULT_CLOCK = TIMER_CLOCK / PRESCALE = 100000Hz
  RESULT_TIME = 1 / RESULT_CLOCK = 0.000001s = 10us
*/

//Exported Macros -------------------------------------------------------------------------------
#define MicroDelay1_Init() HAL_TIM_Base_Start(&htim6)
#define MicroDelay1_Timer_Start() htim6.Instance->CNT = 0
#define MicroDelay1_Timer_GetElapsedTimeMicroSec() (htim6.Instance->CNT)
#define MicroDelay1_DelayUs(delay_us) htim6.Instance->CNT = 0; while((htim6.Instance->CNT) < (delay_us + 1)) {}

#define MicroDelay2_Init() HAL_TIM_Base_Start(&htim7)
#define MicroDelay2_Timer_Start() htim7.Instance->CNT = 0
#define MicroDelay2_Timer_GetElapsedTimeMicroSec() (htim7.Instance->CNT)
#define MicroDelay2_DelayUs(delay_us) htim7.Instance->CNT = 0; while((htim7.Instance->CNT) < (delay_us + 1)) {}
// Data Types -----------------------------------------------------------------------------------

// Exported Functions ---------------------------------------------------------------------------

#endif /* __MICRODELAY_H */
