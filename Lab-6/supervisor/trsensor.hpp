#ifndef TRSENSOR_HPP
#define TRSENSOR_HPP

#define CLOCK     5
#define ADDRESS   4
#define DATAOUT   3
#define CS        2

void setup_trsensors();
void read_trsensors(unsigned int* values);

#endif