#include "los_bsp_uart.h"
#include <stdarg.h>

#ifdef LOS_STM32F407VG
UART_HandleTypeDef UartHandle;
void Error_Handler(void)
{
  /* Turn LED4 on */
  BSP_LED_On(LED4);
  while(1)
  {
  }
}
#endif

void LOS_EvbUartInit(void)
{
#ifdef LOS_STM32F407VG
  UartHandle.Instance          = USARTx;
  
  UartHandle.Init.BaudRate     = 9600;
  UartHandle.Init.WordLength   = UART_WORDLENGTH_8B;
  UartHandle.Init.StopBits     = UART_STOPBITS_1;
  UartHandle.Init.Parity       = UART_PARITY_NONE;
  UartHandle.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
  UartHandle.Init.Mode         = UART_MODE_TX_RX;
  UartHandle.Init.OverSampling = UART_OVERSAMPLING_16;
    
  if(HAL_UART_Init(&UartHandle) != HAL_OK)
  {
    Error_Handler();
  }
	
//	 BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
#endif
	
	return ;
}


/*************************************************************************************************
 *  ���ܣ��򴮿�1����һ���ַ�                                                                    *
 *  ������(1) ��Ҫ�����͵��ַ�                                                                   *
 *  ���أ�                                                                                       *
 *  ˵����                                                                                       *
 *************************************************************************************************/
void LOS_EvbUartWriteByte(char c)
{
#ifdef LOS_STM32F407VG
	if(HAL_UART_Transmit(&UartHandle, (uint8_t*)&c, 1, 5000)!= HAL_OK)
	{
		Error_Handler();   
	}
#endif
	return ;
}

/*************************************************************************************************
 *  ���ܣ��򴮿�1����һ���ַ���                                                                  *
 *  ������(1) ��Ҫ�����͵��ַ���                                                                 *
 *  ���أ�                                                                                       *
 *  ˵����                                                                                       *
 *************************************************************************************************/
void LOS_EvbUartWriteStr(const char* str)
{
#ifdef LOS_STM32F407VG
    while (*str)
    {
			if(HAL_UART_Transmit(&UartHandle, (uint8_t*)str, 1, 5000)!= HAL_OK)
			{
				Error_Handler();   
			}
			str++;
    }
#endif
	return ;
}


/*************************************************************************************************
 *  ���ܣ��Ӵ���1����һ���ַ�                                                                    *
 *  ������(1) �洢���յ����ַ�                                                                   *
 *  ���أ�                                                                                       *
 *  ˵����                                                                                       *
 *************************************************************************************************/
void LOS_EvbUartReadByte(char* c)
{
#ifdef LOS_STM32F407VG
	if(HAL_UART_Receive(&UartHandle, (uint8_t *)c, 1, 5000) != HAL_OK)
	{
		Error_Handler();  
	}
#endif
	return ;
}

#ifdef LOS_STM32F407VG
static char _buffer[128];
#endif
void LOS_EvbUartPrintf(char* fmt, ...)
{
#ifdef LOS_STM32F407VG
    int i;
    va_list ap;
    va_start(ap, fmt);
    vsprintf(_buffer, fmt, ap);
    va_end(ap);

    for (i = 0; _buffer[i] != '\0'; i++)
    {
        LOS_EvbUartWriteByte(_buffer[i]);
    }
#endif
	return ;
}