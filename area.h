/* 
 * File:   area.h
 * Author: dhovemey
 *
 * Created on April 25, 2015, 4:39 PM
 */

#ifndef AREA_H
#define	AREA_H

#include "terrain.h"
#include "geom.h"

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
    
    int get_width() const { return m_width; }
    int get_height() const { return m_height; }
    
    Terrain get_terrain(int x, int y) const;
    void set_terrain(int x, int y, Terrain t);
    Terrain get_terrain(const Pos &pos) const { return get_terrain(pos.x, pos.y); }
    void set_terrain(const Pos &pos, Terrain t) { set_terrain(pos.x, pos.y, t); }
    
    bool in_bounds(const Pos &pos) const {
        return pos.x >= 0 && pos.y >= 0 && pos.x < m_width && pos.y < m_height;
    }
    
    static Area *from_data(const AreaData *ad);
};

#endif	/* AREA_H */

