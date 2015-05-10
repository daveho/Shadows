#include "rng.h"
#include "area_editor.h"
#include "dungeon_gen.h"

namespace {
    const Range DEFAULT_ROOM_WIDTH_RANGE(5, 20);
    const Range DEFAULT_ROOM_HEIGHT_RANGE(5, 20);
    const int DEFAULT_ROOM_INSET = 4;
}

DungeonGenParams::DungeonGenParams()
    : room_width(DEFAULT_ROOM_WIDTH_RANGE)
    , room_height(DEFAULT_ROOM_HEIGHT_RANGE)
    , room_inset(DEFAULT_ROOM_INSET) {
}

DungeonGen::DungeonGen(RNG &rng, const DungeonGenParams &params)
    : m_rng(rng)
    , m_params(params) {
}

DungeonGen::~DungeonGen() {
}

void DungeonGen::generate(AreaEditor *area) {
    m_area = area;
    do_generate();
}

void DungeonGen::do_generate() {
    m_area->fill(ROCK);
    gen_corridors();
    gen_rooms();
}

void DungeonGen::gen_corridors() {
    int vmid = m_area->get_height() / 2, hmid = m_area->get_width() / 2;
    
    // Generate rectangular main corridor system
    Range top(m_params.room_inset + m_params.room_height.min/2, vmid - m_params.room_height.min/2);
    Range bottom(m_area->get_height() - top.max - 1, m_area->get_height() - top.min - 1);
    Range left(m_params.room_inset + m_params.room_width.min/2, hmid - m_params.room_width.min/2);
    Range right(m_area->get_width() - left.max - 1, m_area->get_width() - left.min - 1);
    
    int ctop = top.rand(m_rng);
    int cbottom = bottom.rand(m_rng);
    int cleft = left.rand(m_rng);
    int cright = right.rand(m_rng);
    
    m_area->hline(ctop, Range(cleft, cright+1), FLOOR);
    m_area->hline(cbottom, Range(cleft, cright+1), FLOOR);
    m_area->vline(cleft, Range(ctop, cbottom+1), FLOOR);
    m_area->vline(cright, Range(ctop, cbottom+1), FLOOR);
}

void DungeonGen::gen_rooms() {
    // TODO
}
