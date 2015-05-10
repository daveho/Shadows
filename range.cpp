#include "rng.h"
#include "range.h"

Range::~Range() {
    
}

int Range::rand(RNG &rng) {
    return min + rng.next(size());
}
