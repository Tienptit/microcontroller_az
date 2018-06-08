
#ifndef __HW_STM32F030_MINI_H__
#define __HW_STM32F030_MINI_H__

/* LED D2 - PA4 */
#define write_reg(addr, value)    *((unsigned long int *)(addr)) = value
#define read_reg(addr, mask)      *((unsigned long int *)(addr)) & (mask)

/* RCC - clock */
#define BASE_ADDRESS_RCC          0x40021000u

#define RCC_AHBENR                BASE_ADDRESS_RCC + 0x14
#define RCC_AHBENR_IOPCEN         (0x01 << 19)


/* GPIO - PORTC */
#define BASE_ADDR_GPIOC       0x48000800u
#define GPIOC_MODER           (BASE_ADDR_GPIOC + 0x00u)
// #define GPIO_AFRL             (GPIOC_START_ADDR + 0x20u)
// #define GPIO_AFRH             (GPIOC_START_ADDR + 0x24u)
#define GPIOC_IDR             (BASE_ADDR_GPIOC + 0x10u)
#define GPIOC_ODR             (BASE_ADDR_GPIOC + 0x14u)

#define GPIO_MODE_INPUT       0x00u
#define GPIO_MODE_OUTPUT      0x01u
#define GPIO_MODE_ALT         0x02u
#define GPIO_MODE_ANALOG      0x03u

/* User LD3 -> PC9 */
#define LD3_PIN               9

/* User LD4 -> PC8 */
#define LD4_PIN               8


/* end file */
#endif /* __HW_STM32F030_MINI_H__ */

