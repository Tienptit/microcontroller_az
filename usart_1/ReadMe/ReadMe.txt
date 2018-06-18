UART

1. Khởi tạo:
- Data = 8 bits
- Parity = none
- stop = 1 bit
- baudrate = 9600 bps


2. Quá trình truyền dữ liệu:
- Cần kiểm tra cờ USART_ISR[TXE]
	-> Nếu USART_ISR[TXE] = 1 -> tiến hành ghi dữ liệu vào USART_TDR = <data> (lưu ý là ghi 1 byte dữ liệu)
	-> Nếu USART_ISR[TXE] = 0 -> không ghi dữ liệu vào USART_TDR
- Truyền đc dữ liệu

3. Những phần tài liệu cần đọc:
- 27.5.2./ 27.5.3/ 27.5.4/ 27.5.9/ 27.8
