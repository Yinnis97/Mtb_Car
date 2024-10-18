

#ifndef FUNCTIONSMOTOR_H_
#define FUNCTIONSMOTOR_H_
#include "Pins.h"
#include "cy_retarget_io.h"



void StartMotors()
{
	cyhal_pwm_start(&pwm_MotorA);
	cyhal_pwm_start(&pwm_MotorB);
	cyhal_pwm_start(&pwm_MotorC);
	cyhal_pwm_start(&pwm_MotorD);
}

void StopMotors()
{
    cyhal_pwm_set_duty_cycle(&pwm_MotorA, 0, Frequentie);
    cyhal_pwm_set_duty_cycle(&pwm_MotorB, 0, Frequentie);
    cyhal_pwm_set_duty_cycle(&pwm_MotorC, 0, Frequentie);
    cyhal_pwm_set_duty_cycle(&pwm_MotorD, 0, Frequentie);
}

void RechtsDraaien()
{
	printf("\rRechts\n\r");
    cyhal_pwm_set_duty_cycle(&pwm_MotorA, Speed, Frequentie);
    cyhal_pwm_set_duty_cycle(&pwm_MotorB, 0, Frequentie);
    cyhal_pwm_set_duty_cycle(&pwm_MotorC, Speed, Frequentie);
    cyhal_pwm_set_duty_cycle(&pwm_MotorD, 0, Frequentie);
}

void LinksDraaien()
{
	printf("\rLinks\n\r");
    cyhal_pwm_set_duty_cycle(&pwm_MotorA, 0, Frequentie);
    cyhal_pwm_set_duty_cycle(&pwm_MotorB, Speed, Frequentie);
    cyhal_pwm_set_duty_cycle(&pwm_MotorC, 0, Frequentie);
    cyhal_pwm_set_duty_cycle(&pwm_MotorD, Speed, Frequentie);
}

void Vooruit()
{
	printf("\rVooruit\n\r");
    cyhal_pwm_set_duty_cycle(&pwm_MotorA, Speed, Frequentie);
    cyhal_pwm_set_duty_cycle(&pwm_MotorB, Speed, Frequentie);
    cyhal_pwm_set_duty_cycle(&pwm_MotorC, Speed, Frequentie);
    cyhal_pwm_set_duty_cycle(&pwm_MotorD, Speed, Frequentie);
}



#endif
