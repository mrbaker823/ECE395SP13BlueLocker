#include "io_experiment.h"

/* password hashing is implemented, but buggy.
 * it seems password hashes aren't matching; I suspect that
 *   there's a discrepancy somewhere in how strings are handled
 */

#define PASS_SALT "This is a song that gets on everybody's nerves / on everybody's nerves / on everybody's nerves / \
This is a song that gets on everybody's nerves / and this is how it goes..."

char password[512];
int password_length;

void lpc_init(){
	GPIO_enable();
	UART_enable();

	GPIO0_dir_output(GPIO_P7);

	GPIO0_interrupt_enable(GPIO_P6);

	GPIO0_dir_output(GPIO_P4);

	GPIO0_output_high(GPIO_P4);

	GPIO0_dir_input(GPIO_P6); // we don't actually need this

	GPIO0_dir_output(GPIO_P3);
	GPIO0_output_high(GPIO_P4);
	GPIO0_dir_output(GPIO_P2);
	GPIO0_output_high(GPIO_P4);
	
	GPIO_interrupt_enable();
	UART_interrupt_enable();
	// if we use this often enough, it might be best to make another file
	//   for interrupt abstraction 
}

int main(){
	int i;
//	int blinks;
//	int state = 0;
	SHA1Context pass;

	lpc_init();

//	password[0] = '\0';
	password_length = 0;

	while(1){
		//int i = LPC_GPIO0->DATA & (1 << 6);
		while (UART_done == 0) {
//		 	for (i = 0; i < 0x0007FFFF; i++) {}
			/* enable line above to prevent terminal spam for echoes */
//			UART_data_write('.');
			/* enable line above for dot echo */
//			UART_data_write_string("password currently set to ");
//			UART_data_write_string(password);
//			UART_data_write_string("\r\n");
		}
		/* the bluetooth parsing code can go here; for now,
		 *   this code blinks the LED five times on a newline
		 */

//		UART_data_write_string("password currently set to ");
//		UART_data_write_string(password);
//		UART_data_write_string("\r\n");

//		for (blinks = 0; blinks < 10; blinks++) {
//		 	for (i = 0; i < 0x0007FFFF; i++) {}
//			GPIO0_output_toggle(GPIO_P7);
//		}
		/* enable code block above to add LED blinking on carriage return */ 

//		UART_data_write_string("password currently set to ");
//		UART_data_write_string(password);
//		UART_data_write_string("\r\n");

		/* below is a test parser */

		/* test */
		if (strncmp(UART_buffer, "test", 4) == 0) {
			sha1_test();
		}

		/* open [password] */
		if (strncmp(UART_buffer, "open", 4) == 0) { 
			if (password_length == 0 || checkpass(&pass, UART_buffer + 5, password_length)) {
				GPIO0_output_toggle(GPIO_P3);
				UART_data_write_string("open solenoid actived\r\n");
		 		for (i = 0; i < 0x0007FFFF; i++) {}
				GPIO0_output_toggle(GPIO_P3);
			}
		}
		
//		UART_data_write_string("password currently set to ");
//		UART_data_write_string(password);
//		UART_data_write_string("\r\n");

		/* close [password]	*/
		if (strncmp(UART_buffer, "close", 5) == 0) {
			if (password_length == 0 ||	checkpass(&pass, UART_buffer + 6, password_length)) {
				GPIO0_output_toggle(GPIO_P2);
				UART_data_write_string("close solenoid actived\r\n");
		 		for (i = 0; i < 0x0007FFFF; i++) {}
				GPIO0_output_toggle(GPIO_P2);
			}
		}

//		UART_data_write_string("password currently set to ");
//		UART_data_write_string(password);
//		UART_data_write_string("\r\n");

		/* set [oldpass] [newpass] 
		 * oldpass is a paramater iff a password is currently set*/

		if (strncmp(UART_buffer, "set", 3) == 0) {
			//UART_data_write_string("password is ");
			//UART_data_write_string(password);
			UART_data_write_string("password length is ");
			UART_data_write('0' + (password_length/10));
			UART_data_write('0' + (password_length%10));
			UART_data_write_string("\r\n");
			if ((password_length == 0) && (UART_buffer[3] == ' ')) {
				UART_data_write_string("password is currently null, setting to ");
				UART_data_write_string(UART_buffer + 4);
				UART_data_write_string("\r\n");
				//strcpy(password, (UART_buffer + 4));
				setpass(&pass, &(UART_buffer[4]));
				password_length = strlen(&(UART_buffer[4]));
				//UART_data_write_string("password set to ");
				//UART_data_write_string(password);
				//UART_data_write_string("\r\n");
				UART_data_write_string("password set\r\n");
			} else if ((UART_buffer[3] == ' ') && checkpass(&pass, UART_buffer + 4, password_length)) {
				
				UART_data_write_string("old password matches\r\n");
				UART_data_write_string("checking character \"");
				UART_data_write(UART_buffer[4 + password_length]);
				UART_data_write_string("\r\n");
				if (UART_buffer[4 + password_length] == '\0') {
					UART_data_write_string("no new password, unsetting pass\r\n");
					//password[0] = '\0';
					password_length = 0;
					UART_data_write_string("password reset\r\n");
				} else if ((UART_buffer[4 + password_length] == ' ') &&
					(UART_buffer[4 + password_length + 1] != '\0')) {

					UART_data_write_string("new password supplied, changing\r\n");
					//strcpy(password, (UART_buffer + 4 + password_length + 1));
					setpass(&pass, &(UART_buffer[4 + password_length + 1]));
					password_length = strlen(&(UART_buffer[4 + password_length + 1]));
					UART_buffer[password_length] = '\0';
					UART_data_write_string("password changed\r\n");
				}
			}
		}

//		UART_data_write_string("password currently set to ");
//		UART_data_write_string(password);
//		UART_data_write_string("\r\n");

		UART_done = 0;		
		UART_interrupt_enable();
//		if(GPIO0_data(GPIO_P6) != 0 && state == 0){
//			GPIO0_output_toggle(GPIO_P7);
//			state = 1;
//		} else if(GPIO0_data(GPIO_P6) == 0 && state == 1){
//			state = 0;
//		}
//		LPC_UART->THR = 0x58;
	}
//	return 0;	
}

void setpass(SHA1Context *pass_hash, char* pass) {

    SHA1Reset(pass_hash);
	SHA1Input(pass_hash, PASS_SALT, strlen(PASS_SALT));
    SHA1Input(pass_hash, (const unsigned char *) pass, strlen(pass));
	SHA1Result(pass_hash);
}

int checkpass(SHA1Context *pass_hash, char *string, int length) {

	SHA1Context string_hash; 
	int i;

    SHA1Reset(&string_hash);
	SHA1Input(&string_hash, PASS_SALT, strlen(PASS_SALT));
    SHA1Input(&string_hash, (const unsigned char *) string, length);

    if (!SHA1Result(&string_hash)) {
        UART_data_write_string("ERROR-- could not compute message digest\r\n");
		return 0; // false
    }

    for(i = 0; i < 5 ; i++){
		if (string_hash.Message_Digest[i] != pass_hash->Message_Digest[i]) { return 0; } // false
    }

	return 1; // true

}
