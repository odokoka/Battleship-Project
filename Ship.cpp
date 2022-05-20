/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Ship.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * Ojochilemi Okoka
 * okokaojo
 *
 * Project 4: Battleship
 *
 * The implimentations for the member functions in the Ship class
 */

#include <cmath>

#include "Ship.h"


Ship::Ship() {
    Position start;
    Position end;
    num_hits = 0;
    size = 0;
}

Ship::Ship(Position start_in, Position end_in) {
    start.set_row(start_in.get_row());
    start.set_col(start_in.get_col());
    
    end.set_row(end_in.get_row());
    end.set_col(end_in.get_col());
    
    if (is_horizontal()) {
        size = (abs(start.get_col() - end.get_col())) + 1;
    } else {
        size = (abs(start.get_row() - end.get_row())) + 1;
    }
    num_hits = 0;
}

Position Ship::get_start() {
    return start;
}

Position Ship::get_end() {
    return end;
}

int Ship::get_size() {
    return size;
}

bool Ship::is_horizontal() {
    if (start.get_row() == end.get_row()) {
        return true;
    } else {
    return false;
    }
}

bool Ship::has_position(Position pos) {
    bool validPosition = true;
    
    if (is_horizontal()) {
        if (pos.get_row() != start.get_row()) {
            validPosition = false;
        } else if (start.get_col() < end.get_col()) {
            if ((pos.get_col() < start.get_col() ||
                 pos.get_col() > end.get_col())) {
            validPosition = false;
            }
        } else {
            if (pos.get_col() < end.get_col() ||
                pos.get_col() > start.get_col()) {
                validPosition = false;
            }
        }
    }else if (!is_horizontal()) {
        if (pos.get_col() != start.get_col()) {
            validPosition = false;
        } else if (start.get_row() < end.get_row()) {
            if((pos.get_row() < start.get_row() ||
                pos.get_row() > end.get_row())) {
            validPosition = false;
            }
        } else {
                if (pos.get_row() < end.get_row() ||
                    pos.get_row() > start.get_row()) {
                    validPosition = false;
                }
            }
    }
    return validPosition;
}

void Ship::hit() {
    if (num_hits < size) {
        ++num_hits;
    }
    return;
}

bool Ship::has_sunk() {
    if (num_hits == size) {
        return true;
    } else {
    return false;
}
}
