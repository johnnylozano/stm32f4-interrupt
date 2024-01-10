#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "exti.h"

#define GPIOAEN		(1U<<0)
#define PIN5		(1U<<5)
#define LED		    PIN5

static void exti_callback(void);

int main(void)
{

    /* Enable clock access to GPIOA */
    RCC->AHB1ENR |= GPIOAEN;

    /* Set GPIOA as an output */
    GPIOA->MODER |= (1U<<10);
    GPIOA->MODER &=~(1U<<11);

    pc13_exti_init();
    uart2_tx_init();

    while (1)
    {    
        
    }

    return 0;
}

static void exti_callback(void)
{
    printf("BTN Pressed...\n\r");
    GPIOA->ODR ^= LED;
}

void EXTI15_10_IRQHandler(void)
{
    if((EXTI->PR & LINE13) != 0)
    {
        /* Clear PR flag */
        EXTI->PR |= LINE13;

        exti_callback();
    }
}