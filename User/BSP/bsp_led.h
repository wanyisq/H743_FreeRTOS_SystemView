

#ifndef __BSP_LED_H
#define __BSP_LED_H

#ifdef __cplusplus
extern  "C" {                                                   /* See Note #1.                        */
#endif

#include  <stm32h7xx_hal.h>

typedef  enum  bsp_led {
    USER_LD1 = 1,
    USER_LD2,
    USER_LED_ALL,
} BSP_LED;

/* 供外部调用的函数声明 */
void BSP_LED_Init(void);
void BSP_LED_ON(uint8_t _no);
void BSP_LED_OFF(uint8_t _no);
void BSP_LED_Toggle(uint8_t _no);


#endif

