/*
 *  shatest.c
 *
 *  Copyright (C) 1998, 2009
 *  Paul E. Jones <paulej@packetizer.com>
 *  All Rights Reserved
 *
 *****************************************************************************
 *  $Id: shatest.c 12 2009-06-22 19:34:25Z paulej $
 *****************************************************************************
 *
 *  Description:
 *      This file will exercise the SHA1 class and perform the three
 *      tests documented in FIPS PUB 180-1.
 *
 *  Portability Issues:
 *      None.
 *
 */

#include <stdio.h>
#include <string.h>
#include "sha1.h"
#include "uart.h"

/*
 *  Define patterns for testing
 */
#define TESTA   "abc"
#define TESTB_1 "abcdbcdecdefdefgefghfghighij"
#define TESTB_2 "hijkijkljklmklmnlmnomnopnopq"
#define TESTB   TESTB_1 TESTB_2
#define TESTC   "a"

char buffer[128];

int sha1_test()
{
    SHA1Context sha;
    int i;

    /*
     *  Perform test A
     */
    UART_data_write_string("\r\nTest A: 'abc'\r\n");

    SHA1Reset(&sha);
    SHA1Input(&sha, (const unsigned char *) TESTA, strlen(TESTA));

    if (!SHA1Result(&sha))
    {
        UART_data_write_string("ERROR-- could not compute message digest\r\n");
    }
    else
    {
        UART_data_write_string ("\t");
        for(i = 0; i < 5 ; i++)
        {
			sprintf(buffer, "%X ", sha.Message_Digest[i]);
            UART_data_write_string(buffer);
        }
        UART_data_write_string("\r\nShould match:\r\n");
        UART_data_write_string("\tA9993E36 4706816A BA3E2571 7850C26C 9CD0D89D\r\n");
    }

    /*
     *  Perform test B
     */
    UART_data_write_string("\r\nTest B:\r\n");

    SHA1Reset(&sha);
    SHA1Input(&sha, (const unsigned char *) TESTB, strlen(TESTB));

    if (!SHA1Result(&sha))
    {
        UART_data_write_string("ERROR-- could not compute message digest\r\n");
    }
    else
    {
        UART_data_write_string("\t");
        for(i = 0; i < 5 ; i++)
        {
			sprintf(buffer, "%X ", sha.Message_Digest[i]);
            UART_data_write_string(buffer);
        }
        UART_data_write_string("\r\nShould match:\r\n");
        UART_data_write_string("\t84983E44 1C3BD26E BAAE4AA1 F95129E5 E54670F1\r\n");
    }

    /*
     *  Perform test C
     */
    UART_data_write_string("\r\nTest C: One million 'a' characters\r\n");

    SHA1Reset(&sha);
    for(i = 1; i <= 1000000; i++) {
        SHA1Input(&sha, (const unsigned char *) TESTC, 1);
    }

    if (!SHA1Result(&sha))
    {
        UART_data_write_string("ERROR-- could not compute message digest\r\n");
    }
    else
    {
        UART_data_write_string("\t");
        for(i = 0; i < 5 ; i++)
        {
 			sprintf(buffer, "%X ", sha.Message_Digest[i]);
            UART_data_write_string(buffer);
        }
        UART_data_write_string("\r\nShould match:\r\n");
        UART_data_write_string("\t34AA973C D4C4DAA4 F61EEB2B DBAD2731 6534016F\r\n");
    }

    return 0;
}
