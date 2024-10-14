 /******************************************************************************
 *
 * Module: LEDS
 *
 * File Name: led.h
 *
 * Description: Header file for the LEDS driver
 *
 * Author: Mohamed Gamal
 *
 *******************************************************************************/

#ifndef LED_H_
#define LED_H_

#include "std_types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

 /* Define the logic level for positive and negative logic.
 */
#define POSITIVE_LOGIC   LOGIC_HIGH
#define NEGATIVE_LOGIC   LOGIC_LOW

/*
 * Define the logic used to control the LEDs.
 */
#define LED_LOGIC        POSITIVE_LOGIC

/*
 * Define the port and the initial pin number where the LEDs are connected.
 * The LEDs are assumed to be connected to consecutive pins starting from LEDS_INIT_PIN.
 */
#define LEDS_PORT        PORTC_ID  // Port where the LEDs are connected
#define LEDS_INIT_PIN    PIN0_ID   // Starting pin number for the LEDs
/***************************************/

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

/*
 * Enum to identify the individual LEDs.
 * - LED1: Represents the first LED connected to LEDS_INIT_PIN.
 * - LED2: Represents the second LED connected to LEDS_INIT_PIN+1.
 * - LED3: Represents the third LED connected to LEDS_INIT_PIN+2.
 */
typedef enum
{
	LED1=1, LED2, LED3
} LED_ID;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Function to initialize the LED pins as output.
 * It sets the pins (LEDS_INIT_PIN, LEDS_INIT_PIN+1, LEDS_INIT_PIN+2) as output to control the LEDs.
 */
void LEDS_init(void);

/*
 * Description:
 * Function to turn on a specific LED.
 * It takes the LED ID as an argument and turns on the corresponding LED by setting the pin to the appropriate logic level.
 */
void LED_on(LED_ID id);

/*
 * Description:
 * Function to turn off a specific LED.
 * It takes the LED ID as an argument and turns off the corresponding LED by setting the pin to the opposite logic level.
 */
void LED_off(LED_ID id);

#endif /* LED_H_ */
