#include "area.h"
#include "area_editor.h"

AreaEditor::AreaEditor(Area *area) : m_area(area) {
    
}

AreaEditor::~AreaEditor() {
    
}

int AreaEditor::get_width() {
    return m_area->get_width();
}

int AreaEditor::get_height() {
    return m_area->get_height();
}

void AreaEditor::t_fill(Terrain t) {
    for (int j = 0; j < m_area->get_height(); j++) {
        t_hline(j, Range(0, m_area->get_width()), t);
    }
}

void AreaEditor::t_hline(int y, const Range &xrange, Terrain t) {
    for (int i = xrange.min; i < xrange.max; i++) {
        m_area->set_terrain(Pos(i, y), t);
    }
}

void AreaEditor::t_vline(int x, const Range &yrange, Terrain t) {
    for (int j = yrange.min; j < yrange.max; j++) {
        m_area->set_terrain(Pos(x, j), t);
    }
}

std::vector<Pos> AreaEditor::find_all(Terrain t) const {
    std::vector<Pos> result;
    
    for (int j = 0; j < m_area->get_height(); j++) {
        for (int i = 0; i < m_area->get_width(); i++) {
            Pos pos(i, j);
            if (m_area->get_terrain(pos) == t) {
                result.push_back(pos);
            }
        }
    }
    
    return result;
}
