#include "area.h"

namespace {
    Terrain from_char(char c) {
        switch (c) {
            case '#': return ROCK;
            case '.': return FLOOR;
            case '|': return VWALL;
            case '-': return HWALL;
            case 'q': return ULWALL;
            case 'w': return URWALL;
            case 'a': return LLWALL;
            case 's': return LRWALL;
            default: return UNKNOWN;
        }
    }
}

Area::Area(int w, int h) : m_width(w), m_height(h), m_terrain(new Terrain[h*w]) {
    for (int i = 0; i < h*w; i++) {
        m_terrain[i] = ROCK;
    }
}

Area::~Area() {
    delete[] m_terrain;
}

Terrain Area::get_terrain(int x, int y) const {
    return m_terrain[index(x, y)];
}

void Area::set_terrain(int x, int y, Terrain t) {
    m_terrain[index(x,y)] = t;
}

Area *Area::from_data(const AreaData *ad) {
    Area *area = new Area(ad->width, ad->height);
    
    for (int j = 0; j < ad->height; j++) {
        for (int i = 0; i < ad->width; i++) {
            Terrain t = from_char(ad->data[j*ad->width + i]);
            area->set_terrain(i, j, t);
        }
    }
    
    return area;
}
