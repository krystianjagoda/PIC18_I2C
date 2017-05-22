#ifndef SENSOR_H
#define	SENSOR_H


#define MCP9808_CONFIG_H    0b00000000  // Config Higher Byte  without Sleep
#define MCP9808_CONFIG_L    0b00000000  // Config Lower Byte
#define MCP9808_RESOLUTION  0b00000010  // 0.5C  


unsigned char mcp9808_init(unsigned char address);        	// Initialize MCP9808
void mcp9808_wake(unsigned char address);        	// Wake up MCP9808
void mcp9808_sleep(unsigned char address);       	// Sleep MCP9808
unsigned int mcp9808_get_temp(unsigned char address);    	// Read Current Temp from MCP9808


#endif	/* SENSOR_H */
