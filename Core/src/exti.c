#include "exti.h"

#define GPIOCEN     (1U << 2)
#define SYSCFGEN    (1U << 14)

void pc13_exti_init(void) 
{
    /* Disable global interrupts */
    __disable_irq();

    /* Enable clock access for GPIOC */
    RCC->AHB1ENR |= GPIOCEN;

    /* Enable clock access to SYSCFG */
    RCC->APB2ENR |= SYSCFGEN;

    /* Set PC13 as input */
    GPIOC->MODER &= ~(1U << 26);
    GPIOC->MODER &= ~(1U << 27);

    /* Select PORTC for EXTI13 */
    SYSCFG->EXTICR[3] |= (1U << 5); // EXTICR[3] refers to EXTICR4

    /* Unmask EXTI13 */
    EXTI->IMR |= (1U << 13);

    /* Select falling edge trigger */
    EXTI->FTSR |= (1U << 13);

    /* Enable EXTI line in NVIC */
    NVIC_EnableIRQ(EXTI15_10_IRQn);

    /* Enable global interrupts */
    __enable_irq();
}