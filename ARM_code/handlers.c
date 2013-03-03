#include "io_experiment.h"

extern void PIOINT0_IRQHandler(){

	GPIO0_output_toggle(GPIO_P4);
	GPIO0_interrupt_clear(GPIO_P6);

}

static int state = 0;

extern void UART_IRQHandler(){

	UART_buffer[UART_index++] = UART_data_read();

	if (UART_buffer[UART_index-1] == '\r') {
		UART_data_write_string("Carriage return\r\n");
		state = 1;
	} else if (state == 1) {
		if (UART_buffer[UART_index-1] == '\n'){
			// do stuff to process the string
			UART_data_write_string("I totally see a newline!\r\n");

			UART_buffer[UART_index - 2] = '\0';
			UART_data_write_string("I see \"");
			UART_data_write_string(UART_buffer);
			UART_data_write_string("\"!\r\n");
			UART_index = 0;
			UART_done = 1;
			UART_interrupt_disable();
		}
		state = 0;

	} 

	GPIO0_output_toggle(GPIO_P4);
}
