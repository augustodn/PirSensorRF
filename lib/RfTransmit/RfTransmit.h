#include <Arduino.h>
#define RFTRANSMITPIN 4  //RF Transmitter pin = digital pin 4
#define LEDPIN 13        //Onboard LED = digital pin 13
#define TIMEDELAY 150
#define CODESIZE 30

void toggleCode();
void transmitCode();
