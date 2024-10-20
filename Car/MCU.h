
#ifndef MCU_H_
#define MCU_H_

#include "Pins.h"


void mpu6050_init()
{
    uint8_t data[2];

    // Wake up the MPU6050 (PWR_MGMT_1 naar 0x00)
    data[0] = PWR_MGMT_1;
    data[1] = 0x00;
    cyhal_i2c_master_write(&i2c, MPU6050_ADDR, data, 2, 0, true);
}


void mpu6050_read_accel(int16_t* accel_x, int16_t* accel_y, int16_t* accel_z)
{
    uint8_t reg = ACCEL_XOUT_H;
    //buffer moet 6 groot zijn want we hebben een X,Y en Z , met elk 2 bytes.
    uint8_t buffer[6];

    // Lees 6 bytes van de accelerometer registers
    cyhal_i2c_master_write(&i2c, MPU6050_ADDR, &reg, 1, 0, true);
    cyhal_i2c_master_read(&i2c, MPU6050_ADDR, buffer, 6, 0, true);

    //Waarde wordt opgeslagen in 2 byte waardoor de hoogste 8 en de laagste 8 apart moeten worden opgeslagen.
    //Om dan samen gebracht te worden. 1 van de bytes wordt verschoven naar links met 8 bits waardoor ze de eerste 8 vormen.
    //de andere 8 bits worden er dan aan toegevoegd met een or operatie.
    *accel_x = (buffer[0] << 8) | buffer[1];
    *accel_y = (buffer[2] << 8) | buffer[3];
    *accel_z = (buffer[4] << 8) | buffer[5];
}


#endif /* MCU_H_ */
