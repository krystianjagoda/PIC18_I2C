/************************************************************************
 * Filename:        i2c.c                                               *
 * Date:            08/08/2017                                          *
 * File Version:    v1.1                                                *
 *                                                                      *
 * Author:          Krystian Jagoda                                     *
 * Email:           krystianjagoda@gmail.com                            *
 ************************************************************************
 * Architecture:    Advanced 8-Bit MCUs                                 *
 * Processor:       PIC18F64J11                                         *
 * Compiler:        MPLAB XC8 v1.38                                     *
 * **********************************************************************
 * Description: Basic I2C Functions for PIC18F64J11                     *
 * *********************************************************************/

#include <xc.h>
#include <p18f46j11.h>
#include "i2c.h"

void i2c_init(void) {
    
    SSP2CON1 = 0x28; 			// enable I2C Master mode
    SSP2CON2 = 0x00; 			// clear control bits
    SSP2STAT = 0x80; 			// disable slew rate control; disable SMBus
    SSP2ADD = 0x7F; 			// BaudRate
    
    PIR3bits.SSP2IF = 0;
    PIR3bits.BCL2IF = 0;
    SSP2CON2bits.SEN = 0; 		// force idle condition
}

void i2c_start(void) {
    PIR3bits.SSP2IF = 0; 		// clear flag
    while (SSP2STATbits.BF ); 	// wait for idle condition
    SSP2CON2bits.SEN = 1; 		// initiate START condition
    while (!PIR3bits.SSP2IF) ; 	// wait for a flag to be set
    PIR3bits.SSP2IF = 0; 		// clear flag
}




void i2c_repStart(void) {
    PIR3bits.SSP2IF = 0; 		// clear flag
    while ( SSP2STATbits.BF );  // wait for idle condition
    SSP2CON2bits.RSEN = 1; 		// initiate Repeated START condition
    while (!PIR3bits.SSP2IF); 	// wait for a flag to be set
    PIR3bits.SSP2IF = 0; 		// clear flag
}



void i2c_stop(void) {
    PIR3bits.SSP2IF = 0; 		// clear flag
    while ( SSP2STATbits.BF );  // wait for idle condition
    SSP2CON2bits.PEN = 1; 		// Initiate STOP condition
    while (!PIR3bits.SSP2IF); 	// wait for a flag to be set
    PIR3bits.SSP2IF = 0; 		// clear flag
}



unsigned char i2c_write( unsigned char i2cWritedata ) {
    PIR3bits.SSP2IF = 0; 		// clear interrupt
    while ( SSP2STATbits.BF ); 	// wait for idle condition
    SSP2BUF = i2cWritedata; 	// Load SSPBUF with i2cWritedata (the value to be transmitted)
    while (!PIR3bits.SSP2IF); 	// wait for a flag to be set
    PIR3bits.SSP2IF = 0; 		// clear flag
    
    return ( !SSP2CON2bits.ACKSTAT ); // function returns '1' if transmission is acknowledged
}


unsigned char i2c_read( unsigned char ack ) {
    
    unsigned char i2cReaddata;

    PIR3bits.SSP2IF = 0;		// clear interrupt
    while ( SSPSTATbits.BF ) ; 	// wait for idle condition
    SSP2CON2bits.RCEN = 1; 		// enable receive mode
    while (!PIR3bits.SSP2IF) ; 	// wait for a flag to be set
    PIR3bits.SSP2IF = 0;		// clear flag
    i2cReaddata = SSP2BUF; 		// Read SSPBUF and put it in i2cReaddata
    if ( ack ) { 				// if ack=1
        SSP2CON2bits.ACKDT = 0; // then transmit an Acknowledge
    } else {
        SSP2CON2bits.ACKDT = 1; // otherwise transmit a Not Acknowledge
    }
    SSP2CON2bits.ACKEN = 1; 	// send acknowledge sequence
    
    while (!PIR3bits.SSP2IF) ; 	// wait for a flag to be set
    PIR3bits.SSP2IF = 0;		// clear flag
    
    return( i2cReaddata ); 		// return the value read from SSPBUF
}
