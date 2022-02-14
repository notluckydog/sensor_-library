


#include "led.h"

void LED_GPIO_Config(void){
    /* * @brief 初始化IO
  * @param  无
  * @retval 无
	*/
	
	/*定义结构体*/
    GPIO_InitTypeDef  GPIO_InitStruct;
		LED_GPIO_CLK_ENABLE();
		
    /*选择需要控制的GPIO引脚*/															   
    GPIO_InitStruct.Pin = LED1_PIN;	

		/*设置引脚为推挽输出*/
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  

		/*设置引脚为上拉*/
    GPIO_InitStruct.Pull  = GPIO_PULLUP;

/*设置引脚速率为高速 */   
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

    /*初始化GPIO*/
    HAL_GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStruct);	
		
		/*关闭LED  */
		LED_OFF;

}
void LED_SET_ON(void)
{
/* * @brief 开灯
  * @param  无
  * @retval 无
	*/
		LED_ON  ;
	}
	
void LED_SET_OFF(void){
	/* * @brief 关灯
  * @param  无
  * @retval 无
	*/
		LED_OFF;
		
		}
		
void LED_SET_LEVEL(uint8_t level)
{
		/* * @brief 设置灯的亮度
  * @param  无
  * @retval 无
	*/
}

void LED_SET_BREATH(void)
{
/* * @brief 设置呼吸灯
  * @param  无
  * @retval 无
	*/
	
}
