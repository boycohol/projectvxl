/*
 * global.h
 *
 *  Created on: Dec 14, 2022
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define MAX_BUFFER_SIZE	30

#define AUTO_MODE	1
#define MANUAL_MODE	2
#define TUNING_MODE	3
#define PEDES_MODE_ON	4
#define PEDES_MODE_OFF	5

#define INIT_MODE	10
#define RED_MODE	11
#define AMBER_MODE	12
#define GREEN_MODE	13

extern int status_mode;
extern int status_pedestrian_mode;
extern int led_mode;
extern int control_mode;

extern int led_count[3];
extern int final_led_count[3];

extern int state_led;
extern int index_led;

extern int buffer_led[2];

extern int index00;


#endif /* INC_GLOBAL_H_ */
