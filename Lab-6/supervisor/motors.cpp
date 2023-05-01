#include <Arduino.h>
#include "motors.hpp"

void setup_motors() {
  DDR_MOTOR  |= (1 << IN1) | (1 << IN2) | (1 << IN3) | (1 << IN4);    // Set IN pins as output
  PORT_MOTOR &= 0xF0; // Set IN pins to 0
  DDR_MOTOR_ENABLE  |= (1 << ENA) | (1 << ENB); // Set enable pins as output
  PORT_MOTOR_ENABLE |= (1 << ENA) | (1 << ENB); // Enable motors
  // Timer initialization
  TCCR0A = 0xA3;
  TCCR0B = 0x03;
  TCNT0 = 0x00;
  OCR0A = 0x00;
  OCR0B = 0x00;  
}

void set_speed(float sr,float sl) {
  if ((sl == 0.0) && (sr == 0.0)) {
    PORT_MOTOR &= 0xF0; // Stop    
  } else if ((sl >= 0.0) && (sr >= 0.0)) {
    PORT_MOTOR &= 0xF0;
    PORT_MOTOR |= 0x09; 
  } else if((sl < 0.0) && (sr >= 0.0)){
    PORT_MOTOR &= 0xF0;
    PORT_MOTOR |= 0x05;
    sl *= -1;
  } else if((sl >= 0.0) && (sr < 0.0)){
    PORT_MOTOR &= 0xF0;
    PORT_MOTOR |= 0x0A;
    sr *= -1;
  } else {
    PORT_MOTOR &= 0xF0;
    PORT_MOTOR |= 0x06; 
    sl *= -1; sr *= -1;// Motor direction has been taken care of. We just need the magnitude
  }
  // Clamping the speed
  if (sl > 100.0){ sl = 196.0; PORT_MOTOR &= 0xF0; PORT_MOTOR |= 0x0A; sr = 196;}
  if (sr > 100.0){ sr = 196.0; PORT_MOTOR &= 0xF0; PORT_MOTOR |= 0x05; sl = 196;}
  OCR0B = (unsigned char)((sl/100)*200); // B maps to left motor
  OCR0A = (unsigned char)((sr/100)*200); // A maps to right motor
}
