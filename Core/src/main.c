#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "led.h"

int main(void)
{
    LED_init();

    while (1)
    {    
        /* Toggle LED */
        LED_on();
        for (uint32_t i = 0; i < 1000000; i++) {}

        LED_off();
		for (uint32_t i = 0; i < 1000000; i++) {}
    }

    return 0;
}