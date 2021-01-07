#include "Tape.hpp"


Tape::Tape() {
	
	index = -1; // index is set to negative 1 
	tape_size = 0; // Initial size is  0
	tape;
}

Tape::Tape(std::vector<std::string> v)
{
	tape_size = 0;
	for (int i = 0; i < v.size(); i++) {
		
		tape.addBack(v[i]); // Setting the elements of the tape cells to the string given
		tape_size++;
		//std::cout << tape_size << std::endl;
	}
	index = 0;
}

// Copy constructor
Tape::Tape(const Tape& toCopy)
{
	
	if (!(toCopy.isEmpty())) { // If it is not empty then we copy the tape
		tape_size = toCopy.getSize(); // Tape size is equal to the size of the tape that is being copied 
		//index = toCopy.getIndex();
		for (int i = 0; i < toCopy.getSize(); i++) { // for the size of the tape
			 
			tape.addBack(toCopy.tape.getItem(i)); // add back to the tape
		}
		index = 0;// initialize the index to 0
	}
	else { // if the tape is empty 
		clear();
		//Tape();
	}
}

Tape::~Tape()
{
	//Causes the clear method to destroy the tape
	clear();
	
}

int Tape::getSize() const
{
	return tape_size; // return the size
}

int Tape::getIndex() const
{
	int return_Val;
	if (!isEmpty()) { // If the tape is not empty 
		return_Val = index; // return val is set to index
	}
	else {
		return_Val = -1; // If the tape is empty set the return value to negative one
	}
	return return_Val;
}

// Needs to be done 
void Tape::setTape(Tape toCopy)
{
	if (!(toCopy.isEmpty())) { //if the tape to copy is not empty 
		tape.clear(); // first clear the tape 
		tape_size = toCopy.getSize(); // set the size
		index = toCopy.getIndex(); // get the index not required
		for (int i = 0; i < toCopy.getSize(); i++) {

			tape.addBack(toCopy.tape.getItem(i)); // addback all the elements that are to be added 
		}
	}
	else {
		clear(); // if the tape is empty then clear the tape 
	}
}

bool Tape::isEmpty() const
{
	bool flag;
	if (tape.getCurrentSize() > 0) { // if the size of the tape is greaterr than zero than returns false
		flag = false;
	}
	else { // otherwise the function returns 
		flag = true;
	}
	return flag;
}

bool Tape::moveRight()
{
	bool motion;
	// Check if the index is greater than zero and less than the tape size - 1
	if (index >= 0 && index < (tape_size-1)) {
		index++; // then the index is increased by one 
		motion = true; // motion is true
	}
	else {
		motion = false; // return false if the command was unsuccesful
	}
	return motion;
}

bool Tape::moveLeft()
{
	bool motion;
	//Same conditions as that in move right 
	if (index > 0 && index < tape_size) {
		index--; // if the condition is met than reduce the index by one
		motion = true; // set the motion to true to return true 
	}
	else {
		motion = false; // otherwise set the motion to false
	}
	return motion;
}

//Writes a blank to the tape
bool Tape::writeBlank() 
{
	bool flag;
	// translating the condition to if the tape is not empty 
	if ((index < getSize()) && index >= 0) {
		tape.replace(index, " ");  // replacing the symbol at the index to a blank
		flag = true; // return true 
	}
	else {
		flag = false; // return false
	}
	return flag; // returns the boolean value 

}
 
bool Tape::writeSymbol(std::string s)
{
	//Same as the write blank function but instead of writing a blank we write a specific symbol to the tape
	bool flag;
	if ((index < getSize()) && index >= 0) {
		tape.replace(index, s);
		flag = true;
	}
	else {
		flag = false;
	}
	return flag;
}

std::string Tape::readSymbol() const
{
	//reads a symbol from tape.
	std::string item;
	if ((index < getSize()) && index >= 0) { // checking if the index is not in the given bounds 
		item = tape.getItem(index); // set item to the item in the tape
	}
	else {
		item = ""; // item.clear();
	}
	return item; // return the item 
}

void Tape::clear()
{
	tape.clear(); // clear the tape 
	index = -1; //set indext to -1 
	tape_size = 0; // set size to 0
}

void Tape::printTape() const
{
	tape.printList(); // prints the list
}

void Tape::rewind()
{
	if (!(isEmpty())) { // if the tape is not empty 
		index = 0; // index is set to zero
	}
	else {
		index = -1; // else index is set to -ve 1 
	}
}