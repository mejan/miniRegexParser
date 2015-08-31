#ifndef _REGEX_H_
#define _REGEX_H_

#include <vector>
#include <string>
#include <iostream>
#include <cctype>

// The tokens:
enum token {ID, REP, OR, LPAR, RPAR, SYNER, END};
// make siter be the name for a string iterator.
typedef std::string::iterator siter;

class regex{
	public:
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
		*Set and reset index's to 0.
		*/
		void setIndex();
		/*
		*Returns next token, and change index for regExp.
		*/
		const token getToken();
		/*
		*Returns next letter from expression
		*/
		const char getExp();
	private:
		// Create tokens from string expression.
		void makeTokens(std::string ex);
		// Check what token it is.
		token lookUp(char toCheck);
		// Data member for tokens.
		std::vector<token> tokenList;
		// Data member for original expr (No tokens).
		std::vector<std::string> regExp;
		// Index for tokenList, regExp.
		struct{
			size_t tIndex;
			size_t rIndex;
			size_t rTIndex;
		} index;
};

#endif /*_REGEX_H_*/