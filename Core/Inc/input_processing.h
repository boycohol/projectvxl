/*
 * input_processing.h
 *
 *  Created on: Nov 8, 2022
 *      Author: Admin
 */

#ifndef INC_INPUT_PROCESSING_H_
#define INC_INPUT_PROCESSING_H_

void fsm_changeMode_btn1();
void fsm_changeLed_btn2();
void fsm_modifyTime_btn3();
void fsm_pedestrian_btn4();
void fsm_init();

void display7SEG1(int num);
void display7SEG2(int num);

void led_blink();
void display_set_value();

void fsm_traffic_led();
void buzzer_pedestrian();

int updateState();
int updateBuzzerState();

#endif /* INC_INPUT_PROCESSING_H_ */
