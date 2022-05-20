/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Position.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * Ojochilemi Okoka
 * okokaojo
 *
 * Project 4: Battleship
 *
 * The impleemntations for the member functions in the Position class
 */

#include "Position.h"
#include "utility.h"


Position::Position() {
    set_row(check_range(0));
    set_col(check_range(0));
}

Position::Position(int row_in, int col_in) {
    set_row(check_range(row_in));
    set_col(check_range(col_in));
}

Position::Position(char row_in, char col_in) {
    int newRow = (row_in - '0') - 1;
    set_row(check_range(newRow));
    
    int newCol = (toupper(col_in) - 'A');
    set_col(check_range(newCol));
}

int Position::get_row() {
    return row;
}

void Position::set_row(int row_in) {
    row = check_range(row_in);
    return;
}

int Position::get_col() {
    return col;
}

void Position::set_col(int col_in) {
    col = check_range(col_in);
    
    return;
}

void Position::read(istream &is) {
    char temp;
    int num;
    char letter;
    
    is >> num;
    
    if (is.fail()) {
        is.clear();
        
        is >> temp >> num >> temp >> letter >> temp;
        
    } else {
        row = num;
        is >> letter;
        col = letter;
    }
    
    row = check_range(num - 1);
    letter = toupper(letter);
    col = check_range(letter - 'A');
    
    return;
}

void Position::write(ostream &os) {
    char colLetter = col + 'A';
    int newRow = row + 1;
    os << "(" << newRow << "," << colLetter << ")";
    
    return;
}

int Position::check_range(int val) {
    if (val < 0) {
        val = 0;
    } else if (val > MAX_GRID_SIZE - 1) {
        val = MAX_GRID_SIZE - 1;
    }
    return val;
}


// Your code goes above this line.
// Don't change the implementations below!

istream &operator>>(istream &is,  Position &pos) {
    pos.read(is);
    return is;
}

ostream &operator<<(ostream &os, Position pos) {
    pos.write(os);
    return os;
}

