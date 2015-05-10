#include <cstdio>
#include "rng.h"

RNG::RNG() {
    long seed = 123L;
    FILE *u = fopen("/dev/urandom", "rb");
    if (u) {
        if (fread(&seed, sizeof(long), 1, u) != 1) {
            // Couldn't read?
            seed = 123L;
        }
        fclose(u);
    }
    init(seed);
}

RNG::RNG(long seed) {
    init(seed);
}

RNG::~RNG() {
    
}

int RNG::next() {
    long result;
    lrand48_r(&m_state, &result);
    return int(result);
}

int RNG::next(int n) {
    return next() % n;
}

void RNG::init(long seed) {
    srand48_r(seed, &m_state);
}
