#include "AnalogTemp.h"
#include "PayloadConfig.h"

AnalogTemp::AnalogTemp() : AnalogTemp(1000) {}

AnalogTemp::AnalogTemp(unsigned long minimum_period) 
    : Sensor("AnalogTemp", "ADC_Read,", minimum_period) {

}
    
    bool AnalogTemp::verify(){
        pinMode(THERMISTOR_PIN, INPUT); 
        return true; 
    }
    String AnalogTemp::readData(){
        return String(analogRead(THERMISTOR_PIN)); 
    }
    void AnalogTemp::readDataPacket(uint8_t*& packet){
        int adc_reading = analogRead(THERMISTOR_PIN); 

        memcpy(packet, &adc_reading, sizeof(int)); 

        packet += sizeof(int);
    }
    String AnalogTemp::decodeToCSV(uint8_t*& packet){
        int adc_reading = 0; 

        memcpy(&adc_reading, packet, sizeof(int)); 

        packet += sizeof(int); 

        return String(adc_reading); 
    }