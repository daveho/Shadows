#define DEBUG

#ifdef DEBUG
#  include <cstdio>
#  define debug_printf(args...) printf(args)
#else
#  define debug_printf(args...)
#endif
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
    m_area->t_fill(ROCK);
    gen_corridors();
    gen_rooms();
}

void DungeonGen::gen_corridors() {
    int vmid = m_area->get_height() / 2, hmid = m_area->get_width() / 2;
    
    // Generate rectangular main corridor system
    Range top(m_params.room_inset + m_params.room_height.min/2, vmid - m_params.room_height.min/2);
    Range bottom(m_area->get_height() - top.max, m_area->get_height() - top.min);
    Range left(m_params.room_inset + m_params.room_width.min/2, hmid - m_params.room_width.min/2);
    Range right(m_area->get_width() - left.max, m_area->get_width() - left.min);
    
    debug_printf("top: %i..%i\n", top.min, top.max);
    debug_printf("bottom: %i..%i\n", bottom.min, bottom.max);
    debug_printf("left: %i..%i\n", left.min, left.max);
    debug_printf("right: %i..%i\n", right.min, right.max);
    
    int ctop = top.rand(m_rng);
    int cbottom = bottom.rand(m_rng);
    int cleft = left.rand(m_rng);
    int cright = right.rand(m_rng);
    
    m_area->t_hline(ctop, Range(cleft, cright+1), FLOOR);
    m_area->t_hline(cbottom, Range(cleft, cright+1), FLOOR);
    m_area->t_vline(cleft, Range(ctop, cbottom+1), FLOOR);
    m_area->t_vline(cright, Range(ctop, cbottom+1), FLOOR);
    
    // Room locations are seeded from the set of cooridor tiles
    m_room_seeds = m_area->find_all(FLOOR);
}

void DungeonGen::gen_rooms() {
    int max_attempts = 100;
    int max_rooms = 20;
    
    int num_attempts = 0;
    while (num_attempts < max_attempts) {
        Pos seed = m_room_seeds.at(m_rng.next(int(m_room_seeds.size())));
        attempt_place_room(seed);
        num_attempts++;
    }
}

void DungeonGen::attempt_place_room(const Pos &seed) {
    // TODO
}
