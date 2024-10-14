/******************************************************************************
 *
 * Module: Ultrasonic
 *
 * File Name: ultrasonic.c
 *
 * Description: Source file for the Ultrasonic driver
 *
 * Author: Mohamed Gamal
 *
 *******************************************************************************/

#include "ultrasonic.h"
#include "icu.h"
#include "gpio.h"
#include <util/delay.h>

/*
 * Description:
 * Static variables to restrict their scope to this file.
 */
static uint8 g_edgeCount = 0; // Counter for detected edges
static uint16 g_timeHigh = 0; // Duration of echo signal
static uint16 distance_cm = 0; // Calculated distance in cm

/*
 * Description:
 * ICU configuration for edge detection and timer.
 */
static ICU_ConfigType ICU_Configurations = {F_CPU_8, RAISING};

/*
 * Description:
 * Edge processing function called on edge detection.
 * It increments the edge count and handles timing.
 */
static void Ultrasonic_edgeProcessing(void)
{
	g_edgeCount++; /* Increment edge count */

	if(g_edgeCount == 1)
	{
		/* Start timing on first rising edge */
		ICU_clearTimerValue(); /* Clear timer to begin measurement */
		ICU_setEdgeDetectionType(FALLING); /* Detect falling edge next */
	}
	else if(g_edgeCount == 2)
	{
		/* Capture time on falling edge */
		g_timeHigh = ICU_getInputCaptureValue(); /* Store the duration of the echo */
		ICU_setEdgeDetectionType(RAISING); /* Prepare for the next rising edge */
		ICU_clearTimerValue(); /* Clear timer for next measurement */
	}
}

/*
 * Description:
 * Initialization function for the ultrasonic sensor and ICU.
 * It sets up the ICU and trigger pin direction.
 */
void Ultrasonic_init(void)
{
	ICU_init(&ICU_Configurations); /* Initialize ICU with configurations */
	ICU_setCallBack(&Ultrasonic_edgeProcessing); /* Set callback for edge processing */
	GPIO_setupPinDirection(TRIGGER_PORT, TRIGGER_PIN, PIN_OUTPUT); /* Set trigger pin as output */
	GPIO_writePin(TRIGGER_PORT, TRIGGER_PIN, LOGIC_LOW); /* Ensure trigger pin is low initially */
}

/*
 * Description:
 * Trigger the ultrasonic sensor to send out a pulse.
 */
static void Ultrasonic_Trigger(void)
{
	GPIO_writePin(TRIGGER_PORT, TRIGGER_PIN, LOGIC_HIGH); /* Send trigger pulse */
	_delay_us(10); // Pulse width for HC-SR04
	GPIO_writePin(TRIGGER_PORT, TRIGGER_PIN, LOGIC_LOW); /* Reset trigger pin to low */
}

/*
 * Description:
 * Read the distance from the ultrasonic sensor.
 * It triggers the sensor and waits for echo response.
 * Returns:
 * - Distance in centimeters.
 */
uint16 Ultrasonic_readDistance(void)
{
	Ultrasonic_Trigger(); /* Trigger the sensor */

	/* Wait for two edges to complete measurement */
	while (g_edgeCount < 2);
	g_edgeCount = 0; /* Reset edge count for next measurement */

	/* Calculate distance in cm using the high time value */
	distance_cm = (uint16)((float32)(g_timeHigh) / 117.6);

	return (distance_cm + 1); /* Return calculated distance */
}
