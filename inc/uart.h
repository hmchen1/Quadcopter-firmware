#ifndef __UART_H__
#define __UART_H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f429i_discovery.h"
#include "stm32f4xx_hal.h"

HAL_StatusTypeDef UART_init(USART_TypeDef *uart, uint32_t BaudRate);
HAL_StatusTypeDef UART_send(uint8_t* data, uint16_t length);
HAL_StatusTypeDef UART_recv(uint8_t* buffer, uint16_t length);
void UART_send_IT(uint8_t* data, uint16_t length);
void UART_recv_IT(uint8_t* buffer, uint16_t length);
void USARTx_IRQHandler(void);
void StartUartRXInterrupt();

#ifdef __cplusplus
}
#endif

#endif /* __UART_H__ */
