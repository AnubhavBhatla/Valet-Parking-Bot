#include <stdio.h>
#include <math.h>
#include "var.h"

void reset(memory* self) {
    self->sum = 0;
    self->square_sum = 0;
    self->entries = 0;
}

void step(int x, out* _out, memory* self) {
    // update memory for the next step
    self->sum = self->sum + x;
    self->square_sum = self->square_sum + x*x;
    self->entries = self->entries + 1;
    _out->out = (self->square_sum / (float)self->entries) - (self->sum / (float)self->entries)*(self->sum / (float)self->entries);
}
