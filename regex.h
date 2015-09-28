#ifndef _REGEX_H_
#define _REGEX_H_

#include <vector>
#include <string>
#include <iostream>

// The tokens:
enum token {ID, REP, OR, LPAR, RPAR, SYNER, END};
// make iter to be the name for a string iterator.
typedef std::string::iterator iter;
// make viter to be the name for a vector string iterator.
typedef std::vector<std::string>::iterator viter;

class regex{
	public:
		/*
		*Constructors and destructor.
		*/
		/*
		*Defualt Constructor.
		*/
		regex();
		/*
		*Constructor with expression.
		*/
		regex(std::string ex);
		/*
		*Destructor.
		*/
		~regex();


		/*
		*Member functions in regex.
		*/
		/*
		*Set and reset index's to 0.
		*/
		void resetIndex();
		/*
		*Returns next token, and change index for regExp.
		*/
		token getToken();
		/*
		*Returns next letter from expression,
		*for it to work proper use getToken before
		*getID.
		*/
		std::string getId();
		/*
		*getPrevId gets the prevouse id.
		*/
		std::string getPrevId();
	private:
		/*
		*member functions
		*/
		// Create tokens from string expression.
		void makeTokens(std::string ex);
		// Check what token it is.
		token lookUp(char toCheck);
		// Printing tokenList for debugging purposes.
		void printTokenList();
		// Printing regExp for debgging purposes.
		void printRegExp();

		/*
		*Data members
		*/
		// Data member for tokens.
		std::vector<token> tokenList;
		// Data member for original expr (No tokens).
		std::vector<std::vector<std::string> > regExp;
		// Index for tokenList, regExp.
		struct tokenListIndex{
			size_t tIndex;
			size_t outVIndex;
			size_t inVIndex;
		};
		// use of struct
		tokenListIndex index;
		// Keep track of previous inner index
		size_t prevIn; 
};

#endif /*_REGEX_H_*/