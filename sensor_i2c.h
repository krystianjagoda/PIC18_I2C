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
 * Description:  Microchip MCP9808 I2C temparature Sensor 		 		*
*			     - basic functions                     					*
 * *********************************************************************/


#ifndef SENSOR_H
#define	SENSOR_H


#define MCP9808_CONFIG_H    0b00000000  // Config Higher Byte  without Sleep
#define MCP9808_CONFIG_L    0b00000000  // Config Lower Byte
#define MCP9808_RESOLUTION  0b00000010  // 0.5C  



/********************************************************************
* Function Name: mcp9808_init
* Return Value: Sensor presence
* Parameters: Sensor address
* Description: This function checks the MCP9808sensor presence and 
* 			   performs sensor initialization
********************************************************************/
unsigned char mcp9808_init(unsigned char address);  


/********************************************************************
* Function Name: mcp9808_wake
* Return Value: void
* Parameters: Sensor address
* Description: This function wakes up MCP9808 Sensor from sleep
********************************************************************/
void mcp9808_wake(unsigned char address);



/********************************************************************
* Function Name: mcp9808_sleep
* Return Value: void
* Parameters: Sensor address
* Description: This function puts MCP9808 Sensor into sleep
********************************************************************/
void mcp9808_sleep(unsigned char address); 



/********************************************************************
* Function Name: mcp9808_get_temp
* Return Value: Temperature in °C
* Parameters: Sensor address
* Description: This function reads the temperature data from the sensor
********************************************************************/
unsigned int mcp9808_get_temp(unsigned char address);  


#endif	/* SENSOR_H */
