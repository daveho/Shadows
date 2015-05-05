/* 
 * File:   player.h
 * Author: dhovemey
 *
 * Created on April 25, 2015, 6:32 PM
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include "character.h"

class Player : public Character {
public:
    Player();
    Player(const Pos &pos);
    virtual ~Player();
};

#endif	/* PLAYER_H */

