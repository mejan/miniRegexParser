#ifndef _REGEX_H_
#define _REGEX_H_

#include "parser.h"

class regex{
	public:
		/*
		*Constructors and destructor
		*/

		// default constructor allocate a parser class to pointer
		regex();
		// constructor with expresion
		regex(std::string ex);
		// constructor with file tofindpattern in and add expresion
		regex(std::string fileName, std::string ex);
		//destruktor.
		~regex();

		/*
		*Member function
		*/

		// add a file to find match in
		void addFile(std::string fileName);
		// add new text to find matchin (text not file)
		void addNewText(std::string matchingText);
		// add new expression text
		void addNewExpresion(std::string ex);

	private:
		/*
		*Private member functions
		*/
		// Make concat.
		void concat(std::string toFind);

		/*
		*Private data members
		*/
		// String to contain text to find match in.
		std::string findMatchIn;
		// to keep tokens out of expresion
		parser tokens;
		// Contains current index where in findMatchIn we are.

};

#endif /*_REGEX_H_*/