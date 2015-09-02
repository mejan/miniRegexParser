#ifndef _TEXT_CONTAINER_H_
#define _TEXT_CONTAINER_H_

#include <string>
#include <fstream>
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
		
	private:
		/*
		*Function members
		*/
		// text form file to string 'text'.
		void addFromFile(std::string file, bool removeOLd);

		/*
		*Data members
		*/
		// Text container.
		std::string text;
		// iterators to keep track of the current possition.
		iter currentPos;
		// iterator for where to stop find.
		iter stopPos;
};

#endif /*_TEXT_CONTAINER_H_*/