 /******************************************************************************
 *
 * Module: Buzzer
 *
 * File Name: buzzer.h
 *
 * Description: Header file for the Buzzer driver
 *
 * Author: Mohamed Gamal
 *
 *******************************************************************************/

#ifndef BUZZER_H_
#define BUZZER_H_

#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/*
 * Define the port and pin where the buzzer is connected.
 */
#define BUZZER_PORT PORTC_ID  // Buzzer is connected to Port D
#define BUZZER_PIN  PIN5_ID   // Buzzer is connected to Pin 3

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Function to initialize the buzzer.
 * It sets the buzzer pin direction as output and ensures the buzzer is off initially.
 */
void BUZZER_init(void);

/*
 * Description:
 * Function to turn the buzzer on by setting the buzzer pin to logic high.
 */
void BUZZER_on(void);

/*
 * Description:
 * Function to turn the buzzer off by setting the buzzer pin to logic low.
 */
void BUZZER_OFF(void);

#endif /* BUZZER_H_ */

