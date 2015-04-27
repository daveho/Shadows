#include <ncurses.h>

#include "area.h"
#include "player.h"
#include "game.h"
#include "fov.h"
#include "grid.h"

namespace {
    AreaData demo_area = {
        40, 20,
        "q------w###################q---------w##"
        "|......|###################|.........|##"
        "|....................................|##"
        "|......|##########.########|.........|##"
        "|......|##########.########a-w.....q-s##"
        "a-.----s##########.##########|.....|####"
        "##.###############.##########|.....|####"
        "##.###############.########q-s.....a-w##"
        "##.###############.########|.........|##"
        "##.................########|.o.....o.|##"
        "#######.###################|.........|##"
        "#######.###################|.o.....o.|##"
        "#######.###################|.........|##"
        "#######.###################|.o.....o.|##"
        "##q----.-w######q------w###|.........|##"
        "##|......|######|......|###|.o.....o.|##"
        "##|......|######|......|###|.........|##"
        "##|..........................o.....o.|##"
        "##|......|######|......|###|.........|##"
        "##a------s######a------s###q---------w##"
    };
}

int to_glyph(Terrain t) {
    switch (t) {
        case ROCK:
            return '#';
        case VWALL:
            return '|';
        case HWALL:
            return '-';
        case ULWALL:
        case URWALL:
        case LLWALL:
        case LRWALL:
            return '+';
        case VWALL_SECRET:
            return '|';
        case HWALL_SECRET:
            return '-';
        case PILLAR:
            return 'o';
        case FLOOR:
            return '.';
        case UNKNOWN:
        default: return '?';
    }
}

// FOV callbacks

struct FOV {
    Game *game;
    fov_settings_type *fs;
    Grid<bool> *vis;
    
    FOV(Game *g)
        : game(g)
        , fs(new fov_settings_type)
        , vis(new Grid<bool>(g->get_area()->get_width(), g->get_area()->get_height()))
    { }
    
    ~FOV() {
        delete fs;
        delete vis;
    }
};

bool test_opacity(void *map, int x, int y) {
    FOV *fov = static_cast<FOV *>(map);
    Game *g = fov->game;
    Area *a = g->get_area();
    if (!a->in_bounds(Pos(x, y))) {
        // out of bounds tiles are considered opaque
        return true;
    }
    Terrain t = g->get_area()->get_terrain(Pos(x, y));
    return is_opaque(t);
}

void apply_lighting(void *map, int x, int y, int dx, int dy, void *src) {
    FOV *fov = static_cast<FOV *>(map);
    fov->vis->set(Pos(x, y), true);
}

void show(FOV *f) {
    Game *g = f->game;
    
    f->vis->fill(false); // clear visibility
    Pos ppos = g->get_player()->get_pos();
    fov_circle(f->fs, f, 0, ppos.x, ppos.y, 10); // compute visibility
    
    erase();
    Area *a = g->get_area();
    for (int j = 0; j < a->get_height(); j++) {
        for (int i = 0; i < a->get_width(); i++) {
            if (f->vis->get(Pos(i, j))) {
                move(j, i);
                printw("%c", to_glyph(a->get_terrain(Pos(i, j))));
            }
        }
    }
    move(ppos.y, ppos.x);
    printw("@");
    move(a->get_height(), 0);
    refresh();
}

int main(int argc, char** argv) {
    printf("Hello, world\n");
    
    Game *g = new Game(Area::from_data(&demo_area), new Player());
    Area *a = g->get_area();
    Player *p = g->get_player();
    p->set_pos(Pos(5, 18));
    
    FOV *fov = new FOV(g);
    
    fov_settings_init(fov->fs);
    fov_settings_set_opacity_test_function(fov->fs, &test_opacity);
    fov_settings_set_apply_lighting_function(fov->fs, &apply_lighting);
    
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    
    bool done = false;
    while (!done) {
        show(fov);
        int c = getch();
        Pos next = p->get_pos();
        switch (c) {
            case KEY_UP:
                next = next.move(UP); break;
            case KEY_RIGHT:
                next = next.move(RIGHT); break;
            case KEY_DOWN:
                next = next.move(DOWN); break;
            case KEY_LEFT:
                next = next.move(LEFT); break;
            case 'q':
                done = true; break;
        }
        if (a->in_bounds(next) && !is_solid(a->get_terrain(next))) {
            p->set_pos(next);
        }
    }
    
    endwin();

    return 0;
}

