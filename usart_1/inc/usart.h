
#ifndef __USART_H__
#define __USART_H__

#include "hw_stm32f051r8.h"

extern void UsartInit(void);
extern void UsartSendAByte(unsigned char data_input);

/* end file */
#endif /* __USART_H__ */
