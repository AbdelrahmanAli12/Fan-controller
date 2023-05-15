/*
 * DCmotor.c
 *
 *  Created on: 9 May 2023
 *      Author: Abdelrahman
 */

#include "DCmotor.h"
#include "gpio.h"

void DcMotor_Init(void) {
	GPIO_setupPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN1_ID, PIN_OUTPUT);
	GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
	GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);

}

void DcMotor_Rotate(enum DcMotor_State state, uint8 speed) {

	if (state == CW) {
		// Rotate the DC motor clockwise
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_HIGH);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
		Timer0_Fast_PWM_Init(speed);
	} else if (state == ACW) {
		// Rotate the DC motor anti-clockwise
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_HIGH);
		Timer0_Fast_PWM_Init(speed);
	} else if (state == stop) {
		// Stop the DC motor
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
		Timer0_Fast_PWM_Init(speed);
	}

}
