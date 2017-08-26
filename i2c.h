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


#ifndef I2C_H
#define	I2C_H

/********************************************************************
* Function Name: i2c_init
* Return Value: void
* Parameters: void
* Description: This function sets up the SSP1 module on a
* PIC18F64J11 device 
********************************************************************/
void i2c_init(void);



/********************************************************************
* Function Name: i2c_start
* Return Value: void
* Parameters: void
* Description: Send I2C Start Command
********************************************************************/
void i2c_start(void);



/********************************************************************
* Function Name: i2c_repStart
* Return Value: void
* Parameters: void
* Description: Resend I2C Start Command
********************************************************************/
void i2c_repStart(void);



/********************************************************************
* Function Name: i2c_stop
* Return Value: void
* Parameters: void
* Description: Send I2C Stop command
********************************************************************/
void i2c_stop(void);



/********************************************************************
* Function Name: i2c_write
* Return Value: Status byte for WCOL detection.
* Parameters: Single data byte for I2C2 bus.
* Description: This routine writes a single byte to the
* I2C2 bus.
********************************************************************/
unsigned char i2c_write( unsigned char i2cWritedata );



/********************************************************************
* Function Name: i2c_read
* Return Value: contents of SSP2BUF register
* Parameters: ack = 1 and nak = 0
* Description: Read a byte from I2C bus and ACK/NAK device
********************************************************************/
unsigned char i2c_read( unsigned char ack );


#endif	/* I2C_H */
