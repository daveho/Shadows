/* 
 * File:   Character.h
 * Author: dhovemey
 *
 * Created on May 5, 2015, 4:15 PM
 */

#ifndef CHARACTER_H
#define	CHARACTER_H

#include "geom.h"

class Character {
private:
    Pos m_pos;
    
public:
    Character();
    Character(const Pos &pos);
    virtual ~Character();
    
    void move(Dir dir) { m_pos = m_pos.move(dir); }
    void set_pos(const Pos &pos) { m_pos = pos; }
    const Pos &get_pos() const { return m_pos; }
};

#endif	/* CHARACTER_H */

