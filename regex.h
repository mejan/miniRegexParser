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
		// constrttor arg: parserclass, alloocate parserclass
		// and copy argument pointer.
		regex(parser token);
		~regex();

		/*
		public member functions
		*/
		// add parser if not exsists.
		void addParser(parser token);
	private:
		/*
		private functions
		*/
		// equel functions
		std::string continueOperation(int start, char toFind);
		// Regex statements
		std::string getRegexStrings(int current);
		/*
		Data member
		*/
		// parser klass point
		parser toRegex;
		// store result in.
		std::vector<std::string*> result;
};

#endif /*_REGEX_H_*/