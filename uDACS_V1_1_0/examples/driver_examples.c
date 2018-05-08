/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_examples.h"
#include "driver_init.h"
#include "utils.h"

/**
 * Example of using AD_SPI to write "Hello World" using the IO abstraction.
 *
 * Since the driver is asynchronous we need to use statically allocated memory for string
 * because driver initiates transfer and then returns before the transmission is completed.
 *
 * Once transfer has been completed the tx_cb function will be called.
 */

static uint8_t example_AD_SPI[12] = "Hello World!";

static void complete_cb_AD_SPI(const struct spi_m_async_descriptor *const io_descr)
{
	/* Transfer completed */
}

void AD_SPI_example(void)
{
	struct io_descriptor *io;
	spi_m_async_get_io_descriptor(&AD_SPI, &io);

	spi_m_async_register_callback(&AD_SPI, SPI_M_ASYNC_CB_XFER, (FUNC_PTR)complete_cb_AD_SPI);
	spi_m_async_enable(&AD_SPI);
	io_write(io, example_AD_SPI, 12);
}

static uint8_t UC_I2C_example_str[12] = "Hello World!";

void UC_I2C_tx_complete(struct i2c_m_async_desc *const i2c)
{
}

void UC_I2C_example(void)
{
	struct io_descriptor *UC_I2C_io;

	i2c_m_async_get_io_descriptor(&UC_I2C, &UC_I2C_io);
	i2c_m_async_enable(&UC_I2C);
	i2c_m_async_register_callback(&UC_I2C, I2C_M_ASYNC_TX_COMPLETE, (FUNC_PTR)UC_I2C_tx_complete);
	i2c_m_async_set_slaveaddr(&UC_I2C, 0x12, I2C_M_SEVEN);

	io_write(UC_I2C_io, UC_I2C_example_str, 12);
}

/**
 * Example of using SD_SPI to write "Hello World" using the IO abstraction.
 *
 * Since the driver is asynchronous we need to use statically allocated memory for string
 * because driver initiates transfer and then returns before the transmission is completed.
 *
 * Once transfer has been completed the tx_cb function will be called.
 */

static uint8_t example_SD_SPI[12] = "Hello World!";

static void complete_cb_SD_SPI(const struct spi_m_async_descriptor *const io_descr)
{
	/* Transfer completed */
}

void SD_SPI_example(void)
{
	struct io_descriptor *io;
	spi_m_async_get_io_descriptor(&SD_SPI, &io);

	spi_m_async_register_callback(&SD_SPI, SPI_M_ASYNC_CB_XFER, (FUNC_PTR)complete_cb_SD_SPI);
	spi_m_async_enable(&SD_SPI);
	io_write(io, example_SD_SPI, 12);
}

/**
 * Example of using USART_CTRL to write "Hello World" using the IO abstraction.
 *
 * Since the driver is asynchronous we need to use statically allocated memory for string
 * because driver initiates transfer and then returns before the transmission is completed.
 *
 * Once transfer has been completed the tx_cb function will be called.
 */

static uint8_t example_USART_CTRL[12] = "Hello World!";

static void tx_cb_USART_CTRL(const struct usart_async_descriptor *const io_descr)
{
	/* Transfer completed */
}

void USART_CTRL_example(void)
{
	struct io_descriptor *io;

	usart_async_register_callback(&USART_CTRL, USART_ASYNC_TXC_CB, tx_cb_USART_CTRL);
	/*usart_async_register_callback(&USART_CTRL, USART_ASYNC_RXC_CB, rx_cb);
	usart_async_register_callback(&USART_CTRL, USART_ASYNC_ERROR_CB, err_cb);*/
	usart_async_get_io_descriptor(&USART_CTRL, &io);
	usart_async_enable(&USART_CTRL);

	io_write(io, example_USART_CTRL, 12);
}

static struct timer_task TIMER_0_task1, TIMER_0_task2;
/**
 * Example of using TIMER_0.
 */
static void TIMER_0_task1_cb(const struct timer_task *const timer_task)
{
}

static void TIMER_0_task2_cb(const struct timer_task *const timer_task)
{
}

void TIMER_0_example(void)
{
	TIMER_0_task1.interval = 100;
	TIMER_0_task1.cb       = TIMER_0_task1_cb;
	TIMER_0_task1.mode     = TIMER_TASK_REPEAT;
	TIMER_0_task2.interval = 200;
	TIMER_0_task2.cb       = TIMER_0_task2_cb;
	TIMER_0_task2.mode     = TIMER_TASK_REPEAT;

	timer_add_task(&TIMER_0, &TIMER_0_task1);
	timer_add_task(&TIMER_0, &TIMER_0_task2);
	timer_start(&TIMER_0);
}
