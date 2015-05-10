/* 
 * File:   rng.h
 * Author: dhovemey
 *
 * Created on May 10, 2015, 3:45 PM
 */

#ifndef RNG_H
#define	RNG_H

#include <cstdlib>

class RNG {
private:
    struct drand48_data m_state;
    
public:
    RNG();
    RNG(long seed);
    ~RNG();
    
    int next();
    int next(int n);
    
private:
    void init(long seed);
};

#endif	/* RNG_H */

