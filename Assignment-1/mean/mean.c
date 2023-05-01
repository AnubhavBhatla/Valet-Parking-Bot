#include <stdio.h>
#include "mean.h"

void reset(memory* self) {
    self->sum = 0;
    self->entries = 0;
}

void step(int x, out* _out, memory* self) {
    // update memory for the next step
    self->sum = self->sum + x;
    self->entries = self->entries + 1;
    _out->out = (self->sum / (float)self->entries);
}
