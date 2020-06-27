#ifndef GPIODEFINE_H
#define GPIODEFINE_H

typedef uint8_t Pin;

/*
 * One wire bus for access DS18B20 tempuature devices.
 */
#define OneWirePin 4

/*
 * I2C wire bus for access graphics control and DS3231 RTC devices.
 */
#define I2CSDA 12
#define I2CSCL 14

/*
 * IR pin for connect infrared remote control receiver devices.
 */
#define IRPin 5

#ifdef LED_BUILTIN
#	define LEDPin LED_BUILTIN
#else
#	define LEDPin 2
#endif

#ifdef BTN_BUILTIN
#	define BTNPin BTN_BUILTIN
#else
#	define BTNPin 0
#endif

#endif // GPIODEFINE_H
