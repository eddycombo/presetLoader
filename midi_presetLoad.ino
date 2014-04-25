#include <SoftwareSerial.h>
#include "utility/twi.h"
#include "Wire.h"
#include "presets.h"
#include "knubUtils.h"


unsigned int baseIndx  = 0;

unsigned int  presetIndx = 0;

void setup(){

	
	Serial.begin(9600);
	
	Wire.begin();
	delay(500);
	
	// Serial.println("STARTING");
	// 	eraseEE();
	// Serial.println("DONE ERASING");

	
	for(int i =0; i<20; i++){
		
		//currentPreset.name[6] = i;
		Serial.println(i+1);
		writeAPreset(0, i);
		delay(100);
		readAPreset(0);
	}
	
}


void loop(){
}

void eraseEE(){

	for(int i = 0; i < 20000; i ++){

		writeByte(eepromAddr1, i, 0xFF);
		//delay(5);
		Serial.print("-");
	}	
	
	Serial.println("ready");
}

void readEE(){

	for(int i = 0; i < 20000; i ++){

		Serial.print(readByte(eepromAddr1, i));
		delay(5);
		Serial.print("/");
	}

	Serial.println("ready");
}


void readAPreset(unsigned int pIndx){

	presetIndx = ((pIndx - baseIndx)*presetSize)+baseIndx;

	readKnubPreset(eepromAddr1, presetIndx, &currentPreset);
	delay(100);
	printCurrentPreset();
	delay(100);
	//presetIndx = 0;
}

void writeAPreset(unsigned int wich, unsigned int pIndx){



	presetIndx = ((pIndx - baseIndx)*presetSize)+baseIndx;
	

	Serial.print("writing at address : ");
	Serial.println(presetIndx);
	
	writeKnubPreset(eepromAddr1, presetIndx, &currentPreset);
		
	
	Serial.println("Done writing");
	presetIndx = 0;
}

