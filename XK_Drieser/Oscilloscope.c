#include "Oscilloscope.h"


void Osc_TFT_Windows(void)
{
    LCD_Clear(BLACK);
    HAL_GPIO_WritePin(LCD_BL_GPIO_Port, LCD_BL_Pin, GPIO_PIN_SET);
    uint8_t   lcd_id[12];      //��� LCD ID �ַ���
    uint8_t   lcd_width[18];   //��� LCD ��� �ַ���
    uint8_t   lcd_height[18];  //��� LCD �߶� �ַ���
    
    sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id);         //�� LCD ID   ��ӡ�� lcd_id ����
    sprintf((char*)lcd_width,"LCD width:%d",(int)lcddev.width);   //�� LCD ��� ��ӡ�� lcd_width ����
    sprintf((char*)lcd_height,"LCD height:%d",(int)lcddev.height); //�� LCD �߶� ��ӡ�� lcd_height ����
    
    //Windows ��ͼ
    POINT_COLOR=RED;    //����������ɫΪ��ɫ
    LCD_ArrangedHoriDashed(20,450,0,700);//����������
    LCD_ArrangedDashed(0,700 ,20,450);//���������� 
    POINT_COLOR=WHITE;  //����������ɫΪ��ɫ
    LCD_DrawRectangle(0,20,700,450);  //����
    LCD_CrossShape(235,235,350,350);  //ʮ����
    //Windows ��ͼ

    POINT_COLOR=GREEN; //����������ɫΪ��ɫ
     //������ʾ����
    LCD_ShowString(0  ,0,200,16,16,lcd_id);     //��ʾLCD_ID
    LCD_ShowString(100,0,200,16,16,lcd_width);  //��ʾLCD_width
    LCD_ShowString(250,0,200,16,16,lcd_height); //��ʾLCD_height
    //�ײ���ʾ����
    LCD_ShowString(0  ,460,200,16,16,lcd_id);     //��ʾLCD_ID
    LCD_ShowString(100,460,200,16,16,lcd_width);  //��ʾLCD_width
    LCD_ShowString(250,460,200,16,16,lcd_height); //��ʾLCD_height
}






