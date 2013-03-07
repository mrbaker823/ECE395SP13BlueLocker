

#ifndef __PORT_IO_H
#define __PORT_IO_H

#include <stdio.h>
#include "LPC11xx.h"

void GPIO_enable(void);
void GPIO_disable(void);
void GPIO_toggle(void);
int GPIO_state(void);

void port_1_dir_output(void);
void port_2_dir_output(void);
void port_3_dir_output(void);
void port_4_dir_output(void);  // reserved by default
void port_5_dir_output(void);  // open drain
void port_6_dir_output(void);
// ports 7 and 8 are VCC/GND
void port_9_dir_output(void);  // reserved by default
void port_10_dir_output(void); // reserved by default
void port_11_dir_output(void); // reserved by default
void port_12_dir_output(void); // programmer I/O by default
void port_13_dir_output(void); // 10ns glitch filter
void port_14_dir_output(void);
void port_15_dir_output(void);
void port_16_dir_output(void);
void port_17_dir_output(void);
void port_18_dir_output(void);
// ports 19 and 20 are for oscillator I/O
// ports 21 and 22 are VCC/GND
void port_23_dir_output(void); // reset by default
void port_24_dir_output(void);
void port_25_dir_output(void);
void port_26_dir_output(void);
void port_27_dir_output(void); // open drain
void port_28_dir_output(void); // high current

void port_1_dir_input(void);
void port_2_dir_input(void);
void port_3_dir_input(void);
void port_4_dir_input(void);  // reserved by default
void port_5_dir_input(void);  // open drain
void port_6_dir_input(void);
// ports 7 and 8 are VCC/GND
void port_9_dir_input(void);  // reserved by default
void port_10_dir_input(void); // reserved by default
void port_11_dir_input(void); // reserved by default
void port_12_dir_input(void); // programmer I/O by default
void port_13_dir_input(void); // 10ns glitch filter
void port_14_dir_input(void);
void port_15_dir_input(void);
void port_16_dir_input(void);
void port_17_dir_input(void);
void port_18_dir_input(void);
// ports 19 and 20 are for oscillator I/O
// ports 21 and 22 are VCC/GND
void port_23_dir_input(void); // reset by default
void port_24_dir_input(void);
void port_25_dir_input(void);
void port_26_dir_input(void);
void port_27_dir_input(void); // open drain
void port_28_dir_input(void); // high current

void port_1_dir_toggle(void);
void port_2_dir_toggle(void);
void port_3_dir_toggle(void);
void port_4_dir_toggle(void);  // reserved by default
void port_5_dir_toggle(void);  // open drain
void port_6_dir_toggle(void);
// ports 7 and 8 are VCC/GND
void port_9_dir_toggle(void);  // reserved by default
void port_10_dir_toggle(void); // reserved by default
void port_11_dir_toggle(void); // reserved by default
void port_12_dir_toggle(void); // programmer I/O by default
void port_13_dir_toggle(void); // 10ns glitch filter
void port_14_dir_toggle(void);
void port_15_dir_toggle(void);
void port_16_dir_toggle(void);
void port_17_dir_toggle(void);
void port_18_dir_toggle(void);
// ports 19 and 20 are for oscillator I/O
// ports 21 and 22 are VCC/GND
void port_23_dir_toggle(void); // reset by default
void port_24_dir_toggle(void);
void port_25_dir_toggle(void);
void port_26_dir_toggle(void);
void port_27_dir_toggle(void); // open drain
void port_28_dir_toggle(void); // high current

int port_1_dir_data(void);
int port_2_dir_data(void);
int port_3_dir_data(void);
int port_4_dir_data(void);  // reserved by default
int port_5_dir_data(void);  // open drain
int port_6_dir_data(void);
// ports 7 and 8 are VCC/GND
int port_9_dir_data(void);  // reserved by default
int port_10_dir_data(void); // reserved by default
int port_11_dir_data(void); // reserved by default
int port_12_dir_data(void); // programmer I/O by default
int port_13_dir_data(void); // 10ns glitch filter
int port_14_dir_data(void);
int port_15_dir_data(void);
int port_16_dir_data(void);
int port_17_dir_data(void);
int port_18_dir_data(void);
// ports 19 and 20 are for oscillator I/O
// ports 21 and 22 are VCC/GND
int port_23_dir_data(void); // reset by default
int port_24_dir_data(void);
int port_25_dir_data(void);
int port_26_dir_data(void);
int port_27_dir_data(void); // open drain
int port_28_dir_data(void); // high current

void port_1_high(void);
void port_2_high(void);
void port_3_high(void);
void port_4_high(void);  // reserved by default
void port_5_high(void);  // open drain
void port_6_high(void);
// ports 7 and 8 are VCC/GND
void port_9_high(void);  // reserved by default
void port_10_high(void); // reserved by default
void port_11_high(void); // reserved by default
void port_12_high(void); // programmer I/O by default
void port_13_high(void); // 10ns glitch filter
void port_14_high(void);
void port_15_high(void);
void port_16_high(void);
void port_17_high(void);
void port_18_high(void);
// ports 19 and 20 are for oscillator I/O
// ports 21 and 22 are VCC/GND
void port_23_high(void); // reset by default
void port_24_high(void);
void port_25_high(void);
void port_26_high(void);
void port_27_high(void); // open drain
void port_28_high(void); // high current

void port_1_low(void);
void port_2_low(void);
void port_3_low(void);
void port_4_low(void);  // reserved by default
void port_5_low(void);  // open drain
void port_6_low(void);
// ports 7 and 8 are VCC/GND
void port_9_low(void);  // reserved by default
void port_10_low(void); // reserved by default
void port_11_low(void); // reserved by default
void port_12_low(void); // programmer I/O by default
void port_13_low(void); // 10ns glitch filter
void port_14_low(void);
void port_15_low(void);
void port_16_low(void);
void port_17_low(void);
void port_18_low(void);
// ports 19 and 20 are for oscillator I/O
// ports 21 and 22 are VCC/GND
void port_23_low(void); // reset by default
void port_24_low(void);
void port_25_low(void);
void port_26_low(void);
void port_27_low(void); // open drain
void port_28_low(void); // high current

void port_1_toggle(void);
void port_2_toggle(void);
void port_3_toggle(void);
void port_4_toggle(void);  // reserved by default
void port_5_toggle(void);  // open drain
void port_6_toggle(void);
// ports 7 and 8 are VCC/GND
void port_9_toggle(void);  // reserved by default
void port_10_toggle(void); // reserved by default
void port_11_toggle(void); // reserved by default
void port_12_toggle(void); // programmer I/O by default
void port_13_toggle(void); // 10ns glitch filter
void port_14_toggle(void);
void port_15_toggle(void);
void port_16_toggle(void);
void port_17_toggle(void);
void port_18_toggle(void);
// ports 19 and 20 are for oscillator I/O
// ports 21 and 22 are VCC/GND
void port_23_toggle(void); // reset by default
void port_24_toggle(void);
void port_25_toggle(void);
void port_26_toggle(void);
void port_27_toggle(void); // open drain
void port_28_toggle(void); // high current

int port_1_data(void);
int port_2_data(void);
int port_3_data(void);
int port_4_data(void);  // reserved by default
int port_5_data(void);  // open drain
int port_6_data(void);
// ports 7 and 8 are VCC/GND
int port_9_data(void);  // reserved by default
int port_10_data(void); // reserved by default
int port_11_data(void); // reserved by default
int port_12_data(void); // programmer I/O by default
int port_13_data(void); // 10ns glitch filter
int port_14_data(void);
int port_15_data(void);
int port_16_data(void);
int port_17_data(void);
int port_18_data(void);
// ports 19 and 20 are for oscillator I/O
// ports 21 and 22 are VCC/GND
int port_23_data(void); // reset by default
int port_24_data(void);
int port_25_data(void);
int port_26_data(void);
int port_27_data(void); // open drain
int port_28_data(void); // high current

void port_1_interrupt_clear(void);
void port_2_interrupt_clear(void);
void port_3_interrupt_clear(void);
void port_4_interrupt_clear(void);  // reserved by default
void port_5_interrupt_clear(void);  // open drain
void port_6_interrupt_clear(void);
// ports 7 and 8 are VCC/GND
void port_9_interrupt_clear(void);  // reserved by default
void port_10_interrupt_clear(void); // reserved by default
void port_11_interrupt_clear(void); // reserved by default
void port_12_interrupt_clear(void); // programmer I/O by default
void port_13_interrupt_clear(void); // 10ns glitch filter
void port_14_interrupt_clear(void);
void port_15_interrupt_clear(void);
void port_16_interrupt_clear(void);
void port_17_interrupt_clear(void);
void port_18_interrupt_clear(void);
// ports 19 and 20 are for oscillator I/O
// ports 21 and 22 are VCC/GND
void port_23_interrupt_clear(void); // reset by default
void port_24_interrupt_clear(void);
void port_25_interrupt_clear(void);
void port_26_interrupt_clear(void);
void port_27_interrupt_clear(void); // open drain
void port_28_interrupt_clear(void); // high current







#endif // __PORT_IO_H
