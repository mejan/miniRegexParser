#ifndef _PARSER_H_
#define _PARSER_H_

#include "regex.h"
// #include "textContainer.h"

#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>


class parser{
	public:
		/*
		*Constructors and destructors.
		*/
		/*
		*Default constuctor set private datamebers to basicly zero.
		*/
		parser();
		/*
		*Constructor with expression as in variable.
		*/
		parser(std::string expr);
		/*
		*Dedtructor takes care of memory resturn (maybe not (not sure yet)).
		*/
		~parser();


		/*
		*Public member functions in parser
		*/
		/*
		*Add text to search in by string.
		*/
		void addText(std::string inText);
		/*
		*Add text to search in by filename.
		*/
		void addTextFile(std::string filename);
		/*
		*Delete the current text to search in.
		*/
		void emptyText();

	private:
		/*
		*Private member functions in parser
		*/
		// Expresion bas function for the parsing.
		void expr();
		// How we work with the or sign +.
		bool orOperation();
		// How we work with the ()'s.
		bool parOperation(token tmpT);
		// Concat/Union's function.
		bool conOperation();
		// repeat function.
		bool repOperation();
		// Check for match in textContainer.
		bool match(bool conOrNot);

		/*
		*Datamembers
		*/
		// The text that will be looked in.
		std::string text;
		// keeps the regex expression in.
		regex expression;
		// keeps track of what is found
		std::vector<std::string> ans;
		// Keep index for the ans vector.
		size_t ansIndex;
		// Where to start search.
		// Iter is a typedef in regex.h
		size_t startPos;
};

#endif /*_PARSER_H_*/