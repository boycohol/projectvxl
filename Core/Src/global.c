/*
 * global.c
 *
 *  Created on: Dec 14, 2022
 *      Author: Admin
 */

#include "global.h"

int status_mode = 1;
int status_pedestrian_mode = 5;
int led_mode=11;
int control_mode = 0;

int led_count[3] = { 10, 3, 7 };
int final_led_count[3] = { 10, 3, 7 };

int state_led = 0;
int index_led = 0;

int buffer_led[2] = { 0, 0 };

int index00 = 0;
