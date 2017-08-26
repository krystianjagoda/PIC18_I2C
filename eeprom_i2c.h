/************************************************************************
 * Filename:        eeprom_i2c.c                                        *
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
 * Description: External I2C EEPROM - 24AA01H  basic functions          *
 * *********************************************************************/



#ifndef EEPROM_I2C_H
#define	EEPROM_I2C_H


#define EEPROM_I2C_address 0b10100000 


/********************************************************************
* Function Name: eeprom_i2c_writeByte
* Return Value: void
* Parameters: Memory address [0x00-0x7F], data Byte
* Description: Writes a single byte to specified memory address
********************************************************************/
void eeprom_i2c_writeByte(unsigned char data, unsigned char address); 



/********************************************************************
* Function Name: eeprom_i2c_readByte
* Return Value: data Byte
* Parameters: Memory address [0x00-0x7F]
* Description: Writes a single byte from specified memory address
********************************************************************/
unsigned char eeprom_i2c_readByte(unsigned char address);              


#endif	/* EEPROM_I2C_H */
