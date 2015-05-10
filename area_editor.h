/* 
 * File:   area_editor.h
 * Author: dhovemey
 *
 * Created on May 10, 2015, 4:33 PM
 */

#ifndef AREAEDITOR_H
#define	AREAEDITOR_H

#include "range.h"
#include "terrain.h"

class Area;

class AreaEditor {
private:
    Area *m_area;
    
public:
    AreaEditor(Area *area);
    virtual ~AreaEditor();
    
    int get_width();
    int get_height();
    
    void fill(Terrain t);
    void hline(int y, const Range &xrange, Terrain t);
    void vline(int x, const Range &yrange, Terrain t);
};

#endif	/* AREAEDITOR_H */

