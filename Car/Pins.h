

//This header will be used to define all of our pins and globals in one place.

#ifndef PINS_H_
#define PINS_H_
#include "cy_retarget_io.h"
//Pins
#define MotorA (P5_4)
#define MotorB (P5_5)
#define MotorC (P5_6)
#define MotorD (P5_7)
#define VoorAchterPinA (P8_1)
#define VoorAchterPinB (P8_6)
#define VoorAchterPinC (P8_4)
#define VoorAchterPinD (P8_3)
#define TRIG_PIN_Sensor1 (P9_1)
#define ECHO_PIN_Sensor1 (P9_2)

//Global defines
#define Frequentie (10u)

//Globals
cyhal_pwm_t pwm_MotorA;
cyhal_pwm_t pwm_MotorB;
cyhal_pwm_t pwm_MotorC;
cyhal_pwm_t pwm_MotorD;
cyhal_timer_t timer_obj;
uint8_t Speed = 90;
bool StoppedRecently = false;

void InitGPIOPins()
{
	printf("\rInitGPIOPins...\n\r");
	cyhal_gpio_init(VoorAchterPinA, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, 1);
	cyhal_gpio_init(VoorAchterPinB, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, 1);
	cyhal_gpio_init(VoorAchterPinC, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, 1);
	cyhal_gpio_init(VoorAchterPinD, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, 1);

    cyhal_gpio_init(TRIG_PIN_Sensor1, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, 0);
    cyhal_gpio_init(ECHO_PIN_Sensor1, CYHAL_GPIO_DIR_INPUT, CYHAL_GPIO_DRIVE_NONE, 0);
}

void InitMotorPins()
{
	printf("\rInitMotorPins...\n\r");
    cyhal_pwm_init(&pwm_MotorA, MotorA, NULL);
    cyhal_pwm_init(&pwm_MotorB, MotorB, NULL);
    cyhal_pwm_init(&pwm_MotorC, MotorC, NULL);
    cyhal_pwm_init(&pwm_MotorD, MotorD, NULL);
}

void InitTimer()
{
	printf("\rInitTimer...\n\r");
    cyhal_timer_cfg_t timer_cfg = {
        .compare_value = 0,
        .period = 0xFFFFFFFF,              // Grootste periode (32-bits)
        .direction = CYHAL_TIMER_DIR_UP,
        .is_compare = false,
        .is_continuous = false,
        .value = 0
    };

    cyhal_timer_init(&timer_obj, NC, NULL);
    cyhal_timer_configure(&timer_obj, &timer_cfg);
    cyhal_timer_set_frequency(&timer_obj, 1000000); // Instellen op 1 MHz voor tijd in microseconden

}

#endif /* PINS_H_ */


/*

Voorste wielen :
A-IA = GND
A-IB = P5_6
B-IA = P5_7
B-IB = GND

Achterste Wielen :
A-IA = GND
A-IB = P5_5
B-IA = P5_4
B-IB = GND



*/
