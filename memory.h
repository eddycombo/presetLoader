#include "Arduino.h"
#define saveTime 10

#define maxNameLength 8
#define IDLength 6
#define paramLength 3
#define modOnLength 1
#define stateLength 1
#define numLoopLength 1
#define numKnubbies 8

#define presetSize 126
#define modIndx maxNameLength+paramLength
#define stateIndx maxNameLength+paramLength+modOnLength
#define loopIndx maxNameLength+paramLength+modOnLength+stateLength

#define eepromAddr1 0x50

struct aKnub{
  char name[maxNameLength];
  byte params[paramLength];
  byte modOn;
  byte state;
  byte numLoop;
};

typedef struct aKnub aKnub;

struct aKnubPreset{
  
  char name[maxNameLength];
  byte ID[IDLength];
  
  aKnub knubbies[numKnubbies];
};
typedef struct aKnubPreset aKnubPreset;


void writeByte( int deviceaddress, unsigned int eeaddress, byte data ) {
    
    Wire.beginTransmission(deviceaddress);
    Wire.write((int)(eeaddress >> 8)); // MSB
    Wire.write((int)(eeaddress & 0xFF)); // LSB
    Wire.write(data);
    delay(5);
    Wire.endTransmission();
    
  }

  
byte readByte( int deviceaddress, unsigned int eeaddress ) {
   
    Wire.beginTransmission(deviceaddress);
    Wire.write((int)(eeaddress >> 8)); // MSB
    Wire.write((int)(eeaddress & 0xFF)); // LSB
    Wire.endTransmission();

    Wire.requestFrom(deviceaddress,1);
    if (Wire.available());
     return Wire.read();
  
  }


  void writeKnubPresetName( int deviceaddress, unsigned int eeaddresspage, aKnubPreset *kpreset ) {
    
 
    for(uint8_t i = 0; i<maxNameLength; i++){

      writeByte(deviceaddress, eeaddresspage+i, kpreset->name[i]);

    }

  }
  

  void writeKnubPresetID(int deviceaddress, unsigned int eeaddresspage, aKnubPreset *kpreset){

  for(uint8_t i = 0; i<6;i++){

      writeByte(deviceaddress, eeaddresspage+i,kpreset->ID[i]);


    }

  }

  void writeKnubbieName(int deviceaddress, unsigned int eeaddresspage, aKnubPreset *kpreset, uint8_t knubbieIndx){

    for(uint8_t i =0 ; i<maxNameLength;i++){

      writeByte(deviceaddress, eeaddresspage+i, kpreset->knubbies[knubbieIndx].name[i]);
    }

  }
  
 void writeKnubbieParams(int deviceaddress, unsigned int eeaddresspage, aKnubPreset *kpreset, uint8_t knubbieIndx){

    

    for(uint8_t i = 0; i<3;i++){

        writeByte(deviceaddress, eeaddresspage+i, kpreset->knubbies[knubbieIndx].params[i]);

    }

  }

void writeKnubbiemodOn(int deviceaddress, unsigned int eeaddresspage, aKnubPreset *kpreset, uint8_t knubbieIndx){

   
    writeByte(deviceaddress, eeaddresspage, kpreset->knubbies[knubbieIndx].modOn);

  }

void writeKnubbieModState(int deviceaddress, unsigned int eeaddresspage, aKnubPreset *kpreset, uint8_t knubbieIndx){


    writeByte(deviceaddress, eeaddresspage, kpreset->knubbies[knubbieIndx].state);
  }

void writeKnubbieNumLoop(int deviceaddress, unsigned int eeaddresspage, aKnubPreset *kpreset, uint8_t knubbieIndx){


    writeByte(deviceaddress, eeaddresspage, kpreset->knubbies[knubbieIndx].numLoop);
  }


void readKnubPresetName( int deviceaddress, unsigned int eeaddress, aKnubPreset *kpreset) {
    
    Wire.beginTransmission(deviceaddress);
    Wire.write((int)(eeaddress >> 8)); // MSB
    Wire.write((int)(eeaddress & 0xFF)); // LSB
    Wire.endTransmission();
    
    Wire.requestFrom(deviceaddress,maxNameLength);
    
    for (byte c = 0; c < maxNameLength; c++ )
      if (Wire.available()) kpreset->name[c] = Wire.read();
}

void readKnubPresetID( int deviceaddress, unsigned int eeaddress, aKnubPreset *kpreset) {
    
    Wire.beginTransmission(deviceaddress);
    Wire.write((int)(eeaddress >> 8)); // MSB
    Wire.write((int)(eeaddress & 0xFF)); // LSB
    Wire.endTransmission();
    
    Wire.requestFrom(deviceaddress,IDLength);
    
    for(byte c = 0; c<IDLength; c++){
      if (Wire.available()) kpreset->ID[c] = Wire.read();
    }
}

void readKnubbieName( int deviceaddress, unsigned int eeaddress, aKnubPreset *kpreset, uint8_t knubbieIndx) {
    
    Wire.beginTransmission(deviceaddress);
    Wire.write((int)(eeaddress >> 8)); // MSB
    Wire.write((int)(eeaddress & 0xFF)); // LSB
    Wire.endTransmission();
    
    Wire.requestFrom(deviceaddress,maxNameLength);
    
    for (byte c = 0; c < 8; c++ ){
      
        if (Wire.available()){ 
          
          //Serial.println((char)rData);
          kpreset->knubbies[knubbieIndx].name[c] = Wire.read();
      }
  }
}

void readKnubbieParams(int deviceaddress, unsigned int eeaddress, aKnubPreset *kpreset, uint8_t knubbieIndx){


  Wire.beginTransmission(deviceaddress);
    Wire.write((int)(eeaddress >> 8)); // MSB
    Wire.write((int)(eeaddress & 0xFF)); // LSB
    Wire.endTransmission();
    
    Wire.requestFrom(deviceaddress,paramLength);
    
    for ( byte c = 0; c < paramLength; c++ ){
      if (Wire.available()) kpreset->knubbies[knubbieIndx].params[c] = Wire.read();
    }
}

void readKnubbiemodOn(int deviceaddress, unsigned int eeaddress, aKnubPreset *kpreset, uint8_t knubbieIndx){


    Wire.beginTransmission(deviceaddress);
    Wire.write((int)(eeaddress >> 8)); // MSB
    Wire.write((int)(eeaddress & 0xFF)); // LSB
    Wire.endTransmission();
    
    Wire.requestFrom(deviceaddress,1);
  
      if (Wire.available()) kpreset->knubbies[knubbieIndx].modOn = Wire.read();
}
void readKnubbieModState(int deviceaddress, unsigned int eeaddress, aKnubPreset *kpreset, uint8_t knubbieIndx){


  Wire.beginTransmission(deviceaddress);
    Wire.write((int)(eeaddress >> 8)); // MSB
    Wire.write((int)(eeaddress & 0xFF)); // LSB
    Wire.endTransmission();
    
    Wire.requestFrom(deviceaddress,1);
  
      if (Wire.available()) kpreset->knubbies[knubbieIndx].state = Wire.read();
}
void readKnubbieNumLoop(int deviceaddress, unsigned int eeaddress, aKnubPreset *kpreset, uint8_t knubbieIndx){


  Wire.beginTransmission(deviceaddress);
    Wire.write((int)(eeaddress >> 8)); // MSB
    Wire.write((int)(eeaddress & 0xFF)); // LSB
    Wire.endTransmission();
    
    Wire.requestFrom(deviceaddress,1);
  
      if (Wire.available()) kpreset->knubbies[knubbieIndx].numLoop = Wire.read();
}



void readKnubPreset(int deviceaddress, unsigned int eeaddress, aKnubPreset *kpreset){
  
    ///first we read the preset's name and ID
    
    // so name
    readKnubPresetName(deviceaddress, eeaddress, kpreset); 
    //delay(5);
    //then ID
    readKnubPresetID(deviceaddress, eeaddress + maxNameLength, kpreset);
    //delay(5);
    //so now eeaddress is maxNameLength + IDLength
     unsigned int addrPtr = eeaddress + maxNameLength + IDLength;
   

     //readKnubbieName(deviceaddress, addrPtr, kpreset, 0);

   
   for(unsigned int i = 0; i<numKnubbies; i++){
     
     ///move addrPtr to start of knubbie
     unsigned int addrPtr2 = addrPtr*(i+1);
     
     
     readKnubbieName(deviceaddress,addrPtr2 , kpreset, i);
     
     //delay(5);
     readKnubbieParams(deviceaddress, addrPtr2+maxNameLength, kpreset, i);
     //delay(5);  
     readKnubbiemodOn(deviceaddress, addrPtr2+modIndx, kpreset, i);
     //delay(5);
     readKnubbieModState(deviceaddress, addrPtr2+stateIndx, kpreset, i);
     //delay(5);
     readKnubbieNumLoop(deviceaddress, addrPtr2+loopIndx, kpreset, i);
     //delay(5);    
    
   
   }
   
   
}

void writeKnubPreset(int deviceaddress, unsigned int eeaddress, aKnubPreset *kpreset){
  
    // so name
    writeKnubPresetName(deviceaddress, eeaddress, kpreset); 
    delay(saveTime);
    //then ID
    writeKnubPresetID(deviceaddress, eeaddress + maxNameLength, kpreset);
    delay(saveTime);
    //so now eeaddress is maxNameLength + IDLength
    unsigned int addrPtr = eeaddress + maxNameLength + IDLength;
    
    Serial.println("Done writing name and ID");
    //Serial.println(addrPtr);
   

   for(unsigned int i = 0; i<numKnubbies; i++){
     
     ///move addrPtr to start of knubbie
     unsigned int addrPtr2 = addrPtr*(i+1);
     
     // Serial.print("addrPtr= ");
     // Serial.println(addrPtr2);
  
     writeKnubbieName(deviceaddress,addrPtr2 , kpreset, i);
     delay(saveTime);
     
     writeKnubbieParams(deviceaddress, addrPtr2+maxNameLength, kpreset, i);
     delay(saveTime);  
     
     writeKnubbiemodOn(deviceaddress, addrPtr2+maxNameLength+paramLength, kpreset, i);
     delay(saveTime);
     
     writeKnubbieModState(deviceaddress, addrPtr2+maxNameLength+paramLength+modOnLength, kpreset, i);
     delay(saveTime);
     
     writeKnubbieNumLoop(deviceaddress, addrPtr2+maxNameLength+paramLength+modOnLength+stateLength, kpreset, i);
     delay(saveTime);
   }
}


