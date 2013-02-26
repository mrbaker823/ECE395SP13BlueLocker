#include "io_experiment.h"
//#include "uart.h"
extern void PIOINT0_IRQHandler(){

	GPIO0_output_toggle(GPIO_P4);
	GPIO0_interrupt_clear(GPIO_P6);

}

extern void UART_IRQHandler(){

//	int i;

	if ((UART_buffer[UART_index++] = UART_data_read()) == '\r') {
		// do stuff to process the string
		UART_data_write_string("I totally see a newline!\r\n");

		UART_buffer[UART_index - 1] = '\0';
		UART_data_write_string("I see \"");
		UART_data_write_string(UART_buffer);
		UART_data_write_string("\"!\r\n");
		UART_index = 0;
		UART_done = 1;
		UART_interrupt_disable();

	} /*else {

		UART_buffer[UART_index] = '\0';
		UART_data_write_string("I see \"");
		UART_data_write_string(UART_buffer);
		UART_data_write_string("\"!\r\n");

	}  */ /* enable this block to have character by character echo */


//	data = LPC_UART->RBR;

//	LPC_UART->SCR &= ~(0x000000FF);
//	LPC_UART->SCR |= (data & 0x000000FF);
//    these two lines are scratch register writes;
//    they shouldn't be needed

	GPIO0_output_toggle(GPIO_P4);
//	UART_data_write_string("Character binary: ");
//	for (i = 7; i >= 0; i--) {
//		if ((UART_buffer[UART_index-1] & (1 << i)) != 0) {
//			UART_data_write('1');
//		} else {
//			UART_data_write('0');
//		}	
//	}
//	UART_data_write_string("'\\r' line binary: ");
//	for (i = 7; i >= 0; i--) {
//		if (('\r' & (1 << i)) != 0) {
//			UART_data_write('1');
//		} else {
//			UART_data_write('0');
//		}	
//	}
//	UART_data_write_string("'\\n' line binary: ");
//	for (i = 7; i >= 0; i--) {
//		if (('\n' & (1 << i)) != 0) {
//			UART_data_write('1');
//		} else {
//			UART_data_write('0');
//		}	
//	}
//	UART_data_write_string("!\r\n");
}
