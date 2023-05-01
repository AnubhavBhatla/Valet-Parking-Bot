typedef struct memory {
    int sum;
    int square_sum;
    int entries;
} memory;

typedef struct out {
    float out;
} out;

void reset(memory* self);

void step(int x, out* _out, memory* self);
