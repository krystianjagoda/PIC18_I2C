#ifndef EEPROM_I2C_H
#define	EEPROM_I2C_H


#define EEPROM_I2C_address 0b10100000 

void eeprom_i2c_writeByte(unsigned char data, unsigned char address); 
unsigned char eeprom_i2c_readByte(unsigned char address);              


#endif	/* EEPROM_I2C_H */
