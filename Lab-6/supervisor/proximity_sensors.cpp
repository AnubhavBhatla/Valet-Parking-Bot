#include <Arduino.h>
#include "proximity_sensors.hpp"

void setup_proximity_sensors() {
    DDRD &= ~((1 << 7) | (1 << 4)); // D7 is used for the IRBR sensor, D4 is used for the PROXC sensor
    PORTD &= ~((1 << 7) | (1 << 4));
    DDRB &= ~((1 << 1) | 0x01); // D9 is used for the PROXR sensor, D8 is used for the IRBL sensor
    PORTB &= ~((1 << 1) | 0x01);
}