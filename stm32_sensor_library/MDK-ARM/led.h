#ifndef __LED_H
#define	__LED_H

#include "stm32f1xx.h"

//引脚定义
//单色灯，仅有一个引脚
#define LED_PIN                  GPIO_PIN_5
#define LED_GPIO_PORT            GPIOB
#define LED_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOB_CLK_ENABLE()


/**功能定义
	*控制灯亮
	*控制灯灭
	*控制灯的亮度
	*呼吸灯效果
*/

/* 直接操作寄存器的方式控制IO*/
#define	digitalHi(p,i)			{p->BSRR=i;}			  //设置高电平	
#define digitalLo(p,i)			{p->BSRR=(uint32_t)i << 16;}				//设置低电平
#define digitalToggle(p,i)		{p->ODR ^=i;}			//设置电平反转

/* 定义控制LED的宏 */
#define LED_ON      digitalHi(LED_GPIO_PORT,LED_PIN)    //打开LED
#define LED_OFF     digitalLo(LED_GPIO_PORT,LED_PIN)    //关闭LED


/*   具体功能函数  */
void LED_GPIO_Config(void);
void LED_SET_ON(void);
void LED_SET_OFF(void);
void LED_SET_LEVEL(uint8_t level);
void LED_SET_BREATH(void);

#endif /* __LED_H */
