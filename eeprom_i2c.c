/************************************************************************
 * Filename:        eeprom_i2c.c                                        *
 * Date:            08/10/2016                                          *
 * File Version:    v1.0                                                *
 *                                                                      *
 * Author:          Krystian Jagoda                                     *
 * Email:           krystianjagoda@gmail.com                            *
 ************************************************************************
 * Architecture:    Advanced 8-Bit MCUs                                 *
 * Processor:       PIC18F64J11                                         *
 * Compiler:        MPLAB XC8 v1.38                                     *
 * **********************************************************************
 * Description: External I2C EEPROM - 24AA01H  basic functions          *
 * *********************************************************************/

#include <xc.h>
#include <p18f46j11.h>
#include "eeprom_i2c.h"
#include "i2c.h"


/********************************************************************
* Function Name: eeprom_i2c_writeByte
* Return Value: void
* Parameters: Memory address [0x00-0x7F], data Byte
* Description: Writes a single byte to specified memory address
********************************************************************/
void eeprom_i2c_writeByte(unsigned char address, unsigned char data)
{   
    i2c_start(); 							// START command
    i2c_write(EEPROM_I2C_address & 0xFE); 	// WRITE Command
    i2c_write(address); 					// Write address
    i2c_write(data); 						// Write data
    i2c_stop(); 							// STOP command
    
}

/********************************************************************
* Function Name: eeprom_i2c_readByte
* Return Value: data Byte
* Parameters: Memory address [0x00-0x7F]
* Description: Writes a single byte from specified memory address
********************************************************************/
unsigned char eeprom_i2c_readByte(char address)
{
    unsigned char data = 0xFF;
    
    i2c_start(); 							// START command
    i2c_write (EEPROM_I2C_address & 0xFE);  // WRITE Command 
    i2c_write(address); 					// Write TA Register address
    i2c_start(); 							// Repeat START
    i2c_write(EEPROM_I2C_address | 0x01); 	// READ Command
    data = i2c_read(0); 					// READ 8 bits and Send NAK bit
    i2c_stop(); 							// STOP command   
      
    return data;
}