#include <Arduino.h>
#include "trsensor.hpp"

static int _numSensors = 5;

void setup_trsensors() {
  DDRB  |= (1 << CLOCK) | (1 << ADDRESS) | (1 << DATAOUT); // Clock, address, and CS as output
  DDRB  &= !(1 << DATAOUT); // Dataout as input
  PORTB |= 1 << DATAOUT; // Activate pull-up register for dataout
}

void read_trsensors(unsigned int* output) {
  char i,j;
  unsigned int channel = 0;
  unsigned int values[] = {0,0,0,0,0,0};

  for(j = 0;j < _numSensors + 1;j++)
  {
    PORTB &= !(1 << CS); // digitalWrite(CS,LOW);
    for(i = 0;i < 10;i++)
    {
      //0 to 4 clock transfer channel address
      if((i < 4) && (j >> (3 - i) & 0x01))
      PORTB |= 1 << ADDRESS; // digitalWrite(Address,HIGH);
      else
      PORTB &= !(1 << ADDRESS); // digitalWrite(Address,LOW);

      //0 to 10 clock receives the previous conversion result
      values[j] <<= 1;
      if(PINB & (1 << DATAOUT)) // digitalRead(DataOut) 
      values[j] |= 0x01;
      PORTB |= 1 << CLOCK; // digitalWrite(Clock,HIGH);
      PORTB &= !(1 << CLOCK); // digitalWrite(Clock,LOW);
    }
    //sent 11 to 16 clock 
    for(i = 0;i < 6;i++)
    {
      PORTB |= 1 << CLOCK; // digitalWrite(Clock,HIGH);
      PORTB &= !(1 << CLOCK); // digitalWrite(Clock,LOW);
    }
    PORTB |= 1 << CS; // digitalWrite(CS,HIGH);
  }

  for(i = 0;i < _numSensors;i++)
  {
    output[i] = values[i+1];
  }
}