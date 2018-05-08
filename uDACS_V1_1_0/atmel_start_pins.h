/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_PINS_H_INCLUDED
#define ATMEL_START_PINS_H_INCLUDED

#include <hal_gpio.h>

// SAMD21 has 8 pin functions

#define GPIO_PIN_FUNCTION_A 0
#define GPIO_PIN_FUNCTION_B 1
#define GPIO_PIN_FUNCTION_C 2
#define GPIO_PIN_FUNCTION_D 3
#define GPIO_PIN_FUNCTION_E 4
#define GPIO_PIN_FUNCTION_F 5
#define GPIO_PIN_FUNCTION_G 6
#define GPIO_PIN_FUNCTION_H 7

#define AD_MOSI GPIO(GPIO_PORTA, 8)
#define AD_SCLK GPIO(GPIO_PORTA, 9)
#define AD_MISO GPIO(GPIO_PORTA, 10)
#define ADC_CS GPIO(GPIO_PORTA, 11)
#define SD_MOSI GPIO(GPIO_PORTA, 12)
#define SD_SCLK GPIO(GPIO_PORTA, 13)
#define SD_CS GPIO(GPIO_PORTA, 14)
#define SD_MISO GPIO(GPIO_PORTA, 15)
#define PMOD7 GPIO(GPIO_PORTA, 16)
#define PMOD5 GPIO(GPIO_PORTA, 17)
#define PMOD3 GPIO(GPIO_PORTA, 18)
#define PMOD1 GPIO(GPIO_PORTA, 19)
#define SPR29 GPIO(GPIO_PORTA, 20)
#define PMOD2 GPIO(GPIO_PORTA, 21)
#define UC_SDA GPIO(GPIO_PORTA, 22)
#define UC_SCL GPIO(GPIO_PORTA, 23)
#define SD GPIO(GPIO_PORTA, 27)
#define PMOD4 GPIO(GPIO_PORTA, 28)
#define START GPIO(GPIO_PORTB, 2)
#define DRDY GPIO(GPIO_PORTB, 3)
#define SPR7 GPIO(GPIO_PORTB, 8)
#define DAC_CS GPIO(GPIO_PORTB, 9)
#define PMOD8 GPIO(GPIO_PORTB, 10)
#define PMOD6 GPIO(GPIO_PORTB, 11)
#define UART_TX GPIO(GPIO_PORTB, 22)
#define UART_RX GPIO(GPIO_PORTB, 23)

#endif // ATMEL_START_PINS_H_INCLUDED
