/*
*********************************************************************************************************
*
*	模块名称 : LED指示灯驱动模块
*	文件名称 : bsp_led.c
*	版    本 : V1.0
*	说    明 : 驱动LED指示灯
*
*
*
*********************************************************************************************************
*/

#include "bsp_led.h"

/*
STM32H7板载两颗LED灯
LED0 PB0
LED1 PB1
*/

/*
*********************************************************************************************************
*	函 数 名: bsp_InitLed
*	功能说明: 配置LED指示灯相关的GPIO,  该函数被 bsp_Init() 调用。
*	形    参:  无
*	返 回 值: 无
*********************************************************************************************************
*/
void BSP_LED_Init(void)
{
	GPIO_InitTypeDef GPIO_Initure;
	__HAL_RCC_GPIOB_CLK_ENABLE(); //开启GPIOB时钟

	GPIO_Initure.Pin = GPIO_PIN_0 | GPIO_PIN_1;		//PB0，1
	GPIO_Initure.Mode = GPIO_MODE_OUTPUT_PP;		//推挽输出
	GPIO_Initure.Pull = GPIO_PULLUP;				//上拉
	GPIO_Initure.Speed = GPIO_SPEED_FREQ_VERY_HIGH; //高速
	HAL_GPIO_Init(GPIOB, &GPIO_Initure);			//初始化GPIOB.0和GPIOB.1

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET); //PB0置0
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET); //PB1置1

	BSP_LED_OFF(1);
	BSP_LED_OFF(2);
}

/*
*********************************************************************************************************
*	函 数 名: bsp_LedOn
*	功能说明: 点亮指定的LED指示灯。
*	形    参:  _no : 指示灯序号，范围 1 - 4
*	返 回 值: 无
*********************************************************************************************************
*/
void BSP_LED_ON(uint8_t _no)
{
	if (_no == USER_LD1)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
	}
	else if (_no == USER_LD2)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
	}
        else if(_no == USER_LED_ALL)
    {
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1,GPIO_PIN_SET);
    }
	else
		return;
}

/*
*********************************************************************************************************
*	函 数 名: bsp_LedOff
*	功能说明: 熄灭指定的LED指示灯。
*	形    参:  _no : 指示灯序号，范围 1 - 2
*	返 回 值: 无
*********************************************************************************************************
*/
void BSP_LED_OFF(uint8_t _no)
{
	if (_no == USER_LD1)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
	}
	else if (_no == USER_LD2)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);
	}
    else if(_no == USER_LED_ALL)
    {
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1,GPIO_PIN_SET);
    }
	else
		return;
}

/*
*********************************************************************************************************
*	函 数 名: bsp_LedToggle
*	功能说明: 翻转指定的LED指示灯。
*	形    参:  _no : 指示灯序号，范围 1 - 2
*	返 回 值: 按键代码
*********************************************************************************************************
*/
void BSP_LED_Toggle(uint8_t _no)
{

	if (_no == USER_LD1)
	{
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
	}
	else if (_no == USER_LD2)
	{
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
	}
	else if(_no == USER_LED_ALL)
    {
      HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1);
    }
      else
		return;
}
