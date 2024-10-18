
#ifndef SENSOR_H_
#define SENSOR_H_
#include "Pins.h"


uint32_t measure_distance()
{

    // Reset de trigger pin
    cyhal_gpio_write(TRIG_PIN_Sensor1, false);
    cyhal_system_delay_us(2);

    // Trigger een ultrasonisch puls door de trigger pin hoog te maken voor 10 µs
    cyhal_gpio_write(TRIG_PIN_Sensor1, true);
    cyhal_system_delay_us(30);
    cyhal_gpio_write(TRIG_PIN_Sensor1, false);

    // Wacht tot de echo pin hoog gaat
    while (!cyhal_gpio_read(ECHO_PIN_Sensor1));

    // Start de timer
    cyhal_timer_reset(&timer_obj);
    cyhal_timer_start(&timer_obj);

    // Wacht tot de echo pin weer laag gaat
    while (cyhal_gpio_read(ECHO_PIN_Sensor1));

    // Stop de timer en lees de waarde
    uint32_t duration = cyhal_timer_read(&timer_obj);
    uint32_t distance = duration / 60;
    return distance;
}


#endif /* SENSOR_H_ */
