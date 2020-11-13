
// Interrupts EXTI Project

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

/* Private typedef -----------------------------------------------------------*/
GPIO_InitTypeDef GPIO_InitStructure;
...............   .................; //EXTI
...............   .................; // NVIC
 
/* Private functions ---------------------------------------------------------*/
void Delay(vu32 nCount);

u8 i;
  
int main(void)
{

  
/* Activer les horloges des ports utilisés */
  
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC, ENABLE);

	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO , ENABLE);

 /* Configure PC.08 and PC.09 as Output push-pull */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  /* Configure PA.00 as Input push-pull */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;; //PD;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
 
  
      /* Connect Button EXTI Line to Button GPIO Pin */
     GPIO_EXTILineConfig(................., ................);

    /* Configure Button EXTI line */
   EXTI_InitStructure.EXTI_Line = ..........;
   EXTI_InitStructure.EXTI_Mode = ...........;
   EXTI_InitStructure.EXTI_Trigger = .............;  
   EXTI_InitStructure.EXTI_LineCmd = ENABLE;
   EXTI_Init(....................);


   /* Enable and set Button EXTI Interrupt to the lowest priority */

   NVIC_InitStructure.NVIC_IRQChannel = ........;
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
   NVIC_InitStructure.NVIC_IRQChannelCmd = ........;
   NVIC_Init(..................);
    

    /* Turn on led connected to PB.08 pin */
    GPIO_SetBits(GPIOC, GPIO_Pin_8|GPIO_Pin_9);
    /* Insert delay */
    Delay(0xFFFFF);

   
  /* Infinite loop */
  while (1)  
    { 
      GPIO_ResetBits(GPIOC, GPIO_Pin_8|GPIO_Pin_9);
      }
}

/******************** Function Name  : Delay**************************/
void Delay(vu32 nCount)
{  for(; nCount != 0; nCount--);}
