#include <Arduino.h>
#include <avr/interrupt.h>
#include "position_encoders.hpp"

static int left_counter = 0;
static int right_counter = 0;

void setup_position_encoders() {
  DDRD &= ~((1 << 7) | (1 << 4)); // D7 is used for the IRBR sensor, D4 is used for the PROXC sensor
  PORTD &= ~((1 << 7) | (1 << 4));
  DDRB &= ~((1 << 1) | 0x01); // D9 is used for the PROXR sensor, D8 is used for the IRBL sensor
  PORTB &= ~((1 << 1) | 0x01);
  
  cli();
  EICRA = 0x0A; // Configure to use falling edge interrupts for D2 and D3 (LEFT_PIN and RIGHT_PIN)
  EIMSK = 0x03; // Enable external interrupts only for the pins we need
  sei(); // Set global interrupt
}
