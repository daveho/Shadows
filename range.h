/* 
 * File:   range.h
 * Author: dhovemey
 *
 * Created on May 10, 2015, 4:06 PM
 */

#ifndef RANGE_H
#define	RANGE_H

class RNG;

// Range type: lower bound is inclusive, upper bound is exclusive
struct Range {
    int min, max;
    
    Range(int min_, int max_) : min(min_), max(max_) { }
    Range(const Range &other) : min(other.min), max(other.max) { }
    ~Range();
    
    int size() const { return max - min; }
    
    int rand(RNG &rng);
    
    Range& operator=(const Range &rhs) {
        if (this != &rhs) {
            min = rhs.min;
            max = rhs.max;
        }
        return *this;
    }
};

#endif	/* RANGE_H */

