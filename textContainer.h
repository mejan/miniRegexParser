#ifndef _TEXT_CONTAINER_H_
#define _TEXT_CONTAINER_H_

#include <string>
#include <stack>
#include <fstream>
#include <algorithm>
#include <iostream>

typedef std::string::iterator iter;

class textContainer{
	public:
		/*
		*Constructors and destructor
		*/
		/*
		*Default constructor
		*inialize the stack.
		*/
		textContainer();
		/*
		*Constructor that adds text
		*inialize the stack and fill it with inText as char
		*/
		textContainer(std::string inText);
		/*
		*Destructor
		*Nothing to destruct.
		*/
		~textContainer();

		/*
		*Member functions
		*/
		/*
		*Add new text to container.
		*From input inText string.
		*/
		void addText(std::string inText);
		/*
		*Add text to existing text container
		*and it adds it in the end of the old text.
		*/
		void addMoreText(std::string inText);
		/*
		*Add new text from file.
		*/
		void addFileText(std::string file);
		/*
		*Add text from file to existing text container.
		*And it adds it in the end of the old text.
		*/
		void addMoreFileText(std::string file);
		/*
		*Search in text and pop til it finds c or
		*the container gets empty.
		*/
		bool isInText(char c);
		/*
		*Check if the top is equle to c.
		*If it's equel it will pop top.
		*In the case of miniRegex project,
		*it will be used for repition.		
		*/
		bool isTopEquel(char c);
		/*
		*Check if the top is equal to c
		*and remove top.
		*/
		bool isTopEqPop(char c);
		/*
		*check if container is empty
		*/
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