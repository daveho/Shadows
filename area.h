/* 
 * File:   area.h
 * Author: dhovemey
 *
 * Created on April 25, 2015, 4:39 PM
 */

#ifndef AREA_H
#define	AREA_H

#include "terrain.h"
#include "grid.h"

struct AreaData {
    int width, height;
    const char *data;
};

class Area {
private:
    Grid<Terrain> *m_grid;
    
public:
    Area(int w, int h);
    virtual ~Area();
    
    int get_width() const { return m_grid->get_width(); }
    int get_height() const { return m_grid->get_height(); }
    
    Terrain get_terrain(const Pos &pos) const { return m_grid->get(pos); }
    void set_terrain(const Pos &pos, Terrain t) { m_grid->set(pos, t); }
    
    bool in_bounds(const Pos &pos) const {
        return m_grid->in_bounds(pos);
    }
    
    static Area *from_data(const AreaData *ad);
};

#endif	/* AREA_H */

