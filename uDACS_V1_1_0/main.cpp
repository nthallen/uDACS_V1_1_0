#include <atmel_start.h>

int main(int argc, char **argv)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	/* Replace with your application code */
	while (1) {
    delay_ms(250);
    gpio_set_pin_level(SPR7, true);
    delay_ms(750);
    gpio_set_pin_level(SPR7, false);
	}
}
