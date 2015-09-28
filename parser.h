#ifndef _PARSER_H_
#define _PARSER_H_

#include "regex.h"

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
		~parser() = default;

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
		/*
		*parseExp() member function that will parse
		*the expression. If it finds the expression
		*it was looking  then return the answer, Else it
		*will tell the user No match was found.
		*/
		void parseExp();

	private:
		/*
		*Private member functions in parser
		*/
		// Expresion bas function for the parsing.
		bool expr();
		// How we work with the or sign +.
		bool orOperation();
		// How we work with the ()'s.
		bool parOperation();
		// Concat/Union's function.
		bool conOperation();
		// repeat function.
		bool repOperation();
		// Check for match in textContainer.
		bool match();
		// firstMatch is for the first time we make a match.
		bool fistMatch();
		// nxtMatch is the matching function for matching
		// afer the fisrt match been done.
		bool nxtMatch();
		// repMatch is the matching function for repeat.
		void repMatch();
		// Prints the result.
		void ansPrint();

		/*
		*Datamembers
		*/
		// The text that will be looked in.
		std::string text;
		// keeps the regex expression in.
		regex expression;
		// keeps track of what is found
		std::vector<std::string> ans;
		// Where to start search.
		// Iter is a typedef in regex.h
		size_t startPos;
		// Previous Token
		token prevToken;
};

#endif /*_PARSER_H_*/