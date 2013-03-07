
#include "port_io.h"

/* all returned ints from this library represent bools;
 *   zeroes are false, and nonzero values are true
 *   (true values are not necessarily 1)
 */


/* GPIO enable/disable/toggle/state
 */

void GPIO_enable() {
	LPC_SYSCON->SYSAHBCLKCTRL |= (1UL <<  6);
}

void GPIO_disable() {
	LPC_SYSCON->SYSAHBCLKCTRL &= ~(1UL <<  6);
}

void GPIO_toggle() {
	LPC_SYSCON->SYSAHBCLKCTRL ^= (1UL <<  6);
}

int GPIO_state() {
	return 	LPC_SYSCON->SYSAHBCLKCTRL & (1UL <<  6);
}


/* set ports to output mode
 */

void port_1_dir_output() {
    LPC_GPIO0->DIR |= (1<<8);
}
	
void port_2_dir_output() {
    LPC_GPIO0->DIR |= (1<<9);
}

void port_3_dir_output() {
    LPC_GPIO0->DIR |= (1<<10);
}

void port_4_dir_output() {  // reserved by default
    LPC_GPIO0->DIR |= (1<<11);
}

void port_5_dir_output() {  // open drain
    LPC_GPIO0->DIR |= (1<<5);
}

void port_6_dir_output() { 
    LPC_GPIO0->DIR |= (1<<6);
}

// ports 7 and 8 are VCC/GND

void port_9_dir_output() {  // reserved by default
    LPC_GPIO1->DIR |= (1<<0);
}

void port_10_dir_output() { // reserved by default
    LPC_GPIO1->DIR |= (1<<1);
}

void port_11_dir_output() { // reserved by default
    LPC_GPIO1->DIR |= (1<<2);
}

void port_12_dir_output() { // programmer I/O by default
    LPC_GPIO1->DIR |= (1<<3);
}

void port_13_dir_output() { // 10ns glitch filter
    LPC_GPIO1->DIR |= (1<<4);
}

void port_14_dir_output() {
    LPC_GPIO1->DIR |= (1<<5);
}

void port_15_dir_output() {
    LPC_GPIO1->DIR |= (1<<6);
}

void port_16_dir_output() {
    LPC_GPIO1->DIR |= (1<<7);
}

void port_17_dir_output() {
    LPC_GPIO1->DIR |= (1<<8);
}

void port_18_dir_output() {
    LPC_GPIO1->DIR |= (1<<9);
}

// ports 19 and 20 are for oscillator I/O
// ports 21 and 22 are VCC/GND

void port_23_dir_output() { // reset by default	   
    LPC_GPIO0->DIR |= (1<<0);
}

void port_24_dir_output() {
    LPC_GPIO0->DIR |= (1<<1);
}

void port_25_dir_output() {
    LPC_GPIO0->DIR |= (1<<2);
}

void port_26_dir_output() {
    LPC_GPIO0->DIR |= (1<<3);
}

void port_27_dir_output() { // open drain
    LPC_GPIO0->DIR |= (1<<4);
}

void port_28_dir_output() { // high current
    LPC_GPIO0->DIR |= (1<<7);
}


/* set ports to input mode
 */

void port_1_dir_input() {
    LPC_GPIO0->DIR &= ~(1<<8);
}
	
void port_2_dir_input() {
    LPC_GPIO0->DIR &= ~(1<<9);
}

void port_3_dir_input() {
    LPC_GPIO0->DIR &= ~(1<<10);
}

void port_4_dir_input() {  // reserved by default
    LPC_GPIO0->DIR &= ~(1<<11);
}

void port_5_dir_input() {  // open drain
    LPC_GPIO0->DIR &= ~(1<<5);
}

void port_6_dir_input() { 
    LPC_GPIO0->DIR &= ~(1<<6);
}

// ports 7 and 8 are VCC/GND

void port_9_dir_input() {  // reserved by default
    LPC_GPIO1->DIR &= ~(1<<0);
}

void port_10_dir_input() { // reserved by default
    LPC_GPIO1->DIR &= ~(1<<1);
}

void port_11_dir_input() { // reserved by default
    LPC_GPIO1->DIR &= ~(1<<2);
}

void port_12_dir_input() { // programmer I/O by default
    LPC_GPIO1->DIR &= ~(1<<3);
}

void port_13_dir_input() { // 10ns glitch filter
    LPC_GPIO1->DIR &= ~(1<<4);
}

void port_14_dir_input() {
    LPC_GPIO1->DIR &= ~(1<<5);
}

void port_15_dir_input() {
    LPC_GPIO1->DIR &= ~(1<<6);
}

void port_16_dir_input() {
    LPC_GPIO1->DIR &= ~(1<<7);
}

void port_17_dir_input() {
    LPC_GPIO1->DIR &= ~(1<<8);
}

void port_18_dir_input() {
    LPC_GPIO1->DIR &= ~(1<<9);
}

// ports 19 and 20 are for oscillator I/O
// ports 21 and 22 are VCC/GND

void port_23_dir_input() { // reset by default	   
    LPC_GPIO0->DIR &= ~(1<<0);
}

void port_24_dir_input() {
    LPC_GPIO0->DIR &= ~(1<<1);
}

void port_25_dir_input() {
    LPC_GPIO0->DIR &= ~(1<<2);
}

void port_26_dir_input() {
    LPC_GPIO0->DIR &= ~(1<<3);
}

void port_27_dir_input() { // open drain
    LPC_GPIO0->DIR &= ~(1<<4);
}

void port_28_dir_input() { // high current
    LPC_GPIO0->DIR &= ~(1<<7);
}


/* toggle ports between output and input
 */

void port_1_dir_toggle() {
    LPC_GPIO0->DIR ^= (1<<8);
}
	
void port_2_dir_toggle() {
    LPC_GPIO0->DIR ^= (1<<9);
}

void port_3_dir_toggle() {
    LPC_GPIO0->DIR ^= (1<<10);
}

void port_4_dir_toggle() {  // reserved by default
    LPC_GPIO0->DIR ^= (1<<11);
}

void port_5_dir_toggle() {  // open drain
    LPC_GPIO0->DIR ^= (1<<5);
}

void port_6_dir_toggle() { 
    LPC_GPIO0->DIR ^= (1<<6);
}

// ports 7 and 8 are VCC/GND

void port_9_dir_toggle() {  // reserved by default
    LPC_GPIO1->DIR ^= (1<<0);
}

void port_10_dir_toggle() { // reserved by default
    LPC_GPIO1->DIR ^= (1<<1);
}

void port_11_dir_toggle() { // reserved by default
    LPC_GPIO1->DIR ^= (1<<2);
}

void port_12_dir_toggle() { // programmer I/O by default
    LPC_GPIO1->DIR ^= (1<<3);
}

void port_13_dir_toggle() { // 10ns glitch filter
    LPC_GPIO1->DIR ^= (1<<4);
}

void port_14_dir_toggle() {
    LPC_GPIO1->DIR ^= (1<<5);
}

void port_15_dir_toggle() {
    LPC_GPIO1->DIR ^= (1<<6);
}

void port_16_dir_toggle() {
    LPC_GPIO1->DIR ^= (1<<7);
}

void port_17_dir_toggle() {
    LPC_GPIO1->DIR ^= (1<<8);
}

void port_18_dir_toggle() {
    LPC_GPIO1->DIR ^= (1<<9);
}

// ports 19 and 20 are for oscillator I/O
// ports 21 and 22 are VCC/GND

void port_23_dir_toggle() { // reset by default	   
    LPC_GPIO0->DIR ^= (1<<0);
}

void port_24_dir_toggle() {
    LPC_GPIO0->DIR ^= (1<<1);
}

void port_25_dir_toggle() {
    LPC_GPIO0->DIR ^= (1<<2);
}

void port_26_dir_toggle() {
    LPC_GPIO0->DIR ^= (1<<3);
}

void port_27_dir_toggle() { // open drain
    LPC_GPIO0->DIR ^= (1<<4);
}

void port_28_dir_toggle() { // high current
    LPC_GPIO0->DIR ^= (1<<7);
}


/* read current port I/O state
 */

int port_1_dir_data() {
    return LPC_GPIO0->DIR & (1<<8);
}
	
int port_2_dir_data() {
    return LPC_GPIO0->DIR & (1<<9);
}

int port_3_dir_data() {
    return LPC_GPIO0->DIR & (1<<10);
}

int port_4_dir_data() {  // reserved by default
    return LPC_GPIO0->DIR & (1<<11);
}

int port_5_dir_data() {  // open drain
    return LPC_GPIO0->DIR & (1<<5);
}

int port_6_dir_data() { 
    return LPC_GPIO0->DIR & (1<<6);
}

// ports 7 and 8 are VCC/GND

int port_9_dir_data() {  // reserved by default
    return LPC_GPIO1->DIR & (1<<0);
}

int port_10_dir_data() { // reserved by default
    return LPC_GPIO1->DIR & (1<<1);
}

int port_11_dir_data() { // reserved by default
    return LPC_GPIO1->DIR & (1<<2);
}

int port_12_dir_data() { // programmer I/O by default
    return LPC_GPIO1->DIR & (1<<3);
}

int port_13_dir_data() { // 10ns glitch filter
    return LPC_GPIO1->DIR & (1<<4);
}

int port_14_dir_data() {
    return LPC_GPIO1->DIR & (1<<5);
}

int port_15_dir_data() {
    return LPC_GPIO1->DIR & (1<<6);
}

int port_16_dir_data() {
    return LPC_GPIO1->DIR & (1<<7);
}

int port_17_dir_data() {
    return LPC_GPIO1->DIR & (1<<8);
}

int port_18_dir_data() {
    return LPC_GPIO1->DIR & (1<<9);
}

// ports 19 and 20 are for oscillator I/O
// ports 21 and 22 are VCC/GND

int port_23_dir_data() { // reset by default	   
    return LPC_GPIO0->DIR & (1<<0);
}

int port_24_dir_data() {
    return LPC_GPIO0->DIR & (1<<1);
}

int port_25_dir_data() {
    return LPC_GPIO0->DIR & (1<<2);
}

int port_26_dir_data() {
    return LPC_GPIO0->DIR & (1<<3);
}

int port_27_dir_data() { // open drain
    return LPC_GPIO0->DIR & (1<<4);
}

int port_28_dir_data() { // high current
    return LPC_GPIO0->DIR & (1<<7);
}


/* set ports to output mode
 */

void port_1_high() {
    LPC_GPIO0->DATA |= (1<<8);
}
	
void port_2_high() {
    LPC_GPIO0->DATA |= (1<<9);
}

void port_3_high() {
    LPC_GPIO0->DATA |= (1<<10);
}

void port_4_high() {  // reserved by default
    LPC_GPIO0->DATA |= (1<<11);
}

void port_5_high() {  // open drain
    LPC_GPIO0->DATA |= (1<<5);
}

void port_6_high() { 
    LPC_GPIO0->DATA |= (1<<6);
}

// ports 7 and 8 are VCC/GND

void port_9_high() {  // reserved by default
    LPC_GPIO1->DATA |= (1<<0);
}

void port_10_high() { // reserved by default
    LPC_GPIO1->DATA |= (1<<1);
}

void port_11_high() { // reserved by default
    LPC_GPIO1->DATA |= (1<<2);
}

void port_12_high() { // programmer I/O by default
    LPC_GPIO1->DATA |= (1<<3);
}

void port_13_high() { // 10ns glitch filter
    LPC_GPIO1->DATA |= (1<<4);
}

void port_14_high() {
    LPC_GPIO1->DATA |= (1<<5);
}

void port_15_high() {
    LPC_GPIO1->DATA |= (1<<6);
}

void port_16_high() {
    LPC_GPIO1->DATA |= (1<<7);
}

void port_17_high() {
    LPC_GPIO1->DATA |= (1<<8);
}

void port_18_high() {
    LPC_GPIO1->DATA |= (1<<9);
}

// ports 19 and 20 are for oscillator I/O
// ports 21 and 22 are VCC/GND

void port_23_high() { // reset by default	   
    LPC_GPIO0->DATA |= (1<<0);
}

void port_24_high() {
    LPC_GPIO0->DATA |= (1<<1);
}

void port_25_high() {
    LPC_GPIO0->DATA |= (1<<2);
}

void port_26_high() {
    LPC_GPIO0->DATA |= (1<<3);
}

void port_27_high() { // open drain
    LPC_GPIO0->DATA |= (1<<4);
}

void port_28_high() { // high current
    LPC_GPIO0->DATA |= (1<<7);
}


/* set ports to input mode
 */

void port_1_low() {
    LPC_GPIO0->DATA &= ~(1<<8);
}
	
void port_2_low() {
    LPC_GPIO0->DATA &= ~(1<<9);
}

void port_3_low() {
    LPC_GPIO0->DATA &= ~(1<<10);
}

void port_4_low() {  // reserved by default
    LPC_GPIO0->DATA &= ~(1<<11);
}

void port_5_low() {  // open drain
    LPC_GPIO0->DATA &= ~(1<<5);
}

void port_6_low() { 
    LPC_GPIO0->DATA &= ~(1<<6);
}

// ports 7 and 8 are VCC/GND

void port_9_low() {  // reserved by default
    LPC_GPIO1->DATA &= ~(1<<0);
}

void port_10_low() { // reserved by default
    LPC_GPIO1->DATA &= ~(1<<1);
}

void port_11_low() { // reserved by default
    LPC_GPIO1->DATA &= ~(1<<2);
}

void port_12_low() { // programmer I/O by default
    LPC_GPIO1->DATA &= ~(1<<3);
}

void port_13_low() { // 10ns glitch filter
    LPC_GPIO1->DATA &= ~(1<<4);
}

void port_14_low() {
    LPC_GPIO1->DATA &= ~(1<<5);
}

void port_15_low() {
    LPC_GPIO1->DATA &= ~(1<<6);
}

void port_16_low() {
    LPC_GPIO1->DATA &= ~(1<<7);
}

void port_17_low() {
    LPC_GPIO1->DATA &= ~(1<<8);
}

void port_18_low() {
    LPC_GPIO1->DATA &= ~(1<<9);
}

// ports 19 and 20 are for oscillator I/O
// ports 21 and 22 are VCC/GND

void port_23_low() { // reset by default	   
    LPC_GPIO0->DATA &= ~(1<<0);
}

void port_24_low() {
    LPC_GPIO0->DATA &= ~(1<<1);
}

void port_25_low() {
    LPC_GPIO0->DATA &= ~(1<<2);
}

void port_26_low() {
    LPC_GPIO0->DATA &= ~(1<<3);
}

void port_27_low() { // open drain
    LPC_GPIO0->DATA &= ~(1<<4);
}

void port_28_low() { // high current
    LPC_GPIO0->DATA &= ~(1<<7);
}


/* toggle ports between output and input
 */

void port_1_toggle() {
    LPC_GPIO0->DATA ^= (1<<8);
}
	
void port_2_toggle() {
    LPC_GPIO0->DATA ^= (1<<9);
}

void port_3_toggle() {
    LPC_GPIO0->DATA ^= (1<<10);
}

void port_4_toggle() {  // reserved by default
    LPC_GPIO0->DATA ^= (1<<11);
}

void port_5_toggle() {  // open drain
    LPC_GPIO0->DATA ^= (1<<5);
}

void port_6_toggle() { 
    LPC_GPIO0->DATA ^= (1<<6);
}

// ports 7 and 8 are VCC/GND

void port_9_toggle() {  // reserved by default
    LPC_GPIO1->DATA ^= (1<<0);
}

void port_10_toggle() { // reserved by default
    LPC_GPIO1->DATA ^= (1<<1);
}

void port_11_toggle() { // reserved by default
    LPC_GPIO1->DATA ^= (1<<2);
}

void port_12_toggle() { // programmer I/O by default
    LPC_GPIO1->DATA ^= (1<<3);
}

void port_13_toggle() { // 10ns glitch filter
    LPC_GPIO1->DATA ^= (1<<4);
}

void port_14_toggle() {
    LPC_GPIO1->DATA ^= (1<<5);
}

void port_15_toggle() {
    LPC_GPIO1->DATA ^= (1<<6);
}

void port_16_toggle() {
    LPC_GPIO1->DATA ^= (1<<7);
}

void port_17_toggle() {
    LPC_GPIO1->DATA ^= (1<<8);
}

void port_18_toggle() {
    LPC_GPIO1->DATA ^= (1<<9);
}

// ports 19 and 20 are for oscillator I/O
// ports 21 and 22 are VCC/GND

void port_23_toggle() { // reset by default	   
    LPC_GPIO0->DATA ^= (1<<0);
}

void port_24_toggle() {
    LPC_GPIO0->DATA ^= (1<<1);
}

void port_25_toggle() {
    LPC_GPIO0->DATA ^= (1<<2);
}

void port_26_toggle() {
    LPC_GPIO0->DATA ^= (1<<3);
}

void port_27_toggle() { // open drain
    LPC_GPIO0->DATA ^= (1<<4);
}

void port_28_toggle() { // high current
    LPC_GPIO0->DATA ^= (1<<7);
}


/* read current port I/O state
 */

int port_1_data() {
    return LPC_GPIO0->DATA & (1<<8);
}
	
int port_2_data() {
    return LPC_GPIO0->DATA & (1<<9);
}

int port_3_data() {
    return LPC_GPIO0->DATA & (1<<10);
}

int port_4_data() {  // reserved by default
    return LPC_GPIO0->DATA & (1<<11);
}

int port_5_data() {  // open drain
    return LPC_GPIO0->DATA & (1<<5);
}

int port_6_data() { 
    return LPC_GPIO0->DATA & (1<<6);
}

// ports 7 and 8 are VCC/GND

int port_9_data() {  // reserved by default
    return LPC_GPIO1->DATA & (1<<0);
}

int port_10_data() { // reserved by default
    return LPC_GPIO1->DATA & (1<<1);
}

int port_11_data() { // reserved by default
    return LPC_GPIO1->DATA & (1<<2);
}

int port_12_data() { // programmer I/O by default
    return LPC_GPIO1->DATA & (1<<3);
}

int port_13_data() { // 10ns glitch filter
    return LPC_GPIO1->DATA & (1<<4);
}

int port_14_data() {
    return LPC_GPIO1->DATA & (1<<5);
}

int port_15_data() {
    return LPC_GPIO1->DATA & (1<<6);
}

int port_16_data() {
    return LPC_GPIO1->DATA & (1<<7);
}

int port_17_data() {
    return LPC_GPIO1->DATA & (1<<8);
}

int port_18_data() {
    return LPC_GPIO1->DATA & (1<<9);
}

// ports 19 and 20 are for oscillator I/O
// ports 21 and 22 are VCC/GND

int port_23_data() { // reset by default	   
    return LPC_GPIO0->DATA & (1<<0);
}

int port_24_data() {
    return LPC_GPIO0->DATA & (1<<1);
}

int port_25_data() {
    return LPC_GPIO0->DATA & (1<<2);
}

int port_26_data() {
    return LPC_GPIO0->DATA & (1<<3);
}

int port_27_data() { // open drain
    return LPC_GPIO0->DATA & (1<<4);
}

int port_28_data() { // high current
    return LPC_GPIO0->DATA & (1<<7);
}


/* toggle ports between output and input
 */

void port_1_interrupt_clear() {
    LPC_GPIO0->IC |= (1<<8);
}
	
void port_2_interrupt_clear() {
    LPC_GPIO0->IC |= (1<<9);
}

void port_3_interrupt_clear() {
    LPC_GPIO0->IC |= (1<<10);
}

void port_4_interrupt_clear() {  // reserved by default
    LPC_GPIO0->IC |= (1<<11);
}

void port_5_interrupt_clear() {  // open drain
    LPC_GPIO0->IC |= (1<<5);
}

void port_6_interrupt_clear() { 
    LPC_GPIO0->IC |= (1<<6);
}

// ports 7 and 8 are VCC/GND

void port_9_interrupt_clear() {  // reserved by default
    LPC_GPIO1->IC |= (1<<0);
}

void port_10_interrupt_clear() { // reserved by default
    LPC_GPIO1->IC |= (1<<1);
}

void port_11_interrupt_clear() { // reserved by default
    LPC_GPIO1->IC |= (1<<2);
}

void port_12_interrupt_clear() { // programmer I/O by default
    LPC_GPIO1->IC |= (1<<3);
}

void port_13_interrupt_clear() { // 10ns glitch filter
    LPC_GPIO1->IC |= (1<<4);
}

void port_14_interrupt_clear() {
    LPC_GPIO1->IC |= (1<<5);
}

void port_15_interrupt_clear() {
    LPC_GPIO1->IC |= (1<<6);
}

void port_16_interrupt_clear() {
    LPC_GPIO1->IC |= (1<<7);
}

void port_17_interrupt_clear() {
    LPC_GPIO1->IC |= (1<<8);
}

void port_18_interrupt_clear() {
    LPC_GPIO1->IC |= (1<<9);
}

// ports 19 and 20 are for oscillator I/O
// ports 21 and 22 are VCC/GND

void port_23_interrupt_clear() { // reset by default	   
    LPC_GPIO0->IC |= (1<<0);
}

void port_24_interrupt_clear() {
    LPC_GPIO0->IC |= (1<<1);
}

void port_25_interrupt_clear() {
    LPC_GPIO0->IC |= (1<<2);
}

void port_26_interrupt_clear() {
    LPC_GPIO0->IC |= (1<<3);
}

void port_27_interrupt_clear() { // open drain
    LPC_GPIO0->IC |= (1<<4);
}

void port_28_interrupt_clear() { // high current
    LPC_GPIO0->IC |= (1<<7);
}
