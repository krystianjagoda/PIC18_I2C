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

#include <xc.h>
#include <p18f46j11.h>
#include "eeprom_i2c.h"
#include "i2c.h"



void eeprom_i2c_writeByte(unsigned char address, unsigned char data)
{   
    i2c_start();			
    i2c_write(EEPROM_I2C_address & 0xFE); 	
    i2c_write(address);
    i2c_write(data);
    i2c_stop();
    
}


unsigned char eeprom_i2c_readByte(char address)
{
    unsigned char data = 0xFF;
    
    i2c_start();
    i2c_write (EEPROM_I2C_address & 0xFE);
    i2c_write(address);
    i2c_start();
    i2c_write(EEPROM_I2C_address | 0x01);
    data = i2c_read(0);
    i2c_stop();
      
    return data;
}