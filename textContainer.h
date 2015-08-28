#ifndef _TEXT_CONTAINER_H_
#define _TEXT_CONTAINER_H_

#include <string>
#include <stack>
#include <fstream>
#include <algorithm>
#include <iostream>

typedef std::string::reverse_iterator riter;
typedef std::string::iterator iter;

class textContainer{
	public:
		/*
		*Constructors and destructor
		*/
		// Default constructor
		textContainer();
		// Constructor that adds text
		textContainer(std::string inText);
		// Destructor
		~textContainer();

		/*
		*Member functions
		*/
		// Add new text to container.
		void addText(std::string inText);
		// Add text to existing text container.
		// and it adds it in the end of the old text.
		void addMoreText(std::string inText);
		// Add new text from file.
		void addFileText(std::string file);
		// add text from file to existing text container.
		// and it adds it in the end of the old text.
		void addMoreFileText(std::string file);
		// Search in text and pop til it find + c.
		bool isInText(char c);
		// Check if the top is equle to c.
		// if it's equel it will pop top.
		bool isTopEquel(char c);
		// check if container is empty
		bool isEmpty();
	private:
		/*
		*Function members
		*/
		// Adds text to the stack.
		void fillStack(std::string inText);
		// empty the stack
		void empStack();

		/*
		*Data members
		*/
		// Text container.
		std::stack<char> text;
};

#endif /*_TEXT_CONTAINER_H_*/