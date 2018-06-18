
#include "usart.h"


void UsartInit(void)
{
	unsigned int temp_reg;

	/* disable usart1 */
	write_reg(USART_CR1, 0x00000000);

	/* length data: 8 bits */
	temp_reg = read_reg(USART_CR1, ~((1<<28)||(1<<12)));
	temp_reg |= (0<<28)||(0<<12);
	write_reg(USART_CR1, temp_reg);

	/* parity : none */
	temp_reg = read_reg(USART_CR1, ~(1<<10));
	temp_reg |= (0<<10);
	write_reg(USART_CR1, temp_reg);

	/* stop bit - 1 bit */
	temp_reg = read_reg(USART_CR2, ~(0x3<<12));
	temp_reg |= (0<<12);
	write_reg(USART_CR2, temp_reg);

	/* oversampling: 16 bits */
	temp_reg = read_reg(USART_CR1, ~(1<<15));
	temp_reg |= (0<<15);
	write_reg(USART_CR1, temp_reg);

	/* baudrate = 9600 bps; fCK = 8 MHz */
	write_reg(USART_BRR, 0x0341u);

	/* enable usart1 */
	temp_reg = read_reg(USART_CR1, ~(1<<0));
	temp_reg |= (1<<0);
	write_reg(USART_CR1, temp_reg);

	/* enable transmition */
	temp_reg = read_reg(USART_CR1, ~(1<<3));
	temp_reg |= (1<<3);
	write_reg(USART_CR1, temp_reg);

}


void UsartSendAByte(unsigned char data_input)
{
	write_reg(USART_TDR, (unsigned int)data_input);
}