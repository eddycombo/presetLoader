#include <SoftwareSerial.h>
#include "utility/twi.h"
#include "Wire.h"
#include "presets.h"
#include "knubUtils.h"
#include "knubMidi.h"

unsigned int baseIndx  = 5;
unsigned val;
char tmpStr[8];
unsigned int  presetIndx = 0;

void setup(){

	
	Serial.begin(9600);
	
	Wire.begin();
	delay(500);
	
	Serial.println("STARTING");
		eraseEE();
	Serial.println("DONE ERASING");


	/////!!!! this works put in a for loop

	
for(int i =0; i<5;i++){

	String stringOne = "PGM   ";
	
	stringOne += i+1;
	
	char charBuf[8];
	stringOne.toCharArray(charBuf, 8);
	
	for(int j = 0;j<8;j++){
		currentPreset.name[j] =  charBuf[j];
	}
	Serial.println(sizeof(charBuf)/sizeof(char));
	Serial.println("WRITING PRESETS");
	writeAPreset(0, i+baseIndx);
	delay(100);
	Serial.println("DONE WRITING PRESETS");
	// Serial.println(currentPreset.name);
	// Serial.println(sizeof(currentPreset.name)/sizeof(char));
	// delay(100);
}



	////////////++++++++++++++++++++++++++++++++

	
	
	// writeAPreset(0, 5);
	// delay(10);
	
	
	// writeAPreset(1, 6);
	// delay(10);
	
	
	// writeAPreset(2, 7);
	// delay(10);
	
	// writeAPreset(3, 8);
	// delay(10);
	

	for(int i = 0; i<10;i++){
		readAPreset(i+5);
		delay(20);
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
	presetIndx = 0;
}

void writeAPreset(uint8_t wich, uint8_t pIndx){

	Serial.println(pIndx);

	presetIndx = ((pIndx - baseIndx)*presetSize)+baseIndx;
	

	Serial.print("writing at address : ");
	Serial.println(presetIndx);
	
	//makeSpace(presetIndx*presetSize);

	switch(wich){

		case 0:
			writeKnubPreset(eepromAddr1, presetIndx, &currentPreset);
		break;
		case 1:
			writeKnubPreset(eepromAddr1, presetIndx, &preset2);
		break;
		case 2:
			writeKnubPreset(eepromAddr1, presetIndx, &preset3);
		break;
		case 3:
			writeKnubPreset(eepromAddr1, presetIndx, &preset4);
		break;
		// case 4:
		// 	writeKnubPreset(eepromAddr1, presetIndx, &preset5);
		// break;
		// case 5:
		// 	writeKnubPreset(eepromAddr1, presetIndx, &preset6);
		// break;
		// case 6:
		// 	writeKnubPreset(eepromAddr1, presetIndx, &preset7);
		// break;
		// case 7:
		// 	writeKnubPreset(eepromAddr1, presetIndx, &preset8);
		// break;
	}
	
	Serial.println("Done writing");
	presetIndx = 0;
}

