
#include "hw_stm32f030_mini.h"

void delay(unsigned int timeout)
{
    unsigned int t1, t2;
    for (t1 = 0; t1 < timeout; t1++)
    {
        for (t2 = 0; t2 < 0xFFF; t2++)
        {
          asm(" nop");
        }
    }
}

void enable_clock(void)
{
  /* GPIOC */
  unsigned long int tmpreg;
  tmpreg = read_reg(RCC_AHBENR, ~RCC_AHBENR_IOPCEN);
  tmpreg = tmpreg | RCC_AHBENR_IOPCEN;
  write_reg(RCC_AHBENR, tmpreg);
  delay(10);
}

void init_pin(void)
{
  /* set mode pc9 - Led LD3 */
  write_reg(GPIOC_MODER, GPIO_MODE_OUTPUT << 18);
  /* set mode pc8 - Led LD4 */
  write_reg(GPIOC_MODER, GPIO_MODE_OUTPUT << 16);
}

void turn_on_ld4(void)
{
  write_reg(GPIOC_ODR, 1 << LD4_PIN);
}

void turn_off_ld4(void)
{
  write_reg(GPIOC_ODR, 0 << LD4_PIN);
}

void main(void)
{
  /* enable clock */
  enable_clock();
  /* init led pins */
  init_pin();
  while(1)
  {
    turn_on_ld4();
    delay(0xff);
    turn_off_ld4();
    delay(0xff);
  }
}


void Reserved_IRQHandler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void NMI_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void HardFault_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void SVC_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void PendSV_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void SysTick_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}


