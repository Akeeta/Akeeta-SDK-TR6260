#ifndef _YA_HAL_UART_H_
#define _YA_HAL_UART_H_

extern int32_t ya_hal_uart_open(void);

extern int32_t ya_hal_uart_write(uint8_t *buffer, uint32_t len);

extern int32_t ya_hal_uart_recv(uint8_t *buffer, uint32_t len, uint32_t timeout);


#endif


