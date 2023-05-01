#include <Arduino.h>
#include <avr/interrupt.h>
#include "position_encoders.hpp"

static int left_counter = 0;
static int right_counter = 0;

void setup_position_encoders() {
  DDR_POSITION_ENCODER &= ~((1 << LEFT_PIN) | (1 << RIGHT_PIN)); // Set pins as inputs
  PORTD |= ((1 << LEFT_PIN) | (1 << RIGHT_PIN));
  DDR_POSITION_ENCODER &= ~(1 << 7); // Set pins as inputs
  PORTD &= ~(1 << 7);// Set pins as input
  DDRB &= ~(0x01);
  PORTB &= ~(0x01);
  
  cli();
  EICRA = 0x0A; // Configure to use falling edge interrupts for D2 and D3 (LEFT_PIN and RIGHT_PIN)
  EIMSK = 0x03; // Enable external interrupts only for the pins we need
  sei(); // Set global interrupt
}

ISR(INT1_vect) {
  left_counter = left_counter+1;
}

ISR(INT0_vect) {
  right_counter = right_counter+1;
}

int left_position_encoder() {
  return left_counter;
}

int right_position_encoder() {
  return right_counter;
}
