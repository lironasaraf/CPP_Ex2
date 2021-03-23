#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;
using namespace ariel;


     
  
  ariel::Board board;

	

TEST_CASE("good empty board"){
	
CHECK(board.read(2, 0, Direction::Horizontal, 2) ==string("__"));
CHECK(board.read(2, 2, Direction::Vertical, 4) ==string("____"));

}

TEST_CASE("good spaces"){
	board.post(0,0,Direction::Horizontal,"  ");
	CHECK(board.read(0,0, Direction::Horizontal, 2) ==string("  "));

	board.post(0,0,Direction::Vertical,"   ");
	CHECK(board.read(0,0, Direction::Vertical, 3) ==string("   "));

}

TEST_CASE("good reading letters"){
	board.post(2,3,Direction::Horizontal,"Liron");
	CHECK(board.read(2,3,Direction::Horizontal,5)== string("Liron"));
	CHECK(board.read(2,3,Direction::Horizontal,4)== string("Liro"));
	CHECK(board.read(2,3,Direction::Horizontal,3)== string("Lir"));
	CHECK(board.read(2,3,Direction::Horizontal,2)== string("Li"));
	CHECK(board.read(2,3,Direction::Horizontal,1)== string("L"));
	board.post(2,2,Direction::Vertical,"Asaraf");
	CHECK(board.read(2,2,Direction::Vertical,6)== string("Asaraf"));
	CHECK(board.read(2,2,Direction::Vertical,5)== string("Asara"));
	CHECK(board.read(2,2,Direction::Vertical,4)== string("Asar"));
	CHECK(board.read(2,2,Direction::Vertical,3)== string("Asa"));
	CHECK(board.read(2,2,Direction::Vertical,2)== string("As"));
	CHECK(board.read(2,2,Direction::Vertical,1)== string("A"));

	board.post(23, 1, Direction::Vertical, "cpp");
	CHECK((board.read(23, 1, Direction::Horizontal, 2)) ==string("c"));

	board.post(11, 0, Direction::Vertical, "lironasa");
	CHECK((board.read(11, 0, Direction::Horizontal,2)) ==string("l"));

	board.post(10, 0, Direction::Horizontal, "lironasa");
	CHECK((board.read(7, 7, Direction::Vertical, 6)) ==string("a")); 


}
TEST_CASE("Good overloading"){
		board.post(100, 200, Direction::Horizontal, "abcd");
	CHECK((board.read(99, 201, Direction::Vertical, 3)) ==string("b"));  

	board.post(99, 202, Direction::Vertical, "xyz");
	CHECK((board.read(100, 200, Direction::Horizontal, 6)) =="abyd"); 
}