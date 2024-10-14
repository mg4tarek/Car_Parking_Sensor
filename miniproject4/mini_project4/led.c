 /******************************************************************************
 *
 * Module: LEDS
 *
 * File Name: led.c
 *
 * Description: Source file for the LEDS driver
 *
 * Author: Mohamed Gamal
 *
 *******************************************************************************/


#include "led.h"
#include "gpio.h"

/*
 * Description:
 * Function to initialize the LEDs.
 * It sets the direction of the LED pins.
 */
void LEDS_init(void)
{
	/* Set the pin connected to LED1 as output */
	GPIO_setupPinDirection(LEDS_PORT, LEDS_INIT_PIN, PIN_OUTPUT);

	/* Set the pin connected to LED2 as output */
	GPIO_setupPinDirection(LEDS_PORT, LEDS_INIT_PIN+1, PIN_OUTPUT);

	/* Set the pin connected to LED3 as output */
	GPIO_setupPinDirection(LEDS_PORT, LEDS_INIT_PIN+2, PIN_OUTPUT);
}
/**************************************/
/*
 * Description:
 * Function to turn on a specific LED.
 * It takes the LED ID as an argument and turns on the corresponding LED by setting its pin to the desired logic level.
 * Arguments:
 *  - id: the ID of the LED to be turned on (LED1, LED2, or LED3).
 */
void LED_on(LED_ID id)
{
	switch(id)
	{
	case LED1:
		/* Turn on LED1 by setting its pin to the desired logic level */
		GPIO_writePin(LEDS_PORT, LEDS_INIT_PIN, LED_LOGIC);
		break;
	case LED2:
		/* Turn on LED2 by setting its pin to the desired logic level */
		GPIO_writePin(LEDS_PORT, LEDS_INIT_PIN+1, LED_LOGIC);
		break;
	case LED3:
		/* Turn on LED3 by setting its pin to the desired logic level */
		GPIO_writePin(LEDS_PORT, LEDS_INIT_PIN+2, LED_LOGIC);
		break;
	}
}

/*
 * Description:
 * Function to turn off a specific LED.
 * It takes the LED ID as an argument and turns off the corresponding LED by setting its pin to the opposite logic level.
 * Arguments:
 *  - id: the ID of the LED to be turned off (LED1, LED2, or LED3).
 */
void LED_off(LED_ID id)
{
	switch(id)
	{
	case LED1:
		/* Turn off LED1 by setting its pin to the opposite logic level */
		GPIO_writePin(LEDS_PORT, LEDS_INIT_PIN, !LED_LOGIC);
		break;
	case LED2:
		/* Turn off LED2 by setting its pin to the opposite logic level */
		GPIO_writePin(LEDS_PORT, LEDS_INIT_PIN+1, !LED_LOGIC);
		break;
	case LED3:
		/* Turn off LED3 by setting its pin to the opposite logic level */
		GPIO_writePin(LEDS_PORT, LEDS_INIT_PIN+2, !LED_LOGIC);
		break;
	}
}
