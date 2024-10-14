/******************************************************************************
 *
 * Module: Ultrasonic
 *
 * File Name: ultrasonic.h
 *
 * Description: Header file for the Ultrasonic driver
 *
 * Author: Mohamed Gamal
 *
 *******************************************************************************/

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h" /* Include standard types header */

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Define the port and pin for the ultrasonic sensor trigger */
#define TRIGGER_PORT    PORTD_ID /* Trigger port */
#define TRIGGER_PIN     PIN7_ID    /* Trigger pin */

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Function to initialize the ultrasonic sensor.
 * Sets up the necessary configurations and pin directions.
 */
void Ultrasonic_init(void);

/*
 * Description:
 * Function to read the distance measured by the ultrasonic sensor.
 * Returns:
 * - Distance in centimeters.
 */
uint16 Ultrasonic_readDistance(void);

#endif /* ULTRASONIC_H_ */
