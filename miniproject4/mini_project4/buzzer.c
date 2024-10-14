 /******************************************************************************
 *
 * Module: Buzzer
 *
 * File Name: buzzer.c
 *
 * Description: Source file for the Buzzer driver
 *
 * Author: Mohamed Gamal
 *
 *******************************************************************************/


#include "buzzer.h"
#include "gpio.h"

/*
 * Description:
 * Function to initialize the buzzer by setting up the pin direction
 * as output and ensuring the buzzer is off initially.
 */
void BUZZER_init(void)
{
	/* Set the buzzer pin as an output */
	GPIO_setupPinDirection(BUZZER_PORT, BUZZER_PIN, PIN_OUTPUT);

	/* Initially set the buzzer pin to low (buzzer off) */
	GPIO_writePin(BUZZER_PORT, BUZZER_PIN, LOGIC_LOW);
}

/*
 * Description:
 * Function to turn on the buzzer by setting the pin to high.
 */
void BUZZER_on(void)
{
	/* Set the buzzer pin to high (buzzer on) */
	GPIO_writePin(BUZZER_PORT, BUZZER_PIN, LOGIC_HIGH);
}

/*
 * Description:
 * Function to turn off the buzzer by setting the pin to low.
 */
void BUZZER_OFF(void)
{
	/* Set the buzzer pin to low (buzzer off) */
	GPIO_writePin(BUZZER_PORT, BUZZER_PIN, LOGIC_LOW);
}
