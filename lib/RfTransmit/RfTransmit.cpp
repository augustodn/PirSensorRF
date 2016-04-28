/* 
  Transmit sketch - RF Calibration
     Written by ScottC 17 July 2014
     Arduino IDE version 1.0.5
     Website: http://arduinobasics.blogspot.com
     Transmitter: FS1000A/XY-FST
     Description: A simple sketch used to calibrate RF transmission.          
 ------------------------------------------------------------- */
#include "RfTransmit.h"

int codeToTransmit[]={2,2,1,4,5,1,5,1,5,2,2,1,5,2,2,1,5,2,1,5,2,2,2,1,5,1,5,1,
                      5,3}; //The RF code that will turn the light ON
int lightON[]={2,2,2,2,1,4,4,4,4,5,1,4,4,4,4,4,4,5,2,2,2,2,2,
                2,3}; //The RF code that will turn the light OFF
int lightOFF[]={2,2,2,2,1,4,4,4,4,5,1,4,4,4,4,4,4,5,2,2,2,2,2,
                2,3}; //The RF code that will turn the light OFF
int codeToggler = 0;  //Used to switch between turning the light ON and OFF



void toggleCode()
{
  if(codeToggler)
  {
    for(int i = 0; i<CODESIZE; i++)
    {
      codeToTransmit[i]=lightON[i];
    } 
      
  }else
  {
    for(int i = 0; i<CODESIZE; i++)
    {
      codeToTransmit[i]=lightOFF[i];
    } 
  }
  codeToggler=!codeToggler;
}
   
   
  /*-----------------------------------------------------------------
    transmitCode(): Used to transmit the signal to the RF receiver on
                    the fan/light. There are 6 different HIGH-LOW signal combinations. 
                    
                    SH = short high   or  LH = long high   
                                     PLUS
         SL = short low    or    LL = long low    or    VLL = very long low
                    
  -------------------------------------------------------------------*/
void transmitCode()
{
  // The LED will be turned on to create a visual signal transmission indicator.
  digitalWrite(LEDPIN, HIGH);
 
  //initialise the variables 
  int highLength = 0;
  int lowLength = 0;
  
  //The signal is transmitted 6 times in succession - this may vary with your remote.       
  for(int j = 0; j<24; j++)
  {
    for(int i = 0; i<CODESIZE; i++)
    { 
      switch(codeToTransmit[i])
      {
        case 1: // SH + SL
          highLength=2;
          lowLength=2;
        break;
        case 2: // SH + LL
          highLength=2;
          lowLength=5;
        break;
        case 3: // SH + VLL
          highLength=2;
          lowLength=66;
        break;
        case 4: // LH + SL
          highLength=5;
          lowLength=2;
        break;
        case 5: // LH + LL
          highLength=5;
          lowLength=5;
        break;
        case 6: // LH + VLL
          highLength=5;
          lowLength=66;
        break;
      }
      /* Transmit a HIGH signal - the duration of transmission will be determined 
        by the highLength and timeDelay variables */
      digitalWrite(RFTRANSMITPIN, HIGH);     
      delayMicroseconds(highLength*TIMEDELAY); 
     
      /* Transmit a LOW signal - the duration of transmission will be determined 
        by the lowLength and timeDelay variables */
      digitalWrite(RFTRANSMITPIN,LOW);     
      delayMicroseconds(lowLength*TIMEDELAY);  
    }
  }
  //Turn the LED off after the code has been transmitted.
  digitalWrite(LEDPIN, LOW);
}
