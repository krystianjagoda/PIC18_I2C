/************************************************************************
 * Filename:        sensor_i2c.c                                        *
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
 * Description:  Microchip MCP9808 I2C temparature Sensor 		*
*			     - basic functions                     	*
 * *********************************************************************/

 
#include <xc.h>
#include <p18f46j11.h>
#include "sensor_i2c.h"
#include "i2c.h"


unsigned char mcp9808_init(unsigned char address){
    unsigned char mfc_id = 0;
    unsigned char sensor_status = 0;
    
	// Verifies if sensor present by reading the MFC ID
	i2c_start(); 							
    i2c_write (address & 0xFE); 			
    i2c_write(0x06); 						
    i2c_start(); 							
    i2c_write(address | 0x01); 				
    mfc_id = i2c_read(1); 					
    mfc_id = i2c_read(0); 					
    i2c_stop(); 							
	
    if(mfc_id == 84) sensor_status = 1;
    else sensor_status = 0;

	// Load the sensor configuration
    i2c_start();
    i2c_write(address & 0xFE); 
    i2c_write(0x08); 
    i2c_write(MCP9808_RESOLUTION); 
    i2c_stop(); 
    i2c_repStart();
    i2c_write(address & 0xFE); 
    i2c_write(0x01);
    i2c_write(MCP9808_CONFIG_H | 0x01); 
    i2c_write(MCP9808_CONFIG_L); 
    i2c_stop(); 
    
    return sensor_status;
}



void mcp9808_wake(unsigned char address){
    i2c_start(); 
    i2c_write(address & 0xFE);
    i2c_write(0x01); 
    i2c_write(MCP9808_CONFIG_H & 0xFE);
    i2c_write(MCP9808_CONFIG_L); 
    i2c_stop(); 
}


void mcp9808_sleep(unsigned char address){
    i2c_start(); 
    i2c_write(address & 0xFE);
    i2c_write(0x01); 
    i2c_write(MCP9808_CONFIG_H | 0x01); 
    i2c_write(MCP9808_CONFIG_L); 
    i2c_stop(); 
}




unsigned int mcp9808_get_temp(unsigned char address){
    unsigned int upperByte = 0;
    unsigned int lowerByte = 0;
    float temperature = 0;
    unsigned int temp = 0;
    
	// Read temperature data from the Sensor
    i2c_start();
    i2c_write (address & 0xFE);
    i2c_write(0x05); 
    i2c_start(); 
    i2c_write(address | 0x01); 
    upperByte = i2c_read(1); 
    lowerByte = i2c_read(0); 
    i2c_stop();       

    //Convert the temperature data
    upperByte = upperByte & 0x1F; //Clear flag bits
    if ((upperByte & 0x10) == 0x10){ 	//TA < 0°C
        upperByte = upperByte & 0x0F;
        temperature = (10*(upperByte*16.0 + lowerByte/16.0));
        temp =  temperature;
        temp = (0b1000000000 | temp);
    }
    else{ 								//TA > 0°C
        temperature = (10*(upperByte*16.0 + lowerByte/16.0));
        temp = temperature;
    }
    
    return temp;
}
