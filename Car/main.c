
#if defined (CY_USING_HAL)
#include "cyhal.h"
#endif
#include "cybsp.h"
#include "cy_retarget_io.h"
#include "FunctionsMotor.h"
#include "Sensor.h"
#include "Pins.h"
#include "MCU.h"

int main(void)
{
    cybsp_init();
    __enable_irq();
    cy_retarget_io_init(CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX, CY_RETARGET_IO_BAUDRATE);

	InitGPIOPins();
	InitMotorPins();
	InitTimer();
	InitI2C();
	mpu6050_init();

    StartMotors();
    Vooruit();

    for (;;)
    {
    	/*
    	if(measure_distance() > 10 && StoppedRecently == true )
    	{
    		printf("\rStarted Distance = %lu\n\r",measure_distance());
    		Vooruit();
    		StoppedRecently = false;
    	}
	    if(measure_distance() < 10 && StoppedRecently == false )
	    {
	    	printf("\rStopped Distance = %lu\n\r",measure_distance());
	    	StopMotors();
	    	StoppedRecently = true;
	    }

	    cyhal_system_delay_ms(500);
	    */

        mpu6050_read_accel(&accel_x, &accel_y, &accel_z);
        printf("\rAccel X: %d, Y: %d, Z: %d\n\r", accel_x, accel_y, accel_z);
        cyhal_system_delay_ms(1000);

    }
}


