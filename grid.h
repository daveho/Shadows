/* 
 * File:   grid.h
 * Author: dhovemey
 *
 * Created on April 26, 2015, 9:00 AM
 */

#ifndef GRID_H
#define	GRID_H

#include "geom.h"

template<class T>
class Grid {
private:
    int m_width, m_height;
    T *m_data;

    inline int index(const Pos &pos) const { return pos.y*m_width + pos.x; }
        
public:
    Grid(int w, int h) :m_width(w), m_height(h), m_data(new T[w*h]) { }
    ~Grid() { delete[] m_data; }
    
    void fill(const T &value) {
        for (int i = 0; i < m_width*m_height; i++) {
            m_data[i] = value;
        }
    }
    
    int get_width() const { return m_width; }
    int get_height() const { return m_height; }
    
    T get(const Pos &pos) const { return m_data[index(pos)]; }
    void set(const Pos &pos, const T &value) { m_data[index(pos)] = value; }
    
    bool in_bounds(const Pos &pos) const {
        return pos.x >= 0 && pos.y >= 0 && pos.x < m_width && pos.y < m_height;
    }
};

#endif	/* GRID_H */

