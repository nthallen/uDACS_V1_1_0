/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>
#include <hpl_gclk_base.h>
#include <hpl_pm_base.h>
#include <hpl_rtc_base.h>

/*! The buffer size for USART */
#define USART_CTRL_BUFFER_SIZE 16

struct usart_async_descriptor USART_CTRL;
struct timer_descriptor       TIMER_0;

static uint8_t USART_CTRL_buffer[USART_CTRL_BUFFER_SIZE];

struct spi_m_async_descriptor AD_SPI;

struct i2c_m_async_desc UC_I2C;

struct spi_m_async_descriptor SD_SPI;

void AD_SPI_PORT_init(void)
{

	// Set pin direction to output
	gpio_set_pin_direction(AD_MOSI, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(AD_MOSI,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	gpio_set_pin_function(AD_MOSI, PINMUX_PA08C_SERCOM0_PAD0);

	// Set pin direction to output
	gpio_set_pin_direction(AD_SCLK, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(AD_SCLK,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	gpio_set_pin_function(AD_SCLK, PINMUX_PA09C_SERCOM0_PAD1);

	// Set pin direction to input
	gpio_set_pin_direction(AD_MISO, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(AD_MISO,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(AD_MISO, PINMUX_PA10C_SERCOM0_PAD2);
}

void AD_SPI_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM0);
	_gclk_enable_channel(SERCOM0_GCLK_ID_CORE, CONF_GCLK_SERCOM0_CORE_SRC);
}

void AD_SPI_init(void)
{
	AD_SPI_CLOCK_init();
	spi_m_async_init(&AD_SPI, SERCOM0);
	AD_SPI_PORT_init();
}

void UC_I2C_PORT_init(void)
{

	gpio_set_pin_pull_mode(UC_SDA,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(UC_SDA, PINMUX_PA22C_SERCOM3_PAD0);

	gpio_set_pin_pull_mode(UC_SCL,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(UC_SCL, PINMUX_PA23C_SERCOM3_PAD1);
}

void UC_I2C_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM3);
	_gclk_enable_channel(SERCOM3_GCLK_ID_CORE, CONF_GCLK_SERCOM3_CORE_SRC);
	_gclk_enable_channel(SERCOM3_GCLK_ID_SLOW, CONF_GCLK_SERCOM3_SLOW_SRC);
}

void UC_I2C_init(void)
{
	UC_I2C_CLOCK_init();
	i2c_m_async_init(&UC_I2C, SERCOM3);
	UC_I2C_PORT_init();
}

void SD_SPI_PORT_init(void)
{

	// Set pin direction to output
	gpio_set_pin_direction(SD_MOSI, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(SD_MOSI,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	gpio_set_pin_function(SD_MOSI, PINMUX_PA12D_SERCOM4_PAD0);

	// Set pin direction to output
	gpio_set_pin_direction(SD_SCLK, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(SD_SCLK,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	gpio_set_pin_function(SD_SCLK, PINMUX_PA13D_SERCOM4_PAD1);

	// Set pin direction to input
	gpio_set_pin_direction(SD_MISO, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(SD_MISO,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(SD_MISO, PINMUX_PA15D_SERCOM4_PAD3);
}

void SD_SPI_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM4);
	_gclk_enable_channel(SERCOM4_GCLK_ID_CORE, CONF_GCLK_SERCOM4_CORE_SRC);
}

void SD_SPI_init(void)
{
	SD_SPI_CLOCK_init();
	spi_m_async_init(&SD_SPI, SERCOM4);
	SD_SPI_PORT_init();
}

/**
 * \brief USART Clock initialization function
 *
 * Enables register interface and peripheral clock
 */
void USART_CTRL_CLOCK_init()
{

	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM5);
	_gclk_enable_channel(SERCOM5_GCLK_ID_CORE, CONF_GCLK_SERCOM5_CORE_SRC);
}

/**
 * \brief USART pinmux initialization function
 *
 * Set each required pin to USART functionality
 */
void USART_CTRL_PORT_init()
{

	gpio_set_pin_function(UART_TX, PINMUX_PB22D_SERCOM5_PAD2);

	gpio_set_pin_function(UART_RX, PINMUX_PB23D_SERCOM5_PAD3);
}

/**
 * \brief USART initialization function
 *
 * Enables USART peripheral, clocks and initializes USART driver
 */
void USART_CTRL_init(void)
{
	USART_CTRL_CLOCK_init();
	usart_async_init(&USART_CTRL, SERCOM5, USART_CTRL_buffer, USART_CTRL_BUFFER_SIZE, (void *)NULL);
	USART_CTRL_PORT_init();
}

/**
 * \brief Timer initialization function
 *
 * Enables Timer peripheral, clocks and initializes Timer driver
 */
static void TIMER_0_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBA, RTC);
	_gclk_enable_channel(RTC_GCLK_ID, CONF_GCLK_RTC_SRC);
	timer_init(&TIMER_0, RTC, _rtc_get_timer());
}

void system_init(void)
{
	init_mcu();

	// GPIO on PA11

	// Set pin direction to output
	gpio_set_pin_direction(ADC_CS, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(ADC_CS,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	gpio_set_pin_function(ADC_CS, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA14

	// Set pin direction to output
	gpio_set_pin_direction(SD_CS, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(SD_CS,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	gpio_set_pin_function(SD_CS, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA16

	// Set pin direction to input
	gpio_set_pin_direction(PMOD7, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PMOD7,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PMOD7, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA17

	// Set pin direction to input
	gpio_set_pin_direction(PMOD5, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PMOD5,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PMOD5, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA18

	// Set pin direction to input
	gpio_set_pin_direction(PMOD3, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PMOD3,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PMOD3, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA19

	// Set pin direction to input
	gpio_set_pin_direction(PMOD1, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PMOD1,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PMOD1, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA20

	// Set pin direction to input
	gpio_set_pin_direction(SPR29, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(SPR29,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(SPR29, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA21

	// Set pin direction to input
	gpio_set_pin_direction(PMOD2, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PMOD2,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PMOD2, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA27

	// Set pin direction to input
	gpio_set_pin_direction(SD, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(SD,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(SD, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA28

	// Set pin direction to input
	gpio_set_pin_direction(PMOD4, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PMOD4,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PMOD4, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB02

	// Set pin direction to output
	gpio_set_pin_direction(START, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(START,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	gpio_set_pin_function(START, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB03

	// Set pin direction to input
	gpio_set_pin_direction(DRDY, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(DRDY,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(DRDY, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB08

	// Set pin direction to output
	gpio_set_pin_direction(SPR7, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(SPR7,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	gpio_set_pin_function(SPR7, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB09

	// Set pin direction to output
	gpio_set_pin_direction(DAC_CS, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(DAC_CS,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	gpio_set_pin_function(DAC_CS, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB10

	// Set pin direction to input
	gpio_set_pin_direction(PMOD8, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PMOD8,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PMOD8, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB11

	// Set pin direction to input
	gpio_set_pin_direction(PMOD6, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PMOD6,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PMOD6, GPIO_PIN_FUNCTION_OFF);

	AD_SPI_init();

	UC_I2C_init();

	SD_SPI_init();
	USART_CTRL_init();

	TIMER_0_init();
}
