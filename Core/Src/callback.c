//
// Created by h on 2024/10/13.
//
#include "usart.h"
#include "main.h"
#include "string.h"

extern uint8_t buffer[18];
extern uint8_t data[18];
extern void RemoteDataProcess(const uint8_t *pData);

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart){
    if (huart->Instance == USART1) {
      memcpy(data, buffer, 18);
      RemoteDataProcess(data);
    }
    HAL_UART_Receive_DMA(&huart1, buffer, 18);
}

