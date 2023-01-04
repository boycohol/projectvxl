# include "main.h"
# define N0_OF_BUTTONS 4
#define DURATION_FOR_AUTO_INCREASING 50
# define BUTTON_IS_PRESSED GPIO_PIN_RESET
# define BUTTON_IS_RELEASED GPIO_PIN_SET

static GPIO_PinState buttonBuffer[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS];

static uint8_t flagForButtonPress1s[N0_OF_BUTTONS];
static uint16_t counterForButtonPress1s[N0_OF_BUTTONS];

void button_reading(void) {
	for (uint16_t i = 0; i < N0_OF_BUTTONS; i++) {
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		if (i == 0) {
			debounceButtonBuffer1[0] = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port,
			BUTTON1_Pin);
		} else if (i == 1) {
			debounceButtonBuffer1[1] = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port,
			BUTTON2_Pin);
		} else if (i == 2) {
			debounceButtonBuffer1[2] = HAL_GPIO_ReadPin(BUTTON3_GPIO_Port,
			BUTTON3_Pin);
		} else if (i == 3) {
			debounceButtonBuffer1[3] = HAL_GPIO_ReadPin(BUTTON4_GPIO_Port,
			BUTTON4_Pin);
		}
		if (debounceButtonBuffer1[i] == debounceButtonBuffer2[i])
			buttonBuffer[i] = debounceButtonBuffer1[i];
		if (buttonBuffer[i] == BUTTON_IS_PRESSED) {
			if (counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING) {
				flagForButtonPress1s[i] = 0;
				counterForButtonPress1s[i]++;
			} else {
				flagForButtonPress1s[i] = 1;
			}
		} else {
			flagForButtonPress1s[i] = 0;
			counterForButtonPress1s[i] = 0;
		}
	}
}

int isButtonPressed(int index) {
	if (index >= N0_OF_BUTTONS)
		return 0;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}
