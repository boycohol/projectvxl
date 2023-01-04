/*
 * uart.c
 *
 *  Created on: Dec 16, 2022
 *      Author: Admin
 */

#include "uart.h"
#include "main.h"
#include "stdlib.h"
#include "timer.h"
#include "global.h"


uint32_t ADC_value = 0;
unsigned char ADC_buffer[MAX_BUFFER_SIZE];
unsigned char start_str[] = "!7SEG=";
unsigned char end_str[] = "#\n";

void uart_communiation_fsm(int value) {
//	switch (sensor_reading_state) {
//	case NONE:
//		if (start_response_ADC_value()) {
//	ADC_value = HAL_ADC_GetValue(&hadc1);
	itoa(value, &ADC_buffer[0], 10);
//			timer_flag = 1;
//	sensor_reading_state = SEND;
//		}
//		break;
//	case SEND:
//		if (timer_flag) {
	HAL_UART_Transmit(&huart2, start_str, sizeof(start_str),
			sizeof(start_str) * 10);
	HAL_UART_Transmit(&huart2, ADC_buffer, sizeof(ADC_buffer),
			sizeof(ADC_buffer) * 10);
	HAL_UART_Transmit(&huart2, end_str, sizeof(end_str), sizeof(end_str) * 10);
//			setTimer(3000);
//		}
//		if (stop_response_ADC_value()) {
//			timer_flag = 0;
//			sensor_reading_state = END;
//		} else {
//			sensor_reading_state = SEND;
//		}
//		break;
//	case END:
//		timer_flag = 0;
//		break;
//	}
}
