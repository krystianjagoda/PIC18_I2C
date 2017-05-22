#ifndef I2C_H
#define	I2C_H


void i2c_init(void);
void i2c_start(void);
void i2c_repStart(void);
void i2c_stop(void);

unsigned char i2c_write( unsigned char i2cWritedata );
unsigned char i2c_read( unsigned char ack );


#endif	/* I2C_H */
