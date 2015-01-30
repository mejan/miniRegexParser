#ifndef _TEXTCONTAINER_H_
#define _TEXTCONTAINER_H_

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib>

typedef std::vector<char>::iterator itcp;
typedef std::string::iterator its;

class textContainer{
	public:
		/*
		Constructors.
		*/
		// without adding text to textContainer.
		textContainer();
		// constructor read from file and contain it's chars.
		textContainer(std::string fileName);
		// Destructors.
		~textContainer();

		/*
		Public member functions
		*/
		// console outs the content of the container.
		void printContent();
		// adds specific char to container.
		void pushBackChar(char& toAdd);
		// splitt and add a string, to contain.
		void addString(std::string toCon);
		// opensfile and contain the text.
		void addFile(std::string fileName);
		// remove and return the first element.
		char popFront();
		// returns the specik container.
		char getChar(int i);
		// returns the size
		size_t getSize();
		// empty the container
		void makeEmpty();

	private:
		/*
		Data member
		*/
		// pointer to vector with chars.
		std::vector<char> inText;
};
#endif /*_textContainer_H_*/