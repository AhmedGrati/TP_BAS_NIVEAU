/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

/* Private define ------------------------------------------------------------*/
#define BufferSize  32

/* Private variables ---------------------------------------------------------*/
DMA_InitTypeDef  DMA_InitStructure;

uint16_t appui;

__IO uint32_t NumberOfTransferCyclesCPU = 0;

__IO uint32_t NumberOfTransferCyclesDMA = 0;


const uint32_t SRC_Const_Buffer[BufferSize]= {
                                    0x01020304,0x05060708,0x090A0B0C,0x0D0E0F10,
                                    0x11121314,0x15161718,0x191A1B1C,0x1D1E1F20,
                                    0x21222324,0x25262728,0x292A2B2C,0x2D2E2F30,
                                    0x31323334,0x35363738,0x393A3B3C,0x3D3E3F40,
                                    0x41424344,0x45464748,0x494A4B4C,0x4D4E4F50,
                                    0x51525354,0x55565758,0x595A5B5C,0x5D5E5F60,
                                    0x61626364,0x65666768,0x696A6B6C,0x6D6E6F70,
                                    0x71727374,0x75767778,0x797A7B7C,0x7D7E7F80};
uint32_t DST_Buffer[BufferSize];

/* Private function prototypes -----------------------------------------------*/
void RCC_Configuration(void);
void NVIC_Configuration(void);

    
/* Private functions ---------------------------------------------------------*/

int main(void)
{
       
  /* System Clocks Configuration */
  RCC_Configuration();
       
  /* NVIC configuration */
  NVIC_Configuration();
 


  /* DMA1 channel6 configuration */
  /* DMA1 channel6 configuration */
  DMA_DeInit(DMA1_Channel6);
  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)SRC_Const_Buffer;
  DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)DST_Buffer;
  DMA_InitStructure.DMA_DIR = ...............;
  DMA_InitStructure.DMA_BufferSize = ..............;
  DMA_InitStructure.DMA_PeripheralInc = ...............;
  DMA_InitStructure.DMA_MemoryInc = ................;
  DMA_InitStructure.DMA_PeripheralDataSize = ................;
  DMA_InitStructure.DMA_MemoryDataSize = ......................;
  DMA_InitStructure.DMA_Mode = ................;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_M2M = ..............;
  DMA_Init(DMA1_Channel6, &DMA_InitStructure);

  /* Enable DMA1 Channel6 Transfer Complete interrupt */
  DMA_ITConfig(DMA1_Channel6, ............., ENABLE);


  /* Enable DMA1 Channel6 transfer */
  DMA_Cmd(DMA1_Channel6, ENABLE);

  /* Code a Insérer : quand on appuie sur le BP, on évalue le nombre de cycles de transferts effectués */


  while (1)   
    
    
  {
                              // effectuer un transfert de SRC_Const_Buffer vers DST_Buffer

                              // Incrémenter le nombre de cycles de transferts
  }
  
    


}





void RCC_Configuration(void)
{
  /* Enable peripheral clocks ------------------------------------------------*/
  /* Enable DMA1 clock */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
   RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA, ENABLE);
}

void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
  /* Enable DMA1 channel6 IRQ Channel */
  NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel6_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}

