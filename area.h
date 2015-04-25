/* 
 * File:   area.h
 * Author: dhovemey
 *
 * Created on April 25, 2015, 4:39 PM
 */

#ifndef AREA_H
#define	AREA_H

#include "terrain.h"

struct AreaData {
    int width, height;
    const char *data;
};

class Area {
private:
    int m_width, m_height;
    Terrain *m_terrain;
    
    inline int index(int x, int y) const { return y*m_width + x; }
    
public:
    Area(int w, int h);
    virtual ~Area();
    
    Terrain get_terrain(int x, int y) const;
    void set_terrain(int x, int y, Terrain t);
    
    static Area *from_data(const AreaData *ad);
};

#endif	/* AREA_H */

