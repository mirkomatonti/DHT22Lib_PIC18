#include "dht22.h"


void dht22_inizialize()
{
    // set the pin to output
    PORT_DIR=0; 
    // pull the pin low
    PORT_PIN=0; 
    // wait for 25ms
	__delay_ms(25);  
    // pull the pin high
    PORT_PIN=1; 
    // wait for 30us
	__delay_us(30);  
    // set the pin to output 
    PORT_DIR=1;    
}

uint8_t dht22_response()
{
   PORT_DIR=1; 
	uint8_t res = 0;
	__delay_us (40);  
    // check if the pin is low
	if (!PORT_PIN) 
	{
        // wait for 80us
		__delay_us (80);
        // if the pin is high, response is ok   
		if (PORT_PIN) res = 1;  
		else res = -1;
	}
     // wait for the pin to go low
	while (PORT_PIN);  
	return res;
}

uint8_t read_data(){
	uint8_t i;
    // read 8 bits of data
	for (uint8_t j=0;j<8;j++)
	{
		while (!PORT_PIN);   
		__delay_us(40); 
        // if the pin is low 
		if (!PORT_PIN)  
            i&= ~(1<<(7-j)); // write 0
		else 
            i|= (1<<(7-j));  // write 1
		while (PORT_PIN){}; 
	}
	return i;
}

/*
 * Function:  readValues 
 * --------------------
 * Get temperature and humdity values from the DHT22 sensor.
 * shtvalues_t<int,float,float> containing temperature(C°) and humidty(%) values 
 * 
 * return: 1 if the sensor is responding, 0 otherwise
 */
uint8_t readValues(dhtvalues_t *sensor_data)
{ 
    uint8_t status;
    uint8_t reading[5];
    dht22_inizialize(); 
    if(dht22_response())
    {
        for(int i =0; i < 5;i++)
            reading[i]=read_data();
        sensor_data->humidity = ((reading[0] << 8) | reading[1])/10.0;
        sensor_data->temperature = ((reading[2] << 8) | reading[3])/10.0;
        status=1;
    }
    else
        status=0;
}