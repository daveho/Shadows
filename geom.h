/* 
 * File:   geom.h
 * Author: dhovemey
 *
 * Created on April 25, 2015, 6:33 PM
 */

#ifndef GEOM_H
#define	GEOM_H

#include <cassert>

enum Dir {
    UP,
    UP_RIGHT,
    RIGHT,
    DOWN_RIGHT,
    DOWN,
    DOWN_LEFT,
    LEFT,
    UP_LEFT,
};

struct Pos {
    int x, y;
    Pos(int x_, int y_) : x(x_), y(y_) { }
    Pos move(Dir dir) const {
        switch (dir) {
            case UP:
                return Pos(x, y - 1);
            case UP_RIGHT:
                return Pos(x + 1, y - 1);
            case RIGHT:
                return Pos(x + 1, y);
            case DOWN_RIGHT:
                return Pos(x + 1, y + 1);
            case DOWN:
                return Pos(x, y + 1);
            case DOWN_LEFT:
                return Pos(x - 1, y + 1);
            case LEFT:
                return Pos(x - 1, y);
            case UP_LEFT:
                return Pos(x - 1, y - 1);
            default:
                assert(false);
                return *this;
        }
    }
};

#endif	/* GEOM_H */

