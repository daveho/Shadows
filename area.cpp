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
            case 'o': return PILLAR;
            default: return UNKNOWN;
        }
    }
}

Area::Area(int w, int h) : m_grid(new Grid<Terrain>(w, h)) {
    
}

Area::~Area() {
    delete m_grid;
}

Area *Area::from_data(const AreaData *ad) {
    Area *area = new Area(ad->width, ad->height);
    
    for (int j = 0; j < ad->height; j++) {
        for (int i = 0; i < ad->width; i++) {
            Terrain t = from_char(ad->data[j*ad->width + i]);
            area->set_terrain(Pos(i, j), t);
        }
    }
    
    return area;
}
