/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/


  uint8_t One_seconde=1;
  
__IO uint32_t Nber_Transfer_CPU = 0;
__IO uint32_t Nber_Transfer_DMA = 0;



const uint32_t SRC_Const_Buffer[64]= {
                                    0x01020304,0x05060708,0x090A0B0C,0x0D0E0F10,
                                    0x11121314,0x15161718,0x191A1B1C,0x1D1E1F20,
                                    0x21222324,0x25262728,0x292A2B2C,0x2D2E2F30,
                                    0x31323334,0x35363738,0x393A3B3C,0x3D3E3F40,
                                    0x41424344,0x45464748,0x494A4B4C,0x4D4E4F50,
                                    0x51525354,0x55565758,0x595A5B5C,0x5D5E5F60,
                                    0x61626364,0x65666768,0x696A6B6C,0x6D6E6F70,
                                    0x71727374,0x75767778,0x797A7B7C,0x7D7E7F80,
                                    0x01020304,0x05060708,0x090A0B0C,0x0D0E0F10,
                                    0x11121314,0x15161718,0x191A1B1C,0x1D1E1F20,
                                    0x21222324,0x25262728,0x292A2B2C,0x2D2E2F30,
                                    0x31323334,0x35363738,0x393A3B3C,0x3D3E3F40,
                                    0x41424344,0x45464748,0x494A4B4C,0x4D4E4F50,
                                    0x51525354,0x55565758,0x595A5B5C,0x5D5E5F60,
                                    0x61626364,0x65666768,0x696A6B6C,0x6D6E6F70,
                                    0x71727374,0x75767778,0x797A7B7C,0x7D7E7F80};
uint32_t DST_Buffer[64];



    
/* Private functions ---------------------------------------------------------*/
void RCC_Configuration(void);


int main(void)
{
       
  /* System Clocks Configuration */
  RCC_Configuration();
       
  // Lancer le chrono (1 seconde) en utilisant Systick
  ...........

  while (1)       
  
  {
     while (One_seconde==1)
     {
       for(int i=0;i<64;i++)
       {
        // effectuer un transfert de SRC_Const_Buffer vers DST_Buffer
		.............................
         
       }
       Nber_Transfer_CPU++; // Incrémenter le nombre de cycles de transferts
     }
     
  }

}


void RCC_Configuration(void)
{
  /* Enable peripheral clocks ------------------------------------------------*/
  /* Enable DMA1 clock */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

}




