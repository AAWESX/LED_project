#include "Oscilloscope.h"


void Osc_TFT_Windows(void)
{
    LCD_Clear(BLACK);
    HAL_GPIO_WritePin(LCD_BL_GPIO_Port, LCD_BL_Pin, GPIO_PIN_SET);
    uint8_t   lcd_id[12];      //存放 LCD ID 字符串
    uint8_t   lcd_width[18];   //存放 LCD 宽度 字符串
    uint8_t   lcd_height[18];  //存放 LCD 高度 字符串
    
    sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id);         //将 LCD ID   打印到 lcd_id 数组
    sprintf((char*)lcd_width,"LCD width:%d",(int)lcddev.width);   //将 LCD 宽度 打印到 lcd_width 数组
    sprintf((char*)lcd_height,"LCD height:%d",(int)lcddev.height); //将 LCD 高度 打印到 lcd_height 数组
    
    //Windows 框图
    POINT_COLOR=RED;    //设置字体颜色为红色
    LCD_ArrangedHoriDashed(20,450,0,700);//横虚线排列
    LCD_ArrangedDashed(0,700 ,20,450);//纵虚线排列 
    POINT_COLOR=WHITE;  //设置字体颜色为白色
    LCD_DrawRectangle(0,20,700,450);  //矩形
    LCD_CrossShape(235,235,350,350);  //十字型
    //Windows 框图

    POINT_COLOR=GREEN; //设置字体颜色为绿色
     //顶部显示测试
    LCD_ShowString(0  ,0,200,16,16,lcd_id);     //显示LCD_ID
    LCD_ShowString(100,0,200,16,16,lcd_width);  //显示LCD_width
    LCD_ShowString(250,0,200,16,16,lcd_height); //显示LCD_height
    //底部显示测试
    LCD_ShowString(0  ,460,200,16,16,lcd_id);     //显示LCD_ID
    LCD_ShowString(100,460,200,16,16,lcd_width);  //显示LCD_width
    LCD_ShowString(250,460,200,16,16,lcd_height); //显示LCD_height
}






