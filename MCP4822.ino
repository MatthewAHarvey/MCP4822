#include "MCP4822_SPI.h"

const int cs = 40;
const bool gain = false;
MCP4822 dac(cs, gain);

uint32_t baudrate = 250000;

void setup(){
    Serial.begin(baudrate);
    Serial.println("Connected to MCP4822 22 bit resolution example.");
    uint8_t dacRes = dac.init(10);
    Serial.print("Bit resolution: ");
    Serial.println(dacRes);
    Serial.print("Number of steps: ");
    Serial.println(dac.getNumberOfSteps());
}

void loop(){
	// Serial.println(dac.getBitResolution());
	uint8_t nBits = dac.getBitResolution();
	// Serial.println(nBits);
	uint32_t nSteps = (uint32_t(1) << nBits);
	// Serial.println(nSteps);
	// Serial.print("Total number of steps: ");
	// Serial.println(nSteps);
    for(uint32_t i = 0; i < nSteps; i++){
        dac.setVoltage(i);
    }
}