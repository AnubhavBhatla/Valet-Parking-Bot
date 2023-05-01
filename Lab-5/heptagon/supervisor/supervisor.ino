#include "logic.hpp"
#include "drivers.hpp"
//#include "trsensor.hpp"
#define Clock     13
#define Address   12
#define DataOut   11
#define CS        10

int _numSensors = 5;

#define NUM_SENSORS 5

void trsensors(unsigned int* output){
  char i,j;
  unsigned int channel = 0;
  unsigned int values[] = {0,0,0,0,0,0};

  for(j = 0;j < _numSensors + 1;j++)
  {
    digitalWrite(CS,LOW);
    
    for(i = 0;i < 10;i++)
    {
      //0 to 4 clock transfer channel address
      if((i < 4) && (j >> (3 - i) & 0x01))
      digitalWrite(Address,HIGH);
      else
      digitalWrite(Address,LOW);

      //0 to 10 clock receives the previous conversion result
      values[j] <<= 1;
      if(digitalRead(DataOut)) 
      values[j] |= 0x01;
      digitalWrite(Clock,HIGH);
      digitalWrite(Clock,LOW);
    }
    //sent 11 to 16 clock 
    for(i = 0;i < 6;i++)
    {
      digitalWrite(Clock,HIGH);
      digitalWrite(Clock,LOW);
    }
    digitalWrite(CS,HIGH);
  }

  for(i = 0;i < _numSensors;i++)
  {
    output[i] = values[i+1];
  }

  for(int i = 0;i < NUM_SENSORS;i++)
  {
    Serial.print(output[i]);
    Serial.print("\t");
  }
  Serial.print("\n");
  }

Logic__valet_parking_mem memory;
Logic__valet_parking_out output;

void setup() {  
  Serial.begin(115200);
  setup_motors();
  setup_position_encoders();  
//  setup_trsensors();
  Logic__valet_parking_reset(&memory);
  pinMode(Clock, OUTPUT);
  pinMode(Address, OUTPUT);
  pinMode(DataOut, INPUT);
  pinMode(CS, OUTPUT);  
}

int main() {
  
  setup();
  while (true) {
   unsigned int values[5];
   trsensors(values);
   Logic__valet_parking_step(values[0], values[1], values[2],values[3],values[4],
                               0, 0, 0, &output, &memory);
   
  for(int i = 0;i < 5;i++)
  {
    Serial.print(values[i]);
    Serial.print("\t");
  }
  Serial.print("\n");
   int slm = output.left_speed;
   int srm = output.right_speed;
   Serial.print("Left: "); 
   Serial.println(slm);
   Serial.print("Right: ");
   Serial.println(srm);
   //set_speed(0,0);
   set_speed(srm,slm);  
  }
}
