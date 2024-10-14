/*
 ================================================================================================
 File Name    : car_parking_sensor

 Author      : Mohamed Gamal

 Description : Car Parking Sensor Using ATmega32, Ultrasonic Sensor, LCD Display, LEDs,
               and Buzzer.

 Date        : Oct 12, 2024
 ================================================================================================
 */

#include "buzzer.h"
#include "led.h"
#include "lcd.h"
#include "ultrasonic.h"
#include <util/delay.h>
#include "std_types.h"
#include "avr/io.h" /* To use the IO Ports Registers */

int main(void)
{
	SREG|=(1<<7); /* Enable global interrupts */
	uint16 distance = 0; /* Variable to store the measured distance */

	Ultrasonic_init(); /* Initialize the ultrasonic sensor */
	LCD_init(); /* Initialize the LCD display */
	LEDS_init(); /* Initialize the LEDs */
	BUZZER_init(); /* Initialize the buzzer */

	LCD_displayStringRowColumn(0, 0, "Distance=    cm"); /* Display initial message on LCD */

	for (;;)
	{
		distance = Ultrasonic_readDistance(); /* Read distance from ultrasonic sensor */
		LCD_moveCursor(0, 9); /* Move cursor to the position for distance display */

		LCD_intgerToString(distance); /* Convert distance to string and display */
		LCD_displayCharacter(' '); /* Clear any previous characters */

		if(distance > 5)
		{
			LCD_displayStringRowColumn(1, 6, "         "); /* Clear previous status */
		}

		/* Control logic based on distance */
		if (distance > 20)
		{
			BUZZER_OFF(); /* Turn off buzzer */
			LED_off(LED1); /* Turn off LED1 */
			LED_off(LED2); /* Turn off LED2 */
			LED_off(LED3); /* Turn off LED3 */
		}
		else if (distance <= 20 && distance >= 16)
		{
			BUZZER_OFF(); /* Turn off buzzer */
			LED_on(LED1); /* Turn on LED1 */
			LED_off(LED2); /* Turn off LED2 */
			LED_off(LED3); /* Turn off LED3 */
		}
		else if (distance <= 15 && distance >= 11)
		{
			BUZZER_OFF(); /* Turn off buzzer */
			LED_on(LED1); /* Turn on LED1 */
			LED_on(LED2); /* Turn on LED2 */
			LED_off(LED3); /* Turn off LED3 */
		}
		else if (distance <= 10 && distance >= 6)
		{
			BUZZER_OFF(); /* Turn off buzzer */
			LED_on(LED1); /* Turn on LED1 */
			LED_on(LED2); /* Turn on LED2 */
			LED_on(LED3); /* Turn on LED3 */
		}
		else if (distance <= 5)
		{
			/* Flashing buzzer and LEDS */
			LCD_displayStringRowColumn(1, 6, "Stop !"); /* Display "Stop!" message */
			BUZZER_on(); /* Turn on buzzer */
			LED_on(LED1); /* Turn on LED1 */
			LED_on(LED2); /* Turn on LED2 */
			LED_on(LED3); /* Turn on LED3 */
			_delay_ms(300); /* Delay for visual indication */
			BUZZER_OFF(); /* Turn off buzzer */
			LED_off(LED1); /* Turn off LED1 */
			LED_off(LED2); /* Turn off LED2 */
			LED_off(LED3); /* Turn off LED3 */
			_delay_ms(300); /* Delay for visual indication */
		}
	}
}
