# DHT22 Library for PIC18F4620

## Requirements
 - DHT22 Temperature/Humidity sensor.
 - PIC18F4620.
 - ICD3 Debugger.

## Getting started
- Import dht22.c and dht22.h into your local project.
- In the dht22.h file, set PORT_PIN, PORT_DIR and _XTAL_FREQ according to your schematics/MCU .

## Example
```
void main(void) {
    Init_IO();
    char Text[128];
    dhtvalues_t sensor_values;
    while(1)
    {
        PORTA = 0x04; 
        Delay10KTCYx(200); //wait 2s before every reading        
        if(readValues(&sensor_values))
            sprintf(Text, "humi:%.2f temp:%.2f \r\n",sensor_values.humidity,sensor_values.temperature);
        else
             sprintf(Text, "Error reading the sensor \r\n");
        USARTOut(Text, strlen(Text));       
        PORTA = 0x05; 
    }     
}    
```

## License

This project is licensed under the MIT License.
