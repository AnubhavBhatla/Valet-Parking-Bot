  #include "logic.hpp"
#include "drivers.hpp"

Logic__logic_mem memory;
Logic__logic_out output;

void setup() {  
  setup_motors();
  setup_position_encoders();  
  Logic__logic_reset(&memory);
}

int main() {
  Serial.begin(9600);
  setup();
  while (true) {
   Logic__logic_step((PINB &(0x01)) != 1, (PIND &(1<<7)) >> 7 != 1, &output, &memory);
   int slm = output.left_speed;
   int srm = output.right_speed;
   Serial.print("Left: "); 
   Serial.println(slm);
   Serial.println(OCR0B);
   Serial.print("Right: ");
   Serial.println(srm);
   Serial.println(OCR0A);
   set_speed(slm,srm);  
  }
}
