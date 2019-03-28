#include <stdint.h>
#include "reg.h"

void led_init(unsigned int LED)
{

SET_BIT(RCC_BASE + RCC_AHB1ENR_OFFSET, GPIO_EN_BIT(GPIO_PORTD));
CLEAR_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_MODER_OFFSET, MODERy_1_BIT(LED));
SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_MODER_OFFSET, MODERy_0_BIT(LED));
//OT led pin = 0 => Output push-pull
CLEAR_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_OTYPER_OFFSET, OTy_BIT(LED));
//OSPEEDR led pin = 11 => High speed
SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_OSPEEDR_OFFSET, OSPEEDRy_1_BIT(LED));
SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_OSPEEDR_OFFSET, OSPEEDRy_0_BIT(LED));
//PUPDR led pin = 01 => no pull-up,NO pull-down
SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_PUPDR_OFFSET, PUPDRy_1_BIT(LED));
SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_PUPDR_OFFSET, PUPDRy_0_BIT(LED));
}

void blink(unsigned int led)
{
    	

		led_init(led);
		
	unsigned int i;
	while (1)
	{
		//set GPIOD15
	  SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_BSRR_OFFSET, BSy_BIT(led));
     
		for (i = 0; i < 100000; i++);

		//reset GPIOD15
	   SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_BSRR_OFFSET, BRy_BIT(led));
   
		for (i = 0; i < 100000; i++);
        
  
	}
}
void blink_count (unsigned int led,int count)
{
    unsigned int i;
    unsigned int j=0;
	led_init(led);
	while (j<count)
	{
		//set GPIOD15
	  SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_BSRR_OFFSET, BSy_BIT(led));
     
		for (i = 0; i < 100000; i++);

		//reset GPIOD15
	   SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_BSRR_OFFSET, BRy_BIT(led));
    
		for (i = 0; i < 100000; i++);
         ++j;
  
	}

	
}
