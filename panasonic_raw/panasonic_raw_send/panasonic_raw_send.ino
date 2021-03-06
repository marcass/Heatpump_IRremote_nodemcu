/* Send raw panasonic signal to heatpump to emulate
 * Panasonic remote number A75C2317
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Code borrowed from "Copyright 2009 Ken Shirriff"
 * http://arcfn.com
  * Altered by Marcus
 */

#include "IRremote.h"


IRsend irsend;

void setup()
{ 
 pinMode(3, OUTPUT);
 digitalWrite(3, LOW);
 pinMode(2, INPUT);
 digitalWrite(2, LOW);
 pinMode(8, INPUT);
 digitalWrite(8, LOW);
 Serial.begin(9600);
 Serial.println("IR Demo raw send a harvested cmd to Panasonic heatpump");
 pinMode(13, OUTPUT);
}

// constants won't change. They're used here to set pin numbers:
const int PinOn = 2;     // the number of the pin for on
const int PinOff = 8;     // the number of the pin for off


// variables will change:
int OnState = 0;         // variable for reading the pin status
int OffState = 1;         // variable for reading the pin status

void loop(){
  // read the state of the input pin value:
  OnState = digitalRead(PinOn);
  OffState = digitalRead(PinOff);

  #define first_push
  //  #define second_push
  //  #define third_push
  //  #define fourth_push


  #ifdef first_push
  unsigned int raw[105] = {3528, 3464, 884, 2604, 888, 856, 896, 844, 900, 2588, 876, 868, 876, 2612, 880, 864, 876, 868, 896, 2592, 872, 868, 880, 864, 872, 2616, 900, 844, 872, 2616, 876, 868, 872, 868, 876, 868, 872, 868, 876, 2616, 872, 868, 876, 868, 872, 868, 876, 868, 872, 868, 876, 868, 872, 868, 892, 2596, 904, 840, 872, 872, 888, 852, 876, 868, 872, 868, 3520, 3464, 900, 2592, 872, 868, 904, 840, 900, 2588, 876, 868, 900, 2588, 876, 868, 872, 868, 876, 2612, 904, 840, 876, 868, 876, 2612, 876, 868, 872, 2616, 876, 868, 872, 868, 876, 864, 876, 868, 900};
  // check if the pin is brought to high.
    // if it is, the OnState|OffState is HIGH:
    if (OnState == HIGH && OffState == LOW) {
      // send IR signal for on:
      // altered the code just to send/test my raw code
      irsend.sendRaw(raw,105,40);
      digitalWrite(13, HIGH);
      delay(500);
      digitalWrite(13, LOW);
      Serial.println("IR raw sent");
//      delay(2000);
    }
    else {
    // do nothing
       
    }    
  #endif 
  
  #ifdef second_push
    unsigned int raw[69] = {3528, 3464, 900, 2588, 900, 844, 900, 840, 900, 2588, 900, 844, 900, 2588, 900, 844, 900, 840, 900, 2592, 900, 840, 900, 844, 900, 2588, 900, 844, 900, 2588, 900, 844, 900, 840, 900, 844, 900, 840, 900, 2588, 904, 840, 900, 844, 900, 840, 900, 844, 900, 840, 900, 844, 900, 840, 900, 2588, 900, 844, 900, 844, 900, 840, 900, 844, 900, 840, 3520, 3464, 900};
    // check if the pin is brought to high.
    // if it is, the OnState|OffState is HIGH:
    if (OnState == HIGH && OffState == LOW) {
      // send IR signal for on:
      // altered the code just to send/test my raw code
      irsend.sendRaw(raw,69,40);
      Serial.println("IR raw sent");
//      delay(2000);;
    }
    else {
    // do nothing
       
    }
  #endif
  
  #ifdef third_push
    unsigned int raw[531] = {3524, 3488, 876, 2616, 872, 868, 900, 844, 900, 2588, 872, 872, 872, 2616, 876, 868, 900, 840, 876, 2612, 876, 868, 872, 872, 872, 2616, 900, 840, 880, 2612, 872, 868, 876, 868, 876, 864, 876, 868, 872, 2620, 872, 868, 872, 868, 872, 872, 872, 868, 876, 868, 872, 868, 876, 868, 896, 2592, 872, 872, 872, 872, 868, 872, 872, 868, 876, 868, 3496, 3488, 872, 2616, 876, 868, 876, 868, 896, 2592, 872, 868, 876, 2616, 872, 868, 876, 868, 872, 2616, 876, 868, 880, 860, 876, 2616, 872, 868, 876, 2616, 872, 868, 876, 868, 872, 868, 872, 872, 872, 2616, 872, 872, 872, 868, 872, 872, 872, 868, 900, 840, 876, 868, 872, 872, 872, 2616, 872, 868, 876, 868, 884, 856, 900, 844, 872, 872, 3492, 3488, 876, 2616, 872, 872, 872, 868, 872, 2616, 876, 868, 872, 2616, 900, 844, 900, 840, 900, 2592, 900, 844, 868, 872, 872, 2616, 876, 868, 872, 2616, 876, 868, 896, 844, 876, 868, 872, 868, 880, 2612, 872, 868, 872, 868, 888, 856, 872, 872, 872, 868, 872, 872, 872, 868, 876, 2612, 876, 868, 872, 872, 872, 868, 876, 868, 872, 868, 3520, 3464, 900, 2588, 876, 868, 892, 852, 872, 2616, 872, 872, 872, 2616, 876, 868, 896, 844, 872, 2616, 876, 868, 900, 840, 876, 2616, 872, 872, 872, 2616, 872, 872, 872, 868, 872, 868, 876, 868, 872, 2616, 872, 872, 872, 872, 872, 868, 872, 868, 876, 868, 872, 868, 872, 872, 872, 2616, 872, 872, 872, 868, 876, 868, 872, 868, 872, 872, 3496, 3488, 872, 2616, 876, 868, 872, 868, 876, 2616, 872, 868, 896, 2600, 872, 864, 876, 868, 872, 2616, 872, 872, 872, 868, 872, 2616, 876, 868, 900, 2592, 868, 872, 872, 872, 872, 868, 872, 872, 896, 2592, 872, 872, 872, 868, 872, 872, 896, 844, 900, 840, 900, 844, 876, 864, 904, 2588, 872, 868, 872, 872, 876, 864, 876, 868, 872, 868, 3496, 3488, 876, 2616, 876, 868, 872, 868, 872, 2616, 876, 868, 876, 2616, 872, 868, 872, 868, 876, 2616, 872, 868, 900, 844, 872, 2616, 876, 868, 872, 2616, 900, 844, 896, 844, 872, 872, 872, 868, 872, 2620, 872, 868, 900, 840, 900, 844, 872, 868, 876, 868, 872, 872, 872, 868, 900, 2588, 876, 868, 876, 868, 872, 868, 900, 840, 876, 868, 3492, 3492, 876, 2616, 872, 868, 872, 872, 872, 2616, 872, 872, 872, 2616, 876, 864, 876, 868, 900, 2588, 876, 868, 872, 868, 876, 2616, 872, 868, 880, 2612, 872, 868, 872, 872, 872, 868, 876, 868, 872, 2616, 872, 872, 872, 868, 876, 868, 872, 868, 876, 868, 872, 868, 884, 860, 872, 2616, 872, 872, 872, 868, 872, 868, 876, 868, 872, 872, 3492, 3492, 872, 2616, 876, 868, 872, 896, 844, 2620, 872, 868, 872, 2620, 872, 868, 872, 872, 872, 2616, 872, 872, 872, 872, 868, 2620, 872, 868, 872, 2620, 868, 896, 848, 868, 876, 868, 872, 872, 868, 2620, 872, 872, 868, 872, 872, 868, 872, 872, 872, 896, 848, 868, 876, 868, 868, 2620, 872, 872, 868, 896, 848, 868, 872, 872, 872, 868, 3496, 3488, 876};
    // check if the pin is brought to high.
    // if it is, the OnState|OffState is HIGH:
    if (OnState == HIGH && OffState == LOW) {
      // send IR signal for on:
      // altered the code just to send/test my raw code
      irsend.sendRaw(raw,531,40);
      Serial.println("IR raw sent");
//      delay(2000);
    }  
    else {
    // do nothing
    }
  #endif 
 
  #ifdef fourth_push
    unsigned int raw[465] = {3524, 3488, 876, 2616, 872, 868, 900, 844, 900, 2588, 872, 872, 872, 2616, 876, 868, 900, 840, 876, 2612, 876, 868, 872, 872, 872, 2616, 900, 840, 880, 2612, 872, 868, 876, 868, 876, 864, 876, 868, 872, 2620, 872, 868, 872, 868, 872, 872, 872, 868, 876, 868, 872, 868, 876, 868, 896, 2592, 872, 872, 872, 872, 868, 872, 872, 868, 876, 868, 3496, 3488, 872, 2616, 876, 868, 876, 868, 896, 2592, 872, 868, 876, 2616, 872, 868, 876, 868, 872, 2616, 876, 868, 880, 860, 876, 2616, 872, 868, 876, 2616, 872, 868, 876, 868, 872, 868, 872, 872, 872, 2616, 872, 872, 872, 868, 872, 872, 872, 868, 900, 840, 876, 868, 872, 872, 872, 2616, 872, 868, 876, 868, 884, 856, 900, 844, 872, 872, 3492, 3488, 876, 2616, 872, 872, 872, 868, 872, 2616, 876, 868, 872, 2616, 900, 844, 900, 840, 900, 2592, 900, 844, 868, 872, 872, 2616, 876, 868, 872, 2616, 876, 868, 896, 844, 876, 868, 872, 868, 880, 2612, 872, 868, 872, 868, 888, 856, 872, 872, 872, 868, 872, 872, 872, 868, 876, 2612, 876, 868, 872, 872, 872, 868, 876, 868, 872, 868, 3520, 3464, 900, 2588, 876, 868, 892, 852, 872, 2616, 872, 872, 872, 2616, 876, 868, 896, 844, 872, 2616, 876, 868, 900, 840, 876, 2616, 872, 872, 872, 2616, 872, 872, 872, 868, 872, 868, 876, 868, 872, 2616, 872, 872, 872, 872, 872, 868, 872, 868, 876, 868, 872, 868, 872, 872, 872, 2616, 872, 872, 872, 868, 876, 868, 872, 868, 872, 872, 3496, 3488, 872, 2616, 876, 868, 872, 868, 876, 2616, 872, 868, 896, 2600, 872, 864, 876, 868, 872, 2616, 872, 872, 872, 868, 872, 2616, 876, 868, 900, 2592, 868, 872, 872, 872, 872, 868, 872, 872, 896, 2592, 872, 872, 872, 868, 872, 872, 896, 844, 900, 840, 900, 844, 876, 864, 904, 2588, 872, 868, 872, 872, 876, 864, 876, 868, 872, 868, 3496, 3488, 876, 2616, 876, 868, 872, 868, 872, 2616, 876, 868, 876, 2616, 872, 868, 872, 868, 876, 2616, 872, 868, 900, 844, 872, 2616, 876, 868, 872, 2616, 900, 844, 896, 844, 872, 872, 872, 868, 872, 2620, 872, 868, 900, 840, 900, 844, 872, 868, 876, 868, 872, 872, 872, 868, 900, 2588, 876, 868, 876, 868, 872, 868, 900, 840, 876, 868, 3492, 3492, 876, 2616, 872, 868, 872, 872, 872, 2616, 872, 872, 872, 2616, 876, 864, 876, 868, 900, 2588, 876, 868, 872, 868, 876, 2616, 872, 868, 880, 2612, 872, 868, 872, 872, 872, 868, 876, 868, 872, 2616, 872, 872, 872, 868, 876, 868, 872, 868, 876, 868, 872, 868, 884, 860, 872, 2616, 872, 872, 872, 868, 872, 868, 876, 868, 872, 872, 3492, 3492, 872, 2616, 876, 868, 872, 896, 844, 2620, 872, 868, 872, 2620, 872, 868, 872, 872, 872, 2616, 872, 872, 872, 872, 868, 2620, 872, 868, 872, 2620, 868, 896, 848, 868, 876, 868, 872, 872, 868, 2620, 872, 872, 868, 872, 872, 868, 872, 872, 872, 896, 848, 868, 876, 868, 868, 2620, 872, 872, 868, 896, 848, 868, 872, 872, 872, 868, 3496, 3488, 876};
    // check if the pin is brought to high.
    // if it is, the OnState|OffState is HIGH:
    if (OnState == HIGH && OffState == LOW) {
      // send IR signal for on:
      // altered the code just to send/test my raw code
      irsend.sendRaw(raw,465,40);
      Serial.println("IR raw sent");
//      delay(2000);
    }
    else {
    // do nothing
    }    
  #endif
}

