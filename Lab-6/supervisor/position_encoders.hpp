#ifndef POSITION_ENCODERS_HPP
#define POSITION_ENCODERS_HPP

#define DDR_POSITION_ENCODER DDRD
#define PORT_POSITION_ENCODER PORTD
#define LEFT_PIN 2
#define RIGHT_PIN 3

void setup_position_encoders();
int left_position_encoder();
int right_position_encoder();

#endif
