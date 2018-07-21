/*
 * IRremote: IRsendRawDemo - demonstrates sending IR codes with sendRaw
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 *
 * IRsendRawDemo - added by AnalysIR (via www.AnalysIR.com), 24 August 2015
 *
 * This example shows how to send a RAW signal using the IRremote library.
 * The example signal is actually a 32 bit NEC signal.
 * Remote Control button: LGTV Power On/Off. 
 * Hex Value: 0x20DF10EF, 32 bits
 * 
 * It is more efficient to use the sendNEC function to send NEC signals. 
 * Use of sendRaw here, serves only as an example of using the function.
 * 
 */


#include <IRremote.h>
IRsend irsend; // PWM is D3
void setup()
{

}

void loop() {
  for(int k = 0; k < 18 ; k++) // for 9 hours = 30min * 18
  {
    int Onmin =0;
    int Offmin =0;
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    irsend.sendLG(0x8800347,28); // POWER ON
    delay(5000);   
    
    ///////////////////////////////////////////////////////////////////////////////////////
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(200);     
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    irsend.sendLG(0x880B252,28); // Mode1 AI
    delay(2000);      
    
    ///////////////////////////////////////////////////////////////////////////////////////
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(200);     
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(200);   
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(200);     
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    irsend.sendLG(0x8809801,28);  // Mode 2 - removing humidity
  
    ///////////////////////////////////////////////////////////////////////////////////////
    //delay(10000);
    switch (k){
        case 0:
        case 1:
        case 2:      
        case 3:        
              Onmin = 15;
              break;

        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:         
              Onmin = 12;             
              break;

        case 10:
        case 11:
        case 12:
        case 13:
              Onmin = 10;
              break;
        default:
              Onmin = 8;
              break;
    }// end of switch(k)
    delay(Onmin*60*1000);
    ///////////////////////////////////////////////////////////////////////////////////////
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(200);     
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(200);   
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(200);     
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(200);
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(200);     
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW   
    irsend.sendLG(0x88C0051,28); // POWER OFF
  
    ///////////////////////////////////////////////////////////////////////////////////////
    //   delay(2000);
//    switch (k){
//        case 0:
//        case 1:
//        case 2:      
//        case 3:        
//              Offmin = 15;
//              break;
//
//        case 4:
//        case 5:
//        case 6:
//        case 7:
//        case 8:
//        case 9:        
//              Offmin = 18;              
//              break;
//
//        case 10:
//        case 11:
//        case 12:
//        case 13:
//        case 14:
//        case 15:
//              Offmin = 20;   
//              break;
//        default:
//              Offmin = 22;
//            break;
//    }// end of switch(k)   
    Offmin = 30-Onmin;
    delay(Offmin * 60* 1000);
  }
}
