/* 
 * File:   game.h
 * Author: dhovemey
 *
 * Created on April 25, 2015, 6:32 PM
 */

#ifndef GAME_H
#define	GAME_H

class Area;
class Player;

class Game {
private:
    Area *m_area;
    Player *m_player;
    
public:
    Game(Area *area, Player *player);
    virtual ~Game();
    
    Area *get_area() { return m_area; }
    Player *get_player() { return m_player; }
};

#endif	/* GAME_H */

