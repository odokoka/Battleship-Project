/**
 * Copyright 2019 University of Michigan EECS183
 *
 * test.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * Project 4: Battleship
 *
 * Contains functions for testing classes in the project. 
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "Position.h"
#include "Ship.h"
#include "Player.h"
#include "Game.h"
#include "utility.h"

using namespace std;


void test_position();
void test_ship();
void test_player();
void test_game();

void startTests() {
    test_position();
    test_ship();
    test_player();
    test_game();
    
    return;
}

void test_position() {
    // testing Position default constructor here
    Position start_pos;
    Position end_pos;
    cout << "Testing Position::Position() - default constructor\n";
    cout << "start_pos, expected output: (1,A) actual output: " << start_pos
    << endl;
    cout << "end_pos, expected output: (1,A) actual output: " << end_pos
    << endl << endl;
    
    // testing Position second constructor here
    Position start_second(3, 5);
    Position end_second(-3, 6);
    cout << "Testing Position::Position() - second constructor\n";
    cout << "start_pos, expected output: (4,F) actual output: " << start_second
    << endl;
    cout << "end_pos, expected output: (1,G) actual output: " << end_second
    << endl << endl;
    
    // testing Position third constructor here
    Position start_third('4', 'F');
    Position end_third('1', 'g');
    cout << "Testing Position::Position() - third constructor\n";
    cout << "start_pos, expected output: (4,F) actual output: " << start_third
    << endl;
    cout << "end_pos, expected output: (1,G) actual output: " << end_third
    << endl;
    
    // testing Position setters here
    start_pos.set_row(4);
    start_pos.set_col(5);
    cout << "\nTesting Position::set_row() and Position::set_col()\n";
    cout << "start_pos, expected output: (5,F) actual output: " << start_pos
    << endl;
    
    // testing Position read
    ifstream input_file;
    input_file.open("grid1.txt");
    if (input_file.good()) {

    // can use the Position::read() function directly
    start_pos.read(input_file);

    // or use the extraction operator
    input_file >> end_pos;
        
        cout << "\nTesting Position::read()\n";
        cout << "start_pos, expected output: (8,B) actual output: " << start_pos
        << endl;
        cout << "end_pos, expected output: (8,C) actual output: " << end_pos
        << endl;
    }
    else {
        cout << "\nError opening grid1.txt\n";
    }
  
    return;
}

void test_ship() {
    
    Ship ussOkoka;
    
    Position startShip('3', 'B');
    Position endShip('5', 'B');
    Ship shipment(startShip, endShip);
    
    Position cargoStart(1, 4);
    Position cargoEnd(5, 4);
    Ship cargo(cargoStart, cargoEnd);
    Position attack1('1', 'E');
    
    //Testing default constructor
    cout << "Testing Ship::Ship() - default constructor\n";
    cout << "ussOkoka.get_start, expected output: (1,A) actual output: " <<
    ussOkoka.get_start() << endl;
    cout << "ussOkoka.get_end, expected output: (1,A) actual output: " <<
    ussOkoka.get_end() << endl;
    cout << "ussOkoka.get_size, expected output: 0, actual output: " <<
    ussOkoka.get_size() << endl << endl;
    
    //Testing non-default constructor
    cout << "Testing Ship::Ship() - non-default constructor\n";
    cout << "shipment.get_start, expected output: (3,B) actual output: " <<
    shipment.get_start() << endl;
    cout << "shipment.get_end, expected output: (5,B) actual output: " <<
    shipment.get_end() << endl;
    cout << "shipment.get_size, expected output: 3, actual output: " <<
    shipment.get_size() << endl;
    cout << "cargo.is_horizontal expected output: 0, actual output: " <<
    cargo.is_horizontal() << endl << endl;
    
    //Testing Ship::has_position function
    cout << "\nTesting Ship::has_position()\n";

    cout << "cargo.has_position, expected output: 0 actual output: " <<
    cargo.has_position(attack1) << endl << endl;
   
    Position attack2(1, 4);
    cout << "cargo.has_position, expected output: 1 actual output: " <<
    cargo.has_position(attack2) << endl << endl;
    
    Position attack3(2, 4);
    cout << "cargo.has_position, expected output: 1 actual output: " <<
    cargo.has_position(attack3) << endl << endl;
    
    Position attack4(3, 4);
    cout << "cargo.has_position, expected output: 1 actual output: " <<
    cargo.has_position(attack4) << endl << endl;
    
    Position attack5(4, 6);
    cout << "cargo.has_position, expected output: 0 actual output: " <<
    cargo.has_position(attack5) << endl << endl;
    
    Position attack6(5, 3);
    cout << "cargo.has_position, expected output: 0 actual output: " <<
    cargo.has_position(attack6) << endl << endl;
    
    Position attack7(1, 0);
    cout << "cargo.has_position, expected output: 0 actual output: " <<
    cargo.has_position(attack7) << endl << endl;
    
    //Testing Ship::hit() function
    cout << "\nTesting Ship::hit()\n";
    
    shipment.hit();
    cout << "Expected 0, Actual: " << shipment.has_sunk() << endl;
    shipment.hit();
    shipment.hit();
    cout << "Expected 1, Actual: " << shipment.has_sunk() << endl;
    shipment.hit();
    
        
    
    return;
}

void test_player() {
    
    //Testing default constructor:
    Player headGanger;
    
    cout << "\nTesting Player::Player()\n";
    cout << endl;
    cout << "Expected: "", Actual: ";
    cout << headGanger.get_name() << endl;
    cout << "Expected: 0, Actual: ";
    cout << headGanger.get_num_ships() << endl;
    cout << "Expected: 0, Actual: ";
    cout << headGanger.get_remaining_ships() << endl;
    cout << "Expected: Two all blank grid, Actual: " << endl;
    headGanger.print_grid();
    headGanger.print_guess_grid();
    
    //Testing non-default constructor:
    Player viceGanger("Ocho Cinco");
    
    cout << "\nTesting Player::Player(string name_val)\n";
    cout << endl;
    cout << "Expected: Ocho Cinco, Actual: ";
    cout << viceGanger.get_name() << endl;
    cout << "Expected: 0, Actual: ";
    cout << viceGanger.get_num_ships() << endl;
    cout << "Expected: 0, Actual: ";
    cout << viceGanger.get_remaining_ships() << endl;
    cout << "Expected: Two all blank grid, Actual: " << endl;
    viceGanger.print_grid();
    viceGanger.print_guess_grid();
    
    //Testing Player::add_ship:
    cout << endl;
    Position startTestShip(5, 4);
    Position endTestShip(5, 6);
    Ship testShip(startTestShip, endTestShip);
    Player testPlayer;
    
    cout << "\nTesting Player::add_ship(Ship ship)\n";
    testPlayer.add_ship(testShip);
    cout << endl;
    testPlayer.print_grid();
    cout << endl << endl;
    
    Position startTestShip2(5, 6);
    Position endTestShip2(5, 4);
    Ship testShip2(startTestShip2, endTestShip2);
    Player testPlayer2 ("Player 2");
    testPlayer2.add_ship(testShip2);
    cout << endl;
    testPlayer2.print_grid();
    cout << endl << endl;
    
    Position startTestShip3(4, 5);
    Position endTestShip3(6, 5);
    Ship testShip3(startTestShip3, endTestShip3);
    Player testPlayer3 ("Player 3");
    testPlayer3.add_ship(testShip3);
    cout << endl;
    testPlayer3.print_grid();
    cout << endl << endl;
    
    //Testing Ship::hit()
    Position startTestShip4(4, 5);
    Position endTestShip4(5, 5);
    Ship testShip4(startTestShip4, endTestShip4);
    cout << "\nTesting Ship::hit()\n";
    testShip4.hit();
    cout << "Expected 0, Actual: " << testShip4.has_sunk() << endl;
    testShip4.hit();
    cout << "Expected 1, Actual: " << testShip4.has_sunk() << endl;
    testShip4.hit();
    cout << "Expected 1, Actual: " << testShip4.has_sunk() << endl;
    

    
    //Testing Player::attack
    cout << "\nTesting Player::attack(Pos)\n";
    cout << endl;
    Position strike(5, 5);
    Position strike2(4, 5);
    Position strike3(6, 5);
    testPlayer2.print_grid();
    testPlayer3.print_guess_grid();
    
    cout << endl;
    cout << "Expected 1" << endl;
    cout << testPlayer3.get_num_ships() << endl;
    cout << "Expected 1" << endl;
    cout << testPlayer3.get_remaining_ships() << endl;
    cout << "Expected *" << endl;
    cout << testPlayer3.get_grid_at(5, 5) << endl;
    
    testPlayer2.attack(testPlayer3, strike);
    cout << "Expected *" << endl;
    cout << testPlayer2.get_grid_at(5, 5) << endl;
    cout << "Expected O" << endl;
    cout << testPlayer2.get_guess_grid_at(5, 5) << endl;
    cout << "Expected 1" << endl;
    cout << testPlayer3.get_num_ships() << endl;
    cout << "Expected 1" << endl;
    cout << testPlayer3.get_remaining_ships() << endl;
    cout << endl;
    testPlayer2.attack(testPlayer3, strike2);
    cout << "Expected -" << endl;
    cout << testPlayer2.get_grid_at(4, 5) << endl;
    cout << "Expected O" << endl;
    cout << testPlayer2.get_guess_grid_at(4, 5) << endl;
    cout << "Expected 1" << endl;
    cout << testPlayer3.get_num_ships() << endl;
    cout << "Expected 1" << endl;
    cout << testPlayer3.get_remaining_ships() << endl;
    testPlayer2.attack(testPlayer3, strike3);
    cout << "Expected -" << endl;
    cout << testPlayer2.get_grid_at(6, 5) << endl;
    cout << "Expected O" << endl;
    cout << testPlayer2.get_guess_grid_at(6, 5) << endl;
    cout << "Expected 1" << endl;
    cout << testPlayer3.get_num_ships() << endl;
    cout << "Expected 0" << endl;
    cout << testPlayer3.get_remaining_ships() << endl;
    testPlayer2.print_guess_grid();
    
    
    //Testing Player::load_grid
    cout << "\nTesting Player::load_grid(filename)\n";
    Player testPlayer4;
    cout << "Expected: 1, Actual: " << endl;
    cout << testPlayer4.load_grid_file("grid1.txt") << endl;
    cout << endl << endl;
    testPlayer4.print_grid();
    cout << endl << endl;
    Player testPlayer5;
    cout << "Expected: 1, Actual: " << testPlayer5.load_grid_file("grid2.txt");
    cout << endl << endl;
    //Extraneous test case for add_ship
    testPlayer5.add_ship(testShip);
    testPlayer5.print_grid();
    
    
    return;
}
void test_game() {
    
    cout << "\nTesting Game::Game\n";
    
    Player p1("Ojo");
    Player p2("Tylan");
    Player p3("Vivi");
    Player p4("Big Dog");
    Player p5("Mom");
    Player p6("Dad");
    
    //Game Constructors with variations
    Game origin;
    Game testGame1(p1, "grid1.txt", p2, "grid2.txt");
    Game testGame2(p3, "", p4, "");
    Game testGame3(p5, "grid1.txt", p6, "");
    
    p1.print_grid();
    p2.print_grid();
    p3.print_grid();
    p4.print_grid();
    p5.print_grid();
    p6.print_grid();
    
    
    //Getters
    cout << "Testing get_move, Expected 3D, Actual: " <<
    testGame1.get_move(p1.get_name()) << endl;
    cout << "Testing get_move, Expected 5B, Actual: " <<
    testGame1.get_move(p2.get_name()) << endl;
    
    //Check_Valid_Move
    cout << "Testing check_valid_position, Expected 1, Actual: " << endl;
    cout << testGame1.check_valid_move("1B") << endl;
    cout << "Testing check_valid_position, Expected 0, Actual: " << endl;
    cout << testGame1.check_valid_move("6I") << endl;
    cout << "Testing check_valid_position, Expected 0, Actual: " << endl;
    cout << testGame1.check_valid_move("9G") << endl;
    cout << "Testing check_valid_position, Expected 1, Actual: " << endl;
    cout << testGame1.check_valid_move("3B") << endl;
    
    return;
}
