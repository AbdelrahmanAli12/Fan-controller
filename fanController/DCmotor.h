/*
 * DCmotor.h
 *
 *  Created on: 9 May 2023
 *      Author: Abdelrahman Ali
 */
#include<stdio.h>
#include "std_types.h"
#include "pwm.h"

enum DcMotor_State {CW , ACW , stop};

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

void DcMotor_Init(void);

void DcMotor_Rotate(enum DcMotor_State state,uint8 speed);

#endif /* DCMOTOR_H_ */
