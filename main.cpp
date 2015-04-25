#include <ncurses.h>

#include "area.h"
#include "player.h"
#include "game.h"

namespace {
    AreaData demo_area = {
        20, 20,
        "q------w############"
        "|......|############"
        "|......|############"
        "|......|############"
        "|......|############"
        "a-.----s############"
        "##.#################"
        "##.#################"
        "##.#################"
        "##............######"
        "#######.############"
        "#######.############"
        "#######.############"
        "#######.############"
        "##q----.-w##########"
        "##|......|##########"
        "##|......|##########"
        "##|......|##########"
        "##|......|##########"
        "##a------s##########"
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

void show(Game *g) {
    erase();
    Area *a = g->get_area();
    Player *p = g->get_player();
    for (int j = 0; j < a->get_height(); j++) {
        for (int i = 0; i < a->get_width(); i++) {
            move(j, i);
            printw("%c", to_glyph(a->get_terrain(i, j)));
        }
    }
    Pos ppos = p->get_pos();
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
    
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    
    bool done = false;
    while (!done) {
        show(g);
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

