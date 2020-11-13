
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

/*----------------- Déclaration des structures relatives aux periphs utilisés ---------------*/
GPIO_InitTypeDef  GPIO_InitStructure;

/* ---------------Private functions ---------------*/
void Delay(vu32 nCount);

uint16_t appui; // variable appui pour lire l'etat du bouton

int main(void)
{ /*---------- Activer les horloges des ports utilsés (port A et port C)------------ */ 
 ...................... (........................................., .........);

/*-------------- Configure the GPIO_LED pin -----------------*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

/*-------------- Configure the GPIO_ Pushbutton pin -----------------*/
  GPIO_InitStructure.GPIO_Pin = ........;
  GPIO_InitStructure.GPIO_Mode = ............... ; // IN Floating
  GPIO_Init(......,...............);

  
/* ---------  Led PC8 ON, Led PC9 OFF ---------- */
GPIO_SetBits(GPIO_Pin_8);
GPIO_ResetBits(GPIO_Pin_9);


while (1)
 	 {
appui = ............................(GPIOA,..........); 

if(appui)	         {
 GPIO_ToggleBits(GPIOC,GPIO_Pin_8|GPIO_Pin_9);
 Delay (0xFF);
  	          }

          }
   }
/*******************************************************************************
* Function Name  : Delay
* Description    : Inserts a delay time.
* Input          : nCount: specifies the delay time length.
*******************************************************************************/
void Delay(vu32 nCount)
{
  for(; nCount != 0; nCount--);
}
