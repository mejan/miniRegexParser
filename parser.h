#ifndef _PARSER_H_
#define _PARSER_H_

#include "regex.h"

#include <stack>
#include <fstream>



class parser{
	public:
		/*
		*Constructors and destructor
		*/

		// default constructor allocate a parser class to pointer
		parser();
		// constructor with expresion
		parser(std::string ex);
		// constructor with file tofindpattern in and add expresion
		parser(std::string fileName, std::string ex);
		//destruktor.
		~parser();

		/*
		*Member function
		*/

		// add a new file to find match in
		void addFile(std::string fileName);
		// add new text to find matchin (text not file)
		void addNewText(std::string matchingText);
		// add new expression text
		void addNewExpretion(std::string ex);
		// Starts the new text, and expretion regex.
		void startRegex();

	private:
		/*
		*Private member functions
		*/
		// parse the exprestion.
		bool expression(size_t stackNum);
		// Make concat.
		bool concat();
		/*Or operation
		Left most checking is like C++ is working with the or statment
		if(text a || text b) if the first on (a) is true don't bother checking the
		right one.*/
		bool orOP();
		/*parentes operation*/
		bool parentesLeft();
		bool parentesRight();
		/*repeat operation.
		Will always be true cuz we allow this to find 0-ininty of a id or expression.
		*/
		bool repeat();
		// find match to a string
		bool findMatch(char toMatch);


		/*
		*Data members
		*/
		// String to contain text to find match in.
		std::string searchIn;
		// to keep tokens out of expresion
		regex tokens;
		// store result in
		std::string result;
		// keep the found iterators in
		// std::stack<std::string> stackFound;
		std::vector<bool> currentMatch; //don't forget to change name in .cpp
		// keep track of current possition in searchIn.
		size_t searchPos;
		// keep track of the token being read.
		size_t tokenListPos;
		// keeping track of stack in the vector
		size_t stackNum;

};

#endif /*_PARSER_H_*/