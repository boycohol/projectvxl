/*
 * input_processing.c
 *
 *  Created on: Nov 9, 2022
 *      Author: Admin
 */
#include "input_processing.h"
#include "main.h"
#include "global.h"
#include "input_reading.h"
#include "uart.h"
#include "timer.h"

void display7SEG1(int num) {
	switch (num) {
	case 0:
		HAL_GPIO_WritePin(SEG1_0_GPIO_Port, SEG1_0_Pin, 0);
		HAL_GPIO_WritePin(SEG1_1_GPIO_Port, SEG1_1_Pin, 0);
		HAL_GPIO_WritePin(SEG1_2_GPIO_Port, SEG1_2_Pin, 0);
		HAL_GPIO_WritePin(SEG1_3_GPIO_Port, SEG1_3_Pin, 0);
		HAL_GPIO_WritePin(SEG1_4_GPIO_Port, SEG1_4_Pin, 0);
		HAL_GPIO_WritePin(SEG1_5_GPIO_Port, SEG1_5_Pin, 0);
		HAL_GPIO_WritePin(SEG1_6_GPIO_Port, SEG1_6_Pin, 1);
		break;
	case 1:
		HAL_GPIO_WritePin(SEG1_0_GPIO_Port, SEG1_0_Pin, 1);
		HAL_GPIO_WritePin(SEG1_1_GPIO_Port, SEG1_1_Pin, 0);
		HAL_GPIO_WritePin(SEG1_2_GPIO_Port, SEG1_2_Pin, 0);
		HAL_GPIO_WritePin(SEG1_3_GPIO_Port, SEG1_3_Pin, 1);
		HAL_GPIO_WritePin(SEG1_4_GPIO_Port, SEG1_4_Pin, 1);
		HAL_GPIO_WritePin(SEG1_5_GPIO_Port, SEG1_5_Pin, 1);
		HAL_GPIO_WritePin(SEG1_6_GPIO_Port, SEG1_6_Pin, 1);
		break;
	case 2:
		HAL_GPIO_WritePin(SEG1_0_GPIO_Port, SEG1_0_Pin, 0);
		HAL_GPIO_WritePin(SEG1_1_GPIO_Port, SEG1_1_Pin, 0);
		HAL_GPIO_WritePin(SEG1_2_GPIO_Port, SEG1_2_Pin, 1);
		HAL_GPIO_WritePin(SEG1_3_GPIO_Port, SEG1_3_Pin, 0);
		HAL_GPIO_WritePin(SEG1_4_GPIO_Port, SEG1_4_Pin, 0);
		HAL_GPIO_WritePin(SEG1_5_GPIO_Port, SEG1_5_Pin, 1);
		HAL_GPIO_WritePin(SEG1_6_GPIO_Port, SEG1_6_Pin, 0);
		break;
	case 3:
		HAL_GPIO_WritePin(SEG1_0_GPIO_Port, SEG1_0_Pin, 0);
		HAL_GPIO_WritePin(SEG1_1_GPIO_Port, SEG1_1_Pin, 0);
		HAL_GPIO_WritePin(SEG1_2_GPIO_Port, SEG1_2_Pin, 0);
		HAL_GPIO_WritePin(SEG1_3_GPIO_Port, SEG1_3_Pin, 0);
		HAL_GPIO_WritePin(SEG1_4_GPIO_Port, SEG1_4_Pin, 1);
		HAL_GPIO_WritePin(SEG1_5_GPIO_Port, SEG1_5_Pin, 1);
		HAL_GPIO_WritePin(SEG1_6_GPIO_Port, SEG1_6_Pin, 0);
		break;
	case 4:
		HAL_GPIO_WritePin(SEG1_0_GPIO_Port, SEG1_0_Pin, 1);
		HAL_GPIO_WritePin(SEG1_1_GPIO_Port, SEG1_1_Pin, 0);
		HAL_GPIO_WritePin(SEG1_2_GPIO_Port, SEG1_2_Pin, 0);
		HAL_GPIO_WritePin(SEG1_3_GPIO_Port, SEG1_3_Pin, 1);
		HAL_GPIO_WritePin(SEG1_4_GPIO_Port, SEG1_4_Pin, 1);
		HAL_GPIO_WritePin(SEG1_5_GPIO_Port, SEG1_5_Pin, 0);
		HAL_GPIO_WritePin(SEG1_6_GPIO_Port, SEG1_6_Pin, 0);
		break;
	case 5:
		HAL_GPIO_WritePin(SEG1_0_GPIO_Port, SEG1_0_Pin, 0);
		HAL_GPIO_WritePin(SEG1_1_GPIO_Port, SEG1_1_Pin, 1);
		HAL_GPIO_WritePin(SEG1_2_GPIO_Port, SEG1_2_Pin, 0);
		HAL_GPIO_WritePin(SEG1_3_GPIO_Port, SEG1_3_Pin, 0);
		HAL_GPIO_WritePin(SEG1_4_GPIO_Port, SEG1_4_Pin, 1);
		HAL_GPIO_WritePin(SEG1_5_GPIO_Port, SEG1_5_Pin, 0);
		HAL_GPIO_WritePin(SEG1_6_GPIO_Port, SEG1_6_Pin, 0);
		break;
	case 6:
		HAL_GPIO_WritePin(SEG1_0_GPIO_Port, SEG1_0_Pin, 0);
		HAL_GPIO_WritePin(SEG1_1_GPIO_Port, SEG1_1_Pin, 1);
		HAL_GPIO_WritePin(SEG1_2_GPIO_Port, SEG1_2_Pin, 0);
		HAL_GPIO_WritePin(SEG1_3_GPIO_Port, SEG1_3_Pin, 0);
		HAL_GPIO_WritePin(SEG1_4_GPIO_Port, SEG1_4_Pin, 0);
		HAL_GPIO_WritePin(SEG1_5_GPIO_Port, SEG1_5_Pin, 0);
		HAL_GPIO_WritePin(SEG1_6_GPIO_Port, SEG1_6_Pin, 0);
		break;
	case 7:
		HAL_GPIO_WritePin(SEG1_0_GPIO_Port, SEG1_0_Pin, 0);
		HAL_GPIO_WritePin(SEG1_1_GPIO_Port, SEG1_1_Pin, 0);
		HAL_GPIO_WritePin(SEG1_2_GPIO_Port, SEG1_2_Pin, 0);
		HAL_GPIO_WritePin(SEG1_3_GPIO_Port, SEG1_3_Pin, 1);
		HAL_GPIO_WritePin(SEG1_4_GPIO_Port, SEG1_4_Pin, 1);
		HAL_GPIO_WritePin(SEG1_5_GPIO_Port, SEG1_5_Pin, 1);
		HAL_GPIO_WritePin(SEG1_6_GPIO_Port, SEG1_6_Pin, 1);
		break;
	case 8:
		HAL_GPIO_WritePin(SEG1_0_GPIO_Port, SEG1_0_Pin, 0);
		HAL_GPIO_WritePin(SEG1_1_GPIO_Port, SEG1_1_Pin, 0);
		HAL_GPIO_WritePin(SEG1_2_GPIO_Port, SEG1_2_Pin, 0);
		HAL_GPIO_WritePin(SEG1_3_GPIO_Port, SEG1_3_Pin, 0);
		HAL_GPIO_WritePin(SEG1_4_GPIO_Port, SEG1_4_Pin, 0);
		HAL_GPIO_WritePin(SEG1_5_GPIO_Port, SEG1_5_Pin, 0);
		HAL_GPIO_WritePin(SEG1_6_GPIO_Port, SEG1_6_Pin, 0);
		break;
	case 9:
		HAL_GPIO_WritePin(SEG1_0_GPIO_Port, SEG1_0_Pin, 0);
		HAL_GPIO_WritePin(SEG1_1_GPIO_Port, SEG1_1_Pin, 0);
		HAL_GPIO_WritePin(SEG1_2_GPIO_Port, SEG1_2_Pin, 0);
		HAL_GPIO_WritePin(SEG1_3_GPIO_Port, SEG1_3_Pin, 0);
		HAL_GPIO_WritePin(SEG1_4_GPIO_Port, SEG1_4_Pin, 1);
		HAL_GPIO_WritePin(SEG1_5_GPIO_Port, SEG1_5_Pin, 0);
		HAL_GPIO_WritePin(SEG1_6_GPIO_Port, SEG1_6_Pin, 0);
		break;
	default:
		HAL_GPIO_WritePin(SEG1_0_GPIO_Port, SEG1_0_Pin, 1);
		HAL_GPIO_WritePin(SEG1_1_GPIO_Port, SEG1_1_Pin, 1);
		HAL_GPIO_WritePin(SEG1_2_GPIO_Port, SEG1_2_Pin, 1);
		HAL_GPIO_WritePin(SEG1_3_GPIO_Port, SEG1_3_Pin, 1);
		HAL_GPIO_WritePin(SEG1_4_GPIO_Port, SEG1_4_Pin, 1);
		HAL_GPIO_WritePin(SEG1_5_GPIO_Port, SEG1_5_Pin, 1);
		HAL_GPIO_WritePin(SEG1_6_GPIO_Port, SEG1_6_Pin, 1);
		break;
	}
}
void display7SEG2(int num) {
	switch (num) {
	case 0:
		HAL_GPIO_WritePin(SEG2_0_GPIO_Port, SEG2_0_Pin, 0);
		HAL_GPIO_WritePin(SEG2_1_GPIO_Port, SEG2_1_Pin, 0);
		HAL_GPIO_WritePin(SEG2_2_GPIO_Port, SEG2_2_Pin, 0);
		HAL_GPIO_WritePin(SEG2_3_GPIO_Port, SEG2_3_Pin, 0);
		HAL_GPIO_WritePin(SEG2_4_GPIO_Port, SEG2_4_Pin, 0);
		HAL_GPIO_WritePin(SEG2_5_GPIO_Port, SEG2_5_Pin, 0);
		HAL_GPIO_WritePin(SEG2_6_GPIO_Port, SEG2_6_Pin, 1);
		break;
	case 1:
		HAL_GPIO_WritePin(SEG2_0_GPIO_Port, SEG2_0_Pin, 1);
		HAL_GPIO_WritePin(SEG2_1_GPIO_Port, SEG2_1_Pin, 0);
		HAL_GPIO_WritePin(SEG2_2_GPIO_Port, SEG2_2_Pin, 0);
		HAL_GPIO_WritePin(SEG2_3_GPIO_Port, SEG2_3_Pin, 1);
		HAL_GPIO_WritePin(SEG2_4_GPIO_Port, SEG2_4_Pin, 1);
		HAL_GPIO_WritePin(SEG2_5_GPIO_Port, SEG2_5_Pin, 1);
		HAL_GPIO_WritePin(SEG2_6_GPIO_Port, SEG2_6_Pin, 1);
		break;
	case 2:
		HAL_GPIO_WritePin(SEG2_0_GPIO_Port, SEG2_0_Pin, 0);
		HAL_GPIO_WritePin(SEG2_1_GPIO_Port, SEG2_1_Pin, 0);
		HAL_GPIO_WritePin(SEG2_2_GPIO_Port, SEG2_2_Pin, 1);
		HAL_GPIO_WritePin(SEG2_3_GPIO_Port, SEG2_3_Pin, 0);
		HAL_GPIO_WritePin(SEG2_4_GPIO_Port, SEG2_4_Pin, 0);
		HAL_GPIO_WritePin(SEG2_5_GPIO_Port, SEG2_5_Pin, 1);
		HAL_GPIO_WritePin(SEG2_6_GPIO_Port, SEG2_6_Pin, 0);
		break;
	case 3:
		HAL_GPIO_WritePin(SEG2_0_GPIO_Port, SEG2_0_Pin, 0);
		HAL_GPIO_WritePin(SEG2_1_GPIO_Port, SEG2_1_Pin, 0);
		HAL_GPIO_WritePin(SEG2_2_GPIO_Port, SEG2_2_Pin, 0);
		HAL_GPIO_WritePin(SEG2_3_GPIO_Port, SEG2_3_Pin, 0);
		HAL_GPIO_WritePin(SEG2_4_GPIO_Port, SEG2_4_Pin, 1);
		HAL_GPIO_WritePin(SEG2_5_GPIO_Port, SEG2_5_Pin, 1);
		HAL_GPIO_WritePin(SEG2_6_GPIO_Port, SEG2_6_Pin, 0);
		break;
	case 4:
		HAL_GPIO_WritePin(SEG2_0_GPIO_Port, SEG2_0_Pin, 1);
		HAL_GPIO_WritePin(SEG2_1_GPIO_Port, SEG2_1_Pin, 0);
		HAL_GPIO_WritePin(SEG2_2_GPIO_Port, SEG2_2_Pin, 0);
		HAL_GPIO_WritePin(SEG2_3_GPIO_Port, SEG2_3_Pin, 1);
		HAL_GPIO_WritePin(SEG2_4_GPIO_Port, SEG2_4_Pin, 1);
		HAL_GPIO_WritePin(SEG2_5_GPIO_Port, SEG2_5_Pin, 0);
		HAL_GPIO_WritePin(SEG2_6_GPIO_Port, SEG2_6_Pin, 0);
		break;
	case 5:
		HAL_GPIO_WritePin(SEG2_0_GPIO_Port, SEG2_0_Pin, 0);
		HAL_GPIO_WritePin(SEG2_1_GPIO_Port, SEG2_1_Pin, 1);
		HAL_GPIO_WritePin(SEG2_2_GPIO_Port, SEG2_2_Pin, 0);
		HAL_GPIO_WritePin(SEG2_3_GPIO_Port, SEG2_3_Pin, 0);
		HAL_GPIO_WritePin(SEG2_4_GPIO_Port, SEG2_4_Pin, 1);
		HAL_GPIO_WritePin(SEG2_5_GPIO_Port, SEG2_5_Pin, 0);
		HAL_GPIO_WritePin(SEG2_6_GPIO_Port, SEG2_6_Pin, 0);
		break;
	case 6:
		HAL_GPIO_WritePin(SEG2_0_GPIO_Port, SEG2_0_Pin, 0);
		HAL_GPIO_WritePin(SEG2_1_GPIO_Port, SEG2_1_Pin, 1);
		HAL_GPIO_WritePin(SEG2_2_GPIO_Port, SEG2_2_Pin, 0);
		HAL_GPIO_WritePin(SEG2_3_GPIO_Port, SEG2_3_Pin, 0);
		HAL_GPIO_WritePin(SEG2_4_GPIO_Port, SEG2_4_Pin, 0);
		HAL_GPIO_WritePin(SEG2_5_GPIO_Port, SEG2_5_Pin, 0);
		HAL_GPIO_WritePin(SEG2_6_GPIO_Port, SEG2_6_Pin, 0);
		break;
	case 7:
		HAL_GPIO_WritePin(SEG2_0_GPIO_Port, SEG2_0_Pin, 0);
		HAL_GPIO_WritePin(SEG2_1_GPIO_Port, SEG2_1_Pin, 0);
		HAL_GPIO_WritePin(SEG2_2_GPIO_Port, SEG2_2_Pin, 0);
		HAL_GPIO_WritePin(SEG2_3_GPIO_Port, SEG2_3_Pin, 1);
		HAL_GPIO_WritePin(SEG2_4_GPIO_Port, SEG2_4_Pin, 1);
		HAL_GPIO_WritePin(SEG2_5_GPIO_Port, SEG2_5_Pin, 1);
		HAL_GPIO_WritePin(SEG2_6_GPIO_Port, SEG2_6_Pin, 1);
		break;
	case 8:
		HAL_GPIO_WritePin(SEG2_0_GPIO_Port, SEG2_0_Pin, 0);
		HAL_GPIO_WritePin(SEG2_1_GPIO_Port, SEG2_1_Pin, 0);
		HAL_GPIO_WritePin(SEG2_2_GPIO_Port, SEG2_2_Pin, 0);
		HAL_GPIO_WritePin(SEG2_3_GPIO_Port, SEG2_3_Pin, 0);
		HAL_GPIO_WritePin(SEG2_4_GPIO_Port, SEG2_4_Pin, 0);
		HAL_GPIO_WritePin(SEG2_5_GPIO_Port, SEG2_5_Pin, 0);
		HAL_GPIO_WritePin(SEG2_6_GPIO_Port, SEG2_6_Pin, 0);
		break;
	case 9:
		HAL_GPIO_WritePin(SEG2_0_GPIO_Port, SEG2_0_Pin, 0);
		HAL_GPIO_WritePin(SEG2_1_GPIO_Port, SEG2_1_Pin, 0);
		HAL_GPIO_WritePin(SEG2_2_GPIO_Port, SEG2_2_Pin, 0);
		HAL_GPIO_WritePin(SEG2_3_GPIO_Port, SEG2_3_Pin, 0);
		HAL_GPIO_WritePin(SEG2_4_GPIO_Port, SEG2_4_Pin, 1);
		HAL_GPIO_WritePin(SEG2_5_GPIO_Port, SEG2_5_Pin, 0);
		HAL_GPIO_WritePin(SEG2_6_GPIO_Port, SEG2_6_Pin, 0);
		break;
	default:
		HAL_GPIO_WritePin(SEG2_0_GPIO_Port, SEG2_0_Pin, 1);
		HAL_GPIO_WritePin(SEG2_1_GPIO_Port, SEG2_1_Pin, 1);
		HAL_GPIO_WritePin(SEG2_2_GPIO_Port, SEG2_2_Pin, 1);
		HAL_GPIO_WritePin(SEG2_3_GPIO_Port, SEG2_3_Pin, 1);
		HAL_GPIO_WritePin(SEG2_4_GPIO_Port, SEG2_4_Pin, 1);
		HAL_GPIO_WritePin(SEG2_5_GPIO_Port, SEG2_5_Pin, 1);
		HAL_GPIO_WritePin(SEG2_6_GPIO_Port, SEG2_6_Pin, 1);
		break;
	}
}

void fsm_traffic_led() {
	if (status_mode == AUTO_MODE) {
		if (state_led == 0) {
			HAL_GPIO_WritePin(TRAFFIC_RED_GPIO_Port, TRAFFIC_RED_Pin, 0);
			HAL_GPIO_WritePin(TRAFFIC_AMBER_GPIO_Port, TRAFFIC_AMBER_Pin, 1);
			HAL_GPIO_WritePin(TRAFFIC_GREEN_GPIO_Port, TRAFFIC_GREEN_Pin, 1);
			uart_communiation_fsm(final_led_count[0] - index_led);
			control_mode = final_led_count[0] - index_led;
			index_led++;
			if (final_led_count[0] == index_led) {
				index_led = 0;
				state_led = 2;
			}
		} else if (state_led == 1) {
			HAL_GPIO_WritePin(TRAFFIC_RED_GPIO_Port, TRAFFIC_RED_Pin, 1);
			HAL_GPIO_WritePin(TRAFFIC_AMBER_GPIO_Port, TRAFFIC_AMBER_Pin, 0);
			HAL_GPIO_WritePin(TRAFFIC_GREEN_GPIO_Port, TRAFFIC_GREEN_Pin, 1);
			uart_communiation_fsm(final_led_count[1] - index_led);
			index_led++;
			if (final_led_count[1] == index_led) {
				index_led = 0;
				state_led = 0;
			}
		} else if (state_led == 2) {
			HAL_GPIO_WritePin(TRAFFIC_RED_GPIO_Port, TRAFFIC_RED_Pin, 1);
			HAL_GPIO_WritePin(TRAFFIC_AMBER_GPIO_Port, TRAFFIC_AMBER_Pin, 1);
			HAL_GPIO_WritePin(TRAFFIC_GREEN_GPIO_Port, TRAFFIC_GREEN_Pin, 0);
			uart_communiation_fsm(final_led_count[2] - index_led);
			index_led++;
			if (final_led_count[2] == index_led) {
				index_led = 0;
				state_led = 1;
			}
		}
	}
}
void fsm_changeLed_btn2() {
	if (status_mode == MANUAL_MODE) {
		switch (led_mode) {
		case RED_MODE:
			HAL_GPIO_WritePin(TRAFFIC_RED_GPIO_Port, TRAFFIC_RED_Pin, 0);
			HAL_GPIO_WritePin(TRAFFIC_AMBER_GPIO_Port, TRAFFIC_AMBER_Pin, 1);
			HAL_GPIO_WritePin(TRAFFIC_GREEN_GPIO_Port, TRAFFIC_GREEN_Pin, 1);
			uart_communiation_fsm(final_led_count[0]);
			if (isButtonPressed(1)) {
				led_mode = AMBER_MODE;
			}
			break;
		case AMBER_MODE:
			HAL_GPIO_WritePin(TRAFFIC_RED_GPIO_Port, TRAFFIC_RED_Pin, 1);
			HAL_GPIO_WritePin(TRAFFIC_AMBER_GPIO_Port, TRAFFIC_AMBER_Pin, 0);
			HAL_GPIO_WritePin(TRAFFIC_GREEN_GPIO_Port, TRAFFIC_GREEN_Pin, 1);
			uart_communiation_fsm(final_led_count[1]);
			if (isButtonPressed(1)) {
				led_mode = GREEN_MODE;
			}
			break;
		case GREEN_MODE:
			HAL_GPIO_WritePin(TRAFFIC_RED_GPIO_Port, TRAFFIC_RED_Pin, 1);
			HAL_GPIO_WritePin(TRAFFIC_AMBER_GPIO_Port, TRAFFIC_AMBER_Pin, 1);
			HAL_GPIO_WritePin(TRAFFIC_GREEN_GPIO_Port, TRAFFIC_GREEN_Pin, 0);
			uart_communiation_fsm(final_led_count[2]);
			if (isButtonPressed(1)) {
				led_mode = RED_MODE;
			}
			break;
		default:
			break;
		}
	} else if (status_mode == TUNING_MODE) {
		switch (led_mode) {
		case RED_MODE:
			if (isButtonPressed(1)) {
				led_count[0]++;
			}
			uart_communiation_fsm(led_count[0]);
			break;

		case AMBER_MODE:
			if (isButtonPressed(1)) {
				led_count[1]++;
			}
			uart_communiation_fsm(led_count[1]);
			break;
		case GREEN_MODE:
			if (isButtonPressed(1)) {
				led_count[2]++;
			}
			uart_communiation_fsm(led_count[2]);
			break;
		default:
			break;
		}
	}
}
void fsm_changeMode_btn1() {
	switch (status_mode) {
	case AUTO_MODE:
		if (isButtonPressed(0)&&status_pedestrian_mode==5) {
			status_mode = MANUAL_MODE;
		}
		break;
	case MANUAL_MODE:
		if (isButtonPressed(0)) {
			led_count[0] = final_led_count[0];
			led_count[1] = final_led_count[1];
			led_count[2] = final_led_count[2];
			status_mode = TUNING_MODE;
		}
		break;

	case TUNING_MODE:
		if (isButtonPressed(0)) {
			status_mode = AUTO_MODE;
		}
		break;
	default:
		break;
	}
}
void fsm_modifyTime_btn3() {
	if (status_mode == TUNING_MODE) {
		switch (led_mode) {
		case RED_MODE:
			if (isButtonPressed(2)) {
				final_led_count[0] = led_count[0];
			}
			break;
		case AMBER_MODE:
			if (isButtonPressed(2)) {
				final_led_count[1] = led_count[1];
			}
			break;
		case GREEN_MODE:
			if (isButtonPressed(2)) {
				final_led_count[2] = led_count[2];
			}
			break;
		default:
			break;
		}
	}
}
int updateState() {
	if (status_mode == AUTO_MODE) {
		return 1;
	} else if (status_mode == MANUAL_MODE) {
		return 2;
	} else if (status_mode == TUNING_MODE) {
		return 3;
	} else {
		return -1;
	}
}
void led_blink() {
	if (status_mode == TUNING_MODE) {
		switch (led_mode) {
		case RED_MODE:
			HAL_GPIO_TogglePin(TRAFFIC_RED_GPIO_Port, TRAFFIC_RED_Pin);
			HAL_GPIO_WritePin(TRAFFIC_AMBER_GPIO_Port, TRAFFIC_AMBER_Pin, 1);
			HAL_GPIO_WritePin(TRAFFIC_GREEN_GPIO_Port, TRAFFIC_GREEN_Pin, 1);
			break;
		case AMBER_MODE:
			HAL_GPIO_TogglePin(TRAFFIC_AMBER_GPIO_Port, TRAFFIC_AMBER_Pin);
			HAL_GPIO_WritePin(TRAFFIC_RED_GPIO_Port, TRAFFIC_RED_Pin, 1);
			HAL_GPIO_WritePin(TRAFFIC_GREEN_GPIO_Port, TRAFFIC_GREEN_Pin, 1);
			break;
		case GREEN_MODE:
			HAL_GPIO_TogglePin(TRAFFIC_GREEN_GPIO_Port, TRAFFIC_GREEN_Pin);
			HAL_GPIO_WritePin(TRAFFIC_AMBER_GPIO_Port, TRAFFIC_AMBER_Pin, 1);
			HAL_GPIO_WritePin(TRAFFIC_RED_GPIO_Port, TRAFFIC_RED_Pin, 1);
			break;
		default:
			break;
		}
	}
}

void buzzer_pedestrian() {
	if (timer3_flag) {
		setTimer3(100 - 8 * (10 - control_mode));
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
	}
	if (timer3_flag) {
		setTimer3(100 - 8 * (10 - control_mode));
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1,
				50 + 5 * (10 - control_mode));
	}
}

void fsm_pedestrian_btn4() {
	if (status_mode == AUTO_MODE) {
		switch (status_pedestrian_mode) {
		case PEDES_MODE_OFF:
			HAL_GPIO_WritePin(TRAFFIC2_AMBER_GPIO_Port, TRAFFIC2_AMBER_Pin, 1);
			HAL_GPIO_WritePin(TRAFFIC2_RED_GPIO_Port, TRAFFIC2_RED_Pin, 1);
			HAL_GPIO_WritePin(TRAFFIC2_GREEN_GPIO_Port, TRAFFIC2_GREEN_Pin, 1);
			if (isButtonPressed(3)) {
				status_pedestrian_mode = PEDES_MODE_ON;
			}
			break;
		case PEDES_MODE_ON:
			if (HAL_GPIO_ReadPin(TRAFFIC_RED_GPIO_Port, TRAFFIC_RED_Pin) == 0) {
				HAL_GPIO_WritePin(TRAFFIC2_AMBER_GPIO_Port, TRAFFIC2_AMBER_Pin,
						1);
				HAL_GPIO_WritePin(TRAFFIC2_RED_GPIO_Port, TRAFFIC2_RED_Pin, 1);
				HAL_GPIO_WritePin(TRAFFIC2_GREEN_GPIO_Port, TRAFFIC2_GREEN_Pin,
						0);
//				buzzer_pedestrian();
			} else if (HAL_GPIO_ReadPin(TRAFFIC_AMBER_GPIO_Port,
			TRAFFIC_AMBER_Pin) == 0) {
				HAL_GPIO_WritePin(TRAFFIC2_AMBER_GPIO_Port, TRAFFIC2_AMBER_Pin,
						0);
				HAL_GPIO_WritePin(TRAFFIC2_RED_GPIO_Port, TRAFFIC2_RED_Pin, 1);
				HAL_GPIO_WritePin(TRAFFIC2_GREEN_GPIO_Port, TRAFFIC2_GREEN_Pin,
						1);
			} else if (HAL_GPIO_ReadPin(TRAFFIC_GREEN_GPIO_Port,
			TRAFFIC_GREEN_Pin) == 0) {
				HAL_GPIO_WritePin(TRAFFIC2_AMBER_GPIO_Port, TRAFFIC2_AMBER_Pin,
						1);
				HAL_GPIO_WritePin(TRAFFIC2_RED_GPIO_Port, TRAFFIC2_RED_Pin, 0);
				HAL_GPIO_WritePin(TRAFFIC2_GREEN_GPIO_Port, TRAFFIC2_GREEN_Pin,
						1);
			}
			if (isButtonPressed(3)) {
				status_pedestrian_mode = PEDES_MODE_OFF;
			}
			break;
		default:
			break;
		}
	}
}

int updateBuzzerState(){
	return status_pedestrian_mode;
}

void fsm_init() {
	HAL_GPIO_WritePin(TRAFFIC2_AMBER_GPIO_Port, TRAFFIC2_AMBER_Pin, 1);
	HAL_GPIO_WritePin(TRAFFIC2_RED_GPIO_Port, TRAFFIC2_RED_Pin, 1);
	HAL_GPIO_WritePin(TRAFFIC2_GREEN_GPIO_Port, TRAFFIC2_GREEN_Pin, 1);
	HAL_GPIO_WritePin(TRAFFIC_AMBER_GPIO_Port, TRAFFIC2_AMBER_Pin, 1);
	HAL_GPIO_WritePin(TRAFFIC_RED_GPIO_Port, TRAFFIC2_RED_Pin, 1);
	HAL_GPIO_WritePin(TRAFFIC_GREEN_GPIO_Port, TRAFFIC2_GREEN_Pin, 1);
}

