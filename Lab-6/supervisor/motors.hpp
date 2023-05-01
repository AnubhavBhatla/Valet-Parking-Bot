#ifndef MOTORS_HPP
#define MOTORS_HPP

#define DDR_MOTOR DDRC
#define PORT_MOTOR PORTC
#define DDR_MOTOR_ENABLE DDRD
#define PORT_MOTOR_ENABLE PORTD
#define IN1 0
#define IN2 1
#define IN3 2
#define IN4 3
#define ENA 5
#define ENB 6

void setup_motors();
void set_speed(float sl,float sr);


#endif
