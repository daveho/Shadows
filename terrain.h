/* 
 * File:   terrain.h
 * Author: dhovemey
 *
 * Created on April 25, 2015, 4:24 PM
 */

#ifndef TERRAIN_H
#define	TERRAIN_H

enum Terrain {
    // opaque. solid
    ROCK = 0,
#define TERRAIN_OS_START ROCK
    VWALL,
    HWALL,
    ULWALL, // upper left corner
    URWALL, // upper right corner
    LLWALL, // lower left corner
    LRWALL, // lower right corner
    
    // opaque, permeable
    VWALL_SECRET,
#define TERRAIN_OP_START VWALL_SECRET
    HWALL_SECRET,
    
    // transparent, solid
    PILLAR,
#define TERRAIN_TS_START PILLAR
    
    // transparent, permeable
    FLOOR,
#define TERRAIN_TP_START FLOOR
    
    UNKNOWN, // this should always be last
};

inline bool is_opaque(Terrain t) {
    return t < TERRAIN_TS_START;
}

inline bool is_solid(Terrain t) {
    return t < TERRAIN_OP_START || (t >= TERRAIN_TS_START && t < TERRAIN_TP_START);
}

#endif	/* TERRAIN_H */

