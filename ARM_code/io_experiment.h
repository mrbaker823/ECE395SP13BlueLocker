#ifndef __IO_EXPERIMENT_H__
#define	__IO_EXPERIMENT_H__
#include "LPC11xx.h"
#include "gpio.h"
#include "uart.h"
#include "string.h"
#include "stdlib.h"
#include "sha1.h"

//extern char password[];
//extern int password_length;
//extern char temp[];
// these shouldn't need to be here; I'm debugging...

void setpass(SHA1Context*, char*);
int checkpass(SHA1Context*, char*, int);

#endif
