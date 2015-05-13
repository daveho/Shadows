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
    
    bool operator<(const Pos &rhs) const {
        if (x < rhs.x) {
            return true;
        } else if (x > rhs.x) {
            return false;
        } else {
            return y < rhs.y;
        }
    }
};

#if 0
struct Rect {
    Pos topleft;
    int width, height;
    Rect(const Pos &topleft_, int width_, int height_)
        : topleft(topleft_), width(width_), height(height_) { }
    
    bool contains(const Pos &pos) const {
        return pos.x >= topleft.x
                && pos.x < topleft.x + width
                && pos.y >= topleft.y
                && pos.y < topleft.y + height;
    }
};
#endif

#endif	/* GEOM_H */

