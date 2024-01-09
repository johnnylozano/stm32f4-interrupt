#include "stm32f4xx.h"
#include "led.h"

#define GPIOAEN     (1U<<0)
#define PIN5        (1U<<5)
#define LED_PIN     PIN5

void LED_init(void)
{
    /* Enable clock access to GPIOA */
    RCC->AHB1ENR |= GPIOAEN;

    /* Set GPIOA as an output */
    GPIOA->MODER |= (1U<<10);
    GPIOA->MODER &= ~(1U<<11);
}

void LED_on(void)
{
    GPIOA->BSRR = LED_PIN;
}

void LED_off(void)
{
    GPIOA->BSRR = (1U<<21);
}
