/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Player.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * Ojochilemi Okoka
 * okokaojo
 *
 * Project 4: Battleship
 *
 * The implementations for the member functions in the Player class
 */

#include <fstream>

#include "Player.h"


Player::Player() {
    name = "";
    num_ships = 0;
    remaining_ships = 0;
    init_grid();
}

Player::Player(string name_val) {
    name = name_val;
    num_ships = 0;
    remaining_ships = 0;
    init_grid();
}

void Player::init_grid() {
    
    for (int i = 0; i < MAX_GRID_SIZE; ++i) {
        for (int j = 0; j < MAX_GRID_SIZE; ++j) {
            grid[i][j] = EMPTY_LETTER;
        }
    }
    for (int i = 0; i < MAX_GRID_SIZE; ++i) {
        for (int j = 0; j < MAX_GRID_SIZE; ++j) {
            guess_grid[i][j] = EMPTY_LETTER;
        }
    }
    return;
}

string Player::get_name() {
    return name;
}

int Player::get_num_ships() {
    return num_ships;
}

int Player::get_remaining_ships() {
    return remaining_ships;
}

char Player::get_grid_at(int row, int col) {
    return grid[row][col];
}

char Player::get_guess_grid_at(int row, int col) {
    return guess_grid[row][col];
}

void Player::add_ship(Ship ship) {
    int shipStartRow = ship.get_start().get_row();
    int shipStartCol = ship.get_start().get_col();
    int shipEndRow = ship.get_end().get_row();
    int shipEndCol = ship.get_end().get_col();
    
    if (num_ships != MAX_NUM_SHIPS) {
        if (ship.is_horizontal()) {
            if (shipStartCol < shipEndCol) {
                for (int i = shipStartCol; i <= shipEndCol; ++i) {
                    grid[shipStartRow][i] = SHIP_LETTER;
                }
            } else {
                for (int i = shipStartCol; i >= shipEndCol; --i) {
                    grid[shipStartRow][i] = SHIP_LETTER;
                }
            }
        } else {
            if (shipStartRow < shipEndRow) {
                for (int i = shipStartRow; i <= shipEndRow; ++i) {
                    grid[i][shipStartCol] =  SHIP_LETTER;
                }
            } else {
                for (int i = shipStartRow; i >= shipEndRow; --i) {
                    grid[i][shipStartCol] = SHIP_LETTER;
                }
            }
        }
        ships[num_ships] = ship;
        ++num_ships;
        ++remaining_ships;
} else {
        return;
    }
}

void Player::attack(Player &opponent, Position pos) {
    int posRow = pos.get_row();
    int posCol = pos.get_col();
    int i;
    
    for (i = 0; i < opponent.num_ships; ++i) {
            if (opponent.ships[i].has_position(pos)) {
                if (opponent.grid[posRow][posCol] == SHIP_LETTER) {
                    opponent.ships[i].hit();
                    opponent.grid[posRow][posCol] = HIT_LETTER;
                    guess_grid[posRow][posCol] = HIT_LETTER;
                    cout << get_name() << " " << pos << " " << "hit" << endl;
                
                if (opponent.ships[i].has_sunk()) {
                    --opponent.remaining_ships;
                    announce_ship_sunk(opponent.ships[i].get_size());
                }
                return;
            }
        }
    }
        opponent.grid[posRow][posCol] = MISS_LETTER;
        guess_grid[posRow][posCol] = MISS_LETTER;
        cout << get_name() << " " << pos << " " << "miss" << endl;
    
        return;
}

void Player::announce_ship_sunk(int size) {
    if (size == 2) {
        cout << "Congratulations " << get_name() << "! You sunk a Destroyer"
        << endl;
    }
    if (size == 3) {
        cout << "Congratulations " << get_name() << "! You sunk a Submarine"
        << endl;
    }
    if (size == 4) {
        cout << "Congratulations " << get_name() << "! You sunk a Battleship"
        << endl;
    }
    if (size == 5) {
        cout << "Congratulations " << get_name() << "! You sunk a Carrier"
        << endl;
    }
    return;
}

bool Player::load_grid_file(string filename) {
    Position start;
    Position end;
    
    ifstream reader;
    
    reader.open(filename);
    if (reader.is_open()) {
        while (!reader.eof()) {
            reader >> start >> end;
            if (!reader.fail()) {
            Ship ship(start, end);
            add_ship(ship);
            }
        }
        return true;
    } else {
        return false;
    }
}

bool Player::destroyed() {
    if (get_remaining_ships() == 0) {
        return true;
    } else {
        return false;
    }
}

// Your code goes above this line.
// Don't change the implementations below!

void Player::print_grid() {
    ::print_grid(grid);
}

void Player::print_guess_grid() {
    ::print_grid(guess_grid);
}
