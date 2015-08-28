#ifndef _PARSER_H_
#define _PARSER_H_

#include "regex.h"

class parser{
	public:
		/*
		*Constructors and destructors.
		*/
		// Default constuctor set private datamebers to basicly zero.
		parser();
		// Dedtructor takes care of memory resturn (maybe not (not sure yet)).
		~parser();

		/*
		*Public member functions in parser
		*/
	private:
		/*
		*Private member functions in parser
		*/
		// Expresion bas function for the parsing.
		void expresion();
		// How we work with the or sign +.
		bool orOperation();
		// How we work with the ()'s.
		bool parOperation();
		// Concat/Union's function.
		bool conOperation();
		// repeat function.
		bool repOperation();

		/*
		*Datamembers
		*/
};

#endif /*_PARSER_H_*/