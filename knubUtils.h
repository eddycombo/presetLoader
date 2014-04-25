void checkEdition(bool editState){

	if(editState == false){

		editState == true;	

	}
}


void printCurrentPreset(){

	//for(int i = 0 ; i<8; i++){
		Serial.println(currentPreset.name);
 	//}

 	Serial.println("----------------------");
   	
   	Serial.println("KNUBBIES: ");

   	//Serial.println(currentPreset.knubbies[0].name);
   	
   	for(int i = 0; i<numKnubbies; i++){
   		for (int j = 0; j<8;j++)
   			Serial.print((char)currentPreset.knubbies[i].name[j]);
   		}
   	Serial.println(";");
   	   	
 	
 	
 	Serial.println("----------------------");
   	
   	Serial.println("OUT 1 PARAMS : ");

   	for(int i = 0; i<paramLength; i++){

   		Serial.println(currentPreset.knubbies[0].params[i]);
	}
 

	Serial.println("OUT 1 modOn: ");
	Serial.println(currentPreset.knubbies[0].modOn);
	Serial.println("OUT 1 STATE: ");
	Serial.println(currentPreset.knubbies[0].state);
	Serial.println("OUT 1 NUMLOOP: ");
	Serial.println(currentPreset.knubbies[0].numLoop);

	Serial.println("----------------------");
   	Serial.println("OUT 2 PARAMS : ");

   	for(int i = 0; i<paramLength; i++){

   		Serial.println(currentPreset.knubbies[1].params[i]);
	}
 

	Serial.println("OUT 2 modOn: ");
	Serial.println(currentPreset.knubbies[1].modOn);
	Serial.println("OUT 2 STATE: ");
	Serial.println(currentPreset.knubbies[1].state);
	Serial.println("OUT 2 NUMLOOP: ");
	Serial.println(currentPreset.knubbies[1].numLoop);

	Serial.println("----------------------");
   	Serial.println("OUT 3 PARAMS : ");

   	for(int i = 0; i<paramLength; i++){

   		Serial.println(currentPreset.knubbies[2].params[i]);
	}
 

	Serial.println("OUT 3 modOn: ");
	Serial.println(currentPreset.knubbies[2].modOn);
	Serial.println("OUT 3 STATE: ");
	Serial.println(currentPreset.knubbies[2].state);
	Serial.println("OUT 3 NUMLOOP: ");
	Serial.println(currentPreset.knubbies[2].numLoop);

	Serial.println("----------------------");
   	Serial.println("OUT 4 PARAMS : ");

   	for(int i = 0; i<paramLength; i++){

   		Serial.println(currentPreset.knubbies[3].params[i]);
	}
 

	Serial.println("OUT 4 modOn: ");
	Serial.println(currentPreset.knubbies[3].modOn);
	Serial.println("OUT 4 STATE: ");
	Serial.println(currentPreset.knubbies[3].state);
	Serial.println("OUT 4 NUMLOOP: ");
	Serial.println(currentPreset.knubbies[3].numLoop);

	Serial.println("----------------------");
   	Serial.println("OUT 5 PARAMS : ");

   	for(int i = 0; i<paramLength; i++){

   		Serial.println(currentPreset.knubbies[4].params[i]);
	}
 

	Serial.println("OUT 5 modOn: ");
	Serial.println(currentPreset.knubbies[4].modOn);
	Serial.println("OUT 5 STATE: ");
	Serial.println(currentPreset.knubbies[4].state);
	Serial.println("OUT 5 NUMLOOP: ");
	Serial.println(currentPreset.knubbies[4].numLoop);

	Serial.println("----------------------");
   	Serial.println("OUT 6 PARAMS : ");

   	for(int i = 0; i<paramLength; i++){

   		Serial.println(currentPreset.knubbies[5].params[i]);
	}
 	
 	Serial.println("OUT 6 modOn: ");
	Serial.println(currentPreset.knubbies[5].modOn);
	Serial.println("OUT 6 STATE: ");
	Serial.println(currentPreset.knubbies[5].state);
	Serial.println("OUT 6 NUMLOOP: ");
	Serial.println(currentPreset.knubbies[5].numLoop);


	Serial.println("----------------------");
   	Serial.println("OUT 7 PARAMS : ");

   	for(int i = 0; i<paramLength; i++){

   		Serial.println(currentPreset.knubbies[6].params[i]);
	}
 	
 	Serial.println("OUT 6 modOn: ");
	Serial.println(currentPreset.knubbies[6].modOn);
	Serial.println("OUT 6 STATE: ");
	Serial.println(currentPreset.knubbies[6].state);
	Serial.println("OUT 6 NUMLOOP: ");
	Serial.println(currentPreset.knubbies[6].numLoop);

	Serial.println("----------------------");
   	Serial.println("OUT 8 PARAMS : ");

   	for(int i = 0; i<paramLength; i++){

   		Serial.println(currentPreset.knubbies[7].params[i]);
	}
 	
 	Serial.println("OUT 8 modOn: ");
	Serial.println(currentPreset.knubbies[7].modOn);
	Serial.println("OUT 8 STATE: ");
	Serial.println(currentPreset.knubbies[7].state);
	Serial.println("OUT 8 NUMLOOP: ");
	Serial.println(currentPreset.knubbies[7].numLoop);
		
}
