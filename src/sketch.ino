#include <RfTransmit.h>
#define BATTERYPIN 0
#define LOWBATTVALUE 680

int batteryValue = 0;
/*
* RfTransmitter varibles
*/
void setup()
{
    Serial.begin(115200);
/*
* RfTransmitter 
*/
   pinMode(RFTRANSMITPIN, OUTPUT);   //Transmit pin is an output  
   pinMode(LEDPIN, OUTPUT);          
  
  //LED initialisation sequence - gives us some time to get ready
  digitalWrite(LEDPIN, HIGH); 
  delay(3000);
  digitalWrite(LEDPIN, LOW); 
  delay(1000);


}

void loop()
{
    batteryValue = analogRead(BATTERYPIN);
    if (batteryValue < LOWBATTVALUE)
    {
        Serial.print("Bateria Baja ");
        Serial.println(batteryValue);
        transmitCode();  // transmit the code to RF receiver on the Fan/Light
        Serial.print("Time Delay: ");
        Serial.println(TIMEDELAY); 
        delay(2000);      //Each transmission will be about 2 seconds apart.
    }
    delay(500);

    
}
