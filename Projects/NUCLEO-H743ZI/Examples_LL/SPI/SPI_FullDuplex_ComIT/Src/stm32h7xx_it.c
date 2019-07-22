/**
  ******************************************************************************
  * @file    SPI_FullDuplex_ComIT/Src/stm32h7xx_it.c
  * @author  MCD Application Team
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_it.h"
#include "main.h"

/** @addtogroup STM32H7xx_LL_Examples
  * @{
  */

/** @addtogroup SPI_FullDuplex_ComIT
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M7 Processor Exceptions Handlers                         */
/******************************************************************************/


/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}


/******************************************************************************/
/*                 STM32H7xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32h7xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles SPI1 interrupt request.
  * @param  None
  * @retval None
  */
void SPI1_IRQHandler(void)
{

    /* Check OVR/UDR flag value in ISR register */
    if(LL_SPI_IsActiveFlag_OVR(SPI1) || LL_SPI_IsActiveFlag_UDR(SPI1))
    {
      /* Call Error function */
      SPI_TransferError_Callback();
    }
    /* Check RXP flag value in ISR register */
    if(LL_SPI_IsActiveFlag_RXP(SPI1) && LL_SPI_IsEnabledIT_RXP(SPI1))
    {
      /* Call function Reception Callback */
      SPI1_Rx_Callback();
      return;
    }
    /* Check TXP flag value in ISR register */
    if((LL_SPI_IsActiveFlag_TXP(SPI1) && LL_SPI_IsEnabledIT_TXP(SPI1)))
    {
      /* Call function Reception Callback */
      SPI1_Tx_Callback();
      return;
    }
    /* Check EOT flag value in ISR register */
    if(LL_SPI_IsActiveFlag_EOT(SPI1) && LL_SPI_IsEnabledIT_EOT(SPI1))
    {
      /* Call function Reception Callback */
      SPI1_EOT_Callback();
      return;
    }
}

/**
  * @brief  This function handles SPI4 interrupt request.
  * @param  None
  * @retval None
  */
void SPI4_IRQHandler(void)
{
    /* Check OVR/UDR flag value in ISR register */
    if(LL_SPI_IsActiveFlag_OVR(SPI4) || LL_SPI_IsActiveFlag_UDR(SPI4))
    {
      /* Call Error function */
      SPI_TransferError_Callback();
    }
    /* Check RXP flag value in ISR register */
    if(LL_SPI_IsActiveFlag_RXP(SPI4) && LL_SPI_IsEnabledIT_RXP(SPI4))
    {
      /* Call function Reception Callback */
      SPI4_Rx_Callback();
      return;
    }
    /* Check TXP flag value in ISR register */
    if((LL_SPI_IsActiveFlag_TXP(SPI4) && LL_SPI_IsEnabledIT_TXP(SPI4)))
    {
      /* Call function Reception Callback */
      SPI4_Tx_Callback();
      return;
    }
    /* Check EOT flag value in ISR register */
    if(LL_SPI_IsActiveFlag_EOT(SPI4) && LL_SPI_IsEnabledIT_EOT(SPI4))
    {
      /* Call function Reception Callback */
      SPI4_EOT_Callback();
      return;
    }

}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/