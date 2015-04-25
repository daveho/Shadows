/* 
 * File:   player.h
 * Author: dhovemey
 *
 * Created on April 25, 2015, 6:32 PM
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include "geom.h"

class Player {
private:
    Pos m_pos;
    
public:
    Player();
    Player(const Pos &pos);
    virtual ~Player();
    
    void move(Dir dir) { m_pos = m_pos.move(dir); }
    void set_pos(const Pos &pos) { m_pos = pos; }
    const Pos &get_pos() const { return m_pos; }
};

#endif	/* PLAYER_H */

