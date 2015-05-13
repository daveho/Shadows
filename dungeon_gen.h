/* 
 * File:   dungeon_gen.h
 * Author: dhovemey
 *
 * Created on May 10, 2015, 3:30 PM
 */

#ifndef DUNGEON_GEN_H
#define	DUNGEON_GEN_H

#include <set>
#include "range.h"

class RNG;

struct DungeonGenParams {
    Range room_width;
    Range room_height;
    int room_inset;
    
    DungeonGenParams(); // Initializes with default settings
};

class DungeonGen {
private:    
    RNG &m_rng;
    const DungeonGenParams &m_params;
    AreaEditor *m_area;
    std::vector<Pos> m_room_seeds;
    
public:
    DungeonGen(RNG &rng, const DungeonGenParams &params);
    virtual ~DungeonGen();
    
    virtual void generate(AreaEditor *area);
    
private:
    void do_generate();
    void gen_corridors();
    void gen_rooms();
    void attempt_place_room(const Pos &seed);
};

#endif	/* DUNGEON_GEN_H */

