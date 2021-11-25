/*
* Interface for Temperature & Humidity sensor 
* Using DHT22 Module
*/
#ifndef MY_DHT22_H
#define MY_DHT22_H
#include <xc.h>
#include <stdlib.h> 
#include <stdio.h>
#include <delays.h>    
#include <string.h>   
#include <stdint.h>

#define _XTAL_FREQ  8000000 // rember to set this according to your MCU

#define PORT_PIN PORTDbits.RD0
#define PORT_DIR TRISDbits.TRISD0

typedef struct {
    unsigned sensorPin;
    float temperature;
    float humidity;
}dhtvalues_t;


uint8_t readValues(dhtvalues_t *sensor_data);

#endif