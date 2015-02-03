#ifndef _PARSER_H_
#define _PARSER_H_

#include "regex.h"
#include <stack>

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

	private:
		/*
		*Private member functions
		*/
		// parse the exprestion.
		void exprestion();
		// Make concat.
		bool concat(size_t i);
		// Or operation
		bool orOP();
		// parentes operation
		bool parentes();
		// repeat operation.
		bool repeat();
		// find match to a string
		void findMatch(std::string toFind);


		/*
		*Private data members
		*/
		// String to contain text to find match in.
		std::string searchIn;
		// to keep tokens out of expresion
		regex tokens;
		// Contains current iterator for start the search
		its startSearch;
		// store result in
		std::string result;
		// keep the found iterators in
		std::stack<std::string> stackFound;

};

#endif /*_PARSER_H_*/