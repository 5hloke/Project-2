#include "TuringMachine.hpp"

//Code away

// Default constructor
TuringMachine::TuringMachine()
{
	t.clear(); // clears the tape 
	symbols; // and intializes symbols 
}

TuringMachine::TuringMachine(Tape toCopy, const std::vector<std::string>& p)
{
	t.setTape(toCopy); // Copies the tape to be copies to t
	symbols = p; //sets symbols equal to p
}

TuringMachine::~TuringMachine()
{
	reset(); //t.clear(); // calls the reset method to reset the TuringMachine 
}


std::vector<std::string> TuringMachine:: getSymbols() const
{
	return symbols; // returns the symbols 
}

Tape TuringMachine::getTape()
{
	return t; // returns the tape 
}

bool TuringMachine::setSymbols(std::vector<std::string> p)
{
	bool flag;
	symbols = p;  // Sets the symbols to p and returns true 
	flag = true;

	return flag;
}

bool TuringMachine::setTape(Tape& toCopy)
{
	t.setTape(toCopy); // sets the tape to the "toCopy" tape and returns true

	return true; 
}

bool TuringMachine::setupCheck()
{
	// Checks if there are three ditinct symbols in the legal symbols vector 
	bool flag;
	flag = false;
	if (symbols.size() == 3) { // If the size of the vector is 3 

		// Checks if aany of the symbols are repeated if yes then return false 
		if (symbols[0] == symbols[1] || symbols[0] == symbols[2] || symbols[1] == symbols[2]) { 

			flag = false;

		}
		else { // if not then return true
			flag = true; 
		}
	}
	
	//returns the appropriate value 
	return flag; 
}

void TuringMachine::reset()
{
	t.clear(); // clears the tape

	std::vector<std::string> reset; // creating a new empty vector 
	symbols = reset; // setting the empty vector equal to symbols
}

bool TuringMachine::patternMatch()
{
	t.rewind();// making sure that we start from the begining of the tape 
	//bool flag = true;

	//Check if the first symbol is in the list of the legal symbols 
	if (t.readSymbol() != symbols[0] && t.readSymbol() != symbols[1] && t.readSymbol() != symbols[2]) {

		//flag = false;
		return false;
	}
	//std::cout << flag << std::endl;
	//if (flag) {

	// Check if all ths symbols in the tape are a part of the legal symbols, if not return false 
	while (t.moveRight()) {
		if (t.readSymbol() != symbols[0] && t.readSymbol() != symbols[1] && t.readSymbol() != symbols[2]) {

			//flag = false;
			return false;

		}
	}
		t.rewind();
	//}
	//std::cout << flag << std::endl;
	//Check if the first symbol is equal to an a, if not return false
	if (t.readSymbol() != symbols[0]) {// && flag) {
		//flag = false;
		//first_a_check = false;
		return false;
	}
	//std::cout << flag << std::endl;
	//if (first_a_check && flag) {
		//bool no_a = true;
	
	//travers the list unless you hit the next symbol (Cover all the a's)
	while (t.readSymbol() == symbols[0] && t.moveRight()) {
			//last_a_check = true;
	}

	// making sure that the symbol after a is b, if not return 
	if (t.readSymbol() != symbols[1]) {
		//flag = false;
		return false;
	}
	else if (t.readSymbol() == symbols[1]) { //checking if the symbol is a "b"
		while (t.moveRight()) { // if the symbol is a "b", then check that there are no other "a".
			if (t.readSymbol() == symbols[0]) {
					//no_a = false;
					//flag = false;
					return false;
			}
				//else {
					//no_a = true;
				//}
		}
	}
	t.rewind(); // rewind if there are no other "a's" 
	//}
	//std::cout << flag << std::endl;
	//if (flag) {

	// Move up the list  until done with the "a's" 
	while (t.readSymbol() == symbols[0] && t.moveRight()) {

	}
	
	if (t.readSymbol() != symbols[1]) { // if the symbol is not a b return false
		//flag = false;
		//std::cout << "Inside the if statement" << flag << std::endl;
		return false;
	}
		
	else if (t.readSymbol() == symbols[1]){ // if the symbol is a b
		
		while (t.readSymbol() == symbols[1] && t.moveRight()) { // traverse the tape unless you reach a c and are done with the b's
			
		}

		if (t.readSymbol() != symbols[2]) { // if the symbol is not a c return false
			//flag = false;
			//std::cout << "Inside the if statement 2" << flag << std::endl;
			return false;
				
		}
		else if (t.readSymbol() == symbols[2]) { // if the symbol is a c
			while (t.moveRight()) {
				if (t.readSymbol() == symbols[1]) { // If there are more b's in the tape 
					//flag = false;
					//std::cout << "Inside the if statement 3" << flag << std::endl;
					return false; 
				}
			}
			t.writeSymbol("C"); // Write the symbol as "C", the last c
			
		}
	}

	
	//std::cout << flag << std::endl;
	t.rewind();
	
	// find the first b in the tape 
	while (t.readSymbol() == symbols[0] && t.moveRight()) {

	}
	// and write it as B
	t.writeSymbol("B");
	//t.printTape();
	//rewind the tape 
	t.rewind();
	
	while (true) {
		while (t.readSymbol() != "B" && t.moveRight()) { // reach the first B

		}
		t.moveRight(); // move to the next symbol in the tape 
		//std::cout << "current index is : " << t.getIndex() << std::endl;
		//check if the next symbol is a "b" or a "c" if not return true
		//because next symbol is going to be a C and we have established that for every b there is a c
		if (t.readSymbol() != "b" && t.readSymbol() != "c") {
			//t.printTape();
			return true;
		}
		else if (t.readSymbol() == "b") { // if the next symbol is a b
			t.writeSymbol("B"); // overwrite it with a capital B
			while (t.readSymbol() != "C" && t.moveRight()) { // move right until you find a capital C
				
			}
			t.moveLeft(); // then move left 
			if (t.readSymbol() == "c") { // if the symbol is a "c", overwrite it with a "C"
				t.writeSymbol("C");
			}
			else { // else return false 
				return false;
			}
		}
		else if (t.readSymbol() == "c") { // if the symbol next to a B is a c that means there are more c's than b's because there can not be any b's after we reach a c in the tape 
			return false; //return false
		}
		while (t.readSymbol() != "B" && t.moveLeft()) {

		}

	}
	t.printTape();
	//}
	/*
	if (flag) {
		while (t.moveRight() && t.readSymbol() != symbols[1]) {

		}
		t.writeSymbol("B"); // first b is written 

		while (t.moveRight() && t.readSymbol() != symbols[2]) {

		}

		t.writeSymbol("C"); // first c is written

	}

	*/
	
	
	/*return true;
	bool flag = true; 
	bool first_a_check = true;
	bool last_a_check = false;
	bool first_b_check = false;
	bool last_b_check = false;
	bool first_c_check = false;
	bool last_c_check = false;

	//The first if statement checks if the first symbol in the tape matches the legal symbols
	if (t.readSymbol() != symbols[0] && t.readSymbol() != symbols[1] && t.readSymbol() != symbols[2]) {
		
		flag = false;
	}
	else if (flag) { // Checks if all the symbols in the tape are legal symbols or not if not flag is set to false
		while (t.moveRight()) {
			if (t.readSymbol() != symbols[0] && t.readSymbol() != symbols[1] && t.readSymbol() != symbols[2]) { 
				
				flag = false;

			}
		}
		t.rewind();
	}
	else if (t.readSymbol() != symbols[0] && flag) { // Checks if the first symbol is an a if not then flag is set to false
		
		flag = false;
		first_a_check = false;

	}
	else if (first_a_check && flag) { // checking the first b and the last a (also checks if there is a b after the last a)
		
		bool no_a = true;
		while (t.readSymbol() == symbols[0] && t.moveRight()) {
			last_a_check = true;
		}

		if (t.readSymbol() != symbols[1]) {
			flag = false; 
		}
		else { //checking if there is no other a
			while (t.moveRight()) {
				if (t.readSymbol() == symbols[0]) {
					no_a = false;
					flag = false;
				}
				else {
					no_a = true;
				}
			}
		}
		t.rewind();
	}
	else if (flag) { //If the flag is still true
		while (t.readSymbol() == symbols[1] && t.moveRight()) {

		}
		if (t.readSymbol() != symbols[1]) {
			flag = false;
		}
		else {
			while (t.readSymbol() == symbols[1] && t.moveRight()) {
				
			}
			last_b_check = true;
			
			if (t.readSymbol() != symbols[2]) {
				flag = false;
			}
			else {
				while (t.moveRight()) {
					if (t.readSymbol() == symbols[1]) {
						flag = false;
					}
					else {
						flag = true;
					}
				}
			}
		}

	}
	else if*/

	return true ;

}
