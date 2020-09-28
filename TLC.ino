const int redPin = 11; //Red led attached to pin 11

const int yellowPin = 9; //Yellow led attached to pin 9

const int greenPin = 10; //Green led attached to pin 10


const int buzzerPin = 12; // Buzzer pin attached to pin 12

const int pressPin = 8; // Positive pin of the Switch attached to pin 8


const int stPin = 3;//Pin connected to ST_CP of 74HC595

const int shPin = 2;//Pin connected to SH_CP of 74HC595 

const int dsPin = 4; //Pin connected to DS of 74HC595


int digit1 = 7; // Digit 1 of 74HC595 

int digit2 = 6; // Digit 2 of 74HC595


const byte Digit1[2] = {0b00000110, 0b10111111}; // Data to Drive the Digit 1
 
const byte Digit2[16] = {0b01101101, 0b1100110, 0b01001111, 0b01011011, 0b00000110, 0b10111111, 0b01101111, 0b01111111, // Data to Drive the Digit 2

                         0b00000111, 0b01111101, 0b01101101, 0b1100110, 0b01001111, 0b01011011, 0b00000110, 0b10111111};


void setup(){

        pinMode(yellowPin, OUTPUT); // Set the yellowPin as an output
        
        pinMode(greenPin, OUTPUT); // Set the greenPin as an output
      
        pinMode(redPin, OUTPUT);  // Set the redPin as an output
        
        
        pinMode(digit1, OUTPUT);// Set the digitPin as an output

        pinMode(digit2, OUTPUT);// Set the digitPin as an output
        
        pinMode(buzzerPin, OUTPUT);// Set the buzzerPin as an output
      
        pinMode(pressPin, INPUT);// Set the pressPin as an output      
         
            
        pinMode(stPin, OUTPUT);// Set the latchPin as an output
        
        pinMode(shPin, OUTPUT);// Set the clockPin as an output
        
        pinMode(dsPin, OUTPUT);// // Set the dataPin as an output
  
}


void loop(){ 

  // The red LED Flashes until the Switch is pressed

  if(digitalRead(pressPin) == 0){ 
    
     digitalWrite(redPin, HIGH);

     delay(500);

     digitalWrite(redPin, LOW);
       
     delay(500);

  }

  else{

   // The Three State Machine
    
    redState();     
    
    greenState();      
  
    yellowState();
    

    // To Clear the 7 Segment Display

    digitalWrite(stPin, LOW);

    shiftOut(dsPin, shPin, MSBFIRST, 0b00000000);

    digitalWrite(stPin, HIGH); 
    
   }
}

// State of the red LED

void redState(){ 
 
 // Displaying the 15 minutes remaining time
  
  for (int k = 0; k <= 1; k++)

   for (int n = 0; n <= 15; n++){

      digitalWrite(redPin,HIGH);

       if ( n >= 6) // Displaying zero on digit 1

            k = 1;
    
       for (int m = 0; m < 65; m++){ // Delaying the Display so it is visible to us

        if( digitalRead(pressPin) == 0){
       
        break; // Leave the redState when the Switch is pressed

        }
       
        digitalWrite(digit1, 1);
  
        digitalWrite(digit2, 0);

        
        digitalWrite(stPin, LOW);
        
        shiftOut(dsPin, shPin, MSBFIRST, Digit1[k]);
        
        digitalWrite(stPin, HIGH);
        
        delay(5);
 
        digitalWrite(digit1, 0);
  
        digitalWrite(digit2, 1);
        
        digitalWrite(stPin, LOW);
        
        shiftOut(dsPin, shPin, MSBFIRST, Digit2[n]);
        
        digitalWrite(stPin, HIGH);
        
        delay(5);

       }
      
     if( digitalRead(pressPin) == 0){
       
        break; // Leave the redState when the Switch is pressed

        }

    if(n == 12){

      tone(buzzerPin, HIGH); // Buzzer goes off 3 seconds before the change of the light

    }    
   
  }
 
  digitalWrite(redPin, LOW); // Turn off the red LED

  noTone(buzzerPin); // Turn off the Buzzer
  
}

// State of the Green LED
  
void greenState(){ 
 
 // Displaying the 15 minutes remaining time
  
  for (int k = 0; k <= 1; k++)

   for (int n = 0; n <= 15; n++){  

    if( digitalRead(pressPin) == 0){
       
        break; // Leave the greenState when the Switch is pressed

        }

     digitalWrite(greenPin,HIGH); 


       if ( n >= 6)

            k = 1;
    
       for (int m = 0; m < 65; m++){ // Delaying the Display so it is visible to us
       
        digitalWrite(digit1, 1);
  
        digitalWrite(digit2, 0);

        
        digitalWrite(stPin, LOW);
        
        shiftOut(dsPin, shPin, MSBFIRST, Digit1[k]);
        
        digitalWrite(stPin, HIGH);
        
        delay(5);
 
        digitalWrite(digit1, 0);
  
        digitalWrite(digit2, 1);
        
        digitalWrite(stPin, LOW);
        
        shiftOut(dsPin, shPin, MSBFIRST, Digit2[n]);
        
        digitalWrite(stPin, HIGH);
        
        delay(5);

       }
      
     if( digitalRead(pressPin) == 0){
       
        break; // Leave the GreenState when the Switch is pressed

        }

    if(n == 12){

      tone(buzzerPin, HIGH); // Buzzer goes off 3 seconds before the change of the light

    }    
   
  }
 
  digitalWrite(greenPin, LOW); // Turn off the Green LED

  noTone(buzzerPin); // Turn off the Buzzer
  
}

// State of the Yellow LED

void yellowState(){ 
 
 // Displaying the 15 minutes remaining time

  for (int k = 1; k <= 1; k++){

   for (int n = 12; n <= 15; n++){ 

    if( digitalRead(pressPin) == 0){
       
        break; // Leave the YellowState when the Switch is pressed

        }

      digitalWrite(yellowPin,HIGH); 

   for (int m = 0; m < 65; m++){ // Delaying the Display so it is visible to us
       
        digitalWrite(digit1, 1);
  
        digitalWrite(digit2, 0);

        
        digitalWrite(stPin, LOW);
        
        shiftOut(dsPin, shPin, MSBFIRST, Digit1[k]);
        
        digitalWrite(stPin, HIGH);
        
        delay(5);
 
        digitalWrite(digit1, 0);
  
        digitalWrite(digit2, 1);
        
        digitalWrite(stPin, LOW);
        
        shiftOut(dsPin, shPin, MSBFIRST, Digit2[n]);
        
        digitalWrite(stPin, HIGH);
        
        delay(5);

       }
      
     if( digitalRead(pressPin) == 0){
       
        break; // Leave the YellowState when the Switch is pressed

        }

    if(n == 12){

      tone(buzzerPin, HIGH); // Buzzer goes off 3 seconds before the change of the light

    }    
   
  }
  }
  digitalWrite(yellowPin, LOW); // Turn off the Yellow LED

  noTone(buzzerPin); // Turn off the Buzzer
  
}
