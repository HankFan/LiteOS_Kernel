#ifndef _LOS_BSP_ADAPTER_H
#define _LOS_BSP_ADAPTER_H

#include <stdio.h>
#include <string.h>

#include "stm32f4xx_it.h"

extern void LOS_EvbSetup(void);
extern void LOS_EvbTrace(const char *str);
void SystemClock_Config(void);

#endif
