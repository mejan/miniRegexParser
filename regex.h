#ifndef _REGEX_H_
#define _REGEX_H_

#include <vector>
#include <string>
#include <iostream>
#include <cctype>

// The tokens:
enum token {ID, REP, OR, LPAR, RPAR, SYNER, END};
// make iter to be the name for a string iterator.
typedef std::string::iterator iter;
// make viter to be the name for a vector string iterator.
typedef std::vector<std::string>::iterator viter;

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
		token getToken();
		/*
		*Returns next letter from expression,
		*for it to work proper use getToken before
		*getID.
		*/
		std::string getId();
		/*
		*get left and right. Might remove soon
		*/
		// std::vector<std::string> orSplit();
	private:
		// Create tokens from string expression.
		void makeTokens(std::string ex);
		// Check what token it is.
		token lookUp(char toCheck);
		// Data member for tokens.
		std::vector<token> tokenList;
		// Data member for original expr (No tokens).
		std::vector<std::vector<std::string> > regExp;
		// Index for tokenList, regExp.
		struct{
			size_t tIndex;
			size_t outVIndex;
			size_t inVIndex;
		} index;
};

#endif /*_REGEX_H_*/