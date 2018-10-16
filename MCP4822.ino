#include "MCP4822_SPI.h"

const int cs = 40;
MCP4822 dac(cs);

uint32_t baudrate = 250000;

void setup(){
    Serial.begin(baudrate);
    Serial.println("Connected to MCP4822 22 bit resolution example.")
    uint32_t dacSteps = dac.init(10);
    Serial.println("Number of DAC steps: ");
    Serial.println(dacSteps);
}

void loop(){
    for(uint32_t i = 0; i < dacSteps; i++){
        dac.setVoltage(i);
    }
}