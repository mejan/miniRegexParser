#ifndef _REGEX_H_
#define _REGEX_H_

#include "parser.h"

typedef std::vector<std::string*>::iterator itsp;

class regex{
	public:
		/*
		Constructors and destructor
		*/
		// default constructor allocate a parser class to pointer
		regex();
		//constructor that adds matchin text from the file in argument fileName.
		regex(std::string fileName);

		~regex();
	private:
		/*
		*Private member functions
		*/
		void getMatch(std::string toFind);

		/*
		*Private data members
		*/
		// String to contain text to find match in.
		std::string findMatchIn;
		// Contains current index where in findMatchIn we are.

};

#endif /*_REGEX_H_*/