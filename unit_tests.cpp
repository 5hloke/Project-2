#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE

#include "catch.hpp"
#include "TuringMachine.hpp"

//Your tests go here.

// Tests for the Default tape Constructor Implciptly tests getIndex() and getsize() 
TEST_CASE("Testing the Default Constructor", "Tape.cpp")
{
//	std::vector<std::string> v = { "1", "2", "3", "4" };
	Tape t;
	//std::cout << t.getIndex() << std::endl;
	REQUIRE(t.getIndex() == -1);
	REQUIRE(t.getSize() == 0);
	//REQUIRE(!(t.moveLeft()));
}

//Testing the Parameterized Constructor 
TEST_CASE("Testing the Parameterized constructor in Tape.cpp", "Tape.cpp")
{
	std::vector<std::string> v = { "1", "2", "3", "4" };
	Tape t(v);
	REQUIRE(t.getIndex() == 0);
	REQUIRE(t.getSize() == 4);
	REQUIRE_FALSE(t.moveLeft());
	REQUIRE(t.moveRight());
	REQUIRE(t.readSymbol() == "2");
	REQUIRE(t.moveLeft());
	REQUIRE(t.readSymbol() == "1");
}

//Testing the copy contructor (Implcitly tests the move left/right functions, read symbols functions)
//Also Implictly tests the getIndex and the getSize function
TEST_CASE("Testing the copy constructor from Tape.cpp class", "Tape.cpp")
{
	std::vector<std::string> v = { "1", "2", "3", "4" };
	Tape t(v);
	Tape t1(t);
	REQUIRE(t1.getIndex() == 0);
	REQUIRE(t1.getSize() == 4);
	REQUIRE_FALSE(t1.moveLeft());
	REQUIRE(t1.moveRight());
	REQUIRE(t1.readSymbol() == "2");
	REQUIRE(t1.moveLeft());
	REQUIRE(t1.readSymbol() == "1");
	t1.moveRight();
	t1.moveRight();
	REQUIRE(t1.readSymbol() == "3");
	t1.moveRight();
	REQUIRE(t1.readSymbol() == "4");
	REQUIRE(t1.getIndex() == 3);


}

// testing the tape destructor/clear method 
TEST_CASE("Testing the destructor/clear method in tape.cpp", "Tape.cpp")
{
	std::vector<std::string> v = { "1", "2", "3", "4" };
	Tape t(v);
	REQUIRE(t.getIndex() == 0);
	REQUIRE(t.getSize() == 4);
	t.clear(); // The tape has been cleared 
	REQUIRE(t.getIndex() == -1);
	REQUIRE(t.getSize() == 0);

}

// testing the get size function and the get index function
TEST_CASE("Testing the get size function", "Tape.cpp")
{
	Tape t;
	REQUIRE(t.getIndex() == -1);
	REQUIRE(t.getSize() == 0);
	std::vector<std::string> v = { "1", "2", "3", "4" };
	Tape t1(v);
	REQUIRE(t1.getIndex() == 0);
	REQUIRE(t1.getSize() == 4);
}

// testing the setTape method in the tape.cpp class
TEST_CASE("Testing the setTape method in the tape.cpp class", "Tape.cpp")
{
	Tape t;
	REQUIRE(t.getIndex() == -1);
	REQUIRE(t.getSize() == 0);
	std::vector<std::string> v = { "1", "2", "3", "4" };
	Tape t1(v);
	REQUIRE(t1.getIndex() == 0);
	REQUIRE(t1.getSize() == 4);
	t.setTape(t1);
	REQUIRE(t.getIndex() == 0);
	REQUIRE(t.getSize() == 4);
	REQUIRE(t.readSymbol() == "1");
	REQUIRE(t.getIndex() == 0);
	REQUIRE(t.moveRight());
	REQUIRE(t.readSymbol() == "2");
	REQUIRE(t.getIndex() == 1);
	REQUIRE(t.moveRight());
	REQUIRE(t.readSymbol() == "3");
	REQUIRE(t.getIndex() == 2);
	REQUIRE(t.moveRight());
	REQUIRE(t.readSymbol() == "4");
	REQUIRE(t.getIndex() == 3);
	REQUIRE(!t.moveRight());
	REQUIRE(t.getIndex() == 3);
	t1.clear();
	t.setTape(t1);
	REQUIRE(t.getSize() == 0);
	REQUIRE(t.getIndex() == -1);

}

// Testing the iEmpty() method from the Tape.cpp class
TEST_CASE("Testing the isEmpty method from the Tape.cpp method", "Tape.cpp")
{
	Tape t;
	REQUIRE(t.getIndex() == -1);
	REQUIRE(t.getSize() == 0);
	REQUIRE(t.isEmpty());

	std::vector<std::string> v = { "1", "2", "3", "4" };
	Tape t1(v);
	REQUIRE(t1.getIndex() == 0);
	REQUIRE(t1.getSize() == 4);
	REQUIRE_FALSE(t1.isEmpty());
	t1.clear();
	REQUIRE(t1.isEmpty());
}

// Testing the moveRight()/moveLeft() methods from Tape.cpp 
TEST_CASE("Testing the moveRight()/moveLeft() methods in the Tape.cpp class", "Tape.cpp")
{
	Tape t;
	REQUIRE(t.getIndex() == -1);
	REQUIRE(t.getSize() == 0);
	REQUIRE(!t.moveLeft());
	REQUIRE(!t.moveRight());
	std::vector<std::string> v = { "1", "2", "3", "4" };
	Tape t1(v);
	REQUIRE(t1.getIndex() == 0);
	REQUIRE(t1.getSize() == 4);
	REQUIRE(!t1.moveLeft());
	REQUIRE(t1.getIndex() == 0);
	REQUIRE(t1.moveRight());
	REQUIRE(t1.getIndex() == 1);
	REQUIRE(t1.moveRight());
	REQUIRE(t1.getIndex() == 2);
	REQUIRE(t1.moveRight());
	REQUIRE(t1.getIndex() == 3);
	REQUIRE(!t1.moveRight());
	REQUIRE(t1.getIndex() == 3);
	REQUIRE(t1.moveLeft());
	REQUIRE(t1.getIndex() == 2);
	REQUIRE(t1.moveLeft());
	REQUIRE(t1.getIndex() == 1);
	REQUIRE(t1.moveLeft());
	REQUIRE(t1.getIndex() == 0);
	REQUIRE(!t1.moveLeft());
	REQUIRE(t1.getIndex() == 0);

}

// Testing the writeBlank method in the Tape.cpp class, implicitly tests the readSymbol
TEST_CASE("Testing the writeBlank method in the Tape.cpp class", "Tape.cpp")
{
	std::vector<std::string> v = { "1", "2", "3", "4" };
	Tape t1(v);
	REQUIRE(t1.getIndex() == 0);
	REQUIRE(t1.getSize() == 4);
	t1.writeBlank();
	REQUIRE(t1.readSymbol() == " ");
	t1.moveRight();
	REQUIRE(t1.writeBlank());
	REQUIRE(t1.readSymbol() == " ");
}

// Testing the writeSymbol method in the Tape.cpp class, implicitly tests the readSymbol
TEST_CASE("Testing the writeSymbol method in the Tape.cpp class", "Tape.cpp")
{
	std::vector<std::string> v = { "1", "2", "3", "4" };
	Tape t1(v);
	REQUIRE(t1.getIndex() == 0);
	REQUIRE(t1.getSize() == 4);
	t1.writeSymbol("a");
	REQUIRE(t1.readSymbol() == "a");
	t1.moveRight();
	REQUIRE(t1.writeSymbol("a"));
	REQUIRE(t1.readSymbol() == "a");
}

// Testing the rewind Method in the Tape.cpp class
TEST_CASE("Testing the rewind method", "Tapw.cpp")
{
	std::vector<std::string> v = { "1", "2", "3", "4" };
	Tape t1(v);
	REQUIRE(t1.getIndex() == 0);
	REQUIRE(t1.getSize() == 4);
	t1.moveRight();
	t1.moveRight();
	t1.moveRight();
	REQUIRE(t1.getIndex() == 3);
	t1.rewind();
	REQUIRE(t1.getIndex() == 0);

}

// Testing the Default constructor in the TuringMachine class
TEST_CASE("Testing the default contstructor in the TuringMachine class", "TuringMachine.cpp")
{
	TuringMachine t;
	Tape tape(t.getTape());
	REQUIRE(tape.isEmpty());
	REQUIRE(tape.getIndex() == -1);
	REQUIRE(tape.getSize() == 0);
}

// Testing the Parameterized contructor for the TuringMachine class, implcitly tests
// setup check, and getTape 
TEST_CASE("Testing the parameterized constructor in the TuringMachine class", "TuringMachine.cpp")
{
	TuringMachine t;
	Tape tape(t.getTape());
	REQUIRE(tape.isEmpty());
	REQUIRE(tape.getIndex() == -1);
	REQUIRE(tape.getSize() == 0);
	std::vector<std::string> v = { "1", "2", "3", "4" };
	Tape t1(v);
	std::vector<std::string> s = { "a","b","c" };

	TuringMachine machine(t1, s);
	tape.setTape(machine.getTape());
	REQUIRE(machine.setupCheck());
	REQUIRE(tape.readSymbol() == t1.readSymbol());
	tape.moveRight();
	t1.moveRight();
	REQUIRE(tape.readSymbol() == t1.readSymbol());
	tape.moveRight();
	t1.moveRight();
	REQUIRE(tape.readSymbol() == t1.readSymbol());
	tape.moveRight();
	t1.moveRight();
	REQUIRE(tape.readSymbol() == t1.readSymbol());


}

// Testing the getSymbols method 
TEST_CASE("Testing the getSymbol Method", "TuringMachine.cpp")
{
	std::vector<std::string> v = { "1", "2", "3", "4" };
	Tape t1(v);
	std::vector<std::string> s = { "a","b","c" };

	TuringMachine machine(t1, s);

	REQUIRE(s == machine.getSymbols());
}

//Testing setSymbols and setTape
TEST_CASE("Testing setSymbols and setTape", "TuringMachine.cpp")
{
	TuringMachine t;
	std::vector<std::string> v = { "1", "2", "3", "4" };
	Tape t1(v);
	std::vector<std::string> s = { "a","b","c" };
	t.setTape(t1);
	t.setSymbols(s);
	Tape tape(t.getTape());
	REQUIRE(t.setupCheck());
	REQUIRE(tape.readSymbol() == t1.readSymbol());
	tape.moveRight();
	t1.moveRight();
	REQUIRE(tape.readSymbol() == t1.readSymbol());
	tape.moveRight();
	t1.moveRight();
	REQUIRE(tape.readSymbol() == t1.readSymbol());
	tape.moveRight();
	t1.moveRight();
	REQUIRE(tape.readSymbol() == t1.readSymbol());

	REQUIRE(t.getSymbols() == s);

}

// Testing SetupCheck

TEST_CASE("Testing setupCheck", "TuringMachine.cpp")
{
	std::vector<std::string> s = { "a","b","c" };
	std::vector<std::string> s1 = { "a","b","c", "d" };
	std::vector<std::string> s2 = { "a","b","b" };
	std::vector<std::string> s3 = { "a","b" };
	std::vector<std::string> s4 = { " " };
	std::vector<std::string> v = { "1", "2", "3", "4" };
	Tape t1(v);
	TuringMachine machine(t1, s);
	REQUIRE(machine.setupCheck());
	machine.setSymbols(s1);
	REQUIRE_FALSE(machine.setupCheck());
	machine.setSymbols(s2);
	REQUIRE_FALSE(machine.setupCheck());
	machine.setSymbols(s3);
	REQUIRE_FALSE(machine.setupCheck());
	machine.setSymbols(s4);
	REQUIRE_FALSE(machine.setupCheck());



}

// Testing patternMatch 
TEST_CASE("Testing Turing Machine patternMatch", "TuringMachine.cpp") {

	
	std::vector<std::string> a{ "a","b", "c" };
	std::vector<std::string> b{ "a", "a", "a", "a", "b", "b", "c", "c" };
	std::vector<std::string> c{ "a","b", "b", "c", "c" };
	std::vector<std::string> d{ "a","b", "b", "c"};
	std::vector<std::string> e{ "a","b", "b"};
	std::vector<std::string> f{ "a", "c", "c" };
	std::vector<std::string> g{ "a", "b", "a", "c"};
	std::vector<std::string> h{ "a", "b", "c", "a", "b", "c"};
	std::vector<std::string> s{ "a","b","c" };
	Tape tape1(a);
	Tape tape2(b);
	Tape tape3(c);
	Tape tape4(d);
	Tape tape5(e);
	Tape tape6(f);
	Tape tape7(g);
	Tape tape8(h);

	TuringMachine t1(tape1, s);
	TuringMachine t2(tape2, s);
	TuringMachine t3(tape3, s);
	TuringMachine t4(tape4, s);
	TuringMachine t5(tape5, s);
	TuringMachine t6(tape6, s);
	TuringMachine t7(tape7, s);
	TuringMachine t8(tape8, s);
	//t.getTape().printTape();
	REQUIRE(t1.setupCheck());
	REQUIRE(t2.setupCheck());
	REQUIRE(t3.setupCheck());
	REQUIRE(t4.setupCheck());
	REQUIRE(t5.setupCheck());
	REQUIRE(t6.setupCheck());
	REQUIRE(t7.setupCheck());
	REQUIRE(t8.setupCheck());

	REQUIRE(t1.patternMatch());
	REQUIRE(t2.patternMatch());
	REQUIRE(t3.patternMatch());
	REQUIRE_FALSE(t4.patternMatch());
	REQUIRE_FALSE(t5.patternMatch());
	REQUIRE_FALSE(t6.patternMatch());
	REQUIRE_FALSE(t7.patternMatch());
	REQUIRE_FALSE(t8.patternMatch());

}
