#include "ADC_Osc.h"
#include "adc.h"
#include <stdlib.h>
#include <string.h>

uint16_t ADC_BUFF[700];

void OS_ADC_DMA(void)
{
    HAL_ADC_Start_DMA(&hadc1,(uint32_t *)ADC_BUFF,700);
}

uint32_t OS_ADC_Config(void)
{
    uint32_t adc = 0;
    
    LCD_Fill(0,20,700,450,BLACK);
    
    for(int i = 0; i < 700; i ++)
    {
        adc += ADC_BUFF[i];
        POINT_COLOR=BLUE;
        LCD_DrawLine(i,235 - ADC_BUFF[i]/(4096/100),i+1,235 -ADC_BUFF[i+1]/(4096/100));
    }
    adc /= 700;
    return adc;
}

/**
  * @brief  Conversion complete callback in non blocking mode 
  * @param  hadc: ADC handle
  * @retval None
  */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);
  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_ConvCpltCallback must be implemented in the user file.
   */
    uint8_t ADC_DATA[10];
    uint32_t adc;
  if(hadc == &hadc1)
  {
      adc = OS_ADC_Config();
  }
  HAL_GPIO_TogglePin(LED_DEBUG_GPIO_Port,LED_DEBUG_Pin);
  sprintf((char*)ADC_DATA,"ADC:%.4fV",adc*3.3/4096); //将 LCD 高度 打印到 lcd_height 数组
  LCD_ShowString(600,0,200,16,16,ADC_DATA);     //显示LCD_ID

}

